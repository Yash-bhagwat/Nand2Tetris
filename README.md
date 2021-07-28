# Hack Computer and Assembler (Part of Nand to Tetris)
Created the Project using the following [book](https://www.amazon.in/Elements-Computing-Systems-Building-Principles/dp/0262640686) and [website](https://www.nand2tetris.org/).

## Brief Description of the Projects
### [1)Boolean Logic](/(P1)%20Boolean%20Logic)
Implemented basic gates using Boolean Logic starting from the very basic NAND gate. We use a NAND gate because it is one of the universal gates that can be combined in various ways to create all the different gates we require. In this project we create many other basics gates (eg. AND, OR) and also their 16 bit versions using an HDL(Hardware Description Language).
Also implemented Multiplexers (routes one of the several input signals to a single output using selection logic) ans Demultiplexers (routes a single input signals to one to the several possible output signals)
![](images/mux.png)
![](images/demux.png)

### [2)Boolean Algebra](/(P2)%20Boolean%20Arithmetic/)
Implemented a Half Adder which is capable of adding two bits together to produce a sum and a carry.
Combined Half Adders to create a Full Adder capable of adding three bits which can be used to add the output carry for the last bit, to create a multi-bit adder
Also implemented an ALU (Arithmetic Logic Unit) capable of performing several different operations like A+B, !A, A+1 and so on which will be one of the foundational logic components of our Hack computer

### [3)Sequential Logic](/(P3)%20Sequential%20Logic)
Here we use the D Flip Flop as our building block to create sequential logic components for our system. Sequential Logic is important because we need data components which should be able to hold data stored earlier through subsequent time instants and we should be able to change the data stored in the components. Further developed 16 bit Registers and RAM components which will be used later in our Hack computer 

### [4)Machine Learning](/(P4)%20Machine%20Language)
Here we work with low-level programming in machine language. We focus here on the three main abstractions, a processor, a memory and a set of registers. We use two registers D and A where D can store only data values whereas A can store both data values and addresses. The value stored in the address referred to by Register A is represented by the implicit memory location M.
We have two different types of 16 bit instructions, an A-instruction(set the A-register to a 15-bit value) and a C-instruction(instruction code of the format dest=comp;jump).
Inputs and Outpus interact with the computer platform through memory maps, Here we use the keyboard as the input and a screen as the output which can be accessed and read and written to(keyboard cannot be written to). Using the same logic, any amount or type of input or output devices can be connected to our computer.

### [5)Computer Architecture](/(P5)%20Computer%20Architecture)
In this project we finally create our Hack computer by implementing the Computer, CPU and Memory chips. Here, the most challenging part is creating the CPU chip, the working of the CPU chip can be represented by the following arrow logic. We take in the inputs(instruction, inM and the reset bit) and output(outM, writeM, addressM and the program counter). More detailed explanation is provided in the CPU chip file. Also integrated the memory chip which contains the RAM model and the program instruction burned onto the ROM as well as some high-speed registers. Finally integration all these chips to create the all-encompassing Computer chip.
![](images/cpu.png)
![](images/computer.png)

### [6)Assembler](/(P6)%20Assembler)
Assembler converts the assembly program to symbolic binary notation. Implemented the Assembler in C++. The working of the assembler is quite similar to a text translator. We need to clean up the data, that is removing comments, removing whitespace and we also have to deal with symbols. To work with the symbols we use the symbol table data structure which is essentially a hash map(map in C++). So we pass through the code once and note all of the lables and add them to the Symbol Table. Then we pass again through the code and simultaneously convert the code into binary.

Remaining sections are not available as of now, but I will add them later. If you find any issues with the code, a pull request would be highly appreciated.

### Contributor
Yash Bhagwat (Blitztage)
