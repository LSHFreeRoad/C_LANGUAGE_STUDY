#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>	//malloc, free 함수가 선언된 헤더파일
int main()
{
	/*
	프로그램 실행 중에 원하는 크기만큼 배열을 생성하는
	기능이 있다. 가변길이배열(Variable_LengthArray,VLA)
	가변길이배열은 visual studio 2017에서는 지원하지 않음
	->컴파일 에러가 발생함!, gcc, clang 등 에서는 지원함
	크기를 동적으로 지정하려면 포인터를 선언하고 메모리를
	할당한 뒤 포인터를 배열처럼 사용하면 됨
	
	int size;

	scanf("%d", &size);

	int numArr[size];
	
	포인터를 배열처럼 사용하는 방법-> 포인터에
	malloc함수로 메모리를 할당해주면 됨 
	자료형 *포인터 이름 = malloc(sizeof(자료형) * 크기); 
	*/

	int *numPtr = malloc(sizeof(int) * 10);
	//int 10개 크기만큼의 동적메모리 할당
	//sizeof(int)를 곱하지 않으면 배열처럼 사용할 수 없음
	//포인터[인덱스]; -> 배열처럼 인덱스를 지정하여
	//값을 할당하거나 가져올 수 있음
	
	numPtr[0] = 10;
	numPtr[9] = 20;

	printf("%d\n", numPtr[0]);
	printf("%d\n", numPtr[9]);

	free(numPtr);
	//메모리 할당한 거 해제

	int size;

	scanf("%d", &size);

	int *numPtr2 = malloc(sizeof(int)*size);

	for (int i = 0; i < size; i++)
	{
		numPtr2[i] = i;
	}

	for (int i = 0; i < size; i++) 
	{
		printf("%d\n", numPtr2[i]);
	}

	free(numPtr2);
	
	/*
	자료형 **포인터이름 = 
	malloc(sizeof(자료형 *) * 세로크기);
	세로 공간 메모리 할당 

	반복문으로 반복하면서 포인터[i] = 
	malloc(sizeof(자료형) * 가로크기);
	가로 공간 메모리 할당 

	반복문으로 반복하면서 free(포인터[i]); 와 같이
	가로 공간 메모리 해제
	*/

	int **m = malloc(sizeof(int *) * 3);
	//이중 포인터에 2차원 배열의 세로 공간에 해당하는
	//메모리를 할당함, 이때 세로 공간에는 값이 들어가지 
	//않고 가로 공간의 메모리 주소가 들어감
	//sizeof(int *)로 포인터의 크기를 구한 뒤에
	//세로 크기 3을 곱해줌 

	for (int i = 0; i < 3; i++)
	{											
		m[i] = malloc(sizeof(int) * 4);
	//세로 크기만큼 반복하면서 2차원 배열의 가로 공간에
	//해당하는 메모리 주소를 할당해줌 
	//m[0],m[1],m[2]는 pointer to int이므로 int *가 들어감
	}

	m[0][0] = 1;
	m[2][0] = 5;
	m[2][3] = 2;

	printf("%d\n", m[0][0]);
	printf("%d\n", m[2][0]);
	printf("%d\n", m[2][3]);

	for (int i = 0; i < 3; i++)
	{
		free(m[i]);
	}

	free(m);
	//세로 공간에 해당하는 메모리를 먼저 해제해버리면
	//가로 공간 메모리를 해제할 수 없으므로 주의할 것 

	int row, col;

	scanf("%d %d", &row, &col);

	int **m1 = malloc(sizeof(int*) * row);

	for (int i = 0; i < row; i++)
	{
		m1[i] = malloc(sizeof(int) * col);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			m1[i][j] = i + j;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < row; i++)
	{
		free(m1[i]);
	}

	free(m1);
	
	
	int x;

	scanf("%d", &x);

	int **m2 = malloc(sizeof(int *) * x);

	for (int i = 0; i < x; i++)
	{
		m2[i] = malloc(sizeof(int) * x);
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (i != j)
				m2[i][j] = 0;
			else
				m2[i][j] = 1;
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < x; i++)
	{
		free(m2[i]);
	}

	free(m2);




	return 0;

}