#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Point2D {
	int x;
	int y;
};

int main()
{
	struct Point2D p1;

	/*구조체에 메모리 함수 사용하기
	구조체의 멤버를 모두 0으로 만드려면 선언할 때 0으로 초기화 가능
	struct 구조체 이름 변수 이름={ 0 ,};
	하지만 이것은 변수에만 사용할 수 있고 malloc함수로 할당한
	메모리에는 사용할 수가 없음
	구조체 변수나 메모리의 내용을 한꺼번에 값을 설정하려면 memset
	함수를 사용하면 됨
	memset(구조체 포인터,  설정할 값, sizeof(struct 구조체));
	*/

	memset(&p1, 0, sizeof(struct Point2D));
	//주소 연산자를 사용하여 변수의 메모리 주소를 구해서 넣어줌
	//그리고 설정할 값과 크기를 넣어줌 
	//메모리의 크기 단위는 1바이트임
	printf("%d %d\n", p1.x, p1.y);

	struct Point2D *p2 = malloc(sizeof(struct Point2D));
	memset(p2, 0, sizeof(struct Point2D));
	//memset 함수로 메모리에 값을 설정할 때는 포인터를 그대로 넣음
	//왜냐하면 포인터는 안에 메모리 주소를 담고 있어서 &를 쓸 
	//필요가 없음
	printf("%d %d\n", p2->x, p2->y);
	free(p2);

	/*구조체나 메모리의 값을 복사할 때 
	memcpy(대상 포인터, 원본 포인터, 크기); 목적지 포인터를 반환함
	memory copy에서 따옴, string.h 헤더 파일
	*/

	struct Point2D p3;
	struct Point2D p4;

	p3.x = 10;
	p3.y = 20;

	memcpy(&p4, &p3, sizeof(struct Point2D));
	//구조체 변수 앞에 &를 사용하여 변수의 메모리 주소를 구해서
	//넣어줌, 마지막에는 복사할 크기를 넣어주는데 여기서는 구조체
	//크기를 구해서 넣어주면 됨

	printf("%d %d\n", p4.x, p4.y);

	struct Point2D *p5 = malloc(sizeof(struct Point2D));
	struct Point2D *p6 = malloc(sizeof(struct Point2D));

	p5->x = 30;
	p5->y = 40;

	memcpy(p6, p5, sizeof(struct Point2D));

	printf("%d %d\n", p6->x, p6->y);

	free(p6);
	free(p5);


	return 0;
}

