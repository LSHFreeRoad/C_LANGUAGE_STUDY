#include<stdio.h>
#include<limits.h>	//최댓값, 최솟값이 
//정의되있는 헤더파일
int main()
{

	char num1 = CHAR_MIN;
	short num2 = SHRT_MIN;
	int num3 = INT_MIN;
	long num4 = LONG_MIN;
	long long num5 = LLONG_MIN;

	printf("%d\n%d\n%d\n%ld\n%lld\n"
		, num1, num2, num3, num4, num5);

	printf("===========================\n");

	unsigned char num6 = UCHAR_MAX + 1;	//overflow
	unsigned short num7 = USHRT_MAX + 1;	//overflow
	unsigned int num8 = UINT_MAX + 1;		//overflow
	unsigned long num9 = ULONG_MAX + 1;	//overflow
	unsigned long long num10 = ULLONG_MAX + 1;	//overflow
	
	printf("%u\n%u\n%u\n%lu\n%llu\n"
		, num6, num7, num8, num9, num10);

	printf("===================================\n");

	unsigned char num11 = 0 - 1;	//underflow
	unsigned short num12 = 0 - 1;	//underflow
	unsigned int num13 = 0 - 1;		//underflow
	unsigned long num14 = 0 - 1;	//underflow
	unsigned long long num15 = 0 - 1;//underflow

	printf("%u\n%u\n%u\n%lu\n%llu\n"
		, num11, num12, num13, num14, num15);

	return 0;



}

