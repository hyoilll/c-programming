#include <stdio.h>

int main()
{
	int input_num = 0;
	unsigned int i = 0;

	printf("정수 입력 : ");
	
	scanf_s("%d", &input_num);

	printf("%d의 약수는 ", input_num);

	for (i = 1; i <= input_num; ++i)
	{
		if (input_num % i == 0)
			printf("%d ", i);
	}

	printf("입니다.");
	return 0;
}