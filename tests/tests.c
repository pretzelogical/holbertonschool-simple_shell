#include "../main.h"

void test_search(char **parsed_path);

/**
 * test_env- tests functions in the env part of the program
 * @envp: pointer to environment variables
 *
 * Return: void return
*/
void test_env(char **env)
{
	char *getted;
	char **parsed;
	int i;

	getted = get_path(env);
	printf("getpath(env) = %s\n", getted);
	parsed = parse_path(getted);

	for (i = 0; i < PATH_LIMIT; i++)
	{
		if (parsed[i] != NULL)
			printf("parsed[%i] = %s\n", i, parsed[i]);
		else
			break;
	}

	test_search(parsed);

	free_parsed_path(parsed);
}

/**
 * test_str- tests functions concerning strings
 *
 * Return: void return
*/
void test_str()
{
	char dest[20] = "BRUH";
	char src[4] = "JOE";
	int out;
	out = _strncmp("BRUH", "BRUH", 4);
	printf("_strcmp(BRUH, BRUH, 4) = %i\n", out);
	out = _strncmp("BRUHJON", "BRUHJOE", 4);
	printf("_strcmp(BRUHJON, BRUHJOE, 4) = %i\n", out);
	out = _strncmp("BRUHJON", "BRUHJOE", 5);
	printf("_strcmp(BRUHJON, BRUHJOE, 5) = %i\n", out);

	_strcat(dest, src);
	printf("dest = %s\n", dest);
}

/**
 * tests_search- tests functions concerning search
 * @parsed_path: parsed path
 * Return: void return
*/
void test_search(char **parsed_path)
{
	char *path = strdup("usr/bin");
	char *command = strdup("/cat");
	int out;
	
	out = exec_search(path, command);
	// printf("exec_search(path, command) = %i\n", out);

	// printf("search_path(parsed_path, command) = %s\n", search_path(parsed_path, command));
}

/**
 * main- runs the tests
 * @argc: argument count
 * @argv: argument variable
 * @env: environment variables
*/
int main(int argc, char **argv, char **env)
{
	test_str();
	test_env(env);
	return (0);
}
