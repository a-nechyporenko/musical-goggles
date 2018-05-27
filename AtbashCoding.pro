TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    CAtbashCoding.cpp \
    IAlphabet.cpp \
    CGronsfeldCoding.cpp

HEADERS += \
    CAtbashCoding.hpp \
    IAlphabet.hpp \
    CGronsfeldCoding.hpp
