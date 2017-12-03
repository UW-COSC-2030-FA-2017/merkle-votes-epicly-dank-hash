#pragma once

#include <string>
#include <queue>
#include <vector>
using namespace std;

class bTREE
{

    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need



public:

    bTREE();
	
    ~bTREE();

	struct treeNode {
		string data;
		int time;
		int searchCount;
		int insertCount;
		treeNode *left;
		treeNode *right;
		treeNode(string dataIn, int timeIn)
		{
			this->searchCount = 0;
			this->data = dataIn;
			this->time = timeIn;
			this->left = NULL;
			this->right = NULL;
		}


		friend bool operator==(treeNode const & lhs, treeNode const & rhs)
		{
			return lhs.data == rhs.data
				&& ((lhs.left == 0 && rhs.left == 0)
					|| (lhs.left != 0 && rhs.left != 0 && *lhs.left == *rhs.left))
				&& ((lhs.right == 0 && rhs.right == 0)
					|| (lhs.right != 0 && rhs.right != 0 && *lhs.right == *rhs.right));
		}



	};


	treeNode *head;
	queue< treeNode* > q;
	queue< treeNode* > q1;
	queue< treeNode* > q2;
	vector<char*> path;



	//These were added
	void destroyTree(treeNode *leaf);
	long size(const treeNode *subtree);
	long leaves(const treeNode *subtree);

	treeNode* returnHead(treeNode *root);
	treeNode* returnLeft(treeNode *root)
	{
		return root->left;
	}
	treeNode* returnRight(treeNode *root)
	{
		return root->right;
	}

	struct treeNode* bTREE::newNode(string data, int time);

	//Functions for inorder prints
	void inorder_print(treeNode *leaf);
	void inorder_print();

	//Functions for printing tree
	void display(std::ostream& outfile);
	void displayLeft(std::ostream& outfile, treeNode * subtree, std::string prefix);
	void displayRight(std::ostream& outfile, treeNode * subtree, std::string prefix);

	//Functions for Insert
    bool hasBothChild(treeNode *root);
	void insertNode(treeNode **root, string data, int time, queue< treeNode * > &q);

	//Functions for finding node
	int findNode(struct treeNode* root, string data);
	bool isFound(struct treeNode* root, string x);
	void incCount();
	void incInsertCount();
	void print_queue(queue< treeNode* > q);

	void printPostorderB(treeNode* node);
	void printPostorderB();

	//Functions for locate
	bool printAncestors(struct treeNode *root, string target);


	bool isReallySame(treeNode* p, treeNode* q);
	


	//These are for the pmt find
	bool find(int time);
	bool bTREE::isFound(struct treeNode* root, int x);

	//These were here

    int dataInserted();

    int numberOfNodes();
    
    int insert(string, int);
    
    int find(string);
    
    string locate(string);
    
    
	//Treenode comparison


	
	bool operator==(const bTREE & rhs);
	bool operator != (const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

