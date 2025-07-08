#include <stdio.h>
#include <stdlib.h>
#include "hlinked.h"


node* NewNode(int x){
	node* new=(node*)malloc(sizeof(node));
	new->x=x;
	new->next=NULL;
	return new;
}

node* CreateFromArray(int* A,int n){
	node* head=NewNode(A[0]);
	node* temp=head;
	for(int i=1;i<n;i++){
		temp->next=NewNode(A[i]);
		temp=temp->next;
	}
	return head;
}

void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->x);
		temp=temp->next;
	}
	printf("\n");
	return;
}

int llen(node* head){
	node* temp=head;
	int count=0;
	while(temp!=NULL){
		count++;
                temp=temp->next;
        }
	return count;
}

int sum(node* head){
	node* temp=head;
	int sum=0;
	while(temp!=NULL){
                sum+=temp->x;
                temp=temp->next;
        }
        return sum;

}

int lmax(node* head){
	int retmax=head->x;
	node* temp=head;
	while(temp!=NULL){
		retmax=(retmax>temp->x)?retmax:temp->x;
		temp=temp->next;
	}
	return retmax;
}

node* LinearSearch(node* head,int key){
	node* temp=head;
	while(temp!=NULL){
		if(key>temp->x){
			temp=temp->next;
		}
		else if(key==temp->x){
			return temp;
		}
		else{
			return NULL;

		}
	}
}

void insert(node** head,int key){
        node* new=NewNode(key);
	if ((*head)==NULL){
		*head=new;
		return;
	}
        if (key<=(*head)->x){
                new->next=*head;
                *head=new;
                return;
        }
        node* temp=*head,*prev=*head;
        while(temp!=NULL){
                if (key<=temp->x){
                        new->next=temp;
                        prev->next=new;
                        return;
                }       
                prev=temp;
                temp=temp->next;
        }
	prev->next=new;

}

void deleteNode(node** head,int key){
	if((*head)==NULL){
		printf("List is empty");
		return;
	}
	if((*head)->x==key){
		node* del=*head;
		*head=(*head)->next;
		free(del);
	}
	else{
		node* temp=*head,*prev=*head;
		while(temp!=NULL){
			if(key>temp->x){
				prev=temp;
				temp=temp->next;
			}
			else if(key==temp->x){
				prev->next=temp->next;
				free(temp);
				temp=prev->next;
			}
			else{
				return;
			}
		}
	}
}

void RemoveDuplicates(node** head){
	if((*head)==NULL){
                printf("List is empty");
                return;
        }
	node* temp=(*head)->next,*prev=*head;
	while(temp!=NULL){
		if(prev->x==temp->x){
			prev->next=temp->next;
			free(temp);
			temp=prev->next;
		}
		else{
		prev=temp;
		temp=temp->next;
	
		}

	}
}

void Reverse(node **head){
	node* prev=NULL,*cur=*head,*next;
	if((*head)==NULL){
                printf("List is empty");
                return;
        }
	else{
		next=cur->next;
	}
	while(next!=NULL){
		cur->next=prev;
		prev=cur;
		cur=next;
		next=next->next;
	}
	cur->next=prev;
	*head=cur;
}
void RecursiveReverse(node **head,node* q,node* p){
	if(p!=NULL){
		RecursiveReverse(head,p,p->next);
		p->next=q;
	}
	else{
		*head=q;
	}
}

node* Merge(node* head1,node* head2){
	node* temp1=head1,*temp2=head2;
	node* ret;
	if(temp1->x<temp2->x){
		ret=NewNode(temp1->x);
		temp1=temp1->next;
	}
	else {
		ret=NewNode(temp2->x);
		temp2=temp2->next;
	}
	node *temp=ret;
	while(temp1!=NULL&&temp2!=NULL){
		if(temp1->x>temp2->x){
			temp->next=NewNode(temp2->x);
			temp=temp->next;
			temp2=temp2->next;
		}
		else if(temp1->x<temp2->x){
			temp->next=NewNode(temp1->x);
                        temp=temp->next;
			temp1=temp1->next;
		}
		else{
			temp->next=NewNode(temp2->x);
                        temp=temp->next;
                        temp2=temp2->next;
			temp->next=NewNode(temp1->x);
                        temp=temp->next;
                        temp1=temp1->next;
		}
	}
	while(temp1!=NULL){
		temp->next=NewNode(temp1->x);
                temp=temp->next;
                temp1=temp1->next;
	}
	while(temp2!=NULL){
		temp->next=NewNode(temp2->x);
                temp=temp->next;
		temp2=temp2->next;
	}
	return ret;
}

int IsLoop(node* head){
	node* p=head,*q=head;
	while(p!=q){
		p=p->next;
		q=q->next;
		if(q==NULL) return 0;
		else q=q->next;
	}
	return 1;
}


//CIRCULAR LINKED LIST


node* CreateCircularFromArray(int* A,int n){
	node* head=NewNode(A[0]);
        node* temp=head;
        for(int i=1;i<n;i++){
                temp->next=NewNode(A[i]);
                temp=temp->next;
	}
	temp->next=head;
        return head;
}

void DisplayCircular(node* head){
        node* temp=head;
	printf("%d ",temp->x);
        temp=temp->next;
        while(temp!=head){
                printf("%d ",temp->x);
                temp=temp->next;
        }
        printf("\n");
        return;
}

void InsertInCircular(node** head,int value,int index){
	node* new=NewNode(value);
	if(index==0){
		node* p=(*head)->next;
		while(p->next!=*head){
			p=p->next;
		}
		p->next=new;
		new->next=*head;
		*head=new;
	}
	else{
		node* temp=*head;
		for(int i=0;i<index-1;i++){
			temp=temp->next;
		}
		new->next=temp->next;
		temp->next=new;
	}
}

void DeleteFromCircular(node** head,int key){
	if((*head)->x==key){
		node* p=(*head)->next;
                while(p->next!=*head){
                        p=p->next;
                }
		p->next=(*head)->next;
		free(*head);
		*head=p->next;
	}
	else{
		node* temp=(*head)->next,*prev=*head;
		while(temp!=*head){
			if(temp->x==key){
				prev->next=temp->next;
				free(temp);
				temp=prev->next;
		}
			else{
				prev=temp;
				temp=temp->next;
			}
		}
	}
}


//DOUBLE LINKED LIST

void InitialiseDouble(DoubleLinkedList* l){
	l->head=NULL;
	l->tail=NULL;
	l->len=0;
}

doublenode* CreateDoubleNode(int x){
	doublenode *new=(doublenode*)malloc(sizeof(doublenode));
	new->prev=NULL;
	new->next=NULL;
	new->x=x;
}

DoubleLinkedList* CreateDoubleFromArray(int* A,int len){
	DoubleLinkedList* ret=(DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	InitialiseDouble(ret);
	ret->head=CreateDoubleNode(A[0]);
	doublenode* temp=ret->head->next,*prev=ret->head;
	for(int i=1;i<len;i++){
		temp=CreateDoubleNode(A[i]);
		prev->next=temp;
		temp->prev=prev;
		prev=temp;
		temp=temp->next;
	}
	ret->tail=prev;
	ret->len=len;
	return ret;
}

void DisplayDouble(DoubleLinkedList* list){
	doublenode* temp=list->head;
	for(int i=0;i<list->len;i++){
		printf("%d ",temp->x);
		temp=temp->next;
	}
	printf("\n");
}

void InsertDouble(DoubleLinkedList* list,int x,int index){
	doublenode* new=CreateDoubleNode(x);
	if(index==0){
		new->next=list->head;
		list->head->prev=new;
		list->head=new;
		list->len++;
	}
	else if(index==list->len){
		list->tail->next=new;
		new->prev=list->tail;
		list->tail=new;
		list->len++;
	}
	else if(index<list->len){
		doublenode* temp,*prev;
		if(index<list->len/2){
			temp=list->head;
			for(int i=0;i<index;i++){
				temp=temp->next;
			}
			prev=temp->prev;

			prev->next=new;
			new->next=temp;
			temp->prev=new;
			new->prev=prev;
		}
		else{
			temp=list->tail;
			for(int i=list->len-1;i>=index;i--){
				temp=temp->prev;
			}
			prev=temp->prev;
			
			prev->next=new;
			new->next=temp;
			temp->prev=new;
			new->prev=prev;
		}
		list->len++;
	}
}

void DeleteDouble(DoubleLinkedList* list,int key){
	if(key==list->head->x){
		list->head=list->head->next;
		free(list->head->prev);
		list->head->prev=NULL;
		list->len--;
	}

	doublenode* temp=list->head->next,*prev=list->head;
	while (temp!=NULL)	{
		if(temp->x==key){
			prev->next=temp->next;
			temp->next->prev=prev;
			if(temp==list->tail) list->tail=prev;
			free(temp);
			temp=prev->next;
			list->len--;
		}
		else{
			prev=temp;
			temp=temp->next;
		}
	}

return;
}

void swap(doublenode** a,doublenode** b){
	doublenode* temp=*a;
	*a=*b;
	*b=temp;
}

void ReverseDoublyLinkedList(DoubleLinkedList* list){
	doublenode* temp=list->tail;
	while(temp!=NULL){
		swap(&temp->next,&temp->prev);
		temp=temp->next;
	}
	temp=list->head;
	list->head=list->tail;
	list->tail=temp;
}
//Test