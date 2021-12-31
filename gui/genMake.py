#!/usr/bin/python3
import os
import sys


def checkIncludes(ccFile, headers):
	"""
	given a .cc file and header files, return string indicating whether it needs qt, opencv, or both libs

	ccFile: string name of file to check #include of 
	headers: list of .hh files

	returns either "qt", "opencv", or "both"
	"""

	qtSearch = "Q"  # all QT includes start with Q
	cvSearch = "opencv2/opencv.hpp"
	qtFound = False
	cvFound = False

	# get includes from .cc
	with open(ccFile, "r") as f:
		includes = [line for line in f.readlines() if line[:8] == "#include"]

	# if there is a .hh corresponding to .cc, get those includes too
	if f"{ccFile[:-3]}.hh" in headers:
		with open(f"{ccFile[:-3]}.hh", "r") as f:
			includes += [line for line in f.readlines() if line[:8] == "#include"]

	for include in includes:
		if qtSearch in include:
			qtFound = True
		elif cvSearch in include:
			cvFound = True

	if qtFound and cvFound:
		return "both"
	elif qtFound:
		return "qt"
	elif cvFound:
		return "opencv"
	else:
		return "neither"


def writeMake(sources, headers, includes, exeTarget, makePath="Makefile"):
	"""
	creates a Makefile from .cc and .hh files, make to build final exe

	sources: list of .cc files in pwd
	headers: list of .hh files in pwd
	includes: dictionary like {main: opencv, ...} (see checkIncludes for include options) 
	          that determines how to compile the .o
	exeTarget: string name of final executable
	makePath: string file name of output Makefile

	returns nothing
	"""

	# executable name
	exeTargetLine = f"TARGET = {exeTarget}"

	# object files from .cc
	objs = [path[:-3] + ".o" for path in sources]
	objsStr = ' '.join(objs)
	objLine = f"OBJS = {objsStr}"

	# all target
	allTarget = f"all: {objsStr} build_app clean\n\t@echo It has been made."

	# create object file targets
	targetLines = []

	for obj in objs:
		objBase = obj[:-2]

		if f"{objBase}.hh" in headers:
			targetLine = f"{obj}: {objBase}.cc {objBase}.hh\n"
		else:
			targetLine = f"{obj}: {objBase}.cc\n"

		if includes[objBase] == "qt":
			targetLine += f"\t$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o {obj} {objBase}.cc"
		elif includes[objBase] == "opencv":
			targetLine += f"\t$(COMP) $(CV_INCLUDES) $(CV_OBJ_LIBS) -c -o {obj} {objBase}.cc"
		elif includes[objBase] == "both":
			targetLine += f"\t$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) $(CV_INCLUDES) $(CV_OBJ_LIBS) -c -o {obj} {objBase}.cc"

		targetLines.append(targetLine)

	# write Makefile (everything hardcoded except for the stuff made above)
	with open(makePath, 'w') as fi:
		# im sorry - i should split this up
		fi.write(f"# general compiler stuff\nCOMP = g++\nCFLAGS = -O1\n{objLine}\n{exeTargetLine}\n\n# opencv stuff (build objs, then to compilation with qt stuff)\nCV_INCLUDES = -I /usr/local/include/opencv2\nCV_OBJ_LIBS = -L /usr/local/lib\nCV_FLAGS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_stitching\nCV_LIBS = /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_calib3d.so.405 /usr/local/lib/libopencv_calib3d.so.4.5.5 /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_core.so.405 /usr/local/lib/libopencv_core.so.4.5.5 /usr/local/lib/libopencv_dnn.so /usr/local/lib/libopencv_dnn.so.405 /usr/local/lib/libopencv_dnn.so.4.5.5 /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_features2d.so.405 /usr/local/lib/libopencv_features2d.so.4.5.5 /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_flann.so.405 /usr/local/lib/libopencv_flann.so.4.5.5 /usr/local/lib/libopencv_gapi.so /usr/local/lib/libopencv_gapi.so.405 /usr/local/lib/libopencv_gapi.so.4.5.5 /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_highgui.so.405 /usr/local/lib/libopencv_highgui.so.4.5.5 /usr/local/lib/libopencv_imgcodecs.so /usr/local/lib/libopencv_imgcodecs.so.405 /usr/local/lib/libopencv_imgcodecs.so.4.5.5 /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_imgproc.so.405 /usr/local/lib/libopencv_imgproc.so.4.5.5 /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_ml.so.405 /usr/local/lib/libopencv_ml.so.4.5.5 /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_objdetect.so.405 /usr/local/lib/libopencv_objdetect.so.4.5.5 /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_photo.so.405 /usr/local/lib/libopencv_photo.so.4.5.5 /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_stitching.so.405 /usr/local/lib/libopencv_stitching.so.4.5.5 /usr/local/lib/libopencv_videoio.so /usr/local/lib/libopencv_videoio.so.405 /usr/local/lib/libopencv_videoio.so.4.5.5 /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_video.so.405 /usr/local/lib/libopencv_video.so.4.5.5\n\n# qt stuff (build objs, then to compilation with opencv stuff)\nQT_OBJ_FLAGS = -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB\nQT_INCLUDES = -I. -I. -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++\nQT_FLAGS = -lpthread\nQT_LIBS = /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so /usr/lib/x86_64-linux-gnu/libGL.so\n\n{allTarget}\n\n#build object files\n")

		for targetLine in targetLines:
			fi.write(f"{targetLine}\n\n")

		fi.write("# build the final executable\nbuild_app: $(OBJS)\n\t$(COMP) $(CFLAGS) $(CV_FLAGS) $(QT_FLAGS) -o $(TARGET) $(OBJS) $(CV_LIBS) $(QT_LIBS)\n\n.PHONY: clean\nclean:\n\trm *.o")


def main():
	files = os.listdir()
	sources = [f for f in files if f[-3:] == ".cc"]
	headers = [f for f in files if f[-3:] == ".hh"]
	exe = "app"
	includeDict = {}

	for src in sources:
		includeStr = checkIncludes(src, headers)

		if includeStr == "neither":
			printf(f"opencv nor QT library found for {src}")
			sys.exit(-1)

		includeDict[src[:-3]] = includeStr

	writeMake(sources, headers, includeDict, exe)


if __name__ == "__main__":
	main()

