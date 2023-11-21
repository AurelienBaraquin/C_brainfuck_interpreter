#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **str_to_array(char *str, char delim) {
    char **result = NULL;
    int count = 0;
    char *token;
    char *rest = str;

    while ((token = strtok_r(rest, &delim, &rest))) {
        count++;
        result = realloc(result, sizeof(char*) * count);

        if (result == NULL)
            exit(EXIT_FAILURE);

        result[count-1] = token;
    }

    result = realloc(result, sizeof(char*) * (count + 1));
    result[count] = NULL;

    return result;
}
