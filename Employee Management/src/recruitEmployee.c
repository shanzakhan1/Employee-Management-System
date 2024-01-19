#include "../include/headerA3.h"

/*************************************************
This function allows user to manually enter
employee data from standard input and add their 
information to the end of the linked list

Parameters:
    headLL - linked list (struct employee)

Returns:
    void
**************************************************/
void recruitEmployee (struct employee ** headLL) {
    struct employee * addName, *currentLL;
    char dependentAns;
    int i, sum = 0;

    /*stores employee's first name, last name dependents, etc. in to linked list*/
    addName = (struct employee *) malloc(sizeof(struct employee));

    printf ("\n Enter the first name of the employee: ");
    scanf ("%s", addName->fname);

    printf ("\n Enter the last name of the employee: ");
    scanf ("%s", addName->lname);

    /*dynamically allocates space for dependents*/
    addName->numDependents = 0;
    addName->dependents = (char **)malloc(1 * sizeof(char *));
    do {
        addName->numDependents++;

        addName->dependents = (char **)realloc(addName->dependents, sizeof(char *) * (addName->numDependents + 2));
        addName->dependents[addName->numDependents - 1] = (char *)malloc(sizeof(char) * 25);

        printf ("\n Enter name of dependent #%d: ", addName->numDependents);
        scanf ("%s", addName->dependents[addName->numDependents - 1]);

        printf ("\n Do you have any more dependents? ");
        scanf (" %c", &dependentAns);
    } while (dependentAns == 'y' || dependentAns == 'Y'); //continues do while loop until user enters anything other than 'y'

    /*assigns employee with an employee id number*/
    for (i = 0; i < strlen(addName->fname); i++) {
        sum = sum + addName->fname[i];
    }

    addName->empId = sum + strlen(addName->lname);

    /*checks to see if employee id already exists and adds a random number if it does*/
    currentLL = *headLL;
    while (currentLL != NULL) {
        if (currentLL->empId == addName->empId) {
            addName->empId = rand() % 999 + 1;
        }
        currentLL = currentLL->nextEmployee;
    }

    /*adds new employee to the end of the linked list*/
    addName->nextEmployee = NULL;
    
    if (*headLL == NULL) {
        *headLL = addName;
    }
    else {
        currentLL = *headLL;
        while (currentLL->nextEmployee != NULL) {
            currentLL = currentLL->nextEmployee;
        }
        currentLL->nextEmployee = addName;
    }

}

