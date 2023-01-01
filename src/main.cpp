#include "../include/stack_vm.hpp"
#include <string>
typedef void (*functptr_arr[23])(VM*);

int main(){
    
    VM vm;

    vm.load_file("../bin/challenge.bin");

    // void static (*func_array[23])(VM& vm);
    // // void (VM::*functptr[23])(ifstream&) = {VM::halt, VM::set, VM::push, VM::pop};
    // void (*functptr[23])(VM&) = {VM::halt, VM::set, VM::push, VM::pop, VM::eq, VM::gr, VM::jmp, VM::jt, VM::jf, VM::add, VM::mult, VM::mod,
    //         VM::and_, VM::or_, VM::not_, VM::rmem, VM::wmem, VM::call, VM::ret, VM::out, VM::in_, VM::noop} ;
    
    int i =0; 
    int mem_idx=0;
    std::string temp;
    // std::string temp;\index.html
    //while ((mem_idx<10) && (line.read(bytes,2))){
    // functptr_arr functptr[23] = {**VM::halt}; //, VM::set, &VM::push, &VM::pop, &VM::eq, &VM::gr, &VM::jmp, &VM::jt, &VM::jf, &VM::add, &VM::mult, &VM::mod,
            // &VM::and_, &VM::or_, &VM::not_, &VM::rmem, &VM::wmem, &VM::call, &VM::ret, &VM::out, &VM::in_, &VM::noop} ;


    vm.run();
    
    return 0;
}