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

void add_ascending(tnode *head, char val);

int main(){
    tnode *head=NULL;
    dodaj_na_koniec(&head, 'a');
    dodaj_na_koniec(&head, 'j');
    dodaj_na_koniec(&head, 'k');
    dodaj_na_koniec(&head, 'z');
    print_list(head);
    add_ascending(head, 'w');
    print_list(head);
    free_list(head);
    return 0;
}

void add_ascending(tnode *head, char val){
    if(!head || head->value>val){
        head=dodaj_na_poczatek(head, val);
        return;
    }
    tnode *ptr=head;
    while(ptr->next){
        if(ptr->next->value>val){
            tnode *tmp=calloc(1, sizeof(tnode));
            tmp->value=val;
            tmp->next=ptr->next;
            ptr->next=tmp;
            return;
        }
        ptr=ptr->next;
    }
    dodaj_na_koniec(&head, val);
}