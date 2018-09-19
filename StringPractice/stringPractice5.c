#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*
	화면에 출력하지 않고 문자열을 만들어서 따로 저장하는 방법
	sprintf 함수를 사용하면 서식을 지정하여 
	문자열을 만들 수가 있다. stdio.h에 선언되어 있다.
	sprintf(배열, 서식, 값); 성공하면 문자열의 길이를 반환하고
	실패하면 음수를 반환함, sprintf 함수도 보안 경고가 발생하므로
	#define _CRT_SECURE_NO_WARNINGS를 넣어줘야됨	
	*/

	char s1[20];

	sprintf(s1, "Hello, %s", "world!");
	//%s가 world!로 바뀌고 s1에 저장이 됨, s1과 같이 문자열을
	//저장할 빈 배열을 버퍼(buffer)라고 부름

	printf("%s\n", s1);

	char s2[30];

	sprintf(s2, "%c %d %f %e\n", 'a', 10, 3.2f, 1.123456e-21f);
	//지정된 서식에 맞추어 값을 문자열로 바꿀 수 있음 

	printf("%s", s2);

	/*
	문자열 포인터에 문자열을 만들어보기
	문자열 포인터를 사용하려면 malloc 함수로 메모리를 할당한 뒤 
	sprintf함수로 문자열을 만들면 됨
	sprintf(문자열 포인터, 서식, 값);

	*/

	char *s3 = malloc(sizeof(char) * 20);
	//문자열을 생성할 메모리 공간도 버퍼에 해당함

	sprintf(s3, "Hello, %s", "world!");
	printf("%s\n", s3);

	free(s3);


	char *s4 = malloc(sizeof(char) * 30);
	//문자열을 생성할 메모리 공간도 버퍼에 해당함

	sprintf(s4, "%c %d %f %e", 'a', 10, 3.2f, 1.123456e-21f);
	//지정된 서식에 맞추어 값을 문자열로 바꿀 수 있음 

	printf("%s\n", s4);

	free(s4);

	/*
	
	scanf("%d %s", &number, name);
		
	switch(number)
	{
		case 1:
			sprintf(result, "%dst %s", number, name);   
			break;
		case 2:
			sprintf(result, "%dnd %s", number, name);   
			break;
		case 3:
			sprintf(result, "%drd %s", number, name);   
			break;
		default:
			sprintf(result, "%dth %s", number, name);   
	}
	*/

	return 0;
}