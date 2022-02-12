#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
    char value;
    struct tnode *next;
}tnode;

tnode *dodaj_na_poczatek(tnode *head, char val){
    tnode *tmp=calloc(sizeof(tnode), 1);
    tmp->value=val;
    tmp->next=head;
    head=tmp;
    return head;
}

void dodaj_na_koniec(tnode **head, char val){
    if(!*head){
        *head=calloc(sizeof(tnode), 1);
        (*head)->value=val;
        (*head)->next=NULL;
        return;
    }
    tnode *ptr=*head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    tnode *tmp=calloc(sizeof(tnode), 1);
    tmp->next=NULL;
    tmp->value=val;
    ptr->next=tmp;
}

void print_list(tnode *head){
    if(!head) return;
    tnode *ptr=head;
    while(ptr->next!=NULL){
        printf("%c", ptr->value);
        ptr=ptr->next;
    }
    printf("%c\n", ptr->value);
}

void free_list(tnode *head){
    tnode *ptr=head;
    tnode *ptr2=head;
    while(ptr->next!=NULL){
        ptr2=ptr->next;
        free(ptr);
        ptr=ptr2;
    }
    free(ptr);
}

tnode *merge_lists(tnode **l1, tnode **l2){
    if(!l1 && l2){
        tnode *ptr=*l2;
        *l2=NULL;
        return ptr;
    }
    if(l1 && !l2){
        tnode *ptr=*l1;
        *l1=NULL;
        return ptr;
    }
    if(!l1 && !l2) return NULL;
    tnode *ptr1=*l1;
    tnode *ptr2=*l2;
    while(ptr2){
        while(ptr1->next && ptr1->next->value<ptr2->value)
            ptr1=ptr1->next;
        tnode *tmp=ptr2->next;
        ptr2->next=ptr1->next;
        ptr1->next=ptr2;
        ptr2=tmp;
        ptr1=*l1;
    }
    *l1=NULL;
    *l2=NULL;
    return ptr1;
}

int main(){
    tnode *head1=NULL;
    tnode *head2=NULL;
    tnode *head3=NULL;
    head1=dodaj_na_poczatek(head1, 'z');
    head1=dodaj_na_poczatek(head1, 'l');
    head1=dodaj_na_poczatek(head1, 'k');
    head1=dodaj_na_poczatek(head1, 'a');
    head2=dodaj_na_poczatek(head2, 'w');
    head2=dodaj_na_poczatek(head2, 'l');
    head2=dodaj_na_poczatek(head2, 'n');
    head2=dodaj_na_poczatek(head2, 'b');
    head2=dodaj_na_poczatek(head2, 'a');
    print_list(head1); print_list(head2);
    head3=merge_lists(&head1, &head2);
    print_list(head3);
    print_list(head1);
    print_list(head2);
    free_list(head3);
}