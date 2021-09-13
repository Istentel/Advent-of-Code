#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct instruction{
    string operation;
    int argument;
    bool visited;

    instruction(string op, int arg){
        operation = op;
        argument = arg;
        visited = false;
    }
};

int execute(vector<instruction> &ins, instruction &in, int ind){
    static int acc = 0;

    if(in.visited)
        return acc;
    
    in.visited = true;

    if(in.operation == "acc"){
        acc += in.argument;
        execute(ins, ins[ind + 1], ind + 1);
    }else if(in.operation == "jmp"){
        execute(ins, ins[ind + in.argument], ind + in.argument);
    }else{
        execute(ins, ins[ind + 1], ind + 1);
    }

    return acc;
}


int main()
{
    ifstream in("input.txt");
    string line;
    int acc = 0;
    vector<instruction> instructions;

    while (getline(in, line))
    {
       istringstream ss(line);

       string op;
       int arg;

       ss >> op >> arg;

       instructions.push_back(instruction(op, arg));
    }

    acc = execute(instructions, instructions[0], 0);

    cout << "Accumulator value is " << acc << "\n";

    in.close();
}