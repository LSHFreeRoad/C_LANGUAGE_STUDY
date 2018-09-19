#include <stdio.h>
#include <math.h>

struct Point2D {
	int x;
	int y;
};

int main()
{
	struct Point2D p1;
	struct Point2D p2;

	p1.x = 30;
	p1.y = 20;

	p2.x = 60;
	p2.y = 50;

	printf("p1: %d %d\n", p1.x, p1.y);
	printf("p2: %d %d\n", p2.x, p2.y);

	int a = p2.x - p1.x;
	int b = p2.y - p1.y;
	
	//루트(√)를 구하려면 sqrt함수를 사용함
	//sqrt(값) double sqrt(double _X);
	//제곱근을 반환, _X가 음수이면 NaN을 반환함

	//제곱근을 뜻하는 square root 에서 따옴
	//math.h 헤더파일에 선언되 있음
	//double c = sqrt((a*a) + (b*b));
	double c = sqrt(pow(a, 2) + pow(b, 2));
	printf("%f\n", sqrt(-7));
	//거듭제곱(power)을 구하는 함수 pow로도 표현할 수 있음
	//pow(값, 지수);
	//double pow(double _X, double _Y);
	//_X의 _Y 거듭제곱을 반환함 , math.h 헤더파일에 선언되 있음
	printf("%f\n", c);

	//int a = p1.x - p2.x;
	//int b = p1.y - p2.y;
	//음수를 두 번 곱해서 양수가 되기 때문에 똑같은 값이 나옴
	/*
	abs, fabs, fabsf 함수를 사용하면 양수 또는 음수를 절댓값으로
	만들 수가 있음, 이 함수도 math.h에 선언되있음(GCC는 stdlib.h)
	
	abs(정수);
	int abs(int_X);
	정수 절댓값을 반환

	fabs(double형 실수);
	double fabs(double_X);
	double형 실수의 절댓값을 반환
	
	fabsf(float형 실수);
	float fabsf(float_X);
	float형 실수의 절댓값을 반환

	int a = p2.x - p1.x;
	int b = p2.y - p1.y;
	distance = sqrt(pow(a, 2) + pow(b, 2)); 
	*/

	return 0;
}