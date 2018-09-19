#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	/*
	���ڿ��� �ٸ� �迭�̳� ������(�޸�)�� ������ ���� �ִ�.
	strcpy�Լ��� ���ڿ��� �ٸ� ������ �����ϸ� string copy����
	����, strcpy(��� ���ڿ�, ���� ���ڿ�);
	��� ���ڿ��� �����͸� ��ȯ��, string.h��� ���Ͽ� ����� ����
	strcpy�Լ��� ���� ������ ���ؼ� ���� ��� �߻��ϱ� ������
	_CRT_SECURE_NO_WARNINGS�� �Է������ ��,

	*/

	char s1[10] = "Hello";
	char s2[10];

	strcpy(s2, s1);

	printf("%s\n", s2);
	printf("s1�� �޸� �ּ�: %p\n", s1);
	printf("s2�� �޸� �ּ�: %p\n", s2);


	//s2�� s1�� ���ڿ��� ������. �̶� ����� ����� ����� �迭��
	//ũ��� �ݵ�� NULL���� �� �� �־�� �� 

	/*
	char *s1 = "Hello";
	char *s2 ="";

	strcpy(s2, s1);

	printf("%s\n", s2);

	���ڿ� �����Ϳ� ���ڿ��� ������ ���� ����. �ֳ��ϸ� s2��
	����� �޸� �ּҴ� ������ ������ ���� �б⸸ �� �� �ְ� ���Ⱑ
	��������, ���ڿ� �����Ϳ� ���ڿ��� �����Ϸ��� ���ڿ��� ��
	������ ���� �����ؾߵ�

	*/

	char *s3 = "Hello";
	char *s4 = malloc(sizeof(char) * 10);
	//char 10�� ũ�⸸ŭ �������� �޸𸮸� �Ҵ�
	//�̷��� �ϸ� strcpy�Լ��� s1�� ���ڿ��� s2�� ������ �� ����
	strcpy(s4, s3);
	printf("%s\n", s4);

	free(s4);

	/*
	���ڿ��� strcat �Լ��� ����Ͽ� ���� ���� �� �ְ� �Լ� �̸���
	string concatenate���� ����, string.h ������Ͽ� ����� ����
	strcat(�������ڿ�, ���Ϲ��ڿ�), �������ڿ��� �����͸� ��ȯ��
	strcat�Լ��� ���� ��� �߻��ϹǷ� _CRT_SECURE_NO_WARNINGS�� 
	����
	*/

	char s5[10] = "World";
	char s6[20] = "Hello";
	//���ڿ��� ���� �� NULL���� ������ ���� ���ڿ� �迭�� ũ�⸦
	//�˳��ϰ� ����
	strcat(s6, s5);

	printf("%s\n", s6);

	char *s7 = "World";
	char *s8 = malloc(sizeof(char) * 20);

	strcpy(s8, "Hello");

	strcat(s8, s7);

	printf("%s\n", s8);

	free(s8);

	//���ڿ� ������ s8�� �ڿ� ���� ������ ���� �б� ����
	//�޸��̱� ������ ���ڿ��� ���� �� ���� 
	//���ڿ��� ���̷��� s8�� ���Ⱑ �����ϵ��� 
	//malloc�Լ��� ���� �޸𸮸� �Ҵ��ϰ� ���ڿ��� ���� �� �ֵ���
	//������ �˳��ϰ� 20���� ������

	//�޸𸮰� �Ҵ�� ���ڿ� �����ʹ� ���ڿ��� = ��ȣ�� ���� 
	//�Ҵ��� �� �����Ƿ� strcpy�Լ��� �̿��ؼ� s8�� "Hello"
	//���ڿ��� ������, strcat�Լ��� ���ڿ� ������ s8�ڿ� 
	//���ڿ� ������ s7�� ����

	//malloc�Լ��� s10�� �޸𸮸� �Ҵ���. �Ҵ��� �޸� ������
	//����� ���ڿ����� Ŀ����. �׸��� strcpy�Լ��� s9�� ���ڿ���
	//s10�� ������

	char s9[10] = "Hello";
	char *s10 = malloc(sizeof(char) * 10);

	strcpy(s10, s9);

	printf("%s\n", s10);
	free(s10);

	char s11[10] = "world";
	char *s12 = malloc(sizeof(char) * 20);

	strcpy(s12, "Hello");

	strcat(s12, s11); 

	printf("%s\n", s12);
	free(s12);
	
	return 0;
}