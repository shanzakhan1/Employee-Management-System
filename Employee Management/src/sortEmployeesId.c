#include "../include/headerA3.h"

/************************************************
This function sorts the linked list based on
empId in ascending order.

Parameters:
    headLL - linked list (struct employee)

Returns:
    void
*************************************************/
void sortEmployeesId (struct employee * headLL) {
    int temp, flag = 0, countInner = 0;
    char temp2 [50], **temp3;
    struct employee * currentLL = NULL;

    /*checks if linked list is empty*/
    if (headLL == NULL) {
        printf ("\n The list is empty.\n");
        return;
    }

    do {
        countInner = 0;
        currentLL = headLL;

        /*uses bubble sorting to sort linked list based on empId in ascending order*/
        while (currentLL != NULL && currentLL->nextEmployee != NULL) {
            if (currentLL->empId > currentLL->nextEmployee->empId) {
                /*swaps the empId values*/
                temp = currentLL->empId;
                currentLL->empId = currentLL->nextEmployee->empId;
                currentLL->nextEmployee->empId = temp;

                /*swaps the numDependents values*/
                temp = currentLL->numDependents;
                currentLL->numDependents = currentLL->nextEmployee->numDependents;
                currentLL->nextEmployee->numDependents = temp;

                /*swaps the fname values*/
                strcpy (temp2, currentLL->fname);
                strcpy (currentLL->fname, currentLL->nextEmployee->fname);
                strcpy (currentLL->nextEmployee->fname, temp2);

                /*swaps the lname values*/
                strcpy (temp2, currentLL->lname);
                strcpy (currentLL->lname, currentLL->nextEmployee->lname);
                strcpy (currentLL->nextEmployee->lname, temp2);

                /*swaps the dependents values*/
                temp3 = currentLL->dependents;
                currentLL->dependents = currentLL->nextEmployee->dependents;
                currentLL->nextEmployee->dependents = temp3;

                countInner++;
            }
            currentLL = currentLL->nextEmployee;
        }
        if (countInner == 0) {
            flag = 1;
        }
    } while (flag != 1); //countinues until linked list is completely sorted
}

