/*           list_funcs.c                                                               */
/* Mike McMahon, A.Sc.T.                                                                */
/* March 29, 2015                                                                       */
/* Student ID: 500605231                                                                */
/* Assignment #2 - List Manager                                                         */
/* CCPS 393 Section 1J0                                                                 */
/* Instructor: L. Hiraki                                                                */
/* Purpose: To implement a linked list.                                                 */
/*          This file contains all the function definitions for the function prototypes */
/*          contained in the file list_funcs.h.  The function prototypes are            */
/*          ->  void dump_list (struct data_node *)                                     */
/*          ->  void dump_node (struct data_node *)                                     */
/*          ->  struct data_node * find_node (struct data_node *, int)                  */
/*          ->  int delete (struct data_node **, int)                                   */
/*          ->  struct data_node * insert (struct data_node **, int, char *)            */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_types.h"


void dump_list (struct data_node *p_start)
{
    
    /* Print the contents of the list. */
    printf("Printing List:\n");

    while (p_start != NULL)
    {
        printf ("%s : %d\n", p_start -> name, p_start -> data);
        p_start = p_start -> next;
    }

    printf ("\n");

}




void dump_node (struct data_node *pointer)
{

    /* Print contents of the node found. */
    if (pointer != NULL)
    {
        printf ("Printing node: %s : %d\n", pointer -> name, pointer -> data);
    }
    else
    {
        printf ("Node not found.\n");
    }
    
    }




struct data_node * find_node (struct data_node *p_start, int element)
{
    
    /* Find the node that matches the key data. */
    while (p_start != NULL)
    {
        if (element == p_start -> data)
        {
            return (p_start);
        }
        
        p_start = p_start -> next;
    
    }
    
}




int delete (struct data_node **p_start, int element)
{
    
    /* Delete the selected node if it exists. */
    int return_value = 0;
    struct data_node *current, *prev;
    
    current = *p_start;
    
    while (current != NULL && element != current -> data)
    {
        prev = current;
        current = current -> next;
    }
    
        if (current == NULL)
        {
            return (return_value);
        }
    
        if (current == *p_start)
        {
            *p_start = (*p_start) -> next;
        }
        else
        {
            prev -> next = current -> next;
            free (current);
            return_value = 1;
            return (return_value);
        }
    
}




struct data_node * insert (struct data_node **p_start, int element, char *string)
{

    /* Insert a new node into the list. */
    struct data_node *new_node, *prev, *current;
    
    current = *p_start;
    
    while (current != NULL && element > current->data)
    {
        prev = current;
        current = current->next;
    }
    
    new_node = (struct data_node *) calloc (1, sizeof (struct data_node));
    new_node -> data = element;
    strcpy (new_node -> name, string);
    new_node -> next = current;
    
    if ( current == *p_start )
    {
        *p_start = new_node;
    }
    else
    {
        prev -> next = new_node;
    }
    
    return (new_node);
 
}
