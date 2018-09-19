#include <stdio.h>
#include <stddef.h>

struct PacketHeader {
	char flags;
	int seq;
};
#pragma pack(push, 1)
struct PacketHeader1 {
	char flags;
	int seq;
};
#pragma pack(pop)
int main()
{
	/*
	구조체는 메모리에 올라갔을 때 멤버를 정렬함
	컴퓨터의 CPU는 메모리에 접근할 때 32비트는 4바이트 단위 
	64비트는 8바이트 단위로 접근함
	32비트 CPU에서 4바이트보다 작은데이터에 접근할 경우 
	내부적으로 쉬프트 연산이 발생해서 효율이 떨어짐(똑같이 4바이트
	를 읽어들임) , 그래서 C 언어 컴파일러는 CPU가 메모리의 데이터에
	효율적으로 접근할 있도록 구조체를 일정한 크기로 정렬을 하게 됨
	예를 들어 구조체 크기가 15 나 17바이트가 되면 접근 효율이 
	떨어지게 되므로 2, 4, 8, 16바이트 단위로 정렬을 함, 하지만 
	사진은 정렬되면 깨지게 되고 네트워크 데이터도 전송할 때
	몇 바이트씩 어떤 순서로 보낼지 규약을 정해놓았음
	따라서 정렬이 되면 받는 쪽에서 데이터를 알아볼 수 없게됨
	sizeof(struct 구조체)
	sizeof(구조체 별칭)
	sizeof(구조체 변수)
	*/
										
	struct PacketHeader header;

	printf("%llu\n", sizeof(header.flags));
	printf("%llu\n", sizeof(header.seq));
	printf("%llu\n", sizeof(header));
	printf("%llu\n", sizeof(struct PacketHeader));
	
	//C 언어에서는 가장 큰 자료형 크기의 배수로 정렬을 함
	//여기선 int가 가장 큰 자료형이므로 int의 크기 4바이트를 
	//기준으로 정렬함, 4바이트로 정렬해서 flags와 seq가 모두 
	//들어가는 최소크기는 8바이트임, 1바이트 크기의 char flags 뒤에
	//4바이트를 맞추기 위해 뒤에 3바이트가 더 들어가게됨. 
	//남는 공간을 채우는 것을 패딩이라고 함, 구조체에서 멤버의
	//위치를 구할 때는 offsetof 메크로를 사용함, stddef.h에 선언됨 

	//offsetof(struct 구조체, 멤버);
	//offsetof(구조체별칭, 멤버);

	printf("%llu\n", offsetof(struct PacketHeader, flags));
	printf("%llu\n", offsetof(struct PacketHeader, seq));

	/*
	구조체 정렬을 하지 않는 방법은? 
	c언어에서는 구조체를 정렬하는 표준 방법은 없음 -> 각 컴파일러
	에서 제공하는 특별한 지시자를 사용하면 구조체 정렬 크기를
	조절할 수 있음
	visual studio , gcc 4.0 이상은 #pragma pack(push, 정렬크기)
	#pragma pack(pop) , GCC 4.0 미만은 __attribute__((aligned(정렬
	크기), packed))
	pragma는 그리스어로 action이라는 의미 컴파일러의 행동 지정 	
	*/

	struct PacketHeader1 header1;

	printf("%llu\n", sizeof(header1.flags));
	printf("%llu\n", sizeof(header1.seq));
	printf("%llu\n", sizeof(header1));

	//pack을 1바이트 단위로 정렬하게 되면 남는 공간없이 자료형
	//크기 그대로 메모리에 올라가게 됨
	//#pragma pack(push, 1)을 한 번 사용하면 그 아래에 오는
	//모든 구조체에 영향을 주므로 정렬 설정을 한 뒤에 
	//#pragma pack(pop)을 사용하여 이전 상태로 되돌림 

	printf("%llu\n", offsetof(struct PacketHeader1, flags));
	printf("%llu\n", offsetof(struct PacketHeader1, seq));

	//2바이트 단위로 정렬하면 총 6바이트가 됨
	//4바이트 단위로 정렬하면 총 8바이트가 됨

	return 0;
}