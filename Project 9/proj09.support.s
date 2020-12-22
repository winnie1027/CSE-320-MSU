/* 
    Winnie Yang
    CSE 320 Project 9
                        */

        .global negate
        .global absolute
        .global add
        .global sub
        .global mul
        .global divide
        .global power
        .global factorial

        .text
        .data

        @ functions that read one register
negate:
        push        {r4,r5,lr}              @ stores r4 onto the stack
        mov         r4, r0                  @ copies data from r0 to r4
        mov         r5, #0                  @ sets r5 as 0 for subtraction

        subs        r0, r5, r4              @ subtract r4 by 0 to negate

        bl          done                    @ branch to exit

absolute:
        push        {r4,r5,lr}              @ stores r4 onto the stack
        mov         r4, r0                  @ copies data from r0 to r4
        mov         r5, #0                  @ set r5 as 0 for subtraction

        cmp         r4, #0                  @ comparing r0 to 0
        bge         endAbsolute             @ if r0 >= 0, branch to exit

        sub         r4, r5, r4              @ subtract r4 by 0 for positive int

endAbsolute:
        mov         r0, r4                  @ copies r4 into r0 and return
        bl          done                    @ branch to exit

        @ functions that read 2 registers
add:
        push        {r4,r5,lr}              @ stores r4, r5, and r6 onto the stack
        mov         r4, r0                  @ copies data from r0 to r4
        mov         r5, r1                  @ copies data from r1 to r5

        adds        r0, r4, r5              @ r0 = r4 + r5
        bvs         overflow                @ branch if overflow set

        bl          done                    @ branch to exit

sub:
        push        {r4,r5,lr}              @ stores r4 and r5 onto the stack
        mov         r4, r0                  @ copies data from r0 to r4
        mov         r5, r1                  @ copies data from r1 to r5

        subs        r0, r4, r5              @ r0 = r4 - r5
        bvs         overflow                @ branch if overflow set

        bl          done                    @ branch to exit

mul:
        push        {r4,r5,lr}              @ stores r4 and r5 onto the stack
        smull       r4,r5,r0,r1             @ r4 * r5

        mov         r0, r4                  @ copies data from r4 to r0
        asr         r4, #31                 @ shift r4 right by 31 bits

        cmp         r4, r5                  @ compare r4 to r5
        bne         overflow                @ if r4 != r5, branch to check overflow    

        bl          done                    @ branch to exit

divide:
        push        {r4,r5,lr}              @ stores r4 and r5 onto the stack
        mov         r4, r0                  @ copies data from r0 to r4
        mov         r5, r1                  @ copies data from r1 to r5

        cmp         r5, #0                  @ compare r5 to 0
        beq         overflow                @ branch to overflow if r5 == 0
        
        sdiv        r0, r4, r5              @ r0 = r4 / r5

        bl          done                    @ branch if overflow

power:
        push        {r4,r5,lr}              @ stores r4 and r5 onto the stack
        mov         r4, r0                  @ copies data from r0 to r4
        mov         r5, r1                  @ copies data from r1 to r5

        cmp         r5, #0                  @ compare exponent r5 to 0
        blt         overflow                @ if r5 < 0, branch to overflow
        beq         endPower                @ if r5 == 0, branch to exit
        mov         r0, r4                  @ copies base value r4 to r0

loopPower:
        cmp         r5, #1                  @ compare r5 to 1
        beq         done                    @ if r5 == 1, branch to exit

        mov         r1, r4                  @ copies data from r4 to r1
        bl          mul                     @ branch to multiply

        add         r5, r5, #-1             @ r5 = r5 - 1
        b           loopPower               @ function calls itself to loop again

endPower:
        mov         r0, #1                  @ return 1
        b           done                    @ exit     

factorial:
        push        {r4,lr}                 @ stores r4 onto the stack
        mov         r4, r0                  @ copies data from r0 to r4
        
        cmp         r4, #0                  @ comparing r4 to 0
        blt         ovfFactorial            @ if r4 < 0, branch to return overflow
        beq         endFactorial            @ if r4 == 0, branch to end
        mov         r0, r4                  @ copies data from r4 to r0

loopFactorial:
        cmp         r4, #1                  @ comparing r4 to 1
        beq         end                     @ if r4 == 1, branch to end

        add         r4, r4, #-1             @ r4 = r4 - 1
        mov         r1, r4                  @ copies data from r4 to r1
        bl          mul                     @ branch to multiply
        b           loopFactorial           @ function calls itself to loop again      

ovfFactorial:
        mov         r0, #0x80000000         @ copies overflow to r0
        b           end                     @ branch to exit

endFactorial:
        mov         r0, #1                  @ return 1
        b           end                     @ branch to exit

end:
        pop         {r4,lr}                 @ popping r4
        bx          lr

overflow:
        mov         r0, #0x80000000         @ not valid
        b           done                    @ exit to pop all values

done:
        pop         {r4,r5,lr}              @ popping r4 and r5 to reset
        bx          lr