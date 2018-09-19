#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct Person {
	char name[20];
	int age;
	char address[100];
};

struct Hacker {
	char value[20];
	char skill[15];
	int aPLanguage;
} BughuntingFreelancer;

typedef struct _SnowBoarder {
	char value[20];
	char skill[20];
	int age;
} GodBoarder;

typedef struct {
	char name[20];
	char function[30];
	int CPUMany;
} Notebook;

int main()
{	
	/*
	C 언어는 자료를 체계적으로 관리하기 위해 구조체를 제공함
	구조체는 struct로 정의, data structure(자료 구조)의 약어로 
	struct를 사용함, struct Person은 Person 구조체를 정의한다는 의미
	struct Person{
	char name[20];	//이름
	int age;	//나이
	char address[100];	//주소
	}; Person 구조체를 사용하여 변수를 만들어내면 인적정보를 손쉽게
	추가할 수가 있음
	struct Person people[200];
	구조체는 관련 정보를 하나의 의미로 묶을 때 사용하며 특히
	목적에 맞는 자료형을 만들어서 사용하는데 기본 자료형을 조합하여
	만든 자료형을 파생형(derived type)이라 함
	
	strcut 구조체이름{
		자료형 멤버이름;
	};
	struct 구조체이름 변수이름
	*/
																					
	struct Person p1;
	//정의한 구조체를 사용하려면 구조체 변수를 선언해야 함 
	//그리고 구조체 변수는 앞에 struct 키워드를 붙여야됨
	//Person 구조체 타입의 변수 p1을 선언한다는 의미이다.
	
	strcpy(p1.name, "홍길동");
	p1.age = 30;
	strcpy(p1.address, "서울시 용산구 한남동");
	//일반 변수로 선언한 구조체의 멤버에 접근하기 위해서는
	//.을 사용함, 문자열 멤버는 =(할당연산자)로 저장할 수 없기때문에
	//strcpy함수를 사용하면 됨

	printf("이름: %s\n", p1.name);
	printf("나이: %d\n", p1.age);
	printf("주소: %s\n", p1.address);
	
	/*
	struct 구조체이름{
		자료형 멤버이름;
	} 변수;
	이렇게 하면 구조체를 정의하는 동시에 변수를 선언할 수 있음 
	*/

	strcpy(BughuntingFreelancer.value, "free and justice");
	BughuntingFreelancer.aPLanguage = 6;
	strcpy(BughuntingFreelancer.skill, "reversing");
	//일반 변수로 선언한 구조체의 멤버 접근하기 위해서는
	//.을 사용함, 문자열 멤버는 =(할당연산자)로 저장할 수 없기때문에
	//strcpy함수를 사용하면 됨

	printf("가치관: %s\n", BughuntingFreelancer.value);
	printf("사용가능한 프로그래밍 언어 개수: %d\n",
		BughuntingFreelancer.aPLanguage);
	printf("능숙한 기술: %s\n", BughuntingFreelancer.skill);
	
	//구조체 변수를 선언하는 동시에 초기화를 할려면
	//중괄호안에 .과 멤버이름을 적고 값을 할당하면 됨
	
	struct Hacker jenius = { .value = "free and smart",
		.aPLanguage = 7, .skill = "reversing" };
	printf("가치관: %s\n", jenius.value);
	printf("사용가능한 프로그래밍 언어 개수: %d\n",
		jenius.aPLanguage);
	printf("능숙한 기술: %s\n", jenius.skill);

	//할당 연산자없이 값만 콤마로 구분해서 나열해도 되지만 이때는
	//구조체 멤버가 선언된 순서대로만 넣어야 하며 또한 중간에 있는
	//멤버만 값을 할당하거나 또는 생략할 수는 없음

	struct Hacker shadowHacker = { "imaginative", "reversing", 6 };
	printf("가치관: %s\n", shadowHacker.value);
	printf("능숙한 기술: %s\n", shadowHacker.skill);
	printf("사용가능한 프로그래밍 언어 개수: %d\n",
		shadowHacker.aPLanguage);

	/*
	typedef로 구조체를 정의하면서 별칭(alias)을 지정해주면 됨 
	구조체 이름과 구조체 별칭은 겹쳐도 되지만 이 책에서는
	구조체 이름에 _을 붙이기로 함, 구조체 별칭 변수이름;
	GodBoarder beginner; 변수는 다음과 같이 선언하면됨	
	*/

	GodBoarder beginner;
	//구조체 별칭 GodBoarder로 변수 선언 

	strcpy(beginner.value, "wonderful");
	beginner.age = 21;
	strcpy(beginner.skill, "비기너 턴");
	//구조체 별칭으로 선언한 변수도 구조체의 멤버에 접근할 때 .을 이용

	printf("가치관: %s\n", beginner.value);
	printf("나이: %d\n", beginner.age);
	printf("기술: %s\n", beginner.skill);

	//struct _SnowBoarder beginner2;
	//구조체 별칭이 아닌 이름으로 변수를 선언하려면 struct 키워드에
	//구조체 이름으로 변수를 선언하면 됨

	//typedef로 구조체 뿐만 아니라 모든 자료형의 별칭을 만들 수 있음
	
	typedef int MYINT; //int를 별칭 MYINT로 정의
	typedef int* PMYINT; //int 포인터를 별칭 PMYINT로 정의

	MYINT num1 = 3;
	PMYINT numPtr1;

	numPtr1 = &num1; //포인터에 변수의 주소 저장 
	//사용 방법은 일반 변수, 포인터와 같음
	//이처럼 typedef로 정의한 별칭을 사용자 정의 자료형
	//사용자 정의 타입이라고 부름

	//struct 뒤에 붙는 구조체 이름을 태그라고 부름
	//그리고 typedef로 정의한 것은 사용자 정의 타입이라고 할 수 있음

	//typedef로 구조체를 정의하면서 이름을 생략할 수 있음
	//-> 익명구조체(anonymous structure)
	//변수는 구조체 별칭으로 선언하면 됨

	Notebook n1;

	strcpy(n1.name, "samsung s9");
	strcpy(n1.function, "fast and light");
	n1.CPUMany = 4;

	printf("이름 : %s\n", n1.name);
	printf("기능 : %s\n", n1.function);
	printf("CPU 개수 : %d\n", n1.CPUMany);

	/*
	typedef struct {
		int speed;
		char fuel;
		float mileage;
		int engineTemp;
		int rpm;
	} Dashboard;
	
	*/
	return 0;
}
