#include <iostream>
#include <fstream>
#include <time.h>
#include "BinaryTree.h"

using namespace std;

//https://visualgo.net/en/bst


BinaryTree::BinaryTree()
{
}

BinaryTree::~BinaryTree()
{

}

//************************************************************************
// Receives a filename to place the Graph data into the file
//************************************************************************
void BinaryTree::NodeAssembly()
{
	char InFileName [40];
	char OutFileName [40];
	char GraphType [40];
	char NodeNames [40];
	char label [90];

	int Nodes = 0;

	ifstream infile;
	ofstream outfile;

	cout << "Enter the input file name:";
	cin >> InFileName;
	infile.open(InFileName); //open input file

	cout << "Enter the output file name:";
	cin >> OutFileName;
	outfile.open(OutFileName);//open out putfile
	cout << '\n';

	//makes sure the infile can be opened
	if (infile.fail())
	{
		cout << "Could not open infile. \n\n";
		system("pause");
	}
	//makes sure the outfile can be opened
	else if (outfile.fail())
	{
		cout << "Could not open outfile. \n\n";
		system("pause");
	}

	infile >> GraphType;
	outfile << GraphType << " Graph\n{\n";

	infile >> Nodes;

	for (int i = 0; i < Nodes; i++)
	{
		infile >> NodeNames >> label;
		outfile << NodeNames << "[label=\"" << label << "\"]\n";
	}
	AssembleGraph(infile, outfile);

	outfile << '}';

	infile.close();
	outfile.close();
}

void BinaryTree::AssembleGraph(ifstream &infile, ofstream &outfile)
{
	int linkage = 0, weight;
	char Node1[40];
	char Node2[40];

	infile >> linkage;
	for (int i = 0; i < linkage; i++)
	{
		infile >> Node1 >> Node2 >> weight;
		outfile << Node1 << "->" << Node2 << "[label=\"" << weight << "\"]\n";
	}
}