#include <stdio.h>
#include "/user/cse320/Projects/project10.support.h"

int main()
{
    char test1[] = "abcdefghijklmnopqrstuvwxyz"; 
    int expected = 26;
    printf("Testing length function of alphabets:\n");
    printf("Expected length: %d\n", expected);
    printf("Result from function: %d\n\n", length(test1));

    char test2[] = "";
    expected = 0; 
    printf("Testing length function of empty string:\n");
    printf("Expected length: %d\n", expected);
    printf("Result from function: %d\n\n", length(test2));

    char test3[27]; // size of 27
    copy(test3, test1);
    printf("Testing copy function:\n");
    printf("Result from function: %s\n\n", test3);

    char first[20] = "Game ";
    char second[20] = "of Thrones";
    append(first, second);
    printf("Testing append function:\n");
    printf("Expected string: Game of Thrones\n");
    printf("Result from function: %s\n\n", first);

    char test4[] = "Hello World!";
    printf("Testing duplicate function:\n");
    printf("Expected string: Hello World!\n");
    printf("Result from function: %s\n\n", duplicate(test4));

    char test5[] = "";
    printf("Testing duplicate function with empty string:\n");
    printf("Result from function: %s\n\n", duplicate(test5));

    printf("Testing compare function by comparing 2 same strings:\n");
    printf("Expected result: 0\n");
    printf("Result from function: %d\n\n", compare(test4, test4));

    printf("Testing compare function by comparing 2 different strings:\n");
    printf("Expected result: negative integer\n");
    printf("Result from function: %d\n\n", compare(first, second));

    printf("Testing compare function by comparing 2 different strings:\n");
    printf("Expected result: positive integer\n");
    printf("Result from function: %d\n\n", compare(second, first));
}