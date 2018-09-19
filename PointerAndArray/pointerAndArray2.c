#include<stdio.h>
int main()
{
	/*
	FizzBuzz -> 간단한 프로그래밍 문제
	1에서 100까지 출력
	3의 배수는 Fizz출력
	5의 배수는 Buzz출력
	3과 5의 공배수는 FizzBuzz 출력
	*/

	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			printf("FizzBuzz\n");
		else if (i % 3 == 0)
			printf("Fizz\n");
		else if (i % 5 == 0)
			printf("Buzz\n");
		else
			printf("%d\n", i);
	}

	for (int i = 0; ++i <= 100;)
		printf(i % 3 ? i % 5 ? "%d\n" : "Buzz\n"
			: i % 5 ? "Fizz\n" : "FizzBuzz\n", i);
	//코드 골프 방식 : 소스코드의 문자 수를 최대한 줄여서
	//작성하는 놀이
	//i % 3을 계산하여 0이 아니면 i % 5로 감, i % 5가 0이
	//아니면 %d로 i를 출력함
	//i % 5가 0이면 "Buzz"를 출력함
	//i % 3이 0이면 다시 i % 5를 계산해서 0이 아닌 값이
	//나오면 3의 배수이므로 "Fizz"를 출력함
	//i % 3, i % 5가 둘 다 0이면 "FizzBuzz"를 출력함

	/*
	#define _CRT_SECURE_NO_WARNINGS
	#include<stdio.h>
	int main()
	{
		int num1, num2;
		scanf("%d %d", &num1, &num2);

		for(;num1 <= num2; num1++)
		{
			if(num1 % 5 == 0 && num1 % 11 == 0)
				printf("FizzBuzz\n");
			else if(num1 % 5 ==0)
				printf("Fizz\n");
			else if(num1 % 11 ==0)
				printf("Buzz\n");
			else
				printf("%d\n", num1);
		}







	}
	*/









	return 0;

}