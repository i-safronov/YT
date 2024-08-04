#include <stdio.h>
#include <string.h>

/*
[hello] & [ll]
[he{l}lo] & {{l}l}

*/

int strStr(char* haystack, char* needle) {
    int index = -1, curr = 0;
    for(int i=0; haystack[i]; i++){
        if(needle[curr] == haystack[i]){
            if(index == -1) index = i; 
            curr++; 
            if(!needle[curr]) return index; 
        }
        else {
            if(index != -1) i = index; 
            index = -1; 
            curr = 0; 
        }
    }
    return -1;
}