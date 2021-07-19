// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

//Using the same method as we do in 1+...+100
//but instead we do like R0+R0+....(R1 times) 

@i // i refers to some mem. location.
M=1 // i=1
@R2 // sum refers to some mem. location. 
//this is where I will add up the sum
M=0 // sum=0
//sum is basically the value stored in R2
(LOOP)
    @i
    D=M // D=i
    @R1
    D=D-M // D=i-100
    @END
    D;JGT // If (i-100)>0 goto END
    @R0
    D=M // D=i
    @R2
    M=D+M // sum=sum+R2
    @i
    M=M+1 // i=i+1
@LOOP
0;JMP // Goto LOOP
(END)
@END
0;JMP // End of loop