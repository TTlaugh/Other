#ifndef HANGMAN_HEADERS
#define HANGMAN_HEADERS

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<curses.h>
#include<time.h>


typedef enum Bool { True, False } Bool;
char * hide(int size);
char inputChar(int index ,char *entered);
void checkChar(const char *Word, char *hiddenWord, int size, int *countTrue, int *hp, char inputChar);
int countChar(const char *word);
void printGame(char *hiddenWord, int hp, char * entered);
char *randomWord(const char *fileLocation);

#endif

