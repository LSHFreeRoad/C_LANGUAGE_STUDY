#define _CRT_SECURE_NO_WARNINGS
//strcpy �Լ��� ���� ���� ������ �߻��� �� �����Ƿ�
#include <stdio.h>
#include <string.h> //strlen�� ������ִ� �������
int main()
{
	/*
	���ڿ��� ���̴� strlen(string length���� ����)�Լ��� ���� ��
	����, strlen(���ڿ� ������ or ���� �迭), 
	�����ϰ� ���ڿ��� ���̸� ����
	NULL �κ��� �������� �ʰ� NULL �ٷ� �ձ����� ����
	*/

	char *s1 = "Hello";
	char s2[10] = "Hello";

	printf("%zd\n", strlen(s1));
	printf("%zd\n", strlen(s2));

	/*
	strcmp �Լ��� ����ϸ� �� ���ڿ��� ������ ���� ���� ����
	strcmp string compare ���� ����
	strcmp() -> ��ȣ �ȿ� ���� �� ���ڿ��� �־��ָ� ��
	-1 ��ȯ : ASCII �ڵ� �������� ���ڿ�2(s2)�� Ŭ �� 
	0 ��ȯ : ASCII �ڵ� �������� �� ���ڿ��� ���� ��
	1 ��ȯ : ASCII �ڵ� �������� ���ڿ�1(s1)�� Ŭ ��
	���ڿ��� �������� ���ڿ� �񱳿� ������ ���� ����
	���ڿ� �����Ϳ� NULL�� �� �ִٸ� ������ �߻���
	strcmp�Լ��� ���ڿ����� ù ��° ���ں��� ���ʴ�� ���ϸ� 
	�񱳱����� �� ������ ASCII�ڵ� ����

	*/

	
	int ret = strcmp(s1, s2);

	printf("%d\n", ret);


	char s3[20];
	char s4[20];

	printf("���ڿ� �� ���� �Է��ϼ���: ");
	scanf("%s %s", s3, s4);

	int ret1 = strcmp(s3, s4);

	switch (ret1)
	{
	case -1:
		printf("%s���� %s�� ŭ\n", s3, s4);
		break;
	case 0:
		printf("�� ���ڿ��� ����\n");
		break;
	case 1:
		printf("%s���� %s�� ŭ\n", s4, s3);
		break;
	}
	

	return 0;
}