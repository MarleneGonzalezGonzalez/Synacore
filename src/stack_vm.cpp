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

void VM::halt(){    //0
    std::cerr << "Program exit\n";
    std::exit(EXIT_FAILURE);
}

void VM::set(){     //1
    numtype a,b;
    //memory>>a>>b;
}

void VM::push(){    //2
    numtype val;
    //stack.push_back(convert_value(val));
    //break;
}

void VM::pop(){     //3
    
}

void VM::eq(){      //4

}

void VM::gr(){      //5

}

void VM::jmp(){     //6

}

void VM::jt(){     //7

}

void VM::jf(){    //8

}

void VM::add(){   //9
    
}

void VM::mult(){     //10
    //numtype a,b,c;
    //memory>>a*b;
    
}
void VM::mod(){     //11
    
}
void VM::and_(){     //12
    
}
void VM::or_(){     //13
    
}
void VM::not_(){     //14
    
}
void VM::rmem(){     //15
    
}
void VM::wmem(){     //16
    
}
void VM::call(){     //17
    
}
void VM::ret(){     //18
    
}
void VM::out(){     //19
    numtype output = this-> memory[memory_it];
    std::cout<<output<<std::endl;
}
void VM::in_(){     //20
    
}
void VM::noop(){     //21
    void(0);
}