///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Seth Allen
// Email:            Sballen085@gmail.com
// Label:            Binary Tree
// Title:            Binary Tree
// Course:           CMPS 2143
// Semester:         2021 Spring 
//
// Description:
//       Builds a self balancing binary tree from random values
//	     from a class
//	
//Note:	assembled in vscode 2019
//
// Usage:
//       type in the outfile and type of shape you wish to use it will build the
//		 binary tree from those selection and plave it in your outfile
//
// Files:            Source.cpp, BinaryTree.cpp,BinaryTree.h
/////////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <string>
#include "BinaryTree.h"

int main()
{
	BinaryTree MyTree;

	MyTree.NodeAssembly();

	system("pause");
	return 0;
}