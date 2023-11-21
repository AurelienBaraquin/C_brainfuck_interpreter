#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char *getfile(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "Error: could not open file %s\n", path);
        return NULL;
    }

    struct stat st;
    stat(path, &st);
    if (st.st_size == 0) {
        fprintf(stderr, "Error: file %s is empty\n", path);
        return NULL;
    }

    char *code = malloc(st.st_size + 1);
    if (!code) {
        fprintf(stderr, "Error: could not allocate memory\n");
        return NULL;
    }

    if (fread(code, 1, st.st_size, f) != st.st_size) {
        fprintf(stderr, "Error: could not read file %s\n", path);
        return NULL;
    }

    code[st.st_size] = 0;
    fclose(f);

    return code;
}
