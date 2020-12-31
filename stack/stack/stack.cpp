#include<iostream>
#include<stdlib.h>

using namespace std;

struct stackNode{
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;			//StackNodePtr 是一個指標型態 指向StackNode

void instruction (void);
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
void printStack(StackNodePtr currentPtr);
bool isEmpty(StackNodePtr topPtr);

int main()
{
	StackNodePtr stackPtr=NULL;
	int choice;
	int value;

	instruction();
	cout<<"?";
	cin>>choice;

	while(choice!=3)
	{
		switch(choice)
		{
		case 1:
			cout<<"Enter an integer: ";
			cin>>value;
			push(&stackPtr, value);
			printStack( stackPtr );
			break;
		case 2:
			if(!isEmpty(stackPtr))
				cout<<"The popped value is "<< pop(&stackPtr);
				printStack( stackPtr );
				break;
		default:
			cout<<"Invalid choice.\n\n";
			instruction();
			break;
		}
		cout<<"?";
		cin>>choice;
	}
	cout<<"End of run.\n";
	return 0;
}

void instruction (void)
{
	cout<<"Enter your choice:\n"
		"  1 to push an element into the stack.\n"
		"  2 to pop an element from the stack.\n"
		"  3 to end.\n";
}

void push(StackNodePtr *topPtr, int info)			//topPtr是指向pointer的pointer, call by pointer
{
	StackNodePtr newPtr;

	newPtr = new StackNode;

	if(newPtr!=NULL)
	{
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}

	else
		cout<<info<<" not inserted. No memory available.\n";
}

int pop(StackNodePtr *topPtr)
{
	StackNodePtr tempPtr;
	int popValue;

	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	delete tempPtr;
	return popValue;
}

void printStack(StackNodePtr currentPtr)			//call by value
{
	if(currentPtr==NULL)
		cout<<"The stack is empty.\n\n";
	else
	{
		cout<<"The stack is :\n";
		while(currentPtr!=NULL)
		{
			cout<<currentPtr->data<<" --> ";
			currentPtr=currentPtr->nextPtr;
		}
		cout<<"NULL\n\n";
	}
}

bool isEmpty(StackNodePtr topPtr)
{
	return topPtr==NULL;
}