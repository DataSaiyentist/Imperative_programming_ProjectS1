#ifndef RULES_H
#define RULES_H

/*@ requires that each contents of s (which are stacks) are avlid and not empty
    assigns nothing
    ensures the return of a list with the score of each players */
int* score(stack* s, int* l, int n, int t);

/*@ requires that each contents of s are valid
    assigns nothing
    ensures print the board */
void shown (stack* s, int t);

/*@ requires that each contents of s are valid
    assigns stack* s
    ensures add the chip as requested by the player and change the board if there is any activation */
stack* active(stack* s, int i, int j, int n, int t, int* l);

/*@ requires that each contents of s are valid
    assigns nothing
    ensures returns 1 if the board is not completed, 0 otherwise */
int nofinish(stack* s, int t);

#endif /* RULES_H */