//변수:값을 저장하는 공간으로 그릇과 비슷함

// int -> 자료형(타입) , num1 : 변수 이름 
//변수를 만드는 과정 -> 변수를 선언하다.
//int -> 정수를 뜻하는 integer의 축약형
//C 언어는 저장할 값의 종류에 따라 자료형이 달라짐 
//C 언어는 변수 생성 과정을 "변수를 선언한다"라고 함
//그리고 변수를 선언할 때는  맨 뒤에 ;을 붙여줘야한다
//변수를 선언한다고 하는 이유는 
//C 언어는 무조건 위에서 아래로 해석되기 때문에 
//변수를 사용하려면 사용하는 부분보다 위에 먼저
//변수가 선언이 되어있어야 가능함 
//변수 선언 = 변수가 있다는 것을 알려주는 것을 의미함
//변수명 규칙: #1. 영문 문자와 숫자 사용가능
//#2. 대소문자 구별, #3. 문자부터 시작해야함
//숫자부터 시작하면 안 됨
//#4. 밑줄 문자(_)로 시작이 가능함
//#5. C 언어 키워드(int,float,if,for 등)는 사용 불가


#include<stdio.h>
int main() 
{
	int num1;
	int num2;
	int num3;

	num1 = 10;	//변수에 값 저장 = 변수에 값 할당
	num2 = 20;	// =는 num1에 10을 할당한다는 의미
	num3 = 30;	// 변수 1 =변수 2 사용가능

	printf("%d %d %d\n", num1, num2, num3);
	//%d는 10진수(decimal)를 출력할 때 사용하는 
	//서식 지정자 
	//서식 지정자 하나에 변수(값)하나가 대응됨
	
	//*변수 여러 개 선언 방법
	//자료형 변수1,변수2,변수3;

	return 0;	//함수 바깥으로 값을 전달하는 반환값 부분
}
