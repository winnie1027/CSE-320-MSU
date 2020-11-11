#include "/user/cse320/Projects/project05.support.h"
#include <stdio.h>

int main()
{
    char array[]= "   +abCD";
    int num = 0;	
    int base = 16;
    int T = convert(&array[0], base, &num);
    if(T == 1){
        printf("Expected return: 1\n");
        printf("Convert function returned: %d\n", T);
        printf("Value: %s\n", array);
        printf("Base %d\n", base);
        printf("Decimal: %d\n", num);
        printf("Hexadecimal: %08x\n\n", num);
    }

    char array0[]= "   -abCD";
    int num0 = 0;			
    int base0 = 16;
    int T0 = convert(&array0[0], base0, &num0);
    if(T0 == 1){
        printf("Expected return: 1\n");
        printf("Convert function returned: %d\n", T0);
        printf("Value: %s\n", array0);
        printf("Base %d\n", base0);
        printf("Decimal: %d\n", num0);
        printf("Hexadecimal: %08x\n\n", num0);
    }

    char array1[]= "100";
    int num1 = 0;
    int base1 = 2;
    int T1 = convert(&array1[0], base1, &num1);
    if(T1 == 1){
        printf("Expected return: 1\n");
        printf("Convert function returned: %d\n", T1);
        printf("Value: %s\n", array1);
        printf("Base %d\n", base1);
        printf("Decimal: %d\n", num1);
        printf("Hexadecimal: %08x\n\n", num1);
    } 

    char array2[]= "zzzZZZZ";
    int num2 = 0;
    int base2 = 36;
    int T2 = convert(&array2[0], base2, &num2);
    if(T2 == 1){
        printf("Expected return: 1\n");
        printf("Convert function returned: %d\n", T2);
        printf("Value: %s\n", array2);
        printf("Base %d\n", base2);
        printf("Decimal: %d\n", num2);
        printf("Hexadecimal: %08x\n\n", num2);
    }

    char array3[]= "abcdefg";
    int num3 = 0;
    int base3 = 16;
    int T3 = convert(&array3[0], base3, &num3);
    if(T3 == 1){
        printf("Expected return: 1\n");
        printf("Convert function returned: %d\n", T3);
        printf("Value: %s\n", array3);
        printf("Base %d\n", base3);
        printf("Decimal: %d\n", num3);
        printf("Hexadecimal: %08x\n\n", num3);
    }

    char array4[]= "\n   \t    abcdefg";
    int num4 = 0;
    int base4 = 16;
    int T4 = convert(&array4[0], base4, &num4);
    if(T4 == 1){
        printf("Expected return: 1\n");
        printf("Convert function returned: %d\n", T4);
        printf("Value: %s\n", array4);
        printf("Base %d\n", base4);
        printf("Decimal: %d\n", num4);
        printf("Hexadecimal: %08x\n\n", num4);
    }

    char array5[]= "abcd812-&567    ";
    int num5 = 0;
    int base5 = 36;
    int T5 = convert(&array5[0], base5, &num5);
    if(T5 == 1){
        printf("Expected return: 1\n");
        printf("Convert function returned: %d\n", T5);
        printf("Value: %s\n", array5);
        printf("Base %d\n", base5);
        printf("Decimal: %d\n", num5);
        printf("Hexadecimal: %08x\n\n", num5);
    }

    char array6[]= "Winnie";
    int num6 = 0;
    int base6 = 36;
    int T6 = convert(&array6[0], base6, &num6);
    if(T6 == 1){
        printf("Expected return: 1\n");
        printf("Convert function returned: %d\n", T6);
        printf("Value: %s\n", array6);
        printf("Base %d\n", base6);
        printf("Decimal: %d\n", num6);
        printf("Hexadecimal: %08x\n\n", num6);
    }
}

