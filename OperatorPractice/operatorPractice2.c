#include<stdio.h>
int main() 
{
	/*
	C 언어에서는 ++, --라는 특별한 연산자 제공
	++는 값을 1 증가시키는 연산자
	--는 값을 1 감소시키는 연산자
	줄여서 증감연산자라고 부름 
	증감연산자는 정수에서 1을 증가, 감소시킴 
	포인터 연산에서는 자료형 크기만큼 증가, 감소시키기도 함
	변수++	변수--
	++변수	--변수 

	*/

	int num1 = 1;
	num1++;	//num1을 1증가시킴-> 변수자체의 값을 바꿈
	//num1 = num1 + 1,num+=1과 같음 

	printf("%d\n", num1);

	int num2 = 6;	
	num2--;	//num2 = num2 -1, num2 -= 1과 같음;

	printf("%d\n", num2);

	float num3 = 2.1f;
	float num4 = 2.1f;

	num3++;	//증감연산자는 정수부분만 바뀜
	num4--;	//소수점 이하자리에는 영향을 미치지 않음 

	printf("%f\n", num3);
	printf("%f\n", num4);

	char c1 = 'c';
	char c2 = 'd';

	c1++;
	c2--;

	printf("%c %c\n", c1, c2);
	//문자 자료형도 실제로는 정수여서 증감 연산자를
	//사용하면 1을 증가시키거나 감소시킴 
	//아스키 코드값을 1 증감시킴

	//증감 연산자는 변수 앞이나 뒤에 올 수 있음

	int num5 = 3;
	int num6 = 6;
	int num7;
	int num8; 

	num7 = num5++;
	//1. num7 = num5 -> 2. num5 = num5 + 1
	num8 = num6--;
	//1. num8 = num6 ->2.  num6 = num6 - 1

	printf("%d %d\n", num7, num8);

	//증감 연산자를 변수 뒤에 사용한 것을 후위 연산자라고 함
	//동작 순서 
	//1. 현재 변수의 값이 다른 변수에 할당됨(값 변동x) 
	//2. 증감 연산자가 수행되어 변수 값이 1 증감 

	num7 = ++num5;	//1. num5 = num5 + 1 ->2. num7 = num5
	num8 = --num6;	//1. num6 = num6 - 1 ->2. num8 = num6

	printf("%d %d\n", num7, num8);
	// num7에 num5(4)가 1 증가된 5가 할당됨
	// num8에 num6(5)가 1 감소된 4가 할당됨

	//증감 연산자를 변수 앞에 사용한 것을 전위 연산자라고 함
	//동작 순서 
	//1. 증감 연산자가 수행되서 변수의 값이 1 증감 
	//2. 변수의 바뀐 값이 다른 변수에 할당됨

	int num9 = 3;
	int num10 = 6;

	printf("%d %d\n", num9++, num10--);	
	//증감 연산자가 나중에 동작
	printf("%d %d\n", num9, num10);
	printf("%d %d\n", ++num9, --num10);
	//증감 연산자가 먼저 동작함 

	return 0;
}