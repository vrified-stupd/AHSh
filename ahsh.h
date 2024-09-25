#ifndef AHSH_H
#define AHSH_H

char *builtin_str[];
int (*builtin_func[]) (char **);
int sh_num_builtins();
int sh_launch(char **args);
int sh_Execute(char **args);
int sh_echo(char **args);
int sh_exit(char **args);
int sh_help(char **args);
char **shsplitline(char *line);
char *shReadLine(void);
int sh_Execute(char **args);
int sh_launch(char **args);
void loop_sh(void);
int main(int argc, char **argv);

#endif