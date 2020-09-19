#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void showMenu();
void addBook();
void showAllBooks();
char getAnswer();
void checkPublisher();
void checkTitle();
void checkAuthor();
void showCheckMenu();
void setCategory();
struct tm getTime();
void eraseBooks();

#endif
