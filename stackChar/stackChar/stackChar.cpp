#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct stackNode{
	char data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *sPtr, char item);
char pop(StackNodePtr *sPtr);
void printStack(StackNodePtr currentPtr);
bool isEmpty(StackNodePtr currentPtr);
void instruction (void);
void reverse(StackNodePtr *sPtr);
void isPalindrome(string &s, StackNodePtr *currentPtr);


int main()
{
	StackNodePtr stackPtr=NULL;
	int choice;
	char value;
	string s;

	instruction();
	cout<<"?";
	cin>>choice;
	

	while(choice!=5)
	{
		switch(choice)
		{
		case 1:
			cout<<"Enter an char: ";
			cin>>value;
			push(&stackPtr, value);
			printStack( stackPtr );
			break;
		case 2:
			if(!isEmpty(stackPtr))
				cout<<"The popped value is "<< pop(&stackPtr);
			printStack( stackPtr );
			break;
		case 3:
			if(!isEmpty(stackPtr))
				reverse(&stackPtr);
			break;
		case 4:
			cout<<"Enter an string: ";
			cin>>s;
			for (int i=0; i< s.size(); i++)
			{
				push(&stackPtr,s[i]);
			}
			printStack(stackPtr);
			isPalindrome(s, &stackPtr);
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
		"  3 to reverse the stack.\n"
		"  4 to palindrome tester.\n"
		"  5 to end.\n";
}

void push(StackNodePtr *sPtr, char item)
{
	StackNodePtr newPtr;

	newPtr = new StackNode;
	newPtr->data=item;
	newPtr->nextPtr=*sPtr;
	*sPtr=newPtr;
}

char pop(StackNodePtr *sPtr)
{
	StackNodePtr tempPtr;
	char item;

	if(*sPtr!=NULL)
	{
		tempPtr=*sPtr;
		*sPtr=(*sPtr)->nextPtr;
		item=tempPtr->data;
		delete tempPtr;
		return item;
	}
	else
		return '\0';
}

void printStack(StackNodePtr currentPtr)
{
	while(currentPtr!=NULL)
	{
		cout<<currentPtr->data<<"-->";
		currentPtr=currentPtr->nextPtr;
	}
	cout<<"NULL\n\n";
}

bool isEmpty(StackNodePtr currentPtr)
{
	return currentPtr==NULL;
}

void reverse(StackNodePtr *sPtr)
{
	while(*sPtr!=NULL)
	{
		cout<<pop(sPtr)<<" ";
	}
	cout<<".\n";
}

void isPalindrome(string &s, StackNodePtr *currentPtr)
{
	int i=0;
	for (i=0; i< s.size(); i++)
	{
		if(s[i]!=pop(currentPtr))
			break;
	}
	if(i==s.size())
		cout<<"Palindrome\n\n";
	else
		cout<<"No Palindrome\n\n";
}