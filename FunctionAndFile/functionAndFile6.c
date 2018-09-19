#define _CRT_SECURE_NO_WARNINGS
//fopen 함수의 보안경고 방지 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	/*
	파일의 크기가 작다면 파일을 처음부터 읽어도 상관없지만 
	크기가 크다면 처음부터 읽는 것은 비효율적임 
	파일 포인터를 이동시켜서 파일의 크기를 구하기 
	파일을 부분적으로 읽고 쓰기 
	fseek(파일 포인터, 이동할 크기, 기준점);
	성공하면 0을 반환하고 실패하면 -1을 반환함 
	ftell(파일포인터);
	파일 포인터의 현재 위치를 반환함, 실패하면 -1을 반환함 	
	*/

	int size;

	FILE *fp = fopen("hello.txt", "r");

	fseek(fp, 0, SEEK_END);
	//파일 포인터를 파일의 끝으로 이동시킴
	/*fseek는 기준점에서 이동할 거리를 지정해서 파일 포인터를
	이동시킴, 이후 파일 읽기/쓰기 함수를 사용하면 fseek에서 
	이동시킨 파일 포인터의 위치부터 읽기/쓰기를 하게됨 
	SEEK_SET: 파일의 처음부터 이동을 시작 
	fseek(fp, 0, SEEK_SET);파일 포인터를 파일의 처음으로 이동시킴
	SEEK_CUR: 현재 위치부터 이동을 시작 
	fseek(fp, -10, SEEK_CUR);파일 포인터를 현재 위치에서 10바이트
	만큼 역방향으로 이동시킴(-10이 음수이기 때문에)
	SEEK_END: 파일의 끝부터 이동을 시작함 
	fseek(fp, 0, SEEK_END);파일 포인터를 파일의 끝으로 이동시킴
	이동할 크기가 양수면 순방향으로 이동하고 음수면 역방향으로
	이동함 
	*/
	size = ftell(fp);
	//파일 포인터의 현재 위치를 반환해서 13가 나옴 

	printf("%d\n", size);

	fclose(fp);

	//파일의 크기를 구하는 방법을 이용해서 파일의 크기만큼 버퍼를
	//생성해서 파일을 읽어보기 

	char *buffer;
	int size2;
	unsigned long long count;

	FILE *fp2 = fopen("hello.txt", "r");

	fseek(fp2, 0, SEEK_END);
	//파일 포인터를 파일의 끝으로 이동시킴
	size2 = ftell(fp2);
	//파일 포인터의 현재 위치(=파일 크기)를 반환함 
	buffer = malloc(size2 + 1);
	//파일의 문자열을 읽어서 C 언어 문자열로 만들때는 문자열
	//마지막의 널 문자 공간까지 확보해야 되서 파일크기 + 1바이트
	//만큼 메모리를 할당해줌 

	memset(buffer, 0, size2 + 1);
	//malloc으로 할당한 메모리는 이전에 사용하던 값이
	//남아있으므로 memset 함수를 이용해서 0으로 초기화를 해줌 
	
	fseek(fp2, 0, SEEK_SET);
	//파일 포인터를 파일의 처음으로 이동시킴 
	//rewind 함수를 사용해서 파일 포인터를 파일의 처음으로 이동
	//시킬 수도 있음-> rewind(fp2); ,stdio.h에 선언되있음
	
	count = fread(buffer, size2, 1, fp2);
	//hello.txt에서 파일크기만큼 값을 읽음 

	printf("%s size : %d, count : %llu\n", buffer, size2, count);
	//파일 내용, 파일 크기, 읽은 횟수 출력 
	fclose(fp2);
	//파일 포인터 닫기

	free(buffer);
	//동적 메모리 해제 

	//fseek 함수를 사용하여 파일 포인터의 위치를 설정한 뒤 파일의
	//내용을 부분적으로 읽기 

	char buffer2[10] = { 0, };
	
	FILE *fp3 = fopen("hello.txt", "r");

	fseek(fp3, 2, SEEK_SET);
	//파일 포인터를 파일의 처음에서 2바이트 만큼 순방향으로 
	//이동시킴 

	fread(buffer2, 3, 1, fp3);

	printf("%s\n", buffer2);
	memset(buffer2, 0, 10);

	fseek(fp3, 3, SEEK_CUR);
	fread(buffer2, 4, 1, fp3);

	printf("%s\n", buffer2);

	fclose(fp3);

	char *s1 = "abcd";
	char buffer3[20] = { 0, };
	FILE *fp4 = fopen("hello.txt", "r+");
	fseek(fp4, 3, SEEK_SET);
	fwrite(s1, strlen(s1), 1, fp4);

	rewind(fp4);
	fread(buffer3, 20, 1, fp4);

	printf("%s\n", buffer3);

	fclose(fp4);

	/*
	제한된 버퍼로 파일 전체를 읽어보기 
	feof(파일포인터); 파일의 끝이면1, 끝이 아니면 0을 반환함 
	*/

	char buffer4[5] = { 0, };
	size_t count2 = 0, total = 0;

	FILE *fp5 = fopen("hello.txt", "r");
	
	while (feof(fp5) == 0)
	{
		count2 = fread(buffer4, sizeof(char), 4, fp);
		printf("%s", buffer4);
		memset(buffer4, 0, 5);
		total += count2;
	}

	printf("\ntotal: %zd\n", total);

	fclose(fp5);

	FILE *fp7 = fopen("words.txt", "r");
	fseek(fp7, 0, SEEK_END);
	int size4 = ftell(fp7);
	char *buffer7 = malloc(size4 + 1);
	fseek(fp7, 0, SEEK_SET);
	memset(buffer7, 0, size4 + 1);
	fgets(buffer7, size4 + 1, fp7);
	for (int i = size4 - 1; i >= 0; i--)
	{
		fwrite(&buffer7[i], sizeof(char), 1, stdout);
	}
	printf("\n");

	fclose(fp7);
	free(buffer7);

	
	return 0;
}