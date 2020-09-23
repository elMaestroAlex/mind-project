cmake_minimum_required(VERSION 3.17)
project(kate)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/parser)

add_executable(kate
        src/parser/AST.cpp
        src/parser/AST.h
        src/parser/ast-nodes/AstNodeAbstract.h
        src/parser/Parser.cpp
        src/parser/Parser.h
        src/main.cpp 
        src/parser/Lexer.h 
        src/parser/Lexer.cpp
        src/parser/ast-nodes/AstNodeModel.h
        src/parser/ast-nodes/AstNodeModel.cpp
)
