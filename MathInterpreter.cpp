/*
	Basic Math Class
	Author: Luke Jingwei Sun
	Description: Process and interpret incoming queries

*/
#include "MathInterpreter.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
namespace lukesun{

	MathInterpreter::MathInterpreter(){
		autoPrint = true;
		std::cout<<"Math Interpreter V"<<LUKE_MATHINTERPRETER_VERSION<<std::endl
		<<"Author:"<<LUKE_MATHINTERPRETER_AUTHOR<<std::endl;
	}
	MathInterpreter::MathInterpreter(int argc, char* argv[]){
		autoPrint = true;
		processExpression(argc, argv);
	}
	bool MathInterpreter::isValidExpression(int argc, char* argv[]){
		if (argc != 4){
			return false;
		}
		if (!argv){
			return false;
		}
		if (strlen(argv[2]) != 1){
			return false;
		}
		if (!strcmp(argv[2], "+") &&
			!strcmp(argv[2], "-") &&
			!strcmp(argv[2], "x") &&
			!strcmp(argv[2], "/"))
		{
			return false;
		}
		if (!isValidNumber(argv[1])){
			return false;
		}
		if (!isValidNumber(argv[3])){
			return false;
		}
		if (!strcmp(argv[2], "/") && !strcmp(argv[3], "0")){
			return false;
		}
		return true;
	}
	int MathInterpreter::processExpression(int argc, char* argv[]){
		if (isValidExpression(argc, argv)){
			char* pEnd = NULL;
			int para1 = strtol(argv[1], &pEnd, 10),
				para2 = strtol(argv[3], &pEnd, 10),
				result = 0;
			switch (argv[2][0]){
			case '+':
				result = para1 + para2;
				break;
			case '-':
				result = para1 - para2;
				break;
			case 'x':
				result = para1 * para2;
				break;
			case '/':
				result = para1 / para2;
				break;
			default:
				result = 0;
			}
			if (autoPrint){
				std::cout<<result<<std::endl;
			}
			return result;
		}
	}
	bool MathInterpreter::isValidNumber(char* pStr){
		if (!pStr){
			return false;
		}
		int length = strlen(pStr);
		if (length == 0){
			return false;
		}
		int i = 0;
		for (i = 0; i < length; i++){
			if (pStr[i] < '0' || pStr[i] > '9'){
				return false;
			}
		}
		return true;
	}
}