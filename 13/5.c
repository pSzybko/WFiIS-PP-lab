#include <stdlib.h>
#include <stdio.h>

typedef struct tnode {
    int value;
    struct tnode *next;
}tnode;

void dodaj_na_koniec(tnode **head, int val){
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
        printf("%d\t", ptr->value);
        ptr=ptr->next;
    }
    printf("%d\n", ptr->value);
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
    tnode *L_1=NULL;
    tnode *L_2=NULL;

    while(1){
        int val=0;
        scanf("%d", &val);
        if(val>20) break;
        if(val!=0){
            if(val%2) dodaj_na_koniec(&L_2, val);
            else dodaj_na_koniec(&L_1, val);
        }else{
            dodaj_na_koniec(&L_1, val);
            dodaj_na_koniec(&L_2, val);
            while(1){
                scanf("%d", &val);
                if(val>20) break;
                dodaj_na_koniec(&L_1, val);
                dodaj_na_koniec(&L_2, val);
            }
            break;
        }
    }
    print_list(L_1);
    print_list(L_2);
    free_list(L_1);
    free_list(L_2);
}