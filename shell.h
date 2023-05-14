#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>


#define MAX_INPUT_SIZE 1024


int execute(char *cmd, char *argv[], char **av, char **envp);
void hundle_ctrl(int signal);
int prompt(char **argv, char **envp);
char **split(char *line);
void handle_signal(int signum);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
char *path(char *cmd);
void exit_shell(int status);







#endif
