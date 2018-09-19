#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>	//srand, rand 함수가 선언되있는 헤더파일
#include<time.h>	//time함수가 선언되있는 헤더파일
int main()
{
	/*
	초기식
	while(조건식)
	{
	반복할 코드
	변화식
	}
	초기식부터 시작해서 조건식 판별 -> 참이면 반복할 코드와
	변화식 수행->조건식 다시 판별 -> 참이면 다시 반복할 코드
	와 변화식 실행하고, 거짓이면 반복문을 빠져나가서 
	다음 코드를 실행함, 조건식->루프 본체 및 변화식->조건식
	으로 순환하는 부분이 루프(loop)이다.

	*/

	int i = 0;
	
	while (i < 7)
	{
		printf("Hello, world!\n");
		i++;	//변화식을 안 쓰면 무한루프가 될 수 있음
	}

	i = 1;

	while (i <= 7)
	{
		printf("Hello, world! %d\n",i);
		i++;
	//i를 1부터 7까지 반복하고 101이 될 때 반복문을 끝냄
	}

	i = 16;

	while (i > 0)
	{
		printf("Hello, world! %d\n", i);
		i--;
	}//i를 16부터 1까지 감소시키고 0이 되면 반복문을 끝냄

	i = 0;

	//while (i < 100);
	//{
	//	printf("Hello, world!\n");
	//	i++;
	//} while뒤에 세미콜론을 붙이면 실제로는 while과
	//중괄호가 떨어진 상태가 되서 중괄호 안에 있는 식은 
	//전혀 실행되지 않게 되고 i값은 계속 그대로 유지
	//되게 된다. 따라서 무한루프 상태에 빠지게 된다. 
	
	int count;

	scanf("%d", &count);

	i = 0;
	while (i < count)
	{
		printf("Hello, world! %d\n", i);
		i++;
	}	//입력한 횟수만큼 반복하기 

	scanf("%d", &count);
	while (count > 0)
	{
		printf("Hello, world! %d\n", count);
		count--;
	}	//입력한 횟수만큼 반복하기 
	//while 반복문은 반복 횟수가 정해지지 않았을 때, 논리
	//조건에 따라 반복 여부를 결정할 때 주로 사용함

	srand(time(NULL));	//현재 시간 값으로 시드를 결정함

	i = 0;
	while (i != 3)
	{
		i = rand() % 10;
		printf("%d\n", i); 
	//무작위로 정수를 생성하려면 srand,rand,time함수가 필요
	//무작위로 정수를 생성하는 행동을 난수 생성 또는 랜덤
	//이라고 함, srand: 난수를 발생시킬 초깃값인 시드(seed)
	//를 설정하며 보통 현재 시간 값을 사용함
	//rand: 난수를 발생시킴, time: 정수형태로 된 현재
	//시간 값을 반환함
	}

	//while (true)
	//{
	//	printf("Hello, world!\n");
	//	무한루프 , 1대신 true를 넣기도 함
	//}

	//while (1)
	//	printf("Hello, world!\n");
	//중괄호 안에 실행할 코드가 한 줄이면 중괄호 생략이 가능

	return 0;

}