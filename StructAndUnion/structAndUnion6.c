#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct Point2D {
	int x;
	int y;
};

struct Person {
	char name[30];
	int age;
};

int main()
{
	/*
	구조체 배열 
	struct 구조체 이름 변수 이름[크기]
	*/
		
	struct Point2D p[3];

	p[0].x = 10;
	p[0].y = 20;
	p[1].x = 30;
	p[1].y = 40;
	p[2].x = 50;
	p[2].y = 60;

	printf("%d %d\n", p[0].x, p[0].y);
	printf("%d %d\n", p[1].x, p[1].y);
	printf("%d %d\n", p[2].x, p[2].y);

	//인덱스로 요소에 접근한 뒤 점으로 멤버에 접근함 

	/*
	구조체 배열을 선언하면서 초기화를 할려면 {} 안에 중괄호를
	사용하면 됨, struct 구조체이름 변수이름[크기] 
	={{.멤버이름1 = 값1, .멤버이름2 = 값2},
	{ .멤버이름1 = 값3, .멤버이름2 = 값4} };
	struct 구조체이름 변수이름[크기] = {{값1 ,값2 } 
	, {값3 ,값4 }};
	*/

	struct Point2D p1[3] = { {.x = 15,.y = 25}, {.x = 35,.y = 45},
	{.x = 55,.y = 65} };

	printf("%d %d\n", p1[0].x, p1[0].y);
	printf("%d %d\n", p1[1].x, p1[1].y);
	printf("%d %d\n", p1[2].x, p1[2].y);

	struct Point2D p2[3] = { { 13, 23 },{ 33, 43 },
	{ 53, 63 } };

	printf("%d %d\n", p2[0].x, p2[0].y);
	printf("%d %d\n", p2[1].x, p2[1].y);
	printf("%d %d\n", p2[2].x, p2[2].y);

	struct Point2D *p3[3];
	//구조체 포인터 배열 선언

	for (int i = 0; i < sizeof(p3) / sizeof(struct Point2D *); i++)
	{
		p3[i] = malloc(sizeof(struct Point2D));
	}
	//배열크기(요소 개수)만큼 반복하면서 각 요소에 구조체 크기만큼
	//메모리를 할당해줌, 요소 개수를 구하려면 구조체 포인터 배열
	//전체크기에서 구조체 포인터 크기로 나눠주면 됨
	//sizeof(p3) -> 구조체 포인터 배열크기
	//sizeof(struct Point2D *) -> 구조체 포인터 크기

	p3[0]->x = 11;
	p3[0]->y = 21;
	p3[1]->x = 31;
	p3[1]->y = 41;
	p3[2]->x = 51;
	p3[2]->y = 61;

	//구조체 포인터 배열에서 각 요소에 접근하려면 배열 뒤에
	//대괄호를 사용하여 대괄호 안에 인덱스를 지정해주면 됨
	//배열안에 들어있는 요소가 포인터이므로 화살표 연산자를
	//사용하여 멤버에 접근해야함 

	printf("%d %d\n", p3[0]->x, p3[0]->y);
	printf("%d %d\n", p3[1]->x, p3[1]->y);
	printf("%d %d\n", p3[2]->x, p3[2]->y);

	//구조체 포인터 배열의 사용이 끝나면 메모리를 해제함

	for (int i = 0; i < sizeof(p3) / sizeof(struct Point2D *); i++)
	{
		free(p3[i]);
	}
	
	
	//size_t 자료형은 부호 없는 정수 자료형이고 sizeof 연산자나
	//offsetof 매크로의 결과가 size_t이다.
	//size_t를 출력할 때는 서식지정자에 z를 붙임
	size_t size = sizeof(int);
	size_t offset = offsetof(struct Point2D, x);
	//size_t는 32비트에서는 4바이트, 64비트에서는 8바이트로 정의됨

	printf("%zd %zd\n", size, offset);
	//구조체에서 멤버의 위치를 구할 때는 offsetof 메크로를 사용함
	//stddef.h에 선언됨. offsetof(struct 구조체, 멤버);
	//offsetof(구조체별칭, 멤버);
	
	
	
	return 0;
}


/*
	double d[9];
	for(int i =0, j = 0; i < (sizeof(d) /sizeof(d[0])); i+= 3, j++)
	{	d[i] = p[j+1].x - p[j].x; 
		d[i+1] = p[j+1].y - p[j].y;
		d[i+2] = sqrt((d[i] * d[i]) + (d[i+1] * d[i+1]));
	}

	length = d[2] + d[5] + d[8];
*/	

/*	
	for(int i =0 ; i < (sizeof(p) /sizeof(struct Point2D)) - 1; i++)
	{	length += sqrt(pow((p[i+1].x - p[i].x) , 2) +
	pow((p[i+1].y - p[i].y) , 2));	
	}
*/


/*

	for(int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
		p[i] = malloc(sizeof(struct Person));

	scanf("%s %d %s %d %s %d %s %d %s %d", p[0]->name, &(p[0]->age),
	p[1]->name, &(p[1]->age), p[2]->name, &(p[2]->age)
	p[3]->name, &(p[3]->age), p[4]->name, &(p[4]->age));
	
	struct Person *temp;

	for(int i =0; i < sizeof(p) / sizeof(struct Person *) - 1; i++)
	{
		if(p[i]->age > p[i+1]->age)
		{	temp = p[i];
			p[i] = p[i+1];
			p[i+1] = temp;
		}
	}
	printf("%s\n", p[4]->name);

	for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
	{	free(p[i]);
	}

*/




