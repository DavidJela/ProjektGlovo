#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "functions.h"
int mainMenu(const char* const fileName) {
    
    int choice = 0;

    static DATA* arrayData = NULL;
    static DATA* foundID = NULL;

    arrayData = loadPrint(fileName);
    if (arrayData == NULL) {
        printf("Error: Unable to read data from file.\n");
        return -1;
    }

    /*idData = getIdData(fileName);
    if (idData < 0) {
        printf("Error: Invalid number of Data.\n");
        return -1;
    }*/
    while (1) {
        system("cls");
        printf("====================");
        printf("Glovo profit calcualtor v0.1:");
        printf("====================\n");
        printf("\t\t- - - - - - - - - - - -\n");;
        printf("\t\t1. Add day \n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t2. Load and print all days\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t3. Print max profit day\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t4. Print best hourly earning day\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t5. Sort and print days by profit per day\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t6. Sort and print days by hourly earnings\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t7. Delete certain day\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t8. Delete Bin File\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t9 Edit day\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t10. Search specific day by ID\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t11. Exit program\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("=====================================================================\n");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case INPUT:
            addDay(fileName, arrayData);
            break;
        case LOAD:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadPrint(fileName);
            if (arrayData == NULL) {
                exit(EXIT_FAILURE);
            }
            break;
        case MAX_PROFIT_DAY:
            printMaxProfitDay(arrayData,idData);
            break;
        case MAX_HOUR_DAY:
            printMaxHourDay(arrayData,idData);
            break;
        case SORT_PROFIT:
            maxProfitPrint(arrayData, idData);
            break;
        case SORT_HOUR:
            maxPerHourPrint(arrayData, idData);
            break;
        case DELETE_DAY:
            deleteDay(arrayData, fileName);
            break;
        case DELETE_F:
            if (deleteFile(fileName) == 0) {
                createFile(fileName);

                if (arrayData != NULL) {
                    free(arrayData);
                }

                arrayData = loadPrint(fileName);
                if (arrayData == NULL) {
                    printf("Failed to reload data after deletion.\n");
                    createFile(fileName);
                    arrayData = loadPrint(fileName);
                    if (arrayData == NULL) {
                        printf("Unable to create and load data.\n");
                        return -1;
                    }
                }
            }
            break;
        case EDIT_DAY:
            editDayByID((DATA*) arrayData,fileName);
            break;
        case SEARCH_DAY:
            foundID = (DATA*)searchDate(arrayData);
            break;
        case PROGRAM_EXIT:
            choice = exitProgram(arrayData);
            if (choice == 0)
                return 0;
            break;
        default : 
            printf("Invalid selection!\n");
        }
        system("pause");
    }

    free(arrayData);
    arrayData = NULL;

    return choice;
}