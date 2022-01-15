GPP = g++
GPP_FLAGS = -O1 -g
GREP = grep -Po "[^.+\.(\w|\w\w):].+" | tr -d "\n" | tr -d "\\"
DEFINES = -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
TARGET = app
CV_INCLUDES = -I /usr/local/include/opencv2
CV_OBJ_LIBS = -L /usr/local/lib
CV_FLAGS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_stitching
CV_LIBS = /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_calib3d.so.405 /usr/local/lib/libopencv_calib3d.so.4.5.5 /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_core.so.405 /usr/local/lib/libopencv_core.so.4.5.5 /usr/local/lib/libopencv_dnn.so /usr/local/lib/libopencv_dnn.so.405 /usr/local/lib/libopencv_dnn.so.4.5.5 /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_features2d.so.405 /usr/local/lib/libopencv_features2d.so.4.5.5 /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_flann.so.405 /usr/local/lib/libopencv_flann.so.4.5.5 /usr/local/lib/libopencv_gapi.so /usr/local/lib/libopencv_gapi.so.405 /usr/local/lib/libopencv_gapi.so.4.5.5 /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_highgui.so.405 /usr/local/lib/libopencv_highgui.so.4.5.5 /usr/local/lib/libopencv_imgcodecs.so /usr/local/lib/libopencv_imgcodecs.so.405 /usr/local/lib/libopencv_imgcodecs.so.4.5.5 /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_imgproc.so.405 /usr/local/lib/libopencv_imgproc.so.4.5.5 /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_ml.so.405 /usr/local/lib/libopencv_ml.so.4.5.5 /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_objdetect.so.405 /usr/local/lib/libopencv_objdetect.so.4.5.5 /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_photo.so.405 /usr/local/lib/libopencv_photo.so.4.5.5 /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_stitching.so.405 /usr/local/lib/libopencv_stitching.so.4.5.5 /usr/local/lib/libopencv_videoio.so /usr/local/lib/libopencv_videoio.so.405 /usr/local/lib/libopencv_videoio.so.4.5.5 /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_video.so.405 /usr/local/lib/libopencv_video.so.4.5.5
QT_OBJ_FLAGS = -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB $(DEFINES)
QT_INCLUDES = -I. -I. -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QT_FLAGS = -lpthread
QT_LIBS = /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5Core.so /usr/lib/x86_64-linux-gnu/libGL.so
cv/video_DEPENDS = $(shell $(GPP) -MM cv/video.cc | $(GREP))
gui/main_DEPENDS = $(shell $(GPP) -MM gui/main.cc | $(GREP))
gui/moc_parentLayout_DEPENDS = gui/parentLayout.hh $(shell $(GPP) -MM gui/parentLayout.hh | $(GREP))
gui/parentLayout_DEPENDS = $(shell $(GPP) -MM gui/parentLayout.cc | $(GREP))
gui/vidControls_DEPENDS = $(shell $(GPP) -MM gui/vidControls.cc | $(GREP))
gui/moc_parentWidget_DEPENDS = gui/parentWidget.hh $(shell $(GPP) -MM gui/parentWidget.hh | $(GREP))
gui/parentWidget_DEPENDS = $(shell $(GPP) -MM gui/parentWidget.cc | $(GREP))
gui/moc_rightLayout_DEPENDS = gui/rightLayout.hh $(shell $(GPP) -MM gui/rightLayout.hh | $(GREP))
gui/rightLayout_DEPENDS = $(shell $(GPP) -MM gui/rightLayout.cc | $(GREP))
gui/menu_DEPENDS = $(shell $(GPP) -MM gui/menu.cc | $(GREP))
gui/vidViewer_DEPENDS = $(shell $(GPP) -MM gui/vidViewer.cc | $(GREP))
gui/moc_window_DEPENDS = gui/window.hh $(shell $(GPP) -MM gui/window.hh | $(GREP))
gui/window_DEPENDS = $(shell $(GPP) -MM gui/window.cc | $(GREP))
gui/moc_leftLayout_DEPENDS = gui/leftLayout.hh $(shell $(GPP) -MM gui/leftLayout.hh | $(GREP))
gui/leftLayout_DEPENDS = $(shell $(GPP) -MM gui/leftLayout.cc | $(GREP))
OBJS = cv/video.o gui/main.o gui/parentLayout.o gui/vidControls.o gui/parentWidget.o gui/rightLayout.o gui/menu.o gui/vidViewer.o gui/window.o gui/leftLayout.o gui/moc_parentLayout.o gui/moc_parentWidget.o gui/moc_rightLayout.o gui/moc_window.o gui/moc_leftLayout.o

all: gui/mocPredefs.h gui/moc_parentLayout.cc gui/moc_parentWidget.cc gui/moc_rightLayout.cc gui/moc_window.cc gui/moc_leftLayout.cc $(OBJS) build_app
	@echo It has been made.

gui/mocPredefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	$(GPP) -pipe -O2 -Wall -W -dM -E -o gui/mocPredefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

cv/video.o: $(cv/video_DEPENDS)
	$(GPP) $(CV_INCLUDES) $(CV_OBJ_LIBS) -c -o cv/video.o cv/video.cc

gui/main.o: $(gui/main_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/main.o gui/main.cc

gui/moc_parentLayout.cc: $(gui/moc_parentLayout_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include gui/parentLayout.hh -o gui/moc_parentLayout.cc

gui/moc_parentLayout.o: gui/moc_parentLayout.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/moc_parentLayout.o gui/moc_parentLayout.cc

gui/parentLayout.o: $(gui/parentLayout_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/parentLayout.o gui/parentLayout.cc

gui/vidControls.o: $(gui/vidControls_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/vidControls.o gui/vidControls.cc

gui/moc_parentWidget.cc: $(gui/moc_parentWidget_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include gui/parentWidget.hh -o gui/moc_parentWidget.cc

gui/moc_parentWidget.o: gui/moc_parentWidget.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/moc_parentWidget.o gui/moc_parentWidget.cc

gui/parentWidget.o: $(gui/parentWidget_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/parentWidget.o gui/parentWidget.cc

gui/moc_rightLayout.cc: $(gui/moc_rightLayout_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include gui/rightLayout.hh -o gui/moc_rightLayout.cc

gui/moc_rightLayout.o: gui/moc_rightLayout.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/moc_rightLayout.o gui/moc_rightLayout.cc

gui/rightLayout.o: $(gui/rightLayout_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/rightLayout.o gui/rightLayout.cc

gui/menu.o: $(gui/menu_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/menu.o gui/menu.cc

gui/vidViewer.o: $(gui/vidViewer_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/vidViewer.o gui/vidViewer.cc

gui/moc_window.cc: $(gui/moc_window_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include gui/window.hh -o gui/moc_window.cc

gui/moc_window.o: gui/moc_window.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/moc_window.o gui/moc_window.cc

gui/window.o: $(gui/window_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/window.o gui/window.cc

gui/moc_leftLayout.cc: $(gui/moc_leftLayout_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include gui/leftLayout.hh -o gui/moc_leftLayout.cc

gui/moc_leftLayout.o: gui/moc_leftLayout.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/moc_leftLayout.o gui/moc_leftLayout.cc

gui/leftLayout.o: $(gui/leftLayout_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o gui/leftLayout.o gui/leftLayout.cc

build_app: $(OBJS)
	$(GPP) $(GPP_FLAGS) $(CV_FLAGS) $(QT_FLAGS) -o $(TARGET) $(OBJS) $(CV_LIBS) $(QT_LIBS)

.PHONY: clean
clean:
	rm -f moc*
	rm -f *.o
	rm -f cv/*.o
	rm -f gui/*.o