#include<stdio.h>
int main()
{
	//서로 다른 자료형끼리 연산을 할 때는
	//정해진 규칙을 따름

	int num1 = 11;
	float num2 = 4.4f;

	printf("%f\n", num1 + num2);
	printf("%f\n", num1 - num2);
	printf("%f\n", num1 * num2);
	printf("%f\n", num1 / num2);

	//정수와 실수의 연산 -> 결과는 실수 
	//실수의 범위가 정수보다 더 크기 때문에 
	//표현 범위가 넓은 쪽으로 자동 변환됨
	//즉 정수에서 실수로 자동변환
	//자료형을 섞어 쓰면 컴파일러에서 
	//암시적 형변환(implicit type conversation)을 함
	//자료형의 크기가 큰 쪽, 표현 범위가 넓은 쪽으로
	//자동변환됨,
	//이를 형 확장(type promotion)이라함(값이 보전됨)

	long long num3 = 34283408298484;
	int num4 = 3;

	//long long이 int보다 자료형 크기가 크므로
	//연산 시에 long long으로 형 확장이 발생함

	printf("======================\n");
	printf("%lld\n", num3 + num4);
	printf("%lld\n", num3 - num4);
	printf("%lld\n", num3 * num4);
	printf("%lld\n", num3 / num4);

	/*
	자료형의 크기가 작은 쪽, 표현 범위가 좁은 쪽으로
	변환되는 것을 형 축소(type demotion)이라고 함

	형 축소가 일어나면 값의 손실이 일어남
	컴파일 경고가 나오지 않게 하려면
	형 변환(type conversation, type casting)을 해야됨
	*/

	float num5 = 11.0f;
	float num6 = 5.0f;

	int num7 = (int)(num5 / num6);	//2.2 -> 2

	printf("%d\n", num7);



	char num8 = 28;
	int num9 = 1000000002;

	char num10 = num8 + num9;

	printf("%d\n", num10);

	/*
	num10의 연산과정
	num8 = 28
	= 0001 1100
	num9 = 1000000002
	= 0011 1011 1001 1010 1100 1010 0000 0010

	num10 = 0011 1011 1001 1010 1100 1010 0001 1110
	-------------------------------------==========
	앞 자릿 수는 버림					사용

	char 자료형의 크기에 맞게 저장되고 앞 자릿수는
	버려짐

	문자(정수)		정수			실수	  형 축소
				long long			long double	 ↑ㅣ
		형 축소  long	   형 축소	double		 ㅣㅣ
	1.char	<---  int		 <----  float		 ㅣㅣ
		--->	  short int	  --->				 ㅣ↓
		형 확장				형 확장			형 확장

	*/

	return 0;

}