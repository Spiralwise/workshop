QT += \
    widgets

CONFIG += \
		-std=c++11

SOURCES += \
    main.cpp \
    src/skizzwindow.cpp \
    src/skizzmainwindow.cpp \
    src/skizzedited.cpp

HEADERS += \
    src/skizzwindow.h \
    src/skizzmainwindow.h \
    src/skizzedited.h

FORMS += \
    src/skizzedited.ui
