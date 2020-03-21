#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#define StudentNum 20
#define subjectNum 7

int main()
{
	//3명의 학생, 3과목

	int** s;
	char*** g;
	double* d;

	unsigned int i = 0;
	unsigned int j = 0;

	double sum = 0;

	//학생, 과목점수 동적할당
	s = (int**)malloc(StudentNum * sizeof(int*));
	for (i = 0; i < StudentNum; ++i)
	{
		s[i] = (int*)malloc(subjectNum * sizeof(int));
	}

	//학점 동적할당
	g = (char***)malloc(StudentNum * sizeof(char**));
	for (i = 0; i < StudentNum; ++i)
	{
		g[i] = (char**)malloc(subjectNum * sizeof(char*));
		for (j = 0; j < subjectNum; ++j)
		{
			g[i][j] = (char*)malloc(3 * sizeof(char));
		}
	}

	//평균 동적할당
	d = (double*)malloc(StudentNum * sizeof(double));

	/*
		95 <= score A+
		90 <= score < 95 A0
		85 <= score < 90 B+
		80 <= score < 85 B0
		75 <= score < 80 C+
		70 <= score < 75 C0
			  score < 70 D
	*/

	//학생별, 과목별 성적 랜덤 데이터 생성
	srand((unsigned)time(NULL));
	for (i = 0; i < StudentNum; ++i)
	{
		for (j = 0; j < subjectNum; ++j)
		{
			s[i][j] = rand() % 100;
		}
	}

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
		*(d + i) = sum / 3;
	}

	for (i = 0; i < StudentNum; ++i)
	{
		printf("%c학생의 학점 : ", 97 + i);
		for (j = 0; j < subjectNum; ++j)
		{
			printf("%d(%s), ", *(s[i] + j), *(g[i] + j));
		}
		printf("\n");
		printf("%c학생의 평점 : %5.2f\n", 97 + i, *(d + i));
	}

	//메모리해제
	for (i = 0; i < StudentNum; ++i)
	{
		free(s[i]);
	}
	free(s);

	for (i = 0; i < StudentNum; ++i)
	{
		for (j = 0; j < subjectNum; ++j)
		{
			free(g[i][j]);
		}
		free(g[i]);
	}
	free(g);

	free(d);
	return 0;
}