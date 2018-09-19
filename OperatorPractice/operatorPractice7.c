#include<stdio.h>
int main()
{	/*
	if 조건문은 분기(branch)를 위한 문법임 
	분기는 둘 이상으로 갈라지다 라는 의미임
	프로그램의 흐름을 둘 이상으로 나눔
	if는 조건식을 만족할 때
	else는 조건식을 만족하지 않을 때 실행 
	프로그램이 if, else 두 방향으로 분기함 
	*/

	int num1 = 5;

	if (num1 == 10)
	{
		printf("10입니다.\n");	//조건식이 참일 때 실행
	}
	else {
		printf("10이 아닙니다.\n");	
		//조건식을 만족하지 않을 때 실행함
	}

	int num2 = 10;

	if (num2 == 10)
	{
		printf("10입니다.\n");	
	}
	else;	//else 뒤에 세미콜론을 붙이면 중괄호 안에 있는
	{		//코드가 조건과 관계없이 실행됨
		printf("10이 아닙니다.\n");
	}
	
	int num3 = 25;

	if (num3 == 10)
		printf("10입니다.\n");	//조건식이 참일 때 실행	
	else 
		printf("10이 아닙니다.\n");
		//조건식을 만족하지 않을 때 실행함
	//if, else로 실행할 코드가 2줄 이상일 때 
	//중괄호를 생략하면 컴파일 에러가 발생하게 됨 

	if (2)
		printf("참\n");
	else
		printf("거짓\n");
	//if는 0일때 거짓, 0이 아닌 양수나 음수일 때 참
	//0.0일때 거짓, 그 이외의 실수는 참 

	int num4 = 5;

	if (num4 = 10)	//num4에 10할당 -> 
		//num4만 남는데 num4는 0이 아니므로 참이 됨
		printf("10입니다\n");

	int num5 = 10;
	int num6 = 20;

	if (num5 == 10 && num6 == 20)	//&&:논리연산자
		printf("참\n");	//두 식이 모두 만족할 때 참이 됨
	else
		printf("거짓\n");





		return 0;

}