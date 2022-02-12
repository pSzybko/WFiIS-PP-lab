#include "cycle.h"

void print_list(struct tnode *head){
    if(!head) return;
    tnode *ptr=head;
    while(ptr->next!=head){
        printf("%d\t", ptr->value);
        ptr=ptr->next;
    }
    printf("%d\n", ptr->value);
}

struct tnode* add_el(struct tnode* head, struct tnode* el){
    if(!head){
        el->next=el;
        return el;
    }
    tnode *ptr=head;
    el->next=head;
    while(ptr->next!=head)
        ptr=ptr->next;
    ptr->next=el;
    return head;
}

void del_el(struct tnode** head, int var){
    if(!head) return;
    tnode *ptr=*head;
    tnode *ptr2=*head;
    while(ptr->next!=*head){
        ptr2=ptr;
        ptr=ptr->next;
        if(ptr->value==var){
            ptr2->next=ptr->next;
            free(ptr);
            ptr=ptr2;
        }
    }
    if((*head)->value==var){
        tnode *tmp=*head;
        *head=(*head)->next;
        free(tmp);
        ptr->next=*head;
    }
}

struct tnode* add_list(struct tnode* head1, struct tnode* head2){
    if(!head1) return (!head2) ? NULL : head2;
    if(!head2) return head1;
    tnode *ptr=head1;
    while(ptr->next!=head1) ptr=ptr->next;
    tnode *ptr2=head2;
    while(ptr2->next!=head2) ptr2=ptr2->next;
    ptr->next=head2;
    ptr2->next=head1;
    head2=NULL;
    return head1;
}

struct tnode* div_list(struct tnode** head){
    if(!head) return NULL;
    tnode *ptr=*head;
    tnode *head2=NULL;
    tnode *head3=NULL;
    while(ptr->next!=*head){
        tnode *tmp=ptr->next;
        if(ptr->value%2)
            head2=add_el(head2, ptr);
        else head3=add_el(head3, ptr);
        ptr=tmp;
    }
    if(ptr->value%2) head2=add_el(head2, ptr);
    else head3=add_el(head3, ptr);
    *head=head2;
    return head3;
}

void rev_list(struct tnode** head){
    if(!head || (*head)->next==*head) return;
    tnode *ptr=*head;
    tnode *ptr2=NULL;
    tnode *ptr3=NULL;
    do{
        ptr2=ptr->next;
        ptr->next=ptr3;
        ptr3=ptr;
        ptr=ptr2;
    }while(ptr!=*head);
    (*head)->next=ptr3;
    *head=ptr3;
}

void free_list(struct tnode** head){
    if(!head) return;
    tnode *ptr=(*head)->next;
    while(ptr->next!=*head){
        tnode *ptr2=ptr->next;
        free(ptr);
        ptr=ptr2;
    }
    free(ptr);
    free(*head);
}