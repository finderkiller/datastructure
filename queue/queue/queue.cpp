#include<iostream>
#include<stdlib.h>
using namespace std;

struct queueNode{
	char data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void instruction (void);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value);
char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
bool isEmpty(QueueNodePtr headPtr);
void printQueue(QueueNodePtr currentPtr);



int main ()
{
	QueueNodePtr headPtr = NULL;
	QueueNodePtr tailPtr = NULL;
	int choice;
	char item;

	instruction();
	cout<<"?";
	cin>>choice;

	while(choice!=3){
		switch (choice){
			case 1:
				cout<<"Enter a character: ";
				cin>>item;
				enqueue( &headPtr, &tailPtr,item );
				printQueue( headPtr );
				break;
			case 2:
				if (!isEmpty(headPtr)){
					item = dequeue(&headPtr, &tailPtr);
					cout<<item<<" deleted.\n";
					printQueue(headPtr);
				}
				else{
					cout<<"Queue is empty.\n\n";
				}
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
		"  1 to insert an element into the queue.\n"
		"  2 to delete an element from the queue.\n"
		"  3 to end.\n";
}


void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, char value)
{
	QueueNodePtr newPtr;

	newPtr = new QueueNode;

	if(newPtr!=NULL)
	{
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		if(isEmpty(*headPtr))			//push first item
		{
			*headPtr = newPtr;
		}
		else
		{
			(*tailPtr)-> nextPtr= newPtr;
		}
		*tailPtr = newPtr;				
	}
	else
		cout<<value<<" not inserted. No memory available.\n";
}

char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
	QueueNodePtr tempPtr;
	char value;

	value = (*headPtr)->data;
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;
	
	if(*headPtr==NULL)
		*tailPtr=NULL;

	delete tempPtr;
	return value;
}

bool isEmpty(QueueNodePtr headPtr)
{
	return headPtr==NULL;
}

void printQueue(QueueNodePtr currentPtr)
{
	if(currentPtr==NULL)
		cout<<"Queue is empty.\n\n";
	else
	{
		cout<<"The queue is: \n";
		while(currentPtr!=NULL)
		{
			cout<<currentPtr->data<<" -->";
			currentPtr=currentPtr->nextPtr;
		}

		cout<<"NULL\n\n";
	}

}