#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tnode {
    int value;
    struct tnode *next;
    struct tnode *prev;
}tnode;

void print_list(struct tnode* head){
    if(!head) return;
    tnode *ptr=head;
    while(ptr->next){
        printf("%d\t", ptr->value);
        ptr=ptr->next;
    }
    printf("%d\n", ptr->value);
}

struct tnode* add_first(struct tnode* head, struct tnode* el){
    el->next=head;
    el->prev=NULL;
    if(!head) return el;
    head->prev=el;
    return el;
}

struct tnode* add_last(struct tnode* head, struct tnode* el){
    el->next=NULL;
    if(!head){
        el->prev=NULL;
        return el;
    }
    tnode *ptr=head;
    while(ptr->next) ptr=ptr->next;
    el->prev=ptr;
    ptr->next=el;
    return head;
}

struct tnode* del_el(struct tnode** head, int var){
    tnode *ptr=*head;
    while(ptr!=NULL && ptr->value!=var) ptr=ptr->next;
    if(ptr==*head){
        *head=(*head)->next;
        (*head)->prev=NULL;
        ptr->next=NULL;
        return ptr;
    }
    if(ptr==NULL) return NULL;
    tnode *ptr2=ptr->prev;
    ptr2->next=ptr->next;
    tnode *ptr3=ptr->next;
    ptr3->prev=ptr2;
    ptr->next=NULL;
    ptr->prev=NULL;
    return ptr;
}

void add_sort(struct tnode** head, struct tnode* el){
    if(!*head){
        el->prev=NULL;
        el->next=NULL;
        return;
    }
    tnode *ptr=*head;
    if(ptr->value>el->value){
        *head=add_first(*head, el);
        return;
    }
    while(ptr!=NULL && el->value>ptr->value) ptr=ptr->next;
    if(ptr==NULL) {*head=add_last(*head, el); return;}
    el->next=ptr;
    el->prev=ptr->prev;
    ptr=ptr->prev;
    ptr->next=el;
}

struct tnode* div_list(struct tnode** head){
    if(!*head) return NULL;
    tnode *head2=NULL;
    tnode *head3=NULL;
    tnode *ptr=*head;
    while(ptr){
        tnode *tmp=ptr->next;
        if(ptr->value%2)
            add_sort(&head2, del_el(head, ptr->value));
        else add_sort(&head3, del_el(head, ptr->value));
        ptr=tmp;
    }
    *head=head3;
    return head2;
}

void free_list(struct tnode** head){
    if(!*head) return;
    tnode *ptr=*head;
    while(ptr->next){
        ptr=ptr->next;
        free(ptr->prev);
    }
    free(ptr);
}

int main(){

}