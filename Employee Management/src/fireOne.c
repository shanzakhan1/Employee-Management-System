#include "../include/headerA3.h"

/*********************************************
This function takes a value given by the user
between 1 and the total number of employees 
in the current LL and deletes the employee in
that position.

Parameters:
    headLL - linked list (a3Emp)
    whichOne - employee's position (int)

Returns:
    void
**********************************************/
void fireOne (a3Emp ** headLL, int whichOne) {
    a3Emp * currentLL = *headLL;
    a3Emp * previous = NULL;
    int count = 0;

    /*checks if linked list is empty*/
    if (currentLL == NULL) {
        printf ("\n The list is empty.\n");
        return;
    }

    /*finds employee in linked list*/
    while (currentLL != NULL) {
        count++;
        if (count == whichOne) {
            break;
        }
        previous = currentLL;
        currentLL = currentLL->nextEmployee;
    }

    /*prints if employee is not found*/
    if (currentLL == NULL) {
        printf ("\n Person not found\n");
        return;
    }

    /*shifts nodes in linked list to accommodate deleted employee*/
    if (previous == NULL) {
        *headLL = currentLL->nextEmployee;
    }
    else {
        previous->nextEmployee = currentLL->nextEmployee;
    }

    /*fires employee*/
    free (currentLL);
    
}

