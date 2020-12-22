/*
    Winnie Yang
    Project 10
                */

        .global length
        .global copy
        .global append
        .global duplicate
        .global compare

        .data
        .text

length:
        push        {r5,lr}         @ save r5 and lr on stack
        mov         r5, #0          @ saved variable r5 == 0

find_length:
        ldrb        r2, [r0]        @ loads a byte from source into temp r2
        cmp         r2, #0          @ compare to check if every byte of source has been added
        beq         return_length   @ return function if equal

        addne       r5, r5, #1      @ increment source byte if not equal
        addne       r0, r0, #1      @ increment r0 to the next byte if not equal

        bne         find_length     @ if r2 is not yet 0, loop again

return_length:
        mov         r0, r5          @ moves r5 into return register r0
        pop         {r5,lr}         @ pop r5 and lr off stack
        bx          lr              @ return function

copy:
        push        {lr}            @ save lr on stack

loop_copy:
        ldrb        r2, [r1]        @ loads byte from source into temp r2
        cmp         r2, #0          @ check if all bytes have been copied from dest
        beq         return_copy     @ return function if equal

        strb        r2, [r0]        @ else, stores byte from r2 in dest

        addne       r0, r0, #1      @ increment dest to loop next byte
        addne       r1, r1, #1      @ increment source to loop next byte

        bne         loop_copy       @ if loop is not done, loop again

return_copy:
        pop         {lr}            @ pop lr off stack
        bx          lr              @ return function

append:
        push        {r5,r6,lr}      @ save r5 r6 and lr on stack
        mov         r5, r0          @ moves dest to r5

        bl          length          @ find length of dest

        add         r0, r5, r0      @ append, r0 = r5 + r0

        bl          copy            @ calling copy passing in new r0 and r1 values

        pop         {r5,r6,lr}      @ pop r5, r6, and lr off stack
        bx          lr              @ return function

duplicate:
        push        {r5,r6,lr}      @ save r5 r6 and lr on stack
        mov         r5, r0          @ moves source to r5

        bl          length          @ branch to length to find length of source

        add         r0, r0, #1      @ increment size of return register

        bl          malloc          @ allocate additional memory

        mov         r6, r0          @ moves malloc to r6
        mov         r1, r5          @ moves source from r5 to r1

        bl          copy            @ copy r1 into dest

        mov         r0, r6          @ moves malloc back to return register

        pop         {r5,r6,lr}      @ pop r5, r6, and lr off stack
        bx          lr              @ return function

compare:
        push        {r5,r6,r7,lr}

loop_compare:
        ldrb        r5, [r0]        @ load byte from source1 into r5
        ldrb        r6, [r1]        @ load byte from source2 into r6

        sub         r7, r5, r6      @ r7 = r5 - r6
        cmp         r7, #0          @ compare subtraction result to 0
        bne         return_compare  @ if r7 != 0, return function

        cmp         r5, #0          @ compare byte from source2 to 0
        beq         return_compare  @ if r5 == 0, return function

        cmp         r6, #0          @ compare byte from source2 to 0
        beq         return_compare  @ if r6 == 0, return function

        add         r0, r0, #1      @ increment source1 to next byte for next loop
        add         r1, r1, #1      @ increment source2 to next byte for next loop
        b           loop_compare    @ else, loop again        

return_compare:
        mov         r0, r7          @ move r7 value to return register
        pop         {r5,r6,r7,lr}   @ pop r5, r6, r7, and lr off stack
        bx          lr              @ return function
