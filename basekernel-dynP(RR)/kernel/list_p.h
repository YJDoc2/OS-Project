
#include "list.h"
#ifndef LISTP_H
#define LISTP_H

struct list_p;
struct list_node;

struct list_p {
	struct list_node *head;
	struct list_node *tail;
	int size;
};

void list_p_push(struct list_p *list, struct list_node *node);
//void list_push_tail(struct list *list, struct list_node *node);
//void list_push_priority(struct list *list, struct list_node *node, int pri);
struct list_node *list_p_pop(struct list_p *list);
//struct list_node *list_pop_tail(struct list *list);
void list_p_remove(struct list_node *n);
int  list_p_size(struct list_p *list);

#endif