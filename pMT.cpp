#include "pMT.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stack>
#include <vector>

/**
 * @brief 
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return 
 */
queue< bTREE::treeNode* > diffMerk;

pMT::pMT(int hashSelect)
{
	myMerkle.head = NULL;
	selectedHash = hashSelect;
}

/**
 * @brief destructor
 * @return nada
 */
pMT::~pMT()
{
	myMerkle.destroyTree(myMerkle.head);
	
}


int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time 
 * @return the number of operations needed to do the insert, -1 if out of memory
 */

{

	myMerkle.insert(vote, time);


	//insertNodeMerk(&myMerkle.head, vote, time, qMerk);
	return 1;
}

void pMT::update(int select)
{
	update(myMerkle.head, select);
}

void pMT::update(bTREE::treeNode *root, int select)
{
	if (root)
	{
	
		if (select == 1)
		{
			rHash_1(root);
		}
		else if (select == 2)
		{
			rHash_2(root);
		}
		else if (select == 3)
		{
			rHash_3(root);
		}
	}
	else
	{
		return;
	}

}



bool pMT::hasBothChildMerk(bTREE::treeNode *root)
{
	return (root != NULL && root->left != NULL && root->right != NULL);
}

void pMT::insertNodeMerk(bTREE::treeNode **root, string data, int time, queue< bTREE::treeNode * > &q) {

	myMerkle.insert(data, time);

}



int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{
	myMerkle.head->searchCount = 0;
	if (myMerkle.find(vote) && myMerkle.find(time))
	{
		
		return myMerkle.head->searchCount;
	}
	else
	{
		return 0;
	}
}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
	myMerkle.head->searchCount = 0;
	if (myMerkle.find(mhash))
	{
		return myMerkle.head->searchCount;
	}
	else
	{
		return 0;
	}
}



string pMT::locateData(string vote)
/**
 * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param vote, the data to search for 
 * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
 */
{
	return myMerkle.locate(vote);
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param mhash, the hash to search for 
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
	return myMerkle.locate(mhash);
}

string pMT::locate(string Node)
{
	string parth;

	printAncestors(myMerkle.head, Node);


	for (int i = pathNode.size() - 1; i >= 0; i--)
	{
		parth += pathNode[i];
	}


	return parth;
}
	
bool pMT::printAncestors(bTREE::treeNode *root, string target)
{

	if (root == NULL)
		return false;

	if (root->data == target)
		return true;

	if (printAncestors(root->left, target))
	{
		pathNode.push_back("L");
		return true;
	}

	else if (printAncestors(root->right, target))
	{
		pathNode.push_back("R");
		return true;
	}
	return false;
}





template< typename T >std::string int_to_hex(T i)
{
	std::stringstream stream;
	stream << "0x"
		<< std::setfill('0') << std::setw(sizeof(T) * 2)
		<< std::hex << i;
	return stream.str();
}

string pMT::hash_1(string key) //Erik Horwitz Hash
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{

	std::string str = key;

	const char *cstr = str.c_str();

	unsigned long hash = 15485;
	unsigned long hash2 = 1223;
	unsigned long hash3 = 8741;
	unsigned long hash4 = 11657;
	int c;

	while (c = *cstr++)
		hash = (((((hash * c) % hash3) + hash4) - hash3) * hash4);

	string hexHash = int_to_hex(hash);

	std::string strang(hexHash);

	return strang;
}

string pMT::hash_2(string key)//Aaron Baker Hash
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
	std::string str = key;

	const char *cstr = str.c_str();

	unsigned long hash = 15485863;
	unsigned long hash2 = 541;
	unsigned long hash3 = 8677;
	unsigned long hash4 = 1301057;
	int c;

	while (c = *cstr++)
		hash = (((((hash / 1299721) + hash2) + c) ^ hash3) * hash4);

	/* (((((hash / 1299721) + 541) + c) ^ 8677) * 1301057) */

	string hexHash = int_to_hex(hash);

	std::string strang(hexHash);

	return strang;

}

string pMT::hash_3(string key)//Jacob Claytor Hash
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
	string str = key;
	const char *cstr = str.c_str();

	unsigned long hash = 105323;
	int c;

	while (c = *cstr++)
	{
		hash = (((c * (hash ^ c)) % 1300141) * 7) * 14111;
	}

	string hexHash = int_to_hex(hash);

	std::string strang(hexHash);

	return strang;
}



void pMT::rHash_1(bTREE::treeNode* root)
{
	if (root == NULL)
		return;

	// first recur on left subtree

	if (hasBothChildMerk(root))
	{
		rHash_1(root->left);
		rHash_1(root->right);


		root->data = hash_1((root->left->data) + (root->right->data));
	}
	else
	{
		return;
	}
}

void pMT::rHash_2(bTREE::treeNode* root)
{
	if (root == NULL)
		return;

	// first recur on left subtree

	if (hasBothChildMerk(root))
	{
		rHash_2(root->left);
		rHash_2(root->right);


		root->data = hash_2((root->left->data) + (root->right->data));
	}
	else
	{
		return;
	}
}

void pMT::rHash_3(bTREE::treeNode* root)
{
	if (root == NULL)
		return;

	// first recur on left subtree

	if (hasBothChildMerk(root))
	{
		rHash_3(root->left);
		rHash_3(root->right);


		root->data = hash_3((root->left->data) + (root->right->data));
	}
	else
	{
		return;
	}
}




bool isSameMerk(bTREE::treeNode* p, bTREE::treeNode* q)
{

	/*1. both empty */
	if (p == NULL && q == NULL)
		return 1;

	/* 2. both non-empty -> compare them */
	if (p != NULL && q != NULL)
	{
		return
			(
				p->data == q->data &&
				isSameMerk(p->left, q->left) &&
				isSameMerk(p->right, q->right)
				);
	}

	/* 3. one empty, one not -> false */
	return 0;

}


bool pMT::operator ==(const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if equal, false otherwise
 */
{
	
	bool same = isSameMerk(this->myMerkle.head, rhs.myMerkle.head);
	return same;
}

bool pMT::operator !=(const pMT& rhs)
/**
 * @brief Comparison between two merkle trees
 * @param lhs, the left hand side of the equality statment
 * @param rhs, the right hand side of the equality statement
 * @return true if not equal, false otherwise
 */
{
	bool same = isSameMerk(this->myMerkle.head, rhs.myMerkle.head);
	return !same;
}



//pMT pMT::operator ^(const pMT& rhs)
/**
 * @brief Where do two trees differ
 * @param lhs
 * @param rhs
 * @return a tree comprised of the right hand side tree nodes that are different from the left
 */
//{
//}




//std::ostream& operator <<(std::ostream& out, const pMT& p)
/**
* @brief Print out a tree
* @param out
* @param p
* @return a tree to the screen
*/
//{
	//The professor said as long as we can display the tree we dont need to use this
	//See below

//}


void pMT::displayMerk(std::ostream& outfile)
{
	std::string prefix;
	if (myMerkle.head == NULL)
	{
		outfile << "-" << std::endl;
	}
	else
	{
		displayLeft(outfile, myMerkle.head->left, "    ");
		outfile << "---" << myMerkle.head->data << std::endl;
		displayRight(outfile, myMerkle.head->right, "    ");
	}
}

void pMT::displayLeft(std::ostream & outfile, bTREE::treeNode * subtree, std::string prefix)
{
	if (subtree == NULL)
	{
		outfile << prefix + "/" << std::endl;
	}
	else
	{
		displayLeft(outfile, subtree->left, prefix + "     ");
		outfile << prefix + "/---" << subtree->data << std::endl;
		displayRight(outfile, subtree->right, prefix + "|    ");
	}
}

void pMT::displayRight(std::ostream & outfile, bTREE::treeNode * subtree, std::string prefix)
{
	if (subtree == NULL)
	{
		outfile << prefix + "\\" << std::endl;
	}
	else
	{
		displayLeft(outfile, subtree->left, prefix + "|    ");
		outfile << prefix + "\\---" << subtree->data << std::endl;
		displayRight(outfile, subtree->right, prefix + "     ");
	}
}
