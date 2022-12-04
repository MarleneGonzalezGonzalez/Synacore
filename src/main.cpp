#include "../include/stack_vm.hpp"
#include <string>

int main(){
    
    VM vm;
    
    std::ifstream line("../bin/challenge.bin", std::ios::binary);
    char bytes [2];

    void static (*func_array[23])(VM& vm, ifstream& st);
    // void (VM::*functptr[23])(ifstream&) = {VM::halt, VM::set, VM::push, VM::pop};
    void (*functptr[23])(VM&, ifstream&) = {VM::halt, VM::set, VM::push, VM::pop, VM::eq, VM::gr, VM::jmp, VM::jt, VM::jf, VM::add, VM::mult, VM::mod,
            VM::and_, VM::or_, VM::not_, VM::rmem, VM::wmem, VM::call, VM::ret, VM::out, VM::in_, VM::noop} ;
    
    int i =0; 
    int mem_idx=0;
    std::string temp;
    //while ((mem_idx<10) && (line.read(bytes,2))){
    while (line.read(bytes,2)){
    //    try{
//  NO DATA IN BYTES
        uint16_t output = bytes[0];
        // std::cout << mem_idx<<std::endl;

        // std::cout<<"output:"<<(output)<<std::endl;
        // std::cout<<"first bytes: "<<output<<std::endl;
        // output <<=8;
        // std::cout << std::to_chars(line) << "";
        // printf("line: %c \n" char(lines));
        // printf("bytes0 %c \n", bytes[0]);
        // std::cout<<"byte0:"<<bytes[0]<<std::endl;
        // std::cout<<"byte1:"<<bytes[1]<<std::endl;

        // line.read(bytes,2);
        // std::cout<<"byte0:"<<bytes[0]<<std::endl;
        // std::cout<<"byte1:"<<bytes[1]<<std::endl;
        // uint32_t bina = vm.to_binary_format(output);
        //std::cout<<"second: "<<output<<std::endl;
        // output |= bytes[0];


        //add all of this to main
        if (output<=21){
            // (this->*m_funcPointers[m_currentButton])();
            // (*p[op]) (i, j);
            (functptr[output])(vm,line);
            
            // char c =vm.get_mem((output));
            // char c =);
            // std::cout<<vm.get_mem(output);
            std::cout<<char(vm.get_mem(output));
            // (vm.func_array[output])(line);
        }
        //has to do with registers not sure exactly how
        else{
            //segmentation dault because calling function index that does not exist
            std::cout<<"output over 21:"<<(output)<<std::endl;
            continue;
            //try{
            //    vm.set_reg(output);
            //}catch(std::exception& e){
            //    std::cerr << "Exception caught : " << e.what() << std::endl;
        //}
        }
        
    //    }
    //    catch(int mem_idx){
    //        std::cout<<mem_idx<<std::endl;
        //   }
        mem_idx++;
    }
    return 0;
}