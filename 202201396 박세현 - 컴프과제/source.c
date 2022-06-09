#include "head.h"

void help()
{
	printf("가능한 검색어 : ");
	printf("지역별 일일확진자, 지역별 총 확진자, 지역별 사망자, 종료, 검색기록\n\n\n");
	return 0;
}


void dayday(struct covid_sit p[])
{
	for (int i = 0; i < 7; i++)
	{
		printf("%s 일일확진자 : %.0lf\n", p[i].name, p[i].today_covid);
	}
	printf("\n\n");
}


void total(struct covid_sit p[])
{
	for (int i = 0; i < 7; i++)
	{
		printf("%s 총 확진자 : %.0lf\n", p[i].name, p[i].all_covid);
	}
	printf("\n\n");
}


void totaldie(struct covid_sit p[])
{
	for (int i = 0; i < 7; i++)
	{
		printf("%s 사망자 : %.0lf\n", p[i].name, p[i].death);
	}
	printf("\n\n");
}