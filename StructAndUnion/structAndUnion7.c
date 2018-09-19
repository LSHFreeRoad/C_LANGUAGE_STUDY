#define _CRT_SECURE_NO_WARNINGS	//strcpy함수의 보안경고 방지
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union Box {
	short candy;
	float snack;
	char doll[8];
}; 

union Data {
	char c1;
	short num1;
	int num2;
};


int main()
{	
	/*
	구조체는 각 멤버들이 각각 공간을 차지하지만 공용체는 모든 
	멤버가 공간을 공유함, 공용체는 멤버 중에서 가장 큰 자료형의 
	공간을 공유함
	union 공용체 이름{
		자료형 멤버이름;
	};


	union 공용체 이름 변수 이름;
	*/	

		
	union Box b1;	//Box 공용체 타입의 변수 b1을 선언한다는 의미임
	printf("%zd\n", sizeof(b1));
	//공용체의 멤버에 접근할때는 .을 이용함
	
	b1.candy = 10;
	printf("%d\n", b1.candy);
	
	b1.snack = 60000.0f;
	printf("%f\n", b1.snack);
	
	strcpy(b1.doll, "bear");	
	printf("%s\n", b1.doll);
				
	/*
	공용체는 멤버 중에서 가장 큰 자료형의 공간을 공유함, 따라서
	어느 한 멤버의 값을 저장하면 나머지 멤버의 값은 사용할 수
	없는 상태가 됨, 그래서 공용체의 멤버는 한 번에 하나씩 쓰면
	값을 정상적으로 사용할 수 있음
	공용체는 여러 멤버에 동시에 접근하지 않는 경우 같은 메모리 	
	레이아웃에 멤버를 모아둘 때 사용함	
	*/

	union Data d1; //Data 공용체 타입의 변수 d1 선언

	d1.num2 = 0x12345678;

	printf("0x%x\n", d1.num2);	//0x12345678: 4바이트 전체 출력
	printf("0x%x\n", d1.num1);	//0x5678: 앞의 2바이트 값만 출력 
	printf("0x%x\n", d1.c1); //0x78: 앞의 1바이트 값만 출력

	printf("%zd\n", sizeof(d1)); 
	//공용체의 전체 크기는 가장 큰 자료형의 크기

	/*
	앞의 값만 나와야 한다면 0x1234, 0x12가 나와야 하는데 0x5678, 
	0x78이 나오는 이유는 우리가 사용하는 x86(x86-64)계열 CPU는
	리틀 엔디언이라는 방식으로 값을 메모리에 저장하기 때문임
	리틀 엔디언은 숫자를 1바이트씩 쪼개서 낮은 자릿수가 앞에 오게됨
	사람이 보기에는 반대로 뒤집힌 것임 78 56 34 12가 됨
	빅 엔디언은 0x12345678이 메모리에 그대로 저장되서 그대로 됨
	공용체는 앞에서부터 자료형의 크기 만큼 값을 가져오니까 
	d1.num2는 앞이 2바이트 56 78을 가져오게 되고 d1.c1은 앞의
	1바이트 78만 가져오게 되는 것임 (저장할 때 뒤집혀서 저장되었
	으므로 가져올 때는 다시 되돌려서 가져옴)
	공용체도 구조체와 마찬가지로 별칭을 쓸 수 있음 
	*/

	/*
	구조체와 마찬가지로 공용체도 포인터를 선언할 수 있고 
	공용체 포인터에는 malloc 함수를 사용하여 동적 메모리 할당 가능
	*/
	
	union Box *b2 = malloc(sizeof(union Box));

	printf("%zd\n", sizeof(union Box));

	strcpy(b2->doll, "bear");
	//공용체 포인터도 멤버에 접근할 때는 -> 를 사용함
	//공용체 포인터의 멤버에 접근한 뒤 문자열을 복사함
	

	printf("%d\n", b2->candy);
	printf("%f\n", b2->snack);
	printf("%s\n", b2->doll);

	free(b2);

	return 0;
}