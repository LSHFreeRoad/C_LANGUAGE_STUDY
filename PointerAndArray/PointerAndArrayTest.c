#include <stdio.h>
int main()
{


	//2차원 배열을 포인터에 넣으려면 특별한 방법이 필요함
	//자료형 (*포인터이름)[가로크기];
	//int (*numPtr)[4]; → 가로 크기가 4인 배열을
	//가리키는 포인터라는 뜻임
	//int *numPtr[4] →int형 포인터 4개를 담을 수 있는 배열

	int numArr4[3][4] = {
		{ 11,22,33,44 },
		{ 55,66,77,88 },
		{ 99,110,121,132 }
	};
	int(*numPtr)[4] = numArr4;

	printf("%p\n", numArr4);
	//세로 첫 번째 행(numArr4[0])의 주소값
	printf("%p\n", &numArr4);
	printf("%p\n", numArr4 + 1);
	//세로 두 번째 행의 주소값
	printf("%p\n", numPtr);
	//세로 첫 번째 행의 주소값
	printf("%p\n", numPtr + 1);
	//세로 두 번째 행의 주소값 
	printf("%d\n", **numPtr);
	//첫 번째 요소의 값
	printf("%p\n", *numPtr);
	//세로 첫 행의 첫 번째 요소(numArr4[0][0])의 주소값
	printf("%p\n", numArr4[0]);
	//세로 첫 행의 첫 번째 요소(numArr4[0][0])의 주소값
	printf("%p\n", *numPtr + 1);
	//세로 첫 행의 두 번째 요소(numArr4[0][1])의 주소값

	printf("%p\n", *numArr4);

	printf("%lld %lld %lld \n", sizeof(numArr4), sizeof(*numArr4), sizeof(**numArr4));
	printf("%lld %lld %lld\n", sizeof(numPtr), sizeof(*numPtr), sizeof(**numPtr));

	return 0;
}