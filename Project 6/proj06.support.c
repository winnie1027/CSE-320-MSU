#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>

float get_infinity()     /* Return positive infinity */
{
    union ieee_single theUnionDataObject;
    theUnionDataObject.irep = 0x7f800000;
    return theUnionDataObject.frep;
}

float get_nan()     /* Return not-a-number */
{
    union ieee_single theUnionDataObject;
    theUnionDataObject.irep = 0x7fc00000;
    return theUnionDataObject.frep;
}

float get_max_normal()     /* Return largest normal */
{
    union ieee_single theUnionDataObject;
    theUnionDataObject.irep = 0x7f7fffff;
    return theUnionDataObject.frep;
}

float get_min_normal()     /* Return smallest normal */
{
    union ieee_single theUnionDataObject;
    theUnionDataObject.irep = 0x00800000;
    return theUnionDataObject.frep;
}

float get_max_denormal()   /* Return largest denormal */
{
    union ieee_single theUnionDataObject;
    theUnionDataObject.irep = 0x007fffff;
    return theUnionDataObject.frep;
}

float get_min_denormal()   /* Return smallest denormal */
{
    union ieee_single theUnionDataObject;
    theUnionDataObject.irep = 0x00000001;
    return theUnionDataObject.frep;
}

int is_negative( float input )   /* Test if argument is negative */
{
    union ieee_single num; 
    num.frep = input;
    unsigned int sign = (num.irep >> 31);
    if ( sign == 1 ) // is negative
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_infinity( float input )   /* Test if argument is infinity */
{
    union ieee_single num; 
    num.frep = input;
    if ( num.irep == 0x7f800000 || num.irep == 0xff800000) // positive or negative infinity
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_nan( float input )       /* Test if argument is not-a-number */
{
    union ieee_single num; 
    num.frep = input;
    if ((num.irep >= 0x7f800001 && num.irep <= 0x7fbfffff) || 
        (num.irep >= 0xff800001 && num.irep <= 0xffbfffff) || 
        (num.irep >= 0x7fc00000 && num.irep <= 0x7fffffff) ||
        (num.irep >= 0xffc00000 && num.irep <= 0xffffffff))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int is_zero( float input )       /* Test if argument is zero */
{
    union ieee_single num; 
    num.frep = input;
    if ( num.irep == 0x00000000 || num.irep == 0x80000000 ) // positive or negative zero
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_denormal( float input )   /* Test if argument is denormal */
{
    union ieee_single num; 
    num.frep = input;
    if ( num.irep <= 0x007fffff && num.irep >= 0x00000001 )
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

float negate( float input )      /* Return negation of argument */
{
    union ieee_single num; 
    num.frep = input;
    unsigned int new = num.irep - 0x80000000;
    union ieee_single result;
    result.irep = new;
    return result.frep;
}

float absolute( float input )    /* Return absolute value of argument */
{
    union ieee_single num; 
    num.frep = input;
    unsigned int sign = (num.irep >> 31);
    if ( sign == 1 )
    {
        unsigned int new = num.irep - 0x80000000;
        union ieee_single result;
        result.irep = new;
        return result.frep;
    }
    else 
    {
        return num.frep;
    }
}
