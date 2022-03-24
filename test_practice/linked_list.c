#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char node_value;
    struct node *next;
}stri;


void    print_linkedlist(stri *head)
{
    stri *temp;

    temp = head;
    while (temp != NULL)
    {
        printf("|%d|", temp -> node_value);
        temp = temp->next;
    }

    
}

stri *make_some_nodes(char a)
{
    stri* new_node = malloc(sizeof(stri));
    new_node -> node_value = a;
    new_node -> next = NULL;
    return(new_node);
}

stri specific_nodes_to_create(stri *temp, stri *head, char a)
{
    temp = make_some_nodes(a);
    temp -> next = head;
    head = temp;
    a++;
}    

int main(int argc, char **argv)
{
    stri *head = NULL;
    stri *temp;
    char a = scanf("put some leter");

    specific_nodes_to_create(temp, head, a);

    print_linkedlist(head);
}