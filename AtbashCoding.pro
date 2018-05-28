TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    CAtbashCoding.cpp \
    IAlphabet.cpp \
    CGronsfeldCoding.cpp \
    CVigenereCoding.cpp \
    CTrisemusCoding.cpp \
    LetterCoord.cpp

HEADERS += \
    CAtbashCoding.hpp \
    IAlphabet.hpp \
    CGronsfeldCoding.hpp \
    CVigenereCoding.hpp \
    CTrisemusCoding.hpp \
    LetterCoord.hpp
