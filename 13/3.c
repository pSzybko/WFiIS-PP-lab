#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

tnode *delete_val(tnode **head, char val){
    if(!head) return NULL;
    tnode *tmp=NULL;
    tnode *ptr=*head;
    tnode *ptr2=NULL;
    while(ptr->next && ptr){
        ptr2=ptr;
        ptr=ptr->next;
        if(ptr->value==toupper(val) || ptr->value==tolower(val)){
            dodaj_na_koniec(&tmp, ptr->value);
            ptr2->next=ptr->next;
            free(ptr);
            ptr=ptr2;
        }
    }
    if((*head)->value==toupper(val) || (*head)->value==tolower(val)){
        tmp=dodaj_na_poczatek(tmp, (*head)->value);
        tnode *t=*head;
        *head=(*head)->next;
        free(t);
    }
    return tmp;
}

int main(){
    tnode *head=NULL;
    tnode *left=NULL;
    head=dodaj_na_poczatek(head, 'A');
    head=dodaj_na_poczatek(head, 'l');
    head=dodaj_na_poczatek(head, 'a');
    head=dodaj_na_poczatek(head, ' ');
    head=dodaj_na_poczatek(head, 'm');
    head=dodaj_na_poczatek(head, 'a');
    head=dodaj_na_poczatek(head, ' ');
    head=dodaj_na_poczatek(head, 'k');
    head=dodaj_na_poczatek(head, 'o');
    head=dodaj_na_poczatek(head, 't');
    head=dodaj_na_poczatek(head, 'a');
    print_list(head);
    left=delete_val(&head, 'a');
    print_list(head);
    print_list(left);
    free_list(head);
    free_list(left);
    return 0;
}