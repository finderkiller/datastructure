#include<iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;

struct listNode
{
	int data;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

void insert(ListNodePtr *sPtr, int value);
void instruction (void);
int deleteItem(ListNodePtr *sPtr, int value);
void printList(ListNodePtr currentPtr);
bool isEmpty(ListNodePtr currentPtr);
void merge(ListNodePtr *sPtr,ListNodePtr currentPtr);
void randInsert(ListNodePtr *sPtr);
int sumItem(ListNodePtr currentPtr);
float averageItem(ListNodePtr currentPtr);


int main ()
{
	ListNodePtr startPtr = NULL;
	ListNodePtr startPtr2 = NULL;
	int choice;
	int item;

	instruction();
	cout<<"?";
	cin>>choice;

	while(choice!=7)
	{
		switch (choice)
		{
			case 1:
				cout<<"Enter a integer: ";
				cin>>item;
				insert(&startPtr, item);
				printList(startPtr);
				break;
			case 2:
				if (!isEmpty(startPtr))
				{
					cout<<"Enter integer to be deleted: ";
					cin>> item;

					if(deleteItem(&startPtr, item))
					{
						cout<<item<<" deleted.\n";
						printList(startPtr);
					}
					else{
						cout<<item<<" not found.\n";
					}
				}
				else{
					cout<<"List is empty.\n\n";
				}
				break;
			case 3:
				cout<<"Enter a integer: ";
				cin>>item;
				insert(&startPtr2, item);
				printList(startPtr2);
				break;
			case 4:
				if (!isEmpty(startPtr2))
				{
					cout<<"Enter integer to be deleted: ";
					cin>> item;

					if(deleteItem(&startPtr2, item))
					{
						cout<<item<<" deleted.\n";
						printList(startPtr2);
					}
					else{
						cout<<item<<" not found.\n";
					}
				}
				else{
					cout<<"List is empty.\n\n";
				}
				break;
			case 5:
				merge(&startPtr, startPtr2);
				printList(startPtr);
				break;
			case 6:
				randInsert(&startPtr);
				printList(startPtr);
				cout<<"The sum is "<<sumItem(startPtr)<<"\n";
				cout<<"The average is "<<averageItem(startPtr)<<"\n";
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
		"  1 to insert an element into the first list.\n"
		"  2 to delete an element from the first list.\n"
		"  3 to insert an element into the second list.\n"
		"  4 to delete an element from the second list.\n"
		"  5 to merge the two list.\n"
		"  6 to random the item into the list.\n"
		"  7 to end.\n";
}

void insert(ListNodePtr *sPtr, int value)
{
	ListNodePtr newPtr;
	ListNodePtr currentPtr;
	ListNodePtr previousPtr;

	newPtr= new ListNode;

	if(newPtr!=NULL)
	{
		newPtr->data=value;
		newPtr->nextPtr=NULL;

		previousPtr=NULL;
		currentPtr=*sPtr;
		
		while(currentPtr!=NULL && value>currentPtr->data)
		{
			previousPtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}

		if(previousPtr==NULL)
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else
		{
			newPtr->nextPtr=currentPtr;
			previousPtr->nextPtr=newPtr;

		}
	}
	else
		cout<<value<<" is not inserted.\n";
}

int deleteItem(ListNodePtr *sPtr, int value)
{
	ListNodePtr tempPtr;
	ListNodePtr currentPtr;
	ListNodePtr previousPtr;
	
	if (*sPtr!=NULL)
	{
		if(value==(*sPtr)->data)
		{
			tempPtr=*sPtr;
			*sPtr=(*sPtr)->nextPtr;
			delete tempPtr;
			return value;
		}
		else
		{
			previousPtr=*sPtr;
			currentPtr=(*sPtr)->nextPtr;
			while (currentPtr!=NULL && currentPtr->data!=value)
			{
				previousPtr=previousPtr->nextPtr;
				currentPtr=currentPtr->nextPtr;
			}
			if (currentPtr!=NULL)
			{
				tempPtr=currentPtr;
				previousPtr->nextPtr=currentPtr->nextPtr;
				delete tempPtr;
				return value;
			}
		}		
	}
	return '/0';
}

void printList(ListNodePtr currentPtr)
{
	while (currentPtr!=NULL)
	{
		cout<< currentPtr->data<<"-->";
		currentPtr=currentPtr->nextPtr;
	}
	cout<<"NULL\n\n";
}

bool isEmpty(ListNodePtr currentPtr)
{
	return currentPtr==NULL;
}

void merge(ListNodePtr *sPtr,ListNodePtr currentPtr)
{
	int value;
	while(currentPtr!=NULL)
	{
		value = currentPtr->data;
		currentPtr=currentPtr->nextPtr;
		insert(sPtr,value);
	}
}

void randInsert(ListNodePtr *sPtr)
{
	srand(time(NULL));
	int value=0;
	for(int i=0;i<25;i++)
	{
		value = (rand()%100)+1;
		insert(sPtr,value);
	}
}

int sumItem(ListNodePtr currentPtr)
{
	int sum=0;
	while(currentPtr!=NULL)
	{
		sum+=currentPtr->data;
		currentPtr=currentPtr->nextPtr;
	}
	return sum;
}

float averageItem(ListNodePtr currentPtr)
{
	float average=0;
	while(currentPtr!=NULL)
	{
		average+=currentPtr->data;
		currentPtr=currentPtr->nextPtr;
	}
	average=average/25;
	return average;
}