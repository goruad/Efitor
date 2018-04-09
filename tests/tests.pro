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
    text/text.h \
    text/_text.h \
    common.h

SOURCES +=     main.cpp \
    ../app/myfunc.c \
    ../app/cursors.c \
    create_text.c \
    showwordbeginnings.c \
    append_line.c \
    load.c \
    process_forward.c \
    process_forward_extra_option.c \
    process_output_2_1.c \
    remove_all.c \
    save.c \
    show.c \
    tracer.c

INCLUDEPATH += ../app

DISTFILES += \
    nada
