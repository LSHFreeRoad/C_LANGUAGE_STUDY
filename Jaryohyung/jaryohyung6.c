#include<stdio.h>
int main()
{
	/*
	a,b,c는 문자(character)
	C 언어는 정수 자료형 char에 문자 한 개를 저장함
	char의 크기는 1바이트 
	char : -128~127
	unsigned char :0~255
	char 자료형은 문자를 바로 저장하지 않고 문자에 해당하는
	정수값을 저장함, 문자를 정수로 나타내는 규칙을 ASCII코드
	라고 부름, A~Z(65~90), a~z(97~122) 나머지 값들은 
	공백, 특수문자, 제어문자 등등
	C 언어에서는 문자를 ''(작은 따옴표)로 묶음
	정수자료형에 2바이트 값을 저장할 때는 문자 두 개를 작은 
	따옴표로 묶기도 함 예: 'BA'
	*/
	
	char c1 = 'a';
	char c2 = 'b';
	char c3 = 97;
	char c4 = 98;
	char c5 = 0x61;
	char c6 = 0x62;

	printf("%c %d\n", c1, c1);	//%d -> 아스키 코드값 출력
	printf("%c %d\n", c2, c2);	//%c -> char 약자 

	printf("%c %d\n", c3, c3);	//%d -> 아스키 코드값 출력
	printf("%c %d\n", c4, c4);	//%c -> char 약자 

	printf("%c %d\n", c5, c5);	//%d -> 아스키 코드값 출력
	printf("%c %d\n", c6, c6);	//%c -> char 약자 

	//서식 지정자 %x 16진수 출력됨
	//hexdecimal에서 hex의 x를 따온 것 
	
	char c7 = '0';
	char c8 = 0;	//숫자0과 문자0은 다름

	printf("%c %d\n", c7, c7);
	printf("%c %d\n", c8, c8);	//ASCII 코드 0은 널문자
	//이므로 아무것도 출력되지 않음

	printf("%c %d\n", 'a' + 1, 'a' + 1);
	printf("%c %d\n", 97 + 1, 97 + 1);

	//char 자료형은 문자를 바로 저장하지 않고 문자에 해당하는
	//정수값(ASCII)을 저장해서 숫자와 연산이 가능하다 

	char c9 = 'a';	//문자 a 할당
	char c10 = 'b';	//문자 b 할당
	char lineFeed = '\n';	//제어 문자 \n 할당 

	printf("%c%c%c%c", c1, lineFeed, c2, lineFeed);
	//제어 문자도 %c로 출력이 가능함

	printf("%d 0x%x\n", lineFeed, lineFeed);
	//제어 문자의 아스키 코드 값 및 16진수 값 출력 


	return 0;

}