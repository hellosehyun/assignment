#include "head.h"

void help()
{
	printf("������ �˻��� : ");
	printf("������ ����Ȯ����, ������ �� Ȯ����, ������ �����, ����, �˻����\n\n\n");
	return 0;
}


void dayday(struct covid_sit p[])
{
	for (int i = 0; i < 7; i++)
	{
		printf("%s ����Ȯ���� : %.0lf\n", p[i].name, p[i].today_covid);
	}
	printf("\n\n");
}


void total(struct covid_sit p[])
{
	for (int i = 0; i < 7; i++)
	{
		printf("%s �� Ȯ���� : %.0lf\n", p[i].name, p[i].all_covid);
	}
	printf("\n\n");
}


void totaldie(struct covid_sit p[])
{
	for (int i = 0; i < 7; i++)
	{
		printf("%s ����� : %.0lf\n", p[i].name, p[i].death);
	}
	printf("\n\n");
}