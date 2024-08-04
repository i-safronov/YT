#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char* res = (char*)malloc(sizeof(char) * (strlen(strs[0]) + 1));
    int idx = -1; 

    do {
        idx++; 
        res[idx] = strs[0][idx]; 

        for (int j = 0; j < strsSize; j++) {
            if (!strs[j][idx] || res[idx] != strs[j][idx]) {
                res[idx] = '\0'; 
            }
        }

    } while (res[idx]); 

    return res; 
}