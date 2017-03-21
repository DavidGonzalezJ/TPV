#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;
class PBBVMprog
{
	static const int MAX_SIZE = 100;
	char instr[MAX_SIZE];
	int size;

public:
	enum ENUM { GET_DX, GET_DY,	SET_DX, SET_DY,	GET_CLICKS,	DEACTIVATE,	GET_POINTS, SET_POINTS, 
		GAIN_POINTS, ADD, MUL, SUB, PUSH, GOTO, JMPZ, JMPGT };

	PBBVMprog(string filename) {
		ifstream in;
		in.open(filename, ios::binary);

		in.seekg(0, ios::end);
		size = (int)in.tellg();
		assert(size <= MAX_SIZE);
		in.seekg(0, ios::beg);
		in.read(instr, size);

		in.close();
	}
	~PBBVMprog(){

	}

	const char* getInstr() {
		return instr;
	}

	int getInstrSize() {
		return size;
	}


	static void compile(string infile, string outfile) {
		ifstream in;
		ofstream out;

		in.open(infile);
		out.open(outfile, ios::binary);
 
		char bytecode[MAX_SIZE];
		int addr[MAX_SIZE];
		bool pending[MAX_SIZE];
		string keyword;
		int  pc = 0;
		int bytecodeNum = -1;

		while (!in.eof()) {
			in >> keyword;
			if (/*in.good()*/!in.bad()) {
				bytecodeNum++;
				addr[bytecodeNum] = pc;
				pending[bytecodeNum] = false;
				cout << "Compiling: " << keyword << endl;
				if (keyword == "GET_DX") {
					bytecode[pc++] = GET_DX;
				}
				else if (keyword == "GET_DY") {
					bytecode[pc++] = GET_DY;
				}
				else if (keyword == "SET_DX") {
					bytecode[pc++] = SET_DX;
				}
				else if (keyword == "SET_DY") {
					bytecode[pc++] = SET_DY;
				}
				else if (keyword == "GET_CLICKS") {
					bytecode[pc++] = GET_CLICKS;
				}
				else if (keyword == "DEACTIVATE") {
					bytecode[pc++] = DEACTIVATE;
				}
				else if (keyword == "GET_POINTS") {
					bytecode[pc++] = GET_POINTS;
				}
				else if (keyword == "SET_POINTS") {
					bytecode[pc++] = SET_POINTS;
				}
				else if (keyword == "GAIN_POINTS") {
					bytecode[pc++] = GAIN_POINTS;
				}
				else if (keyword == "ADD") {
					bytecode[pc++] = ADD;
				}
				else if (keyword == "MUL") {
					bytecode[pc++] = MUL;
				}
				else if (keyword == "SUB") {
					bytecode[pc++] = SUB;
				}
				else if (keyword == "PUSH") {
					int n;
					in >> n;
					bytecode[pc++] = PUSH;
					*((int *)(bytecode + pc)) = n;
					pc = pc + sizeof(int);
				}
				else if (keyword == "GOTO") {
					int n;
					in >> n;
					bytecode[pc++] = GOTO;
					if (n < bytecodeNum){
						*((int *)(bytecode + pc)) = addr[n];
					}
					else{
						pending[bytecodeNum] = true;
						*((int *)(bytecode + pc)) = n; // Almacenamos la n
					}
					pc = pc + sizeof(int);
				}
				else if (keyword == "JMPZ") {
					//bytecode[pc++] = JMPZ;
					int n;
					in >> n;
					bytecode[pc++] = JMPZ;
					if (n < bytecodeNum) {
						*((int *)(bytecode + pc)) = addr[n];
					}
					else {
						pending[bytecodeNum] = true;
						*((int *)(bytecode + pc)) = n; // Almacenamos la n
					}
					pc = pc + sizeof(int);
					
				}
				else if (keyword == "IFGT") {

					int n;
					in >> n;
					bytecode[pc++] = JMPGT;
					if (n < bytecodeNum) {
						*((int *)(bytecode + pc)) = addr[n];
					}
					else {
						pending[bytecodeNum] = true;
						*((int *)(bytecode + pc)) = n; // Almacenamos la n
					}
					pc = pc + sizeof(int);

				}
				else {
					throw "Error!";
				}
				
			} 	
		}
	for (int i = 0; i <= bytecodeNum; i++){
		if (pending[i]){
			int n = *((int*)(bytecode + addr[i] + 1));
			if (n <= bytecodeNum){
				*((int*)(bytecode + addr[i]+1)) = addr[n];
			}
			else
			{
				*((int*)(bytecode + addr[i] + 1)) = pc++;
			}
		}
	
	}
		out.write(bytecode, pc);

		in.close();
		out.close();
	}
};

