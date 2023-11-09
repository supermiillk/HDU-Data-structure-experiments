#ifndef _CYCLELINKLIST_H
#define _CYCLELINKLIST_H

#define MAXIZE 100
#define ERROR 0
#define OK 1

typedef struct
{
    int base ;
    int top ;
    int data[ MAXIZE ] ;
} Stack ;

void init_stack( Stack * S ) ;
int empty_stack( Stack * S ) ;
int full_stack( Stack * S ) ;
int push_stack( Stack * S , int val ) ;
int pop_stack( Stack * S , int * val ) ;
int traverse_stack( Stack * S ) ;
int clear_stack( Stack * S ) ;
int gettop( Stack * S , int * val ) ;

#endif
