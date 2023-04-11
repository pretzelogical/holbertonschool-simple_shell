#include "../main.h"

/**
 * test_env- tests functions in the env part of the program
 * @envp: pointer to environment variables
 *
 * Return: void return
*/
void test_env(char **env)
{
	char *getted;

	getted = get_path(env);
	printf("getpath(env) = %s\n", getted);
}

/**
 * test_str- tests functions concerning strings
 *
 * Return: void return
*/
void test_str()
{
	int out;
	out = _strncmp("BRUH", "BRUH", 4);
	printf("_strcmp(BRUH, BRUH, 4) = %i\n", out);
	out = _strncmp("BRUHFAM", "BRUHJOE", 4);
	printf("_strcmp(BRUHFAM, BRUHJOE, 4) = %i\n", out);
	out = _strncmp("BRUHFAM", "BRUHJOE", 5);
	printf("_strcmp(BRUHFAM, BRUHJOE, 5) = %i\n", out);
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
