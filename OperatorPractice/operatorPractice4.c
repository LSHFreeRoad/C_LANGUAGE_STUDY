#include<stdio.h>
int main()
{
	printf("%d\n", 1 % 3);	//나머지 1
	printf("%d\n", 2 % 3);
	printf("%d\n", 3 % 3);
	printf("%d\n", 4 % 3);
	printf("%d\n", 5 % 3);
	printf("%d\n", 6 % 3);
	//나머지 연산자는 특정 수의 배수인지
	//확인할 때 사용함
	//몇 가지 상태로 강제할 때도 사용함 
	//0으로 나눈 나머지는 구할 수 없음 

	int num1 = 7;

	num1 = num1 % 2;
	//num1을 2로 나눈 나머지를 num1에 할당
	printf("%d\n", num1);

	int num2 = 11;

	num2 %= 3;	//num2를 3으로 나눈 나머지를
				//num2에 할당 
	printf("%d\n", num2);




	return 0;





}