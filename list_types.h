#define STRINGMAX 25

struct data_node {
   char name [STRINGMAX];
   int data;
   struct data_node *next;
   };

