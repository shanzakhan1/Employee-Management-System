#include "../include/headerA3.h"

/********************************************************************
This function takes the full name of an employee as inout, it 
searches the current LL, and returns the position of this employee
in the current LL

Parameters:
    headLL - linked list (struct employee)
    whichName - an employee's full name (char)

Returns:
    employee - employee position in linked list (int)
*********************************************************************/
int lookOnFullName (struct employee * headLL, char whichName [100]) {
    int employee = 1, i, exist = 0;
    char firstName[MAX_LENGTH], lastName[MAX_LENGTH];

    /*checks if linked list is empty*/
    if (headLL == NULL) {
        printf ("\n The list is empty.\n");
        return -1;
    }

    /*checks to see if user entered a first and last name*/
    for (i = 0; i < strlen(whichName); i++) {
        if (whichName[i] == ' ') {
            exist = 1;
        }
    }

    if (exist != 1) {
        return -1;
    }

    /*breaks whichName in to the first name and last name*/
    strcpy (firstName, (strtok(whichName, " ")));
    strcpy (lastName, (strtok(NULL, " ")));

    /*finds employee that corresponds with whichName and returns their position*/
    while (headLL != NULL) {
        if ((strcmp(headLL->fname, firstName) == 0) && (strcmp(headLL->lname, lastName) == 0)) {
            return employee;
        }
        headLL = headLL->nextEmployee;
        employee++;
    }
    
    return -1;
}

