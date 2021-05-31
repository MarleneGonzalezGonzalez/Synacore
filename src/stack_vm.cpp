#include "stack_vm.hpp"
#include <iostream>
#include <fstream>
#
/* header : 2 bits
*data: 30 bits
*
*header format:
*0->positive integer
*1->primitive instructison
*2->negative integer
*3->undefined
*/


//functions


//Stack VM
//void VM::start_VM(std::string filename){
//    load_file("filename");
//    reg.insert(std::begin(reg), 8, 0);
//}

numtype VM::to_binary_format (const uint32_t val) {
    if (val <= 32767) {
        return val; 
    } else if (val <= 32775) {
        return reg[(val - 32768)]; 
    } else {
        std::exit(EXIT_FAILURE);
        return 0;
    }
}
 
numtype VM::read_value(const numtype val) {
    if(32767 < val && val < 32776) {
        return reg.at(val);
    }
    std::exit(EXIT_FAILURE);
}

void VM::write_value(int pos, numtype val) {
    if(32767 < pos && pos < 32776) {
        pos -= 32768;
        reg.at(pos) = val;
    } else {
        std::exit(EXIT_FAILURE);
    }
}

void load_file(std::string file){
    std::ifstream read(file, std::ios::binary);
    std::istreambuf_iterator<char> i(read),e;
    std::vector<unsigned char> inf (i,e);
}

void VM::halt(){
    std::cerr << "Program exit\n";
    std::exit(EXIT_FAILURE);
}

void VM::set(){
    numtype a,b;
    //memory>>a>>b;
}

void VM::push(){
    numtype val;
    //stack.push_back(convert_value(val));
    //break;
}

void VM::pop(){

}

void VM::eq(){

}

void VM::gr(){

}

void VM::jmp(){

}

void VM::jt(){

}

void VM::jf(){

}

void VM::add(){
    
}

void VM::mult(){
    //numtype a,b,c;
    //memory>>a*b;
    
}