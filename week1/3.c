/*
	2차원 배열
	arr[행][열];

		ex) int arr[2][3];
				o	o	o
				o	o	o
*/

#include <stdio.h>

int main()
{
	//학생 a, b
	//1 : 수학, 2 : 과학, 3 : 영어

	int students_score[2][3]; //a,b학생의 3과목

	char students_grade[2][4];

	unsigned int i = 0;
	unsigned int j = 0;

	double aver_a = 0.0;
	double aver_b = 0.0;

	int sum = 0;
	char c = 'a';

	//성적 데이터 입력
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			scanf_s("%d", &students_score[i][j]);
		}
	}

	//90이상 : A, 80 ~ 89 : B, 70 ~ 79 : C, 69이하 : D
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (students_score[i][j] >= 90)
			{
				students_grade[i][j] = 'A';
			}
			if ((80 <= students_score[i][j]) && (students_score[i][j] < 90))
			{
				students_grade[i][j] = 'B';
			}
			if ((70 <= students_score[i][j]) && (students_score[i][j] < 80))
			{
				students_grade[i][j] = 'C';
			}
			if ((students_score[i][j] < 70))
			{
				students_grade[i][j] = 'D';
			}
		}
	}

	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			sum += students_score[i][j];
			printf("%c%d : ", c, j + 1);
			printf("%c, ", students_grade[i][j]);
		}
		++c;

		printf("%f\n", (double)sum / 3);
	}

	return 0;
}