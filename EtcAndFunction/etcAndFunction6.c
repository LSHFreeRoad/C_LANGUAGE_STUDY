#include <stdio.h>
#include <stdlib.h>
void swapNumber(int first, int second)
{
	int temp;

	temp = first;
	first = second;
	second = temp;
	//�Ű������� ���� �����ϴ� ���Ҹ� �� �� �Լ� �ٱ��� �����ʹ�
	//����� ����, first�� second�� �Լ� �������� ��ȿ�� 
}

void swapNumber2(int *first, int *second)
{
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
	//�Լ� �ȿ��� �޸� �ּҿ� �����ؼ� ���� ������ 
	//�Լ��� �Ű������� �����ͷ� ����ϸ� �Լ� �ٱ����� ���� ���� 
	//������ ���� ����
}	

enum TYPE {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT
};

void swapValue(void *ptr1, void *ptr2, enum TYPE t)
{	//void �����ʹ� �������� �� �� �����Ƿ� � �ڷ������� ����������
	//�˷��ֱ� ���ؼ� TYPE �������� ����, �Լ� �������� TYPE ��������
	//���� �� �ڷ����� �����ͷ� ��ȯ�� �� �������Ͽ� ���� ���� �ٲ�
	switch (t)
	{
	case TYPE_CHAR:
	{
		char temp;
		temp = *(char *)ptr1;
		*(char *)ptr1 = *(char *)ptr2;
		*(char *)ptr2 = temp;
		break;
	}
	case TYPE_INT:
	{
		int temp;
		temp = *(int *)ptr1;
		*(int *)ptr1 = *(int *)ptr2;
		*(int *)ptr2 = temp;
		break;
	}
	case TYPE_FLOAT:
	{
		float temp;
		temp = *(float *)ptr1;
		*(float *)ptr1 = *(float *)ptr2;
		*(float *)ptr2 = temp;
		break;
	}
	}
	//void ������ �Ű������� ������ �޸� �ּһӸ� �ƴ϶� �޸𸮸�
	//�Ҵ��� �����͵� ���� �� ����, ���� �Ϲ� �ڷ����� ������ �Ӹ���
	//�ƴ϶� ����ü ,����ü, ������ ���� �����͵� ���� �� ����
}
//void allocMemory(void *ptr, int size)
//{
//	ptr = malloc(size);
//	//ptr�� �޸𸮸� �Ҵ��غ��� allocMemory �Լ��� ����� ����� 
//	//���� ����, �޸� ������ �߻��ϰ� ��
//}

void allocMemory(void **ptr, int size)
{
	*ptr = malloc(size);
	//void ���� �����Ͱ� long long �������� �޸� �ּҸ� ���� �ڿ� 
	//void ���� �����͸� �������ؼ� void *ptr�� �ǵ��� ���� �ڿ� 
	//malloc �Լ��� �޸𸮸� �Ҵ���, �����δ� numPtr�� �޸𸮸�
	//�Ҵ��ϰ� ��
}

void helloString(char *s1)
{	//�Ű������� ���ڿ� �����ͷ� ������ 
	printf("Hello, %s\n", s1);
}

void helloString2(char s1[])
{	//�Ű������� char�� �迭�� ������
	//�Ű������� char s1[]�� ���� �����ϴ��� �迭�� �ƴ϶� ���ڿ��̳�
	//�޸𸮰� �Ҵ�� �����͵� ������ �� ���� 
	printf("Hello, %s\n", s1);
}

int main()
{
	int num1 = 10;
	int num2 = 20;

	swapNumber(num1, num2);

	printf("%d %d\n", num1, num2);

	int num3 = 10, num4 = 20;

	swapNumber2(&num3, &num4);
	//num3�� num4�� �޸� �ּ� ���� 

	printf("%d %d\n", num3, num4);

	/*
	���ݱ��� scanf �Լ��� ����� �� ������ �׳� ���� �ʰ� ������
	�޸� �ּҸ� �־��µ� �� ������ scanf �Լ��� ���� ���� �� �Է�
	���� �� �ִµ� ��ȯ�� �����δ� ���� ���� ���� �Լ� �ٱ����� 
	������ ���� ������ ������, ������ �޸� �ּҸ� �Ѱ��ָ� ����
	�� ������ ������� ���� ������ �� ���� 	
	*/

	char c1 = 'a', c2 = 'b';
	swapValue(&c1, &c2, TYPE_CHAR);
	printf("%c %c\n", c1, c2);

	int num5 = 10, num6 = 20;
	swapValue(&num5, &num6, TYPE_INT);
	printf("%d %d\n", num5, num6);

	float num7 = 1.234567f, num8 = 7.654321f;
	swapValue(&num7, &num8, TYPE_FLOAT);
	printf("%f %f\n", num7, num8);

	long long *numPtr = NULL;
	
	//allocMemory(numPtr, sizeof(long long));

	allocMemory(&numPtr, sizeof(long long));
	//long long �������� �޸� �ּҴ� long long ���� �����Ϳ�
	//�����Ƿ� void ���� ������ �Ű������� ���� ���� ���� 

	*numPtr = 10;
	printf("%lld\n", *numPtr);

	free(numPtr);

	helloString("world!");
	//���ڿ��� �ּҰ� �Ű������� ����� 

	char s1[10] = "world!";

	helloString(s1);

	helloString2("world!");
	
	/*
	int getQuotientAndRemainder(int num1, int num2, int *remainder)
	{	
		 int quotient = num1 / num2;
		 *remainder = num1 % num2;
		 return quotient;
	}

	void allocArray(void **ptr, int m, int s)
	{
		*ptr= malloc(s * m);		
	}

	void printFullName(char s1[], char s2[])
	{
		printf("%s%s\n", s1, s2);
	}

	*/

	return 0;
}