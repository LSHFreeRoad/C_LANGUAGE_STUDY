#include<stdio.h>
int main()
{
	/*
	if(조건식)
	{
	
	}else if(조건식)
	{

	}else
	{

	}
	
	
	*/

	int num1 = 20;

	if (num1 == 10)
		printf("10입니다.\n");
	else if (num1 == 20)	//if가 거짓일 때 
		//else if가 참이라면 밑에 코드 실행
		//else if도 끝에 세미콜론을 붙이면 안됨 
		printf("20입니다.\n");

	int num2 = 30;

	if (num2 == 10)
		printf("10입니다.\n");
	else if (num2 == 20)
		printf("20입니다.\n");
	else
		printf("10도 20도 아닙니다.\n");

	//if, else if가 모두 거짓일 때 else 밑에 코드가 실행됨
	//else if는 여러 번 사용가능함
	//else if 앞에 else가 오면 컴파일 에러가 뜨므로 주의!

	return 0;



}