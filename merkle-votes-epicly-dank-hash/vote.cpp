#include <stdio.h>
#include "pMT.h"
#include "bTREE.h"
#include <iostream>
using namespace std;


int main(int argc, char **argv)
{
	printf("hello world\n");

	

	bTREE *tree = new bTREE();
	

	

	tree->insert("string", 101);
	tree->insert("sg1", 99);
	tree->insert("stng2", 57);
	tree->insert("sting3", 14);
	tree->insert("stng4", 125);
	tree->insert("string5", 16);
	tree->insert("strig6", 177);
	tree->insert("stasdad", 1126);
	tree->insert("stgfdfg", 17732);



	tree->display(cout);

	cout << endl << "Number of nodes: " << tree->numberOfNodes() << endl;
	cout << endl <<"Data inserted: "<< tree->dataInserted() << endl;
	cout << endl << "Search for stasdad: " << tree->find("sting3") << endl;

	tree->inorder_print();
	return 0;
}
