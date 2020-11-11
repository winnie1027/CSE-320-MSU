#include "/user/cse320/Projects/project05.support.h"
#include <stdio.h>

int convert(const char ch[], int base, int *convert = 0)
{
    int value = 0;
    int negative = 0;
    int positive = 1;
    
    if (base < 2 || base > 36) // Valid bases range from 2 to 36 inclusive
    {
        return 0;
    }

    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] >= '0' && ch[i] <= '9') // checking for numbers
        {
            int val = ch[i] - '0';
            if (val >= base)
            {
                if (value == 0)
                {
                    return 0;
                }
                break;
            }
            *convert = val + base * (*convert);
            value = 1;
        }
        else if (ch[i] == '+') // checking for positive
        {
            if (value == 1)
            {
                return 1;
            }
            positive = 1;
            negative = 0;
        }
        else if (ch[i] == '-') // checking for negative
        {
            if (value == 1)
            {
                return 1;
            }
            positive = 0;
            negative = 1;
        }
        else if (ch[i] == '\n' || ch[i] == '\t' || ch[i] == ' ') // checking for whitespace
        {
            if (value != 0)
            {
                break;
            }
        }
        else if (ch[i] >= 'a' && ch[i] <= 'z') // checking for lowercase letters
        {
            int val = ch[i] - 'a' + 10;
            if (val >= base)
            {
                if (value == 0)
                {
                    return 0;
                }
                break;
            }
            *convert = val + base * (*convert);
            value = 1;
        }
        else if (ch[i] >= 'A' && ch[i] <= 'Z') // checking for uppercase letters
        {
            int val = ch[i] - 'A' + 10;
            if (val >= base)
            {
                if (value == 0)
                {
                    return 0;
                }
                break;
            }
            *convert = val + base * (*convert);
            value = 1;
        }
        else // checking for other symbols that aren't mentioned above
        {
            if (value == 0)
                {
                    return 0;
                }
            return 1;
        }
    }


    if (negative == 1)
    {
        *convert = -(*convert);
    }
    return 1; // true
}