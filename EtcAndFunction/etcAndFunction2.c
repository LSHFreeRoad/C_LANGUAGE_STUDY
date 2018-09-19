#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
	int num1;
	int num2;
};

int main()
{	
	/*
	포인터 변수에 덧셈이나 뺄셈 연산을 하게 되면 
	메모리 주소가 증가 또는 감소하게 됨
	포인터 연산을 이용하면 다른 메모리 주소에 접근할 수 있고
	메모리 주소를 손쉽게 옮겨 다니기 위해 사용함 
	메모리 주소가 커지는 상황을 순방향으로 이동
	작아지는 상황을 역방향으로 이동이라고 이 책에서는 사용하기로함
	포인터 연산은 +,-,++,-- 연산자를 사용하여 값을 증가, 감소 시킴
	*, / 연산자와 실수 값은 사용할 수 없음
	*/

	int numArr[5] = { 11,22,33,44,55 };
	int *numPtrA;
	int *numPtrB;
	int *numPtrC;

	numPtrA = numArr; 
	//배열의 첫 번째 요소의 메모리 주소를 할당함 

	numPtrB = numArr + 1;

	numPtrC = numArr + 2;

	printf("%p\n", numPtrA);
	printf("%p\n", numPtrB);
	printf("%p\n", numPtrC);

	//포인터 연산은 포인터 자료형의 크기만큼 더하거나 뺌
	//numPtrA가 4바이트 크기의 int형임, 따라서 numPtrA + 1은
	//메모리 주소에서 4바이트만큼 1번 순방향으로 이동한다는 뜻 
	//numPtrA + 2는 2번 순방향으로 이동한다는 뜻임
	//즉 계산식은 sizeof(자료형) * 더하거나 빼는 값 

	numPtrA = &numArr[2];
	//numArr에서 3번째 요소의 메모리 주소를 할당함 

	numPtrB = numPtrA - 1;
	//메모리 주소에서 4바이트만큼 1번 역방향으로 이동함
	numPtrC = numPtrA - 2;
	//메모리 주소에서 4바이트만큼 2번 역방향으로 이동함

	printf("%p\n", numPtrA);
	printf("%p\n", numPtrB);
	printf("%p\n", numPtrC);

	numPtrB = numPtrA;
	numPtrC = numPtrA;

	numPtrB++;
	// + 1과 같으므로 numPtrA의 메모리 주소에서 4바이트만큼
	//1번 순방향으로 이동함 = sizeof(int) * 1
	numPtrC--;
	// - 1과 같으므로 numPtrA의 메모리 주소에서 4바이트만큼
	//1번 역방향으로 이동함 = sizeof(int) * (-1)

	printf("%p\n", numPtrA);
	printf("%p\n", numPtrB);
	printf("%p\n", numPtrC);

	numPtrA = numArr;

	numPtrB = numPtrA + 1;
	//numPtrB에는 numPtrA에 1을 더해서 4바이트만큼 순방향으로 이동한
	//메모리 주소를 저장함 = numArr의 2번째 요소의 메모리 주소 
	numPtrC = numPtrA + 2;
	//numPtrC에는 numPtrA에 2를 더해서 8바이트만큼 순방향으로 이동한
	//메모리 주소를 저장함 = numArr의 3번째 요소의 메모리 주소

	printf("%d\n", *numPtrB);
	printf("%d\n", *numPtrC);

	printf("%d\n", *(numPtrA + 1));
	//괄호로 묶어주면 포인터 연산이 먼저 실행됨
	//numArr[1]
	printf("%d\n", *(numPtrA + 2));
	//numArr[2]

	printf("%d\n", *numPtrA + 1);
	//역참조 연산자가 먼저 실행되어 값을 가져온 뒤 1을 더하게 됨
	printf("%d\n", *numPtrA + 2);
	//역참조 연산자가 먼저 실행되어 값을 가져온 뒤 2를 더하게 됨

	numPtrA = &numArr[2];
	numPtrB = numPtrA;
	numPtrC = numPtrA;

	printf("%d\n", *(++numPtrB));
	//numPtrB의 메모리 주소가 4바이트 만큼 증가하고 해당 메모리의
	//값을 가져옴

	printf("%d\n", *(--numPtrC));
	//numPtrC의 메모리 주소가 4바이트 만큼 감소하고 해당 메모리의
	//값을 가져옴

	printf("%d\n", *++numPtrB);
	//증감 연산자를 변수 앞에 사용할 때 괄호로 묶어주지 않아도
	//동작은 같음, 전위 증감 연산자와 역참조 연산자는 우선 순위가
	//같고 결합방향이 오른쪽에서 왼쪽이기 때문임 

	printf("%d\n", *++numPtrC);
	
	printf("%d\n", *(numPtrB++));
	//현재 메모리 주소값을 가져와서 역참조를 한 후에 
	//포인터 연산을 하게 됨 
	printf("%d\n", *(numPtrC--));
	
	printf("======================\n");
	/*
	void포인터는 자료형의 크기가 정해져 있지 않기 때문에 +, -로
	연산을 해도 얼마만큼 이동할지 알 수가 없음, 따라서 void 포인터는
	포인터 연산을 할 수 없음 -> 컴파일 에러 발생
	void 포인터로 포인터 연산을 할려면 다른 포인터로 변환한 뒤에
	연산을 하면 됨
	(자료형*)void 포인터 +값
	(자료형*)void 포인터 -값
	++(자료형*)void 포인터
	--(자료형*)void 포인터
	((자료형*)void 포인터)++
	((자료형*)void 포인터)--
	*/

	void *ptr = malloc(100);

	printf("%p\n", ptr);
	printf("%p\n", (int *)ptr + 1);
	printf("%p\n", (int *)ptr - 1);
	
	void *ptr2 = ptr;
	//증가,감소 연산자를 사용할 때는 자료형 변환 앞에 연산자를
	//붙이면 됨 
	printf("%p\n", ++(int *)ptr2);
	printf("%p\n", --(int *)ptr2);
	
	printf("%p\n", ((int *)ptr2)++);
	printf("%p\n", ((int *)ptr2)--);

	free(ptr);
	//free함수로 메모리를 해제해줄때는 반드시 처음에 메모리를
	//할당할 때 받은 주소를 넣어주어야 함 

	void *ptr3 = &numArr[2];

	printf("%d\n", *(int *)ptr3);

	printf("%d\n", *((int *)ptr3 + 1));
	printf("%d\n", *((int *)ptr3 - 1));
	//void 포인터 ptr3을 int형 포인터로 변환한 뒤에 포인터 연산을 함
	//그리고 괄호로 묶은 뒤에 역참조를 하면 됨

	printf("%d\n", *(++(int *)ptr3));
	printf("%d\n", *(--(int *)ptr3));
	//증가, 감소 연산자를 변수 앞에 사용할 때는 자료형 변환 앞에
	//연산자를 붙이고 전체를 괄호로 묶은 뒤 역참조를 하면 됨

	printf("%d\n", *(((int *)ptr3)++));
	printf("%d\n", *(((int *)ptr3)--));
	//증가, 감소 연산자를 변수 뒤에 사용할 때는 int형 포인터로 
	//변환한 뒤에 괄호로 묶고 그 뒤에 연산자를 붙임. 그리고 전체를
	//괄호로 묶은 뒤 역참조를 하면 됨, 단 증가, 감소 연산자를 뒤에
	//붙였으므로 현재 메모리의 값을 가져온 뒤에 포인터 연산을 하게 됨

	/*
	변수의 자료형을 다른 자료형으로 변환한 뒤에 변수의 값을 
	변경하는 것은 마이크로 소프트 전용 언어 확장임, 따라서
	visual studio에서만 사용할 수 있음, C 언어 표준에서는
	이를 허용하지 않음 

	int num1 = 10;
	//마이크로소프트 전용 언어 확장
	(char)num1 = 20;
	((char)num1)++;
	((char)num1)--;
	마찬가지로 포인터를 다른 포인터로 변환한 뒤에 ++,--연산자를
	사용하는 것도 마이크로소프트 전용 언어 확장입니다.

	void *ptr = malloc(100);
	void *ptr2 = ptr;
	
	printf("%p\n", ++(int *)ptr2);	
	printf("%p\n", --(int *)ptr2);
	printf("%p\n", *(++(int *)ptr2)));
	printf("%p\n", *(--(int *)ptr2)));
	
	free(ptr);
	
	이 코드를 GCC에서 컴파일하려면 포인터를 다른 자료형의 포인터에
	할당한 뒤 ++,-- 연산자를 사용해야 함
	
	void *ptr = malloc(100);
	int *ptr2 = ptr;

	printf("%p\n", ++ptr2);
	printf("%p\n", --ptr2);
	printf("%p\n", *(++ptr2));
	printf("%p\n", *(--ptr2));

	free(ptr);

	C 언어 표준에서는 자료형 변환은 I-value를 생성하지 않는다고
	규정되어 있음, 참고로 I-value는 메모리 공간을 차지하는 표현식을
	뜻하며 r-value는 I-value 이외의 표현식을 뜻함
	0 = 1; //0은 r-value이므로 값 할당이 안 됨
	(저장할 메모리 공간이 없음)
	int num1 = 1; //num1은 I-value이므로 값을 할당할 수 있음
	(저장할 메모리 공간이 있음)
	*/

	/*
	구조체 포인터로 포인터 연산하기 
	(포인터 + 값)->멤버
	(포인터 - 값)->멤버
	*/
	
	struct Data d[3] = { {10, 20}, {30, 40}, {50, 60} };
	struct Data *ptr4;

	ptr4 = d;
	//구조체 배열의 첫 번째 요소의 메모리 주소를 ptr4 포인터에 할당

	printf("%d %d\n", (ptr4 + 1)->num1, (ptr4 + 1)->num2);
	printf("%d %d\n", (ptr4 + 2)->num1, (ptr4 + 2)->num2);
	//포인터 연산을 한 뒤에 괄호로 묶고 -> 연산자를 사용하여
	//멤버에 접근
	//Data 구조체는 int형 멤버 2개가 들어있으므로 8바이트에 해당함
	//따라서 포인터 연산을 하면 8바이트씩 메모리 주소에서 더하거나 뺌

	//((struct 구조체 이름*)포인터 + 값)->멤버
	//((struct 구조체 이름*)포인터 + 값)->멤버

	void *ptr5 = malloc(sizeof(struct Data) * 3);
	struct Data d1[3];

	((struct Data *)ptr5)->num1 = 10;
	((struct Data *)ptr5)->num2 = 20;
	//구조체 포인터로 변환한 뒤에 멤버에 접근함

	((struct Data *)ptr5 + 1)->num1 = 30;
	((struct Data *)ptr5 + 1)->num2 = 40;
	//구조체 포인터로 변환한 뒤에 값을 더해주면 됨, 그리고 괄호로
	//묶고 ->연산자를 사용해서 멤버에 접근함

	((struct Data *)ptr5 + 2)->num1 = 50;
	((struct Data *)ptr5 + 2)->num2 = 60;

	memcpy(d1, ptr5, sizeof(struct Data) * 3);
	//포인터 연산으로 값을 저장한 결과가 Data 구조체 배열의 형태와
	//같은지 확인하기 위해 memcpy(대상 포인터, 원본 포인터, 크기)함수로
	//동적 메모리의 내용을 복사함

	printf("%d %d\n", d1[1].num1, d1[1].num2);
	printf("%d %d\n", ((struct Data *)ptr5 + 2)->num1,
		((struct Data *)ptr5 + 2)->num2);

	//동적 메모리에 저장된 값의 위치가 구조체 배열의 형태와 같고 동적
	//메모리의 내용을 동적 메모리의 내용을 그대로 복사했기 때문에
	//같은 값이 나오게 됨
	
	/*
	numPtrB = numPtrA + 3;
	numPtrC = numPtrA + 5;
	
	num1 = *(numPtr + 2);
	num2 = *((long long *)ptr + 1);
	
	result1 = ((struct Point3D *)ptr + 1)->x;
	result2 = ((struct Point3D *)ptr + 2)->z;
	
	malloc 함수는 void 포인터를 반환함 
	*/	

	free(ptr5);

	return 0;
}