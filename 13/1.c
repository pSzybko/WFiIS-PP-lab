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

tnode *swap_list(tnode *head){
    if(!head) return NULL;
    tnode *ptr=NULL;
    while(head){
        tnode *ptr2=head->next;
        head->next=ptr;
        ptr=head;
        head=ptr2;
    }
    return ptr;
}

int main(){
    tnode *head=NULL;
    dodaj_na_koniec(&head, 'f');
    dodaj_na_koniec(&head, 'd');
    dodaj_na_koniec(&head, 'u');
    dodaj_na_koniec(&head, 'i');
    print_list(head);
    head=swap_list(head);
    print_list(head);
    free_list(head);
    return 0;
}