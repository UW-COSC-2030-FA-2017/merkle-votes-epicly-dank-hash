#pragma once

#include "bTREE.h"
#include <string>
using namespace std;
class pMT
{
private:

   	queue< bTREE::treeNode* > qMerk;
	vector<char*> pathNode;

public:

	bTREE myMerkle;
	int selectedHash;
	

	//New stuff
	void insertNodeMerk(bTREE::treeNode **root, string data, int time, queue< bTREE::treeNode * > &q);
	bool hasBothChildMerk(bTREE::treeNode *root);

	
	bool printAncestors(bTREE::treeNode *root, string target);


	void update(bTREE::treeNode *root, int select);
	void pMT::update(int select);


	void rHash_1(bTREE::treeNode* root);
	void rHash_2(bTREE::treeNode* root);
	void rHash_3(bTREE::treeNode* root);


	void displayMerk(std::ostream& outfile);
	void displayLeft(std::ostream & outfile, bTREE::treeNode * subtree, std::string prefix);
	void displayRight(std::ostream & outfile, bTREE::treeNode * subtree, std::string prefix);


	//

    pMT(int);
    ~pMT();
    
	string hash_1(string str);
	string hash_2(string str);
	string hash_3(string str);
    
    int insert(string, int);
    
   // int find(string);
    int findHash(string);
	int find(string vote, int time, int hashSelect);


    string locate(string Node);
	string locateData(string vote);
	string locateHash(string mhash);


    bool operator==(const pMT& rhs);
    bool operator!=(const pMT& rhs);
	pMT operator ^(const pMT& rhs);



  //  friend std::ostream& operator<<(std::ostream& out, const pMT& p);
  // The professor said as long as we can display the tree we dont need to use this
    
};

