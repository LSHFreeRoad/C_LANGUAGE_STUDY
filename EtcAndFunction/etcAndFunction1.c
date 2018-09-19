#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
	char c1;
	int num6;
};

typedef struct _Skill {
	char naSunHwan[10];
	char saRunAn[10];
	int count;
}Skill, *PSkill;


int main()
{
	/*
	자료형이 다르면서 크기가 작은 쪽, 표현 범위가 좁은 쪽으로
	저장하면 컴파일 경고 발생함
	실수형 값을 정수형 변수에 저장하면 컴파일 경고가 발생함
	자료형의 크기가 큰 쪽, 표현 범위가 넓은 쪽으로 자동 변환
	되는 것을 형 확장이라 하고 이런 변환을 암시적 형 변환이라고 함
	반대로 자료형 크기가 작은 쪽 , 표현 범위가 좁은 쪽으로 변환되는
	것이 형 축소라 하고 이때 컴파일 경고가 나오지 않게 하는 것을
	형 변환(타입 캐스팅)이라고 함, 또한 프로그래머가 강제로
	자료형을 변환한다고 해서 명시적 형 변환 이라고 부르기도함
	-----> 암시적 형 변환, 형 확장
	char short int long long long float double long double
	<----- 형 변환(타입 캐스팅), 형 축소, 명시적 형 변환
	형 확장은 값 손실이 없어서 컴파일러가 알아서 처리하지만
	형 축소는 값 손실이 있기 때문에 컴파일러가 알아서 처리할 수가
	없어서 경고가 발생함, 따라서 형 변환으로 의도를 밝혀야만
	컴파일러가 안심하고 변환을 하게 됨
	*/

	int num1 = 32;
	int num2 = 7;
	int num17;
	float num3, num15 = 100.438295f, num16 = 7.432913f;
	num3 = num1 / num2;
	printf("%f\n", num3);
	num17 = num15 / num16;
	printf("%d\n", num17);
	long long num21;
	num21 = num1 / num2;
	printf("%lld\n", num21);
	//컴파일 경고 발생 -> num3은 float형인데 num1 / num2는 
	//정수 / 정수라서 정수가 되기 때문임 

	num3 = (float)num1 / num2;
	//int를 float형으로 강제변환해주면 실수 / 정수가 되어 결과가
	//실수가 되기 때문에 num3에 4.571429가 저장되고 컴파일 경고가 
	//빌생하지 않게됨
	printf("%f\n", num3);

	//이처럼 형 변환은 타입을 명확하게 결정할 수 있고 또 
	//컴파일 경고가 발생하지 않도록 만들 수 있음 

	//포인터끼리 변환하는 방법 -> 자료형 뒤에 *를 붙여주고 괄호로
	//묶으면 됨 (자료형 *)포인터

	int *numPtr = malloc(sizeof(int));

	char *cPtr;

	*numPtr = 0x12345678;
	
	cPtr = (char*)numPtr; //int 포인터를 char 포인터로 변환해서 할당
	printf("0x%x\n", *cPtr);
	
	/*
	cPtr은 numPtr의 메모리 주소에 접근하지만 cPtr은
	char 포인터이므로 1바이트만큼 값을 가져옴 
	numPtr과 cPtr에 저장된 메모리 주소는 같지만 자료형에 따라
	역참조 했을 때 값을 가져오는 크기가 결정되기 때문임 
	*/
	free(numPtr);

	short *numPtr1 = malloc(sizeof(short));
	int *numPtr2;

	*numPtr1 = 0x1234;

	numPtr2 = (int*)numPtr1;

	printf("0x%x\n", *numPtr2);
	/*
	크기가 작은 메모리를 할당한 뒤 큰 자료형의 포인터로 역참조하면
	옆의 메모리 공간을 침범하여 값을 가져오게 됨
	malloc함수로 2바이트 만큼 메모리를 할당했으므로 0x1234만
	저장되어 있음, 이 상태에서 4바이트 int 크기만큼 값을 가져오면
	2바이트 크기를 벗어나서 malloc함수로 할당하지 않은 공간에 있는
	값까지 함께 가져오게 됨, 할당되지 않은 공간에는 쓰레기 값이
	들어있음	
	*/

	free(numPtr1);

	/*
	포인터를 다른 자료형으로 변환하면서 역참조 하려면
	*(자료형*)포인터
	*/

	int *numPtr3 = malloc(sizeof(int));

	*numPtr3 = 0x12345678;

	printf("0x%x\n", *(char *)numPtr3);
	free(numPtr3);

	int num4 = 10;
	float num5 = 3.5f;
	char c1 = 'a';
	void *ptr; 

	ptr = &num4;

	printf("%d\n", *(int*)ptr);
	//ptr은 void 포인터여서 그냥 역참조를 하면 컴파일 에러가 발생함
	//int 포인터로 변환한 다음에 역참조를 하면 됨

	ptr = &num5;

	printf("%f\n", *(float *)ptr);

	ptr = &c1;

	printf("%c\n", *(char *)ptr);

	/*
	자료형 변환을 주로 사용할 때는 구조체 포인터를 변환할 때임
	이때는 struct와 구조체 이름 뒤에 *을 붙여주고 괄호로
	묶어주면 됨

	(struct 구조체이름 *)포인터
	((struct 구조체이름 *)포인터)-> 멤버	
	*/

	struct Data *d1 = malloc(sizeof(struct Data));
	void *ptr1;

	d1->c1 = 'a';
	d1->num6 = 10; 

	ptr1 = d1;
	//ptr1은 void 포인터이고 d1 구조체 포인터이지만
	//void 포인터는 타입을 가리지 않고 다 받아들일 수 있으므로 
	//컴파일 경고가 발생하지 않음(암시적으로 자료형이 변환됨)

	printf("%c\n", ((struct Data *)ptr1)->c1);
	printf("%d\n", ((struct Data *)ptr1)->num6);
	/*
	ptr1은 void 포인터라 Data 구조체의 형태를 모르는 상태이므로
	멤버에 바로 접근할 수가 없음, 따라서 다음과 같이 ptr1을 Data
	구조체 포인터로 변환한 뒤 멤버에 접근해야 함
	만약 (struct Data *)ptr1처럼 하면 ptr1을 Data 구조체 포인터로 
	변환하지만 이 상태로는 멤버에 접근할 수가 없음 
	즉 (struct Data *)ptr1은 다른 포인터에 메모리 주소를 저장할 때만
	사용할 수가 있음 
	struct Data *d2 = (struct Data *)ptr1;
	ptr1을 구조체 포인터로 변환한 뒤 멤버에 접근할 때는 자료형
	변환과 포인터 전체를 다시 한 번 괄호로 묶어주면 -> 연산자를
	사용할 수가 있음 
	((struct Data *)ptr)->c1
	*/
	free(d1);

	/*
	typedef로 구조체 포인터 별칭을 정의하기 
	typedef struct 구조체 이름{
		자료형 멤버 이름;
	}구조체 별칭, *구조체포인터별칭;
	*/

	PSkill s1 = malloc(sizeof(Skill));
	void *ptr2;

	strcpy(s1->naSunHwan,"NaSunHwan");
	strcpy(s1->saRunAn, "SaRunAn");
	s1->count = 15;

	ptr2 = s1; //void포인터에 s1할당, 포인터 자료형이 달라도 
	//컴파일 경고가 발생하지 않음

	printf("%s\n", ((Skill *)ptr2)->naSunHwan);
	printf("%s\n", ((PSkill)ptr2)->saRunAn);
	printf("%d\n", ((PSkill)ptr2)->count);

	free(s1);
	
	/*
	num2 = (int)num1;
	numPtr2 = (unsigned int *)numPtr1;
	*(long double *)
	printf("%u\n", ((struct Stats *)ptr)->mana);
	printf("%u\n", ((struct Stats *)ptr)->movementSpeed);
	*/

	return 0;
}
