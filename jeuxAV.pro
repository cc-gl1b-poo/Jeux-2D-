#-------------------------------------------------
#
# Project created by QtCreator 2025-05-19T18:18:27
#
#-------------------------------------------------

QT       += core gui \
          multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jeuxAV
TEMPLATE = app


SOURCES += main.cpp\
        MyRect.cpp \
    Bullet.cpp \
    enemy.cpp \
    Health.cpp \
    Player.cpp \
    Score.cpp \
    Game.cpp

HEADERS  += MyRect.h \
    Bullet.h \
    enemy.h \
    Health.h \
    Player.h \
    Score.h \
    Game.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
