#include "bTREE.h"
#include <queue>
#include <iostream>

//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
{
	head = NULL;
	
}



bTREE::~bTREE()
{
	destroyTree(head);
}

void bTREE::incCount()
{
	head->searchCount= (head->searchCount)+1;
	cout << endl << head->searchCount << endl;
}

void bTREE::destroyTree(treeNode *leaf)
{
	if (leaf != NULL)
	{
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}

int bTREE::dataInserted()
{
	return leaves(head);
}

long bTREE::leaves(const treeNode *subtree)
{
	
	if (subtree == NULL)
	{
		return 0;
	}
	else if (subtree->left == NULL && subtree->right == NULL)
	{
		
		return 1;

	}
	else
	{
		return leaves(subtree->left) + leaves(subtree->right);
	}
}



long bTREE::size(const treeNode *subtree)
{
	if (subtree == NULL)
		return 0;
	else
		return(size(subtree->left) + 1 + size(subtree->right));

}


int bTREE::numberOfNodes()
{
	return size(head);
}



bool bTREE::hasBothChild(treeNode *root)
{
	return (root != NULL && root->left != NULL && root->right != NULL);
}


void bTREE::insertNode(treeNode **root, string data, int time, queue< treeNode * > &q) {

	treeNode *temp = new treeNode(data, time);

	if (*root == NULL)
		*root = temp;

	else {


		treeNode *front = q.front();


		if (front->left == NULL)
			front->left = temp;

		else if (front->right == NULL)
			front->right = temp;

		if (hasBothChild(front))
			q.pop();

	}

	q.push(temp);

	

}



int bTREE::insert(string data, int time)
{
	
	

		insertNode(&head, data, time, q);

	return 1;
}


 struct bTREE::treeNode* bTREE::newNode(string data, int time)
{
	struct treeNode* temp = (struct treeNode *)malloc(sizeof(struct treeNode));
	temp->data = data;
	temp->time = time;
	temp->left = temp->right = NULL;
	return temp;
};



 void bTREE::inorder_print() {
	 inorder_print(head);
	 cout << "\n";
 }

 void bTREE::inorder_print(treeNode *leaf) {
	 if (leaf != NULL) {
		 inorder_print(leaf->left);
		 cout << leaf->data << "," <<leaf->time<<" ";
		 inorder_print(leaf->right);
	 }
 }


 void bTREE::display(std::ostream& outfile) 
 {
	 std::string prefix;
	 if (head == NULL)
	 {
		 outfile << "-" << std::endl;
	 }
	 else
	 {
		 displayLeft(outfile, head->left, "    ");
		 outfile << "---" << head->data << std::endl;
		 displayRight(outfile, head->right, "    ");
	 }
 }


 void bTREE::displayLeft(std::ostream & outfile, treeNode * subtree, std::string prefix)
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

 void bTREE::displayRight(std::ostream & outfile, treeNode * subtree, std::string prefix)
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







 
int bTREE::find(string node)
{
	head->searchCount = 0;

	if (isFound(head, node))
	{
		
		findNode(head, node);
		return head->searchCount;
	}
	else
	{
		return -1;
	}

	
}

int bTREE::findNode(struct treeNode* root, string data)
{
	// Base Case
	if (root == NULL)
		return -1;

	q1.push(root);


	while (q1.empty() == false)
	{
		cout << endl << head->searchCount << endl;
		// See if current node is same as x
		treeNode *node = q.front();
		if (node->data == data)
		{
			incCount();
			return node->searchCount;
		}
		// Remove current node and enqueue its children
		q.pop();
		if (node->left != NULL)
		{
			incCount();
			q.push(node->left);
		}
		if (node->right != NULL)
		{
			incCount();
			q.push(node->right);
		}
		incCount();
	}

	return head->searchCount;

}

bool bTREE::isFound(struct treeNode* root, string x)
{
	if (root == NULL)
		return false;


	q2.push(root);

	while (q2.empty() == false)
	{
		treeNode *node = q2.front();
		if (node->data == x)
			return true;

		q2.pop();
		if (node->left != NULL)
			q2.push(node->left);
		if (node->right != NULL)
			q2.push(node->right);
	}

	return false;
}


/*
string bTREE::locate(string node)
{
}

 bool operator ==(const bTREE& lhs, const bTREE& rhs)
{
}

bool operator !=(const bTREE& lhs, const bTREE& rhs)
{

}

 std::ostream& operator <<(std::ostream& out, const bTREE& p)
{
}
*/