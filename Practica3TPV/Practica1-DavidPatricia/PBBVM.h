#pragma once
#include "PBBExternAccess.h"
#include "PBBVMprog.h"
#include <iostream>
class PBBVM
{
public:
	PBBVM();
	~PBBVM();

	static const int MAX_SIZE = 100;
	int stack[MAX_SIZE];
	int stackSize;

	void push(int n) {
		stack[stackSize++] = n;
	}
	int pop() {
		return stack[--stackSize];
	}

	void run(PBBVMprog& prog, PBBExternAccess& bball) {
		const char*instr = prog.getInstr();
		int size = prog.getInstrSize();
		for (int pc = 0; pc<size; pc++) {
			switch (instr[pc]) {
			case PBBVMprog::GET_DX:
				push(bball.getX());
				pc = pc + sizeof(int);
				break;
			case PBBVMprog::GET_DY:
				push(bball.getY());
				pc = pc + sizeof(int);
				break;
			case PBBVMprog::SET_DX:
				bball.setX(pop());
				break;
			case PBBVMprog::SET_DY:
				bball.setY(pop());
				break;
			case PBBVMprog::PUSH:
				push(*((int*)(instr + pc + 1)));
				pc = pc + sizeof(int); // the for loop will add 1 break;
				std::cout << pop() << "\n";
				break;
			case PBBVMprog::DEACTIVATE:
				bball.disable();
				break;
			case PBBVMprog::GET_POINTS:
				push(bball.getPuntos());
				pc = pc + sizeof(int);
				break;
			case PBBVMprog::SET_POINTS:
				bball.setPuntos(pop());
				break;
			case PBBVMprog::GAIN_POINTS:
				bball.addPoints(pop());
				break;
			case PBBVMprog::ADD:
				push(pop() + pop());
				break;
			case PBBVMprog::MUL:
				push(pop() * pop());
				break;
			case PBBVMprog::SUB:
				push(pop() - pop());
				break;
			case PBBVMprog::GOTO:
				push(pop() * pop());///
				break;
			case PBBVMprog::JMPZ:
				push(pop() * pop());
				break;
			case PBBVMprog::JMPGT:
				push(pop() * pop());
				break;
			}
		}
	}
}
