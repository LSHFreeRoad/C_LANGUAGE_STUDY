#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "archive.h"
#include "file.h"

int append(PARCHIVE archive, char *filename)	//파일 추가 함수 정의
{
	int ret = 0;	//함수의 성공 및 실패 여부를 반환값으로 표현 
					//모든 과정에 성공하면 0을 반환함 
					//각 과정에서 실패할 때마다 goto를 사용해서 에러 처리 부분으로 이동하고 -1을 반환하도록 하기 
					//goto를 사용하지 않으면 실패할 때마다 매번 fclose나 free함수를 계속 사용해야 되서 코드가 길어짐 
	FILE *fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("%s 파일이 없습니다.\n", filename);
		return -1;	//함수 종료, -1은 실패 
	}

	uint8_t *buffer;
	uint32_t size;

	size = getFileSize(fp);	//추가하는 파일의 크기를 구함 
	buffer = malloc(size);

	if (fread(buffer, size, 1, fp) < 1)		//추가할 파일의 내용을 읽어서 buffer가 가리키는 메모리 공간에 저장함  
	{
		printf("%s 파일 읽기 실패\n", filename);
		ret = -1;
		goto Error1;
	}

	//새 파일 정보 생성하기 
	PFILE_DESC desc = malloc(sizeof(FILE_DESC));
	memset(desc, 0, sizeof(FILE_DESC));	//쓸데없는 값이 들어가지 않도록 메모리 공간을 0으로 초기화 
	strcpy(desc->name, filename);	//파일 정보 구조체에 추가할 파일의 이름 저장
	desc->size = size;	//파일 정보 구조체에 추가할 파일의 크기 저장 

	PFILE_NODE node = archive->filelist.next;	//첫 번째 노드
	if (node == NULL) //아카이브 파일에 파일이 하나도 없으면 
	{	fseek(archive->fp, sizeof(ARCHIVE_HEADER), SEEK_SET);	//아카이브 헤더 바로 다음으로 파일 포인터를 이동시킴 
	desc->dataOffset = ftell(archive->fp) + sizeof(FILE_DESC);
	//새로 추가될 파일 데이터의 시작위치는 
	//현재 파일 포인터의 위치에 파일 정보 크기만큼 순방향으로 이동시킨 값 
	}
	else //연결 리스트에서 첫 번째 노드가 가장 마지막에 추가된 파일 
	{	//마지막에 추가된 파일의 파일 데이터 위치에서 파일 크기만큼 순방향으로 이동
		fseek(archive->fp, node->desc.dataOffset + node->desc.size, SEEK_SET);
			
		//새로 추가될 파일 데이터의 시작 위치는 
		//마지막에 추가된 파일의 파일 데이터 위치에서 
		//파일 크기, 파일 정보 크기만큼 순방향으로 이동시킨 값 
		desc->dataOffset = node->desc.dataOffset + node->desc.size + sizeof(FILE_DESC);
	}

	//아카이브 파일에 새 파일 정보 쓰기
	if (fwrite(desc, sizeof(FILE_DESC), 1, archive->fp) < 1)
	{
		printf("파일 데이터 쓰기 실패\n");
		ret = -1;
		goto Error2;	//fp를 닫고, desc와 buffer를 해제하는 에러처리로 이동
	}
	//fwrite함수로 파일에 쓰면 쓴 크기만큼 파일 포인터가 순방향으로 이동하기 때문에 따로 fseek 함수를 안 사용해도 됨 
	
	//아카이브 파일에 새 파일 데이터 쓰기 
	if (fwrite(buffer, size, 1, archive->fp) < 1)
	{
		printf("파일 데이터 쓰기 실패\n");
		ret = -1;
		goto Error2;	//fp를 닫고, desc와 buffer를 해제하는 에러처리로 이동
	}

	printf("%s 파일 추가 성공\n크기: %d\n", filename, size);

	//Error2로 가면 밑에 Error1도 실행이 됨 
Error2:
	free(desc);	//파일 저장용 동적 메모리 해제 

Error1:
	free(buffer);	//파일 내용 저장용 동적 메모리 해제 
	fclose(fp);	//파일 포인터 닫기


	return ret;	//성공이냐 실패에 따라 0 또는 -1을 반환함 
}

void list(PARCHIVE archive)
{
	printf("파일 목록:\n");

	//파일 목록 연결리스트를 순회하면서 파일 이름 출력 
	PFILE_NODE curr = archive->filelist.next;	//첫 번째 노드
	while (curr != NULL)
	{
		printf("	%s\n", curr->desc.name);
		curr = curr->next;
	}


}

int extract(PARCHIVE archive, char *filename)	//파일 추출 함수 정의
{

	//파일 목록 연결리스트를 순회함 
	PFILE_NODE curr = archive->filelist.next;	//첫 번째 노드

	while (curr != NULL)
	{	//추출할 파일이 있는지 검사함 
		if (strcmp(curr->desc.name, filename) == 0)	//아카이브 파일 안에 추출할 파일이 있다면 
		{
			int ret = 0;
			uint32_t size = curr->desc.size;
			uint8_t *buffer = malloc(size);	//파일 크기만큼 버퍼를 할당함 

			//아카이브 파일에서 파일 포인터를 desc.dataOffset만큼 파일 데이터 위치로 이동시킴 
			fseek(archive->fp, curr->desc.dataOffset, SEEK_SET);

			//fread함수로 추출할 파일 크기 만큼 읽기 
			if (fread(buffer, size, 1, archive->fp) < 1)
			{
				printf("아카이브 파일 읽기 실패\n");
				ret = -1;	//-1은 실패
				goto Error1;	//buffer를 해제하는 에러 처리로 이동함 
			}

			//추출할 파일을 저장할 새 파일을 새성함 
			FILE *fp = fopen(filename, "wb");
			if (fp == NULL)
			{
				printf("%s 파일 열기 실패\n", filename);
				ret = -1;
				goto Error1;	//buffer를 해제하는 에러 처리로 이동함 
			}

			//새로 생성된 파일에 파일 데이터 쓰기 
			if (fwrite(buffer, size, 1, fp) < 1)
			{
				printf("%s 파일 쓰기 실패\n", filename);
				ret = -1;
				goto Error2;
			}

			printf("%s 파일 추출 성공\n크기: %d\n", filename, size);

		Error2:
			fclose(fp);	//파일 포인터 닫기

		Error1:
			free(buffer);	//동적 메모리 해제
			return ret;		//성공 또는 실패에 따라 0 또는 -1을 반환함 

		}

		curr = curr->next;
	}


	return -1;

}
