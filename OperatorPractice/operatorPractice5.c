#include<stdio.h>
int main()
{
	//���� �ٸ� �ڷ������� ������ �� ����
	//������ ��Ģ�� ����

	int num1 = 11;
	float num2 = 4.4f;

	printf("%f\n", num1 + num2);
	printf("%f\n", num1 - num2);
	printf("%f\n", num1 * num2);
	printf("%f\n", num1 / num2);

	//������ �Ǽ��� ���� -> ����� �Ǽ� 
	//�Ǽ��� ������ �������� �� ũ�� ������ 
	//ǥ�� ������ ���� ������ �ڵ� ��ȯ��
	//�� �������� �Ǽ��� �ڵ���ȯ
	//�ڷ����� ���� ���� �����Ϸ����� 
	//�Ͻ��� ����ȯ(implicit type conversation)�� ��
	//�ڷ����� ũ�Ⱑ ū ��, ǥ�� ������ ���� ������
	//�ڵ���ȯ��,
	//�̸� �� Ȯ��(type promotion)�̶���(���� ������)

	long long num3 = 34283408298484;
	int num4 = 3;

	//long long�� int���� �ڷ��� ũ�Ⱑ ũ�Ƿ�
	//���� �ÿ� long long���� �� Ȯ���� �߻���

	printf("======================\n");
	printf("%lld\n", num3 + num4);
	printf("%lld\n", num3 - num4);
	printf("%lld\n", num3 * num4);
	printf("%lld\n", num3 / num4);

	/*
	�ڷ����� ũ�Ⱑ ���� ��, ǥ�� ������ ���� ������
	��ȯ�Ǵ� ���� �� ���(type demotion)�̶�� ��

	�� ��Ұ� �Ͼ�� ���� �ս��� �Ͼ
	������ ��� ������ �ʰ� �Ϸ���
	�� ��ȯ(type conversation, type casting)�� �ؾߵ�
	*/

	float num5 = 11.0f;
	float num6 = 5.0f;

	int num7 = (int)(num5 / num6);	//2.2 -> 2

	printf("%d\n", num7);



	char num8 = 28;
	int num9 = 1000000002;

	char num10 = num8 + num9;

	printf("%d\n", num10);

	/*
	num10�� �������
	num8 = 28
	= 0001 1100
	num9 = 1000000002
	= 0011 1011 1001 1010 1100 1010 0000 0010

	num10 = 0011 1011 1001 1010 1100 1010 0001 1110
	-------------------------------------==========
	�� �ڸ� ���� ����					���

	char �ڷ����� ũ�⿡ �°� ����ǰ� �� �ڸ�����
	������

	����(����)		����			�Ǽ�	  �� ���
				long long			long double	 ���
		�� ���  long	   �� ���	double		 �Ӥ�
	1.char	<---  int		 <----  float		 �Ӥ�
		--->	  short int	  --->				 �ӡ�
		�� Ȯ��				�� Ȯ��			�� Ȯ��

	*/

	return 0;

}