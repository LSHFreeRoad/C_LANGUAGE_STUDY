#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //fopen, fwrite, fclose 함수가 선언된 헤더파일
#include <string.h> //memset, strcpy함수가 선언된 헤더파일

#pragma pack(push, 1) //1바이트 크기로 정렬함 
struct Data {
	short num1, num2, num3, num4;
};
#pragma pack(pop) //정렬 설정을 이전 상태(기본값)로 되돌림 

#pragma pack(push, 1) //1바이트 크기로 정렬함 
struct Data2 {
	char c1; 
	short num1;
	int num2;
	//int를 기준으로 구조체 정렬을 하게되면 char c1;은 실제 크기
	//보다 큰 공간을 차지하게 되므로 반드시 1바이트 크기로
	//정렬을 해줌 
	char s1[20];
};
#pragma pack(pop) //정렬 설정을 이전 상태(기본값)로 되돌림 


int main()
{

	/*
	컴퓨터에서 파일은 두 가지로 나눌 수 있음 
	메모장이나 텍스트 편집기로 열 수 있는 텍스트 파일 
	특정 프로그램에서만 열 수 있는 바이너리 파일(2진 파일)
	우리가 자주 쓰는 워드, 파워포인트, 엑셀, pdf, 그림파일은
	바이너리 형식으로 되어있음 
	바이너리 형식을 많이 사용하는 이유 알아보기 
	100(0x64), 200(0xC8), 300(0x12C), 400(0x190)을 
	바이너리 형식과 텍스트 형식으로 저장한다면 바이너리 파일은  
	
	64 00 C8 00 2C 01 90 01 -> 총 8바이트: 숫자를 2바이트 단위로
	저장함 

	텍스트 파일은

	1 0 0 2 0 0 3 0 0 4 0 0 ->12바이트: 숫자를 문자열(ASCII) 
	형태로 저장함, 바이너리 형식은 같은 정보를 저장하더라도
	텍스트 형식보다 차지하는 공간도 적고 처리 속도도 빠름 
	파일에 구조체 쓰기 
	파일에 구조체를 쓰려면 fwrite함수를 이용하면 됨 
	fwrite(버퍼,쓰기크기,쓰기횟수,파일 포인터);
	성공하면 쓰기 횟수를 반환하고 실패하면 지정된 쓰기 횟수보다
	적은 값을 반환함 
	*/

	struct Data d1;
	
	d1.num1 = 100;
	d1.num2 = 200;
	d1.num3 = 300;
	d1.num4 = 400;

	FILE *fp = fopen("data.bin", "wb");
	//파일을 쓰기/바이너리 모드로 열음 

	fwrite(&d1, sizeof(d1), 1, fp);
	//fwrite함수를 사용해서 구조체 변수 d1을 파일에 저장함 

	fclose(fp);

	//x86플랫폼에서는 정수가 리틀 엔디어으로 저장되므로 0x64는
	//64 00이 됨 

	struct Data2 d2;
	memset(&d2, 0, sizeof(d2));
	//구조체 변수의 내용을 모두 0으로 초기화해줌 
	//0으로 초기화해주지 않으면 배열 s1부분에는 이전에 
	//메모리에서 쓰던 값이 들어갈 수도 있음 

	d2.c1 = 'a'; //0x61
	d2.num1 = 32100; //0x7D64
	d2.num2 = 2100000100; //0x702B7564
	strcpy(d2.s1, "Hello, world!"); 
	//문자열은 리틀 엔디언하고 상관없이 문자 순서 그대로 저장됨

	FILE *fp2 = fopen("data2.bin", "wb");

	fwrite(&d2, sizeof(d2), 1, fp2);

	fclose(fp2);

	//파일에서 구조체를 읽으려면 fread함수를 사용함 
	//성공하면 읽기 횟수를 반환하고 실패하면 지정된 읽기 
	//횟수보다 작은 값을 반환함 


	FILE *fp3 = fopen("data2.bin", "rb");

	fread(&d2, sizeof(d2), 1, fp3);

	printf("%c %d %d %s\n", d2.c1, d2.num1, d2.num2, d2.s1);
	//바이너리 파일을 읽어서 구조체에 저장할 때는 구조체 멤버의
	//크기뿐만 아니라 순서도 중요함. 구조체 순서가 달라지면 
	//값의 일부만 가져오거나 여러 개의 값을 묶어서 가져올 수가
	//있음, 파일에는 리틀 엔디언 방식으로 저장되어 있다 하더라도
	//printf 함수로 값을 출력해보면 사람이 읽을 수 있는 형태로
	//나오기 때문에 엔디언 문제는 걱정하지 않아도 됨 
	//파일에서 구조체를 읽고 쓸 때는 반드시 구조체를 1바이트
	//크기로 정렬해야 됨 
	fclose(fp3);

	/*
	#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#pragma pack(push, 1)
struct X850Firmware {
    short serial;
    char mode;
    char desc[20];
    int version;
};
#pragma pack(pop)
int main()
{
     struct X850Firmware x850;
    
    FILE *fp = fopen("x850.bin", "rb");
    fread(&x850, sizeof(x850), 1, fp);
    printf("%d\n%c\n%s\n%d\n",x850.serial, x850.mode, x850.desc,
	x850.version);
    fclose(fp);
    
    return 0;
}
	*/

	/*fopen함수로 파일을 열때 파일모드를 텍스트나 바이너리
	모드로 지정해주지 않으면 텍스트 모드로 열음(기본값) 
	예를 들어 파일의 크기가 15바이트일 때 fread 함수에
	읽기 크기는 10, 읽기 횟수는 2로 지정하여 파일을 읽으면
	반환값은 1이 나옴 하지만 buffer에는 15바이트만큼 파일을
	읽은 값이 잘 들어가 있음 
	바이트 크기의 파일을 10바이트만큼 2번 읽어서 버퍼에
	저장하면 첫 번째 읽기는 10바이트만큼 읽고 두 번째 읽기는
	5바이트만큼 읽게됩니다. 첫 번째 읽기는 지정된 읽기 크기
	10과 같으므로 성공(1), 두 번째 읽기는 지정된 읽기 크기
	10보다 작으므로 실패(0)로 판정하여 최종적으로 1을
	반환하게 됨(1 + 0 = 1).
	*/

	return 0;
}