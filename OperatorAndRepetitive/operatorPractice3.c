#include<stdio.h>
#include<stdbool.h>
int main()
{
	/*��(boolean) �ڷ����� �� �ڷ����̶�� �ϸ� ����
	������ ��Ÿ��,  C ���� 0�� �������� 0�� �ƴ� ���ڸ� ������
	��Ÿ��, stdbool.h ��������� ����ϸ� true�� ������
	false�� �������� ��Ÿ�� ���� ����
		
	*/
	
	bool b1 = true;

	if (b1 == true)	//b1�� true�̹Ƿ� ���� ��
		printf("��\n");
	else
		printf("����\n");
	
	printf("int�� ũ�� : %zd\n", sizeof(int));
	printf("bool�� ũ�� : %zd\n", sizeof(bool));	
	//bool�� ũ�� :1����Ʈ

	printf("%d\n", true && true);
	printf("%d\n", true && false);
	printf("%d\n", false && true);
	printf("%d\n", false && false);
	printf("=========================\n");
	//stdbool.h���� �ڷ����� �Ұ��� ������ �� 
	//���� ���� �����ڴ� ���� 
	printf("%d\n", true || true);
	printf("%d\n", true || false);
	printf("%d\n", false || true);
	printf("%d\n", false || false);
	printf("=========================\n");

	bool b2 = true;
	bool b3 = false;

	printf(b2 ? "true\n" : "false\n");
	printf(b3 ? "true\n" : "false\n");

	printf("%s\n", b2 ? "true" : "false");
	printf("%s\n", b3 ? "true" : "false");

	if (true)
		printf("��\n");
	else
		printf("����\n");

	if (false)
		printf("��\n");
	else
		printf("����\n");

	printf("%d\n", true);
	printf("%d\n", false);


	return 0;
}