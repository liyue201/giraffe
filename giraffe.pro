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
                    src/KMainWindow.h \
               
               
                
                
SOURCES         =   src/main.cpp \
                    src/KMainWindow.cpp \
                 
                

