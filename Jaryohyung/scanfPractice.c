#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	/*
	C 언어를 배울 때는 콘솔(터미널, 명령 프롬프트)창에서
	키보드로 글자만 입출력하게 됨 
	표준 입력(명령 프롬프트에서 키보드 입력)
	=standard input, stdin
	표준 출력(명령 프롬프트에서 결과 출력)
	=standard output, stdout
	
	scanf(서식, 변수의 주소)
	int scanf(char const *const_Format, ...)
	성공하면 가져온 값의 개수를 반환,
	실패하면 EOF(-1)을 반환
	
	scanf는 표준 입력으로 사용자의 입력을 받는 함수 
	stdio.h 헤더파일에 선언되 있음 
	
	scanf함수에서 첫 번째 인자는 서식 지정자 %d를 넣어서
	정수를 입력받도록 함, 두 번째 인자는 입력값을 저장할
	변수를 넣어야함
	#define _CRT_SECURE_NO_WARNINGS
	visual studio만 넣으면 됨, 리눅스나 OS X에선
	넣을 필요가 없음
	scanf는 나온지 오래된 함수라 입력값의 길이를 설정할 수가
	없어서 보안에 취약함-> visual studio에서 사용하지 말라는
	경고가 출력되고 컴파일 에러가 발생함
	-> #define _CRT_SECURE_NO_WARNINGS
	(보안에 취약한 함수를 쓰더라도 경고와 컴파일 에러를
	발생시키지 말라는 의미) 
	scanf_s는 입력값의 길이를 설정할 수가 있지만 C언어 
	표준함수는 아니고 Visual Studio(Visual C++) 전용임
	*/

	int num1;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num1);
	printf("%d\n", num1);

	int num2, num3;

	printf("정수를 두 개 입력하세요 : ");
	scanf("%d %d", &num2, &num3);
	//입력받을 개수하고 서식 지정자 개수 및 변수 개수를 
	//똑같이 맞춰야 함 , 그리고 변수 앞에 &을 꼭 써야함 
	printf("%d %d\n", num2, num3);

	float num4;

	printf("실수를 입력하세요 : ");
	scanf("%f", &num4);
	printf("%f\n", num4);

	double num5;

	printf("실수를 입력하세요 : ");
	scanf("%lf", &num5);
	printf("%f\n", num5);

	long double num6;

	printf("실수를 입력하세요 : ");
	scanf("%Lf", &num6);
	printf("%Lf\n", num6);

	char c1;
	scanf("%c", &c1);

	char c2;
	printf("문자를 입력하세요 : ");
	scanf("%c", &c2);	//문자 하나가 입력됨 
	printf("%c\n", c2);
	
	char cb;
	scanf("%c", &cb);

	printf("문자를 입력하세요 : ");
	char c3 = getchar();	//문자 하나를 입력받음
	printf("%c\n", c3);

	return 0;
	
}