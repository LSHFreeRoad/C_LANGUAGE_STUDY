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
	구조체는 멤버 변수가 여러 개 들어있어서 크기가 큰 편임
	구조체 변수를 일일이 선언해서 사용하는 것보다 포인터에 메모리를
	할당해서 사용하는 편이 효율적임	
	*/
	
	struct Person *p1 = malloc(sizeof(struct Person));
	//struct 키워드와 구조체 이름을 이용해서 구조체 포인터 선언

	strcpy(p1->name, "홍길동");
	p1->age = 30;
	strcpy(p1->address, "서울시 용산구 한남동");
	//구조체 포인터의 멤버에 접근할 때는 화살표를 이용함 
	//(*p1).age 처럼 구조체 포인터를 역참조 한 뒤 .으로 멤버에
	//접근할 수가 있음, 


	printf("이름 : %s\n", p1->name);
	printf("나이 : %d\n", p1->age);
	printf("주소 : %s\n", p1->address);

	free(p1);

	//구조체 별칭으로 포인터를 선언하고 메모리 할당하기 
	//구조체 별칭 *포인터이름 = malloc(sizeof(구조체 별칭))
	Person1 *p2 = malloc(sizeof(Person1));

	strcpy(p2->name, "홍길동");
	p2->age = 30;
	strcpy(p2->address, "서울시 용산구 한남동");

	printf("이름 : %s\n", p2->name);
	printf("나이 : %d\n", p2->age);
	printf("주소 : %s\n", p2->address);

	free(p2);

	struct Person3 p3;
	struct Person3 *ptr;

	ptr = &p3;

	ptr->age = 30;

	printf("나이: %d\n", p3.age);
	printf("나이: %d\n", ptr->age);

	return 0;
}