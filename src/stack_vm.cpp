#include "stack_vm.hpp"
#include <iostream>
#include <fstream>

typedef signed short numtype;
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

numtype VM::get_mem(uint16_t& mem_it){
        return memory[mem_it];
    }

void VM::set_mem(int mem_it, char mem){
        if (mem_it < 32776){
            //add memory int and see how to set memory to value specific
            memory[mem_it] = mem;
        }
    }

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
        return VM::reg[val];
    }
    std::exit(EXIT_FAILURE);
}

void VM::write_value(int pos, numtype val) {
    if(32767 < pos && pos < 32776) {
        pos -= 32768;
        VM::reg[pos] = val;
    } else {
        std::exit(EXIT_FAILURE);
    }
}

void load_file(std::string file){
    std::ifstream read(file, std::ios::binary);
    std::istreambuf_iterator<char> i(read),e;
    std::vector<unsigned char> inf (i,e);
}

void VM::halt(VM& vm, ifstream& line){    //0
    std::cerr << "Program exit\n";
    std::exit(EXIT_FAILURE);
}

void VM::set(VM& vm, ifstream& line){     //1
    numtype a,b;
    //memory>>a>>b;
}

void VM::push(VM& vm, ifstream& line){    //2
    numtype val;
    //stack.push_back(convert_value(val));
    //break;
}

void VM::pop(VM& vm, ifstream& line){     //3
    
}

void VM::eq(VM& vm, ifstream& line){      //4

}

void VM::gr(VM& vm, ifstream& line){      //5

}

void VM::jmp(VM& vm, ifstream& line){     //6
    
}

void VM::jt(VM& vm, ifstream& line){     //7

}

void VM::jf(VM& vm, ifstream& line){    //8

}

void VM::add(VM& vm, ifstream& line){   //9
    
}

void VM::mult(VM& vm, ifstream& line){     //10
    //numtype a,b,c;
    //memory>>a*b;
    
}
void VM::mod(VM& vm, ifstream& line){     //11
    
}
void VM::and_(VM& vm, ifstream& line){     //12
    
}
void VM::or_(VM& vm, ifstream& line){     //13
    
}
void VM::not_(VM& vm, ifstream& line){     //14
    
}
void VM::rmem(VM& vm, ifstream& line){     //15
    
}
void VM::wmem(VM& vm, ifstream& line){     //16
    
}
void VM::call(VM& vm, ifstream& line){     //17
    
}
void VM::ret(VM& vm, ifstream& line){     //18
    
}
void VM::out(VM& vm, ifstream& line){     //19
    char char_ascii [2];
    line.read(char_ascii,2);
    vm.set_mem(19,char(char_ascii[0]));
    // vm.memory[19] = char_ascii[0]
    
    // numtype output = this-> memory[memory_it];
    // std::cout<<char_ascii[0]<<std::endl;
}
void VM::in_(VM& vm, ifstream& line){     //20
    
}
void VM::noop(VM& vm, ifstream& line){     //21
    void(0);
}