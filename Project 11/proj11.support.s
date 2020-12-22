/*
    Winnie Yang
    CSE 320 Project 11
                        */

        .global search
        .global delete
        .global insert

        .data

A:      .word   0

float:  .single 0r0.0

	.text
	.balign 4

search:
        push	        {r4,r5,r6,r7,lr}

        ldrh            r4, [r0, #2]            @ r4 = number of students 
        ldr             r5, [r0, #8]            @ r5 = pointer to array of students
        mov             r6, #0                  @ counter for loop
      
loop_search:
        ldrh            r7, [r5]                @ r7 is now the pointer to students
        cmp             r1, r7                  @ compare student ID to r7
        beq             search_succeed          @ if they're equal, student is in the table

        add             r6, r6, #1              @ increment the counter for next loop
        cmp             r6, r4                  @ compare counter to the number of students
        bgt             search_fail             @ if counter > student count, student can't be found

        add             r5, r5, #44             @ increment pointer to point to next student in table 
        b               loop_search             @ search again

search_succeed:
        mov	        r0, #1	    	        @ Return 1 for true, student was found
        b               search_end              @ end search

search_fail:
        mov	        r0, #0	    	        @ return 0 for false, student was not found
        b               search_end              @ end search

search_end:
        str	        r5, [r2]	        @ store student pointer in r2
        
        pop             {r4,r5,r6,r7,lr}        @ pop all registers 
        bx              lr

delete:
        push	        {r4,r5,r6,r7,r8,r9,lr}
        
        ldr	        r2, =A                  @ r2 = address in r2
        mov	        r4, r0                  @ r4 = pointer to table of students
        ldrh	        r5, [r0, #2]            @ r5 = student count
        ldr	        r6, [r0, #8]            @ r6 = pointer to array of students

        bl		search                  @ call search to check if student already exists
        cmp		r0, #1                  @ check if student is found from search
        bne		delete_fail             @ if not, then it can't be deleted, exit function
        
        ldr		r1, =A                  @ r1 = address in r1
        ldr		r1, [r1]                @ dereferencing r1 so it can be used later
        add		r1, r1, #44             @ r1 = address + 44 to increment by 44 bytes
        
        mov		r7, #44                 @ r7 = 44 for incrementing bytes later
        mul		r7, r5, r7              @ r7 = student count * 44 which is total bytes for table
        add		r6, r6, r7              @ r6 = pointer to student + total bytes for table 

        ldr		r8, =A                  @ r8 = address in r8
        ldr		r8, [r8]                @ dereferencing r8 so it can be used later
        sub		r9, r6, r8              @ r9 = (pointer to student + total bytes for table) - r8 
        
        mov		r0, r8                  @ moving address to pointer to table of students
        mov		r2, r9                  @ moving r9 to address in r2

        sub		r5, r5, #1              @ r5 = student count - 1 to decrement count after deletion
        strh	        r5, [r4, #2]            @ storing new count in student count after deletion
        bl		memmove                 @ move memory

delete_succeed:
        mov	        r0, #1      	        @ return 1 for true, deletion worked
        b               delete_end              

delete_fail:
        mov	        r0, #0	    	        @ return 0 for false, deletion failed
        b               delete_end 

delete_end:
        pop		{r4,r5,r6,r7,r8,r9,lr}  @ pop all registers 
	bx		lr

insert:
        push            {r4,r5,r6,r7,r8,r9,r10,r11,lr}

        mov             r4, r0                  @ r4 = pointer to table of students
        mov             r5, r1                  @ r5 = student ID number 
        mov             r6, r2                  @ r6 = pointer to student name
        mov             r7, r3                  @ r7 = points on exam #1
        
        ldr		r2, =float
        ldrh            r8, [r0, #0]            @ r8 = capacity from table
        ldrh            r9, [r0, #2]            @ r9 = student count from table
        cmp             r9, r8                  @ compare capacity to student count to check if count goes over capacity
        beq             insert_fail             @ if capacity == student count, nothing more should be inserted

        bl              search                  @ search to check if student already exists
        cmp             r0, #1                  @ if yes, then no need to insert
        beq             insert_fail             @ student already exists, exit

        ldr             r2, =float              @ r2 = address r2 
        ldr             r2, [r2]                @ dereference r2 to use it later 
        mov             r1, r2                  @ r1 = r2 which is an address 
        add             r0, r1, #44             @ r0 = r1 + 44 bytes 

        mov             r8, r6                  @ r8 = pointer to student name from r6 before changing r6 
        mov             r6, #44                 @ r6 = 44 for bytes 
        mul             r10, r9, r6             @ r10 = capacity * 44 bytes for total bytes
        ldr             r11, [r4, #8]           @ r11 = pointer to array of students 
        add             r6, r11, r10            @ r6 = student pointer + total number of bytes
        sub             r6, r6, r2              @ r6 = r6 - r2

        mov             r2, r6                  @ r2 = r6 storing r2 in r6 before changing r6
        mov             r6, r1                  @ r6 = r1 
        add             r9, r9, #1              @ r9 = student count + 1 to update count after insertion
        strh            r9, [r4, #2]            @ inserting student count into student table 

        bl              memmove                 @ call move memory function 

        strh            r5, [r6]                @ inserting student ID number into table
        add             r0, r6, #4              @ r0 = r6 + 4
        mov             r1, r8                  @ moving student name pointer into r1
        bl              strcpy                  @ calling string copy function

        mov             r8, #0                  @ r8 = 0 initializing total score 
        add             r8, r8, r7              @ r8 total score = 0 + exam #1 score
        ldr             r9, [sp, #36]           @ r9 = loading exam #2 score from stack
	add		r8, r8, r9		@ r8 total score = both exam scores + homework score 
        
        strh            r7, [r6, #30]           @ inserting exam #1 score into table 
        strh            r9, [r6, #32]           @ inserting exam #2 score into table 
        
        ldr             r9, [sp, #40]           @ r9 = loading homework score from stack
        strh            r9, [r6, #34]           @ inserting homework r9 into table 

        add             r8, r8, r9              @ r8 total score = exam scores + homework score
        str		r8, [r6, #36]           @ inserting total score r8 into table

        ldrh            r4, [r4, #4]            @ r4 = loading 400 from available score on table 
        fmsr            s0, r8                  @ s0 = total score
        fmsr            s1, r4                  @ s1 = 400
        fsitos          s2, s0                  @ s2 = float of total score
        fsitos          s3, s1                  @ s3 = float 400

        fdivs           s4, s2, s3              @ s4 = float percentage = total score / 400.00
				
        ldr             r10, =A                 @ r10 = address r10 
        fsts            s4, [r10]               @ copying s4 value to r10 
        ldr             r10, [r10]              @ dereferencing r10 to be used 
        str             r10, [r6, #40]          @ inserting float percentage into table
        
insert_succeed:
        mov             r0, #1                  @ return 1 for true
        b               end_insert              @ end insert

insert_fail:
        mov             r0, #0                  @ return 0 for false
        b               end_insert              @ end insert

end_insert:
        pop             {r4,r5,r6,r7,r8,r9,r10,r11,lr} 
        bx              lr