#pragma once
#include <stdbool.h>
#include "dataType.h"

extern int idData;

bool isIdUnique(int id,const DATA* arrayData, int size);
bool isValidMoneyInput(const char* input);
bool isValidDateInput(const char* input);


void createFile(const char* const);
void deleteFile(const char* const);
int mainMenu(const char* const);
void addDay(const char* const fileName, const DATA* arrayData);
DATA* loadPrint(const char* const);
void printMaxProfitDay(const DATA* arrayData, int idData);
void printMaxHourDay(const DATA* arrayData, int idData);
int maxProfitSort(const int* a, const int* b);
void maxProfitPrint(const DATA* arrayData, int idData);
int perHourSort(const int* a, const int* b);
void maxPerHourPrint(const DATA* arrayData, int idData);
void editDayByID(const DATA* arrayData, const char* const fileName);
void* searchDate(const DATA* const);
void deleteDay(const DATA* const arrayData, const char* const fileName);
int getIdData(const char* const fileName);
int exitProgram(const DATA*);

