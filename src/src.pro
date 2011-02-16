TEMPLATE = app

TARGET = qtbot
HEADERS += ircbot.h scriptrunner.h mprisreader.h
SOURCES += main.cpp ircbot.cpp scriptrunner.cpp mprisreader.cpp


MOC_DIR = build
OBJECTS_DIR = build
UI_DIR = build

CONFIG += libircclient-qt debug
DESTDIR = build
QT += network script dbus