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

/*Structure definition*/
/**
 * struct path_dir - singly linked list
 * @str: string with whole folder
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct path_dir
{
	char *str;
	unsigned int len;
	struct path_dir *next;
} p_node;

/**
 * struct creator_params - singly linked list
 * @line: pointer that stores what the user writes
 * @counter: counter of shell, shows error in the lines
 * @en_variable: path of the enviroment variable
 * @argv: Entry to program arguments
 * @start: Indicates to continue prompt cycle
 * @status: Returns the number of executing code of every process
 *
 * Description: This structure give us input arguments
 * to create processes - for Holberton projectpu
 */
typedef struct creator_params
{
	char **line;
	int *counter;
	char **argv;
	char *start;
	int *status;
} creator_args;

/* Space for function prototypes*/
int _putchar(char c);
int _puts(char *s);
int process_selector(char *filename, char **command, int *status);
void free_grid(char **grid, int height);
char **extract_string(char *string, int *data_length);
void *_calloc(unsigned int nmemb, unsigned int size);
char *_memset(char *s, char b, unsigned int n);
int _strcmp(char *p1, char *p2);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *c_number_to_arr(char *array_data, int n);
unsigned int cal_digits(unsigned int n);
void errno_lin_st(char *name, char *error);
int errno_per(char *name, int line, char *error);
int errno_found(char *name, int line, char *error);
char *path_searcher(char **command, char *env);
char *_getenv(const char *name);
int new_pro(creator_args param);
int _atoi(char *s);
int print_env(char **env);
void handler_ctrlc(int sig);
int isNumber(char *s);
int errno_int(char *name, int line, char *error, char *code);
int handle_error(creator_args param, char **command, int *data_length);
int str_srch(char *array, char charac);
/*space for extern variables*/
extern char **environ;
#endif
