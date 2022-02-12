#ifndef CYCLE_H
#define CYCLE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    int value;
    struct tnode *next;
}tnode;

void print_list(struct tnode *head);

struct tnode* add_el(struct tnode* head, struct tnode* el);

void del_el(struct tnode** head, int var);

struct tnode* add_list(struct tnode* head1, struct tnode* head2);

struct tnode* div_list(struct tnode** head);

void rev_list(struct tnode**);

void free_list(struct tnode**);

# endif