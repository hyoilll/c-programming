#include <stdio.h>

int main()
{
	int input_num = 0;
	unsigned int i = 0;

	printf("���� �Է� : ");
	
	scanf_s("%d", &input_num);

	printf("%d�� ����� ", input_num);

	for (i = 1; i <= input_num; ++i)
	{
		if (input_num % i == 0)
			printf("%d ", i);
	}

	printf("�Դϴ�.");
	return 0;
}