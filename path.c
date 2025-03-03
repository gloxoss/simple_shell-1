#include "shell.h"

/**
 * path - Function that finds the full path of a command
 * @cmd: Pointer to the command
 * @full_path: Pointer to store the full path of the command
 * Return: 1 on success, 0 if command not found
 */
int path(char *cmd, char **full_path)
{
	char *path = _getenv("PATH");
	char *token;
	size_t path_len = _strlen(path);
	size_t cmd_len = _strlen(cmd);
	size_t full_path_len;
	size_t token_len;
	char *path_copy = malloc((path_len + 1) * sizeof(char));

	if (path_copy == NULL)
	{
		perror("Failed to allocate memory");
		return (0);
	}

	_strcpy(path_copy, path);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		token_len = _strlen(token);
		full_path_len = token_len + cmd_len + 2;

		*full_path = malloc(full_path_len * sizeof(char));
		if (*full_path == NULL)
		{
			perror("Failed to allocate memory");
			free(path_copy);
			return (0);
		}

		_strcpy(*full_path, token);
		(*full_path)[token_len] = '/';
		_strcpy(*full_path + token_len + 1, cmd);

		if (access(*full_path, X_OK) == 0)
			break;

		free(*full_path);
		*full_path = NULL;
		token = strtok(NULL, ":");
	}

	free(path_copy);

	if (*full_path == NULL)
		return (0);

	return (1);
}
