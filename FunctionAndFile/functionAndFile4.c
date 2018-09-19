#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return (a / b);
}

/*�Լ� �����͸� ����ü ����� ����Ϸ��� ����ü�� ������ ��
����� �������ָ� ��
struct ����ü�̸� {
	��ȯ�� �ڷ���(*�Լ��������̸�)(�Ű����� �ڷ���1, �Ű����� 
	�ڷ���2)
};
*/

struct Calc {
	int(*fpC)(int, int);
};

/* �Լ� �����͸� �Ű������� ��ȯ������ ����ϱ� 
�Լ� �����͸� �Ű������� ����Ϸ��� �Լ��� ���� �� �Ű�����
�κп� �Լ� �����͸� �־��ָ� ��
��ȯ�� �ڷ��� �Լ��̸�(�Լ� ������ ��ȯ���ڷ���
(*�Լ� �������̸�)(�Լ� ������ �Ű����� �ڷ���1,
�Լ� ������ �Ű����� �ڷ���2))
{
}

*/

void executer(int(*fp)(int, int))
{
	//�Լ��� ���� �� �Ű����� �κп� �Լ� �����͸� �״�� 
	//������ָ� �� 
	printf("%d\n", fp(10, 20));
}

//�Լ� �����͸� �Լ��� ��ȯ������ ����ϱ� 
/* �Լ� �������� ��ȯ�� �ڷ���(*�Լ��̸�())(�Լ� �������� �Ű�
���� �ڷ���1, 2)
{
	return add; 
	//add �Լ��� �޸� �ּҸ� ��ȯ�� 
}
*/


int (*getAdd())(int, int)
{	
	return add;
}


char *dokrib(int money, int year, char *res)
{
	sprintf(res, "%d�� �� %d���� ��Ƽ� �����ϱ�"
		, year, money);
	return res;
}


char* (*getDokrib(int x, int y))(int, int, char*)
{
	printf("����: %d�� %d����\n", x, y);
	return dokrib;
}

typedef int(*FP)(int, int);

FP getADD()
{	//�Լ� ������ ��Ī�� �Լ��� ��ȯ������ ������ �� ���� 
	return add;
}

struct Calc2 {
	FP fp;
};

void executer2(FP fp)
{
	printf("%d\n", fp(70, 80));
}

int main()
{
	/*
	�Լ� �����͵� �������̹Ƿ� �����ͷ� �� �� �ִ�
	�۾��� �״�� ������ ������, 
	�����͸� �迭�� �����, ����ü ����� ����ϱ�
	�Լ��� �Ű������� ��ȯ������ ����ϱⰡ ������	
	*/

	int funcNumber;
	int num1, num2;
	int(*fp)(int, int) = NULL;

	printf("�Լ� ��ȣ�� ����� ���� �Է��ϼ���: ");
	scanf("%d %d %d", &funcNumber, &num1, &num2);

	switch (funcNumber)
	{
	case 0:
		fp = add;
		break;
	case 1:
		fp = sub;
		break;
	case 2:
		fp = mul;
		break;
	case 3:
		fp = div;	
		break;
	}

	printf("%d\n", fp(num1, num2));
	
	

	/*
	�Լ��� ��ȣ�� ��Ÿ������ �ʹ� ������� �Ǵµ� �̶� 
	�Լ� �����͸� �̿��ϸ� ��������	
	�Լ� ������ �迭�� �Լ� �����͸� ������ �� �Լ� ������ 
	�̸� �� []�ȿ� ũ�⸦ �����ϸ� ��
	��ȯ�� �ڷ��� (*�Լ������� �̸�[ũ��])(�Ű����� �ڷ���1, 
	�Ű����� �ڷ��� 2);	
	*/

	int(*fparr[4])(int, int);

		fparr[0] = add;
		//ù ��° ��ҿ� ���� �Լ��� �޸� �ּҸ� ������  
		fparr[1] = sub;
		fparr[2] = mul;
		fparr[3] = div;
	
	printf("�Լ� ��ȣ�� ����� ���� �Է��ϼ���: ");
	scanf("%d %d %d", &funcNumber, &num1, &num2);
	printf("%d\n", fparr[funcNumber](num1, num2));

	struct Calc c;

	c.fpC = add;
	//����ü ������ ������ �ڿ� .���� �Լ� ������ ����� 
	//�����ؼ� add �Լ��� �޸� �ּҸ� ������ 

	printf("%d\n", c.fpC(10, 20));
	//����ü ����� �Լ� �����ͷ� add�Լ��� ȣ���� 

	executer(add);

	printf("%d\n", getAdd()(10, 20));
	//getAdd �Լ��� ȣ���ϸ� add �Լ��� �����Ͱ� ��ȯ�Ǹ�
	//�� �ڿ� �ٷ� ��ȣ�� �ٿ��� add�Լ��� ȣ����

	char result[50];

	printf("%s\n", getDokrib(21, 200)(2000, 5, result));
	
	/*
	���ݱ��� �Լ� �����͸� ���� �� int (*fp)(int,int); ó��
	������ ��ȯ�� �ڷ����� �Ű����� �ڷ����� �������
	�̷� ����� full pointer type�̶�� �ϴµ� ����ϱⰡ
	����ϱ� ���ŷο� typedef�� ��Ī�� �����ϸ� �Լ� �����͸�
	�Ź� ������ �ʾƵ� �� 
	typedef ��ȯ���ڷ��� (*�Լ� ������ ��Ī)(�Ű����� �ڷ���1,
	�Ű����� �ڷ���2);	
	*/

	printf("%d\n", getADD()(10, 20));

	FP fp1;
	fp1 = add;
	printf("%d\n", fp1(10, 20));

	FP fp2[10];
	fp2[0] = add;
	printf("%d\n", fp2[0](30, 40));

	struct Calc2 c2;
	c2.fp = add;
	printf("%d\n", c2.fp(50, 60));

	executer2(sub);

	/*	
	void (*getPrintFunc(struct Person *p))(struct Person *)
	{
		return p->print;
	}
	
	
	
	
	
	*/

	return 0;
}