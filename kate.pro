TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/main.cpp \
        src/parser/AST.cpp \
        src/parser/Parser.cpp

HEADERS += \
    src/parser/AST.h \
    src/parser/AstNode.h \
    src/parser/Parser.h
