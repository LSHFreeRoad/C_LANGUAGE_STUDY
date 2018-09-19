#include<stdio.h>
#include<stdint.h>	//크기가 표시된 정수 자료형
//stdint의 최대 최솟값이 정의되있는 헤더파일
int main()
{
	int8_t num1 = -128;	
	//8비트(1바이트) 크기의 부호있는 정수 자료형 선언
	int8_t num5 = INT8_MAX;
	int sizeNum1 = sizeof(int8_t);

	int16_t num2 = 32767;
	//16비트(2바이트) 크기의 부호있는 정수 자료형 선언
	int16_t num6 = INT16_MIN;
	int sizeNum2 = sizeof(int16_t);

	int32_t num3 = 2147483647;
	//32비트(4바이트) 크기의 부호있는 정수 자료형 선언
	int32_t num7 = INT32_MIN;
	int sizeNum3 = sizeof(int32_t);

	int64_t num4 = 9223372026854775807;
	//64비트(8바이트) 크기의 부호있는 정수 자료형 선언
	int64_t num8 = INT64_MIN;
	int sizeNum4 = sizeof(int64_t);

	printf("%d\n%d\n%d\n%lld\n", num1, num2, num3, num4);
	printf("%d\n%d\n%d\n%lld\n", num5, num6, num7, num8);

	printf("num1 크기: %d\nnum2 크기: %d\n"
		,sizeNum1,sizeNum2);
	printf("num3 크기: %d\nnum4 크기: %d\n"
		,sizeNum3, sizeNum4);

	return 0;

}