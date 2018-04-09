TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=  \
    myfunc.c \
    showwordbeginnings.c \
    process_forward.c \
    cursors.c \
    editor.c \
    show.c \
    save.c \
    process_forward_extra_option.c \
    tracer.c \
    load.c \
    create_text.c \
    process_output_2_1.c \
    append_line.c \
    remove_all.c

HEADERS += \
    myfunc.h \
    text/text.h \
    common.h \
    text/_text.h \


QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SUBDIRS += \
    app.pro \
    app.pro

DISTFILES += \
    nada
