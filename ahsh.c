#include "include/libs.h"
#include "ahsh.h"

// Function declarations for builtin commands
int sh_echo(char **args);
int sh_exit(char **args);
int sh_help(char **args);

int sh_num_builtins() {
  	return sizeof(builtin_str) / sizeof(char *);
}

int sh_echo(char **args)
{
	if (args[1] == NULL) {
		fprintf(stderr, "sh: expected argument for \"echo\" command\n");
	}
		else {
			int i = 1;
			while (args[i] != NULL) {
				printf("%s ", args[i]);
				i++;
			}
			printf("\n");
		}
	return 1;
}

int sh_help(char **args)
{
	int i;
	printf("Builtin Commands:\n");

	for (i = 0; i < sh_num_builtins(); i++) {
		printf("  %s\n", builtin_str[i]);
	}
	return 1;
}

int sh_exit(char **args)
{
  	return 0;
}

int sh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) {
		// Child process
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		// Error forking
		perror("sh");
	} else {
		// Parent process
		do {
		waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}

int sh_Execute(char **args)
{
	int i;

	if (args[0] == NULL) {
		// An empty command was entered. Like how my brain processes math problems :(
		return 1;
	}

	for (i = 0; i < sh_num_builtins(); i++) {
		if (strcmp(args[0], builtin_str[i]) == 0) {
			return (*builtin_func[i])(args);
		}
	}

	return sh_launch(args);
}

char *shReadLine(void)
{
#ifdef sh_USE_STD_GETLINE
	char *line = NULL;
	ssize_t bufsize = 0; // have getline allocate a buffer for us
	if (getline(&line, &bufsize, stdin) == -1) {
		if (feof(stdin)) {
		exit(EXIT_SUCCESS);  // We received an EOF
		} else  {
		perror("sh: getline\n");
		exit(EXIT_FAILURE);
		}
	}
	return line;
#else
#define sh_RL_BUFSIZE 1024
	int bufsize = sh_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		fprintf(stderr, "sh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1) {
		c = getchar();

		if (c == EOF) {
		exit(EXIT_SUCCESS);
		} else if (c == '\n') {
		buffer[position] = '\0';
		return buffer;
		} else {
		buffer[position] = c;
		}
		position++;

		if (position >= bufsize) {
		bufsize += sh_RL_BUFSIZE;
		buffer = realloc(buffer, bufsize);
		if (!buffer) {
			fprintf(stderr, "sh: allocation error\n");
			exit(EXIT_FAILURE);
		}
		}
	}
#endif
}

#define sh_TOK_BUFSIZE 64
#define sh_TOK_DELIM " \t\r\n\a"

char **shsplitline(char *line)
{
	int bufsize = sh_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_backup;

	if (!tokens) {
		fprintf(stderr, "sh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, sh_TOK_DELIM);
	while (token != NULL) {
		tokens[position] = token;
		position++;

		if (position >= bufsize) {
		bufsize += sh_TOK_BUFSIZE;
		tokens_backup = tokens;
		tokens = realloc(tokens, bufsize * sizeof(char*));
		if (!tokens) {
			free(tokens_backup);
			fprintf(stderr, "sh: allocation error\n");
			exit(EXIT_FAILURE);
		}
		}

		token = strtok(NULL, sh_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}

void loop_sh(void)
{
	char *line;
	char **args;
	int status;

	do {
		if (shInfo == "1") {
			printf("%s", shName);
			printf("|%s", name);

			char cwd[1024];

			if (getcwd(cwd, sizeof(cwd)) != NULL) {
				printf(" %s", cwd);
			} else {
				perror("sh: getcwd");
			}
		}
		printf(" %s", prefix);
		printf(" ");
		line = shReadLine();
		args = shsplitline(line);
		status = sh_Execute(args);

		free(line);
		free(args);
	} while (status);
}

int main(int argc, char **argv)
{
	printf("%s", shName);
	printf("\n");
	printf("%s", shVersion);
	printf("\nType \"help\" for commands\n"); // doesn't work in real life
	loop_sh();

	return EXIT_SUCCESS;
}