#include<stdio.h>
int main() 
{
	int num1;
	int num2;

	num1 = 1 + 2;	//1+2 값을 num1에 저장
	num2 = 1 - 2;	//1-2 값을 num2에 저장 

	printf("%d\n", num1);
	printf("%d\n", num2);

	float num3;
	long double num4;

	num3 = 1.0f + 452.6543f;
	num4 = 1236.5324f - 349.53261l;
	
	printf("%f\n", num3);
	printf("%Lf\n", num4);
	printf("%lld\n", sizeof(num4));
	

	int num5 =105;
	int num6 = 934;

	num5 = num5 + 5;	//num5+ 5 = 110(연산) 
	//-> num5 = 110(할당);
	num6 = num6 - 10;

	printf("%d\n", num5);
	printf("%d\n", num6);

	num5 += 5;	//num5 = num5+5
	num6 -= 100; //

	printf("%d\n", num5);
	printf("%d\n", num6);

	return 0;
}
