#include <stdio.h>
#include <string.h>

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I <- VX = -1  * 
X <- LC = -10 *
C <- DM = -100

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
MCMXCIV
*/

int romanToInt(char* s) {
    int rs = 0; 
    int size = strlen(s); 

    for (int i = 0; i < size; ++i) {
        char cc = s[i]; 
        char nc = '\0'; 
        if (i + 1 <= size) {
            nc = s[i + 1];
        }
        if (cc == 'I') {
            if (nc == 'V') {
                rs += 4;
                ++i;
            } else if (nc == 'X') {
                rs += 9;
                ++i; 
            } else {
                rs += 1;    
            }
        } 
        if (cc == 'V') {
            rs += 5;      
        } 
        if (cc == 'X') {
            if (nc == 'L') {
                rs += 40; 
                ++i; 
            } else if (nc == 'C') {
                rs += 90; 
                ++i; 
            } else {
                rs += 10; 
            }
        } 
        if (cc == 'L') {
            rs += 50; 
        } 
        if (cc == 'C') {
            if (nc == 'D') {
                rs += 400; 
                ++i; 
            } else if (nc == 'M') {
                rs += 900;
                ++i; 
            } else {
                rs += 100; 
            }
        } 
        if (cc == 'D') {
            rs += 500; 
        } 
        if (cc == 'M') {
            rs += 1000; 
        } 
    }
    return rs; 
}