#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "functions.h"
int mainMenu(const char* const fileName) {
    
    int choices = 0;

    static DATA* arrayData = NULL;
    static DATA* foundID = NULL;

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
        printf("\t\t8. Edit day\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t9. Search specific day by ID\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("\t\t10. Exit program\n");
        printf("\t\t- - - - - - - - - - - -\n");
        printf("=====================================================================\n");

        if (scanf("%d", &choices) != 1) {
            printf("Invalid selection!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choices) {
        case INPUT:
            addDay(fileName, arrayData);
            break;
        case PRINT:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadData(fileName);
            printData(arrayData);
            break;
        case MAX_PROFIT_DAY:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadData(fileName);
            printMaxProfitDay(arrayData,idData);
            break;
        case MAX_HOUR_DAY:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadData(fileName);
            printMaxHourDay(arrayData,idData);
            break;
        case SORT_PROFIT:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadData(fileName);
            maxProfitPrint(arrayData, idData);
            break;
        case SORT_HOUR:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadData(fileName);
            maxPerHourPrint(arrayData, idData);
            break;
        case DELETE_DAY:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadData(fileName);
            deleteDay(arrayData, fileName);
            break;
        case EDIT_DAY:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadData(fileName);
            editDayByID((DATA*) arrayData,fileName);
            break;
        case SEARCH_DAY:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadData(fileName);
            foundID = (DATA*)searchDate(arrayData);
            break;
        case PROGRAM_EXIT:
            choices = exitProgram(arrayData);
            if (choices == 0)
                return 0;
            break;
        default : 
            printf("Invalid selection!\n");
        }
        system("pause");
    }

    free(arrayData);
    arrayData = NULL;

    return choices;
}