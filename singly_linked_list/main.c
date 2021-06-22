#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct Node
{
    int value;
    struct Node *next;
}node_t;

void
print_linked_list(node_t *head)
{
    node_t *tmp = head;
    while(tmp != 0)
    {
        printf("value - %d - ",tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

node_t*
create_new_node(int value)
{
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    
    new_node->value = value;
    new_node->next = 0;
    
    return new_node;
}

node_t*
add_node(node_t **head, int value)
{
    
    node_t *p;
    node_t *tmp = create_new_node(value);
    if(!*head)
    {
        *head = tmp;
    }
    else
    {
        p = *head;
        while(p->next != 0)
        {
            p = p->next;
        }
        p->next = tmp;
    }
    return *head;
}

node_t *
find_node(node_t *head,int value)
{
    node_t *tmp = head;
    while(tmp->next != 0)
    {
        if(tmp->value == value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return 0;
}

void
add_after(node_t *node, node_t *new_node)
{
    new_node->next = node->next;
    node->next = new_node;
}

void
add_to_beginning(node_t **head,node_t *new_node)
{
    new_node->next = *head;
    *head = new_node;
}

void
delete_node(node_t **head, int value)
{
    if(!*head)
    {
        return;
    }
    if((*head)->value == value)
    {
        *head = (*head)->next;
    }
    
    node_t *tmp = *head;
    while(tmp->next != 0)
    {
        if(tmp->next->value == value)
        {
            tmp->next = tmp->next->next;
        }
        else
        {
            tmp = tmp->next;
        }
    }
}

int
main(int argc, char *argv[])
{
    node_t *list = 0;
    add_node(&list, 1);
    add_node(&list, 2);
    add_node(&list, 3);
    add_node(&list, 4);
    add_node(&list, 5);
    
    int value = 1;
    node_t *found_node;
    if(found_node = find_node(list, value))
    {
        printf("%d is finded in list\n",value);
        node_t *new_node = create_new_node(135);
        add_to_beginning(&list, new_node);
    }
    else
    {
        printf("%d is not finded in list\n",value);
    }
    
    print_linked_list(list);
    
    delete_node(&list,135);
    
    print_linked_list(list);
    
    return 0;
}