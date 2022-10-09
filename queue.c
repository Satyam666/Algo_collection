#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int d;
    struct Node *next;
};
typedef struct Node Node;
void enqueue(Node** F,Node** R,int v){

    Node* n=(Node*)malloc(sizeof(Node));
    n->next=NULL;
    n->d=v;
    if(*F==NULL && *R==NULL){
        *F=n;
        *R=n;
    }
    else{
        (*R)->next=n;
        *R=n;
    }
}
int dequeue(Node** F,Node** R){
    if((*F)==(*R)){
        (*R)=NULL;
    }
    Node* t=*F;
    *F=(*F)->next;
    int a=t->d;
    free(t);
    return a;
}

int peekQ(Node* F){
    return F->d;
}
void printQ(Node* F){
    while(F->next!=NULL){
        printf("%d->",F->d);
        F=F->next;
    }
    printf("%d->NULL\n",F->d);
    return;
}