TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    CAtbashCoding.cpp \
    CGronsfeldCoding.cpp \
    CVigenereCoding.cpp \
    CTrisemusCoding.cpp \
    LetterCoord.cpp \
    CUserInterface.cpp

HEADERS += \
    CAtbashCoding.hpp \
    CGronsfeldCoding.hpp \
    CVigenereCoding.hpp \
    CTrisemusCoding.hpp \
    LetterCoord.hpp \
    CUserInterface.hpp \
    Helper.hpp
