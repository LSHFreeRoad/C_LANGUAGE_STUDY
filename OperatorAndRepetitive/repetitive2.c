#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	for반복문
	for(초기식 ; 조건식 ; 변화식)	//루프 선언문
	{
	반복할 코드 
	}	//루프 본체
	
	초기식 부터 시작해서 조건식을 판별 -> 참이면 루프를 실행
	하고 변화식을 수행함 -> 다시 조건식을 판별하여 참이면
	코드를 실행하고 거짓이면 반복문을 끝낸 뒤 다음 코드를
	실행함, 조건식 -> 루프 본체 -> 변화식 -> 조건식으로 
	순환하는 부분을 루프라고 부름 
	*/

	int i;
	for (i = 1; i <= 13; i++)
	{
		printf("Hello, world!\t");
		if (i % 5 == 0)
			printf("\n");
	}
	//변화식은 변화식이 한 번 증가될 때 마다 한 번씩 수행함	
	//for 반복문은 반복 횟수가 정해져 있을 때 유용함

	for (i = 0; i < 10; i++)
	{
		printf("Hello, world!\n");
	}
	printf("%d\n", i);	//i가 10이 될 때 빠져나오므로

	for (i = 1; i <= 13 ; i++)
	{
		printf("Hello, world! %d\n",i);
	}//13일때 반복문을 끝냄

	
	for ( i = 16; i > 0 ; i--)
	{
		printf("Hello, world! %d\n",i);
	} //i가 0일때 반복문을 끝냄

	//for (i = 0; i < 100; i++);
	//{
	//	printf("Hello, world! %d\n", i);
	//}
	//for 반복문 뒤에 세미콜론을 붙이면 안 됨
	//세미콜론을 붙이게 되면 떨어진 코드가 됨
	//for (i = 0; i < 100; i++);
	//	printf("Hello, world! %d\n", i);

	for (i = 0; i < 13; i++)
		printf("Hello, world! %d\n", i);

	//for반복문에서 실행할 코드가 한 줄이면 중괄호 생략이
	//가능함, 실행할 코드가 2줄이상이면 꼭 중괄호를 써야됨
	//묶지 않으면 첫번째 코드만 반복문이 실행됨

	int count;

	scanf("%d", &count);

	for ( i = 0; i < count; i++)
	{
		printf("Hello, world! %d\n", i);
	}
	

	for (i = count; i > 0; i--)
	{
		printf("Hello, world! %d\n", i);
	}

	for (; count > 0; count--)
	{
		printf("Hello, world! %d\n", count);
	} //초깃값 생략 : for반복문에 사용할 변수와 초깃값이
	//준비되어 있으면 초깃값 부분을 생략할 수 있음
	int j;

	for (i = 0,j = 0; i < 7; i++, j+=2)
	{
		printf("i : %d, j : %d\n", i, j);
	}// for반복문에서 변수를 2개 이상 사용하는 것이 가능함
	// 변화식에서 여러 연산자를 사용할 수 있음 
	//논리 연산자를 조건식에 사용해서 i, j를 동시에
	//검사할 수도 있음 

	for (;;)
	{
		printf("Hello, world!\n");
	}//무한루프, CTRL+C로 탈출

	/*
	#define _CRT_SECURE_NO_WARNINGS
	#include<stdio.h>
	int main()
	{
		char c1;
		scanf("%d",&c1);
		for(; c1 <= 'z' ; c1++)
		{
			printf("%c\n",c1);
		}


	}
	*/

	return 0;
}	