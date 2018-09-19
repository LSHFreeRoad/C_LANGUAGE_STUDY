#include<stdio.h>
int main()
{	/*
	곱셈: *, 나눗셈: / 
	*/
	int num1;
	int num2;

	num1 = 2 * 3;
	num2 = 7 / 2;	//C 언어에서 정수/정수 = 정수 
	//정수는 0으로 나눌 수가 없음 
	//변수로 해서 0으로 나누면 실행 에러 발생함 

	printf("%d\n", num1);
	printf("%d\n", num2);

	float num3;
	float num4;

	num3 = 2.73f * 3.81f;	
	num4 = 5.0f / 2.0f;	//실수 / 실수 = 실수 
	//실수계산에서 특이한 점은 오차가 나온 다는 것
	//부록 참조
	//실수도 0으로 나누면 컴파일 에러가 발생함
	//변수에 0을 저장해서 나누면 inf가 나옴
	//부록 참조 
	printf("%f\n", num3);
	printf("%f\n", num4);

	//변수 1 = 변수1 * 값;
	//변수 2 = 변수2 / 값;

	int num5 = 2;
	int num6 = 7;

	num5 = num5 * 3;
	num6 = num6 / 2;

	printf("%d\n", num5);
	printf("%d\n", num6);

	num5 *= 3;	//곱셈과 할당연산 연속해서 처리 
	num6 /= 2;	//나눗셈과 할당연산 연속해서 처리 
	
	printf("%d\n", num5);
	printf("%d\n", num6);

	return 0;

}