#include<stdio.h>
//#include<memory.h>
#include<string.h>
#include<stdlib.h>	//free함수가 선언된 헤더파일
int main()
{
	/*
	포인터에는 malloc함수로 원하는 만큼 메모리를 할당할
	수 있음, malloc -> 사용 -> free
	메모리를 사용하려면 malloc 함수로 메모리 공간을 확보
	해야됨, 이 때 필요한 메모리 크기는 바이트 단위로 지정
	메모리 할당, 해제 함수는 stdlib.h 헤더파일에 선언되
	있음, 포인터 = malloc(크기); ,
	void malloc(size_t_Size);
	성공하면 메모리 주소 반환, 실패하면 NULL 반환
	*/

	int num1 = 20;
	int *numPtr1;

	numPtr1 = &num1;

	int *numPtr2;

	numPtr2 = malloc(sizeof(int));
	/*메모리를 할당할때는 malloc함수를 사용해서 할당할
	메모리 공간의 크기를 넣어줌, int의 크기만큼 메모리
	할당, 원하는 시점에 원하는 만큼 메모리를 할당할 수
	있다고 해서 동적 메모리 할당(dynamic memory 
	allocation)이라고 부름
	같은 메모리 주소라도 내부적으로 약간의 차이가 있음
	스택(stack)과 힙(heap) 두 가지인데 변수는
	stack을 malloc함수는 heap 부분의 메모리를 사용함
	스택과 힙의 큰 차이점은 메모리 해제이다, 스택에
	생성된 변수는 사용한 뒤 따로 처리를 해주지 않아도
	되지만 malloc 함수를 사용하여 heap에서 할당한
	메모리는 반드시 해제를 해야됨(free 함수 이용)
	free(포인터) -> free(void *_Block)
	메모리 해제는 선택사항이 아니라 필수임-> 해제를
	안하면 시스템에 메모리가 부족해져서 운영체제가 
	프로그램을 강제로 종료시키거나 메모리 할당에 
	실패하게 됨, 할당받은 메모리 공간을 해제하지 않아서
	메모리 사용량이 계속 증가하는 현상을
	메모리 누수(memory leak)라고 부름
	*/
	
	printf("%p\n", numPtr1);
	printf("%p\n", numPtr2);

	free(numPtr2);

	int *numPtr3;

	numPtr3 = malloc(sizeof(int));
	*numPtr3 = 10;	//할당받은 메모리에 값을 저장할 때는 
	//포인터를 역참조한 뒤 값을 저장하면 됨

	printf("%d\n", *numPtr3);

	free(numPtr3);

	//memset 함수를 사용하면 메모리의 내용을 원하는
	//크기만큼 특정 값으로 설정할 수 있으며 memset은
	//memory set에서 따옴->string.h 또는 memory.h 
	//헤더파일에 선언되 있음, 설정하는 크기는 바이트 단위
	//memset(포인터, 설정할 값, 크기)

	long long *numPtr4 = malloc(sizeof(long long));

	memset(numPtr4, 0x27, 8);
	//numPtr4가 가리키는 메모리 공간을 8바이트만큼 0x27로
	//설정함
	printf("0x%llx\n", *numPtr4);
	//0x2727272727272727 -> 16진수 27이 8개 들어있음 
	free(numPtr4);


	//메모리가 할당되지 않은 포인터

	int *numPtr5 = NULL;	//NULL이 들어있는 포인터를
	//널(NULL) 포인터라고 함 

	printf("%p\n", numPtr5);



	return 0;
}