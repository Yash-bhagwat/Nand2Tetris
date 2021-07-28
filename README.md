# Hack Computer and Assembler (Part of Nand to Tetris)
Created the Project using the following [book](https://www.amazon.in/Elements-Computing-Systems-Building-Principles/dp/0262640686) and [website](https://www.nand2tetris.org/).

## Brief Description of the Projects
### [1)Boolean Logic](/(P1)%20Boolean%20Logic)
Implemented basic gates using Boolean Logic starting from the very basic NAND gate. We use a NAND gate because it is one of the universal gates that can be combined in various ways to create all the different gates we require. In this project I create all the other basics gates (eg. AND, OR) and also their 16 bit versions using an HDL(Hardware Description Language).
Also implemented Multiplexers (routes one of the several input signals to a single output using selection logic) ans Demultiplexers (routes a single input signals to one to the several possible output signals)

### [2)Boolean Algebra](/(P2)%20Boolean%20Arithmetic/)
Implemented an Half Adder which is capable of adding two bits together to produce a sum and a carry.
Combined Half Adders to create a Full Adder capable of adding three bits which can be used to add the output carry for the last bit, to create a multi-bit adder
Also added ALU (Arithmetic Logic Unit) capable of performing several different operations like A+B, !A, A+1 and so on which will be one of the foundation logic components of our Hack computer

### [3)Sequential Logic](/(P3)%20Sequential%20Logic)
Here we use the D Flip Flop as your building block to create sequential logic components for our system. Sequential Logic is important because we need data components which should be able to hold data stored earlier and also be able to change the data stored in the components. Further develop 16 bit Registers and RAM components which will be later used in our Hack computer 

### [4)Machine Learning](/(P4)%20Machine%20Language)
Here we work with low-level programming in machine language. We focus here on the three main abstractions, a processor, a memory and a set of registers. We use two registers D and A where D can store only data values whereas A can store both data values and addresses. The value stored in the address referred to by Register A is represented by the implicit memory location M.
We have two different types of 16 bit instructions, and A-instruction(set the A-register to a 15-bit value) and a C-instruction(instruction code of the format dest=comp;jump).
Inputs and Outpus interact with the computer platform through memory maps, Here we use keyboard as the input and a screen as the output which can be accessed and read and written to(keyboard cannot be written to).

