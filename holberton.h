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
 * @direct: string with whole folder
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
} path_dir_node;

/* Space for function prototypes*/
int _putchar(char c);
int _puts(char *s);
int process_selector(char *filename, char **command, int *status);
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
int errno_per(char *name, int line, char *error);
int errno_found(char *name, int line, char *error);
char *path_searcher(char **command, char *env);
char *_getenv(const char *name);
void free_list(path_dir_node *head);
size_t print_list(const path_dir_node *h);
void put_node(path_dir_node **head, path_dir_node *new_node, path_dir_node *old_clone);
char *get_match(const path_dir_node *h);
int create_process(char *line, int counter, char *envariable, char *argv[]);
/*space for extern variables*/
extern char **environ;
#endif
