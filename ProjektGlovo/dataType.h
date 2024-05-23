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
	input = 1,
	load,
	maxProfitDay,
	maxHourDay,
	sortProfit,
	sortHour,
	delete,
	edit,
	search,
	programExit,
};
