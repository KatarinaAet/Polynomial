TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    polynomial.cpp \
    quotient.cpp \
    storage.cpp

HEADERS += \
    polynomial.h \
    quotient.h \
    function.h \
    storage.h

