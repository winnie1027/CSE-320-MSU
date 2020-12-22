/*  
    Winnie Yang
    CSE 320 Project 8
                        */

        .global main

        .data
        .text               

@ Function body
main:   push    {lr}                @ declared to link lr 

        mov     r4, #0              @ initializing total number of characters
        mov     r5, #0              @ initializing number of newline characters
        mov     r6, #0              @ initializing number of whitespace characters (blanks, tabs and newlines)
        mov     r7, #0              @ initilaizing number of letters (in the set {A-Z, a-z})
        mov     r8, #0              @ initializing number of decimal digits (in the set {0-9})
        mov     r9, #0              @ initializing number of hexadecimal digits (in the set {0-9, A-F, a-f})
        mov     r10, #0             @ initializing number of arithmetic operators (in the set {+, -, *, /})

@ counts the total number of characters through a loop
loop:   bl      getchar             @ read one character, returned in r0
        add     r4, r4, #1          @ increment r4 for total character count

@ counts the number of newline characters
if1:    cmp     r0, #0x0A           @ compare return value r0 to a newline character
        bne     if2                 @ if not equal, go to next if statement

then1:  add     r5, r5, #1          @ increment r5 for newline character count
        add     r6, r6, #1          @ increment r6 for white space character count

@ counts the number of whitespace characters (blanks, tabs and newlines)
if2:    cmp     r0, #0x20           @ compare return value space ASCII hex value
        bne     if3                 @ if not equal, go to next if statement

then2:  add     r6, r6, #1          @ increment r6 for white space character count

@ counts the number of letters (in the set {A-Z, a-z})
if3:    cmp     r0, #0x61           @ compare return value r0 to 'a' ASCII hex value
        blt     if4                 @ go to next if statement r0 is less than  'a'

then3:  cmp     r0, #0x7A           @ compare return value r0 to 'z' ASCII hex value
        bgt     if4                 @ go to next if statement if r0 is greater than 'z'

else3:  add     r7, r7, #1          @ increment r7 for number of letters in the set {a-z}

if4:    cmp     r0, #0x41           @ compare return value r0 to 'A' ASCII hex value
        blt     if5                 @ go to next if statement if r0 is less than 'A'

then4:  cmp     r0, #0x5A           @ compare return value r0 to 'Z' ASCII hex value
        bgt     if5                 @ go to next if statement if r0 is greater than 'Z'

else4:  add     r7, r7, #1          @ increment r7 for number of letters in the set {A-Z}


@ counts the number of decimal digits (in the set {0-9})
if5:    cmp     r0, #0x30           @ compare return value r0 to hex ASCII value of 0
        blt     if6                 @ go to next if statement if r0 is less than 0

then5:  cmp     r0, #0x39           @ compare return value r0 to hex ASCII value of 9
        bgt     if6                 @ go to next if statement if r0 is greater than 9

else5:  add     r8, r8, #1          @ increment r8 for number of decimal digits in the set {0-9}
        add     r9, r9, #1          @ increment r9 for the number of hexadecimal digits (in the set {0-9, A-F, a-f})

@ counts the number of hexadecimal digits (in the set {0-9, A-F, a-f})
if6:    cmp     r0, #0x61           @ compare return value r0 to hex ASCII value of 'a'
        blt     if7                 @ go to next if statement if r0 is less than 'a'

then6:  cmp     r0, #0x66           @ compare return value r0 to hex ASCII value of 'f'
        bgt     if7                 @ go to next if statement if r0 is greater than 'f'

else6:  add     r9, r9, #1          @ increment r9 for the number of hexadecimal digits (in the set {0-9, A-F, a-f})

if7:    cmp     r0, #0x41           @ compare return value r0 to hex ASCII value of 'A'
        blt     if8                 @ go to next if statement r0 is less than 'A'

then7:  cmp     r0, #0x46           @ compare return value r0 to hex ASCII value of 'F'
        bgt     if8                 @ go to next if statement if r0 is greater than 'F'

else7:  add     r9, r9, #1          @ increment r9 for the number of hexadecimal digits (in the set {0-9, A-F, a-f})

@ counts the number of arithmetic operators (in the set {+, -, *, /})
if8:    cmp     r0, #0x2B           @ compare return value r0 to hex ASCII value of '+'
        bne     if9                 @ if not equal, go to next if statement

else8:  add     r10, r10, #1        @ increment r10 for the number of arithmetic operators (in the set {+, -, *, /})

if9:    cmp     r0, #0x2D           @ compare return value r0 to hex ASCII value of '-'
        bne     if10                @ if not equal, go to next if statement

else9:  add     r10, r10, #1        @ increment r10 for the number of arithmetic operators (in the set {+, -, *, /})

if10:   cmp     r0, #0x2A           @ compare return value r0 to hex ASCII value of '*'
        bne     if11                @ if not equal, go to next if statement

else10: add     r10, r10, #1        @ increment r10 for the number of arithmetic operators (in the set {+, -, *, /})

if11:   cmp     r0, #0x2F           @ compare return value r0 to hex ASCII value of '/'
        bne     endloop             @ if not equal, end loop since this is the last if statement

else11: add     r10, r10, #1        @ increment r10 for the number of arithmetic operators (in the set {+, -, *, /})

endloop:cmp     r0, #-1             @ Compare return value to EOF
        beq     end                 @ If EOF found, exit loop

        b       loop                @ jump to top of loop

end:    ldr     r0, =fmt1           @ loads data from total into register r0
        mov     r1, r4              @ copies r4 into r1
        bl      printf              @ display r4 value

        ldr     r0, =fmt2           @ loads data from newl for newline into register r0
        mov     r1, r5              @ copies r5 into r1
        bl      printf              @ display r5 value

        ldr     r0, =fmt3           @ loads data from white for whitespace into register r0
        mov     r1, r6              @ copies r6 into r1
        bl      printf              @ display r6 value

        ldr     r0, =fmt4           @ loads data from letter into register r0
        mov     r1, r7              @ copies r7 into r1
        bl      printf              @ display r7 value

        ldr     r0, =fmt5           @ loads data from dec for decimal digits into register r0
        mov     r1, r8              @ copies r8 into r1
        bl      printf              @ display r8 value

        ldr     r0, =fmt6           @ loads data from hex for hexadecimal digits into register r0
        mov     r1, r9              @ copies r9 into r1
        bl      printf              @ display r9 value

        ldr     r0, =fmt7           @ loads data from arith for arithmetic operators into register r0
        mov     r1, r10             @ copies r10 into r1
        bl      printf              @ displays r10 value

        pop     {lr}        
        bx      lr          

fmt1:   .asciz      "\nTotal number of characters is %d.\n"
fmt2:   .asciz      "\nNumber of newline characters is %d.\n"
fmt3:   .asciz      "\nNumber of whitespace characters (blanks, tabs and newlines) is %d.\n"
fmt4:   .asciz      "\nNumber of letters (in the set {A-Z, a-z}) is %d.\n"
fmt5:   .asciz      "\nNumber of decimal digits (in the set {0-9}) is %d.\n"
fmt6:   .asciz      "\nNumber of hexadecimal digits (in the set {0-9, A-F, a-f}) is %d.\n"
fmt7:   .asciz      "\nNumber of arithmetic operators (in the set {+, -, *, /}) is %d.\n"




