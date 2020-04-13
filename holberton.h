#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

/*  space to include libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* Space for function prototypes*/
int _putchar(char c);
int _puts(char *s);
int process_selector(char **command, int *status);
void free_grid(char **grid, int height);
char **extract_string(char *string, int *data_length);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_memset(char *s, char b, unsigned int n);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *c_number_to_arr(char *array_data, int n);
unsigned int cal_digits(unsigned int n);
void errno_lin_st(char *name, char *error);
void errno_per(char *name, int line, char *error);
int errno_found(char *name, int line, char *error);
/*space for extern variables*/
extern char **environ;
#endif
