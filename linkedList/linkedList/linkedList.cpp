#include<iostream>
#include<stdlib.h>
using namespace std;

struct listNode{
	char data;
	struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;		//ListNodePtr is a type of pointer to type ListNode

//prototype
void insert (ListNodePtr *sPtr, char value);
char deleteItem(ListNodePtr *sPtr, char value);
bool isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void instruction (void);
void concatenate(ListNodePtr *sPtr1,ListNodePtr *sPtr2);
void reverseList(ListNodePtr *sPtr);

int main ()
{
	ListNodePtr startPtr = NULL;
	ListNodePtr startPtr2 = NULL;
	//ListNodePtr reversePtr = NULL;
	int choice;
	char item;

	instruction();
	cout<<"?";
	cin>>choice;

	while(choice!=7){
		switch (choice){
			case 1:
				cout<<"Enter a character: ";
				cin>>item;
				insert(&startPtr, item);
				printList(startPtr);
				break;
			case 2:
				if (!isEmpty(startPtr))
				{
					cout<<"Enter character to be deleted: ";
					cin>> item;

					if(deleteItem(&startPtr, item)){
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
				cout<<"Enter a character: ";
				cin>>item;
				insert(&startPtr2, item);
				printList(startPtr2);
				break;
			case 4:
				if (!isEmpty(startPtr2))
				{
					cout<<"Enter character to be deleted: ";
					cin>> item;

					if(deleteItem(&startPtr2, item)){
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
				if(!isEmpty(startPtr) && !isEmpty(startPtr2))
				{
					concatenate(&startPtr, &startPtr2);
					printList(startPtr);
				}
				break;
			case 6:
				if(!isEmpty(startPtr))
				{
					reverseList(&startPtr);
					printList(startPtr);
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
		"  1 to insert an element into the first list.\n"
		"  2 to delete an element from the first list.\n"
		"  3 to insert an element into the second list.\n"
		"  4 to delete an element from the second list.\n"
		"  5 to concatenate two list.\n"
		"  6 to reverse list.\n"
		"  7 to end.\n";
}

void insert(ListNodePtr *sPtr, char value)
{
	ListNodePtr newPtr;				//pointer to new node
	ListNodePtr previousPtr;		//pointer to previous node in list
	ListNodePtr currentPtr;			//pointer to current node in list

	newPtr = new ListNode;

	if(newPtr != NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		previousPtr = NULL;
		currentPtr = *sPtr;

		while(currentPtr!=NULL && value>currentPtr->data){		//find the correct location in the list
			previousPtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}
		
		if (previousPtr==NULL){			//insert new node at beginning of list, 不管是不是第一個放的
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}

		else{							//insert new node between previousPtr and currentPtr
			previousPtr->nextPtr= newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else{
		cout<<value<<" not inserted. No memory available.\n";
	}
}

char deleteItem(ListNodePtr *sPtr, char value)
{
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr;

	if(value == (*sPtr)->data){
		tempPtr = *sPtr;
		*sPtr = (*sPtr)->nextPtr;
		free(tempPtr);
		return value;
	}
	else{
		previousPtr =*sPtr;
		currentPtr = (*sPtr)->nextPtr;								//由currentPtr控制現在要刪除甚麼

		while(currentPtr!=NULL && currentPtr->data != value){		//find the coorect location in the list
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if(currentPtr!=NULL){
			tempPtr=currentPtr;
			previousPtr->nextPtr=currentPtr->nextPtr;
			free( tempPtr );
			return value;
		}
	}
	return '\0';
}

bool isEmpty(ListNodePtr sPtr)			//return 1 if list is empty
{			
	return sPtr == NULL;
}

void printList(ListNodePtr currentPtr)
{
	if (currentPtr == NULL){
		cout<<"List is empty.\n\n";
	}
	else{
		cout<<"The list is:\n";
		while(currentPtr !=NULL){
		cout<< currentPtr->data << "-->";
		currentPtr=currentPtr->nextPtr;
	}
	//cout<<"NULL\n\n";
	}
}

void concatenate(ListNodePtr *sPtr1,ListNodePtr *sPtr2)
{
	ListNodePtr currentPtr;
	if(*sPtr1!=NULL)
	{
		currentPtr = *sPtr1;
		while (currentPtr->nextPtr!=NULL)
		{
			currentPtr=currentPtr->nextPtr;
		}
		currentPtr->nextPtr=*sPtr2;
	}
	
}

void reverseList(ListNodePtr *sPtr)
{
	ListNodePtr Ptr1;
	ListNodePtr Ptr2;
	ListNodePtr Ptr3;
	
	Ptr1=*sPtr;
	Ptr2=NULL;
	Ptr3=NULL;
	while (Ptr1!=NULL)
	{
		Ptr2=Ptr1->nextPtr;
		Ptr1->nextPtr=Ptr3;
		if(Ptr2==NULL)
		{
			*sPtr=Ptr1;
			break;
		}
		Ptr3=Ptr2->nextPtr;
		Ptr2->nextPtr=Ptr1;
		if(Ptr3==NULL)
		{
			*sPtr=Ptr2;
			break;
		}
		Ptr1=Ptr3->nextPtr;
		Ptr3->nextPtr=Ptr2;
		*sPtr=Ptr3;
	}
}
