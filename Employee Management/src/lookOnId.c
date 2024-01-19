#include "../include/headerA3.h"

/********************************************************
This function does the following: takes an empId as input,
it searches the current LL using the given empId, and 
returns the position of this employee in the current LL.

Parameters:
    headLL - linked list (struct employee)
    whichEmpId - specfic employee Id (int)

Returns:
    count - employee position in linked list (int)
*********************************************************/
int lookOnId (struct employee * headLL, int whichEmpId) {
    int count = 1;

    /*checks if linked list is empty*/
    if (headLL == NULL) {
        printf ("\n The list is empty.\n");
        return -1;
    }

    /*traverses through the linked list to find employee with the corresponding empId and returns their position*/
    while (headLL != NULL) {
        if (headLL->empId == whichEmpId) {
            return count;
        }
        headLL = headLL->nextEmployee;
        count++;
    }

    return -1;
}

