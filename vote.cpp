#include <stdio.h>
#include "pMT.h"
#include "bTREE.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;



int main(int argc, char **argv)
{
	//Everything commented is just for testing the classes
	/*
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
	cout << endl << "Data inserted: " << tree->dataInserted() << endl;
	cout << endl << "Number of operations to find stasdad: " << tree->find("stasdad") << endl;
	cout << endl << "Locate function test for 'stng4': " << tree->locate("stng4") << endl;



	bTREE *tree1 = new bTREE();

	tree1->insert("string", 101);
	tree1->insert("sg1", 99);
	tree1->insert("stng2", 57);
	tree1->insert("sting3", 14);
	tree1->insert("stng4", 125);
	tree1->insert("string5", 16);
	tree1->insert("strig6", 177);
	tree1->insert("stasdad", 1126);
	tree1->insert("stgfdfg", 17732);


	tree1->display(cout);

	cout << endl << "Are tree and tree1 equal?: " << (*tree == *tree1)<<endl;
	cout << endl << "Are tree and tree1 not equal?: " << (*tree != *tree1) << endl;


	pMT *merkTree = new pMT(1);


	merkTree->insert("string", 101);
	merkTree->insert("sg1", 99);
	merkTree->insert("stng2", 57);
	merkTree->insert("sting3", 14);
	merkTree->insert("stng4", 125);
	merkTree->insert("string5", 16);
	merkTree->insert("strig6", 177);
	merkTree->insert("stasdad", 1126);
	merkTree->insert("stgfdfg", 17732);
	merkTree->insert("strang", 17234232);
	cout << "This is the merk" << endl;
	merkTree->displayMerk(cout);


	cout << endl << "Search for stasdad: " << merkTree->find("string 5", 16, 1) << endl;
	cout << endl << "Search for hash of stasdad: " << (merkTree->findHash(merkTree->hash_1("stng4"))) << endl;
	cout << endl << "Locate function test: " << merkTree->locate("strang") << endl;
	cout << endl << "Locate hash function test: " << merkTree->locateHash(merkTree->hash_1("stng4")) << endl;



	pMT *merkTree1 = new pMT(1);
	merkTree1->insert("string", 101);
	merkTree1->insert("sg1", 99);
	merkTree1->insert("stng2", 57);
	merkTree1->insert("sting3", 14);
	merkTree1->insert("stng4", 125);
	merkTree1->insert("string5", 16);
	merkTree1->insert("strig6", 177);
	merkTree1->insert("stasdad", 1126);
	merkTree1->insert("stgfd", 17732);
	merkTree1->insert("strang", 17234232);
	merkTree1->insert("strung", 172332);
	merkTree1->displayMerk(cout);

	cout << endl << "Are they the same: " <<(*merkTree==*merkTree1) << endl;
	cout << endl << "Are they not the same: " << (*merkTree != *merkTree1) << endl;
	*/
	

	//These functions compare 2 different Merkle Trees from different files
	//Comparing the same files will return Validated 


	int number_of_lines = 0;
	std::string line;
	std::ifstream myfile("mv_test.txt");

	while (std::getline(myfile, line))
	{
		++number_of_lines;
	}


	pMT *merkTree2 = new pMT(1);

	while (merkTree2->myMerkle.q.size()*2 < number_of_lines  )
	{

		merkTree2->myMerkle.insert("",-1);
	}




	std::string line2;
	std::ifstream myfile1("mv_test.txt");
	int size = 0;
	while (std::getline(myfile1, line2))
	{

		if (line2.find(":") != std::string::npos)
		{
			std::string delimiter = "	";
			size_t pos = 0;

			while ((pos = line2.find(delimiter)) != std::string::npos)
			{
				std::string data = line2.substr(0, line2.find(delimiter));
				line2.erase(0, pos + delimiter.length());
				merkTree2->myMerkle.insert(data, std::stoi(line2));
				size += 1;
			}
		}
	}


	pMT *merkTree3 = new pMT(1);

	std::string line3;
	std::ifstream myfile2("mv_test_1.txt");
	size = 0;
	while (std::getline(myfile2, line3))
	{
		if (line3.find(":") != std::string::npos)
		{
			std::string delimiter = "	";
			size_t pos = 0;

			while ((pos = line3.find(delimiter)) != std::string::npos)
			{
				std::string data = line3.substr(0, line3.find(delimiter));
				line3.erase(0, pos + delimiter.length());
				merkTree3->myMerkle.insert(data, std::stoi(line3));
				size += 1;
			}

		}
	}


	merkTree2->update(merkTree2->selectedHash);
	cout << endl << "First Merkle Tree" << endl;
	merkTree2->displayMerk(cout);

	merkTree3->update(merkTree3->selectedHash);
		cout << endl << "Second Merkle Tree" << endl;
	merkTree3->displayMerk(cout);

	if ((*merkTree2 == *merkTree3))
	{
		cout << endl << "Validated" << endl;
	}
	else
	{
		cout << endl << "Not Validated" << endl;
	}




	return 0;
}
