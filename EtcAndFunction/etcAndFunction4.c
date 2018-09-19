#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int one()
{
	return 1;
}

float realNumber()
{
	return 1.234567f;
}

bool truth()
{
	return true;
}

int two()
{
	return (int)2.2f;
}

float SevenPointSeven()
{
	return 7.7f;
}

int *ten()
{
	//int num5 = 10;

	//return &num5;
	//���� ������ �ּҸ� ��ȯ�ϴ� ����� �߸��� ����� -> ������ ���
	//��� ����� 10�� �� ������ ���� ���� ���α׷��� �ſ� �����ؼ�
	//10�� ����� ������ ���� �������� �ʾұ� ������, ���α׷���
	//���������� ����� ���� ������ ������ �ٸ� ������ ����Ἥ
	//���� ������ �������� ����.(ȯ�濡 ���� 10�� �� ���� �� ����)

	int *numPtr = malloc(sizeof(int));
	*numPtr = 10;
	return numPtr;
	//�����͸� ��ȯ�Ϸ��� ������ ���� malloc �Լ��� �޸𸮸� �Ҵ��� ��
	//��ȯ�ؾ� ��. malloc���� �޸𸮸� �Ҵ��ϸ� �Լ��� ������
	//free�Լ��� �����ϱ� �������� ������� ����

}
char *helloLiteral()
{
	char *s1 = "Hello, world!";

	return s1;

	//���ڿ� ���ͷ��� �ּҸ� �����Ϳ� ������ �� ��ȯ�� 
	//�ҽ��ڵ� �� �Է��� ���ڿ� ���ͷ��� ���������� ����� ��
	//�޸𸮿� ����ǹǷ� �Լ��� ����Ǵ��� ��� ����� ���� ����
}

char *helloDynamicMemory()
{
	char *s1 = malloc(sizeof(char) * 20);

	strcpy(s1, "Hello, world!");

	return s1;

	//���ڿ� �����Ϳ� ���� �޸𸮸� �Ҵ��� �� strcpy�Լ��� ���ڿ���
	//������, �̶��� �ݵ�� free �Լ��� ���� �޸𸮸� �����ؾ� �� 
}
void *allocMemory()
{
	void *ptr = malloc(100);
	//100����Ʈ ��ŭ�� ���� �޸� �Ҵ� 

	return ptr;
	//void ������ ��ȯ 
}

struct Person {
	char name[20];
	int age;
	char address[100];
};

struct Person getPerson()
{
	//����ü�� ��ȯ�ϴ� �Լ��� �����Ϸ��� �̷��� struct Ű�����
	//����ü �̸��� �Լ� �̸� �տ� �ٿ��ָ� ��
	struct Person p;
	
	strcpy(p.name, "ȫ�浿");
	p.age = 30;
	strcpy(p.address, "����� ��걸 �ѳ���");

	return p; //����ü ���� ��ȯ
}

struct Person *allocPerson()
{
	//��ȯ���� �ڷ����� ����ü �����ͷ� �������� 
	struct Person *p = malloc(sizeof(struct Person));
	
	strcpy(p->name, "ȫ�浿");
	p->age = 30;
	strcpy(p->address, "����� ��걸 �ѳ���");

	return p;
	//�Լ� �ȿ��� ����ü �����Ϳ� �޸𸮸� �Ҵ��ϰ� ���� ������ ��
	//����ü �����͸� ��ȯ��
}

union Box {
	short candy;
	float snack;
	char doll[8];
};

enum BOX_TYPE {
	BOX_PAPER = 0,
	BOX_WOOD,
	BOX_PLASTIC
};

union Box getBox()
{
	union Box b;
	b.candy = 0x1002;

	return b;
}

enum BOX_TYPE getBoxType()
{
	return BOX_WOOD;
}

typedef struct {
	char disease[30];
	char worry[10];
	int age;
} Pain, *PPain;

PPain getPain()
{
	PPain p = malloc(sizeof(Pain));

	strcpy(p->disease, "atopy and allergic coryza");
	strcpy(p->worry, "army");
	p->age = 21;

	return p;
}

int main()
{
	/*
	�Լ����� ���� �������� ���-> ��ȯ��(return value)�� �����
	��ȯ���� �Լ��� ȣ���� �ٱ��� �ᱣ���� �˷��ֱ� ���� �����
	��ȯ���ڷ��� �Լ��̸�()
	{
		�ڵ�
		return ��ȯ��;
	}
	�߿��� ���� ��ȯ���� ��ȯ���� �ڷ����� ��ġ�ؾ� �ȴٴ� ��
	��ȯ���� ������ ��ȯ�� �ڷ����� ������ �ش��ϴ� int, long���� ����
	�Ǽ��� float, double ���� ��� ��. 
	*/

	int num1;

	num1 = one();
	//��ȯ���� �����Ϸ��� ������ ������ �Ҵ� ������(=)�� ����� ��
	//�Լ��� ȣ�����ָ� ��. ��ȯ���� �ڷ����� ��ȯ���� ������ ������
	//�ڷ����� ���ƾ� ��

	printf("%d\n", num1);

	float num2;
	bool b1;
	
	num2 = realNumber();
	b1 = truth();

	printf("%f\n", num2);
	printf("%d\n", b1);

	//���� ��ȯ���� �ڷ����� ��ȯ�ϴ� ���� �ڷ����� �ٸ� ���� �ڷ���
	//��ȯ��Ģ�� ������ ��. ���� ������ ��� �߻��ϸ� �ڷ����� 
	//���������� ��ȯ�ؼ� ��ȯ�ϰų� ��ȯ�� ���� �ڷ����� ��ȯ��Ű�� ��

	int num3 = two();

	printf("%d\n", num3);

	printf("%d\n", (int)SevenPointSeven());

	int *numPtr = ten();

	printf("%d\n", *numPtr);

	free(numPtr);

	char *s1, *s2;

	s1 = helloLiteral();
	s2 = helloDynamicMemory();

	printf("%s\n%s\n", s1, s2);
	
	free(s2);
	
	/*
	�ڷ����� ������� ���� �������� �ʹٸ� � �ڷ������� ��
	�����͵��� ���� �� �ִ� void �����͸� Ȱ���ϸ� ����
	*/

	//void�����ʹ� �پ��� �����ͷ� �ڵ� ��ȯ��

	char *s3 = allocMemory();
	//allocMemory���� ��ȯ�� void �����͸� ���ڿ� �����Ϳ� �־
	//���ڿ�ó�� �����
	strcpy(s3, "Hello, world!");
	printf("%s\n", s3);
	free(s3);
	//allocMemory���� malloc�Լ��� ����ϰ� �����Ƿ� allocMemory����
	//��ȯ�� �����͸� ����� ������ �ݵ�� free�Լ��� ������ �����

	int *numPtr1 = allocMemory();
	//allocMemory���� ��ȯ�� void �����͸� int �����Ϳ� �־ 
	//int�� �迭ó�� ����� ���� ����
	numPtr1[0] = 10;
	numPtr1[1] = 20;
	printf("%d %d\n", numPtr1[0], numPtr1[1]);
	free(numPtr1);

	/*C ���� �Լ��� ���� �ϳ��� ��ȯ��, �̶� ���� ������ 
	��ȯ������ �������� ����ü�� Ȱ���ϴ� ���� ����
	�Լ����� ����ü�� ��ȯ�ϸ� �����͸� ���
	�� ���� ������ ���� ����
	struct ����ü �̸� �Լ��̸�()
	{
		return ����ü ����; 
	}
	*/

	struct Person p1;

	p1 = getPerson();
	//��ȯ�� ����ü ������ ������ ��� p1���� ����� 

	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("�ּ�: %s\n", p1.address);
	
	/*
	����ü ũ�Ⱑ Ŀ���� ������ ������ �׸�ŭ �� �ʿ��ϰ� �Ǿ� ������
	����ǹǷ� ��ȿ������, ����ü�� ��ȯ�Ҷ��� ����ü ���簡 �Ͼ��
	�ʵ��� malloc�Լ��� ���� �޸𸮸� �Ҵ��� �� ����ü �����͸�
	��ȯ�ϴ� ���� ����. ����ü �����͸� ��ȯ�ϴ� �Լ��� ����ü �̸���
	�Լ� �̸� ���̿� *�� ���� 
	
	struct ����ü �̸� *�Լ��̸�()
	{
		return ����ü ������();
	}
	*/

	struct Person* p2;

	p2 = allocPerson();
	//���� allocPerson �Լ��� ȣ���� �� ��ȯ�� �����͸� p2�� ������
	//����ü�� ������ �������� �ʱ� ������ �ξ� ȿ������ 

	printf("�̸�: %s\n", p2->name);
	printf("����: %d\n", p2->age);
	printf("�ּ�: %s\n", p2->address);

	free(p2);
	//�޸� ����� �������� �ݵ�� free�Լ��� �������� 

	union Box box;
	enum BOX_TYPE boxType;

	box = getBox();
	boxType = getBoxType();
	
	printf("0x%x\n", box.doll[1]);
	printf("%d\n", boxType);
	
	PPain painPerson = getPain();
	
	printf("���� : %s\n", painPerson->disease);
	printf("��� : %s\n", painPerson->worry);
	printf("���� : %d\n", painPerson->age);

	/*
	float getArmor()
	{
		return 20.5f;
	}
	bool hasSlowSkill()
	{
		return false;
	}
	
	char* getName()
	{
		char * c1 = malloc(sizeof(char) * 8);

		strcpy(c1, "Neptune");
	
		return c1;
	}
	
	void *allocMemory()
	{
		void *ptr = malloc(sizeof(char) * 8);	

		return ptr;
	}
	
	struct Point2D *allocPoint2D()
	{
		struct Point2D *ptr = malloc(sizeof(struct Point2D));
		
		ptr->x = 90;
		ptr->y = 75;
	
		return ptr;
	}

	*/
	return 0;
}