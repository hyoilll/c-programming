#pragma warning(disable: 4996)

#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

//함수 원형 선언

//1차원 동적할당
double* Mal1Double(int);
int* Mal1Int(int);

//2차원 동적할당
int** Mal2Int(int, int);
char** Mal2char(int, int);

//3차원 동적할당
char*** Mal3char(int, int, int);

//동적할당 해제 함수
void Free1Double(double*);
void Free2Int(int**, int);
void Free3Char(char***, int, int);
void Free2Char(char**, int);
void Free1Int(int*);

//성적 입력 함수
void score_input(char*, char**, char**, int**, int, int);

//학점 계산 함수
void score_credit(int**, char***, int, int);

//평점 계산 함수
void score_grade(char***, double*, int, int);

//성적 출력 함수
void score_output(char*, char**, char**, int**, char***, double*, int*, int, int);

//평점 정렬 함수
void score_sort(double*, int*, int);

int main()
{
	int** s;
	char*** g;
	double* d;

	char** name; //이름
	char** id; //학번
	int* rank; //등수

	int studentNum = 23;
	int subjectNum = 7;

	//동적 할당
	s = Mal2Int(studentNum, subjectNum);
	g = Mal3char(studentNum, subjectNum, 3);
	d = Mal1Double(studentNum);

	name = Mal2char(studentNum, 20);
	id = Mal2char(studentNum, 20);
	rank = Mal1Int(studentNum);

	//성적 랜덤 데이터 입력
	score_input("score.txt", name, id, s, studentNum, subjectNum);

	//학점 계산
	score_credit(s, g, studentNum, subjectNum);

	//평점 계산
	score_grade(g, d, studentNum, subjectNum);

	//평점 정렬
	score_sort(d, rank, studentNum);

	//성적 출력
	score_output("output.txt", name, id, s, g, d, rank, studentNum, subjectNum);

	//동적할당 해제
	Free1Double(d);
	Free2Int(s, studentNum);
	Free3Char(g, studentNum, subjectNum);
	Free2Char(name, subjectNum);
	Free2Char(id, subjectNum);

	return 0;
}

void score_sort(double* d, int* rank, int studentNum)
{
	unsigned int i, j;

	//정렬
	for (i = 0; i < studentNum; ++i)
	{
		for (j = 0; j < studentNum - 1 - i; ++j)
		{
			if (d[j] < d[j + 1])
			{
				double temp = d[j];
				d[j] = d[j + 1];
				d[j + 1] = temp;
			}
		}
	}

	//등수
	for (i = 0; i < studentNum; ++i)
	{
		if (i != 0)
		{
			if (d[i - 1] == d[i])
			{
				rank[i] = rank[i - 1];
			}
			else
			{
				rank[i] = i + 1;
			}
		}
		else
		{
			rank[i] = i + 1;
		}
	}
}

void score_input(char* fn, char** name, char** id, int** s, int studentNum, int subjectNum)
{
	FILE* fp;
	unsigned int j = 0;
	unsigned int i = 0;

	fp = fopen(fn, "r");

	if (fp == NULL)
	{
		perror("error fopen");
		return;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%s %s", name[i], id[i]);
		for (j = 0; j < subjectNum; ++j)
		{
			fscanf(fp, "%d", &s[i][j]);
		}
		i++;
	}

	fclose(fp);
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

void score_output(char* fn, char** name, char** id, int** s, char*** g, double* d, int* rank, int StudentNum, int subjectNum)
{
	FILE* fp;
	unsigned int i, j;

	fp = fopen(fn, "w");

	if (fp == NULL)
	{
		perror("error fopen");
		return;
	}

	for (i = 0; i < StudentNum; ++i)
	{
		fprintf(fp, "%s %s ", name[i], id[i]);
		for (j = 0; j < subjectNum; ++j)
		{
			fprintf(fp, "%d(%s), ", *(s[i] + j), *(g[i] + j));
		}
		fprintf(fp, "\n");
		fprintf(fp, "%s학생의 평점 : %5.2f %d등\n", name[i], *(d + i), rank[i]);
	}

	fclose(fp);
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

int* Mal1Int(int studentNum)
{
	int* i;

	i = (int*)malloc(studentNum * sizeof(int));

	if (i == NULL)
	{
		printf("\7 2-D Memory Allocation Error");
		exit(0);
	}

	return i;
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

char** Mal2char(int studentNum, int size)
{
	char** buf;
	unsigned int i = 0;

	buf = (char**)malloc(studentNum * sizeof(char*));
	for (i = 0; i < studentNum; ++i)
	{
		buf[i] = (char*)malloc(size * sizeof(char));
		if (buf[i] == NULL)
		{
			printf("\7 2-D Memory Allocation Error");
			exit(0);
		}
	}

	return buf;
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

void Free1Int(int* i)
{
	free(i);
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

void Free2Char(char** c, int studentNum)
{
	unsigned int i = 0;

	for (i = 0; i < studentNum; ++i)
	{
		free(c[i]);
	}
	free(c);
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