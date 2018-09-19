#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return (a / b);
}

/*함수 포인터를 구조체 멤버로 사용하려면 구조체를 정의할 때
멤버로 지정해주면 됨
struct 구조체이름 {
	반환값 자료형(*함수포인터이름)(매개변수 자료형1, 매개변수 
	자료형2)
};
*/

struct Calc {
	int(*fpC)(int, int);
};

/* 함수 포인터를 매개변수와 반환값으로 사용하기 
함수 포인터를 매개변수로 사용하려면 함수를 만들 때 매개변수
부분에 함수 포인터를 넣어주면 됨
반환값 자료형 함수이름(함수 포인터 반환값자료형
(*함수 포인터이름)(함수 포인터 매개변수 자료형1,
함수 포인터 매개변수 자료형2))
{
}

*/

void executer(int(*fp)(int, int))
{
	//함수를 만들 때 매개변수 부분에 함수 포인터를 그대로 
	//만들어주면 됨 
	printf("%d\n", fp(10, 20));
}

//함수 포인터를 함수의 반환값으로 사용하기 
/* 함수 포인터의 반환값 자료형(*함수이름())(함수 포인터의 매개
변수 자료형1, 2)
{
	return add; 
	//add 함수의 메모리 주소를 반환함 
}
*/


int (*getAdd())(int, int)
{	
	return add;
}


char *dokrib(int money, int year, char *res)
{
	sprintf(res, "%d년 뒤 %d만원 모아서 독립하기"
		, year, money);
	return res;
}


char* (*getDokrib(int x, int y))(int, int, char*)
{
	printf("현재: %d살 %d만원\n", x, y);
	return dokrib;
}

typedef int(*FP)(int, int);

FP getADD()
{	//함수 포인터 별칭을 함수의 반환값으로 지정할 수 있음 
	return add;
}

struct Calc2 {
	FP fp;
};

void executer2(FP fp)
{
	printf("%d\n", fp(70, 80));
}

int main()
{
	/*
	함수 포인터도 포인터이므로 포인터로 할 수 있는
	작업을 그대로 수행이 가능함, 
	포인터를 배열로 만들기, 구조체 멤버로 사용하기
	함수의 매개변수와 반환값으로 사용하기가 가능함	
	*/

	int funcNumber;
	int num1, num2;
	int(*fp)(int, int) = NULL;

	printf("함수 번호와 계산할 값을 입력하세요: ");
	scanf("%d %d %d", &funcNumber, &num1, &num2);

	switch (funcNumber)
	{
	case 0:
		fp = add;
		break;
	case 1:
		fp = sub;
		break;
	case 2:
		fp = mul;
		break;
	case 3:
		fp = div;	
		break;
	}

	printf("%d\n", fp(num1, num2));
	
	

	/*
	함수를 번호로 나타내려니 너무 길어지게 되는데 이때 
	함수 포인터를 이용하면 간단해짐	
	함수 포인터 배열은 함수 포인터를 선언할 때 함수 포인터 
	이름 뒤 []안에 크기를 지정하면 됨
	반환값 자료형 (*함수포인터 이름[크기])(매개변수 자료형1, 
	매개변수 자료형 2);	
	*/

	int(*fparr[4])(int, int);

		fparr[0] = add;
		//첫 번째 요소에 덧셈 함수의 메모리 주소를 저장함  
		fparr[1] = sub;
		fparr[2] = mul;
		fparr[3] = div;
	
	printf("함수 번호와 계산할 값을 입력하세요: ");
	scanf("%d %d %d", &funcNumber, &num1, &num2);
	printf("%d\n", fparr[funcNumber](num1, num2));

	struct Calc c;

	c.fpC = add;
	//구조체 변수를 선언한 뒤에 .으로 함수 포인터 멤버에 
	//접근해서 add 함수의 메모리 주소를 저장함 

	printf("%d\n", c.fpC(10, 20));
	//구조체 멤버인 함수 포인터로 add함수를 호출함 

	executer(add);

	printf("%d\n", getAdd()(10, 20));
	//getAdd 함수를 호출하면 add 함수의 포인터가 반환되며
	//그 뒤에 바로 괄호를 붙여서 add함수를 호출함

	char result[50];

	printf("%s\n", getDokrib(21, 200)(2000, 5, result));
	
	/*
	지금까지 함수 포인터를 만들 때 int (*fp)(int,int); 처럼
	일일이 반환값 자료형과 매개변수 자료형을 명시했음
	이런 방식을 full pointer type이라고 하는데 사용하기가
	상당하기 번거로움 typedef로 별칭을 정의하면 함수 포인터를
	매번 만들지 않아도 됨 
	typedef 반환값자료형 (*함수 포인터 별칭)(매개변수 자료형1,
	매개변수 자료형2);	
	*/

	printf("%d\n", getADD()(10, 20));

	FP fp1;
	fp1 = add;
	printf("%d\n", fp1(10, 20));

	FP fp2[10];
	fp2[0] = add;
	printf("%d\n", fp2[0](30, 40));

	struct Calc2 c2;
	c2.fp = add;
	printf("%d\n", c2.fp(50, 60));

	executer2(sub);

	/*	
	void (*getPrintFunc(struct Person *p))(struct Person *)
	{
		return p->print;
	}
	
	
	
	
	
	*/

	return 0;
}