#pragma warning(disable: 4996)

#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

//구조체 선언
struct Student
{
	int s[7];			//과목 수
	char g[7][3];		//학점
	char name[20];		//이름
	char id[20];		//학번

	int rank;		//등수
	double d;		//평균
};

//함수 원형 선언

//1차원 동적할당
double* Mal1Double(int);
int* Mal1Int(int);
struct Student* Mal1Student(int);
char* Mal1Char(int);

//2차원 동적할당
int** Mal2Int(int, int);
char** Mal2Char(int, int);

//3차원 동적할당
char*** Mal3char(int, int, int);

//동적할당 해제 함수
void Free1Double(double*);
void Free2Int(int**, int);
void Free3Char(char***, int, int);
void Free2Char(char**, int);
void Free1Char(char*);
void Free1Int(int*);
void FreeStudent(struct Student*, int);


//성적 입력 함수
void score_input(char*, struct Student*, int, int);

//학점 계산 함수
void score_credit(struct Student*, int, int);

//평점 계산 함수
void score_grade(struct Student*, int, int);

//성적 출력 함수
void score_output(char*, struct Student*, int, int);

//평점 정렬 함수
void score_sort(struct Student*, int);

int main()
{
	struct Student* s;

	int studentNum = 23;
	int subjectNum = 7;

	//동적 할당
	s = Mal1Student(studentNum);

	//성적 랜덤 데이터 입력
	score_input("score.txt", s, studentNum, subjectNum);

	//학점 계산
	score_credit(s, studentNum, subjectNum);

	//평점 계산
	score_grade(s, studentNum, subjectNum);

	//평점 정렬
	score_sort(s, studentNum);

	//성적 출력
	score_output("output.txt", s, studentNum, subjectNum);

	//동적할당 해제
	FreeStudent(s);

	return 0;
}

void score_sort(struct Student* s, int studentNum)
{
	unsigned int i, j;

	//정렬
	for (i = 0; i < studentNum; ++i)
	{
		for (j = 0; j < studentNum - 1 - i; ++j)
		{
			if (s[j].d < s[j + 1].d)
			{
				struct Student temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}

	//등수
	for (i = 0; i < studentNum; ++i)
	{
		if (i != 0)
		{
			if (s[i - 1].d == s[i].d)
			{
				s[i].rank = s[i - 1].rank;
			}
			else
			{
				s[i].rank = i + 1;
			}
		}
		else
		{
			s[i].rank = i + 1;
		}
	}
}

void score_input(char* fn, struct Student* s, int studentNum, int subjectNum)
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
		fscanf(fp, "%s %s", s[i].name, s[i].id);
		for (j = 0; j < subjectNum; ++j)
		{
			fscanf(fp, "%d", &s[i].s[j]);
		}
		i++;
	}

	fclose(fp);
}

void score_credit(struct Student* s, int StudentNum, int subjectNum)
{
	unsigned int i, j;

	for (i = 0; i < StudentNum; ++i)
	{
		for (j = 0; j < subjectNum; ++j)
		{
			if (*(s[i].s + j) >= 95) strcpy(*(s[i].g + j), "A+");
			else if (*(s[i].s + j) >= 90) strcpy(*(s[i].g + j), "A0");
			else if (*(s[i].s + j) >= 85) strcpy(*(s[i].g + j), "B+");
			else if (*(s[i].s + j) >= 80) strcpy(*(s[i].g + j), "B0");
			else if (*(s[i].s + j) >= 75) strcpy(*(s[i].g + j), "C+");
			else if (*(s[i].s + j) >= 70) strcpy(*(s[i].g + j), "C0");
			else strcpy(s[i].g + j, "D");
		}
	}
}

void score_grade(struct Student* s, int StudentNum, int subjectNum)
{
	unsigned int i, j;
	double sum;

	for (i = 0; i < StudentNum; ++i)
	{
		sum = 0;
		for (j = 0; j < subjectNum; ++j)
		{
			if (strcmp(*(s[i].g + j), "A+") == 0) sum = sum + 4.5;
			else if (strcmp(*(s[i].g + j), "A0") == 0) sum = sum + 4.0;
			else if (strcmp(*(s[i].g + j), "B+") == 0) sum = sum + 3.5;
			else if (strcmp(*(s[i].g + j), "B0") == 0) sum = sum + 3.0;
			else if (strcmp(*(s[i].g + j), "C+") == 0) sum = sum + 2.5;
			else if (strcmp(*(s[i].g + j), "C0") == 0) sum = sum + 2.0;
			else sum = sum + 1;
		}
		s[i].d = sum / subjectNum;
	}
}

void score_output(char* fn, struct Student* s, int StudentNum, int subjectNum)
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
		fprintf(fp, "%s %s ", s[i].name, s[i].id);
		for (j = 0; j < subjectNum; ++j)
		{
			fprintf(fp, "%d(%s), ", *(s[i].s + j), *(s[i].g + j));
		}
		fprintf(fp, "\n");
		fprintf(fp, "%s학생의 평점 : %5.2f %d등\n", s[i].name, s[i].d, s[i].rank);
	}

	fclose(fp);
}

char* Mal1Char(int length)
{
	char *c;

	c = (char*)malloc(length * sizeof(char));

	if (c == NULL)
	{
		printf("Memory Allocation error");
		exit(0);
	}

	return c;
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

struct Student* Mal1Student(int studentNum)
{
	struct Student* temp;

	temp = (struct Student*)malloc(studentNum * sizeof(struct Student));

	if (temp == NULL)
	{
		printf("Memory Allocation Error");
		exit(0);
	}

	return temp;
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

char** Mal2Char(int studentNum, int size)
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

void FreeStudent(struct Student* s)
{
	free(s);
}

void Free1Char(char* c)
{
	free(c);
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