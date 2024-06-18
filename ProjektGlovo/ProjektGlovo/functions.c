#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "dataType.h" 

#define CONFIRMINP 4
#define INPUTLEN 20

int idData = 0;

static bool isIdUnique(int id, DATA* arrayData, int size) {
	for (int i = 0; i < size; i++) {
		if (arrayData[i].id == id) {
			return false;
		}
	}
	return true;
}
static bool isValidMoneyInput(const char* input) {
	int wholeDigits = 0;
	int decimalDigits = 0;
	bool decimalPointEncountered = false;

	for (int i = 0; input[i] != '\0'; i++) {

		if (input[i] >= '0' && input[i] <= '9') {
			if (decimalPointEncountered) {
				decimalDigits++;
			}
			else {
				wholeDigits++;
			}
		}
		else if (input[i] == '.') {
			if (decimalPointEncountered) {

				return false;
			}
			decimalPointEncountered = true;
		}
		else {

			return false;
		}
	}


	return (wholeDigits <= 3 && decimalDigits <= 2);
}
static bool isValidDateInput(const char* input) {
	int day, month, year;
	char format[CONFIRMINP];
	int parsed = sscanf(input, "%d.%d.%d.%3s", &day, &month, &year, format);
	return (parsed == 3 && month >= 1 && month <= 12 && day >= 1 && day <= 31 && year > 2023);
}


void createFile(const char* fileName) {
	FILE* file = fopen(fileName, "rb+");
	if (file == NULL) {
		printf("File %s doesn't exist. Creating file...\n", fileName);
		file = fopen(fileName, "wb");
		if (file == NULL) {
			perror("Error while creating file");
			exit(EXIT_FAILURE);
		}
		int tmp = 0;
		fwrite(&tmp, sizeof(int), 1, file);
		fclose(file);
		printf("File %s successfully created!\n\n", fileName);
	}
	else {
		printf("File %s already exists!\n\n", fileName);
		fclose(file);
	}
}
void addDay(const char* const fileName, DATA* arrayData) {
	printf("Adding day:\n\n");
	bool validInput = false;

	FILE* pF = fopen(fileName, "rb+");

	if (pF == NULL) {
		perror("Adding days to data.bin");
		exit(EXIT_FAILURE);
	}
	printf("Number of added days: %d\n\n", idData);
	DATA temp = { 0 };
	do {
		temp.id = rand() % 1000;
	} while (!isIdUnique(temp.id, arrayData, idData));
	getchar();
	while (!validInput) {
		printf("Money earned on the day(Eur): ");
		char moneyInput[INPUTLEN];
		scanf("%6s", moneyInput);
		if (isValidMoneyInput(moneyInput)) {
			temp.earned = strtof(moneyInput, NULL);
			validInput = true;
		}
		else {
			printf("Invalid input. Please enter a valid number with maximum 3 digits and 2 decimal places.\n");
			while (getchar() != '\n');
		}
	}
	validInput = false;
	while (!validInput) {
		printf("Money spent on the day (Eur): ");
		char moneyInput[INPUTLEN];
		scanf("%6s", moneyInput);
		if (isValidMoneyInput(moneyInput)) {
			temp.spent = strtof(moneyInput, NULL);
			validInput = true;
		}
		else {
			printf("Invalid input. Please enter a valid number with maximum 3 digits and 2 decimal places.\n");
			while (getchar() != '\n');
		}
	}
	validInput = false;
	while (!validInput) {
		printf("Enter new date (DD.MM.YYYY): ");
		if (scanf("%11s", temp.date) == 1 && isValidDateInput(temp.date)) {
			if (temp.date[strlen(temp.date) - 1] != '.') {
					strcat(temp.date, ".");
			}
			validInput = 1;
		}
		else {
			printf("Invalid date format. Please enter date in the format DD.MM.YYYY.\n");
			while (getchar() != '\n');
		}
	}
	validInput = false;
	while (!validInput) {
		printf("Hours worked (Max 12hrs): ");
		if (scanf("%d", &temp.workHours) == 1 && temp.workHours >= 1 && temp.workHours <= 12) {
			validInput = true;
		}
		else {
			printf("Invalid input. Please enter a valid number(1 to 12).\n");
			while (getchar() != '\n');
		}
	}
	fread(&idData, sizeof(int), 1, pF);
	fseek(pF, sizeof(DATA) * idData, SEEK_CUR);
	fwrite(&temp, sizeof(DATA), 1, pF);
	rewind(pF);
	idData++;
	fwrite(&idData, sizeof(int), 1, pF);
	fclose(pF);
	printf("\n");
	printf("Data successfully added!\n\n");
} 
DATA* loadData(const char* const fileName){
		FILE* pF = fopen(fileName, "rb+");
	if (pF == NULL) {
		perror("Loading data from data.bin!");
		return NULL;
	}

	fread(&idData, sizeof(int), 1, pF);
	printf("Number of days added: %d\n\n", idData);
	DATA* arrayData = (DATA*)calloc(idData, sizeof(DATA));
	if (arrayData == NULL) {
		perror("Allocating memory for data");
		return NULL;
	}

	fread(arrayData, sizeof(DATA), idData, pF);
	if (arrayData == NULL) {
		printf("Array of Data is empty!\n");
		return 0;
	}
	return arrayData;
}
DATA* printData(const DATA* const arrayData) {
	printf("Loading data...\n\n");
	int i;
	for (i = 0; i < idData; i++) {
		float dailyProfit = arrayData[i].earned - arrayData[i].spent;
		float perHour = arrayData[i].earned / arrayData[i].workHours;
		printf("%d.\nID: %d\nEarned: %.2f Eur\nSpent: %.2f Eur\nDaily Profit: %.2f Eur\nEarned per Hour: %.2f Eur\nDate: %s\nWork hours: %d\n\n",
			i + 1,
			arrayData[i].id,
			arrayData[i].earned,
			arrayData[i].spent,
			dailyProfit,
			perHour,
			arrayData[i].date,
			arrayData[i].workHours);
	}
	printf("Successfully loaded!\n");
}
void printMaxProfitDay(DATA* arrayData, int idData) {
	
	if (idData <= 0) {
		printf("No data available.\n");
		return;
	}


	int maxProfitIndex = 0;
	float maxProfit = arrayData[0].earned - arrayData[0].spent;
	for (int i = 1; i < idData; i++) {
		float profit = arrayData[i].earned - arrayData[i].spent;
		if (profit > maxProfit) {
			maxProfit = profit;
			maxProfitIndex = i;
		}
	}
	printf("Day with maximum profit:\n\n");
	printf("ID: %d\n", arrayData[maxProfitIndex].id);
	printf("Earned: %.2f Eur\n", arrayData[maxProfitIndex].earned);
	printf("Spent: %.2f Eur\n", arrayData[maxProfitIndex].spent);
	printf("Date: %s\n", arrayData[maxProfitIndex].date);
	printf("Work hours: %d\n", arrayData[maxProfitIndex].workHours);
	printf("Earned per hour: %.2f\n", arrayData[maxProfitIndex].earned / arrayData[maxProfitIndex].workHours);
	printf("Profit: %.2f Eur\n\n", maxProfit);
	printf("Successfully loaded!\n");
}
void printMaxHourDay(DATA* arrayData, int idData) {
	if (idData <= 0) {
		printf("No data available.\n");
		return;
	}


	int bestHourlyIndex = 0;
	float bestHourlyRate = arrayData[0].earned/ arrayData[0].workHours;
	for (int i = 1; i < idData; i++) {
		float hourlyRate = arrayData[i].earned/ arrayData[i].workHours;
		if (hourlyRate > bestHourlyRate) {
			bestHourlyRate = hourlyRate;
			bestHourlyIndex = i;
		}
	}

	printf("Day with best hourly earning rate:\n\n");
	printf("ID: %d\n", arrayData[bestHourlyIndex].id);
	printf("Earned: %.2f Eur\n", arrayData[bestHourlyIndex].earned);
	printf("Spent: %.2f Eur\n", arrayData[bestHourlyIndex].spent);
	printf("Date: %s\n", arrayData[bestHourlyIndex].date);
	printf("Work hours: %d\n", arrayData[bestHourlyIndex].workHours);
	printf("Profit: %.2f\n", arrayData[bestHourlyIndex].earned - arrayData[bestHourlyIndex].spent);
	printf("Earned per hour: %.2f Eur\n\n", bestHourlyRate);
	printf("Successuflly loaded!\n");
}
static inline int maxProfitSort(const int* a, const int* b) {
	const DATA* dataA = (const DATA*)a;
	const DATA* dataB = (const DATA*)b;
	float profitA = dataA->earned - dataA->spent;
	float profitB = dataB->earned - dataB->spent;

	if (profitA < profitB) return 1;
	if (profitA > profitB) return -1;
	return 0;
}
void maxProfitPrint(DATA* arrayData, int idData) {
	if (idData <= 0) {
		printf("No data available.\n");
		return;
	}
	qsort(arrayData, idData, sizeof(DATA), maxProfitSort);

	printf("Sorted data by max profit:\n");
	for (int i = 0; i < idData; i++) {
		float profit = arrayData[i].earned - arrayData[i].spent;
		float perHour = arrayData[i].earned / arrayData[i].workHours;
		printf("%d.\nID: %d\nEarned: %.2f Eur\nSpent: %.2f Eur\nDate: %s\nWork hours: %d\nProfit: %.2f Eur\nProfit per Hour: %.2f Eur\n",
			i + 1, arrayData[i].id, arrayData[i].earned, arrayData[i].spent,
			arrayData[i].date, arrayData[i].workHours, profit, perHour);
		printf("\n");
	}
	printf("Succesfully sorted!\n");
}
static inline int perHourSort(const int* a, const int* b) {
	const DATA* dataA = (const DATA*)a;
	const DATA* dataB = (const DATA*)b;
	float hourA = dataA->earned / dataA->workHours;
	float hourB = dataB->earned / dataB->workHours;

	if (hourA < hourB) return 1;
	if (hourA > hourB) return -1;
	return 0;
}
void maxPerHourPrint(DATA* arrayData, int idData) {
	if (idData <= 0) {
		printf("No data available.\n");
		return;
	}

	qsort(arrayData, idData, sizeof(DATA), perHourSort);

	printf("Sorted data by max profit:\n");
	for (int i = 0; i < idData; i++) {
		float profit = arrayData[i].earned - arrayData[i].spent;
		float perHour = arrayData[i].earned / arrayData[i].workHours;
		printf("%d.\nID: %d\nEarned: %.2f Eur\nSpent: %.2f Eur\nDate: %s\nWork hours: %d\nProfit: %.2f Eur\nHourly earnings: %.2f Eur\n",
			i + 1, arrayData[i].id, arrayData[i].earned, arrayData[i].spent,
			arrayData[i].date, arrayData[i].workHours, profit, perHour);
		printf("\n");
	}
	printf("Succesfully sorted!\n");
}
void editDayByID(DATA* arrayData, const char* const fileName) {
	FILE* pF = fopen(fileName, "rb+");
	if (pF == NULL) {
		perror("Editing day in data.bin");
		exit(EXIT_FAILURE);
	}
	if (idData <= 0) {
		printf("No data available.\n");
		return;
	}
	fseek(pF, sizeof(int), SEEK_SET); // Skip the ID count
	int editID;
	printf("Enter the ID of the day you want to edit: ");
	scanf("%d", &editID);

	int foundIndex = -1;
	for (int i = 0; i < idData; i++) {
		if (arrayData[i].id == editID) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex == -1) {
		printf("Day with ID %d not found!\n", editID);
		fclose(pF);
		return;
	}

	printf("Editing day with ID %d\n", editID);
	DATA editedDay = arrayData[foundIndex];
	bool validInput = false;


	while (!validInput) {
		printf("Enter new earned amount: ");
		char moneyInput[INPUTLEN];
		scanf("%19s", moneyInput);
		if (isValidMoneyInput(moneyInput)) {
			editedDay.earned = strtof(moneyInput, NULL);
			validInput = true;
		}
		else {
			printf("Invalid input. Please enter a valid number with maximum 3 digits and 2 decimal places.\n");
			while (getchar() != '\n'); 
		}
	}

	validInput = false;

	while (!validInput) {
		printf("Enter new spent amount: ");
		char moneyInput[INPUTLEN];
		scanf("%19s", moneyInput);
		if (isValidMoneyInput(moneyInput)) {
			editedDay.spent = strtof(moneyInput, NULL);
			validInput = true;
		}
		else {
			printf("Invalid input. Please enter a valid number with maximum 3 digits and 2 decimal places.\n");
			while (getchar() != '\n'); 
		}
	}

	validInput = false;

	while (!validInput) {
		printf("Enter new date (DD.MM.YYYY): ");
		if (scanf("%11s", editedDay.date) == 1 && isValidDateInput(editedDay.date)) {
	
			if (editedDay.date[strlen(editedDay.date) - 1] != '.') {
		
				strcat(editedDay.date, ".");
			}
			validInput = true;
		}
		else {
			printf("Invalid date format. Please enter date in the format DD.MM.YYYY.\n");
			while (getchar() != '\n'); 
		}
	}

	validInput = false;

	while (!validInput) {
		printf("Enter new work hours (Max 12hrs): ");
		if (scanf("%d", &editedDay.workHours) == 1 && editedDay.workHours > 0 && editedDay.workHours <= 12) {
			validInput = true;
		}
		else {
			printf("Invalid input. Please enter a valid number of hours (0 to 12).\n");
			while (getchar() != '\n'); 
		}
	}

	fseek(pF, sizeof(int) + foundIndex * sizeof(DATA), SEEK_SET);
	fwrite(&editedDay, sizeof(DATA), 1, pF);
	fclose(pF);
	printf("Day with ID %d has been successfully edited!\n", editID);
}
void* searchDate(DATA* const arrayData) {
	if (idData <= 0) {
		printf("No data available.\n");
		return;
	}

	if (arrayData == NULL) {
		printf("Array of data is empty, please load data if you have any!\n");
		return NULL;
	}
	int searchID;
	printf("Input ID of the day you want to print out:  ");
	scanf("%d", &searchID);
	for (int i = 0; i < idData; i++) {
		float dailyProfit = arrayData[i].earned - arrayData[i].spent;
		float perHour = arrayData[i].earned / arrayData[i].workHours;
		if (arrayData[i].id == searchID) {
			printf("Day is found!\n");
			printf("ID: %d\n", arrayData[i].id);
			printf("Earned: %.2f Eur\n", arrayData[i].earned);
			printf("Spent: %.2f Eur\n", arrayData[i].spent);
			printf("Profit: %.2f\n", dailyProfit);
			printf("Earned per hour: %.2f\n", perHour);
			printf("Date: %s\n", arrayData[i].date);
			printf("Work hours: %d\n", arrayData[i].workHours);
			return (DATA*)&arrayData[i];
		}
	}

	printf("No day with matching ID was found! %d\n", searchID);
	return NULL;
}
void deleteDay(DATA* arrayData, const char* const fileName) {
	if (idData <= 0) {
		printf("No data available.\n");
		return;
	}
	int deleteID;
	char confirm[CONFIRMINP];
	bool found = false;

	printf("Enter the ID of the day you want to delete: ");

	while (scanf("%d", &deleteID) != 1 || deleteID <= -1) {
		printf("Invalid input. Please enter a valid ID: ");
		while (getchar() != '\n');
	}


	for (int i = 0; i < idData; i++) {
		if (arrayData[i].id == deleteID) {
			found = true;
			break;
		}
	}

	if (!found) {
		printf("Day with ID %d does not exist.\n", deleteID);
		return;
	}


	while (1) {
		printf("Are you sure you want to delete the selected day? Type \"yes\" to confirm or \"no\" to cancel: ");
		scanf("%3s", confirm);
		if (strcmp("yes", confirm) == 0) {
			break;
		}
		else if (strcmp("no", confirm) == 0) {
			printf("Deletion cancelled. Returning to main menu.\n");
			return;
		}
		else {
			printf("Invalid input. Please type \"yes\" or \"no\".\n");
		}
	}
	FILE* pF = fopen(fileName, "rb+");
	if (pF == NULL) {
		perror("Deleting day from data.bin");
		exit(EXIT_FAILURE);
	}

	fseek(pF, sizeof(int), SEEK_SET);

	int newIdCounter = 0;
	for (int i = 0; i < idData; i++) {
		if (arrayData[i].id == deleteID) {
			continue;
		}
		fwrite(&arrayData[i], sizeof(DATA), 1, pF);
		newIdCounter++;
	}

	rewind(pF);
	fwrite(&newIdCounter, sizeof(int), 1, pF); // Update the ID count
	fclose(pF);
	printf("Day with ID %d has been successfully deleted!\n", deleteID);
}
int exitProgram(DATA* arrayData) {
	char confirm[CONFIRMINP];
	while (1) {
		printf("Do you really want to exit the file?\n");
		printf("Type \"yes\" if you really want to exit the file, otherwise type \"no\"!\n");
		if (scanf("%3s", confirm) == 1) { 

			while (getchar() != '\n');

			if (strcmp("yes", confirm) == 0) {
				if (arrayData != NULL) {
					free(arrayData);
					arrayData = NULL;
				}
				return 0;
			}
			else if (strcmp("no", confirm) == 0) {
				return 1;
			}
			else {
				printf("Invalid input. Please type \"yes\" or \"no\".\n");
			}
		}
		else {
			printf("Invalid input. Please type \"yes\" or \"no\".\n");

			while (getchar() != '\n');
		}
	}
}


//int exitProgram(DATA* arrayData) {
//	char confirm[CONFIRMINP];
//	while (1) {
//		printf("Do you really want to exit the file?\n");
//		printf("Type \"yes\" if you really want to exit the file, otherwise type \"no\"!\n");
//		if (scanf("%3s", confirm) == 1) {
//
//			while (getchar() != '\n');
//
//			if (strcmp("yes", confirm) == 0) {
//				if (arrayData != NULL) {
//					free(arrayData);
//					arrayData = NULL;
//				}
//				return 0;
//			}
//			else if (strcmp("no", confirm) == 0) {
//				return 1;
//			}
//			else {
//				printf("Invalid input. Please type \"yes\" or \"no\".\n");
//			}
//		}
//		else {
//			printf("Invalid input. Please type \"yes\" or \"no\".\n");
//
//			while (getchar() != '\n');
//		}
//	}
//}
