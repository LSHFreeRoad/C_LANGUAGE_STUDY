#include <stdio.h>

void printArray(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void setElement(int arr[])
{
	arr[2] = 300;
}

void printArray2(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

swapElement(int arr[], int first, int second)
{
	int temp;

	temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
	//배열의 메모리 주소를 받아서 주소에 직접 접근해서 값을 변경함
}

//GCC, Clang에서만 지원함 
//void printArray3(int arr[static 5], int count)
//{
//	for (int i = 0; i < count; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//}




void print2DArray(int arr[][5], int col, int row)
{
	//함수에서 2차원 배열을 매개변수로 사용할때는 괄호를 2개 붙이고 
	//2번째 괄호에서는 가로크기를 지정함 
	//즉, arr[][5]는 2차원 배열의 메모리 주소를 담고 있는 포인터이며
	//2차원 배열의 실제 크기를 알 수 없으므로 다른 매개변수로 
	//배열의 가로, 세로 크기를 받아야 함

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}

void print2DArray2(int (*arr)[5], int col, int row)
{
	//가로크기가 5인 2차원 배열을 가리키는 포인터
	//포인터로는 2차원 배열의 크기를 알 수 없으므로 다른 매개변수를
	//통해서 가로, 세로 크기를 받음 
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}

void transpose(int (*arr)[4], int n)
{
	int temp;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (j > i)
			{
				temp = arr[i][j];
				arr[i][j] = arr[j][i];
				arr[j][i] = temp;
			}
		}
	}

}


int main()
{
	/*
	함수에서 배열을 매개변수로 사용하면 연속된 값을 전달할 수 있음
	함수에 전달한 배열의 요소를 함수 안에서 변경이 가능함
	반환값 자료형 함수이름(자료형 매개변수[])
	{
	}
	반환값 자료형 함수이름(자료형 *매개변수)
	{
	}
	*/

	int numArr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	printArray(numArr, sizeof(numArr) / sizeof(int));

	setElement(numArr);
	//배열의 메모리 주소 전달 

	printf("%d\n", numArr[2]);

	printArray2(numArr, sizeof(numArr) / sizeof(int));
	
	swapElement(numArr, 0, 1);
	//배열의 메모리 주소 전달
	printf("%d %d\n", numArr[0], numArr[1]);

	/*복합 리터럴 사용하기 -> 함수에 배열을 넘겨줄 때 복합 리터럴을
	사용하면 배열을 따로 선언하지 않아도 됨(복합 리터럴은 C99에
	추가된 기능임), 
	(자료형[]) {값1, 값2, 값3} 
	(자료형[크기]) {값1, 값2, 값3}
	*/
	
	printArray((int[]) { 21, 25, 32, 43 , 56}, 5);

	/*
	2차원 배열을 매개변수로 사용하기 
	반환값 자료형 함수이름(자료형 매개변수[][가로크기]
	{
	}
	
	반환값 자료형 함수이름(자료형 (*매개변수)[가로크기])
	{
	}

	*/

	int numArr2[2][5] = { {1,2,3,4,5},{6,7,8,9,10} };

	int col = sizeof(numArr2[0]) / sizeof(int);
	//가로 크기는 2차원 배열의 가로 한 줄을 자료형의 크기로 나눔 

	int row = sizeof(numArr2) / sizeof(numArr2[0]);
	//세로 크기는 2차원 배열 전체 크기를 가로 한 줄로 나눔 
	print2DArray(numArr2, col, row);

	print2DArray2(numArr2, col, row);

	/*
void printReverse(int arr[], int count)  
{
	for(int i = 0; i < count; i++)
		printf("%d ", arr[count - (i + 1)]);

	printf("\n");
}
	*/

	int numArr3[4][4] = { {1,2,3,4},{5,6,7,8,},{9,10,11,12},
	{13,14,15,16} };

	transpose(numArr3, 4);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", numArr3[i][j]);
		}
		printf("\n");
	}






	return 0;
}