#include <stdio.h>
#include <stdlib.h>

typedef int value;

struct stack {
    value v;
    struct stack* next;
};

typedef struct stack* stack;

stack empty_stack() {
    return NULL;
}

int is_empty_stack (stack s) {
    return (s==NULL);
}

stack cons(value v, stack s) {
    stack res;
    res=malloc(sizeof(struct stack));
    res->v=v;
    res->next=s;
    return res;
}

void push(value v, stack *ps) {
    *ps=cons(v,*ps);
}

value pop(stack *ps) {
    value res;
    stack tmp;
    res=(*ps)->v;
    tmp=*ps;
    *ps=(*ps)->next;
    free(tmp);
    return res;
}


void show(stack s) {
    if (is_empty_stack(s)) printf("\n");
    else {
        while (s!=NULL) {

        /* En notant i le nmbre d'itération et n le nbre de buckets de s: alors n-i est un variant de boucle, donc la boucle se termine */

            printf(" %i\n", s->v);
            s=s->next;
        }
    }    
    printf("---\n\n");
}