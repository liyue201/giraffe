QT += widgets gui network


CONFIG  -= flat

debug {
    TARGET      = giraffed
    DESTDIR     = ./bin/debug
    OBJECTS_DIR = ./tmp/debug
    MOC_DIR     = ./tmp/debug
}
release {
    TARGET      = giraffe
    DESTDIR     = ./bin/release
    OBJECTS_DIR = ./tmp/release
    MOC_DIR     = ./tmp/release
}

INCLUDEPATH += .

HEADERS        =    src/global.h \
                    src/MainWindow.h \
                    src/ReqBodyWidget.h \
                    src/ReqCookieWidget.h \
                    src/ReqHeaderWidget.h \
                    src/RespBodyWidget.h \
                    src/RespCookieWidget.h \
                    src/RespHeaderWidget.h \
               
                
SOURCES         =   src/main.cpp \
                    src/MainWindow.cpp \
                    src/ReqBodyWidget.cpp \
                    src/ReqCookieWidget.cpp \
                    src/ReqHeaderWidget.cpp \
                    src/RespBodyWidget.cpp \
                    src/RespCookieWidget.cpp \
                    src/RespHeaderWidget.cpp \
                

