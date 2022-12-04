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

        public:
        // void (halt_)(ifstream& line);
        void static (halt)(VM& vm, ifstream& line);
        // void (VM::*halt)(ifstream& line) = &VM::halt_;
        // unique_ptr<>;        
        void static (set)(VM& vm, ifstream& line);
        void static (push)(VM& vm, ifstream& line);
        void static (pop)(VM& vm, ifstream& line);
        void static (eq)(VM& vm, ifstream& line);
        void static (gr)(VM& vm, ifstream& line);
        void static (jmp)(VM& vm, ifstream& line);
        void static (jt)(VM& vm, ifstream& line);
        void static (jf)(VM& vm, ifstream& line);
        void static (add)(VM& vm, ifstream& line);
        void static (mult)(VM& vm, ifstream& line);
        void static (mod)(VM& vm, ifstream& line);
        void static (and_)(VM& vm, ifstream& line);
        void static (or_)(VM& vm, ifstream& line);
        void static (not_)(VM& vm, ifstream& line);    
        void static (rmem)(VM& vm, ifstream& line);
        void static (wmem)(VM& vm, ifstream& line);
        void static (call)(VM& vm, ifstream& line);
        void static (ret)(VM& vm, ifstream& line);
        void static (out)(VM& vm, ifstream& line);
        void static (in_)(VM& vm, ifstream& line);
        void static (noop)(VM& vm, ifstream& line);

    public:
        //void (*funct[22])(void); 
        // (* arr [3])(int)
        
        // typedef void(*func_t)(ifstream&);
        // void (VM::*func_array[23])(ifstream& st);
        // typedef std::function<void(ifstream)> as func_t;
        // using func_t = std::function<void(ifstream)>;
        // std::array< func_t, 23> func_array; 
        // typedef void(*func_t)(ifstream&);
        void static (VM::*func_array[23])(VM& vm, ifstream& st);

        // VM()
        // {
            
        //     // void (VM::*functptr[23])(ifstream&) = {halt, set, push, pop};
            
        //     // void (VM::*functptr[23])(ifstream&) = {halt, set, push, pop, eq, gr, jmp, jt, jf, add, mult, mod,
        //     // and_, or_, not_, rmem, wmem, call, ret, out, in_, noop} ;
        //     // func_array[0] = VM::halt;
        //     // func_array[1] = VM::set;
        //     // func_array[2] = VM::push;
        //     // func_array[3] = VM::pop;
        //     // func_array[4] = VM::eq;
        //     // func_array[5] = VM::gr;
        //     // func_array[6] = VM::jmp;
        //     // func_array[7] = VM::jt; 
        //     // func_array[8] = VM::jf; 
        //     // func_array[9] = VM::add;
        //     // func_array[10] = VM::mult;
        //     // func_array[11] = VM::mod; 
        //     // func_array[12] = VM::and_;
        //     // func_array[13] = VM::or_; 
        //     // func_array[14] = VM::not_;
        //     // func_array[15] = VM::rmem;
        //     // func_array[16] = VM::wmem;
        //     // func_array[17] = VM::call;
        //     // func_array[18] = VM::ret; 
        //     // func_array[19] = VM::out; 
        //     // func_array[20] = VM::in_; 
        //     // func_array[21] = VM::noop;
            
            
            
        //     // func_array2[0] = [this](ifstream st){ halt; };
        //     // func_array2[1] = [this](ifstream st){&set; };
        //     // func_array2[2] = [this](ifstream st){ push; };
        //     // func_array[3] = [this](ifstream){ pop; };
        //     // func_array[4] = [this](ifstream){ eq; };
        //     // func_array[5] = [this](ifstream){ gr; };
        //     // func_array[6] = [this](ifstream){ jmp; };
        //     // func_array[7] = [this](ifstream){ jt; };
        //     // func_array[8] = [this](ifstream){ jf; };
        //     // func_array[9] = [this](ifstream){ add; };
        //     // func_array[10] = [this](ifstream){ mult; };
        //     // func_array[11] = [this](ifstream){ mod; };
        //     // func_array[12] = [this](ifstream){ and_; };
        //     // func_array[13] = [this](ifstream){ or_; };
        //     // func_array[14] = [this](ifstream){ not_; };
        //     // func_array[15] = [this](ifstream){ rmem; };
        //     // func_array[16] = [this](ifstream){ wmem; };
        //     // func_array[17] = [this](ifstream){ call; };
        //     // func_array[18] = [this](ifstream){ ret; };
        //     // func_array[19] = [this](ifstream){ out; };
        //     // func_array[20] = [this](ifstream){ in_; };
        //     // func_array[21] = [this](ifstream){ noop; };

        // }

    uint16 running=1; //

    //void fetch();
    //void decode();
    //void execute();
    public:
        //VM constructor

    numtype to_binary_format (const uint32_t value);
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

    numtype get_mem(uint16_t& mem_it);

    void set_mem(int mem_it, char mem);

};