#include<stdio.h>
int main()
{
	/*
	상수는 변하지 않는 값을 뜻함(constant)
	리터럴은 값 그 자체를 뜻함 
	상수는 변수처럼 리터럴이 저장된 공간 
	const int con1 = 10;
	con1 -> 상수, 10-> 리터럴 	
	상수는 값이 의도치 않게 바뀌는 것을 방지하기 위해 사용
	코드의 의도를 명확하게 만들 수 있음 
	리터럴 
	*/

	printf("%d\n", 10);	//10: 정수 리터럴
	printf("%f\n", 0.1f);	//0.1f: 실수 리터럴
	printf("%c\n", 'a');	//'a': 문자 리터럴
	printf("%s\n", "hello world");	
	//hello world: 문자열 리터럴
	//문자는 작은 따옴표로 묶고
	//문자열은 큰 따옴표로 묶어줘야됨

	printf("%d\n", 17);
	printf("0%o\n", 021);	//8진수는 숫자 앞에 0을 붙임
	//8진수 0~7까지 사용
	//%o -> octal number의 약어로 o를 사용함
	printf("0x%X\n", 0x1F);	//16진수는 0x를 붙임
	//10~15는 A~F로 사용 

	printf("%f\n", 0.1f);
	printf("%f\n", 0.1F);
	printf("%f\n", 1.0e-5f);
	printf("%f\n", 1.0E-5f);

	const int con1 = 1;
	const float con2 = 0.1f;
	const char con3 = 'a';
	//const는 자료형 앞 뒤로 올 수가 있음 
	//상수는 선언과 동시에 값 할당을 해줘야됨(초기화)
	//안하면 컴파일 에러가 발생

	printf("================================\n");
	printf("%d %f %c\n", con1, con2, con3);

	printf("%ld\n", -10L);
	printf("%lld\n", -12948384928985923ll);

	printf("%lu\n", 10ul);
	printf("%llu\n", 18438929381894ULL);

	printf("%lu\n", 10UL);
	printf("%llu\n", 1293989481239892Ull);	
	//대소문자를 섞어 쓰는 것도 가능함
	//리터럴은 접미사를 활용해서 크기를 명확하게 표현함

	//8진수와 16진수에도 접미사를 사용할 수 있음

	printf("0%lo\n", 017L);
	printf("0%lo\n", 017Ul);	
	//%u는 %o와 동급이라 같이 안 씀
	printf("0x%lx\n", 0x7FAbcael);
	printf("0x%llx\n", 0xF6535d45829ull);
	//%u는 %x와 동급이라 같이 안 씀
	
	printf("%f\n", 0.1f);	
	//0.100000 : float 크기의 실수 리터럴
	printf("%f\n", 0.1F);	
	printf("%f\n", 0.1);
	//0.100000 : double 크기의 실수 리터럴
	printf("%Lf\n", 0.1l);	
	//0.100000: long double 크기의 실수 리터럴
	printf("%Lf\n", 0.1L);

	printf("========================================\n");

	printf("%f\n", 1.0e-5f);
	//0.000010 : float 크기의 실수 리터럴
	printf("%f\n", 1.0e-5F);
	printf("%f\n", 1.0e-5);
	//0.000010 : double 크기의 실수 리터럴
	printf("%Lf\n", 1.0e-5l);
	//0.000010 : long double 크기의 실수 리터럴
	printf("%Lf\n", 1.0e-5L);
	
	return 0;
}