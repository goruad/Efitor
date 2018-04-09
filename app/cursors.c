/**
 * cursor.c -- реализует основные функции курсора
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "text/_text.h"

/**
 * Возвращает позицию курсора
 * 
 * @param txt текст
 * @returns none
 */
int pos_return(text txt)
{
    return txt -> cursor -> position;
}


/**
 * Возвращает строку курсора
 * 
 * @param txt текст
 * @returns строку курсора
 */
struct _node *line_return(text txt)
{
    return txt -> cursor -> line;
}


/**
 * Вставляем в текст курсор
 *
 * @param txt текст
 * @returns none
 *
 */
void print_cursor(text txt){
    int i;
    node *line = txt->cursor->line;
    /* Сдвиг части строки за курсором вправо */
    for(i = strlen(line->contents); i > txt->cursor->position; i--)
		line->contents[i]= line->contents[i - 1];
    (line->contents)[txt->cursor->position]='|';
}

/**
 * Удаляем курсор из текста
 * 
 * @param txt текст
 * @returns none
 *
 */
void remove_cursor(text txt){
    int i;
    node *line = txt->cursor->line;
    /* Сдвиг строки за курсором влево */
    for(i = txt->cursor->position; i < (signed)strlen(line->contents); i++)
	line->contents[i]= line->contents[i + 1];
}
