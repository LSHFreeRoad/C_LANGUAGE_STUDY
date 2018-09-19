#include<stdio.h>
int main()
{
	/*
	��ȣ �ִ� ������ ���� ������ ��Ʈ ������ ����� �ٸ�
	*/
	unsigned char num1 = 1; //0000 0001: 1 

	printf("%d\n", num1 << 1);	//0000 0010 : 2->2�� 1����
	printf("%d\n", num1 << 2);	//0000 0100 : 4->2�� 2����
	printf("%d\n", num1 << 3);	//0000 1000 : 8->2�� 3����
	printf("%d\n", num1 << 4);	//0001 0000 : 16->2�� 4����
	printf("%d\n", num1 << 5);	//0010 0000 : 32->2�� 5����
	printf("%d\n", num1 << 6);	//0100 0000 : 64->2�� 6����
	printf("%d\n", num1 << 7);	//1000 0000 : 128->2�� 7����

	unsigned char num2 = 240;	//240: 1111 0000
	unsigned char num3 = 15;	// 15: 0000 1111

	unsigned char num4, num5;

	num4 = num2 << 2;
	num5 = num3 >> 2;

	printf("%u\n", num4);	//192 : 1100 0000
	printf("%u\n", num5);	//3: 0000 0011
	//����Ʈ ������ �� �� ù ° �ڸ�(�ֻ��� ��Ʈ)��
	//������ �ڸ��� ��Ʈ(������ ��Ʈ)�� ������� �ǰ�
	//�� �ڸ��� 0�� ä������.

	unsigned char num6 = 131;	//131: 1000 0011
	char num7 = -125;	// -125: 1000 0011
	

	unsigned char num8;
	char num9;

	num8 = num6 >> 5;
	num9 = num7 >> 5;

	printf("%d\n", num8);	//0000 0100 : 4
	printf("%d\n", num9);	//1111 1100 : -4
	//��ȣ �ִ� �ڷ����� ���������� �̵���Ű�� ���ڶ�
	//��Ʈ�� ��ȣ ��Ʈ�� ä����
	//��ȣ ���� �ڷ����� ���������� �̵���Ű�� ���ڶ�
	//��Ʈ�� 0���� ä����	
	char num10 = 67;	//67 : 0100 0011 
	char num11;

	num11 = num10 >> 5;	// : 0000 0010
	//���ڶ� ��Ʈ�� ��ȣ ��Ʈ�� 0���� ä�� 
	printf("%d\n", num11);	

	char num12 = 113;	//113: 0111 0001
	char num13 = -15;	//-15: 1111 0001
	char num14, num15, num16, num17;

	num14 = num12 << 2;	
	num15 = num13 << 2;

	num16 = num12 << 4;
	num17 = num13 << 4;

	printf("%d\n", num14);	//1100 0100 ->��ȣ ��Ʈ�� �ٲ�
	printf("%d\n", num15);	//1100 0100 ->��ȣ ��Ʈ ����
	printf("%d\n", num16);	//0001 0000 ->��ȣ ��Ʈ ���� 
	printf("%d\n", num17);	//0001 0000 ->��ȣ ��Ʈ�� �ٲ�
	//�÷���(flag)�� ��߿��� ������ ����̴�.
	//���� ����� ���� �ø��� on, �Ʒ��� ������ off�� ����
	//�̰� ������ ��Ʈ�� Ȱ���ϴ� �ǵ� 
	//��Ʈ�� 1�̸� on, 0�̸� off�� ��Ÿ����
	//8��Ʈ ũ���� �ڷ����� ��Ʈ�� 8���̹Ƿ� 8���� ���¸�
	//������ �� �ִ� 0100 0001->2��°, 8��° ��Ʈ�� ��������
	//4����Ʈ �ڷ����� 32��Ʈ�̹Ƿ� 32���� ���¸� 
	//������ �� �ִ� 
	//Ư�� ��Ʈ�� �� ���� �÷��� |= ����ũ
	//�÷����� ��Ʈ�� �����ϰų� �˻��� �� ����ϴ� ���ڸ�
	//����ũ�����
	unsigned char flag = 0;

	flag |= 1;	//0000 0001
	//����ũ�� ��ƮOR �����ڷ� ���� ��° ��Ʈ�� ��
	flag |= 2;	//0000 0010
	//����ũ�� ��ƮOR �����ڷ� �ϰ� ��° ��Ʈ�� ��
	flag |= 4;	//0000 0100
	//����ũ�� ��ƮOR �����ڷ� ���� ��° ��Ʈ�� ��
	
	printf("%u\n", flag);	//0000 0111 : 7

	if (flag & 1)	//&�����ڷ� ���� ��° ��Ʈ�� �����ִ���
		//Ȯ����
		printf("0000 0001�� ��������\n");
	else
		printf("0000 0001�� ��������\n");

	if (flag & 2)	//&�����ڷ� �ϰ� ��° ��Ʈ�� �����ִ���
		//Ȯ����
		printf("0000 0010�� ��������\n");
	else
		printf("0000 0010�� ��������\n");

	if (flag & 4)	//&�����ڷ� ���� ��° ��Ʈ�� �����ִ���
		//Ȯ����
		printf("0000 0100�� ��������\n");
	else
		printf("0000 0100�� ��������\n");

	
	//�÷����� ��Ʈ�� �� ���� �÷��� &= ~����ũ
	unsigned char flag2 = 7;

	flag2 &= ~2;	//1111 1101, ����ũ �� 2�� ��Ʈ�� 
	//������ �� ��Ʈ AND �����ڷ� �ϰ� ��° ��Ʈ�� ��
	//���� ���� ��Ʈ �̿��� ���� ��� 1�� ��
	//0000 0111
	//1111 1101
	//0000 0101
	printf("%u\n", flag2);	//0000 0101

	if (flag2 & 1)	
		//&�����ڷ� ���� ��° ��Ʈ�� �����ִ��� Ȯ����
		printf("0000 0001�� ��������\n");
	else
		printf("0000 0001�� ��������\n");

	if (flag2 & 2)	
		//&�����ڷ� �ϰ� ��° ��Ʈ�� �����ִ��� Ȯ����
		printf("0000 0010�� ��������\n");
	else
		printf("0000 0010�� ��������\n");

	if (flag2 & 4)	
		//&�����ڷ� ���� ��° ��Ʈ�� �����ִ��� Ȯ����
		printf("0000 0100�� ��������\n");
	else
		printf("0000 0100�� ��������\n");

	//�÷����� ��Ʈ�� ���(���� ������ ���� ���� ������
	//Ű�� ���� ����)�ϴ� ����� �÷��� ^= ����ũ
	unsigned char flag3 = 7;	//0000 0111

	flag3 ^= 2;	//0000 0010 
	flag3 ^= 8;	//0000 1000
	//�÷����� ��Ʈ�� ����ϴ� ������ ��Ʈ XOR��������
	//Ư���� Ȱ���� ����
	//�� ��Ʈ�� �ٸ��� 1 ������ 0�� �ȴ�.
	//���� flag�� ��Ʈ�� 1�̶�� ����ũ�� 1�� �����Ƿ� 
	//0�̵ǰ� 0�̶�� ����ũ�� 1�� �ٸ��Ƿ� 1�� �Ǵ� ������
	//������ Ŀ���� �ҽ��ڵ带 ���ų� �ϵ��� 
	//�ٷ� �� ����
	printf("%u\n", flag3);	//13: 0000 1101

	if (flag3 & 1)
		//&�����ڷ� ���� ��° ��Ʈ�� �����ִ��� Ȯ����
		printf("0000 0001�� ��������\n");
	else
		printf("0000 0001�� ��������\n");

	if (flag3 & 2)
		//&�����ڷ� �ϰ� ��° ��Ʈ�� �����ִ��� Ȯ����
		printf("0000 0010�� ��������\n");
	else
		printf("0000 0010�� ��������\n");

	if (flag3 & 4)
		//&�����ڷ� ���� ��° ��Ʈ�� �����ִ��� Ȯ����
		printf("0000 0100�� ��������\n");
	else
		printf("0000 0100�� ��������\n");
	
	if (flag3 & 8)
		//&�����ڷ� �ټ� ��° ��Ʈ�� �����ִ��� Ȯ����
		printf("0000 1000�� ��������\n");
	else
		printf("0000 1000�� ��������\n");

	return 0;
}