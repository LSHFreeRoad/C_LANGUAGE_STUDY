#define _CRT_SECURE_NO_WARNINGS
//strcpy 함수로 인한 보안 문제가 발생할 수 있으므로
#include <stdio.h>
#include <string.h> //strlen이 선언되있는 헤더파일
int main()
{
	/*
	문자열의 길이는 strlen(string length에서 따옴)함수로 구할 수
	있음, strlen(문자열 포인터 or 문자 배열), 
	순수하게 문자열의 길이만 구함
	NULL 부분은 포함하지 않고 NULL 바로 앞까지만 구함
	*/

	char *s1 = "Hello";
	char s2[10] = "Hello";

	printf("%zd\n", strlen(s1));
	printf("%zd\n", strlen(s2));

	/*
	strcmp 함수를 사용하면 두 문자열이 같은지 비교할 수가 있음
	strcmp string compare 에서 따옴
	strcmp() -> 괄호 안에 비교할 두 문자열을 넣어주면 됨
	-1 반환 : ASCII 코드 기준으로 문자열2(s2)가 클 때 
	0 반환 : ASCII 코드 기준으로 두 문자열이 같을 때
	1 반환 : ASCII 코드 기준으로 문자열1(s1)이 클 때
	문자열의 저장방식은 문자열 비교에 영향을 주지 않음
	문자열 포인터에 NULL이 들어가 있다면 에러가 발생함
	strcmp함수는 문자열에서 첫 번째 문자부터 차례대로 비교하며 
	비교기준은 각 문자의 ASCII코드 값임

	*/

	
	int ret = strcmp(s1, s2);

	printf("%d\n", ret);


	char s3[20];
	char s4[20];

	printf("문자열 두 개를 입력하세요: ");
	scanf("%s %s", s3, s4);

	int ret1 = strcmp(s3, s4);

	switch (ret1)
	{
	case -1:
		printf("%s보다 %s가 큼\n", s3, s4);
		break;
	case 0:
		printf("두 문자열이 같음\n");
		break;
	case 1:
		printf("%s보다 %s가 큼\n", s4, s3);
		break;
	}
	

	return 0;
}