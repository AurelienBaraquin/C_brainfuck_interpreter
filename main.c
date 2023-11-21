#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

#define MEM_SIZE 30000

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

void loop(char memory[], char *ptr, char *code, unsigned int *i) {
    while (code[*i]) {
        switch (code[*i]) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                ++*ptr;
                break;
            case '-':
                --*ptr;
                break;
            case '.':
                write(1, ptr, 1);
                break;
            case ',':
                *ptr = getchar();
                break;
            case ']':
                if (*ptr) {
                    unsigned int j = *i;
                    while (code[j] != '[') {
                        --j;
                    }
                    *i = j;
                }
                break;
            case '[':
                if (!*ptr) {
                    unsigned int j = *i;
                    while (code[j] != ']') {
                        ++j;
                    }
                    *i = j;
                }
                break;
        }
        ++*i;
    }
}

int main(int c, char **v) {
    if (c != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", v[0]);
        return 1;
    }

    char memmory[MEM_SIZE] = {0};
    char *ptr = &memmory[MEM_SIZE / 2];

    char *code = getfile(v[1]);
    unsigned int i = 0;

    loop(memmory, ptr, code, &i);

    free(code);
}
