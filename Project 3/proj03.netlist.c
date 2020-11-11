/******************************************************************************
 Project3 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
Function "simnet" -- test bed for student circuits
******************************************************************************/

void simnet()
{
Signal w, x, y, z, Present, a, b, c, d, e, f, g;

// Generating 4 input signals
Signal Strobe (1); // Counter strobe input
Signal ResetA (1); // Counter reset signal (before complemented)
Signal ResetB (1); // Counter reset signal (after complemented)

// Code to generate 4 input signals
Counter ((SD("1c-4c"), "4-bit counter"), (ResetB, Strobe), (w,x,y,z)); 
circuits( SD("1d-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);

// A pulser is used to generate a temporary value of "One" on a specified
// signal line (signal value: Zero ==> One ==> Zero)
Pulser ((SD("1a"), "r -- Reset counter"), ResetA, 'r', 10000);
Pulser ((SD("2a"), "s -- Strobe counter"), Strobe, 's', 10000);

// To complement the reset signal
Not (SD("1b"), ResetA, ResetB);

// This displays 8 output signals
Probe ((SD("1h"), "Present"), Present);
Probe ((SD("2h"), "a()"), a);
Probe ((SD("3i"), "b()"), b);
Probe ((SD("5i"), "c()"), c);
Probe ((SD("6h"), "d()"), d);
Probe ((SD("5g"), "e()"), e);
Probe ((SD("3g"), "f()"), f);
Probe ((SD("4h"), "g()"), g);
}


/******************************************************************************
Function "circuits" -- implementation of student circuits

Do not alter the interface -- function "circuits" must receive four
signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
Signal f, Signal g ) 
{
Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );
Signal notw, notx, noty, notz;
Signal and1, and2, and3, and4, and5, and6, and7, and8, and9, and10, and11,
       and12, and13, and14, and15, 
and16, and17, and18, and19, and20, and21, and22, and23, and24;
// Declarations for any auxiliary Signals
// Circuit implementation (Not, And, Or gates)
// Not gates
Not ( SD(sd,"1f"), w, notw );
Not ( SD(sd,"2f"), x, notx );
Not ( SD(sd,"4f"), y, noty );
Not ( SD(sd,"5f"), z, notz );

// Present()
And ( SD(sd,"1g"), (notw, notx, noty, z), and1);
And ( SD(sd,"1g"), (notw, notx, y, notz), and2);
And ( SD(sd,"1g"), (notw, x, noty, z), and3);
And ( SD(sd,"1g"), (notw, x, y, notz), and4);
And ( SD(sd,"1g"), (w, notx, noty, notz), and5);
And ( SD(sd,"1g"), (w, notx, y, notz), and6);
Or ( SD(sd,"1e"), (and1, and2, and3, and4, and5, and6), Present);

// a() implementation
And ( SD(sd,"2g"), (notw, x), and7);
And ( SD(sd,"2g"), (w, notx), and8);
And ( SD(sd,"2g"), (y, notz), and9);
Or ( SD (sd,"2e"), (and7, and8, and9), a);

// b() implementation
And ( SD(sd,"3g"), (notw, notx), and10);
And ( SD(sd,"3g"), (w, notx), and11);
Or ( SD(sd,"3e"), (and10, and11), b);

// c() implementation
And ( SD(sd,"4g"), (notw, noty, z), and12);
And ( SD(sd,"4g"), (notw, x), and13);
And ( SD(sd,"4g"), (w, notx), and14);
Or ( SD(sd,"4e"), (and12, and13, and14), c);

// d() implementation
And ( SD(sd,"5g"), (notw, y, notz), and15);
And ( SD(sd,"5g"), (notw, x), and16);
And ( SD(sd,"5g"), (w, notx, noty, notz), and17);
Or ( SD(sd,"5e"), (and15, and16, and17), d);

// e() implementation
And ( SD(sd,"6g"), (y, notz), and18);
And ( SD(sd,"6g"), (w, notx), and19);
Or ( SD(sd,"6e"), (and18, and19), e);

// f() implementation
And ( SD(sd,"7g"), (notw, x), and20);
And ( SD(sd,"7g"), (w, notx), and21);
Or ( SD(sd,"7e"), (and20, and21), f);

// g() implementation
And ( SD(sd,"8g"), (y, notz), and22);
And ( SD(sd,"8g"), (notw, x), and23);
And ( SD(sd,"8g"), (w, notx), and24);
Or (SD(sd,"8e"), (and22, and23, and24), g);
}
