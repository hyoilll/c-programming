/*
	2���� �迭
	arr[��][��];

		ex) int arr[2][3];
				o	o	o
				o	o	o
*/

#include <stdio.h>

int main()
{
	//�л� a, b
	//1 : ����, 2 : ����, 3 : ����

	int students_score[2][3]; //a,b�л��� 3����

	char students_grade[2][4];

	unsigned int i = 0;
	unsigned int j = 0;

	double aver_a = 0.0;
	double aver_b = 0.0;

	int sum = 0;
	char c = 'a';

	//���� ������ �Է�
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			scanf_s("%d", &students_score[i][j]);
		}
	}

	//90�̻� : A, 80 ~ 89 : B, 70 ~ 79 : C, 69���� : D
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