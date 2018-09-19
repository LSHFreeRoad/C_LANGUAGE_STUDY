//여러 곳에서 포함하는  헤더 파일이으므로 #ifndef ARCHIVE_H, #define ARCHIVE_H , #endif를 사용하여 중복포함을 방지함
//이렇게 조건부 컴파일을 만들지 않으면 중복 포함이 발생하고, 컴파일 에러가 발생함
//각종 구조체와 initialize, finalize, isExtract 함수를 선언해줌
#ifndef	ARCHIVE_H
#define ARCHIVE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#pragma pack(push,1)
//아카이브 헤더(아카이브 파일에 저장되는 구조체)
typedef struct _ARCHIVE_HEADER
{
	uint16_t magic;	//아카이브 파일 매직 넘버
	uint16_t version;	//아카이브 파일 버전
} ARCHIVE_HEADER, *PARCHIVE_HEADER;

//아카이브 파일 정보(아카이브 파일에 저장되는 구조체)
typedef struct _FILE_DESC
{
	char name[256];	//파일 이름
	uint32_t size;	//파일 크기
	uint32_t dataOffset;	//파일 데이터 위치 
} FILE_DESC, *PFILE_DESC;
#pragma pack(pop)

typedef struct _FILE_NODE
{	//파일 목록 연결 리스트의 구조체 정의
	struct _FILE_NODE *next;	//다음 노드의 주소를 저장할 포인터
	FILE_DESC desc;	//파일 정보 
} FILE_NODE, *PFILE_NODE;


//프로그램에서만 사용하는 구조체(각종 함수를 실행할 때마다 ARCHIVE 구조체에서 필요한 정보를  꺼내 쓰게됨)
//만약 파일 저장용 구조체와 프로그램용 구조체를 분리하지 않고 뭉쳐서 구현하게 되면 구조체를 파일에 저장했을 때 필요없는
//데이터까지 함께 파일에 저장됨 
typedef struct _ARCHIVE	//아카이브 메인 구조체 
{
	ARCHIVE_HEADER header;	//아카이브 헤더
	FILE *fp;	//아카이브 파일 포인터 
	FILE_NODE filelist;	//파일 목록 연결 리스트의 머리 노드 
} ARCHIVE, *PARCHIVE;

PARCHIVE initialize();	//초기화 함수 선언
void finalize(PARCHIVE archive);	//종료 함수 선언
bool isExist(PARCHIVE archive, char *filename);	//아카이브에 특정 파일이 있는지 검사하는 함수 선언

#endif	//#ifndef ARCHIVE_H 끝
