#ifndef AHSH_H
#define AHSH_H

char *builtin_str[];
int (*builtin_func[]) (char **);
int sh_num_builtins();
int sh_launch(char **args);
int sh_Execute(char **args);

#endif