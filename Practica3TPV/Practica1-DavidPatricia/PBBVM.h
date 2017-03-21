#pragma once
#include "PBBExternAccess.h"
#include "PBBVMprog.h"
#include <iostream>

class PBBVM
{
public:
	PBBVM() {};
	~PBBVM() { };

	static const int MAX_SIZE = 100;
	int stack[MAX_SIZE];
	int stackSize = 0;

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
					break;

				case PBBVMprog::GET_DY:
					push(bball.getY());
					break;

				case PBBVMprog::SET_DX:
					bball.setX(pop());
					break;

				case PBBVMprog::SET_DY:
					bball.setY(pop());
					break;

				case PBBVMprog::GET_CLICKS:
					push(bball.getClicks());
					break;

				case PBBVMprog::DEACTIVATE:
					bball.disable();
					break;

				case PBBVMprog::GET_POINTS:
					push(bball.getPuntos());
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

				case PBBVMprog::PUSH:
					push(*((int*)(instr + pc + 1)));
					pc = pc + sizeof(int); // the for loop will add 1 break;
					break;

				case PBBVMprog::GOTO:
					pc = *((int*)(instr + pc+1));
					break;

				case PBBVMprog::JMPZ:				///FALTA
					if (pop() == 0){
						//SALTA
					}
					push(*((int*)(instr + pc + 1)));
					pc = pc + sizeof(int);
					break;

				case PBBVMprog::JMPGT:				///FALTA
					if (pop() > pop()){
						//SALTA
					}

					push(*((int*)(instr + pc + 1)));
					pc = pc + sizeof(int);
					break;

				default:
					break;
			}
		}
	}
};