# general compiler stuff
COMP = g++
CFLAGS = -O1
OBJS = main.o parentLayout.o vidControls.o rightLayout.o menu.o vidViewer.o window.o leftLayout.o
TARGET = app

# opencv stuff (build objs, then to compilation with qt stuff)
CV_INCLUDES = -I /usr/local/include/opencv2
CV_OBJ_LIBS = -L /usr/local/lib
CV_FLAGS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_stitching
CV_LIBS = /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_calib3d.so.405 /usr/local/lib/libopencv_calib3d.so.4.5.5 /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_core.so.405 /usr/local/lib/libopencv_core.so.4.5.5 /usr/local/lib/libopencv_dnn.so /usr/local/lib/libopencv_dnn.so.405 /usr/local/lib/libopencv_dnn.so.4.5.5 /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_features2d.so.405 /usr/local/lib/libopencv_features2d.so.4.5.5 /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_flann.so.405 /usr/local/lib/libopencv_flann.so.4.5.5 /usr/local/lib/libopencv_gapi.so /usr/local/lib/libopencv_gapi.so.405 /usr/local/lib/libopencv_gapi.so.4.5.5 /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_highgui.so.405 /usr/local/lib/libopencv_highgui.so.4.5.5 /usr/local/lib/libopencv_imgcodecs.so /usr/local/lib/libopencv_imgcodecs.so.405 /usr/local/lib/libopencv_imgcodecs.so.4.5.5 /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_imgproc.so.405 /usr/local/lib/libopencv_imgproc.so.4.5.5 /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_ml.so.405 /usr/local/lib/libopencv_ml.so.4.5.5 /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_objdetect.so.405 /usr/local/lib/libopencv_objdetect.so.4.5.5 /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_photo.so.405 /usr/local/lib/libopencv_photo.so.4.5.5 /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_stitching.so.405 /usr/local/lib/libopencv_stitching.so.4.5.5 /usr/local/lib/libopencv_videoio.so /usr/local/lib/libopencv_videoio.so.405 /usr/local/lib/libopencv_videoio.so.4.5.5 /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_video.so.405 /usr/local/lib/libopencv_video.so.4.5.5

# qt stuff (build objs, then to compilation with opencv stuff)
QT_OBJ_FLAGS = -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
QT_INCLUDES = -I. -I. -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QT_FLAGS = -lpthread
QT_LIBS = /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so /usr/lib/x86_64-linux-gnu/libGL.so

all: main.o parentLayout.o vidControls.o rightLayout.o menu.o vidViewer.o window.o leftLayout.o build_app
	@echo It has been made.

#build object files
main.o: main.cc
	$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o main.o main.cc

parentLayout.o: parentLayout.cc parentLayout.hh
	$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o parentLayout.o parentLayout.cc

vidControls.o: vidControls.cc vidControls.hh
	$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o vidControls.o vidControls.cc

rightLayout.o: rightLayout.cc rightLayout.hh
	$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o rightLayout.o rightLayout.cc

menu.o: menu.cc menu.hh
	$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o menu.o menu.cc

vidViewer.o: vidViewer.cc vidViewer.hh
	$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o vidViewer.o vidViewer.cc

window.o: window.cc window.hh
	$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o window.o window.cc

leftLayout.o: leftLayout.cc leftLayout.hh
	$(COMP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o leftLayout.o leftLayout.cc

# build the final executable
build_app: $(OBJS)
	$(COMP) $(CFLAGS) $(CV_FLAGS) $(QT_FLAGS) -o $(TARGET) $(OBJS) $(CV_LIBS) $(QT_LIBS)

.PHONY: clean
clean:
	rm *.o