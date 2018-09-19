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
	printf("이름: %s\n", p.name);
	printf("나이: %d\n", p.age);
	printf("주소: %s\n", p.address);
}

void setPerson(struct Person p)
{
	strcpy(p.name, "고길동");
	p.age = 30;
	strcpy(p.address, "서울시 서초구 반포동");
}

void setPerson2(struct Person *p)
{
	//매개변수를 구조체 포인터로 지정하고 함수 안에서 포인터로
	//받은 구조체 멤버의 값을 변경함 
	strcpy(p->name, "고길동");
	p->age = 40;
	strcpy(p->address, "서울시 서초구 반포동");
}

void printPerson2(struct Person *p)
{
	printf("이름: %s\n", p->name);
	printf("나이: %d\n", p->age);
	printf("주소: %s\n", p->address);
}

typedef struct {
	char carName[10];
	int productionYear;
	char feature[20];
} CAR, *PCAR;

void carOption(PCAR pCar)
{
	strcpy(pCar->carName, "소나타");
	pCar->productionYear = 2011;
	strcpy(pCar->feature, "연비가 좋음");
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
	printf("핸드폰 기종: %s\n", handPhone->name);

	handPhone->productionYear = 2017;
	printf("핸드폰 생산년도: %d\n", handPhone->productionYear);

	handPhone->price = 300000;
	printf("핸드폰 가격: %f원\n", handPhone->price);

}

void printBoxType(enum BOX_TYPE boxType)
{
	printf("%d\n", boxType);
}

void getSize(char buffer[], char *ptr)
{
	printf("함수 내에서 char형 배열크기: %zd\n", sizeof(buffer));
	printf("함수 내에서 char형 포인터크기: %zd\n", sizeof(ptr));
}

int main()
{
	/*
	함수에서 전달해야 할 매개변수가 많을 때 구조체로 묶어서 
	전달하면 간단해짐 
	반환값 자료형 함수 이름(struct 구조체 이름 매개변수)
	{
	}	
	*/

	struct Person p1;

	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");

	printPerson(p1);
	//함수를 호출할 때 구조체 변수의 모든 멤버가 매개변수로 복사됨
	//단 구조체 크기가 커지면 복사할 공간이 그만큼 더 필요하므로
	//공간이 낭비되어 비효율적임, 보통 매개변수로 구조체를 전달할
	//때는 포인터를 활용하는 것이 좋음 

	setPerson(p1);

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);

	//매개변수로 값이 전달될 떄 구조체 멤버가 모두 복사되었으므로
	//함수 안에서 구조체 멤버를 아무리 변경해도
	//바깥에 있는 구조체 변수에는 영향을 미치지 않음

	/*
	구조체 포인터를 매개변수로 사용하기
	반환값 자료형 함수 이름(struct 구조체 이름 *매개변수)
	{
	}
	*/

	struct Person p2;

	strcpy(p2.name, "홍길동");
	p2.age = 30;
	strcpy(p2.address, "서울시 용산구 한남동");

	setPerson2(&p2);
	//주소 연산자를 사용해서 구조체 멤버의 값이 복사되지 않고
	//구조체 변수 p2의 메모리 주소를 전달함
	//함수 setPerson에서는 바깥에 선언된 구조체 변수의 값을
	//변경하게 됨

	printf("이름: %s\n", p2.name);
	printf("나이: %d\n", p2.age);
	printf("주소: %s\n", p2.address);

	/*
	함수에 구조체 포인터를 넘겨줄 때는 복합 리터럴을 사용해서 리터럴 앞에 
	&를 붙이면 됨
	&(struct 구조체 이름) {.멤버 이름1= 값1, .멤버 이름2= 값2}
	&(struct 구조체 이름) {값1, 값2}
	*/

	printPerson2(&(struct Person) {.name = "홍길동", .age = 30,
		.address = "서울시 서초구 서초1동"
	});

	printPerson2(&(struct Person) { "블랙썬", 30,
		"고양시 일산동구 풍동" });

	PCAR pCar = malloc(sizeof(CAR));

	carOption(pCar);

	printf("차 기종: %s\n", pCar->carName);
	printf("차 생산년도: %d\n", pCar->productionYear);
	printf("차 특징: %s\n", pCar->feature);

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
	
	배열 매개변수와 포인터 매개변수의 차이점 
	편의상 void hello(char s1[])로 사용하는 것일 뿐 배열 이름은
	포인터로 바뀜(배열은 수식에서 사용될 때 포인터로 변환됨).
	따라서 void hello(char s1[])로 사용하더라도 컴파일러는
	포인터로 인식하여 void hello(char *s1)이 됨
	보통 함수 바깥에서 인수로 받은 값이 배열일 때는 배열로
	지정해주고, 포인터일 때는 포인터로 지정해주는 식으로 사용함
	*/

	char buffer[20];
	char *ptr = "No pain, no gain";

	getSize(buffer, ptr);

	printf("%zd\n", sizeof(buffer));
	printf("%zd\n", sizeof(ptr));

	return 0;
}