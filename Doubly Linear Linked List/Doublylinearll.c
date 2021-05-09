#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;           //+
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head,int No)
{
	PNODE newn=NULL;
	newn =(PNODE)malloc(sizeof(NODE));
	newn->data=No;
	newn->next=NULL;
	newn->prev=NULL; //+
	
	if(NULL == *Head)
	{
		*Head = newn;
	}	
	else					//Linked list contains atleast one node
	{
		newn->next=*Head;
		(*Head)->prev=newn;
		*Head= newn;			//+
	}
}

void InsertLast(PPNODE Head,int No)
{
	PNODE newn=NULL;
	PNODE temp= *Head;
	newn =(PNODE)malloc(sizeof(NODE));
	newn->data=No;
	newn->next=NULL;
	newn->prev=NULL; //+
	
	if(*Head == NULL)     	//Linked list is empty
	{
		*Head=newn;
	}	
	else					//Linked list contains atleast one node
	{
		while(temp->next != NULL)
		{
			temp=temp->next;
			
		}
		temp->next=newn;
		newn->prev=temp;
	}
}

void display(PNODE Head)
{
	printf("NULL<=>");
	while(Head !=NULL)
	{
		printf("|%d|<=>",Head->data);
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
	if(*Head== NULL)				//Empty LL
	{
		return;
	}
	else if((*Head)->next==NULL)		//Single node
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		*Head=(*Head)->next;
		free((*Head)->prev);			//+
		(*Head)->prev=NULL;			//+
	}

}

void DeleteLast(PPNODE Head)
{
	PNODE Temp= *Head;
	if(*Head== NULL)				//Empty LL
	{
		return;
	}
	else if((*Head)->next==NULL)		//Single node
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
		Temp->next = NULL;
	}

}

void InsertAtPos(PPNODE Head,int no, int pos)
{
	int iSize=0;
	PNODE newn=NULL;
	PNODE temp=*Head;
	iSize=count(*Head);
	if((pos<1)||(pos>iSize+1))
	{
		return;
	}
	if(pos==1)
	{
		InsertFirst(Head,no);
	}
	else if(pos==iSize+1)
	{
		InsertLast(Head,no);
	}
	else
	{
		newn=(PNODE)malloc(sizeof(NODE));
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
	}
}

int main()
{
	PNODE First = NULL;
	int iOption = 1,ivalue=0,pos=0;
	int iret=0;
	while(iOption !=0)
	{
		printf("\n*************************************\n");
		printf("\n-------------------------------------\n");
		
		printf("Please select the option\n");
		printf("1:Insert the node at first position.\n");
		printf("2:Insert the node at last position.\n");
		printf("3:Insert the node at given position.\n");
		printf("4:Delete First node\n");
		printf("5:Delete Last node\n");
		printf("6:Delete node at given position.\n");
		printf("7:Display the contents of linked list.\n");
		printf("8:Count the nodes of Doubly Linear linked list\n");
		printf("0:Exit the application\n");
		scanf("%d",&iOption);
		printf("***************************************\n");
		switch(iOption)
		{
			case 1:
				printf("Enter data to insert.\n");
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
				scanf("%d",&pos);
				InsertAtPos(&First,ivalue,pos);
				break;
				
			case 4:
				DeleteFirst(&First);
				break;
				
			case 5:
				DeleteLast(&First);
				break;
				
			case 6:
				break;
				
			case 7:
				printf("Nodes of linked list are:\n");
				display(First);
				break;
				
			case 8:
				iret=count(First);
				printf("Number of nodes are: %d\n",iret);
				break;
				
			case 0:
				printf("Thank you for using linked list application\n");
				break;
				
			default:
				printf("Please enter valid option\n");
				break;
		}//switch
	}//while
	
}//main
