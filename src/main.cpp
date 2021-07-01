#include "../include/stack_vm.hpp"

int main(){
    
    //VM vm("../bin/challenge.bin");
    VM vm;
    std::ifstream line("../bin/challenge.bin", std::ios::binary);
    char bytes [2];
    
    int mem_idx=0;
    //while ((mem_idx<10) && (line.read(bytes,2))){
    while (line.read(bytes,2)){
    //    try{
        uint16_t output =bytes[1];
        //std::cout<<"first bytes: "<<output<<std::endl;
        output <<=8;
        //std::cout<<"second: "<<output<<std::endl;
        output |= bytes[0];
        std::cout<<"output:"<<(output)<<std::endl;

        //add all of this to main
        if (output<=21){
            vm.func_array[output]();
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