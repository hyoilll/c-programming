//1���� �迭�� Ȱ���� ����ó�� ���α׷�

#include <stdio.h>

int main()
{
	//�л� a, b
	//1 : ����, 2 : ����, 3 : ����

	int i_a[3]; //a�л��� 3����
	int i_b[3]; //b�л��� 3����

	char c_a[4]; //3���� + NULL == 4byte
	char c_b[4];

	//���� ������ �Է�
	unsigned int i = 0;
	for (i = 0; i < 3; ++i)
		scanf_s("%d", &i_a[i]);

	for (i = 0; i < 3; ++i)
		scanf_s("%d", &i_b[i]);

	//90�̻� : A, 80 ~ 89 : B, 70 ~ 79 : C, 69���� : D
	for (i = 0; i < 3; ++i)
	{
		if ((i_a[i] >= 90) || (i_b[i] >= 90))
		{
			if (i_a[i] >= 90)
				c_a[i] = 'A';
			if (i_b[i] >= 90)
				c_b[i] = 'A';
		}
		if (((80 <= i_a[i]) && (i_a[i] < 90)) || ((80 <= i_b[i]) && (i_b[i] < 90)))
		{
			if (((80 <= i_a[i]) && (i_a[i] < 90)) != 0)
				c_a[i] = 'B';
			if (((80 <= i_b[i]) && (i_b[i] < 90)) != 0)
				c_b[i] = 'B';
		}
		if (((70 <= i_a[i]) && (i_a[i] < 80)) || ((70 <= i_b[i]) && (i_b[i] < 80)))
		{
			if (((70 <= i_a[i]) && (i_a[i] < 80)) != 0)
				c_a[i] = 'C';
			if (((70 <= i_b[i]) && (i_b[i] < 80)) != 0)
				c_b[i] = 'C';
		}
		if (i_a[i] < 70 || i_b[i] < 70)
		{
			if (i_a[i] < 70)
				c_a[i] = 'D';
			if (i_b[i] < 70)
				c_b[i] = 'D';
		}
	}

	double aver_a = (i_a[0] + i_a[1] + i_a[2]) / 3;
	double aver_b = (i_b[0] + i_b[1] + i_b[2]) / 3;

	printf("a1 : %c, a2 : %c, a3 : %c\n", c_a[0], c_a[1], c_a[2]);
	printf("b1 : %c, b2 : %c, b3 : %c\n", c_b[0], c_b[1], c_b[2]);

	printf("%f %f\n", aver_a, aver_b);


	return 0;
}