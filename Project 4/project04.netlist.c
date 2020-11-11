
/******************************************************************************
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
    Signal Init, Clock, w, x, y, z;

    // Pulsers are vertically on the left side of the simulation
    Pulser ( (SD("1a"), "i -- Init"), Init, 'i', 10000);
    Pulser ( (SD("2a"), "c -- Clock"), Clock, 'c', 10000);

    circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

    // Probes are vertically on the right side of the simulation
    Probe ( (SD("1h"), "w"), w);
    Probe ( (SD("2h"), "x"), x);
    Probe ( (SD("3h"), "y"), y);
    Probe ( (SD("4h"), "z"), z);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
    Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );
    
    Signal notw, notx, noty, notz;
    Signal W, X, Y, Z;
    Signal and1, and2, and3, and4, and5, and6;

    // DFFs
    Dff ((SD(sd, "1b"), "Dff0"), (Init, W, Clock, Zero), w);
    Dff ((SD(sd, "2b"), "Dff1"), (Zero, X, Clock, Init), x);
    Dff ((SD(sd, "3b"), "Dff2"), (Init, Y, Clock, Zero), y);
    Dff ((SD(sd, "4b"), "Dff3"), (Zero, Z, Clock, Init), z);

    // Not gates
    Not ( SD(sd, "1c"), w, notw);
    Not ( SD(sd, "2c"), x, notx);
    Not ( SD(sd, "3c"), y, noty);
    Not ( SD(sd, "4c"), z, notz);

    // W gates
    And ( SD(sd, "1d"), (notw, notx, y, notz), and1);
    And ( SD(sd, "1d"), (notw, x, y, notz), and2);
    Or ( SD(sd, "1d"), (and1, and2), W);

    // X gates
    And ( SD(sd, "2d"), (notw, x, noty, z), and3);
    And ( SD(sd, "2d"), (w, notx, y, notz), and4);
    Or ( SD(sd, "2d"), (and3, and4), X);

    // Y gates
    And ( SD(sd, "3d"), (notw, notx), and5);
    And ( SD(sd, "3d"), (noty, z), and6);
    Or ( SD(sd, "3d"), (and5, and6), Y);

    // Z gate
    Or ( SD(sd, "4d"), (w, notx), Z);
}
