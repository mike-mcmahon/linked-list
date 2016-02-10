/*          list_mgr.c                                                          */
/* Mike McMahon, A.Sc.T.                                                        */
/* March 29, 2015                                                               */
/* Student ID: 500605231                                                        */
/* Assignment #2 - List Manager                                                 */
/* CCPS 393 Section 1J0                                                         */
/* Instructor: L. Hiraki                                                        */
/* Purpose: To implement a linked list.                                         */
/*          This implementation allows for the following actions to be taken    */
/*          by the user:                                                        */
/*          -> Insert a node                                                    */
/*          -> Delete a node                                                    */
/*          -> Search for a node (by key)                                       */
/*          -> Print the list                                                   */


#include <stdio.h>
#include "list_types.h"
#include "list_funcs.h"


main()
{

    /* Declaration of variables used locally within main function. */
    struct data_node *ptr, *start;
    int key;
    char command;
    char string_name[STRINGMAX];
    
    /* set the root or start of the list to NULL. */
    start = NULL;
    
    /* Prompt user for initial choice of action. */
    /* +  -> ADD                */
    /* -  -> DELETE             */
    /* f  -> SEARCH or FIND     */
    /* l  -> PRINT LIST         */
    /* x  -> EXIT               */
    printf ("Please enter a list command (+ - f l x): ");
    
    command = getchar();
    
    /* Main control loop.  Continually prompt for a user command, and */
    /* execute the function.  Exit to O/S if 'x' is selected. */
    while (command != 'x')
    {
        /* Select list function to execute. */
        switch (command)
        {
            case '+':
                    /* Insert a new node. */
                    printf ("+ detected\n");
                    printf ("Enter key data: ");
                    scanf ("%d", &key);
                    printf ("What string to store? ");
                    scanf ("%s", string_name);
                
                    ptr = insert (&start, key, string_name);

                    /* When list is first created, set start to point to */
                    /* the beginning of the list.                        */
                    if (start == NULL)
                    {
                        start = ptr;
                    }
    
                    break;
                
            case '-':
                    /* Delete a node. */
                    printf ("- detected\n");
                    printf ("Enter key data: ");
                    scanf ("%d", &key);
                
                    /* If the function delete returns 1, then the node selected */
                    /* was successfully deleted, else the function returns 0,   */
                    /* and no node was deleted.                                 */
                    if (delete (&start, key))
                    {
                        printf ("Data found: Node %d deleted.\n", key);
                    }
                    else
                    {
                        printf ("Data not found.  No deletion performed.\n");
                    }
    
                    break;
        
            case 'f':
                    /* Find and print a node. */
                    printf ("f detected\n");
                    printf ("Enter key data: ");
                    scanf ("%d", &key);
            
                    /* Find the node requested. */
                    ptr = find_node (start, key);
            
                    /* Print the node if/when found. */
                    dump_node (ptr);
                
                    break;
            
            case 'l':
                    /* Print the list. */
                    printf ("l detected\n");
                
                    dump_list (start);

                    break;
            
            default:
                    /* Ignor all other characters entered by user */
                    /* and reprompt as necessary.                 */

                    break;
        }
        
        /* Now that we are in a loop, again prompt user for choice of action. */
        while (getchar() != '\n');
        printf ("Please enter a list command (+ - f l x): ");
        command = getchar();
    }
    
    /* When command entered = 'x', exit program with message. */
    printf ("Exiting, goodbye\n");
    
    return (0);

}
