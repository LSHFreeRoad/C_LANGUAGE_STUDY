#include <stdio.h>

void helloNumber(int num1)
{	//호출할 때 넣은 값이 매개변수에 저장이 됨

	printf("Hello, %d\n", num1);
}

int add(int a, int b)
{	//함수를 호출했을 때 넣은 값이 a와 b에 순서대로 저장이 됨
	return a + b;
}

int main()
{
	/*
	함수에 값을 넘겨줘서 동작을 바꾸기
	ex)add(10, 20) 
	반환값 자료형 함수 이름(자료형 매개변수)
	{
	}	-> 매개변수가 있는 함수 정의
	반환값 자료형 함수 이름(자료형 매개변수1, 자료형 매개변수 2)
	{
	}	-> 매개변수가 있는 함수 정의

	*/
	
	helloNumber(10);
	helloNumber(20);

	int num1;

	num1 = add(10, 20);
	//함수에 정의된 매개변수 개수대로 넣어야 됨. 많거나 적으면 안 됨
	printf("%d\n", num1);

	/*함수 안에 들어가는 값을 뜻하는 용어가 꽤 많음
	매개변수, 파라미터, 형식 매개변수: 함수 바깥에서 전달 된 값이
	저장되는 변수를 뜻함
	인자, 인수, 아규먼트, 실행 전달인자: 함수를 호출할 때 전달하는 
	값이나 변수	
	중단점 삽입/삭제: F9
	디버깅 시작 및 계속: F5
	디버깅 중지: Shift + F5
	프로시저 단위 실행: F10(한 줄 단위로 실행)
	한 단계씩 실행: F11(함수 안으로 들어감)
	프로시저 나가기: Shift + F11(함수 나가기, 
	보통 함수를 프로시저라고함)
	*/
	
	/*
	long long add(long long a, long long b)
	{
		return a + b;
	}
	
	struct Point3D * allocPoint3D(float a, float b, float c)
	{	
		struct Point3D *pos1;

		pos1=malloc(sizeof(struct Point3D));

		pos1->x = a;
		pos1->y = b;
		pos1->z = c;
		
		return pos1;
	}

	함수 실행이 끝나면 함수 안에 선언된 변수가 사라지는 이유
	컴퓨터에서는 지역변수를 선언하고 함수를 호출할 때 스택을 사용하기
	때문임, 스택은 접시쌓기에 비유할 수 있음. 함수를 호출하면 접시를
	하나 쌓고 변수를 선언할 때마다 접시를 계속 쌓게됨. 함수가 끝나게
	되면 함수 부분에 해당하는 접시만 중간에 뺄 수 없기 때문에 위에
	있는 변수부터 차례대로 꺼낸 뒤 함수를 꺼냄
	함수 실행이 끝나도 사라지지 않는 변수-> 정적 변수
	정적변수는 스택을 사용하지 않고 메모리에서 계속 유지되기 때문에
	함수가 끝나도 사라지지 않음. 함수에서 정적 변수는 &로 메모리 주소를
	반환해도 됨
	void hello(void)-> 매개변수가 없다는 뜻
	void hello() -> 매개변수 목록이 정의되지 않음
	void hello(void)가 C 언어 표준에 정확한 표기이지만 void를 생략해도
	특별한 문제는 없음
	*/

	return 0;
}