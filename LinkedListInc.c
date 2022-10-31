#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

//Function def
struct node* addAtHead(struct node** headg, int data);
void addAtEnd(struct node** headg, int data);
int getNthFromLast(struct node* head, int n);
int getsize(struct node* head);
void printlinkedRecForward(struct node* head);
void printLinkedList(struct node* head);
void reverseLinkedList(struct node** headg);
int isCircular(struct node* head);
int getNthNode(struct node* head, int n);
void deleteElem(struct node** head, int val);
int getJoiningPoint(struct node* heada, struct node* headb);
int getJoiningUnit(struct node* a, struct node* b, int n);
void printlinkedRecReverse(struct node* head);
int isPresent(struct node* head, int val);
void reverseLinkedList(struct node** head);


// Single linked list node structure
struct node {
    int data;
    struct node* next;
};

struct nodedouble {
    int data;
    struct nodedouble* next;
    struct nodedouble* prev;
};

// Adds data at head
struct node* addAtHead(struct node** headg, int data) {
    struct node* n = malloc(sizeof(struct node));
    n->data = data;
    n->next = *headg;
    *headg = n;
}

// Adds node data at end
void addAtEnd(struct node** headg, int data) {
    struct node* head = *headg;
    struct node* n = malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if (head == NULL) {
        *headg = n;
        return;
    }

    while (head->next != NULL) {
        head = head->next;
    }
    head->next = n;
}

// Prints the complete linked list
void printLinkedList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

// Reverses the linked list
void reverseLinkedList(struct node** headg) {
    struct node* head = *headg;
    if (head == NULL) {
        return;
    }
    struct node* s = head, * current = head->next, * next = head->next;
    s->next = NULL;
    while (next != NULL) {
        current = next;
        next = current->next;
        current->next = s;
        s = current;
    }
    *headg = s;
}

// Detects the linked list is circular or not
int isCircular(struct node* head) {
    struct node* a = head;
    struct node* b = head;
    while (b != NULL && b->next != NULL) {
        a = a->next;
        b = b->next->next;
        if (a == b) {
            return 1;
        }
    }
    return 0;
}

//get nth node 
int getNthNode(struct node* head, int n) {
    int l = getsize(head);
    if (l < n) {
        return -1;
    }
    for (int i = 0;i < n;i++) {
        head = head->next;
    }
    return head->data;
}

int getNthFromLast(struct node* head, int n) {
    if (n <= 0) return -1;
    int len = 1;
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
        len++;
    }
    temp = head;
    len = len - n;
    if (len < 0) return-1;
    while (len--) {
        temp = temp->next;
    }
    return temp->data;
}

//get size of linked list
int getsize(struct node* head) {
    int n = 0;
    while (head != NULL) {
        n++;
        head = head->next;
    }
    return n;
}

//two linked list merged at a point get that points data
int getJoiningUnit(struct node* a, struct node* b, int n) {
    while (n--) {
        a = a->next;
    }
    while (a != b) {
        a = a->next;
        b = b->next;
    }
    return a->data;
}

//find the joining point in list
int getJoiningPoint(struct node* heada, struct node* headb) {
    int a = getsize(heada);
    int b = getsize(headb);
    if (a > b) {
        return getJoiningUnit(heada, headb, a - b);
    }
    return getJoiningUnit(headb, heada, b - a);
}

// delete the list element
void deleteElem(struct node** head, int val) {
    struct  node* temp = *head;
    struct node* todelete = NULL;
    if (temp->data == val) {
        todelete = temp;
        *head = temp->next;
        free(todelete);
        return;
    }
    while (temp->next->data != val) {
        temp = temp->next;
    }
    todelete = temp->next;
    temp->next = temp->next->next;
    free(todelete);
    return;
}

//reverse the linked list
// void reverseLinkedList(struct node** head) {
//     struct node* temp = *head;//pointing to the head
//     struct node* toadd = NULL;
//     struct node* second = temp->next;
//     temp->next = NULL;
//     while (second != NULL) {
//         toadd = second;
//         second = second->next;
//         toadd->next = temp;
//         temp = toadd;
//     }
//     *head = temp;
// }

//searching linked list 

int isPresent(struct node* head, int val) {
    while (head != NULL) {
        if (head->data == val) return 1;
        head = head->next;
    }
    return 0;
}

// print the linked list in forward direction using recursion
void printlinkedRecForward(struct node* head) {
    if (head == NULL || head->next == NULL) return;
    printf("%d", head->data);
    printLinkedList(head->next);
}

//print the linked list in reverse direction using recursion
void printlinkedRecReverse(struct node* head) {
    if (head == NULL)return;
    printlinkedRecReverse(head->next);
    printf("%d", head->data);
}

//doubly linked list

//create double linked list 
void insertAtHeadDoub(struct nodedouble** headg, int data) {
    struct nodedouble* head = *headg;
    struct nodedouble* n = malloc(sizeof(struct nodedouble));
    n->data = data;
    if (head == NULL) {
        n->next = NULL;
        n->prev = NULL;
        *headg = n;
        return;
    }
    n->next = head;
    head->prev = n;
    n->prev = NULL;
    *headg = n;

}

void printDoubleLinkedlist(struct nodedouble* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}
//create double linked list insert at end
void deleteNodedouble(struct nodedouble** headg, int data) {
    struct nodedouble* head = *headg;
    struct nodedouble* todelete = NULL;
    if (head->data == data) {
        todelete = head;
        if (head->next != NULL) {
            head->next->prev = NULL;
            *headg = head->next;
        } else *headg = NULL;

    } else {
        while (head->data != data && head != NULL) {
            head = head->next;
        }
        todelete = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
    }
    free(todelete);
}

void reverseDoublyLinkedList(struct nodedouble** headg) {
    struct nodedouble* p = *headg, * c = p->next, * n = p->next;
    p->next = NULL;
    while (n->next != NULL) {
        c = n;
        n = c->next;
        p->prev = c;
        c->next = p;
        c->prev = NULL;
        p = c;
    }
}

void insertInCirLinkelistasHead(struct nodedouble** headg, int data) {
    struct nodedouble* n = malloc(sizeof(struct nodedouble)), * head = *headg;
    n->next = head;
    n->prev = head->prev;
    *headg = n;
}


void deleteFromCirLinkList(struct nodedouble** headg, int data) {
    struct nodedouble* head = *headg, * realHead = *headg;
    int ispresent = 0;
    if (head->data == data) {
        ispresent = 1;
        *headg = head->next;
    }
    while (head->next != realHead) {
        head = head->next;
        if (head->data == data) {
            ispresent = 1;
            break;
        }
    }
    if (isPresent) {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        free(head);
    }

}

int main() {
    struct nodedouble* head = NULL;
    insertAtHeadDoub(&head, 5);
    insertAtHeadDoub(&head, 4);
    insertAtHeadDoub(&head, 3);
    insertAtHeadDoub(&head, 2);
    insertAtHeadDoub(&head, 1);
    deleteNodedouble(&head, 2);
    printDoubleLinkedlist(head);
}