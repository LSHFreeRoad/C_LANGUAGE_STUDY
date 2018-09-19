#include<stdio.h>
int main()
{
	/*
	비트 연산자: 비트 단위로 연산하는 연산자
	비트 : 2진수를 저장하는 단위이며 컴퓨터에서 사용할
	수 있는 최소 단위이며 0과 1을 나타냄 
	바이트 : 8비트 크기의 단위
	&: 비트 AND(두 비트가 모두 1일 때 1)
	|: 비트 OR(두 비트 중 하나라도 1이면 1)
	^: 비트 XOR(배타적 OR: Exclusive OR, 두 비트가
	다를 때 1), ~ : 비트 NOT,
	<< : 비트를 왼쪽으로 시프트,
	>>: 비트를 오른쪽으로 시프트
	&=: 비트 AND 연산 후 할당, |=: 비트 OR 연산 후 할당
	^=: 비트 XOR 연산 후 할당, <<=: 비트를 왼쪽으로 
	시프트 한 후에 할당, >>=: 비트를 오른쪽으로 쉬프트
	한 후에 할당, 비트 연산자는 비트로 옵션을 설정할 때
	주로 사용함-> 비트로 옵션을 설정하는 방식을 플래그
	라고 함 
	10진수를 2진수로 쉽게 바꾸는 방법
	계산기-> 프로그래머 용으로 바꿔서 하기 
	*/

	unsigned char num1 = 1;	//0000 0001
	unsigned char num2 = 3;	//0000 0011

	printf("%d\n", num1 & num2);	//0000 0001 : 1
	printf("%d\n", num1 | num2);	//0000 0011 : 3
	printf("%d\n", num1 ^ num2);	//0000 0010 : 2
	
	unsigned char num3 = 162; // 1010 0010
	unsigned char num4;

	num4 = ~num3;	//0101 1101 -> 93

	printf("%d\n", num4);	//0101 1101 -> 93
	
	//a << b , a >> b
	//a를 b 횟수만큼 왼쪽 또는 오른쪽으로 이동시킴

	unsigned char num5 = 3;	// 0000 0011
	unsigned char num6 = 24;// 0001 1000

	printf("%d\n", num5 << 3); //0001 1000 -> 3*2의 3제곱
	printf("%d\n", num6 >> 2); //0000 0110 -> 24/2의 제곱

	unsigned char num7 = 4;	//0000 0100
	unsigned char num8 = 4;	//0000 0100
	unsigned char num9 = 4;	//0000 0100
	unsigned char num10 = 4; //0000 0100
	unsigned char num11 = 4;	//0000 0100

	num7 &= 5;	//0000 0101
	num8 |= 6;	//0000 0110
	num9 ^= 3;	//0000 0011
	num10 <<= 2;	
	num11 >>= 2;

	printf("%d\n", num7); //4 : 0000 0100 num7에 할당됨
	printf("%d\n", num8); //6: 0000 0110 num8에 할당됨
	printf("%d\n", num9); //7 : 0000 0111 num9에 할당됨
	printf("%d\n", num10); //16 : 0001 0000 num10에 할당됨
	printf("%d\n", num11);	//1 : 0000 0001 num11에 할당됨

	return 0;

}