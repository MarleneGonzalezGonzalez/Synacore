#ifdef STACK_VM_H
#define STACK_VM_H

#include <iostream>
#include <vector>

typedef int16_t i16;

class Stack_VM{
    i16 pc =100; //program counter- 
    i16 sp =100; //stack pointer- small register that stores the address of the last program request in a stack
    std::vector<i16> memory;
    i16 typ=0; //register 1
    i16 dat=0; //register 2
    i16 reg3=0; //register 3
    i16 reg4=0; //register 4s
    i16 reg5=0; //register 5
    i16 reg6=0; //register 6
    i16 reg7=0; //register 7
    i16 reg8=0; //register 8
    i16 running=1; //

    i16 getType(i16 instruction);
    i16 getData(i16 instruction);
    void fetch();
    void decode();
    void execute();

    public:
    Stack_VM();
    void run();
    void loadProgram(std::vector<i16> prog);
};
#endif