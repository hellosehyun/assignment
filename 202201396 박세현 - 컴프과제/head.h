#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#pragma warning(disable:4996)

void search_covid();
void help();
void dayday();
void total();
void totaldie();

struct covid_sit
{
	char name[100];
	double today_covid;
	double all_covid;
	double death;
};