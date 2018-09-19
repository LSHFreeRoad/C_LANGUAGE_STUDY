#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	//srand, rand함수가 선언된 헤더파일
#include<time.h>	//time함수가 선언된 헤더파일
#include<stdbool.h>
int main()
{	/*
	초기식
	do
	{
	반복할 코드	--> 루프 본체 및 변화식
	변화식
	}while(조건식); -->루프 선언문 
	실행 과정: 코드와 변화식 실행 -> 조건식이 참이면 다시 
	루프 본체(코드와 변화식) 실행, 거짓이면 반복문을
	빠져나가 다음 코드 실행
	*/

	int i = 0; // 초기식

	do
	{
		printf("Hellom world! %d\n", i);	//반복할 코드
		i++;	//변화식
	} while (i < 7);	//조건식
	//조건식에 관계없이 무조건 한 번은 실행됨
	//변화식이 없으면 무한 루프가 될 수 있으므로 주의할 것

	i = 1;

	do 
	{
		printf("Hello, world! %d\n", i);
		i++;
	} while (i <= 13);	//i가 14가 될 때 반복문이 끝남

	i = 13;
	
	do
	{
		printf("Hello, world! %d\n", i);
		i--;
	} while (i > 0);

	int count;

	scanf("%d", &count);

	i = 0;
	do
	{
		printf("Hello, world! %d\n", i);
		i++;
	} while (i < count);	//count만큼 반복횟수 지정


	scanf("%d", &count);

	do
	{
		printf("Hello, world! %d\n", count);
		count--;	//반복문이 실행될 때마다 count 감소
	} while (count>0);	//count만큼 반복횟수 지정

	srand(time(NULL));	
	//srand : 난수를 발생시킬 시드(seed)를 설정함, 보통 현재
	//시간 값을 사용함, rand: 난수를 발생시킴
	//time: 정수 형태로 된 현재 시간 값을 반환함 

	i = 0;
	do
	{
		i = rand() % 10;	//rand함수를 이용하여 무작위로
		//정수를 생성하는데 이때 10 미만의 숫자로 생성함
		printf("%d\n", i);
	} while (i != 3);	//i가 3이 나올 때 반복문을 끝냄

	//do
	//{
	//	printf("Hello, world!\n");
	//} while (1); //while에 1 또는 true를 지정하면 무한루프

	do
	{
		printf("Hello, world!\n");
	} while (false); //0또는 false를 지정하면 코드가 한 번만
	//실행됨, 반복문은 반복조건이 가장 중요함 

	/*
		sum += i;
		i++;
	
	*/

	return 0;
}