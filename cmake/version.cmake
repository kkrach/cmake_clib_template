#
# Creates version.h in cmake build directory
#
# In CMakeLists.txt the following lines have to be added:
#
#   include(version.cmake)
#   ADD_DEPENDENCIES(my_project version)
#

FIND_PACKAGE(Git)

if (NOT GIT_FOUND)
    set(GIT_EXECUTABLE "/usr/bin/git")
    set(GIT_FOUND true)
    set(GIT_WORKAROUND true)
    message(WARNING "No git executable found! Setting variable \$GIT_EXECUTABLE temporarily to ${GIT_EXECUTABLE}")
endif()

FILE(WRITE ${CMAKE_BINARY_DIR}/version.h.in
"// Generated file - do not edit!
\#define PROJECT_NAME \"${CMAKE_PROJECT_NAME}\"
\#define GIT_EXECUTABLE \"${GIT_EXECUTABLE}\"
\#define GIT_SOURCE_VERSION \"@GIT_SOURCE_VERSION@\"
\#define GIT_SOURCE_DATE \"@GIT_SOURCE_DATE@\"
\#define GIT_REPOSITORY \"@GIT_REPOSITORY@\"
\#define COMPILE_HOST \"@COMPILE_HOST@\"
\#define COMPILE_DATE \"@COMPILE_DATE@\"
\#define COMPILE_USER \"$ENV{USER}\"
\#define COMPILE_SOURCE \"${CMAKE_SOURCE_DIR}\"
\#define COMPILE_DIR \"${CMAKE_BINARY_DIR}\"
"
)
FILE(WRITE ${CMAKE_BINARY_DIR}/version.cmake
"
EXECUTE_PROCESS(
    COMMAND date \"+%Y-%m-%d %H:%M:%S %z\"
    OUTPUT_VARIABLE COMPILE_DATE
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
EXECUTE_PROCESS(
    COMMAND ${GIT_EXECUTABLE} -C ${CMAKE_SOURCE_DIR} describe --long --dirty --always
    OUTPUT_VARIABLE GIT_SOURCE_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
EXECUTE_PROCESS(
    COMMAND ${GIT_EXECUTABLE} -C ${CMAKE_SOURCE_DIR} log -1 --date=iso --format=%cd
    OUTPUT_VARIABLE GIT_SOURCE_DATE
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
EXECUTE_PROCESS(
    COMMAND ${GIT_EXECUTABLE} -C ${CMAKE_SOURCE_DIR} config --get remote.origin.url
    OUTPUT_VARIABLE GIT_REPOSITORY
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
EXECUTE_PROCESS(
    COMMAND hostname --long
    OUTPUT_VARIABLE COMPILE_HOST
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
CONFIGURE_FILE(\${SRC} \${DST} @ONLY)
")

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR})

ADD_CUSTOM_TARGET(
   version
   ${CMAKE_COMMAND} -D SRC=${CMAKE_BINARY_DIR}/version.h.in
                    -D DST=${CMAKE_BINARY_DIR}/version.h
                    -P ${CMAKE_BINARY_DIR}/version.cmake
)

if (GIT_WORKAROUND)
    set(GIT_EXECUTABLE "GIT_EXECUTABLE_NOTFOUND")
    set(GIT_FOUND false)
    unset(GIT_WORKAROUND)
endif()
