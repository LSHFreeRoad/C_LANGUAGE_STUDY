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
	//지역 변수의 주소를 반환하는 방법은 잘못된 방법임 -> 컴파일 경고
	//출력 결과가 10이 잘 나오는 것은 예제 프로그램이 매우 간단해서
	//10이 저장된 변수가 덮어 쓰여지지 않았기 때문임, 프로그램이
	//복잡해지면 사라진 지역 변수의 공간을 다른 값으로 덮어써서
	//값이 온전히 유지되지 않음.(환경에 따라서 10이 안 나올 수 있음)

	int *numPtr = malloc(sizeof(int));
	*numPtr = 10;
	return numPtr;
	//포인터를 반환하려면 다음과 같이 malloc 함수로 메모리를 할당한 뒤
	//반환해야 함. malloc으로 메모리를 할당하면 함수가 끝나도
	//free함수로 해제하기 전까지는 사라지지 않음

}
char *helloLiteral()
{
	char *s1 = "Hello, world!";

	return s1;

	//문자열 리터럴의 주소를 포인터에 저장한 뒤 반환함 
	//소스코드 상에 입력한 문자열 리터럴은 실행파일이 실행될 때
	//메모리에 저장되므로 함수가 종료되더라도 계속 사용할 수가 있음
}

char *helloDynamicMemory()
{
	char *s1 = malloc(sizeof(char) * 20);

	strcpy(s1, "Hello, world!");

	return s1;

	//문자열 포인터에 동적 메모리를 할당한 뒤 strcpy함수로 문자열을
	//복사함, 이때는 반드시 free 함수로 동적 메모리를 해제해야 함 
}
void *allocMemory()
{
	void *ptr = malloc(100);
	//100바이트 만큼의 동적 메모리 할당 

	return ptr;
	//void 포인터 반환 
}

struct Person {
	char name[20];
	int age;
	char address[100];
};

struct Person getPerson()
{
	//구조체를 반환하는 함수를 정의하려면 이렇게 struct 키워드와
	//구조체 이름을 함수 이름 앞에 붙여주면 됨
	struct Person p;
	
	strcpy(p.name, "홍길동");
	p.age = 30;
	strcpy(p.address, "서울시 용산구 한남동");

	return p; //구조체 변수 반환
}

struct Person *allocPerson()
{
	//반환값의 자료형을 구조체 포인터로 지정해줌 
	struct Person *p = malloc(sizeof(struct Person));
	
	strcpy(p->name, "홍길동");
	p->age = 30;
	strcpy(p->address, "서울시 용산구 한남동");

	return p;
	//함수 안에서 구조체 포인터에 메모리를 할당하고 값을 저장한 뒤
	//구조체 포인터를 반환함
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
	함수에서 값을 꺼내오는 방법-> 반환값(return value)을 사용함
	반환값은 함수를 호출한 바깥에 결괏값을 알려주기 위해 사용함
	반환값자료형 함수이름()
	{
		코드
		return 반환값;
	}
	중요한 점은 반환값과 반환값의 자료형이 일치해야 된다는 점
	반환값이 정수면 반환값 자료형은 정수에 해당하는 int, long등을 쓰고
	실수면 float, double 등을 써야 함. 
	*/

	int num1;

	num1 = one();
	//반환값을 저장하려면 저장할 변수에 할당 연산자(=)를 사용한 뒤
	//함수를 호출해주면 됨. 반환값의 자료형과 반환값을 저장할 변수의
	//자료형도 같아야 함

	printf("%d\n", num1);

	float num2;
	bool b1;
	
	num2 = realNumber();
	b1 = truth();

	printf("%f\n", num2);
	printf("%d\n", b1);

	//만약 반환값의 자료형과 반환하는 값의 자료형이 다를 때는 자료형
	//변환규칙을 따르게 됨. 만약 컴파일 경고가 발생하면 자료형을 
	//강제적으로 변환해서 반환하거나 반환한 값의 자료형을 변환시키면 됨

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
	자료형에 상관없이 값을 꺼내오고 싶다면 어떤 자료형으로 된
	포인터든지 넣을 수 있는 void 포인터를 활용하면 편리함
	*/

	//void포인터는 다양한 포인터로 자동 변환됨

	char *s3 = allocMemory();
	//allocMemory에서 반환된 void 포인터를 문자열 포인터에 넣어서
	//문자열처럼 사용함
	strcpy(s3, "Hello, world!");
	printf("%s\n", s3);
	free(s3);
	//allocMemory에서 malloc함수를 사용하고 있으므로 allocMemory에서
	//반환된 포인터를 사용할 때마다 반드시 free함수로 해제해 줘야함

	int *numPtr1 = allocMemory();
	//allocMemory에서 반환된 void 포인터를 int 포인터에 넣어서 
	//int형 배열처럼 사용할 수도 있음
	numPtr1[0] = 10;
	numPtr1[1] = 20;
	printf("%d %d\n", numPtr1[0], numPtr1[1]);
	free(numPtr1);

	/*C 언어에서 함수는 값을 하나만 반환함, 이때 인적 정보를 
	반환값으로 얻어오려면 구조체를 활용하는 것이 편리함
	함수에서 구조체를 반환하면 데이터를 묶어서
	한 번에 가져올 수가 있음
	struct 구조체 이름 함수이름()
	{
		return 구조체 변수; 
	}
	*/

	struct Person p1;

	p1 = getPerson();
	//반환된 구조체 변수의 내용이 모두 p1으로 복사됨 

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);
	
	/*
	구조체 크기가 커지면 복사할 공간이 그만큼 더 필요하게 되어 공간이
	낭비되므로 비효율적임, 구조체를 반환할때는 구조체 복사가 일어나지
	않도록 malloc함수로 동적 메모리를 할당한 뒤 구조체 포인터를
	반환하는 것이 좋음. 구조체 포인터를 반환하는 함수는 구조체 이름과
	함수 이름 사이에 *을 붙임 
	
	struct 구조체 이름 *함수이름()
	{
		return 구조체 포인터();
	}
	*/

	struct Person* p2;

	p2 = allocPerson();
	//이제 allocPerson 함수를 호출한 뒤 반환된 포인터를 p2에 저장함
	//구조체의 내용을 복사하지 않기 때문에 훨씬 효율적임 

	printf("이름: %s\n", p2->name);
	printf("나이: %d\n", p2->age);
	printf("주소: %s\n", p2->address);

	free(p2);
	//메모리 사용이 끝났으면 반드시 free함수로 해제해줌 

	union Box box;
	enum BOX_TYPE boxType;

	box = getBox();
	boxType = getBoxType();
	
	printf("0x%x\n", box.doll[1]);
	printf("%d\n", boxType);
	
	PPain painPerson = getPain();
	
	printf("질병 : %s\n", painPerson->disease);
	printf("고민 : %s\n", painPerson->worry);
	printf("나이 : %d\n", painPerson->age);

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