#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "functions.h"
int mainMenu(const char* const fileName) {
    int choice = 0;
    static DATA* arrayData = NULL;
    static DATA* foundID = NULL;

    while (1) {
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

        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            if (arrayData == NULL) {
                printf("Please load data first before adding a new day.\n");
                break;
            }
            addDay(fileName, arrayData);
            break;
        case 2:
            if (arrayData != NULL) {
                free(arrayData);
                arrayData = NULL;
            }
            arrayData = (DATA*)loadPrint(fileName);
            if (arrayData == NULL) {
                exit(EXIT_FAILURE);
            }
            break;
        case 3:
            if (arrayData == NULL) {
                printf("Please load data first before working with file!\n");
                break;
            }
            printMaxProfitDay(arrayData,idData);
            break;
        case 4:
            if (arrayData == NULL) {
                printf("Please load data first before working with file!\n");
                break;
            }
            printMaxHourDay(arrayData,idData);
            break;
        case 5:
            if (arrayData == NULL) {
                printf("Please load data first before working with file!\n");
                break;
            }
            maxProfitPrint(arrayData, idData);
            break;
        case 6:
            if (arrayData == NULL) {
                printf("Please load data first before working with file!\n");
                break;
            }
            maxPerHour(arrayData, idData);
            break;
        case 7:
            if (arrayData == NULL) {
                printf("Please load data first before working with file!\n");
                break;
            }
            deleteDay(arrayData, fileName);
            break;
        case 8:
            if (arrayData == NULL) {
                printf("Please load data first before working with file!\n");
                break;
            }
            editDayByID((DATA*) arrayData,fileName);
            break;
        case 9:
            if (arrayData == NULL) {
                printf("Please load data first before working with file!\n");
                break;
            }
            foundID = (DATA*)searchDate(arrayData);
            break;
        case 10:
            choice = exitProgram(arrayData);
            if (choice == 0)
                return 0;
            break;
        default : 
            printf("Invalid selection!\n");
        }
    }

    return choice;
}