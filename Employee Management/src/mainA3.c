#include "../include/headerA3.h"

int main () {
    int idLook = 0, fullNameLook = 0, employeeCount, employeeCount2, whichOne, whichone2, whichEmpId = 0, choice, i;
    struct employee * headLL = NULL;
    struct employee* temp = NULL, * temp2 = NULL;
    char whichName [100], whichName2 [100], deleteAns;

    loadEmpData (&headLL, "proFile.txt");

    do {
        /*prints menu of options for user*/
        printf ("\n 1. Add a new employee\n");
        printf (" 2. Print data of all employees\n");
        printf (" 3. Print data of the nth employee\n");
        printf (" 4. Search for employee based on empId\n");
        printf (" 5. Search for employee based on full name\n");
        printf (" 6. Count the total number of employees\n");
        printf (" 7. Sort the employees based on their empId\n");
        printf (" 8. Remove the nth employee in the current LL\n");
        printf (" 9. Remove all employees in the current LL\n");
        printf (" 10. Exit\n");

        printf ("\n Enter a menu option: ");
        scanf ("%d", &choice);

        switch (choice) {
            case 1: 

                /*calls the recuitEmployee function if user chooses 1*/
                recruitEmployee (&headLL);

                break;

            case 2:

                /*calls the printAll function if user chooses 2*/
                printAll (headLL);

                break;
                
            case 3:

                /*asks user to enter position of employee, then calls the printOne function*/
                printf ("\n Enter a position: ");
                scanf ("%d", &whichOne);

                printOne (headLL, whichOne);

                break;
                
            case 4:

                /*asks user to enter Id of specfic employee, then calls the lookOnId function*/
                printf ("\n Enter an employee ID: ");
                scanf ("%d", &whichEmpId);

                idLook = lookOnId (headLL, whichEmpId);

                if (idLook == -1) {
                    printf (" The employee with the Id %d does not exist.\n\n", whichEmpId);
                }
                else {
                    printOne(headLL, idLook);
                }

                break;
                
            case 5:

                /*asks user to enter an employee's name, then calls the lookOnFullName function*/
                while ((getchar()) != '\n');

                printf ("\n Enter the full name of the employee: ");
                fgets (whichName, 100, stdin);
                whichName[strlen(whichName) - 1] = '\0';

                strcpy (whichName2, whichName);

                fullNameLook = lookOnFullName (headLL, whichName);

                if (fullNameLook == -1) {
                    printf (" The employee with the name %s does not exist.\n\n", whichName2);
                }
                else {
                    printOne(headLL, fullNameLook);
                }

                break;
                
            case 6:

                /*calls the countEmployees function, displays number of employees*/
                employeeCount = countEmployees (headLL);

                printf ("\n Total number of employees = %d\n\n", employeeCount);

                break;
                
            case 7:

                /*calls the sortEmployeesId function*/
                sortEmployeesId (headLL);

                printf ("\n The employees have been sorted.\n");

                printAll (headLL);

                break;
                
            case 8:

                /*displays number of employees, then asks user which employee they want to fire*/
                employeeCount2 = countEmployees (headLL);

                printf (" Which employee do you wish to fire – enter a value between 1 and %d: ", employeeCount2);
                scanf ("%d", &whichone2);

                /*calls the fireOne function*/
                fireOne (&headLL, whichone2);
                
                printf ("\n There are now %d employees.\n", (countEmployees (headLL)));

                break;
                
            case 9:

                /*double checks if user wants to fire all employees, then calls the fireAll function*/
                printf ("\n Are you sure you want to fire everyone: ");
                scanf (" %c", &deleteAns);

                if (deleteAns == 'y' || deleteAns == 'Y') {
                    fireAll (&headLL);
                    headLL = NULL;
                    printf ("\n All fired. Linked list is now empty.\n\n");
                }
                else {
                    printf ("\n Employees not fired.\n");
                }

                break;
        }

    } while (choice != 10);

    /*freeing dynamically allocated space*/
    while (headLL != NULL) {
        temp2 = headLL;
        for (i = 0; i < temp2->numDependents; i++) {
            free (temp2->dependents[i]);
        }
        headLL = headLL->nextEmployee;
    }

    /*frees linked list*/
    while (headLL != NULL) {
	temp = headLL;
        free(temp);
        headLL = headLL->nextEmployee;
    }

}

