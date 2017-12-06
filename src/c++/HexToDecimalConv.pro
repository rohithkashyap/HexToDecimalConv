#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T10:34:02
#
#-------------------------------------------------

QT += core gui widgets

TARGET = HexToDecimalConv
TEMPLATE  = app
CONFIG   += c++11
#RC_FILE = HexToDecimalConv.rc


SOURCES += main.cpp\
        tcHexToDec.cpp \
    tcMsgViewDlg.cpp

HEADERS  += tcHexToDec.h \
    tcMsgViewDlg.h

FORMS    += tcHexToDec.ui \
    tcMsgViewDlg.ui

DESTDIR     = ../../bin
MOC_DIR     = ../../bld/HexToDecimalConv
OBJECTS_DIR = ../../bld/HexToDecimalConv
