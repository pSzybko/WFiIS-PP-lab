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

int main(){
    tnode *head=NULL;
    head=dodaj_na_poczatek(head, 'a');
    head=dodaj_na_poczatek(head, 'c');
    head=dodaj_na_poczatek(head, 'v');
    head=dodaj_na_poczatek(head, 'f');
    head=dodaj_na_poczatek(head, 't');
    print_list(head);
    free_list(head);
    head=NULL;
    dodaj_na_koniec(&head, 'a');
    dodaj_na_koniec(&head, 'c');
    dodaj_na_koniec(&head, 'v');
    dodaj_na_koniec(&head, 'f');
    dodaj_na_koniec(&head, 't');
    print_list(head);
    free_list(head);
    return 0;
}