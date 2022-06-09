#include "head.h"

//정해진 검색어를 입력하면 해당 검색어에 관한 정보를 얻을 수 있는 프로그램

int main(void)
{
	search_covid();
}


void search_covid()
{
	printf("\n6월 8일 기준                  출처  질병관리청\n\n");
	printf("□□□■■■□□□□□□□□□□□□□□■□□\n");
	printf("□□■□□□■□□□□□□□□□■□□□■□□\n");
	printf("□□■□□□□□□□□□□□□□□□□□■□□\n");
	printf("□□■□□□□□■■■□■□■□■□□■■□□\n");
	printf("□□■□□□■□■□■□■□■□■□■□■□□\n");
	printf("□□□■■■□□■■■□□■□□■□■■■□□\n\n");
	printf("[ search ] ex)도움말 ▷ "); //검색 인터페이스 창

	struct covid_sit list[7] = {//각 지역별로 구조체 배열에 데이터 저장
	{ "경기", 3064, 4943924, 6234 },
	{ "서울", 2619, 3632164, 4845 },
	{ "부산", 815, 1096561, 2150 },
	{ "경남", 746, 1093512, 1250 },
	{ "인천",532, 1075395, 1396 },
	{ "경북",816, 781624, 1375 },
	{ "대구", 990, 763523, 1336 } };

	char search[100];//검색어 입력시 저장할 변수
	char* contents[] = { "지역별 일일확진자","지역별 총 확진자"//저장된 검색어들
		,"지역별 사망자","도움말","종료","검색기록" };//포인터 배열 사용
	int(*pf[3])() = { dayday, total, totaldie };//함수 포인터 배열 사용
	FILE* fp = NULL;//파일 입출력, 검색기록 저장 공간

	gets(search);//검색어 입력

	printf("\n\n");

	for (int i = 0; i < 6; i++)
	{
		//검색한 값이 저장된 검색어 중 같은게 있으면 실행
		if ((strcmp(contents[i], search) == 0))
		{
			//검색기록 이면 스크립트 내의 파일 search_list를 읽어온다
			if (strcmp(search, "검색기록") == 0)
			{
				char line[10000];
				char* pLine;
				fp = fopen("search_list.txt", "r");
				if (fp == NULL)
					exit(1);
				while (!feof(fp))
				{
					pLine = fgets(line, 10000, fp);
					if (pLine == NULL)
						break;
					printf("%s", pLine);
				}
				fclose(fp);
				printf("\n\n\n");
				//이때 Y또는 N을 입력해서 검색어를 초기화할지 말지 결정
				while (1)
				{
					printf("검색기록 초기화 Y / N\n");
					gets(search);
					if (strcmp(search, "Y") == 0)
					{
						printf("검색기록 초기화 중...\n\n\n");
						fp = fopen("search_list.txt", "w");
						if (fp == NULL)
							exit(1);
						fclose(fp);
						return search_covid();
					}
					else if (strcmp(search, "N") == 0)
					{
						printf("\n\n\n");
						return search_covid();
					}
					else
					{
						printf("\nERR(%s) 다시 입력\n\n\n", search);
						continue;
					}
				}
			}
			//종료 라고 입력시 return 0
			else if (strcmp(search, "종료") == 0)
			{
				printf("프로그램을 종료합니다.\n\n");
				return 0;
			}
			//도움말 함수 실행
			else if (strcmp(search, "도움말") == 0)
			{
				help();
				break;
			}
			//일반적으로는 해당 검색어의 함수 실행
			//포인터 함수 배열과 연결지어서
			printf("%s의 검색 결과\n\n\n", search);

			pf[i](list);

			break;
		}

		//반복횟수(0 ~ 5)를 다 채우면 해당 검색어는 저장된 검색어가 아니니까 오류
		else if (i >= 5)
		{
			printf("%s와(과) 일치하는 검색결과가 없습니다.\n\n\n", search);
		}
	}

	//검색어를 입력하고나면 search_list에다가 그 입력값을 계속 저장
	fp = fopen("search_list.txt", "a");
	if (fp == NULL)
		exit(1);
	fputs(search, fp);
	fputs("\n", fp);
	fclose(fp);

	//계속 반복
	return search_covid();
}