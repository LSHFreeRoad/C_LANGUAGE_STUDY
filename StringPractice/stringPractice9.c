#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main()
{
	/*
	ȸ���� ������ �Ųٷ� �о ����� ���� �Ͱ� ���� �ܾ�� ����
	ȸ���� ������ ���⼭�� �м��� ���� ����
	N-gram�� ���ڿ����� N���� ���ӵ� ��Ҹ� �����ϴ� ���
	N-gram�� ������ �м�, �˻� ������ ���� ����
	������ å���� ��ĵ�ؼ� N-gram viewer�� ���� �������
	��������� �м���
	*/

	//ȸ��(palindrome)�� �Ųٷ� �о ����� ���� �Ͱ� ����
	//�ܾ�� ������ ���ϸ� ���� ��� "level" , "SOS", "rotator",
	//"nurses run"�� ���� �ܾ�� ������ �ִ� 
	//���ڿ��� ȸ������ �Ǻ��ϴ� ����� ù ��° ���ڿ� ������ ���ڰ�
	//���� �������� �� ���ھ� ������ �� ���ڰ� ���� ������ ȸ���̴�
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
		printf("ȸ��\n");
		count = 0;
	}

	*/

	char word[30];	//�ܾ ������ �迭
	unsigned long long length;	//���ڿ� ����
	bool isPalindrome = true;	//ȸ�� �Ǻ� ���� ������ ����

	printf("�ܾ �Է��ϼ���: ");
	scanf("%s", word);

	length = strlen(word); //���ڿ��� ���̸� ���� 

	//0���� ���ڿ��� ���̸� ���ݸ�ŭ �ݺ���
	for (int i = 0; i < length / 2; i++)
	{
		// ���� ���ڿ� ������ ���ڸ� ���ؼ� ���ڰ� �ٸ��� ȸ���� �ƴ�
		if (word[i] != word[length - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	printf("%d\n", isPalindrome);

	/*
	N-gram�� ���ڿ����� N���� ���ӵ� ��Ҹ� �����ϴ� ���
	Hello ���ڿ��� ���� ���� 2-gram���� ����
	He, el, ll, lo, ���ڿ��� ó������ ������ �̵��ϸ鼭
	2���ڸ� ������
	*/

	char text[30] = "Hello";
	unsigned long long length2;

	length2 = strlen(text);

	for (int i = 0; i < length2 - 1; i++)
	{
		printf("%c%c\n", text[i], text[i + 1]);
	}

	//2-gram�̹Ƿ� ���ڿ��� ������ �� ���� �ձ����� �ݺ���

	char text2[30] = "Hello";
	unsigned long long length3;

	length3 = strlen(text2);

	for (int i = 0; i < length3 - 2; i++)
	{
		printf("%c%c%c\n", text2[i], text2[i + 1], text2[i + 2]);
	}

	//2-gram�̹Ƿ� ���ڿ��� ������ �� ���� �ձ����� �ݺ���

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

	//�ܾ� ���� 2-gram�� ���
	//2-gram�̹Ƿ� tokens �迭�� ���������� ��� �� �� �ձ�����
	//�ݺ��ϸ鼭 ���� ���ڿ��� �� ���� ���ڿ��� ����ϸ� ��

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