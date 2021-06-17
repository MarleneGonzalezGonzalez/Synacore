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

        //void (*funct[22])(void);  

        void (VM::*func_ptr[23])(void) = {
            &VM::halt, 
            &VM::set,
            &VM::push,
            &VM::pop,
            &VM::eq,
            &VM::gr,
            &VM::jmp,
            &VM::jt,            //output (* pointer to function name) (function input)
            &VM::jf,
            &VM::add,
            &VM::mult,
            &VM::mod,
            &VM::and_,
            &VM::or_,
            &VM::not_,
            &VM::rmem,
            &VM::wmem,
            &VM::call,
            &VM::ret,
            &VM::out,
            &VM::in_,
            &VM::noop}; 

        //using instruction_t = std::function<void()>;
        //std::unordered_map<uint16_t, instruction_t> instruction_map {
        //    {0x01, f1},
        //    {0x02, f2},
        //    {0x03, [](){ std::cout << "f3\n";}}
        //};
            //f func[22];
        //funct[0]= halt;

        //void (*functions[3])(halt);
        //std::function<void> [3] ={halt, set, push};
        
        //unordered_map<uint16, void(VM::*)()> function_map = {
        //    {0x00,&halt},
        //    {0x01,&set},
        //    {0x02,&push}
        //};
            //{0x03,pop},
            //{0x04,eq},
            //{0x05,gr},
            //{0x06,jmp},
            //{0x07,jt},
            //{0x08,jf},
            //{0x09,add},
            //{0x10,mult},
            //{0x11,mod},
            //{0x12,and_},
            //{0x13,eq},
            //{0x14,or_},
            //{0x15,not_},
            //{0x16,rmem},
            //{0x17,wmem},
            //{0x18,call},
            //{0x19,ret},
            //{0x20,out},
            //{0x21,in_},
            //{0x22,noop}
        //};

    uint16 running=1; //

    //void fetch();
    //void decode();
    //void execute();
    public:
        void run();
        //VM constructor
        VM(std::string filename){
            std::ifstream line(filename, std::ios::binary);
            char bytes [2];
           
            int mem_idx=0;
            while ((mem_idx==0) && (line.read(bytes,2))){
                std::cout<<("aAaaa")<<std::endl;
            //    try{
                
                //reinterpret_cast<uint16_t*>(&btu[0])
                uint16_t output =bytes[1];
                output <<=8;
                output |= bytes[0];
                std::cout<<"output:"<<(output)<<std::endl;
                func_ptr[output];
            //    }
            //    catch(int mem_idx){
            //        std::cout<<mem_idx<<std::endl;
             //   }
                mem_idx++;


            }
        }

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
