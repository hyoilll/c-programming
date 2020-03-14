#include <stdio.h>
#include <string.h>
int main()
{
	//학생 a, b
	//1 : 수학, 2 : 과학, 3 : 영어

	int i_a[3]; //a학생의 3과목
	int i_b[3]; //b학생의 3과목

	int* i_aPtr = i_a;
	int* i_bPtr = i_b;

	char c_a[4]; //3과목 + NULL == 4byte
	char c_b[4];

	char* c_aPtr = c_a;
	char* c_bPtr = c_b; 

	//성적 데이터 입력
	unsigned int i = 0;
	for (i = 0; i < 3; ++i)
		scanf_s("%d", i_aPtr + i);

	for (i = 0; i < 3; ++i)
		scanf_s("%d", i_bPtr + i);

	//90이상 : A, 80 ~ 89 : B, 70 ~ 79 : C, 69이하 : D
	for (i = 0; i < 3; ++i)
	{
		if ((*(i_aPtr + i) >= 90) || (*(i_bPtr + i) >= 90))
		{
			if (*(i_aPtr + i) >= 90)
				*(c_aPtr + i) = 'A';
			if (*(i_bPtr + i) >= 90)
				*(c_bPtr + i) = 'A';
		}
		if (((80 <= *(i_aPtr + i)) && (*(i_aPtr + i) < 90)) || ((80 <= *(i_bPtr + i)) && (*(i_bPtr + i) < 90)))
		{
			if (((80 <= *(i_aPtr + i)) && (*(i_aPtr + i) < 90)) != 0)
				*(c_aPtr + i) = 'B';
			if (((80 <= *(i_bPtr + i)) && (*(i_bPtr + i) < 90)) != 0)
				*(c_bPtr + i) = 'B';
		}
		if (((70 <= *(i_aPtr + i)) && (*(i_aPtr + i) < 80)) || ((70 <= *(i_bPtr + i)) && (*(i_bPtr + i) < 80)))
		{
			if (((70 <= *(i_aPtr + i)) && (*(i_aPtr + i) < 80)) != 0)
				*(c_aPtr + i) = 'C';
			if (((70 <= *(i_bPtr + i)) && (*(i_bPtr + i) < 80)) != 0)
				*(c_bPtr + i) = 'C';
		}
		if (*(i_aPtr + i) < 70 || *(i_bPtr + i) < 70)
		{
			if (*(i_aPtr + i) < 70)
				*(c_aPtr + i) = 'D';
			if (*(i_bPtr + i) < 70)
				*(c_bPtr + i) = 'D';
		}
	}

	double aver_a = (*(i_aPtr) + *(i_aPtr + 1) + *(i_aPtr + 2)) / 3;
	double aver_b = (*(i_bPtr) + *(i_bPtr + 1) + *(i_bPtr + 2)) / 3;

	printf("a1 : %c, a2 : %c, a3 : %c\n", *(c_aPtr), *(c_aPtr + 1), *(c_aPtr + 2));
	printf("b1 : %c, b2 : %c, b3 : %c\n", *(c_bPtr), *(c_bPtr + 1), *(c_bPtr + 2));

	printf("%f %f\n", aver_a, aver_b);
	
	
	/*
	char c = 'c';
	char* c_ptr = &c;
	char ca[3] = "A+";
	int n = strcmp(ca, "A+");
	printf("%d",n);
	*/

	return 0;
}