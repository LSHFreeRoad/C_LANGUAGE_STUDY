//���� ������ �����ϴ�  ��� ���������Ƿ� #ifndef ARCHIVE_H, #define ARCHIVE_H , #endif�� ����Ͽ� �ߺ������� ������
//�̷��� ���Ǻ� �������� ������ ������ �ߺ� ������ �߻��ϰ�, ������ ������ �߻���
//���� ����ü�� initialize, finalize, isExtract �Լ��� ��������
#ifndef	ARCHIVE_H
#define ARCHIVE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#pragma pack(push,1)
//��ī�̺� ���(��ī�̺� ���Ͽ� ����Ǵ� ����ü)
typedef struct _ARCHIVE_HEADER
{
	uint16_t magic;	//��ī�̺� ���� ���� �ѹ�
	uint16_t version;	//��ī�̺� ���� ����
} ARCHIVE_HEADER, *PARCHIVE_HEADER;

//��ī�̺� ���� ����(��ī�̺� ���Ͽ� ����Ǵ� ����ü)
typedef struct _FILE_DESC
{
	char name[256];	//���� �̸�
	uint32_t size;	//���� ũ��
	uint32_t dataOffset;	//���� ������ ��ġ 
} FILE_DESC, *PFILE_DESC;
#pragma pack(pop)

typedef struct _FILE_NODE
{	//���� ��� ���� ����Ʈ�� ����ü ����
	struct _FILE_NODE *next;	//���� ����� �ּҸ� ������ ������
	FILE_DESC desc;	//���� ���� 
} FILE_NODE, *PFILE_NODE;


//���α׷������� ����ϴ� ����ü(���� �Լ��� ������ ������ ARCHIVE ����ü���� �ʿ��� ������  ���� ���Ե�)
//���� ���� ����� ����ü�� ���α׷��� ����ü�� �и����� �ʰ� ���ļ� �����ϰ� �Ǹ� ����ü�� ���Ͽ� �������� �� �ʿ����
//�����ͱ��� �Բ� ���Ͽ� ����� 
typedef struct _ARCHIVE	//��ī�̺� ���� ����ü 
{
	ARCHIVE_HEADER header;	//��ī�̺� ���
	FILE *fp;	//��ī�̺� ���� ������ 
	FILE_NODE filelist;	//���� ��� ���� ����Ʈ�� �Ӹ� ��� 
} ARCHIVE, *PARCHIVE;

PARCHIVE initialize();	//�ʱ�ȭ �Լ� ����
void finalize(PARCHIVE archive);	//���� �Լ� ����
bool isExist(PARCHIVE archive, char *filename);	//��ī�̺꿡 Ư�� ������ �ִ��� �˻��ϴ� �Լ� ����

#endif	//#ifndef ARCHIVE_H ��
