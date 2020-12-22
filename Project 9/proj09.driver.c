#include <stdio.h>
#include "/user/cse320/Projects/project09.support.h"

int main()
{
    int num = 7;
    int expected = -7;
    int result = negate(num);
    printf("Negate function testing 7:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num = -7;
    expected = 7;
    result = negate(num);
    printf("Negate function testing -7:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num = 0;
    expected = 0;
    result = negate(num);
    printf("Negate function testing 0:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num = -5;
    expected = 5;
    result = absolute(num);
    printf("Absolute function testing -5:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num = 5;
    expected = 5;
    result = absolute(num);
    printf("Absolute function testing 5:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num = 0;
    expected = 0;
    result = absolute(num);
    printf("Absolute function testing 0:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    int num1 = 5;
    int num2 = 7;
    expected = num1 + num2;
    result = add(num1, num2);
    printf("Add function testing 5 + 7:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = -5;
    num2 = -7;
    expected = num1 + num2;
    result = add(num1, num2);
    printf("Add function testing -5 + -7:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = 5;
    num2 = -7;
    expected = num1 + num2;
    result = add(num1, num2);
    printf("Add function testing 5 + -7:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = 0x7fffffff;
    num2 = 0x260;
    result = add(num1, num2);
    printf("Add function testing overflow:\n");
    printf("Expected number: 80000000\n");
    printf("Result: %8x\n\n", result);

    num1 = 6;
    num2 = 1;
    expected = num1 - num2;
    result = sub(num1, num2);
    printf("Subtract function testing 6 - 1:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = 6;
    num2 = -1;
    expected = num1 - num2;
    result = sub(num1, num2);
    printf("Subtract function testing 6 - -1:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = -6;
    num2 = 1;
    expected = num1 - num2;
    result = sub(num1, num2);
    printf("Subtract function testing -6 - 1:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = -6;
    num2 = -1;
    expected = num1 - num2;
    result = sub(num1, num2);
    printf("Subtract function testing -6 - -1:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = 0x7fffffff;
    num2 = 0xffffffff;
    result = sub(num1, num2);
    printf("Subtract function testing overflow:\n");
    printf("Expected number: 80000000\n");
    printf("Result: %8x\n\n", result);

    num1 = 3;
    num2 = 9;
    expected = num1 * num2;
    result = mul(num1, num2);
    printf("Multiply function testing 3 * 9:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = 3;
    num2 = -9;
    expected = num1 * num2;
    result = mul(num1, num2);
    printf("Multiply function testing 3 * -9:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = -3;
    num2 = -9;
    expected = num1 * num2;
    result = mul(num1, num2);
    printf("Multiply function testing -3 * -9:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = 0x7fffffff;
    num2 = 0x260;
    result = mul(num1, num2);
    printf("Multiply function testing overflow:\n");
    printf("Expected number: 80000000\n");
    printf("Result: %8x\n\n", result);

    num1 = 27;
    num2 = 3;
    expected = num1 / num2;
    result = divide(num1, num2);
    printf("Divide function testing 27 / 3:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = 27;
    num2 = -3;
    expected = num1 / num2;
    result = divide(num1, num2);
    printf("Divide function testing 27 / -3:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = 27;
    num2 = 0;
    result = divide(num1, num2);
    printf("Divide function testing 27 / 0:\n");
    printf("Expected number: 80000000\n");
    printf("Result: %8x\n\n", result);

    num1 = 2;
    num2 = 3;
    expected = num1 * num1 * num1;
    result = power(num1, num2);
    printf("Power function testing 2^3:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num1 = 2;
    num2 = 0;
    result = power(num1, num2);
    printf("Power function testing 2^0:\n");
    printf("Expected number: 1\n");
    printf("Result: %d\n\n", result);

    num1 = 2;
    num2 = -2;
    result = power(num1, num2);
    printf("Power function testing 2^-2:\n");
    printf("Expected number: 80000000\n");
    printf("Result: %8x\n\n", result);

    num1 = 0x7fffffff;
    num2 = 0x260;
    result = power(num1, num2);
    printf("Power function testing overflow:\n");
    printf("Expected number: 80000000\n");
    printf("Result: %8x\n\n", result);

    num = 6;
    expected = 6 * 5 * 4 * 3 * 2 * 1;
    result = factorial(num);
    printf("Factorial function testing 6:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num = -4;
    result = factorial(num);
    printf("Factorial function testing -4:\n");
    printf("Expected number: 80000000\n");
    printf("Result: %8x\n\n", result);

    num = 0;
    expected = 1;
    result = factorial(num);
    printf("Factorial function testing 0:\n");
    printf("Expected number: %d\n", expected);
    printf("Result: %d\n\n", result);

    num = 0x7fffffff;
    result = factorial(num);
    printf("Factorial function testing overflow:\n");
    printf("Expected number: 80000000\n");
    printf("Result: %8x\n\n", result);
}