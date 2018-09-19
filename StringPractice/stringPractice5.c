#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*
	ȭ�鿡 ������� �ʰ� ���ڿ��� ���� ���� �����ϴ� ���
	sprintf �Լ��� ����ϸ� ������ �����Ͽ� 
	���ڿ��� ���� ���� �ִ�. stdio.h�� ����Ǿ� �ִ�.
	sprintf(�迭, ����, ��); �����ϸ� ���ڿ��� ���̸� ��ȯ�ϰ�
	�����ϸ� ������ ��ȯ��, sprintf �Լ��� ���� ��� �߻��ϹǷ�
	#define _CRT_SECURE_NO_WARNINGS�� �־���ߵ�	
	*/

	char s1[20];

	sprintf(s1, "Hello, %s", "world!");
	//%s�� world!�� �ٲ�� s1�� ������ ��, s1�� ���� ���ڿ���
	//������ �� �迭�� ����(buffer)��� �θ�

	printf("%s\n", s1);

	char s2[30];

	sprintf(s2, "%c %d %f %e\n", 'a', 10, 3.2f, 1.123456e-21f);
	//������ ���Ŀ� ���߾� ���� ���ڿ��� �ٲ� �� ���� 

	printf("%s", s2);

	/*
	���ڿ� �����Ϳ� ���ڿ��� ������
	���ڿ� �����͸� ����Ϸ��� malloc �Լ��� �޸𸮸� �Ҵ��� �� 
	sprintf�Լ��� ���ڿ��� ����� ��
	sprintf(���ڿ� ������, ����, ��);

	*/

	char *s3 = malloc(sizeof(char) * 20);
	//���ڿ��� ������ �޸� ������ ���ۿ� �ش���

	sprintf(s3, "Hello, %s", "world!");
	printf("%s\n", s3);

	free(s3);


	char *s4 = malloc(sizeof(char) * 30);
	//���ڿ��� ������ �޸� ������ ���ۿ� �ش���

	sprintf(s4, "%c %d %f %e", 'a', 10, 3.2f, 1.123456e-21f);
	//������ ���Ŀ� ���߾� ���� ���ڿ��� �ٲ� �� ���� 

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