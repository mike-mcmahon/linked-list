#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 
C program to demonstrate ordered singly-linked list.
2012 09 07 F:
   updated: implementation code all within functions (none in main())
*/

struct data_node {
   char name [25];
   int data;
   struct data_node *next;
   };

void dump_list (struct data_node *current) {
printf("List dump:\n");
while (current != NULL) {
   printf("%s: %d\n", current->name, current->data);
   current=current->next;
   } /* end while */
printf("\n");
}; /* end dump_list */

void dump_node (struct data_node *current) {
printf("Dumping node: ");
if (current != NULL)
   printf("%s: %d\n", current->name, current->data);
}; /* end dump_list */

struct data_node * find_node (struct data_node *p, int elem) {
while (p != NULL) {
   if ( elem == p->data )
      return p;
   p=p->next;
   } /* end while */
}; /* end find_node */

int delete (struct data_node **p_first, int elem) {
int retval = 0;
struct data_node *current, *prev;
current=*p_first;
while (current != NULL && elem != current->data ) {
   prev=current;
   current=current->next;
   }
if (current == NULL) /* element not found */
   return retval;
/* current now points to node to delete */
if ( current == *p_first ) /* delete 1st node */
   *p_first = (*p_first)->next;
else  /* link previous to next thus skipping over node to delete */
   prev->next=current->next;
free(current);
retval=1;
return retval;
}; /* end delete */

struct data_node * insert (struct data_node **p_first, int elem) {

struct data_node *new_node, *prev, *current;
current=*p_first;
while (current != NULL && elem > current->data) {
   prev=current;
   current=current->next;
} /* end while */
/* now need to insert new node before current */
new_node = (struct data_node *) malloc(sizeof(struct data_node));
new_node->data=elem;

new_node->next=current;
if ( current == *p_first ) /* insert before 1st element */
   *p_first=new_node; 
else                       /* now insert before current */
   prev->next=new_node;
/* end if current == *p_first */
return new_node;
}; /* end insert */


int main (void) {

struct data_node *first=NULL, *ptr;

printf("Insert first node into list\n");
first=ptr=insert(&first, 5);
strcpy(ptr->name,"Alexander");

ptr=insert(&first, 7);
strcpy(ptr->name,"Zeigfried");

dump_list(first);
printf("Search found: ");
ptr=find_node(first, 7);
dump_node(ptr);
printf("Insert before 1st node.\n");
ptr=insert(&first, 4);
strcpy(ptr->name,"Carlos");
dump_node(ptr);
dump_list(first);
printf("Deleting non-1st node.\n");
delete(&first, 7);
dump_list(first);
printf("Insert at end.\n");
ptr=insert(&first, 9);
strcpy(ptr->name,"Deanna");
dump_list(first);
printf("Deleting 1st node.\n");
delete(&first, 4);
dump_list(first);
printf("Insert in middle.\n");
ptr=insert(&first, 6);
strcpy(ptr->name,"Edwin");
dump_list(first);
return (0);
} /* end main */

