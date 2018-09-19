#include <stdio.h>
#include <stdint.h>

uint32_t getFileSize(FILE *fp)	//파일의 크기를 구하는 함수 정의
{
	uint32_t size;
	uint32_t currPos = ftell(fp);	//현재 파일 포인터의 위치 저장

	//파일의 끝으로 이동하여 파일의 크기를 구함
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	fseek(fp, currPos, SEEK_SET);	//파일 포인터를 이전의 위치로 되돌림 

	return size;
}