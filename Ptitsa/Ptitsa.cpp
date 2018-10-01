#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>

#include "Compiler\NewLexer.h"
#include "Compiler\BuildContextTree.h"
#include "Compiler\Util.h"
#include "Compiler\InterpretTree.h"
//#include "Compiler\BuildContextTree.h"
//#include "Compiler\BuildContextTree.h"
//#include "Compiler\InterpretTree.h"

std::string getCode()
{
	std::string const INPUT_FILE = "D:/Code/C++/Ptitsa/Ptitsa/program.pti";

	std::ifstream file(INPUT_FILE);
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

void writeCode(const std::string& cppCode)
{
	std::string const OUTPUT_FILE = "D:/Code/C++/Ptitsa/Ptitsa/program.cpp";
	std::ofstream output(OUTPUT_FILE);
	output << cppCode;
	output.close();
}

int main()
{ 
	std::vector<NewLexer::LexemeLine> lexemeDoc = NewLexer::createTypedLexemes(getCode());
	NewLexer::parseTypedLexemes(lexemeDoc);
	std::vector<BuildContextTree::ContextTree> trees = BuildContextTree::generateContextTrees(lexemeDoc);
	std::cout << InterpretTree::treesToString(trees) << std::endl;
}
// */

