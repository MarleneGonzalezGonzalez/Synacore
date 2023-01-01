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
        numtype memory[33000];
        uint16_t mem_idx = 0;


        numtype read_value(numtype val);
        void write_value(int pos, numtype val);
        
        void run_program(uint16 ptr);

        public:
        char c;
        typedef void (VM::*functptr_arr)(VM*);
        // void (halt_)(ifstream& line);
        void  halt( VM* vm);
        // void (VM::*halt)(ifstream& line) = &VM::halt_;
        // unique_ptr<>;        
        void  set( VM* vm);
        void  push( VM* vm);
        void  pop( VM* vm);
        void  eq( VM* vm);
        void  gr( VM* vm);
        void  jmp( VM* vm);
        void  jt( VM* vm);
        void  jf( VM* vm);
        void  add( VM* vm);
        void  mult( VM* vm);
        void  mod( VM* vm);
        void  and_( VM* vm);
        void  or_( VM* vm);
        void  not_( VM* vm);    
        void  rmem( VM* vm);
        void  wmem( VM* vm);
        void  call( VM* vm);
        void  ret( VM* vm);
        void out( VM* vm);
        void  in_( VM* vm);
        void  noop( VM* vm);

        functptr_arr functptr[23] = {&VM::halt, &VM::set, &VM::push, &VM::pop, &VM::eq, &VM::gr, &VM::jmp, &VM::jt, &VM::jf, &VM::add, &VM::mult, &VM::mod,
            &VM::and_, &VM::or_, &VM::not_, &VM::rmem, &VM::wmem, &VM::call, &VM::ret, &VM::out, &VM::in_, &VM::noop} ;

        // functptr_arr functptr[23] = {halt, set, push, pop, eq, gr, jmp, jt, jf, add, mult, mod,
        //     and_, or_, not_, rmem, wmem, call, ret, out, in_, noop} ;

    public:
        //void (*funct[22])(void); 
        // (* arr [3])(int)
        
        // typedef void(*func_t)(ifstream&);
        // void (VM::*func_array[23])(ifstream& st);
        // typedef std::function<void(ifstream)> as func_t;
        // using func_t = std::function<void(ifstream)>;
        // std::array< func_t, 23> func_array; 
        // typedef void(*func_t)(ifstream&);
        // void (VM::*func_array[23])(VM* vm);

        uint16 running=1; //

        void load_file(std::string file){
            std::ifstream line("../bin/challenge.bin", std::ios::binary);
            int i = 0;
            char bytes[2];
            while (line.read(bytes,2)){
                uint16_t val =  *reinterpret_cast<uint16_t*>(&bytes);
                memory[i] = val;
                i++;
            }
        }

        void run(){

            uint16_t last_op;

            while (true){
                last_op = memory[this->mem_idx];
                // std::cout << this->mem_idx << std::endl;
                // std::cout << last_op << std::endl;
                (this->*functptr[last_op])(this);
                
                this->mem_idx++;
            }
        }

        //VM constructor

    numtype to_binary_format (const uint16_t value);
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

    numtype get_mem(uint16_t& mem_it){
        return memory[mem_it];
    }

    void set_mem(int mem_it, uint16_t mem){
        if (mem_it < 32776){
            //add memory int and see how to set memory to value specific
            memory[mem_it] = mem;
        }
    }

};