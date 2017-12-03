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

}

void bTREE::incInsertCount()
{
	head->insertCount = (head->insertCount) + 1;
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
	{
		*root = temp;
	}

	else {


		treeNode *front = q.front();


		if (front->left == NULL)
		{
			incInsertCount();
			front->left = temp;
		}

		else if (front->right == NULL)
		{
			incInsertCount();
			front->right = temp;
		}

		if (hasBothChild(front))
		{
			incInsertCount();
			q.pop();
		}
	}

	q.push(temp);

	

}



int bTREE::insert(string data, int time)
{
		insertNode(&head, data, time, q);

	return head->insertCount;
}


void bTREE::printPostorderB()
{
	printPostorderB(head);
}


void bTREE::printPostorderB(treeNode* node)
{

	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorderB(node->left);

	// then recur on right subtree
	printPostorderB(node->right);

	// now deal with the node
	//postCount++;
	//cout << endl << "postorder" << postCount<<endl;
	if ((node->left->data) != "" && (node->right->data) != "")
	{
		node->data = "string"; 
	}
	else
	{
		return;
	}
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
		
		return head->searchCount;

	}
	else
	{
		return -1;
	}

	
}


bool bTREE::isFound(struct treeNode* root, string x)
{
	
	if (root == NULL)
	{
		return false;
	}

	q2.push(root);

	while (q2.empty() == false)
	{
		incCount();

		treeNode *node = q2.front();
		if (node->data == x)
		{
			return true;
		}

		q2.pop();
		if (node->left != NULL)
		{
			q2.push(node->left);
		}

		if (node->right != NULL)
		{ 
			q2.push(node->right);
		}
	}

	return false;
}

bool bTREE::find(int time)
{
	if (isFound(head, time))
	{		
		return true;
	}
	else
	{
		return false;
	}
}

bool bTREE::isFound(struct treeNode* root, int x)
{

	if (root == NULL)
	{
		return false;
	}

	q2.push(root);

	while (q2.empty() == false)
	{
		incCount();

		treeNode *node = q2.front();
		if (node->time == x)
		{
			return true;
		}

		q2.pop();
		if (node->left != NULL)
		{
			q2.push(node->left);
		}

		if (node->right != NULL)
		{
			q2.push(node->right);
		}
	}

	return false;
}

string bTREE::locate(string node)
{
	string parth;

	printAncestors(head, node);


	for (int i = path.size()-1; i >= 0; i--)
	{
		parth += path[i];
		//cout << path[i]<<" ";
	}
	


	return parth;
}


bool bTREE::printAncestors(treeNode *root, string target)
{
	/* base cases */
	if (root == NULL)
		return false;

	if (root->data == target)
		return true;

	/* If target is present in either left or right subtree of this node,
	then print this node */
	if (printAncestors(root->left, target))
	{
		
		//cout << "L";
		path.push_back("L");
		return true;
	}

	else if(printAncestors(root->right, target))
	{
		//cout << "R";
		path.push_back("R");
		return true;
	}

	/* Else return false */
	return false;
}


bool isSame(bTREE::treeNode* p, bTREE::treeNode* q)
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
				isSame(p->left, q->left) &&
				isSame(p->right, q->right)
				);
	}

	/* 3. one empty, one not -> false */
	return 0;

}


bool bTREE::isReallySame(treeNode* p, treeNode* q)
{
	return isSame(p, q);
}


 bool bTREE::operator ==(const bTREE& rhs)
{

	bool same = isSame(this->head, rhs.head);
	return same;

}

 
 bool bTREE::operator != (const bTREE& rhs)
{
	bool same = isSame(this->head, rhs.head);
	return !same;
}

 /*
 std::ostream& operator <<(std::ostream& out, const bTREE& p)
{
	

	

	 return display();

	 

	 
	 std::string prefix;
	 if (p.head == NULL)
	 {
		 out << "-" << std::endl;
	 }
	 else
	 {
		 p.displayLeft(out, p.head->left, "    ");
		 out << "---" <<p.head->data << std::endl;
		 p.displayRight(out, p.head->right, "    ");
	 }
	 
	 return out;
	 
}

*/


 void bTREE::print_queue(queue< treeNode* > q)
 {

	 queue<treeNode*> copy = q;

	 while (!copy.empty())
	 {
		 std::cout << copy.front()->data << endl;
		 copy.pop();
	 }
	 std::cout << std::endl;


 }