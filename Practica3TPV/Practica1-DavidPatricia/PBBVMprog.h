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
		GAIN_POINTS, ADD, MUL, SUB, PUSH, GOTO, JMPZ };

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

		string keyword;
		int  pc = 0;

		while (!in.eof()) {
			in >> keyword;
			if (in.good()) {
				cout << "Compiling: " << keyword << endl;
				if (keyword == "Get_dx") {
					bytecode[pc++] = GET_DX;
				}
				else if (keyword == "Get_dy") {
					bytecode[pc++] = GET_DY;
				}
				else if (keyword == "Set_dx") {
					bytecode[pc++] = SET_DX;
				}
				else if (keyword == "Set_dy") {
					bytecode[pc++] = SET_DY;
				}
				else if (keyword == "Get_clicks") { ////ESPECIAL
					bytecode[pc++] = GET_CLICKS;
				}
				else if (keyword == "Push") { ////ESPECIAL
					bytecode[pc++] = PUSH;
				}
				else {
					throw "Error!";
				}
			}
		}
		out.write(bytecode, pc);

		in.close();
		out.close();
	}
};

