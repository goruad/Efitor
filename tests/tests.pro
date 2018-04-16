include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES+=INPUTDIR=\\\"$$PWD/input/\\\"

HEADERS +=     tst_test1.h \
    ../app/myfunc.h \
    fibonachi_test.h \
    ../app/text/text.h \
    ../app/text/_text.h \
    ../app/common.h

SOURCES +=     main.cpp \
    ../app/myfunc.c \
    ../app/cursors.c \
    ../app/create_text.c \
    ../app/showwordbeginnings.c \
    ../app/append_line.c \
    ../app/load.c \
    ../app/process_forward.c \
    ../app/process_forward_extra_option.c \
    ../app/process_output_2_1.c \
    ../app/remove_all.c \
    ../app/save.c \
    ../app/show.c \
    ../app/tracer.c

INCLUDEPATH += ../app

DISTFILES += \
    nada
