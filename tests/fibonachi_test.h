#ifndef FIBONACHI_H
#define FIBONACHI_H
#define OUTPUT 1
#include <gtest/gtest.h>
#include <fcntl.h>
#include <unistd.h>
#include<errno.h>
extern "C" {
#include "common.h"
#include"text/text.h"
#include"text/_text.h"
 void show_word_beginnings(int j, char *contents);
}


/*TEST(fibonachiTest, num0) {
    ASSERT_EQ(fibonachi(0), 0);
    ASSERT_EQ(fibonachi(1), 1);
    ASSERT_EQ(fibonachi(2), 2);
}

TEST(fibonachiTest, greather2) {
    ASSERT_EQ(fibonachi(5), 5);
    ASSERT_EQ(fibonachi(10), 55);
}

TEST(fibonachiTest, negative) {
    ASSERT_EQ(fibonachi(-1), 0);
}
*/
//TEST(fibonachiTest, num0) {
  //  ASSERT_EQ(showwordbeginnings("tv"), "t");
    //ASSERT_EQ(showwordbeginnings("c"), "c");
    //ASSERT_EQ(showwordbeginnings("application"),"a");
//}
TEST(showwordbeginningsTest, num0){
    text txt = create_text();
    load(txt,(char*)"nada" );
    showwordbeginnings(txt);
    ASSERT_TRUE(true);
}
TEST(group_func1, params) {
char *nada = (char *)malloc(sizeof(char) * 1024);
// ОТКРЫВАЕМ ФАЙЛ
//Создаем выходной файл
errno = 0;
int out = open("nadaout", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
int oldOutput = dup(1);
dup2(out,1);
 ASSERT_EQ(errno,0);
close(out);
sprintf(nada, "%s/nada", INPUTDIR);
printf("%s",nada);
text txt = create_text();
load(txt, nada);

showwordbeginnings(txt);
fflush(stdout);
dup2(oldOutput,1);

SUCCEED();
}
TEST(for_test,num1){
    char* str= (char*)malloc(1000);
    str[0] = '\0';
    show_word_beginnings(0, str);
    SUCCEED();
}
TEST(for_test,num2){
    char* str= (char*)malloc(1000);
    str[0] = '\0';
    show_word_beginnings(1000, str);
    SUCCEED();
}
TEST(for_test, num3){
    char* str= (char*)malloc(1000);
    str[0] = 'a';
    str[1] = 'b';
    show_word_beginnings(1000, str);
    SUCCEED();
}
TEST(for_test, num4){
    char* str= (char*)malloc(1000);
    str[0] = 'b';
    str[1] = 's';
    str[2] = '\0';
    int outFd = open("nadaout1", O_WRONLY|O_CREAT);
    int oldOutput = dup(OUTPUT);
    dup2(outFd, OUTPUT);
    // запуск функции

    show_word_beginnings(3, str);
 fflush(stdout);
    close(outFd);
    dup2(oldOutput, OUTPUT);
int fd1 = open("nadaout1", O_WRONLY|O_CREAT);
char* buffer = (char*)malloc(1000);
int count1 = read(fd1, buffer, 1000);
int fd2 = open("nadach", O_WRONLY|O_CREAT);
char* buffer1 = (char*)malloc(1000);
int count2 = read(fd2, buffer1, 1000);
ASSERT_EQ(count1,count2);
for(int i=0; i<count1;i++){
    ASSERT_EQ(buffer[i],buffer1[i]);
}
close(fd1);
close(fd2);
free(buffer);
free(buffer1);
}

#endif // FIBONACHI_H

