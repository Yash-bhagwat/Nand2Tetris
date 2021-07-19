// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm
// Important point : pixel addresses go from 16x384 to 24575
// Plan of Action:
// just check if keyboard is pressed or not if pressed 
// goto blacked else go to whiten then go back to loop
(LOOP)
    @SCREEN
    D=A
    @pos
    M=D
    @KBD //set to keyboard bit 
    D=M
    @black //if black, we go to black loop
    D;JNE
	@white //if white, we go to white loop
	D;JMP
    //pixel addresses go from 16x384 to 24575
(white)
	@pos
	A=M
	M=0 //set to white
	@pos
	M=M+1
	@pos
	D=M //which pixel I am at
	@24575 //when we reach the end
	D=D-A
	@LOOP
	D;JGT
	@white
	D;JLE
(black)
	@pos
	A=M
	M=-1 //set to black
	@pos
	M=M+1
	@pos
	D=M //which pixel I am at
	@24575 //when we reach the end
	D=D-A
	@LOOP
	D;JGT
	//else blacken the next cell
	@black
	D;JLE
//No need of looping at the end, when we reach the end, 
//We will automatically go back