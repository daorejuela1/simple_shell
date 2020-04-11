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

/* Space for function prototypes*/
int _putchar(char c);
int _puts(char *s);
int process_selector(char **command, int *status);

/*space for extern variables*/
extern char **environ;
#endif
