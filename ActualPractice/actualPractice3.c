#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "archive.h"
#include "command.h"

int main(int argc, char *argv[])
{

	/*
	파일 아카이브 구현하기
	아카이브 파일에 새 파일 추가(append)
	아카이브 파일에 들어있는 파일의 목록 출력(list)
	아카이브 파일에 들어있는 파일을 추출하여 새 파일로 저장(extract)
	파일 안에 파일을 여러 개를 저장하려면 파일 내용을 연달아 저장하면 되지만 그렇게 되면 어느 위치에 어떤 파일이
	저장되어 있는지 알기가 어려움. 따라서 아카이브 파일 안에는 필요한 정보도 함께 넣어주어야 함
	필수적인 정보는 파일 이름, 파일 크기, 파일 데이터 위치임. 아카이브 파일이 맞는지 확인하기 위한
	매직 넘버와 파일 버전도 필요함
	아카이브 파일 구조
	아카이브 헤더		 파일1												 파일2
	매직 넘버 파일 버전	 파일 이름 파일 크기  파일 데이터 위치 파일 데이터   파일 이름 파일 크기  파일 데이터 위치 파일 데이터

	바이너리 형식은 파일 구조가 조금이라도 바뀌면 사용이 힘들어짐. 1바이트라도 어긋나면 완전히 다른 정보를 읽게 되기 때문임
	그래서 보통 바이너리 형식으로 된 파일은 파일(포맷) 버전을 함께 저장하고 파일 버전이 맞을 때만 처리하도록 구현함
	아카이브 파일 구조체 작성하기
	아카이브 헤더 작성(아카이브 파일의 매직넘버와 파일 버전이 들어감. 여기서는 각 멤버의 크기를 정확하게 표현가능한
	stdint.h 헤더파일의 자료형을 사용함)
	파일 정보 구조체 작성하기
	파일 이름 문자열과 파일 크기, 파일 데이터의 위치가 들어감. 파일 데이터의 위치는 아카이브 파일 안에서 해당 파일의 데이터가
	있는 곳의 시작 위치를 저장하게 됨
	아카이브 헤더 구조체 및 파일 정보 구조체는 자료형 크기 그대로 저장되어야 하므로 #pragma pack(push,1), #pragma pack(pop)을
	사용하여 1바이트 크기로 정렬해줌
	현재 설계한 아카이브 파일 구조의 한계
	1. 파일 이름은 255자 이상 저장이 안 됨
	2. 파일 크기와 파일 데이터의 위치를 저장하는 자료형이 uint32이므로 크기가 4GB이상인 파일은 저장할 수 없음
	3. 아카이브 파일의 최대 크기는 운영체제의 파일 시스템이 저장할 수 있는 파일 하나의 크기를 따름
	아카이브 파일을 생성하고 첫 파일을 추가하는 과정
	아카이브 파일 열기 -> 아카이브 헤더 생성 -> 아카이브 헤더 저장 -> hello.txt 파일 추가, append() -> 추가할 파일 열기 
	-> 추가할 파일의 크기 구하기 -> 새 파일 정보 생성 -> 아카이브 헤더 다음에 새 파일 정보 쓰기 -> 새 파일 데이터 쓰기 
	-> 아카이브 파일 닫기, getFileSize: 파일의 크기를 구하는 함수, append: 아카이브 파일에 파일을 추가하는 함수
	
	main 함수에서 아카이브 파일에 아카이브 헤더를 저장하면 아래와 같은 모양이 됨
					아카이브 헤더	hello.txt
	archive.bin		magic version	name size	dataOffset	파일 데이터 		
	*/

	/* 아카이브 파일에서 파일 목록 출력하기 -> 연결리스트로 구현 
	아카이브 파일에서 파일 목록을 출력하는 과정
	아카이브 파일 열기 -> 아카이브 헤더 읽기 -> 매직 넘버 검사 -> 파일 버전 검사 -> 파일 정보를 읽어서 연결 리스트에 추가
	-> 파일 목록 출력, list() <연결 리스트를 순회하면서 파일 이름 출력> -> 연결 리스트 메모리 해제 -> 아카이브 파일 닫기  
	파일 노드 구조체가 필요함(파일 목록을 연결리스트에 저장해서 파일 목록을 관리하기 위한 구조체임, 프로그램에서만 사용함)  
	파일 3개를 연결 리스트로 관리했을 때 구조
				파일 A		파일 B		파일 C
FILE_NODE		next	->	next	->	next	->	NULL
FILE_DESC		name		name		name	
				size		size		size
				dataOffset	dataOffset	dataOffset
	ARCHIVE 구조체에는 파일 목록 연결 리스트의 머리 노드를 멤버로 추가해줌 
	*/

	/*	아카이브 파일에 들어있는 특정 파일 추출하기 
	아카이브 파일 열기 -> 아카이브 헤더 읽기 -> 매직 넘버 검사 -> 파일 버전 검사 -> 파일 정보를 읽어서 연결 리스트에 추가
	-> hello.txt 파일 추출, extract() < 파일 목록 연결 리스트 순회 -> 아카이브 파일에서 추출할 파일의 데이터 읽기 -> 추출한
	파일을 저장할 새 파일 생성 -> 새 파일에 데이터 쓰기 -> 파일 닫기> -> 연결 리스트 메모리 해제 -> 아카이브 파일 닫기 
	
	지금은 actualPractice3.c 안에 모든 기능이 다 들어가 있는데 소스코드가 간단할 때는 괜찮지만 소스코드가 길어지면 
	기능 추가도 힘들어지고 유지보수도 쉽지 않게 됨
	함수별로 파일 분류하기
	archive.h	initialize	아카이브 파일을 열어서 매직 넘버와 파일 버전을 검사하고 파일 목록을 만듬
	archive.c	finalize	프로그램 종료전에 각종 구조체 메모리를 해제하고 아카이브 파일을 닫음
				isExtract	아카이브에 특정 파일이 있는지 검사함 
	command.h	append		아카이브에 파일을 추가함
	command.h	list		아카이브의 파일 목록을 출력함		
				extract		아카이브에서 파일을 추출함
	file.h		getFileSize	파일의 크기를 구함
	file.c	
	actualPractice3.c		main함수
	*/

	/*C언어에서 제공하는 실행 파일 옵션 기능을 활용하여 append, list, extract 명령을 처리하기 
			initialize() -> 초기화 
		↓		↓		   ↓
	append()	list()	extract()	-> 명령 실행 
				↓
			finalize() -> 해제 
	
	*/
	//실행 파일에 지정된 옵션이 없을 때 프로그램 사용 방법 출력
	if (argc == 1)
	{
		printf("filearchive <명령> <파일명>\n\n");
		printf("명령:\n");
		printf("	append	파일 추가\n");
		printf("	list	파일 목록 출력\n");
		printf("	extract	파일 추출\n");
		return 0;
	}
	//initialize 함수를 호출하여 아카이브 파일을 열고 파일 정보와 파일 목록을 얻음 
	PARCHIVE archive = initialize();
	
	if (archive == NULL)
		return -1;
	//filearchive.exe <명령> <파일명> 형식이 될 것이므로 argv[1]은 명령, argv[2]는 파일명이 됨
	char *command = argv[1];
	char *filename = argv[2];

	//command의 내용을 판별하여 append이면 파일 추가, list이면 파일 목록 출력
	//extract이면 파일 추출을 함, 여기서 파일을 추가할 때 같은 이름으로 된 파일이 중복하지 않도록
	//isExist 함수로 검사해주고 파일을 추출할 때는 아카이브 파일에 추출할 파일이 있는지 isExist 함수로 검사해줌 

	if (strcmp(command, "append") == 0)	//파일 추가 명령
	{
		if (!isExist(archive, filename))	//아카이브 파일에 추가할 파일이 있는지 검사
		{	
			//파일이 중복되지 않으면 새 파일 추가 
			if (append(archive, filename) == -1)
			{
				printf("%s 파일 추가 실패\n", filename);
			}
		}
		else
		{
			printf("이미 %s 파일이 추가되어 있습니다.\n", filename);
		}
	}
	else if (strcmp(command, "list") == 0)
	{
		list(archive);
	}
	else if (strcmp(command, "extract") == 0)
	{
		if (isExist(archive, filename))
		{
			if (extract(archive, filename) == -1)
			{
				printf("%s 파일 추출 실패\n", filename);
			}
		}
		else
		{
			printf("%s 파일이 없습니다.\n", filename);
		}
	}
	//모든 작업이 끝났으면 finalize함수를 호출하여 파일 포인터를 닫고 모든 동적 메모리를 해제함 
	finalize(archive);	
	
	 //파일들의 포함관계
	//actualPractice3.c (command.h, archive.h 포함)
	//command.c (archive.h, file.h 포함)
	//archive.c (archive.h, file.h 포함)
	//command.h (archive.h 포함)

	/*
	#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)

typedef struct _ARCHIVE_HEADER {
    uint16_t magic;
    uint16_t version;
} ARCHIVE_HEADER, *PARCHIVE_HEADER;

typedef struct _FILE_DESC {
    char     name[256];
    uint32_t size;
    uint32_t dataOffset;
} FILE_DESC, *PFILE_DESC;

#pragma pack(pop)

typedef struct _FILE_NODE
{
    FILE_NODE *next;   
    FILE_DESC desc;
} FILE_NODE, *PFILE_NODE;

typedef struct _ARCHIVE
{   ARCHIVE_HEADER header;
    FILE *fp;
    FILE_NODE node;      
} ARCHIVE, *PARCHIVE;

void list(PARCHIVE archive)
{
        
    
    
}

int getFileSize(FILE *fp)
{
    int size;
    int currPos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    size=ftell(fp);
    fseek(fp, currPos, SEEK_SET);
    return size;
}

int main()
{
    PARCHIVE archive = malloc(sizeof(ARCHIVE));
    memset(archive, 0, sizeof(ARCHIVE));
    
    FILE *fp = fopen("archive.bin", "rb");
    
    if(fread(&archive->header, sizeof(ARCHIVE_HEADER), 1, fp) < 1)
        return -1;
    
    if(archive->header.magic != 'XR')
        return -1;
    
    if(archive->header.version != 2)
        return -1;
    
    archive->fp = fp;
    
    int size = getFilseSize(fp);
    int currPos = ftell(fp);
    
    while(size > currPos)
    {
        PFILE_NODE node = malloc(sizeof(FILE_NODE));
        memset(node, 0, sizeof(FILE_NODE));
        
        if(fread(&node->desc, sizeof(FILE_DESC), 1, fp) < 1)
            return -1;
        
        printf("%s\n", node->desc.name);
        node->next = archive->filelist.next;
		archive->filelist.next = node;
        
        currPos = ftell(fp) + node->desc.size;
        fseek(fp, currPos, SEEK_SET);
    }
    
    
    
    
    
    
    
    return 0;
}
	
	
	*/

	return 0;
}