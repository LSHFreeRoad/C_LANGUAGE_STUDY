#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	/*
	C �� ��� ���� �ܼ�(�͹̳�, ��� ������Ʈ)â����
	Ű����� ���ڸ� ������ϰ� �� 
	ǥ�� �Է�(��� ������Ʈ���� Ű���� �Է�)
	=standard input, stdin
	ǥ�� ���(��� ������Ʈ���� ��� ���)
	=standard output, stdout
	
	scanf(����, ������ �ּ�)
	int scanf(char const *const_Format, ...)
	�����ϸ� ������ ���� ������ ��ȯ,
	�����ϸ� EOF(-1)�� ��ȯ
	
	scanf�� ǥ�� �Է����� ������� �Է��� �޴� �Լ� 
	stdio.h ������Ͽ� ����� ���� 
	
	scanf�Լ����� ù ��° ���ڴ� ���� ������ %d�� �־
	������ �Է¹޵��� ��, �� ��° ���ڴ� �Է°��� ������
	������ �־����
	#define _CRT_SECURE_NO_WARNINGS
	visual studio�� ������ ��, �������� OS X����
	���� �ʿ䰡 ����
	scanf�� ������ ������ �Լ��� �Է°��� ���̸� ������ ����
	��� ���ȿ� �����-> visual studio���� ������� �����
	��� ��µǰ� ������ ������ �߻���
	-> #define _CRT_SECURE_NO_WARNINGS
	(���ȿ� ����� �Լ��� ������ ���� ������ ������
	�߻���Ű�� ����� �ǹ�) 
	scanf_s�� �Է°��� ���̸� ������ ���� ������ C��� 
	ǥ���Լ��� �ƴϰ� Visual Studio(Visual C++) ������
	*/

	int num1;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &num1);
	printf("%d\n", num1);

	int num2, num3;

	printf("������ �� �� �Է��ϼ��� : ");
	scanf("%d %d", &num2, &num3);
	//�Է¹��� �����ϰ� ���� ������ ���� �� ���� ������ 
	//�Ȱ��� ����� �� , �׸��� ���� �տ� &�� �� ����� 
	printf("%d %d\n", num2, num3);

	float num4;

	printf("�Ǽ��� �Է��ϼ��� : ");
	scanf("%f", &num4);
	printf("%f\n", num4);

	double num5;

	printf("�Ǽ��� �Է��ϼ��� : ");
	scanf("%lf", &num5);
	printf("%f\n", num5);

	long double num6;

	printf("�Ǽ��� �Է��ϼ��� : ");
	scanf("%Lf", &num6);
	printf("%Lf\n", num6);

	char c1;
	scanf("%c", &c1);

	char c2;
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%c", &c2);	//���� �ϳ��� �Էµ� 
	printf("%c\n", c2);
	
	char cb;
	scanf("%c", &cb);

	printf("���ڸ� �Է��ϼ��� : ");
	char c3 = getchar();	//���� �ϳ��� �Է¹���
	printf("%c\n", c3);

	return 0;
	
}