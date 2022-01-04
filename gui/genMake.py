#!/usr/bin/python3
import os
import sys


def checkIncludes(srcName, headers, infoDict):
	"""
	checks for opencv and/or qt includes in srcName and for QT_OBJECT in corresponding header

	srcName: str name of src file (w/o ext)
	headers: list[str] of all header files
	infoDict: dict defined out of scope with keys of srcNames, this function updates 
	          corresponding sub dictionary

	return None
	"""

	ccName = f"{srcName}.cc"
	hhName = f"{srcName}.hh"

	mocDependKey = "mocDepend"
	libDependKey = "libDepend"

	qObj = "Q_OBJECT"
	qtSearch = "Q"  # all QT includes start with Q
	cvSearch = "opencv2/opencv.hpp"
	qtFound = False
	cvFound = False

	# get includes from .cc
	with open(ccName, "r") as f:
		includes = [line for line in f.readlines() if line[:8] == "#include"]

	# if there is a .hh corresponding to .cc, get those includes and check for moc depend
	infoDict[srcName][mocDependKey] = False

	if hhName in headers:
		with open(hhName, "r") as f:
			for line in f.readlines():
				if line[:8] == "#include":
					includes.append(line)
				elif qObj in line:
					infoDict[srcName][mocDependKey] = True

	# determine which libs are included
	for include in includes:
		if qtSearch in include:
			qtFound = True
		elif cvSearch in include:
			cvFound = True

	# set values in infoDict corresponding to lib depends
	if qtFound and cvFound:
		infoDict[srcName][libDependKey] = "opencv&qt"
	elif qtFound:
		infoDict[srcName][libDependKey] = "qt"
	elif cvFound:
		infoDict[srcName][libDependKey] = "opencv"
	else:
		infoDict[srcName][libDependKey] = "none"


def writeMake(srcNames, infoDict, otherDirs, makePath="Makefile"):
	"""
	writes a Makefile with everything needed

	srcNames: list[str] of .cc names needed (w/o ext.)
	infoDict: dict containing dependency info on each src in srcNames 
	otherDirs: list[str] of other directories to clean 
	makePath: str to write as makefile

	return None
	"""

	# create each line of Makefile as variable b4 writing
	# will write these lists in order to out file
	variables = []
	targets = []

	# compiler/sys stuff
	gpp = "GPP = g++"
	gppFlags = "GPP_FLAGS = -O1 -g"
	grep = 'GREP = grep -Po "[^.+\.(\w|\w\w):].+" | tr -d "\\n" | tr -d "\\\\"'  # NOTE tr shows a warning but it's not important
	defines = "DEFINES = -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB"
	target = "TARGET = app"

	variables.append(gpp)
	variables.append(gppFlags)
	variables.append(grep)
	variables.append(defines)
	variables.append(target)

	# cv stuff
	cvInc = "CV_INCLUDES = -I /usr/local/include/opencv2"
	cvObjLibs = "CV_OBJ_LIBS = -L /usr/local/lib"
	cvFlags = "CV_FLAGS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_stitching"
	cvLibs = "CV_LIBS = /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_calib3d.so.405 /usr/local/lib/libopencv_calib3d.so.4.5.5 /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_core.so.405 /usr/local/lib/libopencv_core.so.4.5.5 /usr/local/lib/libopencv_dnn.so /usr/local/lib/libopencv_dnn.so.405 /usr/local/lib/libopencv_dnn.so.4.5.5 /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_features2d.so.405 /usr/local/lib/libopencv_features2d.so.4.5.5 /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_flann.so.405 /usr/local/lib/libopencv_flann.so.4.5.5 /usr/local/lib/libopencv_gapi.so /usr/local/lib/libopencv_gapi.so.405 /usr/local/lib/libopencv_gapi.so.4.5.5 /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_highgui.so.405 /usr/local/lib/libopencv_highgui.so.4.5.5 /usr/local/lib/libopencv_imgcodecs.so /usr/local/lib/libopencv_imgcodecs.so.405 /usr/local/lib/libopencv_imgcodecs.so.4.5.5 /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_imgproc.so.405 /usr/local/lib/libopencv_imgproc.so.4.5.5 /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_ml.so.405 /usr/local/lib/libopencv_ml.so.4.5.5 /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_objdetect.so.405 /usr/local/lib/libopencv_objdetect.so.4.5.5 /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_photo.so.405 /usr/local/lib/libopencv_photo.so.4.5.5 /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_stitching.so.405 /usr/local/lib/libopencv_stitching.so.4.5.5 /usr/local/lib/libopencv_videoio.so /usr/local/lib/libopencv_videoio.so.405 /usr/local/lib/libopencv_videoio.so.4.5.5 /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_video.so.405 /usr/local/lib/libopencv_video.so.4.5.5"

	variables.append(cvInc)
	variables.append(cvObjLibs)
	variables.append(cvFlags)
	variables.append(cvLibs)

	# qt stuff
	qtObjFlags = "QT_OBJ_FLAGS = -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB $(DEFINES)"
	qtInc = "QT_INCLUDES = -I. -I. -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++"
	qtFlags = "QT_FLAGS = -lpthread"
	qtLibs = "QT_LIBS = /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so /usr/lib/x86_64-linux-gnu/libGL.so"

	variables.append(qtObjFlags)
	variables.append(qtInc)
	variables.append(qtFlags)
	variables.append(qtLibs)

	# loop below adds to these
	objs = [f"{srcName}.o" for srcName in srcNames]
	mocNames = []

	# this target shouldn't ever have to change
	mocPredefs = "mocPredefs"
	mocPredefsTarget = f"{mocPredefs}.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp\n\t$(GPP) -pipe -O2 -Wall -W -dM -E -o {mocPredefs}.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp"
	targets.append(mocPredefsTarget)

	# create targets along with any needed dependency variables
	for srcName, srcDeps in infoDict.items():

		# create a variable for moc dependencies, create corresponding moc .cc target, moc .o target
		if srcDeps["mocDepend"] == True:
			mocName = f"moc_{srcName}"
			mocNames.append(mocName)
			objs.append(f"{mocName}.o")
			mocDepVar = f"moc_{srcName}_DEPENDS = {srcName}.hh $(shell $(GPP) -MM {srcName}.hh | $(GREP))"
			variables.append(mocDepVar)

			# NOTE those that need moc should only be .hh class files, if they need opencv this may need to be updated, probs not, but not super sure
			ccMocTarget = f"{mocName}.cc: $(moc_{srcName}_DEPENDS) /usr/lib/qt5/bin/moc\n\t/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/{mocPredefs}.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include {srcName}.hh -o {mocName}.cc"
			targets.append(ccMocTarget)
			
			oMocTarget = f"moc_{srcName}.o: moc_{srcName}.cc\n\t$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o moc_{srcName}.o moc_{srcName}.cc"
			targets.append(oMocTarget)

		# create src .o target
		srcDepVar = f"{srcName}_DEPENDS = $(shell $(GPP) -MM {srcName}.cc | $(GREP))"
		variables.append(srcDepVar)
		srcTarget = f"{srcName}.o: $({srcName}_DEPENDS)\n\t"

		if infoDict[srcName]["libDepend"] == "qt":
			srcTarget += f"$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o {srcName}.o {srcName}.cc"
		elif infoDict[srcName]["libDepend"] == "opencv":
			srcTarget += f"$(GPP) $(CV_INCLUDES) $(CV_OBJ_LIBS) -c -o {srcName}.o {srcName}.cc"
		elif infoDict[srcName]["libDepend"] == "opencv&qt":
			srcTarget += f"$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) $(CV_INCLUDES) $(CV_OBJ_LIBS) -c -o {srcName} {srcName}.cc"
		else:
			print(f"unknown lib depend: {infoDict[srcName]['libDepend']}")
			sys.exit(-1)

		targets.append(srcTarget)

	objVar = f"OBJS = {' '.join(objs)}"
	variables.append(objVar)

	# final build command
	buildTarget = "build_app: $(OBJS)\n\t$(GPP) $(CFLAGS) $(CV_FLAGS) $(QT_FLAGS) -o $(TARGET) $(OBJS) $(CV_LIBS) $(QT_LIBS)"
	targets.append(buildTarget)

	# all except moc targets are also object names
	allTarget = f"all: {mocPredefs}.h {' '.join([mocName + '.cc' for mocName in mocNames])} $(OBJS) build_app\n\t@echo It has been made."
	targets.insert(0, allTarget)

	cleanRemoves = "\n\t".join([f"rm -f {otherDir}/*.o" for otherDir in otherDirs])
	cleanTarget = f".PHONY: clean\nclean:\n\trm -f moc*\n\trm -f *.o\n\t{cleanRemoves}"

	# write everything 
	with open(makePath, 'w') as f:
		for variable in variables:
			f.write(f"{variable}\n")

		f.write("\n")

		for target in targets:
			f.write(f"{target}\n\n")

		f.write(cleanTarget)
			

def main():
	print("DID YOU CLEAN PWD OF ALL moc* FILES B4 RUNNING THIS?")

	# get all required source and header files
	cvDir = "../cv"
	otherDirs = [cvDir]
	files = os.listdir() + [f"{cvDir}/{f}" for f in os.listdir(cvDir)]
	srcNames = [f[:-3] for f in files if f[-3:] == ".cc"]
	headers = [f for f in files if f[-3:] == ".hh"]

	# name of final exe to build
	exeName = "app"

	# dependency info dictionary for each src
	infoDict = {}

	for srcName in srcNames:
		infoDict[srcName] = {}
		checkIncludes(srcName, headers, infoDict)

	writeMake(srcNames, infoDict, otherDirs)


if __name__ == "__main__":
	main()

