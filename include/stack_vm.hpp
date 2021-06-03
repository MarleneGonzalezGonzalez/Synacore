#include <iostream>
#include <vector>
#include <stdint.h>
#include <string>
#include <vector>
#include <fstream>
#include <cstdint>
#include <cinttypes>

#define MEMORY_SIZE 32768
#define REGISTERS 8

typedef unsigned short uint16;
typedef signed short numtype;
struct bytes_to_uint16{
    char low_byte;
    char high_byte;
    uint16 uint16_;
};

class VM{
    public:
        void run();
        //VM constructor
        VM(std::string filename){
            std::ifstream line(filename, std::ios::binary);
            for (size_t ir=0; ir<reg.size(); ir++);
            for (size_t im=0; im<memory.size();im++); 
            char bytes [2];
            bytes_to_uint16 btu;
            int mem_idx=0;
            while ((mem_idx==0) && (line.read(bytes,2))){
                //std::cout<<("aAaaa")<<std::endl;
            //    try{
                btu.low_byte = bytes[0];
                btu.high_byte = bytes[1];
                memory[mem_idx] = btu.uint16_;
            //    }
            //    catch(int mem_idx){
            //        std::cout<<mem_idx<<std::endl;
             //   }
                mem_idx++;
            }

        }

    private:
        std::vector<numtype> stack;
        std::vector<numtype> reg;
        std::vector<numtype> memory;
        numtype memory_it;
        
        numtype read_value(numtype val);
        void write_value(int pos, numtype val);
        void load_file(std::string file);
        void run_program(uint16 ptr);

        //std::vector<std::function<void(void)>> prepareInstructions();
        std::vector<char> input;
        
        void halt();
        void set();
        void push();
        void pop();
        void eq();
        void gr();
        void jmp();
        void jt();
        void jf();
        void add();
        void mult();
        void mod();
        void and_();
        void or_();
        void not_();    
        void rmem();
        void wmem();
        void call();
        void ret();
        void out();
        void in_();
        void noop();

    //int16_t pc =100; //program counter
    //int16_t sp =100; //stack pointer- small register that stores the address of the last program request in a stack

    uint16 running=1; //

    //void fetch();
    //void decode();
    //void execute();


    public:
    numtype to_binary_format (uint32_t value);
    void start_VM();
    //void run();
    void loadProgram(std::vector<uint16> prog);

    numtype get_reg(VM vm, numtype reg_it){
        return vm.reg[reg_it];
    }

    void set_reg(VM vm, const numtype reg_num, const numtype num){
        if ((num > 32767) && (num < 32776)){
            numtype reg_idx = reg_num - 32768 ;
            vm.reg[reg_idx] = num;
        } else {
            std::exit(EXIT_FAILURE);
        }
    }

    numtype get_mem(VM vm, numtype mem_it){
        return vm.memory[mem_it];
    }

    void set_mem(VM vm, numtype mem_it, numtype mem){
        if (mem_it < 32776){
            //add memory int and see how to set memory to value specific
            vm.memory[mem_it] = mem;
        }
    }

};
