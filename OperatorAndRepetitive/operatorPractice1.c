#include<stdio.h>
int main()
{
	/*비교 연산자는 값을 비교할 때 사용함 
	== : 같음 , != : 다름, > : 큼, < : 작음
	>= : 크거나 같음 , <= : 작거나 같음 
	삼항 연산자는 if else의 축약형
	( ? : ) ?앞에 값이 참이면 : 앞에 코드가 실행되고
	? 앞에 값이 거짓이면 : 뒤에 코드가 실행됨 
	단항 연산자 : +x , ++x 등(연산할 값이 1개)
	이항 연산자 : a + b, a+=b 등(연산할 값이 2개)
	삼항 연산자 : x ? a : b(연산할 값이 3개) 
	변수 ? 값1 : 값2	
	참이면 1, 거짓이면 0	
	*/

	int num1 = 10;

	printf("%d\n", num1 == 10);
	printf("%d\n", num1 != 10);

	printf("%d\n", num1 > 10);
	printf("%d\n", num1 < 10);

	printf("%d\n", num1 >= 10);
	printf("%d\n", num1 <= 10);

	int num2 = 5;
	int num3;

	if (num2)
		num3 = 100;	//num2가 참(1)이면 num3에 100을 할당함 
	else
		num3 = 200;	//num2가 거짓(0)이면 num3에 200을 할당함

	printf("%d\n", num3);

	int num4 = -200 ? 200 : 300; //num2가 참(0이 아님)이면
	//num4에 200할당, num2가 거짓(0)이면 num4에 300할당 
	printf("%d\n", num4);

	int num5 = num4 == 300 ? 50 : 150;
	//num4 == 300이 참이면 num5에 50이 할당되고 
	//거짓이면 150이 할당됨
	
	printf("%d\n", num5);

	int num6 = 100;

	if (num6 == 100)
		printf("100입니다.\n");

	if (num6 != 50)
		printf("50이 아닙니다.\n");
	
	if (num6 > 30)
		printf("30보다 큽니다.\n");
	
	if (num6 < 70)
		printf("70보다 작습니다.\n");

	if (num6 >= 200)
		printf("200보다 크거나 같습니다.\n");
	
	if (num6 <= 150)
		printf("150보다 작거나 같습니다.\n");

	float num7 = 0.1f;
	char c1 = 'c';

	if (num7 >= 0.09f)
		printf("0.09보다 크거나 같습니다.\n");
	//실수 자료형은 비교 연산자를 사용하여 비교할 수 있지만
	//반올림 오차가 발생하므로 ==연산자를 이용해서 
	//특정 실수와 같은지 비교하는 것은 위험함 
	if (c1 == 'a')
		printf("a입니다.\n");

	if (c1 == 99)
		printf("99입니다.\n");

	if (c1 < 'd')
		printf("d보다 작습니다.\n");

	int num8 = 5;

	printf("%s\n", num8 == 10 ? "10입니다." : "10이 아닙니다.");
	//삼항 연산자는 참 거짓을 판별해서 특정 값을 함수에 전달할 때
	//유용하게 쓸 수가 있음


	
	return 0;
}
