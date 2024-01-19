#include "../include/headerA3.h"

/*******************************************************
This function takes a sequence number as input and 
prints the data of the employee at that position in 
the current LL.

Parameters:
    headLL - linked list (stuct employee)
    whichOne - which employee (int)

Returns:
    void
********************************************************/
void printOne (struct employee * headLL, int whichOne) {
    int i, count = 1;

    /*checks if linked list is empty*/
    if (headLL == NULL) {
        printf ("\n The list is empty.\n");
        return;
    }

    while (headLL != NULL) {
        /*searches through linked list to find employee*/
        if (count == whichOne) {
            /*prints specified employee's information*/
            printf ("\n Employee #%d:\n", whichOne);
            printf (" \t Employeee id: %d\n", headLL->empId);
            printf (" \t First Name: %s\n", headLL->fname);
            printf (" \t Last Name: %s\n", headLL->lname);
            printf (" \t Dependents[%d]: ", headLL->numDependents);
            for (i = 0; i < headLL->numDependents; i++) {
                if (i == (headLL->numDependents - 1)) {
                    printf ("%s\n\n", headLL->dependents[i]);
                }
                else {
                    printf ("%s, ", headLL->dependents[i]);
                }
            }
            break;
        }
        /*moves to next node*/
        headLL = headLL->nextEmployee;
        count++;
    }

    if (headLL == NULL) {
        printf (" An employee at %d position does not exist.\n", whichOne);
        return;
    }
}

