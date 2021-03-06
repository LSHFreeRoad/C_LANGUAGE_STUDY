#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//조건문은 특정 조건일 때 코드를 실행

	int num1 = 10;

	if (num1 == 10) //조건식, == -> 두 값이 같을 때 
	{
		printf("10입니다.\n");
		//조건식을 만족할 때 실행할 코드 
	}

	int num2 = 5;

	if (num2 == 10); //조건식, == -> 두 값이 같을 때 
	{
		printf("10입니다.\n");
		//조건식을 만족할 때 실행할 코드 //
	}

	//if 조건문 끝에 ;을 붙이면 if는 제대로 동작하지
	//않고 중괄호 안의 코드가 무조건 실행됨 
	//실제로는 if(num1 ==10);
	//printf("10 입니다.\n");
	//컴파일 에러가 나지 않는 이유는 코드를
	//중괄호로 감쌀 수 있기 때문임 

	int num3 = 25;

	if (num3 == 25) //조건식, == -> 두 값이 같을 때 
		printf("25 입니다.\n");
	//조건식을 만족할 때 실행할 코드 
	//if 조건문에서 실행할 코드가 한 줄이면
	//중괄호를 생략할 수 있음 
	//만약 실행할 코드가 2줄이상 일 때 중괄호를 
	//사용하지 않으면 첫 줄을 제외한 2번째 줄의
	//코드 부터는 if와 관계 없이 실행이 됨 

	if (num3 == 20)
		printf("20 입니다.\n");
	printf("다음 값은 뭔가요?.\n");

	float num4 = .1f;
	char c1 = 'c';

	if (num4 == 0.1f)	//실수 자료형 오차 감안
		printf("0.1 입니다.\n");
	//반올림 되는 것을 감안해야됨
	if (c1 == 'c')
		printf("c 입니다.\n");
	//char는 문자로 비교하거나
	if (c1 == 99)
		printf("99 입니다.\n");
	//아스키 코드 값으로 비교해도 됨 

	int num5;

	scanf("%d", &num5);

	if (num5 == 10)
	{
		printf("10입니다.\n");
	}

	if (num5 == 20)
		printf("20입니다\n");



	return 0;
}