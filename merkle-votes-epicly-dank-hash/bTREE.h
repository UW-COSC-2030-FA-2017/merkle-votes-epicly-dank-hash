#pragma once
#include <string>
#include <queue>
using namespace std;

class bTREE
{
    struct treeNode{
        string data;
        int time;
		int searchCount;
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
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
	treeNode *head;
	queue< treeNode* > q;
	queue< treeNode* > q1;
	queue< treeNode* > q2;
	
    
public:
    bTREE();
	
    ~bTREE();

	//These were added
	void destroyTree(treeNode *leaf);
	long size(const treeNode *subtree);
	long leaves(const treeNode *subtree);
	//void insertNode(string data, int time, treeNode* next);

	struct treeNode* bTREE::newNode(string data, int time);

	void inorder_print(treeNode *leaf);
	void inorder_print();


	void display(std::ostream& outfile);

	void displayLeft(std::ostream & outfile, treeNode * subtree, std::string prefix);
	void displayRight(std::ostream & outfile, treeNode * subtree, std::string prefix);

	bool hasBothChild(treeNode *root);
	void insertNode(treeNode **root, string data, int time, queue< treeNode * > &q);

	int findNode(struct treeNode* root, string data);
	bool isFound(struct treeNode* root, string x);
	void incCount();

	//These were here

    int dataInserted();
    int numberOfNodes();
    
    int insert(string, int);
    
    int find(string);
    
    string locate(string);
    
    
    friend bool operator==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

