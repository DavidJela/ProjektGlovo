#pragma once
#include <stdbool.h>
#include "dataType.h"

extern int idData;

bool isIdUnique(int id,const DATA* arrayData, int size);
bool isValidMoneyInput(const char* input);
bool isValidDateInput(const char* input);
void createFile(const char* const);
int mainMenu(const char* const);
void addDay(const char* const fileName, const DATA* arrayData);
void* loadPrint(const char* const);
void printMaxProfitDay(const DATA* arrayData, int idData);
void printMaxHourDay(const DATA* arrayData, int idData);
int maxProfit(const void* a, const void* b);
void maxProfitPrint(const DATA* arrayData, int idData);
int perHour(const void* a, const void* b);
void maxPerHour(const DATA* arrayData, int idData);
void editDayByID(const DATA* arrayData, const char* const fileName);
void* searchDate(const DATA* const);
void deleteDay(const DATA* const arrayData, const char* const fileName);
int exitProgram(const DATA*);


//void date(char* date);