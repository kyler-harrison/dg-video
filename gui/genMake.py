#!/usr/bin/python3

import os


def writeMake(sources, headers, exeTarget, makePath="Makefile"):
	"""
	creates a Makefile from .cc and .hh files, make to build final exe

	sources: list of .cc files in pwd
	headers: list of .hh files in pwd
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
	allTarget = f"all: {objsStr} build_app\n\t@echo It has been made."

	# create object file targets
	# TODO this is only good for things that only include QT libs (will need to change stuff when using OpenCV libs)
	# will need to read each file and examine includes
	targetLines = []

	for obj in objs:
		objBase = obj[:-2]

		if f"{objBase}.hh" in headers:
			targetLine = f"{obj}: {objBase}.cc {objBase}.hh\n\t$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o {obj} {objBase}.cc"
		else:
			targetLine = f"{obj}: {objBase}.cc\n\t$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o {obj} {objBase}.cc"

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
	writeMake(sources, headers, exe)


if __name__ == "__main__":
	main()

