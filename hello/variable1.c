//����:���� �����ϴ� �������� �׸��� �����

// int -> �ڷ���(Ÿ��) , num1 : ���� �̸� 
//������ ����� ���� -> ������ �����ϴ�.
//int -> ������ ���ϴ� integer�� �����
//C ���� ������ ���� ������ ���� �ڷ����� �޶��� 
//C ���� ���� ���� ������ "������ �����Ѵ�"��� ��
//�׸��� ������ ������ ����  �� �ڿ� ;�� �ٿ�����Ѵ�
//������ �����Ѵٰ� �ϴ� ������ 
//C ���� ������ ������ �Ʒ��� �ؼ��Ǳ� ������ 
//������ ����Ϸ��� ����ϴ� �κк��� ���� ����
//������ ������ �Ǿ��־�� ������ 
//���� ���� = ������ �ִٴ� ���� �˷��ִ� ���� �ǹ���
//������ ��Ģ: #1. ���� ���ڿ� ���� ��밡��
//#2. ��ҹ��� ����, #3. ���ں��� �����ؾ���
//���ں��� �����ϸ� �� ��
//#4. ���� ����(_)�� ������ ������
//#5. C ��� Ű����(int,float,if,for ��)�� ��� �Ұ�


#include<stdio.h>
int main() 
{
	int num1;
	int num2;
	int num3;

	num1 = 10;	//������ �� ���� = ������ �� �Ҵ�
	num2 = 20;	// =�� num1�� 10�� �Ҵ��Ѵٴ� �ǹ�
	num3 = 30;	// ���� 1 =���� 2 ��밡��

	printf("%d %d %d\n", num1, num2, num3);
	//%d�� 10����(decimal)�� ����� �� ����ϴ� 
	//���� ������ 
	//���� ������ �ϳ��� ����(��)�ϳ��� ������
	
	//*���� ���� �� ���� ���
	//�ڷ��� ����1,����2,����3;

	return 0;	//�Լ� �ٱ����� ���� �����ϴ� ��ȯ�� �κ�
}