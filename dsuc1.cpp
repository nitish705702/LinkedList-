/*
        Code for Data inserting,deleting,updating 
        and many type manipulation using Linklist
    
	    Name : Nitish Kumar Arya
        
		B.tech :
	            at Madan Mohan Malaviya University of Technology ,Gorakhpur
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node
{
	int info;
	struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);
int main()
{
	struct node *start=NULL;
	int choice,data,item,pos;
	while(1)
	{
		printf("1. Create \n");
		printf("2. Display \n");
		printf("3. Count \n");
		printf("4. Search \n");
		printf("5. Add to empty List /Add at beginning \n");
		printf("6. Add at the end\n");
		printf("7. Add after the node\n");
		printf("8. Add before the node \n");
		printf("9. Add at the position \n");
		printf("10. Reverse\n");
		printf("11. Delete \n");
		printf("12. Quite\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				start=create_list(start);
				break;
			case 2:
				display(start);
				break;
			case 3:
				count(start);
				break;
			case 4:
				printf("Enter the element to be searched \n");
				scanf("%d",&data);
				search(start,data);
				break;
			case 5:
				printf("Enter the element to be inserted \n");
				scanf("%d",&data);
				start=addatbeg(start,data);
				break;
			case 6:
				printf("Enter the element to be inserted \n");
				scanf("%d",&data);
				start=addatend(start,data);
				break;
			case 7:
				printf("Enter the element to be inserted \n");
				scanf("%d",&data);
				printf("Enter element which after to be inserted \n");
				scanf("%d",&item);
				start=addafter(start,data,item);
				break;
			case 8:
				printf("Enter the element to be inserted \n");
				scanf("%d",&data);
				printf("Enter element which before to be inserted \n");
				scanf("%d",&item);
				start=addbefore(start,data,item);
				break;
			case 9:
				printf("Enter the element to be inserted \n");
				scanf("%d",&data);
				printf("Enter element which pos to be inserted  \n");
				scanf("%d",&pos);
				start=addatpos(start,data,pos);
				break;
			case 10:
				printf("Enter the element to be deleted \n");
				scanf("%d",&data);
				start=del(start,data);
				break;
			case 11:
				start=reverse(start);
				break;
			case 12:
				exit(1);
			default:
				printf("Wrong choice \n");
	    }
	}
	return 0;
}
void display(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is an empty \n");
		return;	
	}
	p=start;
	printf(" List is an : \n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
}
void count(struct node *start)
{
	struct node *p;
	int cnt=0;
	p=start;
	while(p!=NULL)
	{
		p=p->link;
		cnt++;
	}
	printf("Number of element are : %d",cnt);
	
}
void search(struct node *start,int item)
{
	struct node *p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			printf("Item %d`are present at the pos %d \n",item,pos);
			return ;
		}
		p=p->link;
		pos++;
	}
}
struct node *addatbeg(struct node *start,int data)
{
	struct node *temp=NULL;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=start;
	start=temp;
	return start;
}
struct node *addatend(struct node *start,int data)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p->link!=NULL)
	{
		p=p->link;
	}
	p->link=temp;
	temp->link=NULL;
	return start;
}
struct node *addafter(struct node *start,int data,int item)
{
	struct node *temp,*p;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=data;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
}
struct node *addbefore(struct node *start,int data,int item)
{
	struct node *temp,*p;
	if(start==NULL)
	{
		printf("List is an Empty \n");
		return start;
	}
	if(start->info==item)
	{
		temp=(struct node *)malloc(sizeof(struct node));
	    temp->info=data;
		temp->link=start;
		start=temp;
		return start;
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==item)
		{
			temp=(struct node *)malloc(sizeof(struct node));
	        temp->info=data;
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	return start;
}
struct node *addatpos(struct node *start,int data,int pos)
{
	struct node *temp,*p;
	if(pos==1)
	{
		temp=(struct node *)malloc(sizeof(struct node));
	    temp->info=data;
	    temp->link=start;
	    start=temp;
	    return start;
	}
	p=start;
	for(int i=1;i<pos-1&&p!=NULL;i++)
	{
		p=p->link;
	}
	if(p==NULL)
	{
		printf("Invalid Position \n");
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
	    temp->info=data;
	    temp->link=p->link;
	    p->link=temp;
	}
	return start;
}
struct node *create_list(struct node *start)
{
	int data,n;
	printf("Enter the number of element in a list \n");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
	{
		return start;
	}
	printf("Enter the data of list \n");
	scanf("%d",&data);
	start=addatbeg(start,data);
	for(int i=2;i<=n;i++);
	{
		printf("Enter the data of list \n");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	return start;
}
struct node *del(struct node *start,int data)
{
	struct node *p,*temp;
	if(start->info==data)
	{
		temp=start;
		start=start->link;
		free(temp);
		return start;
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data)
		{
			temp=p->link;
			p->link=temp->link;
			free(temp);
			return start;
		}
		p=p->link;
	}
	return start;
}
struct node *reverse(struct node *start)
{
    struct node *p,*prev,*next;
    start=p;
    prev=NULL;
    while(p!=NULL)
    {
        next=p->link;
        p->link=prev;
        prev=p;
        p=next;
    }
    start=prev;
    return start;
}








