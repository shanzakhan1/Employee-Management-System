#include "../include/headerA3.h"

/***********************************
This funtion counts number of
employees in linked list

Parameters:
    headLL - linked list (struct employee)

Returns:
    count - number of employees (int)
*************************************/
int countEmployees (a3Emp * headLL) {
    int count = 0;

    /*checks if linked list is empty*/
    if (headLL == NULL) {
        printf ("\n The list is empty.\n");
        return 0;
    }

    /*counts number of employees by traversing through linked list*/
    while (headLL != NULL) {
        count++;
        headLL = headLL->nextEmployee;
    }

    return count;
}

