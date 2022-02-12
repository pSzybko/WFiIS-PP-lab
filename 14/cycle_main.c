#include "cycle.h"

int main(){
    tnode *head=NULL;
    tnode *head2=NULL;
    for(int i=0; i<10; i++){
        tnode *el=calloc(1, sizeof(tnode));
        tnode *el2=calloc(1, sizeof(tnode));
        el->value=i%4;
        el2->value=i;
        head=add_el(head, el);
        head2=add_el(head2, el2);
    }
    printf("Dodawanie do listy:\n");
    print_list(head);
    printf("Usuwanie z listy:\n");
    del_el(&head, 0);
    print_list(head);
    printf("Dodawanie list:\n");
    print_list(head);
    print_list(head2);
    head=add_list(head, head2);
    print_list(head);
    free_list(&head);
    head=NULL;
    head2=NULL;
    for(int i=0; i<10; i++){
        tnode *el=calloc(1, sizeof(tnode));
        el->value=i;
        head=add_el(head, el);
    }
    printf("Podział listy:\n");
    print_list(head);
    head2=div_list(&head);
    print_list(head);
    print_list(head2);
    free_list(&head);
    free_list(&head2);
    head=NULL;
    for(int i=0; i<10; i++){
        tnode *el=calloc(1, sizeof(tnode));
        el->value=i;
        head=add_el(head, el);
    }
    printf("Obracanie listy:\n");
    print_list(head);
    rev_list(&head);
    print_list(head);
    free_list(&head);
    return 0;
}