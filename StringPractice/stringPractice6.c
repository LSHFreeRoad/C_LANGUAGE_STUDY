#include<stdio.h>
#include<string.h>
int main()
{
	/*
	문자열에서 문자와 문자열로 검색하기, 포인터를 이용하는 방식임
	문자로 검색하는 방법 → strchr함수를 사용하면 문자열에서 특정
	문자로 검색할 수 있고 함수 이름은 string character에서 따옴
	string.h헤더파일에 선언되있음, strchr(대상 문자열, 검색할 문자)
	대소문자를 구분함, 문자를 찾았으면 해당 문자로 시작하는 
	문자열의 포인터를 반환하고 문자가 없으면 NULL을 반환함
	*/

	char s1[30] = "A Garden Diary";

	char *ptr = strchr(s1, 'a');
	//'a'로 시작하는 문자열 검색, 포인터 반환


	while (ptr != NULL)//검색된 문자열이 없을 때까지 반복함
	{
		printf("%s\n", ptr);
		ptr = strchr(ptr + 1, 'a');
		//a 다음 문자부터 검색함 

	}

	/*
	문자열의 오른쪽 끝부터 역순으로 문자 검색하기
	strrchr 함수를 이용해서 문자열의 오른쪽 끝부터 역순으로 
	문자를 검색함, string.h 에 선언되 있음
	string (find from the right) character에서 따옴
	대소문자를 구분함, strrchr(대상 문자열, 검색할 문자);
	문자를 찾았으면 해당 문자로 시작하는 문자열의 포인터를 반환 
	문자가 없으면 NULL을 반환함
	*/

	char s2[30] = "A Garden Diary";

	char *ptr1 = strrchr(s2, 'a');
	

	printf("%s\n", ptr1);


	/*
	문자열 안에서 문자열을 검색하기, strstr 함수를 이용해서 문자열
	안에서 문자열을 검색함, strstr 함수는 string (find) string에서 
	따옴, string.h 에 선언되 있음, 실제로 문자보단 문자열 찾기를
	더 자주 사용함, strstr(대상 문자열, 검색할 문자열)
	문자열을 찾았으면 문자열로 시작하는 문자열의 포인터를 반환함
	문자열이 없으면 NULL을 반환함
	*/

	char s3[30] = "A Garden Diary";

	char *ptr2 = strstr(s3, "den");

	printf("%s\n", ptr2);

	char s4[100] = "A Garden Diary A Garden Diary A Garden Diary";

	char *ptr3 = strstr(s4, "den");

	while (ptr3 != NULL)
	{
		printf("%s\n", ptr3);
		ptr3 = strstr(ptr3 + 1, "den");
	}

	/*
	#include<stdio.h>
	#include<string.h>
	int main()
	{
		char *s1 = malloc(sizeof(char) * 1001);

		int count = 0;

		scanf("%[^\n]s", s1);
		char *ptr = strchr(s1, ' '); 


		while(ptr != NULL)
		{
			count++;
			ptr = strchr(ptr + 1, ' '); 

		}

		printf("%d\n", count);

		return 0;
	}
	*/


	return 0;
}