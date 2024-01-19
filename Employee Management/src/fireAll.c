#include "../include/headerA3.h"

/*********************************
This function clears all the
employees from the linked list

Parameters:
    headLL - linked list (a3Emp)

Returns:
    void
*********************************/
void fireAll (a3Emp ** headLL) {
    a3Emp * currentLL = *headLL;
    a3Emp * next;

    /*checks if linked list is empty*/
    if (currentLL == NULL) {
        printf ("\n The list is empty.\n");
        return;
    }

    /*frees each employee's information from linked list*/
    while (currentLL != NULL) {
        next = currentLL->nextEmployee;
        free (currentLL);
        currentLL = next;
    }

    *headLL = NULL;
}

