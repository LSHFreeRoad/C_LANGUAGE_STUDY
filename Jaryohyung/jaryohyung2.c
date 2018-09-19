#include<stdio.h>
int main()
{
	int num1 = 0;
	int size,size1;

	size = sizeof num1; // 표현식
	//표현식은 변수, 상수, 배열 등
	//프로그래머가 만들어낸 요소를 뜻한다

	size1 = sizeof(int);

	printf("num1의 크기 : %d바이트\nint의 크기: %d바이트\n"
		, size, size1 );

	printf("=====================================\n");

	printf("char : %d \nshort : %d \nint : %d \n" 
		,sizeof(char),sizeof(short),
		sizeof(int) );
	printf("long : %d\nlong long : %d\n",sizeof(long)
		, sizeof(long long));


	return 0;


}