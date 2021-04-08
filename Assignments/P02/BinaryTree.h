#include <iostream>
#include <string>


using namespace std;

class BinaryTree
{
	public:
	BinaryTree();
	~BinaryTree();
	void NodeAssembly();
	void AssembleGraph(ifstream &infile, ofstream &outfile);
};