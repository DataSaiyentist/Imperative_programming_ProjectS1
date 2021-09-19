#ifndef STACK_H
#define STACK_H

typedef int value;

struct stack {
    value v;
    struct stack* next;
};

typedef struct stack* stack;

/*@ requires nothing
    assigns nothing
    ensures the return of an empty stack */
stack empty_stack();

/*@ requires s is valid
    assigns nothing
    ensures returns 1 if s is empty, 0 otherwise */
int is_empty_stack (stack s);

/*@ requires s is valid
    assigns nothing
    ensures returns a stack res such as res->v=v and res->next=s  */
stack cons(value v, stack s);

/*@ requires ps and *ps are valid (also not empty)
    assigns *ps
    ensures insert v into the FILO *ps */
void push(value v, stack *ps);

/*@ requires ps and *ps are valid and ot empty
    assigns *ps
    ensures removes the last value pushed of *ps and returns it */
value pop (stack *ps);


/*@requires s is valid (even empty)
@assigns nothing
@ensures print the contents of s as requested*/
void show(stack s);

#endif /* STACK_H */