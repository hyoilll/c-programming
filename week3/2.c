#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

//�Լ� ���� ����

//1���� �����Ҵ�
double* Mal1Double(int);

//2���� �����Ҵ�
int** Mal2Int(int, int);

//3���� �����Ҵ�
char*** Mal3char(int, int, int);

//�����Ҵ� ���� �Լ�
void Free1Double(double*);
void Free2Int(int**, int);
void Free3Char(char***, int, int);

//���� �Է� �Լ�
void score_input(int**, int, int);

//���� ��� �Լ�
void score_credit(int**, char***, int, int);

//���� ��� �Լ�
void score_grade(char***, double*, int, int);

//���� ��� �Լ�
void score_output(int**, char***, double*, int, int);

int main()
{
	int** s;
	char*** g;
	double* d;

	int studentNum = 20;
	int subjectNum = 7;

	//���� �Ҵ�
	s = Mal2Int(studentNum, subjectNum);
	g = Mal3char(studentNum, subjectNum, 3);
	d = Mal1Double(studentNum);

	//���� ���� ������ �Է�
	score_input(s, studentNum, subjectNum);

	//���� ���
	score_credit(s, g, studentNum, subjectNum);

	//���� ���
	score_grade(g, d, studentNum, subjectNum);
	
	//���� ���
	score_output(s, g, d, studentNum, subjectNum);

	//�����Ҵ� ����
	Free1Double(d);
	Free2Int(s, studentNum);
	Free3Char(g, studentNum, subjectNum);

	return 0;
}

void score_input(int** s, int studentNum, int subjectNum)
{
	unsigned int i, j;

	srand((unsigned)time(NULL));
	for (i = 0; i < studentNum; ++i)
	{
		for (j = 0; j < subjectNum; ++j)
		{
			s[i][j] = rand() % 100;
		}
	}
}

void score_credit(int** s, char*** g, int StudentNum, int subjectNum)
{
	unsigned int i, j;

	for (i = 0; i < StudentNum; ++i)
	{
		for (j = 0; j < subjectNum; ++j)
		{
			if (*(s[i] + j) >= 95) strcpy(*(g[i] + j), "A+");
			else if (*(s[i] + j) >= 90) strcpy(*(g[i] + j), "A0");
			else if (*(s[i] + j) >= 85) strcpy(*(g[i] + j), "B+");
			else if (*(s[i] + j) >= 80) strcpy(*(g[i] + j), "B0");
			else if (*(s[i] + j) >= 75) strcpy(*(g[i] + j), "C+");
			else if (*(s[i] + j) >= 70) strcpy(*(g[i] + j), "C0");
			else strcpy(g[i][j], "D");
		}
	}
}

void score_grade(char*** g, double* d, int StudentNum, int subjectNum)
{
	unsigned int i, j;
	double sum;

	for (i = 0; i < StudentNum; ++i)
	{
		sum = 0;
		for (j = 0; j < subjectNum; ++j)
		{
			if (strcmp(*(g[i] + j), "A+") == 0) sum = sum + 4.5;
			else if (strcmp(*(g[i] + j), "A0") == 0) sum = sum + 4.0;
			else if (strcmp(*(g[i] + j), "B+") == 0) sum = sum + 3.5;
			else if (strcmp(*(g[i] + j), "B0") == 0) sum = sum + 3.0;
			else if (strcmp(*(g[i] + j), "C+") == 0) sum = sum + 2.5;
			else if (strcmp(*(g[i] + j), "C0") == 0) sum = sum + 2.0;
			else sum = sum + 1;
		}
		*(d + i) = sum / subjectNum;
	}
}

void score_output(int** s, char*** g, double* d, int StudentNum, int subjectNum)
{
	unsigned int i, j;

	for (i = 0; i < StudentNum; ++i)
	{
		printf("%c�л��� ���� : ", 97 + i);
		for (j = 0; j < subjectNum; ++j)
		{
			printf("%d(%s), ", *(s[i] + j), *(g[i] + j));
		}
		printf("\n");
		printf("%c�л��� ���� : %5.2f\n", 97 + i, *(d + i));
	}
}

double* Mal1Double(int studentNum)
{
	double* d;

	d = (double*)malloc(studentNum * sizeof(double));

	if (d == NULL)
	{
		printf("\7 2-D Memory Allocation Error");
		exit(0);
	}

	return d;
}

int** Mal2Int(int studentNum, int subjectNum)
{
	int** s;
	unsigned int i = 0;

	s = (int**)malloc(studentNum * sizeof(int*));
	
	if (s == NULL)
	{
		printf("\7 2-D Memory Allocation Error");
		exit(0);
	}

	for (i = 0; i < studentNum; ++i)
	{
		s[i] = (int*)malloc(subjectNum * sizeof(int));
		if (s[i] == NULL)
		{
			printf("\7 2-D Memory Allocation Error");
			exit(0);
		}
	}

	return s;
}

char*** Mal3char(int studentNum, int subjectNum, int size)
{
	char*** g;
	unsigned int i = 0;
	unsigned int j = 0;

	g = (char***)malloc(studentNum * sizeof(char**));
	if (g == NULL)
	{
		printf("\7 3-D Memory Allocation Error");
		exit(0);
	}
	for (i = 0; i < studentNum; ++i)
	{
		g[i] = (char**)malloc(subjectNum * sizeof(char*));
		if (g[i] == NULL)
		{
			printf("\7 2-D Memory Allocation Error");
			exit(0);
		}
		for (j = 0; j < subjectNum; ++j)
		{
			g[i][j] = (char*)malloc(3 * sizeof(char));
			if (g[i][j] == NULL)
			{
				printf("\7 1-D Memory Allocation Error");
				exit(0);
			}
		}
	}

	return g;
}

void Free1Double(double* d)
{
	free(d);
}

void Free2Int(int** s, int studentNum)
{
	unsigned int i = 0;

	for (i = 0; i < studentNum; ++i)
	{
		free(s[i]);
	}
	free(s);
}

void Free3Char(char*** g, int studentNum, int subjectNum)
{
	unsigned int i = 0;
	unsigned int j = 0;

	for (i = 0; i < studentNum; ++i)
	{
		for (j = 0; j < subjectNum; ++j)
		{
			free(g[i][j]);
		}
		free(g[i]);
	}
	free(g);
}