#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode{
    char arr[10];
    int n;
    struct tnode *next;
}tnode;

void print_list(tnode *head){
    if(!head) return;
    tnode *ptr=head;
    while(ptr->next){
        printf("%s:\t%d\n", ptr->arr, ptr->n);
        ptr=ptr->next;
    }
    printf("%s:\t%d\n", ptr->arr, ptr->n);
}


void free_list(tnode **head){
    if(!head) return;
    tnode *ptr=*head;
    while(ptr->next){
        tnode *ptr2=ptr->next;
        free(ptr);
        ptr=ptr2;
    }
    free(ptr);
}

void add_alphabetical(tnode **head, char tab[10]){
    tnode *tmp=calloc(1, sizeof(tnode));
    strcpy(tmp->arr,tab);
    tmp->n=1;
    tmp->next=NULL;
    if(!*head){
        *head=tmp;
        return;
    }
    if(strcmp((*head)->arr, tmp->arr)>0){
        tmp->next=*head;
        *head=tmp;
        return;
    }
    if(strcmp((*head)->arr, tmp->arr)==0){
        (*head)->n++;
        free(tmp);
        return;
    }
    tnode *ptr=*head;
    while(ptr!=NULL){
        if(strcmp(ptr->next->arr, tmp->arr)>0){
            tmp->next=ptr->next;
            ptr->next=tmp;
            return;
        }
        if(strcmp(ptr->next->arr, tmp->arr)==0){
            free(tmp);
            ptr->next->n++;
            return;
        }
        ptr=ptr->next;
    }
}

int main(int argc, const char **argv[]){
    tnode *head=NULL;
    FILE *f=fopen("example.txt", "r");
    char str[10];
    while(fscanf(f, "%s", str)==1)
        add_alphabetical(&head, str);
    print_list(head);
    free_list(&head);
    fclose(f);
    return 0;
}