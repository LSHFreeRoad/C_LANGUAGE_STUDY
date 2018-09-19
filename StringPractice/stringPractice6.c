#include<stdio.h>
#include<string.h>
int main()
{
	/*
	���ڿ����� ���ڿ� ���ڿ��� �˻��ϱ�, �����͸� �̿��ϴ� �����
	���ڷ� �˻��ϴ� ��� �� strchr�Լ��� ����ϸ� ���ڿ����� Ư��
	���ڷ� �˻��� �� �ְ� �Լ� �̸��� string character���� ����
	string.h������Ͽ� ���������, strchr(��� ���ڿ�, �˻��� ����)
	��ҹ��ڸ� ������, ���ڸ� ã������ �ش� ���ڷ� �����ϴ� 
	���ڿ��� �����͸� ��ȯ�ϰ� ���ڰ� ������ NULL�� ��ȯ��
	*/

	char s1[30] = "A Garden Diary";

	char *ptr = strchr(s1, 'a');
	//'a'�� �����ϴ� ���ڿ� �˻�, ������ ��ȯ


	while (ptr != NULL)//�˻��� ���ڿ��� ���� ������ �ݺ���
	{
		printf("%s\n", ptr);
		ptr = strchr(ptr + 1, 'a');
		//a ���� ���ں��� �˻��� 

	}

	/*
	���ڿ��� ������ ������ �������� ���� �˻��ϱ�
	strrchr �Լ��� �̿��ؼ� ���ڿ��� ������ ������ �������� 
	���ڸ� �˻���, string.h �� ����� ����
	string (find from the right) character���� ����
	��ҹ��ڸ� ������, strrchr(��� ���ڿ�, �˻��� ����);
	���ڸ� ã������ �ش� ���ڷ� �����ϴ� ���ڿ��� �����͸� ��ȯ 
	���ڰ� ������ NULL�� ��ȯ��
	*/

	char s2[30] = "A Garden Diary";

	char *ptr1 = strrchr(s2, 'a');
	

	printf("%s\n", ptr1);


	/*
	���ڿ� �ȿ��� ���ڿ��� �˻��ϱ�, strstr �Լ��� �̿��ؼ� ���ڿ�
	�ȿ��� ���ڿ��� �˻���, strstr �Լ��� string (find) string���� 
	����, string.h �� ����� ����, ������ ���ں��� ���ڿ� ã�⸦
	�� ���� �����, strstr(��� ���ڿ�, �˻��� ���ڿ�)
	���ڿ��� ã������ ���ڿ��� �����ϴ� ���ڿ��� �����͸� ��ȯ��
	���ڿ��� ������ NULL�� ��ȯ��
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