#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	2차원 배열은 행과 열로 이루어져 있고 모두 0부터 시작함
		열0 열1 열2 ...
	행0
	행1
	행2
	 .
	 .
	 .
	
	2차원 배열은 []를 2번 사용하여 선언하며 첫 번째 대괄호
	에는 세로크기, 두 번째 대괄호에는 가로크기를 지정함
	세로크기 = 행의 개수, 가로 크기 = 열의 개수 
	자료형 배열이름[세로크기][가로크기];
	
	*/
	//세로 크기가 3, 가로 크기가 4인 int형 2차원 배열 선언
	//및 값 초기화하기
	
	int numArr[3][4] = { {11,22,33,44}, {55,66,77,88},
	{99,110,121,132} };

	printf("%d\n", numArr[0][0]); 
	//세로 인덱스0 가로 인덱스 0
	printf("%d\n", numArr[1][2]);
	//세로 인덱스1 가로 인덱스 2 
	printf("%d\n", numArr[2][0]);
	//세로 인덱스2 가로 인덱스 0 
	printf("%d\n", numArr[2][3]);
	//세로 인덱스2 가로 인덱스 3 

	int numArr1[3][4] = { 0, };	//요소를 모두 0으로 초기화 

	printf("%d\n", numArr1[0][0]);
	//세로 인덱스0 가로 인덱스 0
	printf("%d\n", numArr1[1][2]);
	//세로 인덱스1 가로 인덱스 2 
	printf("%d\n", numArr1[2][0]);
	//세로 인덱스2 가로 인덱스 0 
	printf("%d\n", numArr1[2][3]);
	//세로 인덱스2 가로 인덱스 3 

	int numArr2[3][4];	 

	numArr2[0][0] = 11;
	numArr2[0][1] = 22;
	numArr2[0][2] = 33;
	numArr2[0][3] = 44;
	
	numArr2[1][0] = 55;
	numArr2[1][1] = 66;
	numArr2[1][2] = 77;
	numArr2[1][3] = 88;
	
	numArr2[2][0] = 99;
	numArr2[2][1] = 110;
	numArr2[2][2] = 121;
	numArr2[2][3] = 132;
	
	printf("%d\n", numArr2[0][0]);
	//세로 인덱스0 가로 인덱스 0
	printf("%d\n", numArr2[1][2]);
	//세로 인덱스1 가로 인덱스 2 
	printf("%d\n", numArr2[2][0]);
	//세로 인덱스2 가로 인덱스 0 
	printf("%d\n", numArr2[2][3]);
	//세로 인덱스2 가로 인덱스 3 
			
	//2차원 배열의 요소에 접근할 때 인덱스를 음수를 지정
	//하거나 배열의 범위를 벗어나면 실행했을 때 쓰레기 값이
	//출력됨, 즉 배열의 범위를 벗어나 다른 메모리 공간에
	//접근하게 됨, 특히 2차원 배열은 값이 일렬로 쭉 늘어서
	//있어서 num[0][4]와 같이 가로 인덱스가 범위를 벗어나도
	//록 지정하면 그 다음 세로 인덱스 요소인 numArr2[1][0]에
	//접근하게 됨 
	printf("%d\n", numArr2[-1][-1]);
	//음수이므로 잘못된 인덱스
	printf("%d\n", numArr2[0][4]);
	//가로 인덱스가 배열의 범위를 벗어남 
	printf("%d\n", numArr2[4][0]);
	//세로 인덱스가 배열의 범위를 벗어남
	printf("%d\n", numArr2[5][5]);
	//세로, 가로 인덱스 모두 배열의 범위를 벗어남 

	//2차원 배열이 차지하는 전체 공간과 가로, 세로 요소의
	//개수는 sizeof 연산자로 구할 수가 있다


	printf("%lld\n", sizeof(numArr2));	
	//배열이 차지하는 전체 공간의 크기: 4바이트 12개여서
	//48바이트

	int col = sizeof(numArr2[0]) / sizeof(int);
	//2차원 배열의 가로크기: 가로 한 줄의 크기를 요소의
	//크기로 나눠줌
	int row = sizeof(numArr2) / sizeof(numArr2[0]);
	//2차원 배열의 세로크기: 배열이 차지하는 전체 공간을
	//가로 한 줄 크기로 나눠줌

	printf("%d\n", col);
	printf("%d\n", row);

	int numArr3[3][4] = {
	{11,22,33,44},
	{55,66,77,88},
	{99,110,121,132}
	};

	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", numArr3[i][j]);
		}
		printf("\n");
	}

	for (int i = row-1; i >= 0; i--)	
		//배열의 요소는 0부터 시작하므로 역순으로 출력하려면
		//배열의크기 - 1 부터 시작하면 됨
	{
		for (int j = col-1; j >= 0; j--)
		{
			printf("%d ", numArr3[i][j]);
		}
		printf("\n");
	}

	int numArr4[3][4] = {
		{ 11,22,33,44 },
		{ 55,66,77,88 },
		{ 99,110,121,132 }
	};

	//2차원 배열을 포인터에 넣으려면 특별한 방법이 필요함
	//자료형 (*포인터이름)[가로크기];
	//int (*numPtr)[4]; → 가로 크기가 4인 배열을
	//가리키는 포인터라는 뜻임
	//int *numPtr[4] →int형 포인터 4개를 담을 수 있는 배열

	int(*numPtr)[4] = numArr4;

	printf("%p\n", numArr4);
	//세로 첫 번째 행(numArr4[0])의 주소값
	printf("%p\n", numPtr);
	//세로 첫 번째 행의 주소값
	printf("%d\n", **numPtr);
	//첫 번째 요소의 값
	printf("%p\n", *numPtr);
	//세로 첫 행의 첫 번째 요소(numArr4[0][0])의 주소값
	printf("%p\n", numArr4[0]);
	//세로 첫 행의 첫 번째 요소(numArr4[0][0])의 주소값
	printf("%p\n", *numPtr + 1);
	//세로 첫 행의 두 번째 요소(numArr4[0][1])의 주소값

	//2차원 배열을 포인터에 할당한 뒤에 역참조를 해보면
	//배열의 세로 첫 번째 행의 첫 번째 요소의 주소값이
	//나옴, 즉 배열이 시작하는 주소임,
	//마찬가지로 2차원 배열도 역참조해보면 배열의
	//세로 첫 번째 행의 첫 번째 요소의 주소값이 나옴

	printf("%d\n", numPtr[2][1]);
	//2차원 배열 포인터는 []를 2번 사용하여 배열의 요소에
	//접근 할 수가 있음

	printf("%lld\n", sizeof(numArr4)); //배열의 크기
	printf("%lld\n", sizeof(numPtr)); //포인터의 크기
	
	//3차원 배열은 높이 가로 세로 형태로 이루어져 있음
	//3차원 배열은 면이 여러 개 있는 형태
	//자료형 배열이름[높이][세로 크기][가로 크기]
	//값을 초기화 할 때는 면 단위로 묶어줌
	//3차원 배열 예
	int numArr5[2][3][4] = {
	{{11,22,33,44},
	 {55,66,77,88},
	 {99,110,121,132}	
	},
	{{12,24,36,48},
	 {60,72,84,96},
	 {108,120,132,144}
	}
	};

	printf("%d\n", numArr5[0][2][2]);
	numArr5[0][1][2] = 35;
	printf("%d\n", numArr5[0][1][2]);
	int depth = sizeof(numArr5) / sizeof(numArr5[0]);
	//3차원 배열의 높이(깊이)는 배열이 차지하는 전체공간을
	//면의 크기로 나눠줌
	row = sizeof(numArr5[0]) / sizeof(numArr5[0][0]);
	//3차원 배열의 세로 크기는 한 면의 크기를 가로 한 줄의
	//크기로 나눠줌
	int column = sizeof(numArr5[0][0]) / sizeof(int);
	//3차원 배열의 가로 크기는 가로 한 줄의 크기를 요소의
	//크기로 나눠줌

	printf("3차원 배열의 높이: %d\n", depth);
	printf("3차원 배열의 세로 크기: %d\n", row);
	printf("3차원 배열의 가로 크기: %d\n", column);

	//3차원 배열을 포인터에 할당하려면 세로 가로로 구성된
	//면을 가리키는 포인터를 선언하면 됨
	int(*numPtr1)[3][4] = numArr5;
	//세로 크기가 3, 가로 크기가 4인 면을 가리키는 포인터
	printf("%p\n", numPtr1);

	int matrix[5][5];


	for (int i = 0; i < sizeof(matrix) /
		sizeof(matrix[0]); i++)
	{	scanf("%d %d %d %d %d",
		&matrix[i][0], &matrix[i][1],
		&matrix[i][2], &matrix[i][3], &matrix[i][4]);
	}


/*	scanf("%d %d %d %d %d",
		&matrix[1][0], &matrix[1][1],
		&matrix[1][2], &matrix[1][3], &matrix[1][4]);
	scanf("%d %d %d %d %d",
		&matrix[2][0], &matrix[2][1],
		&matrix[2][2], &matrix[2][3], &matrix[2][4]);
	scanf("%d %d %d %d %d",
		&matrix[3][0], &matrix[3][1],
		&matrix[3][2], &matrix[3][3], &matrix[3][4]);
	scanf("%d %d %d %d %d",
		&matrix[4][0], &matrix[4][1],
		&matrix[4][2], &matrix[4][3], &matrix[4][4]);
*/
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(j > i)
			{
				int temp = 0;
				temp = matrix[j][i];
				matrix[j][i] = matrix[i][j];
				matrix[i][j] = temp;
			}
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
		

	return 0;
}