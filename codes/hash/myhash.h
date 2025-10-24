#ifndef MYLIB_H
#define MYLIB_H

// Include standard libraries if needed
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;//data
    struct node* next;//ptr
}node;
node* NewNode(int x){
	node* n=(node*)malloc(sizeof(node));
	n->x=x;
	n->next=NULL;
	return n;
}
void insert(node** head,int key){
        node* nod=NewNode(key);
	if ((*head)==NULL){
		*head=nod;
		return;
	}
        if (key<=(*head)->x){
                nod->next=*head;
                *head=nod;
                return;
        }
        node* temp=*head,*prev=*head;
        while(temp!=NULL){
                if (key<=temp->x){
                        nod->next=temp;
                        prev->next=nod;
                        return;
                }       
                prev=temp;
                temp=temp->next;
        }
	prev->next=nod;

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

int hash(int x,int mod){
    return x%mod;
}

void CHAINInsertHash(node* HT[],int x,int mod){
    insert(&HT[x%mod],x);
}

node* CHAINSearch(node* HT[],int x,int mod){
    LinearSearch(HT[hash(x,mod)],x);
}

int* CreateProbeHash(int mod){
    int* ret=(int*)malloc(mod*sizeof(int));
    for(int i=0;i<mod;i++){
        ret[i]=-1;
    }
    return ret;
}

void PROBINGinsert(int HT[],int x,int mod){
    int index=hash(x,mod);
    if(HT[index]==-1){
            HT[index]=x;
            return;
        } 
    for (int i=(index+1)%mod;i%mod!=index;i++){
        if(HT[i%mod]==-1){
            HT[i%mod]=x;
            return;
        } 
    }
    printf("FAIL! HASH TABLE FULL!\n");
}

int PROBINGsearch(int* HT,int x,int mod){
    int index=hash(x,mod);
    if(HT[index]==x){
            return index;
        } 
    for (int i=(index+1)%mod;i%mod!=index;i++){
        if(HT[i%mod]==-1){
            return -1;
            printf("FAIL! ABSENT FROM HASH TABLE!\n");
        } 
        if(HT[i%mod]==x){
            return i%mod;
        } 
    }
    printf("FAIL! ABSENT FROM HASH TABLE!\n");
    return -1;
}

void printHT(int* HT,int mod){
    for (int i=0;i<mod;i++){
        printf("%d ",HT[i]);
    }
    printf("\n");
}
#endif // MYLIB_H