#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "archive.h"
#include "file.h"

/* main �Լ��� ����ִ� �ڵ带 initialize, finalize �Լ��� �и��ϰ� isExtract �Լ��� ������ 
isExtract �Լ��� ���� ��� ���� ����Ʈ�� ù ��° ������ ��ȸ�ϸ鼭 ������ ������ true�� ��ȯ�ϰ� ������ false�� ��ȯ�� 
*/
#define ARCHIVE_NAME "archive.bin"

PARCHIVE initialize()	//�ʱ�ȭ �Լ� ���� 
{
	PARCHIVE archive = malloc(sizeof(ARCHIVE));
	memset(archive, 0, sizeof(ARCHIVE));

	FILE *fp = fopen(ARCHIVE_NAME, "r+b");	//��ī�̺� ������ �б�/���� ���� ����
	if (fp == NULL)	//��ī�̺� ������ ������ 
	{

		fp = fopen(ARCHIVE_NAME, "w+b");	//���ο� ��ī�̺� ������ ������ 

		if (fp == NULL)	//���� ������ �����ϸ� ���α׷� ����
			return NULL;

		//�� ��ī�̺� ��� ���� 
		archive->header.magic = 'AF';	//�����ѹ� 'AF'����(��Ʋ ����𿡼��� 'FA'�� �����)
		archive->header.version = 1;	//���� ���� 1�� ������ 

		//��ī�̺� ���Ͽ� ��ī�̺� ��� ���� 
		if (fwrite((&archive->header), sizeof(ARCHIVE_HEADER), 1, fp) < 1)
		{
			printf("��ī�̺� ��� ���� ����\n");
			fclose(fp);
			return NULL;
		}
	}
	else	//��ī�̺� ������ ������ 
	{
		//��ī�̺� ���Ͽ��� ��ī�̺� ��� �б�
		if (fread(&archive->header, sizeof(ARCHIVE_HEADER), 1, fp) < 1)
		{
			printf("��ī�̺� ��� �б� ����\n");
			fclose(fp);
			return NULL;
		}
	}

	//��ī�̺� ���� �����ѹ� �˻�
	if (archive->header.magic != 'AF')
	{
		printf("��ī�̺� ������ �ƴմϴ�.\n");
		fclose(fp);
		return NULL;
	}
	//��ī�̺� ���� ���� �˻� 
	if (archive->header.version != 1)
	{
		printf("������ ���� �ʽ��ϴ�.\n");
		fclose(fp);
		return NULL;
	}//���� ��ī�̺� ���� ������ ������ ���� �� ���� ���� �������� ����ü�� �������� ������ ���� �ش� ����ü�� 
	 //����ϸ� ��. switch �б⹮�̳� if, else�� ������ ���� ����ü�� �����ؼ� ����ϸ� �� 

	archive->fp = fp;	//��ī�̺� ���� ������ ����

	uint32_t size = getFileSize(fp);	//��ī�̺� ������ ũ�⸦ ����
	uint32_t currPos = ftell(fp);		//���� ���� �������� ��ġ�� ���� 

	while (size > currPos)	//���� �������� ��ġ�� ���� ũ�⺸�� ���� �� �ݺ�
	{	//�� ��ī�̺� ��� �������� ���� ������ ��� �����鼭 ���� ������ ������ 
		PFILE_NODE node = malloc(sizeof(FILE_NODE));
		memset(node, 0, sizeof(FILE_NODE));

		//���� ���� �б�
		if (fread(&node->desc, sizeof(FILE_DESC), 1, fp) < 1)
		{
			printf("��ī�̺� ���� �б� ����\n");
			free(node);
			finalize(archive);
			return NULL;
		}

		//���Ḯ��Ʈ�� ���� ���� ��� �߰� 
		node->next = archive->filelist.next;
		archive->filelist.next = node;

		//���� ���� �������� ��ġ�� ���� ������ ũ�⸸ŭ ���ؼ� ���� ���� ���� ��ġ�� �̵��� 
		currPos = ftell(fp) + node->desc.size;
		fseek(fp, currPos, SEEK_SET);

	}

	return archive;
}

void finalize(PARCHIVE archive)	//���� �Լ� ����
{	
	//���� ��� ���Ḯ��Ʈ�� ��ȸ�ϸ鼭 �޸� ���� 
	PFILE_NODE curr = archive->filelist.next;	//ù ��° ���
	while (curr != NULL)
	{
		PFILE_NODE next = curr->next;
		free(curr);
		curr = next;
	}

	fclose(archive->fp);	//��ī�̺� ���� ������ �ݱ�
	free(archive);	//��ī�̺� ���� ����ü ���� 
}

bool isExist(PARCHIVE archive, char *filename)
{	
	//���� ��� ���Ḯ��Ʈ�� ��ȸ�ϸ鼭 ������ �ִ��� �˻��� 
	PFILE_NODE curr = archive->filelist.next;	//ù ��° ��� 

	while (curr != NULL)
	{	//������ ������ true ��ȯ 
		if (strcmp(curr->desc.name, filename) == 0)
			return true;
		curr = curr->next;
	}
	return false;	//������ ã�� �������� false ��ȯ 
}
