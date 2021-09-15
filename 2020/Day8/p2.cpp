#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct instruction {
    string operation;
    int argument;
    bool visited;

    instruction(string op, int arg) {
        operation = op;
        argument = arg;
        visited = false;
    }
};

int execute(vector<instruction> &ins, instruction& in, int ind) {
    static int acc = 0;

    if (in.visited)
        return acc;

    in.visited = true;

    if (in.operation == "acc") {
        acc += in.argument;
        if(ind < ins.size() - 1)
            execute(ins, ins[ind + 1], ind + 1);
    }
    else if (in.operation == "jmp") {
        if (ind < ins.size() - 1)
            execute(ins, ins[ind + in.argument], ind + in.argument);
    }
    else {
        if (ind < ins.size() - 1)
            execute(ins, ins[ind + 1], ind + 1);
    }

    return acc;
}

bool findOperation(vector<instruction>& ins, instruction& in, int ind) {
    if (ind == ins.size() - 1)
        return true;

    if (in.visited)
        return false;

    in.visited = true;

    if (in.operation == "acc") {
        return findOperation(ins, ins[ind + 1], ind + 1);
    }
    else if (in.operation == "jmp") {
        return findOperation(ins, ins[ind + in.argument], ind + in.argument);
    }
    else {
        return findOperation(ins, ins[ind + 1], ind + 1);
    }
}

int findError(vector<instruction>& ins) {
    vector<vector<instruction>> allIns;
    vector<instruction> copyIns = ins;

    for (int i = 0; i < ins.size(); i++) {
        if (copyIns[i].operation == "acc")
            continue;
        else if (copyIns[i].operation == "jmp") {
            copyIns[i].operation = "nop";
            allIns.push_back(copyIns);
            copyIns[i].operation = "jmp";
        }
        else {
            copyIns[i].operation = "jmp";
            allIns.push_back(copyIns);
            copyIns[i].operation = "nop";
        }
    }


    for (vector<instruction> in : allIns) {
        if (findOperation(in, in[0], 0)) {
            for (instruction &i : in) {
                i.visited = false;
            }
            return execute(in, in[0], 0);
        }
    }

    return -1;
}


int main()
{
    ifstream in("input.txt");
    string line;
    vector<instruction> instructions;

    while (getline(in, line))
    {
        istringstream ss(line);

        string op;
        int arg;

        ss >> op >> arg;

        instructions.push_back(instruction(op, arg));
    }

    cout << "Accumulator value is " << findError(instructions) << "\n";

    in.close();
}