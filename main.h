#ifndef _MAIN_H_
#define _MAIN_H_
int _strlen(char *s);
void _puts(char *s);
void _putchar(char c);
char *_strcpy(char *dest, char *src);
char *prompt(void);
char *_strncpy(char *dest, char *src, int n);
char **split(char *string);
int _strcmp(char *s1, char *s2);
void free_split(char **string);
char *get_command(char *command);
char *_strcat(char *dest, char *src);
char *prefix(char *prefix, char *str);
char *_strdup(char *str);
int _pow(int x, int y);
int _atoi(char *str);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_itoa(int a);
void replace_variables(char **args, int status, char **env);
void reverse_string(char *s);
int _abs(int d);
#endif
