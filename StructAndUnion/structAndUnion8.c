#include <stdio.h>
#include <stdlib.h>
struct Phone {
	int areacode;
	unsigned long long number;
};

struct Person {
	char name[20];
	int age;
	struct Phone phone;
	struct Phone *phone2;
	//구조체를 멤버로 가지려면 구조체 안에서 구조체를 선언하면 됨
};

struct Vector3 {
	union {
		struct {
			float x;
			float y;
			float z;
		};	
		//pos.x처럼 멤버에 바로 접근하기 위해 익명 구조체로 정의함 
		float v[3];
		//익명 공용체가 x,y,z 익명 구조체와 배열 v를 감싸고 있음
		//pos.v처럼 멤버에 바로 접근하기 위해 익명 공용체로 정의함 
	};
};


int main()
{
	struct Person p1;

	//멤버에 접근할 때는 .을 사용해서 가지고 있는 구조체에 
	//계층적으로 접근하면 됨 , 변수.멤버.멤버

	p1.phone.areacode = 82;
	p1.phone.number = 3045671234;

	printf("%d %llu\n", p1.phone.areacode, p1.phone.number);

	/*

	struct Person {
		char name[20];
		int age;
		struct Phone {
			int areacode;
			unsigned long long number;
		} phone;
	};

	구조체 내에서 구조체를 정의할 때는 반드시 변수를 선언해야 됨!
	또한 구조체내에 구조체를 선언할 때는 그 선언되는 구조체를
	이전에 정의했어야 됨		
	*/

	struct Person *p2 = malloc(sizeof(struct Person));

	p2->phone.areacode = 82;
	p2->phone.number = 3045671234;

	//p2는 ->을 사용하여 멤버에 접근 , phone은 포인터가 아닌 일반
	//변수이므로 .을 사용하여 멤버에 접근함. 즉, 포인터->멤버.멤버


	printf("%d %llu\n", p2->phone.areacode, p2->phone.number);

	free(p2);

	struct Person *p3 = malloc(sizeof(struct Person));
	p3->phone2 = malloc(sizeof(struct Phone));

	p3->phone2->areacode = 82;
	p3->phone2->number = 3045671234;

	printf("%d %llu\n", p3->phone2->areacode, p3->phone2->number);

	free(p3);

	/*
	바깥에 있는 구조체 포인터를 먼저 해제하면 데이터가 사라지므로
	안에 있는 멤버에 더 이상 접근할 수가 없게 됨, 그래서
	멤버 포인터가 저장된 주소도 알 수 없으므로 해제도 할 수 없음 
	하지만 미리 멤버 포인터의 주소를 다른 곳에 저장해 두었다면 
	바깥에 있는 구조체 포인터를 먼저 해제해도 상관이 없음
	구조체 안에 구조체가 포인터로 들어갈 때는 전방 선언을 사용하면
	정의되지 않은 구조체를 먼저 사용할 수가 있음
	struct 구조체 이름;
	*/

	struct Vector3 pos;
	
	for (int i = 0; i < 3; i++)
	{
		pos.v[i] = i + 1.0f; //v는 배열이므로 인덱스로 접근
	}

	printf("%f %f %f\n", pos.x, pos.y, pos.z);
	//공용체에 값을 넣었으므로 값은 같은 공간에 있다
	//따라서 x,y,z 멤버로도 접근할 수가 있다.
	
	/*
	struct Champion *swain = malloc(sizeof(struct Champion));
	swain->stats = malloc(sizeof(struct Stats));

	strcpy(swain->name, "Swain");
	swain->stats->health = 463.000000f;
	*/
	/*
	struct DeviceOption{
		union{
			struct{
				char boot;
				char interrupt;
			};
				short option;
		};
	};	
	*/

	return 0;
}