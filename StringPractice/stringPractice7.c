#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
	/*
	문자열을 특정 문자를 기준으로 자르기, strtok함수를 이용하면
	되고 함수 이름은 문자열을 조각(token)으로 나누다(string toknize)
	에서 따옴, string.h 에 선언되어 있음 
	strtok(대상문자열, 기준문자);
	자른 문자열을 반환, 더는 자를 문자열이 없으면 NULL을 반환함
	strtok함수는 보안 경고가 발생하므로 
	#define _CRT_SECURE_NO_WARNINGS를 넣어줌
	*/

	char s1[30] = "The Little Prince";

	char *ptr = strtok(s1, " ");
	//공백 문자(" ")를 넣어주면 공백으로 구분하여 문자열을 자름
	//단 기준 문자를 (' ')로 묶으면 안 됨, strtok함수는 
	//잘린 문자열을 한 번에 얻을 수 없기 때문에 while 반복문으로
	//문자열을 계속 자르다가 문자열이 나오지 않으면 반복문을 
	//끝내는 방식으로 사용함

	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
		/*자른 문자열 부분에 NULL을 넣어줌, NULL을 넣었을 때
		직전 strtok함수에서 처리했던 문자열에서
		잘린 문자열만큼 다음 문자로 이동한 뒤 다음 문자열을 자름
		만약 ptr = strtok(ptr, " "); 처럼 잘린 문자열의
		포인터를 다시 넣었을 때는 다음 문자로 이동하지 못하고
		처음에 나오는 문자열만 계속 자르게 됨
		strtok 함수를 사용할 때는 처음에만 자를 문자열을 넣어주고
		그 다음부터는 NULL을 넣어준다
		strtok함수의 동작순서 → 처음 호출되는 strtok는 
		" "(공백문자)를 찾아서 NULL로 채운 뒤에 문자열의 첫 부분인 
		"The"를 자름 → while 반복문 안에서 strtok에 NULL을 넣어주어
		앞에서 잘린 문자열만큼 다음 문자로 이동함 
		-> 방금 전의 과정을 반복하다가 공백문자를 만나지 못하면 
		NULL을 반환하고 while 반복문을 끝냄
		strtok() 함수는 처음 한 번 대상 문자열을 지정해주면
		이후에는 대상 문자열이 어디에 있는지 알고 있음
		그래서 두 번째 호출부터는 NULL을 넣어서
		대상 문자열을 이어서 자를 수 있음
		원본 문자열의 내용이 바뀌므로 사용에 주의해야 함(기준 문자가
		NULL로 바뀜)
		*/
	}
		//문자열 포인터에 할당된 문자열 리터럴의 주소값은
		//읽기 전용이라서 strtok함수를 사용할 수 없음(에러 발생)
		//문자열 포인터에 동적 메모리를 할당하고 문자열을 복사하면
		//이 문제를 해결할 수 있음
		
	char *s2 = malloc(sizeof(char) * 30);

	strcpy(s2, "The Little Prince");

	char *ptr2 = strtok(s2, " ");

	while (ptr2 != NULL)
	{	printf("%s\n", ptr2);
		ptr2 = strtok(NULL, " ");
	}

	free(s2);

	/*
	strtok 함수는 공백 문자뿐만 아니라 다양한 특수 문자와 
	알파벳 영문자를 기준으로 문자열을 자를 수 있음
	다음 예제는 연-월-일T시:분:초 형식으로 된 문자열을 잘라서 출력함
	*/

	char s3[30] = "2017-6-20T21:01:50";

	char *ptr3 = strtok(s3, "-T:");
	//-, T, :을 기준으로 문자열을 자르므로 "-T:"와 같이 기준 문자를
	//여러 개 넣음

	while (ptr3 != NULL)
	{
		printf("%s\n", ptr3);
		ptr3 = strtok(NULL, "-T:");
	}

	/*
	자른 문자열 보관하기, 실제로 자른 문자열을 보관해서 사용하는
	경우가 많음
	*/
	
	char s4[30] = "The Little Prince";
	//char 크기 30개만큼 배열을 선언하고 문자열을 할당함
	char *sArr[10] = { NULL , };
	//문자열 포인터 10개를 담는 배열을 선언하고 모든 요소를 
	//NULL로 초기화함

	int i = 0;	//문자열 포인터 배열의 인덱스로 사용할 변수

	char *ptr4 = strtok(s4, " ");	//공백 문자열을 기준으로
	//문자열을 자름

	while (ptr4 != NULL)	//자른 문자열이 나오지 않을 때까지 반복
	{
		sArr[i] = ptr4;	//문자열을 자른 뒤 메모리 주소를 문자열
		//포인터에 저장함
		i++;
		ptr4 = strtok(NULL, " ");
		//다음 문자열을 잘라서 포인터를 반환함
	}

	for (i = 0; i < 10; i++)
	{
		if (sArr[i] != NULL)
			printf("%s\n", sArr[i]);
		else
			break;
	}
	/*
	#define _CRT_SECURE_NO_WARNINGS
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	int main()
	{
		char s10[1001];

		int count = 0;
		scanf("%[^\n]s", s10);
		
		char *ptr7 = strtok(s10, " -,.");

		while (ptr7 != NULL)
		{
			if (ptr7 != NULL &&strcmp(ptr7, "the") == 0)
				count++;
			ptr7 = strtok(NULL, " -,.");
		}

		printf("%d\n", count);
	
	}*/
	
	return 0;
}