#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include "func.h"

char ToB2(char str[], int b1, int b2, int len) {
    unsigned long long int num10 = 0;

    int fullStr[48];
    unsigned long long acc = 1;
    for (int i = len; i > 0; --i) {
        int ch = ToNumber(str[i - 1]);
        if (ch == -1) {
            return 0;
        }
        num10 += (unsigned long long)(ch * acc);
        acc *= b1;
    }
    int counter = 0;
    while ((unsigned long long)num10 / b2 > 0) {
        fullStr[counter] = num10 % b2;
        counter++;
        num10 = (unsigned long long)num10 / b2;
    }
    fullStr[counter] = num10 % b2;
    counter++;
    for (int i = 0; i < counter; i++) {
        char sim;
        if (fullStr[counter - i - 1] >= 10 && fullStr[counter - i - 1] <= 15) {
            sim = (char)fullStr[counter - i - 1] + 87;
        }
        else {
            sim = (char)fullStr[counter - i - 1] + 48;
        }
        printf("%c", sim);
    }
    return 1;

}

char ToB2D(char str[], int b1, int b2, int len) {
    double num10D = 0.0;
    double acc = b1;
    for (int i = 0; i < len; ++i) {
        int ch = ToNumber(str[i]);
        if (ch == -1) {
            return 0;
        }
        num10D += (double)(ch / acc);
        acc *= b1;
    }
    int countR = 0;
    while (countR < 12 && (int)num10D != num10D) {
        num10D *= b2;
        int ch = (int)num10D;
        if (ch != 0) {
            num10D -= ch;
        }
        char sim;
        if (ch >= 10 && ch <= 15) {
            sim = (char)ch + 87;
        }
        else {
            sim = (char)ch + 48;
        }
        printf("%c", sim);
        countR++;

    }
    return 1;
}

int ToNumber(char str) {
    int ch1 = tolower(str);
    if (ch1 >= 'a' && ch1 <= 'f') {
        return (ch1 - 'a' + 10);
    }
    else if (ch1 >= '0' && ch1 <= '9') {
        return (ch1 - '0');
    }
    else {
        printf("bad input");
        return -1;
    }

}

