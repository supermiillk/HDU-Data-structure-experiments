#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void init_stack( Stack * S )
{
    S->base = S->top = 0 ;
}

int empty_stack( Stack * S )
{
    if( S->base == S->top )
        return OK ;
    else
        return ERROR ;
}

int full_stack( Stack * S )
{
    if( S->top == MAXIZE - 1 )
        return 1 ;
    else
        return 0 ;
}

int push_stack( Stack * S , int val )
{
    if( full_stack( S ) )
        return ERROR ;
    else
    {
        S->data[ S->top++ ] = val ;
        return OK ;
    }
}

int pop_stack( Stack * S , int * val )
{
    if( empty_stack( S ) )
        return ERROR ;
    else
    {
        *val = S->data[ --S->top ] ;
        return OK ;
    }
}

int traverse_stack( Stack * S )
{
    if( empty_stack( S ) )
        return ERROR ;
    else
    {
        for( int i = S->top - 1 ; i >= 0 ; i-- )
            printf( "%d " , S->data[ i ] ) ;

        printf( "\n" ) ;
        return OK ;
    }
}

int clear_stack( Stack * S )
{
    S->top = S->base ;
    return OK ;
}

int gettop( Stack * S , int * val )
{
    if( empty_stack( S ) )
        return ERROR ;
    else
    {
        int i = S->top - 1 ;
        *val = S->data[ i ] ;
        return OK ;
    }
}

