#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
	/*
	���ڿ��� Ư�� ���ڸ� �������� �ڸ���, strtok�Լ��� �̿��ϸ�
	�ǰ� �Լ� �̸��� ���ڿ��� ����(token)���� ������(string toknize)
	���� ����, string.h �� ����Ǿ� ���� 
	strtok(����ڿ�, ���ع���);
	�ڸ� ���ڿ��� ��ȯ, ���� �ڸ� ���ڿ��� ������ NULL�� ��ȯ��
	strtok�Լ��� ���� ����� �߻��ϹǷ� 
	#define _CRT_SECURE_NO_WARNINGS�� �־���
	*/

	char s1[30] = "The Little Prince";

	char *ptr = strtok(s1, " ");
	//���� ����(" ")�� �־��ָ� �������� �����Ͽ� ���ڿ��� �ڸ�
	//�� ���� ���ڸ� (' ')�� ������ �� ��, strtok�Լ��� 
	//�߸� ���ڿ��� �� ���� ���� �� ���� ������ while �ݺ�������
	//���ڿ��� ��� �ڸ��ٰ� ���ڿ��� ������ ������ �ݺ����� 
	//������ ������� �����

	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
		/*�ڸ� ���ڿ� �κп� NULL�� �־���, NULL�� �־��� ��
		���� strtok�Լ����� ó���ߴ� ���ڿ�����
		�߸� ���ڿ���ŭ ���� ���ڷ� �̵��� �� ���� ���ڿ��� �ڸ�
		���� ptr = strtok(ptr, " "); ó�� �߸� ���ڿ���
		�����͸� �ٽ� �־��� ���� ���� ���ڷ� �̵����� ���ϰ�
		ó���� ������ ���ڿ��� ��� �ڸ��� ��
		strtok �Լ��� ����� ���� ó������ �ڸ� ���ڿ��� �־��ְ�
		�� �������ʹ� NULL�� �־��ش�
		strtok�Լ��� ���ۼ��� �� ó�� ȣ��Ǵ� strtok�� 
		" "(���鹮��)�� ã�Ƽ� NULL�� ä�� �ڿ� ���ڿ��� ù �κ��� 
		"The"�� �ڸ� �� while �ݺ��� �ȿ��� strtok�� NULL�� �־��־�
		�տ��� �߸� ���ڿ���ŭ ���� ���ڷ� �̵��� 
		-> ��� ���� ������ �ݺ��ϴٰ� ���鹮�ڸ� ������ ���ϸ� 
		NULL�� ��ȯ�ϰ� while �ݺ����� ����
		strtok() �Լ��� ó�� �� �� ��� ���ڿ��� �������ָ�
		���Ŀ��� ��� ���ڿ��� ��� �ִ��� �˰� ����
		�׷��� �� ��° ȣ����ʹ� NULL�� �־
		��� ���ڿ��� �̾ �ڸ� �� ����
		���� ���ڿ��� ������ �ٲ�Ƿ� ��뿡 �����ؾ� ��(���� ���ڰ�
		NULL�� �ٲ�)
		*/
	}
		//���ڿ� �����Ϳ� �Ҵ�� ���ڿ� ���ͷ��� �ּҰ���
		//�б� �����̶� strtok�Լ��� ����� �� ����(���� �߻�)
		//���ڿ� �����Ϳ� ���� �޸𸮸� �Ҵ��ϰ� ���ڿ��� �����ϸ�
		//�� ������ �ذ��� �� ����
		
	char *s2 = malloc(sizeof(char) * 30);

	strcpy(s2, "The Little Prince");

	char *ptr2 = strtok(s2, " ");

	while (ptr2 != NULL)
	{	printf("%s\n", ptr2);
		ptr2 = strtok(NULL, " ");
	}

	free(s2);

	/*
	strtok �Լ��� ���� ���ڻӸ� �ƴ϶� �پ��� Ư�� ���ڿ� 
	���ĺ� �����ڸ� �������� ���ڿ��� �ڸ� �� ����
	���� ������ ��-��-��T��:��:�� �������� �� ���ڿ��� �߶� �����
	*/

	char s3[30] = "2017-6-20T21:01:50";

	char *ptr3 = strtok(s3, "-T:");
	//-, T, :�� �������� ���ڿ��� �ڸ��Ƿ� "-T:"�� ���� ���� ���ڸ�
	//���� �� ����

	while (ptr3 != NULL)
	{
		printf("%s\n", ptr3);
		ptr3 = strtok(NULL, "-T:");
	}

	/*
	�ڸ� ���ڿ� �����ϱ�, ������ �ڸ� ���ڿ��� �����ؼ� ����ϴ�
	��찡 ����
	*/
	
	char s4[30] = "The Little Prince";
	//char ũ�� 30����ŭ �迭�� �����ϰ� ���ڿ��� �Ҵ���
	char *sArr[10] = { NULL , };
	//���ڿ� ������ 10���� ��� �迭�� �����ϰ� ��� ��Ҹ� 
	//NULL�� �ʱ�ȭ��

	int i = 0;	//���ڿ� ������ �迭�� �ε����� ����� ����

	char *ptr4 = strtok(s4, " ");	//���� ���ڿ��� ��������
	//���ڿ��� �ڸ�

	while (ptr4 != NULL)	//�ڸ� ���ڿ��� ������ ���� ������ �ݺ�
	{
		sArr[i] = ptr4;	//���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ�
		//�����Ϳ� ������
		i++;
		ptr4 = strtok(NULL, " ");
		//���� ���ڿ��� �߶� �����͸� ��ȯ��
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