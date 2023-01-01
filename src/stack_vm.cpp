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


numtype VM::to_binary_format (const uint16_t val) {
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

// void load_file(std::string file){
//     std::ifstream read(file, std::ios::binary);
//     std::istreambuf_iterator<char> i(read),e;
//     std::vector<unsigned char> inf (i,e);
// }

void VM::halt(VM* vm){    //0
    std::cerr << "Program exit\n";
    std::exit(EXIT_FAILURE);
}

void VM::set(VM* vm){     //1
    numtype a,b;
    //memory>>a>>b;
}

void VM::push(VM* vm){    //2
    numtype val;
    //stack.push_back(convert_value(val));
    //break;
}

void VM::pop(VM* vm){     //3
    
}

void VM::eq(VM* vm){      //4

}

void VM::gr(VM* vm){      //5

}

void VM::jmp(VM* vm){     //6
    // vm->mem_idx++;
    // a = memory[memory_ptr+1];
    //         opsize = 0;
    //         memory_ptr = convert_value(a);

    uint16_t i= mem_idx +1;
    vm->c = vm->get_mem(i);
    std::cout<<c<<std::endl;
    vm->mem_idx = to_binary_format(c);

    
}

void VM::jt(VM* vm){     //7

}

void VM::jf(VM* vm){    //8

}

void VM::add(VM* vm){   //9
    
}

void VM::mult(VM* vm){     //10
    //numtype a,b,c;
    //memory>>a*b;
    
}
void VM::mod(VM* vm){     //11
    
}
void VM::and_(VM* vm){     //12
    
}
void VM::or_(VM* vm){     //13
    
}
void VM::not_(VM* vm){     //14
    
}
void VM::rmem(VM* vm){     //15
    
}
void VM::wmem(VM* vm){     //16
    
}
void VM::call(VM* vm){     //17
    
}
void VM::ret(VM* vm){     //18
    
}

void VM::out(VM* vm){     //19
    char char_ascii [2];
    vm->mem_idx++;
    vm->c = vm->get_mem(mem_idx);
    std::cout<<(c);

}
void VM::in_(VM* vm){     //20
    
}
void VM::noop(VM* vm){     //21
}