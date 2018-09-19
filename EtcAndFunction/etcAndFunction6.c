#include <stdio.h>
#include <stdlib.h>
void swapNumber(int first, int second)
{
	int temp;

	temp = first;
	first = second;
	second = temp;
	//매개변수는 값을 전달하는 역할만 할 뿐 함수 바깥의 변수와는
	//상관이 없음, first와 second는 함수 내에서만 유효함 
}

void swapNumber2(int *first, int *second)
{
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
	//함수 안에서 메모리 주소에 접근해서 값을 저장함 
	//함수의 매개변수를 포인터로 사용하면 함수 바깥으로 여러 값을 
	//전달할 수가 있음
}	

enum TYPE {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT
};

void swapValue(void *ptr1, void *ptr2, enum TYPE t)
{	//void 포인터는 역참조를 할 수 없으므로 어떤 자료형으로 역참조할지
	//알려주기 위해서 TYPE 열거형을 받음, 함수 내에서는 TYPE 열거형에
	//따라 각 자료형의 포인터로 변환한 뒤 역참조하여 값을 서로 바꿈
	switch (t)
	{
	case TYPE_CHAR:
	{
		char temp;
		temp = *(char *)ptr1;
		*(char *)ptr1 = *(char *)ptr2;
		*(char *)ptr2 = temp;
		break;
	}
	case TYPE_INT:
	{
		int temp;
		temp = *(int *)ptr1;
		*(int *)ptr1 = *(int *)ptr2;
		*(int *)ptr2 = temp;
		break;
	}
	case TYPE_FLOAT:
	{
		float temp;
		temp = *(float *)ptr1;
		*(float *)ptr1 = *(float *)ptr2;
		*(float *)ptr2 = temp;
		break;
	}
	}
	//void 포인터 매개변수는 변수의 메모리 주소뿐만 아니라 메모리를
	//할당한 포인터도 넣을 수 있음, 또한 일반 자료형의 포인터 뿐만이
	//아니라 구조체 ,공용체, 열거형 등의 포인터도 넣을 수 있음
}
//void allocMemory(void *ptr, int size)
//{
//	ptr = malloc(size);
//	//ptr에 메모리를 할당해봐야 allocMemory 함수를 벗어나면 사용할 
//	//수가 없음, 메모리 누수가 발생하게 됨
//}

void allocMemory(void **ptr, int size)
{
	*ptr = malloc(size);
	//void 이중 포인터가 long long 포인터의 메모리 주소를 받은 뒤에 
	//void 이중 포인터를 역참조해서 void *ptr이 되도록 만든 뒤에 
	//malloc 함수로 메모리를 할당함, 실제로는 numPtr에 메모리를
	//할당하게 됨
}

void helloString(char *s1)
{	//매개변수를 문자열 포인터로 지정함 
	printf("Hello, %s\n", s1);
}

void helloString2(char s1[])
{	//매개변수를 char형 배열로 지정함
	//매개변수를 char s1[]과 같이 지정하더라도 배열뿐 아니라 문자열이나
	//메모리가 할당된 포인터도 전달할 수 있음 
	printf("Hello, %s\n", s1);
}

int main()
{
	int num1 = 10;
	int num2 = 20;

	swapNumber(num1, num2);

	printf("%d %d\n", num1, num2);

	int num3 = 10, num4 = 20;

	swapNumber2(&num3, &num4);
	//num3과 num4의 메모리 주소 전달 

	printf("%d %d\n", num3, num4);

	/*
	지금까지 scanf 함수를 사용할 때 변수를 그냥 넣지 않고 변수의
	메모리 주소를 넣었는데 그 이유는 scanf 함수는 값을 여러 개 입력
	받을 수 있는데 반환값 만으로는 여러 개의 값을 함수 바깥으로 
	전달할 수가 없었기 때문임, 변수의 메모리 주소만 넘겨주면 값이
	몇 개든지 상관없이 값을 가져올 수 있음 	
	*/

	char c1 = 'a', c2 = 'b';
	swapValue(&c1, &c2, TYPE_CHAR);
	printf("%c %c\n", c1, c2);

	int num5 = 10, num6 = 20;
	swapValue(&num5, &num6, TYPE_INT);
	printf("%d %d\n", num5, num6);

	float num7 = 1.234567f, num8 = 7.654321f;
	swapValue(&num7, &num8, TYPE_FLOAT);
	printf("%f %f\n", num7, num8);

	long long *numPtr = NULL;
	
	//allocMemory(numPtr, sizeof(long long));

	allocMemory(&numPtr, sizeof(long long));
	//long long 포인터의 메모리 주소는 long long 이중 포인터와
	//같으므로 void 이중 포인터 매개변수로 받을 수가 있음 

	*numPtr = 10;
	printf("%lld\n", *numPtr);

	free(numPtr);

	helloString("world!");
	//문자열의 주소가 매개변수에 저장됨 

	char s1[10] = "world!";

	helloString(s1);

	helloString2("world!");
	
	/*
	int getQuotientAndRemainder(int num1, int num2, int *remainder)
	{	
		 int quotient = num1 / num2;
		 *remainder = num1 % num2;
		 return quotient;
	}

	void allocArray(void **ptr, int m, int s)
	{
		*ptr= malloc(s * m);		
	}

	void printFullName(char s1[], char s2[])
	{
		printf("%s%s\n", s1, s2);
	}

	*/

	return 0;
}