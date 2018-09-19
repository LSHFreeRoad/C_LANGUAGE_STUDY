#include <stdio.h>
struct Flags {
	unsigned int a : 1; //a는 1비트
	unsigned int b : 3; //b는 3비트
	unsigned int c : 7; //c는 7비트
};

struct Flags2 {
	union {
		struct {
			unsigned short a : 3;
			unsigned short b : 2;
			unsigned short c : 7;
			unsigned short d : 4;
		};
		unsigned short e;
	};
};

int main()
{
	/*
	구조체 멤버는 각 자료형 크기만큼 공간을 차지함
	구조체 비트 필드를 사용하면 멤버를 비트 단위로 저장할 수 있음
	CPU, 칩의 플래그를 다루는 저수준 프로그래밍을 할 때 기본
	자료형보다 더 작은 비트 단위로 값을 가져오거나 저장하는
	경우가 많으므로 구조체 비트 필드가 유용하게 사용됨
	c99 표준에서는 비트 필드로 사용할 수 있는 자료형이 Bool
	,signed int , unsigned int로 규정, 대부분의 컴파일러에서는 
	모든 정수 자료형을 사용할 수 있음, 보통 비트 필드에는 부호 없는
	자료형을 많이 사용함, 실수 자료형은 사용할 수 없음
	비트 필드의 멤버를 선언하는 자료형보다 큰 비트 수는
	지정할 수 없음
	비트필드 ->  struct 구조체 이름{
					정수 자료형 멤버이름 : 비트수;
				 };		
	*/

	struct Flags f1;

	f1.a = 1; 
	f1.b = 15;
	f1.c = 255;

	printf("%u\n", f1.a); //비트 1개만 저장됨
	printf("%u\n", f1.b); //비트 3개만 저장됨
	printf("%u\n", f1.c); //비트 7개만 저장됨

	//비트 필드의 각 멤버는 최하위 비트부터 차례대로 배치됨 
	//따라서 a가 최하위 비트에 오고 나머지 멤버들은 각각 상위
	//비트에 배치가 됨
	//전체크기는 unsigned int의 크기인 4바이트가 됨
	//만약 멤버를 unsigned short로 선언하면 구조체의 크기는 2가 됨

	printf("%llu\n", sizeof(struct Flags));

	//비트필드와 공용체를 함께 

	struct Flags2 flag2;

	flag2.a = 4; //4: 0000 0100-> 100
	flag2.b = 2; //2: 0000 0010 -> 10
	flag2.c = 80; //80: 0101 0000 -> 1010000
	flag2.d = 15; //15: 0000 1111 -> 1111

	//비트필드에 할당한 비트들을 차례대로 연결하면
	//1111 1010000 10 100 -> 64020

	printf("%u\n", flag2.e);


	/*
	unsigned short a : 3;
	unsigned short b : 4;
	unsigned short c : 7;
	unsigned short d : 2;
	*/

	return 0;
}