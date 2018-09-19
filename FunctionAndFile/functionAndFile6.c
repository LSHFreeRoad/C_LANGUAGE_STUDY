#define _CRT_SECURE_NO_WARNINGS
//fopen �Լ��� ���Ȱ�� ���� 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	/*
	������ ũ�Ⱑ �۴ٸ� ������ ó������ �о ��������� 
	ũ�Ⱑ ũ�ٸ� ó������ �д� ���� ��ȿ������ 
	���� �����͸� �̵����Ѽ� ������ ũ�⸦ ���ϱ� 
	������ �κ������� �а� ���� 
	fseek(���� ������, �̵��� ũ��, ������);
	�����ϸ� 0�� ��ȯ�ϰ� �����ϸ� -1�� ��ȯ�� 
	ftell(����������);
	���� �������� ���� ��ġ�� ��ȯ��, �����ϸ� -1�� ��ȯ�� 	
	*/

	int size;

	FILE *fp = fopen("hello.txt", "r");

	fseek(fp, 0, SEEK_END);
	//���� �����͸� ������ ������ �̵���Ŵ
	/*fseek�� ���������� �̵��� �Ÿ��� �����ؼ� ���� �����͸�
	�̵���Ŵ, ���� ���� �б�/���� �Լ��� ����ϸ� fseek���� 
	�̵���Ų ���� �������� ��ġ���� �б�/���⸦ �ϰԵ� 
	SEEK_SET: ������ ó������ �̵��� ���� 
	fseek(fp, 0, SEEK_SET);���� �����͸� ������ ó������ �̵���Ŵ
	SEEK_CUR: ���� ��ġ���� �̵��� ���� 
	fseek(fp, -10, SEEK_CUR);���� �����͸� ���� ��ġ���� 10����Ʈ
	��ŭ ���������� �̵���Ŵ(-10�� �����̱� ������)
	SEEK_END: ������ ������ �̵��� ������ 
	fseek(fp, 0, SEEK_END);���� �����͸� ������ ������ �̵���Ŵ
	�̵��� ũ�Ⱑ ����� ���������� �̵��ϰ� ������ ����������
	�̵��� 
	*/
	size = ftell(fp);
	//���� �������� ���� ��ġ�� ��ȯ�ؼ� 13�� ���� 

	printf("%d\n", size);

	fclose(fp);

	//������ ũ�⸦ ���ϴ� ����� �̿��ؼ� ������ ũ�⸸ŭ ���۸�
	//�����ؼ� ������ �о�� 

	char *buffer;
	int size2;
	unsigned long long count;

	FILE *fp2 = fopen("hello.txt", "r");

	fseek(fp2, 0, SEEK_END);
	//���� �����͸� ������ ������ �̵���Ŵ
	size2 = ftell(fp2);
	//���� �������� ���� ��ġ(=���� ũ��)�� ��ȯ�� 
	buffer = malloc(size2 + 1);
	//������ ���ڿ��� �о C ��� ���ڿ��� ���鶧�� ���ڿ�
	//�������� �� ���� �������� Ȯ���ؾ� �Ǽ� ����ũ�� + 1����Ʈ
	//��ŭ �޸𸮸� �Ҵ����� 

	memset(buffer, 0, size2 + 1);
	//malloc���� �Ҵ��� �޸𸮴� ������ ����ϴ� ����
	//���������Ƿ� memset �Լ��� �̿��ؼ� 0���� �ʱ�ȭ�� ���� 
	
	fseek(fp2, 0, SEEK_SET);
	//���� �����͸� ������ ó������ �̵���Ŵ 
	//rewind �Լ��� ����ؼ� ���� �����͸� ������ ó������ �̵�
	//��ų ���� ����-> rewind(fp2); ,stdio.h�� ���������
	
	count = fread(buffer, size2, 1, fp2);
	//hello.txt���� ����ũ�⸸ŭ ���� ���� 

	printf("%s size : %d, count : %llu\n", buffer, size2, count);
	//���� ����, ���� ũ��, ���� Ƚ�� ��� 
	fclose(fp2);
	//���� ������ �ݱ�

	free(buffer);
	//���� �޸� ���� 

	//fseek �Լ��� ����Ͽ� ���� �������� ��ġ�� ������ �� ������
	//������ �κ������� �б� 

	char buffer2[10] = { 0, };
	
	FILE *fp3 = fopen("hello.txt", "r");

	fseek(fp3, 2, SEEK_SET);
	//���� �����͸� ������ ó������ 2����Ʈ ��ŭ ���������� 
	//�̵���Ŵ 

	fread(buffer2, 3, 1, fp3);

	printf("%s\n", buffer2);
	memset(buffer2, 0, 10);

	fseek(fp3, 3, SEEK_CUR);
	fread(buffer2, 4, 1, fp3);

	printf("%s\n", buffer2);

	fclose(fp3);

	char *s1 = "abcd";
	char buffer3[20] = { 0, };
	FILE *fp4 = fopen("hello.txt", "r+");
	fseek(fp4, 3, SEEK_SET);
	fwrite(s1, strlen(s1), 1, fp4);

	rewind(fp4);
	fread(buffer3, 20, 1, fp4);

	printf("%s\n", buffer3);

	fclose(fp4);

	/*
	���ѵ� ���۷� ���� ��ü�� �о�� 
	feof(����������); ������ ���̸�1, ���� �ƴϸ� 0�� ��ȯ�� 
	*/

	char buffer4[5] = { 0, };
	size_t count2 = 0, total = 0;

	FILE *fp5 = fopen("hello.txt", "r");
	
	while (feof(fp5) == 0)
	{
		count2 = fread(buffer4, sizeof(char), 4, fp);
		printf("%s", buffer4);
		memset(buffer4, 0, 5);
		total += count2;
	}

	printf("\ntotal: %zd\n", total);

	fclose(fp5);

	FILE *fp7 = fopen("words.txt", "r");
	fseek(fp7, 0, SEEK_END);
	int size4 = ftell(fp7);
	char *buffer7 = malloc(size4 + 1);
	fseek(fp7, 0, SEEK_SET);
	memset(buffer7, 0, size4 + 1);
	fgets(buffer7, size4 + 1, fp7);
	for (int i = size4 - 1; i >= 0; i--)
	{
		fwrite(&buffer7[i], sizeof(char), 1, stdout);
	}
	printf("\n");

	fclose(fp7);
	free(buffer7);

	
	return 0;
}