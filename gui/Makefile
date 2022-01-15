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
main_DEPENDS = $(shell $(GPP) -MM main.cc | $(GREP))
moc_parentLayout_DEPENDS = parentLayout.hh $(shell $(GPP) -MM parentLayout.hh | $(GREP))
parentLayout_DEPENDS = $(shell $(GPP) -MM parentLayout.cc | $(GREP))
vidControls_DEPENDS = $(shell $(GPP) -MM vidControls.cc | $(GREP))
moc_parentWidget_DEPENDS = parentWidget.hh $(shell $(GPP) -MM parentWidget.hh | $(GREP))
parentWidget_DEPENDS = $(shell $(GPP) -MM parentWidget.cc | $(GREP))
moc_rightLayout_DEPENDS = rightLayout.hh $(shell $(GPP) -MM rightLayout.hh | $(GREP))
rightLayout_DEPENDS = $(shell $(GPP) -MM rightLayout.cc | $(GREP))
menu_DEPENDS = $(shell $(GPP) -MM menu.cc | $(GREP))
vidViewer_DEPENDS = $(shell $(GPP) -MM vidViewer.cc | $(GREP))
moc_window_DEPENDS = window.hh $(shell $(GPP) -MM window.hh | $(GREP))
window_DEPENDS = $(shell $(GPP) -MM window.cc | $(GREP))
moc_leftLayout_DEPENDS = leftLayout.hh $(shell $(GPP) -MM leftLayout.hh | $(GREP))
leftLayout_DEPENDS = $(shell $(GPP) -MM leftLayout.cc | $(GREP))
../cv/video_DEPENDS = $(shell $(GPP) -MM ../cv/video.cc | $(GREP))
OBJS = main.o parentLayout.o vidControls.o parentWidget.o rightLayout.o menu.o vidViewer.o window.o leftLayout.o ../cv/video.o moc_parentLayout.o moc_parentWidget.o moc_rightLayout.o moc_window.o moc_leftLayout.o

all: mocPredefs.h moc_parentLayout.cc moc_parentWidget.cc moc_rightLayout.cc moc_window.cc moc_leftLayout.cc $(OBJS) build_app
	@echo It has been made.

mocPredefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	$(GPP) -pipe -O2 -Wall -W -dM -E -o mocPredefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

main.o: $(main_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o main.o main.cc

moc_parentLayout.cc: $(moc_parentLayout_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include parentLayout.hh -o moc_parentLayout.cc

moc_parentLayout.o: moc_parentLayout.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o moc_parentLayout.o moc_parentLayout.cc

parentLayout.o: $(parentLayout_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o parentLayout.o parentLayout.cc

vidControls.o: $(vidControls_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o vidControls.o vidControls.cc

moc_parentWidget.cc: $(moc_parentWidget_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include parentWidget.hh -o moc_parentWidget.cc

moc_parentWidget.o: moc_parentWidget.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o moc_parentWidget.o moc_parentWidget.cc

parentWidget.o: $(parentWidget_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o parentWidget.o parentWidget.cc

moc_rightLayout.cc: $(moc_rightLayout_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include rightLayout.hh -o moc_rightLayout.cc

moc_rightLayout.o: moc_rightLayout.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o moc_rightLayout.o moc_rightLayout.cc

rightLayout.o: $(rightLayout_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o rightLayout.o rightLayout.cc

menu.o: $(menu_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o menu.o menu.cc

vidViewer.o: $(vidViewer_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o vidViewer.o vidViewer.cc

moc_window.cc: $(moc_window_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include window.hh -o moc_window.cc

moc_window.o: moc_window.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o moc_window.o moc_window.cc

window.o: $(window_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o window.o window.cc

moc_leftLayout.cc: $(moc_leftLayout_DEPENDS) /usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/kyguy/dgvid/gui/mocPredefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/kyguy/dgvid/gui -I/home/kyguy/dgvid/gui -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/9 -I/usr/include/x86_64-linux-gnu/c++/9 -I/usr/include/c++/9/backward -I/usr/lib/gcc/x86_64-linux-gnu/9/include -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include leftLayout.hh -o moc_leftLayout.cc

moc_leftLayout.o: moc_leftLayout.cc
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o moc_leftLayout.o moc_leftLayout.cc

leftLayout.o: $(leftLayout_DEPENDS)
	$(GPP) $(QT_OBJ_FLAGS) $(QT_INCLUDES) -c -o leftLayout.o leftLayout.cc

../cv/video.o: $(../cv/video_DEPENDS)
	$(GPP) $(CV_INCLUDES) $(CV_OBJ_LIBS) -c -o ../cv/video.o ../cv/video.cc

build_app: $(OBJS)
	$(GPP) $(GPP_FLAGS) $(CV_FLAGS) $(QT_FLAGS) -o $(TARGET) $(OBJS) $(CV_LIBS) $(QT_LIBS)

.PHONY: clean
clean:
	rm -f moc*
	rm -f *.o
	rm -f ../cv/*.o