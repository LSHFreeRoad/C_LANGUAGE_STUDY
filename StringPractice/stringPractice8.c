#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*
	프로그램을 만들다보면 내용은 숫자이지만 형태는 문자열인 경우가 
	있음 , 예:Hello, world!, 10, 35.28 →문자와 숫자가 섞여있음
	문자열을 int, float형으로 변환하는 방법, int, float형을 
	문자열로 변환하는 방법 익히기
	atoi(문자열)함수는 문자열을 정수로 바꿀 수 있음
	성공하면 변환된 정수를 반환하고 실패하면 0을 반환함
	ASCII string to integer에서 따옴, stdlib.h헤더파일에 선언되있음
	*/

	char *s1 = "283";
	int num1;

	num1 = atoi(s1);

	printf("%d\n", num1);
	printf("%d\n", atoi("259*$"));
	/*문자열은 정수로 되어있어야 되고 알파벳 영문자, 특수문자가
	있으면 해당문자 부터는 변환하지 않음. 
	또한 처음부터 숫자가 아니면 0으로 변환이 됨
	*/

	//특정 진법으로 표기된 문자열을 정수로 변환할 수 있음
	//strtol 함수를 사용하면 16진법으로 표기된 문자열을
	//정수로 바꿀 수 있고 함수 이름은 string to long에서 따옴
	//stdlib.h 에 선언되 있음, strtol(문자열, 끝 포인터, 진법);
	//성공하면 변환된 정수를 반환하고 실패하면 0을 반환함

	char *s2 = "0xaf10";
	int num2;

	num2 = strtol(s2, NULL, 16);
	//변환할 문자열을 저장할 배열(또는 동적 메모리를 할당한 포인터)
	//을 넣어주고 16을 지정하면 16진법으로 표기된 문자열을 정수로
	//변환할 수 있음, 두 번째 인자에 NULL을 넣었는데 이 부분은
	//여러 개의 정수로 된 문자열을 변환할 때 사용함

	printf("%x %d\n", num2, num2);

	char *s3 = "0xaf10 42 0x27C 9952";

	int num3, num4, num5, num6;
	char *end;
	num3 = strtol(s3, &end, 16);
	//s3 첫 부분을 정수로 변환하고 끝 포인터는 &end처럼 end에
	//메모리 주소를 넣어줌. strtol 함수가 실행된 뒤에는 " 42 0x27C
	//9952처럼 이전 숫자의 끝부분부터 시작하게 됨

	num4 = strtol(end, &end, 10);
	//end를 넣어주어 이전 숫자의 끝부분부터 변환이 됨.
	//strtol 함수가 실행된 뒤에는 " 0x27C 9952처럼
	//이전 숫자의 끝부분부터 시작하게 됨

	num5 = strtol(end, &end, 16);
	num6 = strtol(end, NULL, 10);

	printf("%x\n", num3);
	printf("%d\n", num4);
	printf("%X\n", num5);
	printf("%d\n", num6);

	/*
	문자열을 실수로 바꾸기, atof함수를 사용하면 문자열을 실수로 바꿀
	수가 있고 함수 이름은 ASCII string to float에서 따옴,
	stdlib.h에 선언되어 있음 atof(문자열); 
	성공하면 변환된 실수를 반환하고 실패하면 0을 반환함
	*/

	char *s4 = "35.283672";
	double num7;

	num7 = atof(s4);
	/*문자열은 실수로 되어 있어야 하며 알파벳 영문자, 특수 문자가
	//포함되면 해당 문자부터는 변환하지 않음, 처음부터 숫자가 아니면
	0으로 변환됨
	*/

	printf("%f\n", num7);

	char *s5 = "3.e5";
	//지수 표기법으로 된 문자열도 실수로 바꿀 수 있음
	double num8;

	num8 = atof(s5);

	printf("%e %f\n", num8, num8);

	/*
	strtof 함수를 이용하면 여러 개의 실수로 된 문자열을 실수로
	바꿀 수 있으며 함수 이름은 string to float에서 따옴.
	stdlib.h 에 선언되 있음, strtof(문자열, 끝 포인터); 
	성공하면 실수를 반환하고 실패하면 0을 반환함
	*/
	
	char *s6 = "35.283672 3.e5 9.281772 7.e-5";
	float num9, num10, num11, num12;
	char *end2;	//이전 숫자의 끝 부분부터 시작하게 됨

	num9 = strtof(s6, &end2);
	num10 = strtof(end2, &end2);
	num11 = strtof(end2, &end2);
	num12 = strtof(end2, NULL);
	//더 이상 변환할 문자열이 없다면 끝 포인터에 NULL을 넣어주면 됨

	printf("%f\n", num9);
	printf("%e\n", num10);
	printf("%f\n", num11);
	printf("%e\n", num12);

	/*
	strtod 함수를 이용하면 문자열을 double형 실수로 변환할 수 있음
	float로 선언한 변수를 double로 바꾸려면 strtod함수를 사용하면 됨
	strtod(문자열, 끝 포인터);
	성공하면 변환된 실수를 반환, 실패하면 0을 반환함	
	*/

	char *s7 = "35.283672 3.e5 9.281772 7.e-5";
	double num13, num14, num15, num16;
	char *end3;	//이전 숫자의 끝 부분부터 시작하게 됨

	num13 = strtod(s6, &end3);
	num14 = strtod(end3, &end3);
	num15 = strtod(end3, &end3);
	num16 = strtod(end3, NULL);
	//더 이상 변환할 문자열이 없다면 끝 포인터에 NULL을 넣어주면 됨

	printf("%f\n", num13);
	printf("%e\n", num14);
	printf("%f\n", num15);
	printf("%e\n", num16);

	/*
	정수를 문자열 형태로 변환하기, sprintf 함수를 사용하면
	정수를 문자열로 변환할 수 있음, stdio.h에 선언되 있음
	보안 경고가 발생하므로 #define _CRT_SECURE_NO_WARNINGS를 넣음
	sprintf(문자열, "%d", 정수); sprintf(문자열, "%x", 정수);
	sprintf(문자열, "%X", 정수);	
	*/

	char s8[10];
	int num17 = 283;

	sprintf(s8, "%d", num17);

	printf("%s\n", s8);

	sprintf(s8, "0x%x", num17);
	//16진법으로 표기된 문자열로 변환할 수 있음
	//서식 지정자를 %X로 지정하면 16진수의 알파벳 부분이 
	//대문자로 저장이 됨
	printf("%s\n", s8);

	//실수를 문자열로 변환할 때도 sprintf 함수를 사용함

	char s9[10];

	float num18 = 38.973240f;

	sprintf(s9, "%f", num18);
	//실수를 문자열로 변환

	printf("%s\n", s9);

	char s10[20];
	//변환된 문자열이 길어질 수 있으므로 반드시 배열의 크기를 확인함

	float num19 = 38.973240f;

	sprintf(s10, "%e", num19);
	//실수를 문자열로 변환

	printf("%s\n", s10);

	return 0;
}