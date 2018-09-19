#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	배열은 같은 자료형의 변수를 일렬로 늘어놓은 형태
	연속적이고 반복되는 값을 손쉽게 처리할 수가 있음
	자료형 배열이름[크기]; 배열 선언
	자료형 배열이름[크기] = {값,값,값...}; 배열을
	선언하면서 값 할당(초기화)을 할 때는 중괄호를 씀
	*/

	int numArr[10] = { 11,22,33,44,55,66,77,88,99,110 };
	//크기가 10인 배열을 선언하면서 값 할당
	//초기화를 할 때는 중괄호 안의 값 개수는 배열의
	//크기 보다 작거나 같아야 되고 크면 안 됨
	//중괄호는 초기화 할 때만 쓸 수가 있고
	//이미 선언된 배열에는 쓸 수가 없음
	//배열에 값이 저장된 공간을 요소(element)라고 함
	//배열의 각 요소에 접근하려면 []를 사용하고 각 요소의
	//인덱스를 지정해주면 됨, 인덱스는 0부터 시작함
	//배열을 선언할 때의 []는 이 변수가 배열이고 크기는
	//얼마다라고 알려주는 역할이고 배열의 요소에 접근할
	//때의 []는 배열의 요소에 접근하겠다라는 의미임
	//배열의 인덱스가 0부터 시작하는 이유는 메모리 주소가
	//0부터 시작하기 때문임, 배열도 포인터로 취급되서
	//인덱스가 0부터 시작하면 요소 접근과 포인터 연산이
	//일치하게 됨 

	printf("%d\n", numArr[0]);
	printf("%d\n", numArr[5]);
	printf("%d\n", numArr[9]);

	//배열의 모든 요소를 간단하게 0으로 초기화	
	//-> 자료형 배열이름[크기] = { 0,};

	int numArr1[10] = { 0, };

	printf("%d\t", numArr1[0]);
	printf("%d\t", numArr1[5]);
	printf("%d\n", numArr1[9]);

	numArr1[0] = 11;
	numArr1[1] = 22;
	numArr1[2] = 33;
	numArr1[3] = 44;
	numArr1[4] = 55;
	numArr1[5] = 66;
	numArr1[6] = 77;
	numArr1[7] = 88;
	numArr1[8] = 99;
	numArr1[9] = 110;

	printf("%d\t", numArr1[0]);
	printf("%d\t", numArr1[5]);
	printf("%d\n", numArr1[9]);
	printf("%d\n", numArr1[-1]);
	printf("%d\n", numArr1[10]);
	printf("%d\n", numArr1[20]);
	//배열의 요소에 벗어난 인덱스에 접근하면 컴파일
	//에러는 발생하지 않지만 실행해보면 쓰레기 값이
	//출력됨, 즉 배열의 범위를 벗어난 인덱스에 접근하면 
	//배열이 아닌 다른 메모리 공간에 접근하게 됨
	//쓰레기 값은 메모리에서 이전에 사용하던 값인데
	//현재는 필요없어진 값임

	int numArr2[15] = { 11,22,33,44,55,66,77,88,99,110,121
	,132,143,154,165 };
	//배열이 차지하는 전체 공간과 개수는 sizeof연산자를
	//사용하면 구할 수 있음
	//sizeof(배열) -> 배열이 차지하는 공간
	//sizeof(배열)/ sizeof(자료형) -> 배열의 크기
	//즉, 요소의 개수

	printf("%lld\n", sizeof(numArr2));
	//배열이 차지하는 공간 ->60
	printf("%lld\n", sizeof(numArr2) / sizeof(int));
	//배열의 크기 ->15

	for (int i = 0; i < sizeof(numArr2) / sizeof(int);
		i++)	//배열의 요소 개수만큼 반복 
	{
		printf("%d\n", numArr2[i]);	//배열의 요소를
	//인덱스 0부터 순서대로 접근함
	}


	for (int i = (sizeof(numArr2) / sizeof(int)) - 1;
		i >= 0; i--)	//배열의 요소 개수만큼 반복 
	{	//마지막 요소의 인덱스는 요소의 개수 - 1 
		printf("%d\n", numArr2[i]);	//배열의 요소를
		//마지막 인덱스부터 역순으로 접근함
	}

	int sum = 0;
	int numArr3[10] = { 11,22,33,44,55,66,77,88,99,110 };
	//sum을 초기화해주지 않으면 스레기 값이 출력될 수 있음

	for (int i = 0; i < sizeof(numArr3) / sizeof(int); i++)
	{
		sum += numArr3[i];
	}

	printf("%d\n", sum);

	for (int i = 0; i < sizeof(numArr3) / sizeof(int); i++)
	{
		numArr3[i] *= 2;
		//반복문으로 반복하면서 배열에 저장된 값을 
		//변경할 수가 있음
	}

	for (int i = 0; i < sizeof(numArr3) / sizeof(int); i++)
	{
		printf("%d\n", numArr3[i]);
	}

	//배열은 첫 번째 요소의 주솟값만 담고 있음

	int *numPtr = numArr3;	//배열을 포인터에 바로 할당할 
	//수 있음, 하지만 자료형이 같아야 하고 *가 한 개인
	//단일 포인터이어야함
	printf("%d\n", *numPtr);	//배열을 포인터에 할당한
	//뒤에 역참조해보면 첫 번째 요소가 나옴
	printf("%d\n", *numArr3);	//배열 자체도 역참조해보면
	//배열의 첫 번째 요소의 값이 나옴
	//실제로 배열도 포인터라고 할 수 있음
	//배열의 주소가 들어있는 포인터는 인덱스를 통하여
	//해당 요소의 값에 접근할 수가 있음
	//배열과 포인터가 다른 점은 sizeof로 크기를 계산했을
	//때이다, 배열에 sizeof연산자를 사용하면 배열이
	//차지하는 전체공간이 출력되지만 sizeof로 포인터의
	//크기를 구해보면 그냥 포인터의 크기만 나옴
	//포인터의 크기: 32비트-> 4바이트 , 64비트 -> 8바이트
	printf("%d\n", numPtr[5]);

	printf("%lld\n", sizeof(numArr3));
	printf("%lld\n", sizeof(numPtr));

	//10진수를 2진수로 변환, 10진수를 계속 2로 나눠서
	//몫이 0이 나오면 아래서부터 읽으면 됨

	int decimal = 13;
	int binary[20] = { 0, }; //배열의 모든 요소를 0으로 
	//초기화를 함

	int position = 0;
	while (1)
	{
		binary[position] = decimal % 2;
		decimal = decimal / 2;
		position++;
		if (decimal == 0)
			break;
	}

	for (int i = position - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}

	printf("\n");

	int numArr5[5];
	int smallestNumber;

	scanf("%d %d %d %d %d", &numArr5[0], &numArr5[1],
			&numArr5[2], &numArr5[3], &numArr5[4]);

	smallestNumber = numArr5[0];
	for(int i =1; i<(sizeof(numArr5) / sizeof(int)); i++)
	{	
		if (smallestNumber > numArr5[i])
				smallestNumber = numArr5[i];
	}

	printf("%d\n", smallestNumber);

	return 0;
}



