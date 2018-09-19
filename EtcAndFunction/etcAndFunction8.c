#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct Person {
	char name[20];
	int age;
	char address[100];
};

void printPerson(struct Person p)
{
	printf("�̸�: %s\n", p.name);
	printf("����: %d\n", p.age);
	printf("�ּ�: %s\n", p.address);
}

void setPerson(struct Person p)
{
	strcpy(p.name, "��浿");
	p.age = 30;
	strcpy(p.address, "����� ���ʱ� ������");
}

void setPerson2(struct Person *p)
{
	//�Ű������� ����ü �����ͷ� �����ϰ� �Լ� �ȿ��� �����ͷ�
	//���� ����ü ����� ���� ������ 
	strcpy(p->name, "��浿");
	p->age = 40;
	strcpy(p->address, "����� ���ʱ� ������");
}

void printPerson2(struct Person *p)
{
	printf("�̸�: %s\n", p->name);
	printf("����: %d\n", p->age);
	printf("�ּ�: %s\n", p->address);
}

typedef struct {
	char carName[10];
	int productionYear;
	char feature[20];
} CAR, *PCAR;

void carOption(PCAR pCar)
{
	strcpy(pCar->carName, "�ҳ�Ÿ");
	pCar->productionYear = 2011;
	strcpy(pCar->feature, "���� ����");
}

union HandPhone {
	char name[20];
	int productionYear;
	double price;	
};

enum BOX_TYPE {
	PAPER =0,
	WOOD,
	PLASTIC
};

void printHandPhone(union HandPhone *handPhone)
{

	strcpy(handPhone->name, "galuxy S note 8");
	printf("�ڵ��� ����: %s\n", handPhone->name);

	handPhone->productionYear = 2017;
	printf("�ڵ��� ����⵵: %d\n", handPhone->productionYear);

	handPhone->price = 300000;
	printf("�ڵ��� ����: %f��\n", handPhone->price);

}

void printBoxType(enum BOX_TYPE boxType)
{
	printf("%d\n", boxType);
}

void getSize(char buffer[], char *ptr)
{
	printf("�Լ� ������ char�� �迭ũ��: %zd\n", sizeof(buffer));
	printf("�Լ� ������ char�� ������ũ��: %zd\n", sizeof(ptr));
}

int main()
{
	/*
	�Լ����� �����ؾ� �� �Ű������� ���� �� ����ü�� ��� 
	�����ϸ� �������� 
	��ȯ�� �ڷ��� �Լ� �̸�(struct ����ü �̸� �Ű�����)
	{
	}	
	*/

	struct Person p1;

	strcpy(p1.name, "ȫ�浿");
	p1.age = 30;
	strcpy(p1.address, "����� ��걸 �ѳ���");

	printPerson(p1);
	//�Լ��� ȣ���� �� ����ü ������ ��� ����� �Ű������� �����
	//�� ����ü ũ�Ⱑ Ŀ���� ������ ������ �׸�ŭ �� �ʿ��ϹǷ�
	//������ ����Ǿ� ��ȿ������, ���� �Ű������� ����ü�� ������
	//���� �����͸� Ȱ���ϴ� ���� ���� 

	setPerson(p1);

	printf("�̸�: %s\n", p1.name);
	printf("����: %d\n", p1.age);
	printf("�ּ�: %s\n", p1.address);

	//�Ű������� ���� ���޵� �� ����ü ����� ��� ����Ǿ����Ƿ�
	//�Լ� �ȿ��� ����ü ����� �ƹ��� �����ص�
	//�ٱ��� �ִ� ����ü �������� ������ ��ġ�� ����

	/*
	����ü �����͸� �Ű������� ����ϱ�
	��ȯ�� �ڷ��� �Լ� �̸�(struct ����ü �̸� *�Ű�����)
	{
	}
	*/

	struct Person p2;

	strcpy(p2.name, "ȫ�浿");
	p2.age = 30;
	strcpy(p2.address, "����� ��걸 �ѳ���");

	setPerson2(&p2);
	//�ּ� �����ڸ� ����ؼ� ����ü ����� ���� ������� �ʰ�
	//����ü ���� p2�� �޸� �ּҸ� ������
	//�Լ� setPerson������ �ٱ��� ����� ����ü ������ ����
	//�����ϰ� ��

	printf("�̸�: %s\n", p2.name);
	printf("����: %d\n", p2.age);
	printf("�ּ�: %s\n", p2.address);

	/*
	�Լ��� ����ü �����͸� �Ѱ��� ���� ���� ���ͷ��� ����ؼ� ���ͷ� �տ� 
	&�� ���̸� ��
	&(struct ����ü �̸�) {.��� �̸�1= ��1, .��� �̸�2= ��2}
	&(struct ����ü �̸�) {��1, ��2}
	*/

	printPerson2(&(struct Person) {.name = "ȫ�浿", .age = 30,
		.address = "����� ���ʱ� ����1��"
	});

	printPerson2(&(struct Person) { "����", 30,
		"���� �ϻ굿�� ǳ��" });

	PCAR pCar = malloc(sizeof(CAR));

	carOption(pCar);

	printf("�� ����: %s\n", pCar->carName);
	printf("�� ����⵵: %d\n", pCar->productionYear);
	printf("�� Ư¡: %s\n", pCar->feature);

	union HandPhone *handPhone = malloc(sizeof(union HandPhone));

	printHandPhone(handPhone);

	free(handPhone);

	enum BOX_TYPE boxType = PLASTIC;

	printBoxType(boxType);

	/*
	double getDistance(struct Point2D p1, struct Point2D p2)
	{
		double distance;

		distance = sqrt(pow((p2.x - p1.x), 2) + pow(p2.y - p1.y, 2)); 
	
		return distance;
	}
	
	void movePoint2D(struct Point2D *p, int x, int y)
	{
		p->x += x;
		p->y += y;
	}
	
	�迭 �Ű������� ������ �Ű������� ������ 
	���ǻ� void hello(char s1[])�� ����ϴ� ���� �� �迭 �̸���
	�����ͷ� �ٲ�(�迭�� ���Ŀ��� ���� �� �����ͷ� ��ȯ��).
	���� void hello(char s1[])�� ����ϴ��� �����Ϸ���
	�����ͷ� �ν��Ͽ� void hello(char *s1)�� ��
	���� �Լ� �ٱ����� �μ��� ���� ���� �迭�� ���� �迭��
	�������ְ�, �������� ���� �����ͷ� �������ִ� ������ �����
	*/

	char buffer[20];
	char *ptr = "No pain, no gain";

	getSize(buffer, ptr);

	printf("%zd\n", sizeof(buffer));
	printf("%zd\n", sizeof(ptr));

	return 0;
}