cmake_minimum_required(VERSION 3.10)
project(SysY)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Java)

add_definitions("-Wall -g")

include_directories(
    ${PROJECT_SOURCE_DIR}/third_party/
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/src/frontend/
    ${PROJECT_SOURCE_DIR}/src/frontend/parser/
    ${PROJECT_SOURCE_DIR}/src/frontend/scope/
    ${PROJECT_SOURCE_DIR}/src/frontend/symb/
    ${PROJECT_SOURCE_DIR}/src/frontend/tac/
    ${PROJECT_SOURCE_DIR}/src/frontend/translation/
    ${PROJECT_SOURCE_DIR}/src/frontend/type/
    ${PROJECT_SOURCE_DIR}/src/backend/
    ${PROJECT_SOURCE_DIR}/src/backend/asm/
    ${PROJECT_SOURCE_DIR}/src/3rdparty/
    ${PROJECT_SOURCE_DIR}/src/optimizer/
    ${PROJECT_SOURCE_DIR}/src/util/
)

file(GLOB antlr4-cpp-src
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/atn/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/dfa/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/misc/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/support/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/tree/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/tree/pattern/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-runtime/tree/xpath/*.cpp
)
add_library(antlr4-cpp-runtime ${antlr4-cpp-src})

execute_process(
    WORKING_DIRECTORY
        ${PROJECT_SOURCE_DIR}/src/frontend/parser/
    # Note that this command runs in pure shell
    COMMAND
        java -jar ${PROJECT_SOURCE_DIR}/third_party/antlr-4.8-complete.jar -Dlanguage=Cpp -no-listener -visitor SysY.g4
)

file(GLOB src_dir
    ${PROJECT_SOURCE_DIR}/src/frontend/parser/SysYLexer.cpp
    ${PROJECT_SOURCE_DIR}/src/frontend/parser/SysYParser.cpp
    ${PROJECT_SOURCE_DIR}/src/frontend/parser/SysYVisitor.cpp
    ${PROJECT_SOURCE_DIR}/src/frontend/parser/SysYBaseVisitor.cpp
    ${PROJECT_SOURCE_DIR}/src/frontend/scope/*.cpp
    ${PROJECT_SOURCE_DIR}/src/frontend/symb/*.cpp
    ${PROJECT_SOURCE_DIR}/src/frontend/tac/*.cpp
    ${PROJECT_SOURCE_DIR}/src/frontend/translation/*.cpp
    ${PROJECT_SOURCE_DIR}/src/frontend/type/*.cpp
    ${PROJECT_SOURCE_DIR}/src/optimizer/*.cpp
    ${PROJECT_SOURCE_DIR}/src/backend/asm/*.cpp
    ${PROJECT_SOURCE_DIR}/src/util/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(SysY ${src_dir})
target_link_libraries(SysY antlr4-cpp-runtime)
target_link_libraries(SysY gc)

# Add custom target update_antlr, use `make update_antlr` to update your lexer & grammar rules anytime
add_custom_target(update_antlr
    WORKING_DIRECTORY
        ${PROJECT_SOURCE_DIR}/src/frontend/parser/
    COMMAND 
        java -jar ${PROJECT_SOURCE_DIR}/third_party/antlr-4.8-complete.jar -Dlanguage=Cpp -no-listener -visitor SysY.g4
    COMMENT 
        "Auto updates for developing antlr grammar"
)