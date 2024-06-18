#pragma once

#define DATE_LENGHT	11

typedef struct data{
	char date[DATE_LENGHT];
	float earned;
	float spent;
	int id;
	int workHours;
}DATA;

enum choice {
	INPUT = 1,
	PRINT,
	MAX_PROFIT_DAY,
	MAX_HOUR_DAY,
	SORT_PROFIT,
	SORT_HOUR,
	DELETE_DAY,
	EDIT_DAY,
	SEARCH_DAY,
	PROGRAM_EXIT,
};
