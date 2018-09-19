#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	/*
	문자열은 다른 배열이나 포인터(메모리)로 복사할 수가 있다.
	strcpy함수는 문자열을 다른 곳으로 복사하며 string copy에서
	따옴, strcpy(대상 문자열, 원본 문자열);
	대상 문자열의 포인터를 반환함, string.h헤더 파일에 선언되 있음
	strcpy함수도 보안 문제로 인해서 보안 경고가 발생하기 때문에
	_CRT_SECURE_NO_WARNINGS를 입력해줘야 됨,

	*/

	char s1[10] = "Hello";
	char s2[10];

	strcpy(s2, s1);

	printf("%s\n", s2);
	printf("s1의 메모리 주소: %p\n", s1);
	printf("s2의 메모리 주소: %p\n", s2);


	//s2에 s1의 문자열을 복사함. 이때 복사된 결과가 저장될 배열의
	//크기는 반드시 NULL까지 들어갈 수 있어야 함 

	/*
	char *s1 = "Hello";
	char *s2 ="";

	strcpy(s2, s1);

	printf("%s\n", s2);

	문자열 포인터에 문자열을 복사할 수는 없음. 왜냐하면 s2에
	저장된 메모리 주소는 복사할 공간도 없고 읽기만 할 수 있고 쓰기가
	막혀있음, 문자열 포인터에 문자열을 복사하려면 문자열이 들어갈
	공간을 따로 마련해야됨

	*/

	char *s3 = "Hello";
	char *s4 = malloc(sizeof(char) * 10);
	//char 10개 크기만큼 동적으로 메모리를 할당
	//이렇게 하면 strcpy함수로 s1의 문자열을 s2에 복사할 수 있음
	strcpy(s4, s3);
	printf("%s\n", s4);

	free(s4);

	/*
	문자열은 strcat 함수를 사용하여 서로 붙일 수 있고 함수 이름은
	string concatenate에서 따옴, string.h 헤더파일에 선언되 있음
	strcat(최종문자열, 붙일문자열), 최종문자열의 포인터를 반환함
	strcat함수도 보안 경고가 발생하므로 _CRT_SECURE_NO_WARNINGS를 
	붙임
	*/

	char s5[10] = "World";
	char s6[20] = "Hello";
	//문자열을 붙일 때 NULL까지 들어가도록 최종 문자열 배열의 크기를
	//넉넉하게 만듬
	strcat(s6, s5);

	printf("%s\n", s6);

	char *s7 = "World";
	char *s8 = malloc(sizeof(char) * 20);

	strcpy(s8, "Hello");

	strcat(s8, s7);

	printf("%s\n", s8);

	free(s8);

	//문자열 포인터 s8은 뒤에 붙일 공간도 없고 읽기 전용
	//메모리이기 때문에 문자열을 붙일 수 없음 
	//문자열을 붙이려면 s8에 쓰기가 가능하도록 
	//malloc함수로 동적 메모리를 할당하고 문자열을 붙일 수 있도록
	//공간도 넉넉하게 20으로 설정함

	//메모리가 할당된 문자열 포인터는 문자열을 = 기호로 직접 
	//할당할 수 없으므로 strcpy함수를 이용해서 s8에 "Hello"
	//문자열을 복사함, strcat함수로 문자열 포인터 s8뒤에 
	//문자열 포인터 s7을 붙임

	//malloc함수로 s10에 메모리를 할당함. 할당할 메모리 공간은
	//복사될 문자열보다 커야함. 그리고 strcpy함수로 s9의 문자열을
	//s10에 복사함

	char s9[10] = "Hello";
	char *s10 = malloc(sizeof(char) * 10);

	strcpy(s10, s9);

	printf("%s\n", s10);
	free(s10);

	char s11[10] = "world";
	char *s12 = malloc(sizeof(char) * 20);

	strcpy(s12, "Hello");

	strcat(s12, s11); 

	printf("%s\n", s12);
	free(s12);
	
	return 0;
}