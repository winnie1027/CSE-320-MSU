#include "/user/cse320/Projects/project06.support.h"
#include <stdio.h>

int main()
{
    union ieee_single num1; 
    num1.frep = -1.5;
    printf("Test case 1: Testing negative number case with a negative float number.\n");
    printf( "Real: %f Hex integer: %08x \n", num1.frep, num1.irep );
    printf("Expected: 1\n");
    printf("Actual: %d\n\n", is_negative(num1.frep));

    union ieee_single num2; 
    num2.frep = 1.5;
    printf("Test case 2: Testing negative number case with a positive float number.\n");
    printf( "Real: %f Hex integer: %08x \n", num2.frep, num2.irep );
    printf("Expected: 0\n");
    printf("Actual: %d\n\n", is_negative(num2.frep));

    union ieee_single num3;
    num3.irep = 0x7f800000;
    printf("Test case 3: Testing infinity case with positive infinity.\n");
    printf( "Real: %f Hex integer: %08x \n", num3.frep, num3.irep );
    printf("Expected: 1\n");
    printf("Actual: %d\n\n", is_infinity(num3.frep));

    union ieee_single num4;
    num4.irep = 0xff800000;
    printf("Test case 4: Testing infinity case with negative infinity.\n");
    printf( "Real: %f Hex integer: %08x \n", num4.frep, num4.irep );
    printf("Expected: 1\n");
    printf("Actual: %d\n\n", is_infinity(num4.frep));

    union ieee_single num5;
    num5.frep = 9.9;
    printf("Test case 5: Testing infinity case with a none-infinity number.\n");
    printf( "Real: %f Hex integer: %08x \n", num5.frep, num5.irep );
    printf("Expected: 0\n");
    printf("Actual: %d\n\n", is_infinity(num5.frep));

    union ieee_single num6;
    num6.frep = 0.0;
    printf("Test case 6: Testing zero case with positive 0.\n");
    printf( "Real: %f Hex integer: %08x \n", num6.frep, num6.irep );
    printf("Expected: 1\n");
    printf("Actual: %d\n\n", is_zero(num6.frep));

    union ieee_single num7;
    num7.frep = -0.0;
    printf("Test case 7: Testing zero case with negative 0.\n");
    printf( "Real: %f Hex integer: %08x \n", num7.frep, num7.irep );
    printf("Expected: 1\n");
    printf("Actual: %d\n\n", is_zero(num7.frep));

    union ieee_single num8;
    num8.frep = 1.0;
    printf("Test case 8: Testing zero case with a none-zero number.\n");
    printf( "Real: %f Hex integer: %08x \n", num8.frep, num8.irep );
    printf("Expected: 0\n");
    printf("Actual: %d\n\n", is_zero(num8.frep));

    union ieee_single num9;
    num9.irep = 0x7fc00000;
    printf("Test case 9: Testing NaN case with NAN.\n");
    printf( "Real: %f Hex integer: %08x \n", num9.frep, num9.irep );
    printf("Expected: 1\n");
    printf("Actual: %d\n\n", is_nan(num9.frep));

    union ieee_single num10;
    num10.frep = 1.5;
    printf("Test case 10: Testing NaN case with a number.\n");
    printf( "Real: %f Hex integer: %08x \n", num10.frep, num10.irep );
    printf("Expected: 0\n");
    printf("Actual: %d\n\n", is_nan(num10.frep));

    union ieee_single num11;
    num11.frep = 1.5e-40;
    printf("Test case 11: Testing denormal case with a denormal float number.\n");
    printf( "Real: %f Hex integer: %08x \n", num11.frep, num11.irep );
    printf("Expected: 1\n");
    printf("Actual: %d\n\n", is_denormal(num11.frep));

    union ieee_single num12;
    num12.frep = 1.5;
    printf("Test case 12: Testing denormal case with a normal float number.\n");
    printf( "Real: %f Hex integer: %08x \n", num12.frep, num12.irep );
    printf("Expected: 0\n");
    printf("Actual: %d\n\n", is_denormal(num12.frep));

    union ieee_single num13;
    num13.frep = 1.5;
    printf("Test case 13: Negating a float number.\n");
    printf( "Real: %f Hex integer: %08x \n", num13.frep, num13.irep );
    printf("Expected: -1.500000\n");
    printf("Actual: %f\n\n", negate(num13.frep));

    union ieee_single num14;
    num14.frep = -1.5;
    printf("Test case 14: Finding the absolute value of a float number.\n");
    printf( "Real: %f Hex integer: %08x \n", num14.frep, num14.irep );
    printf("Expected: 1.500000\n");
    printf("Actual: %f\n\n", absolute(num14.frep));

    union ieee_single num15;
    num15.frep = get_infinity();
    printf("Test case 15: Getting positive infinity value from get_infinity.\n");
    printf( "Real: %f Hex integer: %08x \n", num15.frep, num15.irep );
    printf("Expected: inf\n");
    printf("Actual: %f\n\n", get_infinity());

    union ieee_single num16;
    num16.frep = get_nan();
    printf("Test case 16: Getting NaN value from get_nan.\n");
    printf( "Real: %f Hex integer: %08x \n", num16.frep, num16.irep );
    printf("Expected: nan\n");
    printf("Actual: %f\n\n", get_nan());

    union ieee_single num17;
    num17.frep = get_max_normal();
    printf("Test case 17: Getting the maximum normal number from get_max_normal.\n");
    printf( "Real: %f Hex integer: %08x \n", num17.frep, num17.irep );
    printf("Expected: 340282346638528859811704183484516925440.000000\n");
    printf("Actual: %f\n\n", get_max_normal());

    union ieee_single num18;
    num18.frep = get_min_normal();
    printf("Test case 18: Getting the minimum normal number from get_min_normal.\n");
    printf( "Real: %f Hex integer: %08x \n", num18.frep, num18.irep );
    printf("Expected: 0.000000\n");
    printf("Actual: %f\n\n", get_min_normal());

    union ieee_single num19;
    num19.frep = get_max_denormal();
    printf("Test case 19: Getting the maximum denormal number from get_max_denormal.\n");
    printf( "Real: %f Hex integer: %08x \n", num19.frep, num19.irep );
    printf("Expected: 0.000000\n");
    printf("Actual: %f\n\n", get_max_denormal());

    union ieee_single num20;
    num20.frep = get_min_denormal();
    printf("Test case 20: Getting the minimum denormal number from get_min_denormal.\n");
    printf( "Real: %f Hex integer: %08x \n", num20.frep, num20.irep );
    printf("Expected: 0.000000\n");
    printf("Actual: %f\n\n", get_min_denormal());
}