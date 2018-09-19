#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "archive.h"
#include "file.h"

/* main 함수에 들어있던 코드를 initialize, finalize 함수로 분리하고 isExtract 함수를 구현함 
isExtract 함수는 파일 목록 연결 리스트의 첫 번째 노드부터 순회하면서 파일이 있으면 true를 반환하고 없으면 false를 반환함 
*/
#define ARCHIVE_NAME "archive.bin"

PARCHIVE initialize()	//초기화 함수 정의 
{
	PARCHIVE archive = malloc(sizeof(ARCHIVE));
	memset(archive, 0, sizeof(ARCHIVE));

	FILE *fp = fopen(ARCHIVE_NAME, "r+b");	//아카이브 파일을 읽기/쓰기 모드로 열음
	if (fp == NULL)	//아카이브 파일이 없으면 
	{

		fp = fopen(ARCHIVE_NAME, "w+b");	//새로운 아카이브 파일을 생성함 

		if (fp == NULL)	//파일 생성에 실패하면 프로그램 종료
			return NULL;

		//새 아카이브 헤더 생성 
		archive->header.magic = 'AF';	//매직넘버 'AF'저장(리틀 엔디언에서는 'FA'로 저장됨)
		archive->header.version = 1;	//파일 버전 1로 저장함 

		//아카이브 파일에 아카이브 헤더 저장 
		if (fwrite((&archive->header), sizeof(ARCHIVE_HEADER), 1, fp) < 1)
		{
			printf("아카이브 헤더 쓰기 실패\n");
			fclose(fp);
			return NULL;
		}
	}
	else	//아카이브 파일이 있으면 
	{
		//아카이브 파일에서 아카이브 헤더 읽기
		if (fread(&archive->header, sizeof(ARCHIVE_HEADER), 1, fp) < 1)
		{
			printf("아카이브 헤더 읽기 실패\n");
			fclose(fp);
			return NULL;
		}
	}

	//아카이브 파일 매직넘버 검사
	if (archive->header.magic != 'AF')
	{
		printf("아카이브 파일이 아닙니다.\n");
		fclose(fp);
		return NULL;
	}
	//아카이브 파일 버전 검사 
	if (archive->header.version != 1)
	{
		printf("버전이 맞지 않습니다.\n");
		fclose(fp);
		return NULL;
	}//만약 아카이브 파일 구조가 버전이 여러 개 있을 때는 버전별로 구조체를 만들어놓고 버전에 따라 해당 구조체를 
	 //사용하면 됨. switch 분기문이나 if, else로 버전에 따라 구조체를 선택해서 사용하면 됨 

	archive->fp = fp;	//아카이브 파일 포인터 저장

	uint32_t size = getFileSize(fp);	//아카이브 파일의 크기를 구함
	uint32_t currPos = ftell(fp);		//현재 파일 포인터의 위치를 구함 

	while (size > currPos)	//파일 포인터의 위치가 파일 크기보다 작을 때 반복
	{	//즉 아카이브 헤더 다음부터 파일 끝까지 계속 읽으면서 파일 정보를 가져옴 
		PFILE_NODE node = malloc(sizeof(FILE_NODE));
		memset(node, 0, sizeof(FILE_NODE));

		//파일 정보 읽기
		if (fread(&node->desc, sizeof(FILE_DESC), 1, fp) < 1)
		{
			printf("아카이브 파일 읽기 실패\n");
			free(node);
			finalize(archive);
			return NULL;
		}

		//연결리스트에 파일 정보 노드 추가 
		node->next = archive->filelist.next;
		archive->filelist.next = node;

		//현재 파일 포인터의 위치에 파일 데이터 크기만큼 더해서 다음 파일 정보 위치로 이동함 
		currPos = ftell(fp) + node->desc.size;
		fseek(fp, currPos, SEEK_SET);

	}

	return archive;
}

void finalize(PARCHIVE archive)	//종료 함수 정의
{	
	//파일 목록 연결리스트를 순회하면서 메모리 해제 
	PFILE_NODE curr = archive->filelist.next;	//첫 번째 노드
	while (curr != NULL)
	{
		PFILE_NODE next = curr->next;
		free(curr);
		curr = next;
	}

	fclose(archive->fp);	//아카이브 파일 포인터 닫기
	free(archive);	//아카이브 메인 구조체 해제 
}

bool isExist(PARCHIVE archive, char *filename)
{	
	//파일 목록 연결리스트를 순회하면서 파일이 있는지 검사함 
	PFILE_NODE curr = archive->filelist.next;	//첫 번째 노드 

	while (curr != NULL)
	{	//파일이 있으면 true 반환 
		if (strcmp(curr->desc.name, filename) == 0)
			return true;
		curr = curr->next;
	}
	return false;	//파일을 찾지 못했으면 false 반환 
}
