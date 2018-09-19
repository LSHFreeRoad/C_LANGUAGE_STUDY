#include<stdio.h>
#include<float.h> 
//실수 자료형의 최댓값,최솟값이 있는 헤더파일
int main()
{
	/*
	프로그래밍 언어에서 실수(real number)는
	소수점이 있는 수를 말함
	실수는 실수 자료형에 저장 
	실수 자료형: float, double ,long double
	실수는 부동소수점 방식으로 정함
	IEEE 754 표준규약 
	소수점이 떠다닌다고 해서 floating point
	double은 float의 두 배 크기라서 double 
	long double은 double보다 길어서 그런 것
	부동소수점 방식 : ±(부호) m(가수) x nⁿ(기수,지수)
	기수는 2로 고정되있음, 저장할 때는 2 생략 
	float는 단정밀도 부동소수점 저장방식
	double은 배정밀도 부동소수점 저장방식
	double이 좀 더 긴 자릿수의 소수점을 정밀하게 표현이 가능
	window 운영체제에서의 실수 자료형의 크기
	float : 4바이트, double: 8바이트, long double : 8바이트
	유효자릿수: float 7, double 16, long double 16 
	long double은 운영체제마다 크기가 다름
	*/
	
	float num1 = 0.1f;
	//.1f 1.f 가능 (0생략)
	double num2 = 3867.21564;
	long double num3 = 9.3425351l;

	//%f : floating point의 약자 
	//%Lf : long floating point의 약자 

	printf("%f\n%f\n%Lf\n",num1,num2,num3);

	/*
	지수 표기법(exponential notation)
	정수 부분을 한 자리로 만들고 지수를 표시

	실수e+지수 : 실수 *10의 거듭제곱
	2.1e + 3은 2.1*1000 = 2100을 의미
	
	실수e-지수 : 실수 *(1/10)의 거듭제곱
	2.1e - 2은 2.1*(1/100) = 0.021을 의미
	*/

	float num4 = 3.e5f;	//300000 지수가 양수일 때 + 생략가능
	double num5 = -1.3827e-2;	//-0.013827	
	long double num6 = 5.21e+9l;	

	printf("%e\n%e\n%Le\n", num4, num5, num6);
	//%e 는 지수표기법(exponential notation)의 약자
	//%Le 는 long exponential notation의 약자 

	float num7 = 0.0f;
	double num8 = 0.0;
	long double num9 = 0.0l;

	printf("float : %lld\ndouble : %lld\nlong double : %lld\n"
		, sizeof(num7),sizeof(num8),sizeof(num9) );

	float num10 = FLT_MIN;
	float num11 = FLT_MAX;
	double num12 = DBL_MIN;
	double num13 = DBL_MAX;
	long double num14 = LDBL_MIN;
	long double num15 = LDBL_MAX;

	printf("%.40f\n%.2f\n", num10, num11);	
	//소수점이하 자릿수 지정 .40f -> 소수점 이하 40자리까지
	printf("%e\n%e\n", num12, num13);
	//지수 표기법으로 출력
	printf("%Le\n%Le\n", num14, num15);

	float num16 = FLT_MIN;
	float num17 = FLT_MAX;
	float num18 = -FLT_MAX*10000000000;
	float num19 = -FLT_MIN / 10000000000000000;
	
	num16 = num16 / 1000000000.0f;
	num17 = num17 *1000.0f;

	printf("%e\n%e\n%e\n%e\n", num16, num17,num18, num19);
	//INF ->  무한대(양수 최댓값에서 오버플로우 발생할 때)
	//-INF -> 마이너스 무한대(음수 최솟값에서 
	//언더 플로우 발생할 때)
	//0또는 쓰레기 값으로 처리(양수 최솟값에서 
	//언더 플로우 발생할 때) 
	
	return 0;


}