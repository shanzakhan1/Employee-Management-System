#include "../include/headerA3.h"

/******************************************
This function prints the information of 
each employee in the linked list

Parameters:
    headLL - linked list (struct employee)

Returns:
    void
*******************************************/
void printAll (struct employee * headLL) {
    int i = 1, j;

    /*checks if linked list is empty*/
    if (headLL == NULL) {
        printf ("\n The list is empty.\n");
        return;
    }

    /*prints each employee's information*/
    while (headLL != NULL) {
        printf ("\n Employee #%d:\n", i++);
        printf (" \t Employeee id: %d\n", headLL->empId);
        printf (" \t First Name: %s\n", headLL->fname);
        printf (" \t Last Name: %s\n", headLL->lname);
        printf (" \t Dependents[%d]: ", headLL->numDependents);
        for (j = 0; j < headLL->numDependents; j++) {
            if (j == (headLL->numDependents - 1)) {
                printf ("%s\n\n", headLL->dependents[j]);
            }
            else {
                printf ("%s, ", headLL->dependents[j]);
            }
        }
        /*moves to next node*/
        headLL = headLL->nextEmployee;
    }
}

