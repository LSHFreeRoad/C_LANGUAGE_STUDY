#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{

	//char s1[10];

	//printf("문자열을 입력하세요: ");
	//scanf("%s", s1);

	//printf("%s\n", s1);
	//일반 변수와는 다르게 &는 붙이지 않음
	//입력할 때는 배열의 크기 -1을 넘지 않도록 해야됨
	//scanf에서 %s로 문자열을 저장할 때 입력된 문자열에 공백이
	//있다면 배열에는 공백 직전까지만 저장됨
	//공백까지 포함해서 입력받으려면 서식 지정자를
	//"%[^\n]s"와 같이 지정해주면 됨

	//char s2[20];

	//printf("문자열을 입력하세요: ");
	//scanf("%[^\n]s", s2);

	//printf("%s\n", s2);

	/*
	문자열 포인터에 사용자의 입력 값을 저장하기
	
	char *s3 = "Hello";

	printf("문자열을 입력하세요: ");
	scanf("%s", s3);

	printf("%s\n", s3);
	실행해보면 에러가 발생하게 됨 왜냐하면 s3에 저장된 메모리
	주소는 읽기만 가능하고 쓰기는 막혀있기 때문임
	입력값을 문자열 포인터에 저장하려면 문자열이 들어갈 공간을
	따로 마련해야됨


	*/

	char *s4 = malloc(sizeof(char) * 10);
	//char형 10개 크기만큼 동적으로 메모리를 할당함
	//이렇게 하면 scanf로 받은
	//입력값을 문자열 포인터에 저장할 수 있음
	/*printf("문자열을 입력하세요: ");
	scanf("%s", s4);

	printf("%s\n", s4);

	free(s4);
	//문자열 사용이 끝났다면 반드시 free함수로 할당한 메모리 해제
	*/

	char s5[10], s6[10];

	printf("문자열을 두 개 입력하세요: ");
	scanf("%s %s", s5, s6);

	printf("%s\n", s5);
	printf("%s\n", s6);





	return 0;
}