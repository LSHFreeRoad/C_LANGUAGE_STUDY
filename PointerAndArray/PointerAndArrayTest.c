#include <stdio.h>
int main()
{


	//2���� �迭�� �����Ϳ� �������� Ư���� ����� �ʿ���
	//�ڷ��� (*�������̸�)[����ũ��];
	//int (*numPtr)[4]; �� ���� ũ�Ⱑ 4�� �迭��
	//����Ű�� �����Ͷ�� ����
	//int *numPtr[4] ��int�� ������ 4���� ���� �� �ִ� �迭

	int numArr4[3][4] = {
		{ 11,22,33,44 },
		{ 55,66,77,88 },
		{ 99,110,121,132 }
	};
	int(*numPtr)[4] = numArr4;

	printf("%p\n", numArr4);
	//���� ù ��° ��(numArr4[0])�� �ּҰ�
	printf("%p\n", &numArr4);
	printf("%p\n", numArr4 + 1);
	//���� �� ��° ���� �ּҰ�
	printf("%p\n", numPtr);
	//���� ù ��° ���� �ּҰ�
	printf("%p\n", numPtr + 1);
	//���� �� ��° ���� �ּҰ� 
	printf("%d\n", **numPtr);
	//ù ��° ����� ��
	printf("%p\n", *numPtr);
	//���� ù ���� ù ��° ���(numArr4[0][0])�� �ּҰ�
	printf("%p\n", numArr4[0]);
	//���� ù ���� ù ��° ���(numArr4[0][0])�� �ּҰ�
	printf("%p\n", *numPtr + 1);
	//���� ù ���� �� ��° ���(numArr4[0][1])�� �ּҰ�

	printf("%p\n", *numArr4);

	printf("%lld %lld %lld \n", sizeof(numArr4), sizeof(*numArr4), sizeof(**numArr4));
	printf("%lld %lld %lld\n", sizeof(numPtr), sizeof(*numPtr), sizeof(**numPtr));

	return 0;
}