#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	논리 연산자는 조건식이나 값을 논리적으로 판단함  
	if 조건문에서 조건식을 판단할 때 주로 사용함
	&& : AND(논리곱), 양쪽 모두 참일 때 참임
	|| : OR(논리합), 양쪽 중 한 쪽만 참이라도 참임
	! : NOT(논리 부정), 참과 거짓을 뒤집음
	거짓은 0을 사용하고 참은 보통 1을 사용함 

	*/
	
	//c 언어에서는 0이 아닌 모든 값이 참임 
	printf("%d\n", 1 && 1);	//둘 다 참이어야 함 
	//논리 연산에서 중요한 부분이 단락
	//평가인데 단락평가는 첫 번째 값의 결과가 확실할 때 
	//두 번째 값은 확인(평가)하지 않는 방법이다
	printf("%d\n", 1 && 0);	//첫 번째 값이 거짓이면
	//두 번째 값에 상관없이 전체 논리값은 거짓(0)이 됨 
	printf("%d\n", 0 && 1);
	printf("%d\n", 0 && 0);
	printf("%d\n", 2 && 3);
	printf("===================\n");
	
	printf("%d\n", 1 || 1);	//하나만 참이면 참이 됨 
	printf("%d\n", 1 || 0);
	printf("%d\n", 0 || 1);
	printf("%d\n", 0 || 0);
	printf("%d\n", 2 || 3);
	printf("===================\n");

	printf("%d\n", !1);
	printf("%d\n", !0);
	printf("%d\n", !3);
	printf("===================\n");

	int num1 = 20, num2 = 10, num3 = 30, num4 = 15;

	printf("%d\n", num1 > num2 && num3 > num4);	
	//양쪽 모두 참이어서 참
	printf("%d\n", num1 > num2 && num3 < num4);
	//앞만 참이므로 거짓
	printf("%d\n", num1 > num2 || num3 < num4);
	//앞에 것이 참이므로 참 
	printf("%d\n", num1 < num2 || num3 < num4);
	//양쪽 모두 거짓이므로 거짓
	printf("%d\n", !(num1 > num2));
	//참의 not 연산은 거짓
	printf("===================\n");

	int num5 = 1, num6 = 0;

	if (num5 && num6)	//num6가 거짓이므로 거짓 
		printf("참\n");
	else
		printf("거짓\n");


	if (num5 || num6)	//num5가 참이므로 참
		printf("참\n");	
	else
		printf("거짓\n");

	if (!num5)	//
		printf("참\n");
	else
		printf("거짓\n");

	printf("=====================\n");
	int num7 = 1, num8 = 0;
	printf("%s\n", num7 && num8 ? "참" : "거짓");
	printf("%s\n", num7 || num8 ? "참" : "거짓");
	
	int num9, num10;
	
	scanf("%d %d", &num9, &num10);
		
	printf("%s\n", num9 && num10 ? "참" : "거짓");
	printf("%s\n", num9 || num10 ? "참" : "거짓");
	printf("%s\n", !num9 ? "참" : "거짓");


	return 0;
}