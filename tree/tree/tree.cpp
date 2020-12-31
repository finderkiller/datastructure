#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct treeNode{
	int data;
	struct treeNode *leftPtr;
	struct treeNode *rightPtr;
};

typedef treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode(TreeNodePtr *treePtr, int value);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main()
{
	int item;
	TreeNodePtr rootPtr = NULL;

	srand(time(NULL));
	cout<<"The numbers being placed in the tree are:\n";

	for(int i=0; i<10; i++)
	{
		item = rand() % 15;
		cout<<item<<" ";
		insertNode(&rootPtr,item);
	}

	cout<<"\n\nThe preOrder traversal is:\n";
	preOrder(rootPtr);

	cout<<"\n\nThe inOrder traversal is:\n";
	inOrder(rootPtr);

	cout<<"\n\nThe postOrder traversal is:\n";
	postOrder(rootPtr);
	return 0;
}

void insertNode(TreeNodePtr *treePtr, int value)
{
	if(*treePtr == NULL)
	{
		*treePtr = new TreeNode;
		if(*treePtr != NULL)
		{
			(*treePtr)->data=value;
			(*treePtr)->leftPtr=NULL;
			(*treePtr)->rightPtr=NULL;
		}
		else
		{
			cout<<value<<" not inserted. No memory available.\n";
		}
	}
	else
	{
		if(value<(*treePtr)->data)
			insertNode(&((*treePtr)->leftPtr), value);
		else if (value>(*treePtr)->data)
			insertNode(&((*treePtr)->rightPtr), value);
		else
			cout<<"dup ";
	}
}

void inOrder(TreeNodePtr treePtr)
{
	if(treePtr!=NULL)
	{
		inOrder(treePtr->leftPtr);
		cout<<treePtr->data<<" ";
		inOrder(treePtr->rightPtr);
	}
}

void preOrder(TreeNodePtr treePtr)
{
	if(treePtr !=NULL)
	{
		cout<<treePtr->data<<" ";
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

void postOrder(TreeNodePtr treePtr)
{
	if(treePtr != NULL)
	{
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		cout<<treePtr->data<<" ";
	}
}