#include "head.h"

//������ �˻�� �Է��ϸ� �ش� �˻�� ���� ������ ���� �� �ִ� ���α׷�

int main(void)
{
	search_covid();
}


void search_covid()
{
	printf("\n6�� 8�� ����                  ��ó  ��������û\n\n");
	printf("������������������������\n");
	printf("������������������������\n");
	printf("������������������������\n");
	printf("������������������������\n");
	printf("������������������������\n");
	printf("������������������������\n\n");
	printf("[ search ] ex)���� �� "); //�˻� �������̽� â

	struct covid_sit list[7] = {//�� �������� ����ü �迭�� ������ ����
	{ "���", 3064, 4943924, 6234 },
	{ "����", 2619, 3632164, 4845 },
	{ "�λ�", 815, 1096561, 2150 },
	{ "�泲", 746, 1093512, 1250 },
	{ "��õ",532, 1075395, 1396 },
	{ "���",816, 781624, 1375 },
	{ "�뱸", 990, 763523, 1336 } };

	char search[100];//�˻��� �Է½� ������ ����
	char* contents[] = { "������ ����Ȯ����","������ �� Ȯ����"//����� �˻����
		,"������ �����","����","����","�˻����" };//������ �迭 ���
	int(*pf[3])() = { dayday, total, totaldie };//�Լ� ������ �迭 ���
	FILE* fp = NULL;//���� �����, �˻���� ���� ����

	gets(search);//�˻��� �Է�

	printf("\n\n");

	for (int i = 0; i < 6; i++)
	{
		//�˻��� ���� ����� �˻��� �� ������ ������ ����
		if ((strcmp(contents[i], search) == 0))
		{
			//�˻���� �̸� ��ũ��Ʈ ���� ���� search_list�� �о�´�
			if (strcmp(search, "�˻����") == 0)
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
				//�̶� Y�Ǵ� N�� �Է��ؼ� �˻�� �ʱ�ȭ���� ���� ����
				while (1)
				{
					printf("�˻���� �ʱ�ȭ Y / N\n");
					gets(search);
					if (strcmp(search, "Y") == 0)
					{
						printf("�˻���� �ʱ�ȭ ��...\n\n\n");
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
						printf("\nERR(%s) �ٽ� �Է�\n\n\n", search);
						continue;
					}
				}
			}
			//���� ��� �Է½� return 0
			else if (strcmp(search, "����") == 0)
			{
				printf("���α׷��� �����մϴ�.\n\n");
				return 0;
			}
			//���� �Լ� ����
			else if (strcmp(search, "����") == 0)
			{
				help();
				break;
			}
			//�Ϲ������δ� �ش� �˻����� �Լ� ����
			//������ �Լ� �迭�� �������
			printf("%s�� �˻� ���\n\n\n", search);

			pf[i](list);

			break;
		}

		//�ݺ�Ƚ��(0 ~ 5)�� �� ä��� �ش� �˻���� ����� �˻�� �ƴϴϱ� ����
		else if (i >= 5)
		{
			printf("%s��(��) ��ġ�ϴ� �˻������ �����ϴ�.\n\n\n", search);
		}
	}

	//�˻�� �Է��ϰ��� search_list���ٰ� �� �Է°��� ��� ����
	fp = fopen("search_list.txt", "a");
	if (fp == NULL)
		exit(1);
	fputs(search, fp);
	fputs("\n", fp);
	fclose(fp);

	//��� �ݺ�
	return search_covid();
}