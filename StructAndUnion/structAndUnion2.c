#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
	char name[20];
	int age;
	char address[100];
};

//
//typedef struct _Person {
//	char name[20];
//	int age;
//	char address[100];
//} Person1;

typedef struct {
	char name[20];
	int age;
	char address[100];
} Person1;

struct Person3 {
	char name[20];
	int age;
	char address[100];
};

int main()
{
	/*
	����ü�� ��� ������ ���� �� ����־ ũ�Ⱑ ū ����
	����ü ������ ������ �����ؼ� ����ϴ� �ͺ��� �����Ϳ� �޸𸮸�
	�Ҵ��ؼ� ����ϴ� ���� ȿ������	
	*/
	
	struct Person *p1 = malloc(sizeof(struct Person));
	//struct Ű����� ����ü �̸��� �̿��ؼ� ����ü ������ ����

	strcpy(p1->name, "ȫ�浿");
	p1->age = 30;
	strcpy(p1->address, "����� ��걸 �ѳ���");
	//����ü �������� ����� ������ ���� ȭ��ǥ�� �̿��� 
	//(*p1).age ó�� ����ü �����͸� ������ �� �� .���� �����
	//������ ���� ����, 


	printf("�̸� : %s\n", p1->name);
	printf("���� : %d\n", p1->age);
	printf("�ּ� : %s\n", p1->address);

	free(p1);

	//����ü ��Ī���� �����͸� �����ϰ� �޸� �Ҵ��ϱ� 
	//����ü ��Ī *�������̸� = malloc(sizeof(����ü ��Ī))
	Person1 *p2 = malloc(sizeof(Person1));

	strcpy(p2->name, "ȫ�浿");
	p2->age = 30;
	strcpy(p2->address, "����� ��걸 �ѳ���");

	printf("�̸� : %s\n", p2->name);
	printf("���� : %d\n", p2->age);
	printf("�ּ� : %s\n", p2->address);

	free(p2);

	struct Person3 p3;
	struct Person3 *ptr;

	ptr = &p3;

	ptr->age = 30;

	printf("����: %d\n", p3.age);
	printf("����: %d\n", ptr->age);

	return 0;
}