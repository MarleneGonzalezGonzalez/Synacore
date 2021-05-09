#include "stack_vm.hpp"
/* header : 2 bits
*data: 30 bits
*
*header format:
*0->positive integer
*1->primitive instruction
*2->negative integer
*3->undefined
*/


//functions
Stack_VM::Stack_VM(){
    memory.reserve(1000000);
}
i16 Stack_VM::getType(i16 instruction){
    i16 type =0xc0000000;
    type=(type & instruction) >>30;
    return type;
}
i16 Stack_VM::getData(i16 instruction){

}
