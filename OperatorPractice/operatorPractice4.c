#include<stdio.h>
int main()
{
	printf("%d\n", 1 % 3);	//������ 1
	printf("%d\n", 2 % 3);
	printf("%d\n", 3 % 3);
	printf("%d\n", 4 % 3);
	printf("%d\n", 5 % 3);
	printf("%d\n", 6 % 3);
	//������ �����ڴ� Ư�� ���� �������
	//Ȯ���� �� �����
	//�� ���� ���·� ������ ���� ����� 
	//0���� ���� �������� ���� �� ���� 

	int num1 = 7;

	num1 = num1 % 2;
	//num1�� 2�� ���� �������� num1�� �Ҵ�
	printf("%d\n", num1);

	int num2 = 11;

	num2 %= 3;	//num2�� 3���� ���� ��������
				//num2�� �Ҵ� 
	printf("%d\n", num2);




	return 0;





}