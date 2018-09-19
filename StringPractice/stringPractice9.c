#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main()
{
	/*
	회문은 순서를 거꾸로 읽어도 제대로 읽은 것과 같은 단어와 문장
	회문은 유전자 염기서열 분석에 많이 쓰임
	N-gram은 문자열에서 N개의 연속된 요소를 추출하는 방법
	N-gram은 빅데이터 분석, 검색 엔진에 많이 쓰임
	구글은 책들을 스캔해서 N-gram viewer를 만들어서 사람들의
	언어패턴을 분석함
	*/

	//회문(palindrome)은 거꾸로 읽어도 제대로 읽은 것과 같은
	//단어와 문장을 말하며 예를 들면 "level" , "SOS", "rotator",
	//"nurses run"과 같은 단어와 문장이 있다 
	//문자열이 회문인지 판별하는 방법은 첫 번째 글자와 마지막 글자가
	//같고 안쪽으로 한 글자씩 좁혔을 때 글자가 서로 같으면 회문이다
	/*

	char s2[30] = "level";
	char s3[30] = "rotator";

	int count = 0;

	for (int i = 0; i < (strlen(s2) / 2); i++)
	{
		if (strlen(s2) % 2 == 1)
		{
			s2[i] == (s2[strlen(s2) - (i + 1)]);
			count++;
		}
		else
		{
			s2[i] == (s2[strlen(s2) - (i + 1)]);
			count++;
		}
	}

	if (count == (strlen(s2) / 2))
	{
		printf("회문\n");
		count = 0;
	}

	*/

	char word[30];	//단어를 저장할 배열
	unsigned long long length;	//문자열 길이
	bool isPalindrome = true;	//회문 판별 값을 저장할 변수

	printf("단어를 입력하세요: ");
	scanf("%s", word);

	length = strlen(word); //문자열의 길이를 구함 

	//0부터 문자열의 길이를 절반만큼 반복함
	for (int i = 0; i < length / 2; i++)
	{
		// 왼쪽 문자와 오른쪽 문자를 비교해서 문자가 다르면 회문이 아님
		if (word[i] != word[length - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	printf("%d\n", isPalindrome);

	/*
	N-gram은 문자열에서 N개의 연속된 요소를 추출하는 방법
	Hello 문자열을 문자 단위 2-gram으로 추출
	He, el, ll, lo, 문자열의 처음부터 끝까지 이동하면서
	2글자를 추출함
	*/

	char text[30] = "Hello";
	unsigned long long length2;

	length2 = strlen(text);

	for (int i = 0; i < length2 - 1; i++)
	{
		printf("%c%c\n", text[i], text[i + 1]);
	}

	//2-gram이므로 문자열의 끝에서 한 글자 앞까지만 반복함

	char text2[30] = "Hello";
	unsigned long long length3;

	length3 = strlen(text2);

	for (int i = 0; i < length3 - 2; i++)
	{
		printf("%c%c%c\n", text2[i], text2[i + 1], text2[i + 2]);
	}

	//2-gram이므로 문자열의 끝에서 한 글자 앞까지만 반복함

	char text3[100] = "this is c language";
	char *tokens[30] = { NULL, };
	int count = 0;

	char *ptr = strtok(text3, " ");

	while (ptr != NULL)
	{
		tokens[count] = ptr;
		count++;

		ptr = strtok(NULL, " ");
	}

	for (int i = 0; i < count - 1; i++)
	{
		printf("%s %s\n", tokens[i], tokens[i + 1]);
	}

	//단어 단위 2-gram을 출력
	//2-gram이므로 tokens 배열의 마지막에서 요소 한 개 앞까지만
	//반복하면서 현재 문자열과 그 다음 문자열을 출력하면 됨

	/*
	#include<stdio.h>
	#include<string.h>
	#include<stdbool.h>
	#include<stdlib.h>
	#define _CRT_SECURE_NO_WARNINGS
	int main()
	{

		char s5[31];
		char *ptr3;
		char *ptr4 = malloc(sizeof(char) * 31);

		scanf("%[^\n]s", s5);

		ptr3 = strtok(s5, " ");
		strcpy(ptr4, ptr3);

		while(true)
		{
			ptr3 = strtok(NULL, " ");
			if (ptr3 == NULL)
				break;
			strcat(ptr4, ptr3);
		}

		unsigned long long legnth5 = strlen(ptr4);

		bool isPalindrome2 = true;

		for (int i = 0; i < legnth5 / 2; i++)
		{
			if (ptr4[i] != ptr4[legnth5 - 1 - i])
			{
				isPalindrome2 = false;
				break;
			}
		}

		printf("%d\n", isPalindrome2);

		free(ptr4);


		return 0;

	}
	*/
	/*
	#include<stdio.h>
	#include<string.h>
	#define _CRT_SECURE_NO_WARNINGS
	int main()
	{
		char s7[12];
		int num7, length7;

		scanf("%d %s", &num7, s7);

		length7 = strlen(s7);

		if(length7 < num7)
			printf("%s\n", "wrong");
		else
			for (int i = 0; i < (length7 - num7 + 1); i++)
			{
				for (int j = 0; j < num7; j++)
				{
					printf("%c", s7[i + j]);
				}
				printf("\n");
			}
		return 0;
	}

	*/


	return 0;
}