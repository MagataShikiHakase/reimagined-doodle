#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream programming;
	programming.open("inside.cpp");

	programming << "#include <iostream>" << endl;
	programming << "#include <fstream>" << endl << endl;
	programming << "using namespace std;" << endl << endl;
	programming << "int main()" << endl;
	programming << "{" << endl;
	programming << "ofstream programming;" << endl;
	programming << "programming.open(\"insideOfInside.cpp\");" << endl << endl;
	programming << "programming << \"#include <iostream>\" << endl;" << endl;
	programming << "programming << \"#include <fstream>\" << endl << endl;" << endl << endl;
	programming << "programming << \"using namespace std;\" << endl << endl;" << endl << endl;
	programming << "programming << \"int main()\" << endl;" << endl;
	programming << "programming << \"{\" << endl;" << endl;
	programming << "programming << \"ofstream programming;\" << endl;" << endl;
	programming << "programming << \"programming.open(\\\"insideOfInsideOfInside.cpp\\\");\" << endl;" << endl;
	programming << "programming << \"programming << \\\"cout << \\\"if I keep writing this code, my brain would be crazy, so I stop here.\\\" << endl; \" << endl;" << endl;
	programming << "programming << \"programming.close();\" << endl;" << endl;
	programming << "programming << \"}\" << endl;" << endl;
	programming << "programming.close()" << endl;
	programming << "}" << endl;
}