// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;  
    bool inWord = false;     

    while (*str) { 
        if (isspace(*str)) { 
            inWord = false; 
        } else { 
            if (!inWord) { 
                inWord = true; 
                const char *temp = str;
                bool hasDigit = false;
                while (*temp && !isspace(*temp)) {
                    if (isdigit(*temp)) {
                        hasDigit = true;
                        break;
                    }
                    temp++;
                }
                if (!hasDigit) count++; 
            }
        }
        str++; 
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;

    while (*str) {
        if (isspace(*str)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            if (isupper(*str)) {
                const char *temp = str + 1;
                bool isValid = true;
                while (*temp && !isspace(*temp)) {
                    if (!islower(*temp)) {
                        isValid = false;
                        break;
                    }
                    temp++;
                }
                if (isValid) count++;
            }
        }
        str++;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    unsigned int wordLength = 0;

    while (*str) {
        if (isspace(*str)) {
            if (wordLength > 0) {
                totalLength += wordLength;
                wordCount++;
                wordLength = 0;
            }
        } else {
            wordLength++;
        }
        str++;
    }   

    if (wordLength > 0) {
        totalLength += wordLength;
        wordCount++;
    }

    if (wordCount == 0) return 0;
    return (totalLength + wordCount / 2) / wordCount;
}
