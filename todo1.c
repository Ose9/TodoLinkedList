#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Todo todo;

struct Todo{
	char task[100];
	todo* link;
	int cnt;
};

todo *afirst =NULL; 
todo *dfirst = NULL;
todo *alast =NULL; 
todo *dlast = NULL;

void add();
void see();
void delete();
void fixcount(int);
void done();
void stats();
void memdlt();
todo* check(int);



int main()
{
	int n;
	while(1)
	{
		
		printf("\nType numbers for respective functions:\n");
		printf("1.Add tasks to list\n");
		printf("2.See the todo list\n");
		printf("3.Task is done\n");
		printf("4.Delete the task\n");	
		printf("5.Statistics\n");
		printf("6.Delete the memory used.\n");
		printf("7.Exit\n");
		printf(">>");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				add();
				break;
			case 2:
				see();
				break;
			case 3:
				done();
				break;
			case 4:
				delete();
				break;
			case 5:
				stats();
				break;
			case 6:
				memdlt(afirst);
				memdlt(dfirst);
				break;
			case 7:
				exit(0);
			default:
				printf("Error: Enter the number from the menu.\n");
		}//switch
	}//while
	printf("Thank you");
}//main

void add()
{
	
	char choice;
	todo *t, *temp;
	while(1)
	{
	printf("\nWant to add tasks? y/n\n>>");
	scanf(" %c",&choice);
	if(choice=='n')
	{break;}
	else
	{
		if(afirst==NULL)
		{
			t=(todo*)malloc(sizeof(todo));
			afirst=t;
			printf("Add task:\n>>");
			fflush(stdin);
			gets(t->task);
			t->cnt=1;
			afirst->link=alast;
			printf("\nTask added.\n");
		}
		else
		{
			temp=(todo*)malloc(sizeof(todo));
			printf("Add task:\n>>");
			fflush(stdin);
			gets(temp->task);
			temp->link=alast;
			t->link=temp;
			t=t->link;
			printf("\nTask added.\n");
		}
		fixcount(1);
	}//end of outer else
	}//end of while
system("pause");

}//end of add

void fixcount(int j)
{
	todo *temp;
	int i=1;
	switch(j)
	{
		case 1:
			{
				temp=afirst;
				while(temp!=alast)
				{
				temp->cnt=i;
				i++;
				temp=temp->link;
				}
				break;
			}
	
		case 2:
			{
				temp=dfirst;
				while(temp!=dlast)
				{
				temp->cnt=i;
				i++;
				temp=temp->link;
				}
				break;
			}
		default:
		return;
	}
}
void delete()
{
	
	todo *temp, *temp1;
	int i;
	printf("\nEnter the number of task, you want to delete :\n>>");
	scanf("%d",&i);
	temp1=afirst;
	temp=afirst->link;
	while(1)
	{
		if(temp1->cnt==i)
		{
			afirst=afirst->link;
			free(temp1);
			fixcount(1);
			printf("\nTask deleted.\n");
			break;
		}
		else if(temp->cnt==i)
		{
			temp1->link=temp->link;
			free(temp);
			fixcount(1);
			printf("\nTask deleted.\n");
			break;
		}
		else 
		{
			temp1=temp;
			temp=temp->link;
		}
		
	}
system("pause");

}

void see()
{
	todo *temp=afirst;
	if(afirst==NULL)
	{
		printf("\nYou have added no tasks yet.\n");
	}
	else
	{
	printf("\nYour tasks are :\n");
	while(temp!=alast)
	{
		printf("%d : ",temp->cnt);
		fflush(stdin);
		puts(temp->task);
		temp=temp->link;
	}
	}
	system("pause");
}

/*void done()
{
	todo *done,*temp,*temp1,*t;
	
	int i;
	printf("\nEnter the number of task, you want to mark as done :\n>>");
	scanf("%d",&i);	
	done=malloc(sizeof(todo));
	done->link=dfirst;
	temp1=astart;
	temp=astart->link;
	while(1)
	{
	if(afirst==NULL)
	{
		printf("\nYou have added no tasks yet.\n");
		break;
	}
	else if(temp1->cnt==i)
	{
		
		done->cnt=temp1->cnt;
		strcpy(done->task,temp1->task);
		printf("\nTask marked as done.\n");
		free(temp1);
		num++;
		fixcount();
		break;
	}
	else if(temp->cnt==i)
	{
		temp1->link=temp->link;
		done->cnt=temp->cnt;
		strcpy(done->task,temp->task);
		done->link=temp->link;
		printf("\nTask marked as done.\n");
		free(temp);
		num++;
		fixcount();
		break;
	}
	else 
	{
		temp1=temp;
		temp=temp->link;
		
	}
}
system("pause");

}*/

void stats()
{
	int j=0,i=0;
	todo *temp,*temp1;
    if(dfirst==NULL)
	{
		printf("\nDone list is empty\n");
	}
	else
	{
	temp=dfirst;
	while(temp!=dlast)
	{
		i++;
		printf("%d : ",temp->cnt);
		puts(temp->task);
		printf("\n");
		temp=temp->link;
	}
	printf("Completed : %d\n",i);
	}
	

	if(afirst==NULL)
	{
		printf("\nPending list is empty\n");
	}
	else
	{
	temp1=afirst;
	while(temp1!=alast)
	{
		j++;
		printf("%d : ",temp1->cnt);
		puts(temp1->task);
		printf("\n");
		temp1=temp1->link;
	}
	printf("  Pending : %d\n",j);
	}

system("pause");

}

void done()
{
	char choice;
	int i;
	todo *t,*temp;
	while(1)
	{	
	printf("Wanna mark tasks to done?(y/n) \n>>");
	scanf(" %c",&choice);
	if(choice=='n')
	{break;}
	else 
	{
		if(dfirst==NULL)
		{
			t=(todo*)malloc(sizeof(todo));
			dfirst=t;
			printf("Enter the number of task you want to mark as done :\n>>");
			scanf("%d",&i);
			if(check(i)!=NULL)
			{
				t->cnt=check(i)->cnt;
				strcpy(t->task,check(i)->task);
				free(check(i));
				dfirst->link=dlast;			
			    printf("\nTask marked as done.\n");
			}
		
		}
	else
		{
			temp=(todo*)malloc(sizeof(todo));
			printf("Enter the number of task you want to mark as done :\n>>");
			scanf("%d",&i);
			if(check(i)!=NULL)
			{
				temp->cnt=check(i)->cnt;
				strcpy(temp->task,check(i)->task);
				free(check(i));
				temp->link=dlast;
			    t->link=temp;
			    t=t->link;
				printf("\nTask marked as done.\n");
			}
			
		}
		fixcount(2);
	}
	system("pause");	
	}//end of while
}

todo* check(int i)
{
	todo *temp=afirst;
	
	while(temp!=alast)
	{
		if(temp->cnt==i)
		{
		return temp;
		}
		temp=temp->link;
	}
	printf("NOT FOUND");
	return NULL;
	
}

void memdlt()
{
	
	todo *temp,*dtemp,*atemp;
	
	if(afirst!=NULL)
	{
	while(afirst!=NULL)
	{
		atemp=afirst;
		afirst=afirst->link;
		printf("\nDeleting %d.\n",atemp->cnt);
		free(atemp);
	}
	}
		
	if(dfirst!=NULL)
	{
	while(dfirst!=NULL)
	{
		dtemp=dfirst;
		dfirst=dfirst->link;
		printf("\nDeleting %d.\n",dtemp->cnt);
		free(dtemp);
	}
	}
	return;
}