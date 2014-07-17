
TEMPLATE = app
TARGET = entities
INCLUDEPATH += .
LIBS = -ldxfrw
# Input
HEADERS += dxfrw_intf.h \
    write_entities.h
SOURCES += test.cpp \
    write_entities.cpp
