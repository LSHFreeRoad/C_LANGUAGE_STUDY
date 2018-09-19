#include<stdio.h>
int main()
{
	/*
	C 언어는 다양한 정수 자료형을 제공함
	정수는 부호와 크기에 따라 자료형이 달라짐
	정수 자료형은 부호 + 정수자료형을 조합해서 사용함
	signed 부호 있는 정수 음수, 0 ,양수 , 생략 가능
	unsigned 부호 없는 정수 0, 양수 , 생략 불가
	signed int = int
	unsigned int = unsigned
	생략 가능한 키워드 : signed, int
	signed int는 보통 int로 선언
	부호 + 문자 자료형 C 언어에서는 문자를 정수취급함
	signed char = char
	unsigned char 생략불가
	부호 + short 자료형
	정수 자료형은 int에 short와 long을 붙여서
	크기를 나타냄
	signed short int = short
	unsigned short int = unsigned short
	부호 + long 자료형


	부호 + long long 자료형


	부호		정수 자료형
	signed		char			ㅣ 자료형의 크기
				short int		ㅣ
	unsigned	int				ㅣ
				long int		ㅣ
				long long int	ㅣ
								↓

	char -> 1바이트
	short int -> 2바이트
	int, long int -> 4바이트
	long long -> 8바이트

	long은 운영체제마다 크기가 다름
	windows(32,64비트 둘 다 4바이트)
	리눅스(32비트 4바이트, 64비트 8바이트)
	OS X(32비트 4바이트, 64비트 8바이트)

	short, long, long long은 기본적으로 int를 생략함
	*/

	char num1 = -10;
	short num2 = 30000;
	int num3 = -12345645;
	long num4 = 123542643;
	long long num5 = -1238493859813;

	printf("%d\n%d\n%d\n%ld\n%lld\n"
		, num1, num2, num3, num4, num5);

	/*
	%d -> 10진수 decimal의 첫 글자를 따서 사용
	%ld -> long decimal의 첫글자를 따서 사용
	%lld -> long long decimal의 첫글자를 따서 사용
	*/

	printf("================================\n");

	unsigned char num6 = 200;
	unsigned short num7 = 35325;
	unsigned int num8 = 3493253;
	unsigned long num9 = 34939952935352;
	unsigned long long num10 = 34285874892378934;

	printf("%u\n%u\n%u\n%lu\n%llu\n",num6,num7,num8,num9,num10);

	/*%u -> unsigned decimal의 첫 글자를 따서 사용
	(decimal 제외)
	% lu -> long unsigned decimal의 첫글자를 따서 사용
	(decimal 제외)
	% llu -> long long unsigned decimal의
	첫글자를 따서 사용(decimal 제외)
	*/

	printf("=============================\n");

	char num11 = 128;	//최댓값 : 127 
						//오버플로우(overflow)가 발생해서 그 다음값인 -128이 됨
	unsigned char num12 = 256; //최댓값 : 255
							   //오버플로우(overflow)가 발생해서 그 다음값인 0이 됨

	printf("%d\n%u\n", num11, num12);

	char num13 = -129;	//최솟값 : -128
						//언더플로우(underflow)가 발생해서 다음값인 127이 됨
	unsigned char num14 = -1; //최솟값 : 0
							  //언더플로우(underflow)가 발생해서 다음값인 255가 됨
	unsigned char num15 = -2; //최솟값 : 0
							  //언더플로우(underflow)가 발생해서 다 다음값 254가 됨

	printf("%d\n%u\n%u\n", num13, num14, num15);

	return 0;

}
