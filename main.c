#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "func.h"


int main(void) {
    int b1, b2;
    int dot = 0;
    int lenBefore = 0;
    int lenAfter = 0;
    int counterEnter = 0;
    char strBeforeDot[13];
    char strAfterDot[13];
    int t = 0;


    if (scanf("%d%d", &b1, &b2) == 0) {
        return 0;
    };


    while (counterEnter != 2) {
        char c;
        if (scanf("%c", &c) == 0) {
            return 0;
        }
        if (c == '(' || c == ')') {
            printf("bad input");
            return 0;
        }
        if (c == '\n') {
            counterEnter++;
        }
        else {

            if (c == '.') {
                dot += 1;
            }
            else {
                int cInt = ToNumber(c);
                if (cInt >= b1) {
                    printf("bad input");
                    return 0;
                }
                if (dot == 0) {
                    strBeforeDot[lenBefore] = c;
                    lenBefore++;
                }
                else {
                    if (c != '0') {
                        t = 1;
                    }
                    strAfterDot[lenAfter] = c;
                    lenAfter++;
                }
            }

            if (lenAfter + lenBefore >= 13 && c != '\n') {
                printf("bad input");
                return 0;
            }
        }
    }
    if (b1 > 16 || b1 < 2 || b2>16 || b2 < 2) {
        printf("bad input");
        return 0;
    }
    if (dot == 1 && (lenAfter == 0 || lenBefore == 0)) {
        printf("bad input");
        return 0;

    }
    if (dot > 1) {
        printf("bad input");
        return 0;
    }
    int item1 = ToB2(strBeforeDot, b1, b2, lenBefore);
    if (item1 == 0) {
        return 0;
    }
    if (t == 1) {
        printf(".");
        ToB2D(strAfterDot, b1, b2, lenAfter);
    }
    return 0;
}
