#include "hashtable.h"
#include "dict.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

int read_from_file(FILE * input_file, Dict *d);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        exit(1);
    }
    FILE *input = fopen(argv[1], "r");
    if (input == 0) {
        perror("Fopen Failed ");
        exit(-1);
    }
    Dict d = Dict();
    read_from_file(input, &d);
    fclose(input);
    d.print();
    return 0;
}

int read_from_file(FILE * input_file, Dict *d) {
    // 从文件指针中读取单词  判断单词中是否有非字母字符  并将所有字母转换为小写
    char word[1000];
    while (fscanf(input_file, "%s", word) != EOF) {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            if (!isalpha(word[i])) {
                // 非字母字符  不存储单词
                word[0] = '\0';
                break;
            }
            if (word[i] >= 'A' && word[i] <= 'Z') {
                word[i] = tolower(word[i]);
            }
        }
        if (strlen(word) > 0) {
            d->insert(word);
        }
    }
    return 0;
}
