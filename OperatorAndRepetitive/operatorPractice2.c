#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	�� �����ڴ� ���ǽ��̳� ���� �������� �Ǵ���  
	if ���ǹ����� ���ǽ��� �Ǵ��� �� �ַ� �����
	&& : AND(����), ���� ��� ���� �� ����
	|| : OR(����), ���� �� �� �ʸ� ���̶� ����
	! : NOT(�� ����), ���� ������ ������
	������ 0�� ����ϰ� ���� ���� 1�� ����� 

	*/
	
	//c ������ 0�� �ƴ� ��� ���� ���� 
	printf("%d\n", 1 && 1);	//�� �� ���̾�� �� 
	//�� ���꿡�� �߿��� �κ��� �ܶ�
	//���ε� �ܶ��򰡴� ù ��° ���� ����� Ȯ���� �� 
	//�� ��° ���� Ȯ��(��)���� �ʴ� ����̴�
	printf("%d\n", 1 && 0);	//ù ��° ���� �����̸�
	//�� ��° ���� ������� ��ü ������ ����(0)�� �� 
	printf("%d\n", 0 && 1);
	printf("%d\n", 0 && 0);
	printf("%d\n", 2 && 3);
	printf("===================\n");
	
	printf("%d\n", 1 || 1);	//�ϳ��� ���̸� ���� �� 
	printf("%d\n", 1 || 0);
	printf("%d\n", 0 || 1);
	printf("%d\n", 0 || 0);
	printf("%d\n", 2 || 3);
	printf("===================\n");

	printf("%d\n", !1);
	printf("%d\n", !0);
	printf("%d\n", !3);
	printf("===================\n");

	int num1 = 20, num2 = 10, num3 = 30, num4 = 15;

	printf("%d\n", num1 > num2 && num3 > num4);	
	//���� ��� ���̾ ��
	printf("%d\n", num1 > num2 && num3 < num4);
	//�ո� ���̹Ƿ� ����
	printf("%d\n", num1 > num2 || num3 < num4);
	//�տ� ���� ���̹Ƿ� �� 
	printf("%d\n", num1 < num2 || num3 < num4);
	//���� ��� �����̹Ƿ� ����
	printf("%d\n", !(num1 > num2));
	//���� not ������ ����
	printf("===================\n");

	int num5 = 1, num6 = 0;

	if (num5 && num6)	//num6�� �����̹Ƿ� ���� 
		printf("��\n");
	else
		printf("����\n");


	if (num5 || num6)	//num5�� ���̹Ƿ� ��
		printf("��\n");	
	else
		printf("����\n");

	if (!num5)	//
		printf("��\n");
	else
		printf("����\n");

	printf("=====================\n");
	int num7 = 1, num8 = 0;
	printf("%s\n", num7 && num8 ? "��" : "����");
	printf("%s\n", num7 || num8 ? "��" : "����");
	
	int num9, num10;
	
	scanf("%d %d", &num9, &num10);
		
	printf("%s\n", num9 && num10 ? "��" : "����");
	printf("%s\n", num9 || num10 ? "��" : "����");
	printf("%s\n", !num9 ? "��" : "����");


	return 0;
}