#include <stdio.h>

hello()
{
	printf("Hello, world!\n");
}

void  bonjour()
{
	printf("bonjour le mode!\n");
}

int add(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	return a * b;
}

int main()
{
	/*
	함수 자체를 매개변수로 넘겨주고 반환값으로 가져오려면
	함수 포인터를 이용하면 됨. 함수 포인터는 함수를 저장하는
	포인터를 뜻하며 함수 포인터를 주고 받거나 함수 포인터로
	함수를 호출할 수 있음. 함수 포인터 활용-> 함수 포인터의 배열
	구조체에 함수 포인터를 멤버로 넣음, 함수 포인터를 주고 받음
	함수 이름도 포인터이므로 출력해보면 주소가 나옴
	*/
	
	printf("%p\n", hello);
	
	/*
	함수 포인터 만들기
	반환값 자료형 (*함수포인터 이름)();
	*/

	void(*fp)(); //반환값과 매개변수가 없는 함수포인터 fp 선언 
	//함수 포인터를 선언할 때는 함수 포인터와 저장될 함수의
	//반환값 자료형, 매개변수 자료형과 개수가 일치해야함 


	fp = hello;
	//함수의 메모리 주소를 함수 포인터에 저장할 때 할당 연산자를
	//이용함

	fp();
	//함수 포인터에 들어있는 함수를 호출함

	fp = bonjour;
	//함수의 메모리 주소를 함수 포인터에 저장할 때 할당 연산자를
	//이용함

	fp();
	//함수 포인터에 들어있는 함수를 호출함

	//함수 포인터를 활용하면 함수를 전구 소켓처럼
	//갈아끼울 수 있음

	/*
	반환값과 매개변수가 있는 함수 포인터 만들기
	반환값 자료형 (*함수포인터 이름)(매개변수 자료형1, 매개변수
	자료형2);	
	*/

	int(*fp2)(int, int);
	//int형 반환값, fp:함수포인터 이름, int형 매개변수 2개

	fp2 = add;
	//할당 연산자로 함수 포인터에 함수의 메모리 주소를 저장함
	printf("%d\n", fp2(10, 20));

	fp2 = mul;
	//할당 연산자로 함수 포인터에 함수의 메모리 주소를 저장함
	printf("%d\n", fp2(10, 20));

	//함수 포인터를 활용하면 상황에 따라 함수를 바꿔가며 호출할
	//수 있음

	/*
	int (*fp)(int *,int *);
	if(strcmp("add", funcName) == 0)
	{	fp = add;
	}else if(strcmp("sub", funcName) == 0)
	{	fp = sub;
	}else if(strcmp("mul", funcName) == 0)
	{	fp = mul;
	}else
	{	fp = div;
	}

	*/

	return 0; 
}