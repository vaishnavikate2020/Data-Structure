#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head,int no)
{
	PNODE newn= NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn-> data = no;
	newn-> next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next=*Head;
		*Head = newn;
	}
}
void InsertLast(PPNODE Head,int no)
{
	PNODE newn= NULL;
	PNODE temp = *Head;
	newn = (PNODE)malloc(sizeof(NODE));
	newn-> data = no;
	newn-> next = NULL;
	
	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
}


void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("|%d|->",Head->data);
		Head=Head->next;
	}
	printf("NULL\n");
}

int count(PNODE Head)
{
	int icnt=0;
	while(Head !=NULL)
	{
		icnt++;
		Head=Head->next;
	}
	return icnt;
}
void DeleteFirst(PPNODE Head)
{
	PNODE Temp= *Head;
	if(*Head== NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		*Head=(*Head)->next;
		free(Temp);
	}
}
void DeleteLast(PPNODE Head)
{
	PNODE Temp= *Head;
	if(*Head== NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		while(Temp->next->next !=NULL)
		{
			Temp=Temp->next;
		}
		free(Temp->next);
		Temp->next=NULL;
	}
}
void InsertAtPosition(PPNODE Head, int no,int ipos)
{
	int isize=0;
	PNODE newn=NULL;
	PNODE Temp = *Head;

	isize=count(*Head);
		if((ipos<1)||(ipos>isize+1))	//Invalid position
	{
		return;
	}
	if(ipos==1)						//First Position
	{
		InsertFirst(Head,no);
	}
	else if(ipos==isize+1)			//Last Position
	{
		InsertLast(Head,no);
	}
	else							//In between first and
	{
		newn=(PNODE)malloc(sizeof(NODE));
		newn->data=no;
		newn->next=NULL;
		for(int i=1;i<ipos-1;i++)
		{
				Temp=Temp->next;
		}	
		newn->next=Temp->next;
		Temp->next=newn;
	}
}

void DeleteAtPosition(PPNODE Head,int ipos)
{
	int isize=0;
	PNODE Temp = *Head;
	PNODE Target=NULL;
	isize=count(*Head);
		if((ipos<1)||(ipos>isize))	//Invalid position
	{
		return;
	}
	if(ipos==1)						//First Position
	{
		DeleteFirst(Head);
	}
	else if(ipos==isize)			//Last Position
	{
		DeleteLast(Head);
	}
	else							//In between first and
	{
		for(int i=1;i<ipos-1;i++)
		{
				Temp=Temp->next;
		}	
	Target= Temp->next;
	Temp->next = Target->next;
	free(Target);
	}
}


int main()
{
	PNODE First = NULL;
	int iRet=0,iOption=1,ivalue=0,ipos=0;
	while(iOption!=0)
	{
		printf("----------------------------------------------\n");
		printf("Enter your action on Linked List:\n");
		printf("1:Insert node at first position.\n");
		printf("2:Insert node at last position.\n");
		printf("3:Insert node at given position.\n");
		printf("4:Delete First node\n");
		printf("5:Delete Last node\n");
		printf("6:Delete node from given position:\n");
		printf("7:Display the contents of linked list\n");
		printf("8:Count number of nodes of linked list\n");
		printf("0:Exit the application\n");
		scanf("%d",&iOption);
		printf("------------------------------------------------\n");
		
		switch(iOption)
		{
			case 1:
				printf("Enter data to insert:\n");
				scanf("%d",&ivalue);
				InsertFirst(&First,ivalue);
				break;
				
			case 2:
				printf("Enter data to insert:\n");
				scanf("%d",&ivalue);
				InsertLast(&First,ivalue);
				break;
				
			case 3:
				printf("Enter data to insert:\n");
				scanf("%d",&ivalue);
				printf("ENter Position:\n");
				scanf("%d",&ipos);
				InsertAtPosition(&First,ivalue,ipos);
				break;
			case 4:
				DeleteFirst(&First);
				break;
				
			case 5:
				DeleteLast(&First);
				break;
				
			case 6:
				printf("ENter the position\n");
				scanf("%d",&ipos);
				DeleteAtPosition(&First,ipos);
			case 7:
				printf("Nodes of linked list are:\n");
				Display(First);
				break;
			
			case 8:
				iRet=count(First);
				printf("Number of nodes are: %d\n",iRet);
				break;
			case 0:
				printf("Thank you for using linked list application\n");
				break;
				
			default:
				printf("Please enter valid option\n");
				break;
	}//end of switch
	
	}//end of while
	return 0;
}// end of main