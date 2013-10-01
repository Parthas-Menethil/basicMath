/*
	Basic Math Header
	Author: Luke Jingwei Sun
	Description: Declare prototypes

*/

#ifndef __MATHINTERPRETER_H__
#define __MATHINTERPRETER_H__
#define LUKE_MATHINTERPRETER_VERSION	"1.0.1"
#define LUKE_MATHINTERPRETER_AUTHOR		"Luke Jingwei Sun"
#define LUKE_MATHINTERPRETER_LASTUPDATE	"Luke Jingwei Sun"
namespace lukesun{
	class MathInterpreter{
	private:
		bool autoPrint;
		bool isValidExpression(int argc, char* argv[]);
		bool isValidNumber(char* pStr);
	public:
		MathInterpreter();
		MathInterpreter(int argc, char* argv[]);
		int processExpression(int argc, char* argv[]);
	};

}
#endif
