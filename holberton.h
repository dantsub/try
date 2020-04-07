#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_
/*=================*/
/*    Libraries    */
/*=================*/
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
/*==================*/
/*    Structures    */
/*==================*/
/**
 * list_t - Entry point
 * @var: member of env or paths.
 * @len: lenght of var.
 * @next: pointer to a new node
 * Description: 
 */
typedef struct list_s
{
	char *var;
	int len;
	struct list_s *next;
} list_t;

/**
 * global_s - 
 * 
 * 
 */
typedef struct global_s
{
	char *buff;
	size_t len;
	list_t *henv;
	list_t *hpath;
} global_t;

/*==================*/
/*    Global var    */
/*==================*/
extern char **environ;
global_t *init(void);

/*==================*/
/*    Prototypes    */
/*==================*/

/* Manage strings */
int _strlen(char *str);
char *_strdup(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int bytes);

/* Manage memory */
int malloc_checked(void *pointer);
void *_calloc(size_t nmemb, size_t size);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* frees */
void allfree(void);
void dfree(char **array);
void free_list(list_t *head);

/* helpers */

/* prompt and aux */
void _puts(char *s);
void prompt(char *av);

/* environment functions */
void lenv(void);
char *_getenv(char *name);
/* path functions */
int check_path(char *args);
char *path(char *args);
void list_path(void);
char **split_args(char *s, char *delim);

/* process functions */
void process(char **argv, char *av);
void child(char **args, char *name);

/* linked list functions */
list_t *addnode_end(list_t **head, char *var);

#endif /* _SIMPLE_SHELL_ */
