#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	break는 for, while, do while, switch문에서 제어 흐름을
	벗어나기 위해 사용함, continue는 제어흐름을
	유지한 상태에서 코드의 실행만 건너뜀 반면에
	break는 제어흐름을 중단하고 빠져나옴
	
	*/
	int num1 = 0;

	while (1)
	{
		num1++;
		printf("%d\t", num1);
		if (num1 == 7)	//num1이 7이면 반복문을 끝냄
			break;
	}

	num1 = 0;
	printf("\n");

	for(;;)
	{
		num1++;
		printf("%d\t", num1);
		if (num1 == 6)	//num1이 6이면 반복문을 끝냄
			break;
	}
	printf("\n");
	int i = 0;
	for (i = 1; i <= 13; i++)
	{
		if (i % 2 != 0)	//짝수만 출력되도록 하기
			continue;	//홀수면 continue 아래의 코드는 실행
		//하지 않고 건너뛴 후에 반복문을 다시 실행함
		printf("%d\n", i);	
	}
	i = 1;
	while (i <= 16)
	{
		i++;
		if (i % 2 != 0)
			continue;
		printf("%d\n", i);
	}

	int count;

	scanf("%d", &count);

	i = 1;
	while (1)
	{
		printf("%d\n", i);
		if (i == count)
			break;

		i++;
	}

	scanf("%d", &count);

	for (i = 1; i <= count; i++)
	{

		if (i % 2 != 0)	//i가 홀수일때는 건너뛰고 짝수일때만
			//출력하도록 설정함
			continue;

		printf("%d\n", i);
	}



	return 0;
}