#include "../main.h"

/**
 * test_str- tests functions concerning strings
 *
 * Return: void return
*/
void test_str(char **env)
{
	char **envCp;
	int i, j;

	for (j = 0; j < 3; j++)
	{
		envCp = strp_array_dup(env);

		for (i = 0; i < ENV_CP_LIMIT && envCp[i] != NULL; i++)
		{
			printf("%s\n", envCp[i]);
		}

		strp_array_free(envCp);
	}
}

/**
 * tests_search- tests functions concerning search
 * @parsed_path: parsed path
 * Return: void return
*/
void test_search(char **env)
{
	char *getted;
	char *Ptest;
	char test[] = "ls";

	getted = get_path(env);
	printf("getpath(env) = %s\n", getted);

	Ptest = search_path(test, env);
	printf("search_path(test, env) = %s\n", Ptest);
	free(Ptest);

}

/**
 * main- runs the tests
 * @argc: argument count
 * @argv: argument variable
 * @env: environment variables
*/
int main(__attribute__ ((unused)) int argc,__attribute__ ((unused))
	char **argv, char **env)
{
	test_str(env);
	/* test_search(env); */
	return (0);
}
