#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **str_to_array(char *str, char delim);
char *getfile(const char *path);

int main(int c, char **v) {
    if (c != 2) {
        return 1;
    }
    char *buffer = getfile(v[1]);
    char **code = str_to_array(buffer, '\n');
    free(buffer);

    long ptr = 0;

    

    for (int i = 0; code[i] != NULL; ++i)
        free(code[i]);
    free(code);
}
