#include <iostream>
#include <vector>
#include <stdint.h>
#include <string>
#include <fstream>
#include <cstdint>
#include <cinttypes>
#include <unordered_map>
#include <functional>
#include <array>
#include <any>
using namespace std;


#define MEMORY_SIZE 32768
#define REGISTERS 8

typedef unsigned short uint16;
typedef signed short numtype;

class VM{
    private:
        std::vector<numtype> stack;
        numtype reg[32776];
        numtype memory[32777];
        numtype memory_it;
        
        numtype read_value(numtype val);
        void write_value(int pos, numtype val);
        void load_file(std::string file);
        void run_program(uint16 ptr);

        //std::vector<std::function<void(void)>> prepareInstructions();
        //std::vector<char> input;
//        using instruction_t = std::function<void()>;

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

    public:
        //void (*funct[22])(void); 
        using func_t = std::function<void()>;
        func_t func_array[23]; 
        VM()
        {
            func_array[0] = [this](){ halt(); };
            func_array[1] = [this](){ set(); };
            func_array[2] = [this](){ push(); };
            func_array[3] = [this](){ pop(); };
            func_array[4] = [this](){ eq(); };
            func_array[5] = [this](){ gr(); };
            func_array[6] = [this](){ jmp(); };
            func_array[7] = [this](){ jt(); };
            func_array[8] = [this](){ jf(); };
            func_array[9] = [this](){ add(); };
            func_array[10] = [this](){ mult(); };
            func_array[11] = [this](){ mod(); };
            func_array[12] = [this](){ and_(); };
            func_array[13] = [this](){ or_(); };
            func_array[14] = [this](){ not_(); };
            func_array[15] = [this](){ rmem(); };
            func_array[16] = [this](){ wmem(); };
            func_array[17] = [this](){ call(); };
            func_array[18] = [this](){ ret(); };
            func_array[19] = [this](){ out(); };
            func_array[20] = [this](){ in_(); };
            func_array[21] = [this](){ noop(); };

        }

    uint16 running=1; //

    //void fetch();
    //void decode();
    //void execute();
    public:
        //VM constructor

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
