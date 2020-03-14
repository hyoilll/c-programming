#include <stdio.h>

int main()
{
	//3명의 학생, 3과목

	int s[3][3] =
	{
		{90,88,99},
		{94,76,88},
		{89,98,82}
	};
	int* sp[3];
	
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int z = 0;

	char g[3][3][3]; //3명, 3과목, 3글자
	char* gp[3][3];

	double score[3]; //0 : a학생, 1 : b학생, 2 : c학생
	double* scoreP = score;

	double sum = 0;

	//행의 시작 주소 대입
	for (i = 0; i < 3; ++i)
		sp[i] = s[i];

	//면, 행의 시작 주소를 대입
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			gp[i][j] = g[i][j];
		}
	}

	/*
		95 <= score A+
		90 <= score < 95 A0
		85 <= score < 90 B+
		80 <= score < 85 B0
		75 <= score < 80 C+
		70 <= score < 75 C0
		      score < 70 D
	*/

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (*(sp[i] + j) >= 95) strcpy(*(gp[i] + j), "A+");
			else if (*(sp[i] + j) >= 90) strcpy(*(gp[i] + j), "A0");
			else if (*(sp[i] + j) >= 85) strcpy(*(gp[i] + j), "B+");
			else if (*(sp[i] + j) >= 80) strcpy(*(gp[i] + j), "B0");
			else if (*(sp[i] + j) >= 75) strcpy(*(gp[i] + j), "C+");
			else if (*(sp[i] + j) >= 70) strcpy(*(gp[i] + j), "C0");
			else strcpy(gp[i][j], "D");
		}
	}

	for (i = 0; i < 3; ++i)
	{
		sum = 0;
		for (j = 0; j < 3; ++j)
		{
			if (strcmp(*(gp[i] + j), "A+") == 0) sum = sum + 4.5;
			else if (strcmp(*(gp[i] + j), "A0") == 0) sum = sum + 4.0;
			else if (strcmp(*(gp[i] + j), "B+") == 0) sum = sum + 3.5;
			else if (strcmp(*(gp[i] + j), "B0") == 0) sum = sum + 3.0;
			else if (strcmp(*(gp[i] + j), "C+") == 0) sum = sum + 2.5;
			else if (strcmp(*(gp[i] + j), "C0") == 0) sum = sum + 2.0;
			else sum = sum + 1;
		}
		*(scoreP + i) = sum / 3;
	}

	for (i = 0; i < 3; ++i)
	{
		printf("%c학생의 학점 : ", 97 + i);
		for (j = 0; j < 3; ++j)
		{
			printf("%d(%s), ", *(sp[i] + j), *(gp[i] + j));
		}
		printf("\n");
		printf("%c학생의 평점 : %5.2f\n", 97 + i, *(scoreP + i));
	}

	return 0;
}