#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "archive.h"
#include "file.h"

int append(PARCHIVE archive, char *filename)	//���� �߰� �Լ� ����
{
	int ret = 0;	//�Լ��� ���� �� ���� ���θ� ��ȯ������ ǥ�� 
					//��� ������ �����ϸ� 0�� ��ȯ�� 
					//�� �������� ������ ������ goto�� ����ؼ� ���� ó�� �κ����� �̵��ϰ� -1�� ��ȯ�ϵ��� �ϱ� 
					//goto�� ������� ������ ������ ������ �Ź� fclose�� free�Լ��� ��� ����ؾ� �Ǽ� �ڵ尡 ����� 
	FILE *fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("%s ������ �����ϴ�.\n", filename);
		return -1;	//�Լ� ����, -1�� ���� 
	}

	uint8_t *buffer;
	uint32_t size;

	size = getFileSize(fp);	//�߰��ϴ� ������ ũ�⸦ ���� 
	buffer = malloc(size);

	if (fread(buffer, size, 1, fp) < 1)		//�߰��� ������ ������ �о buffer�� ����Ű�� �޸� ������ ������  
	{
		printf("%s ���� �б� ����\n", filename);
		ret = -1;
		goto Error1;
	}

	//�� ���� ���� �����ϱ� 
	PFILE_DESC desc = malloc(sizeof(FILE_DESC));
	memset(desc, 0, sizeof(FILE_DESC));	//�������� ���� ���� �ʵ��� �޸� ������ 0���� �ʱ�ȭ 
	strcpy(desc->name, filename);	//���� ���� ����ü�� �߰��� ������ �̸� ����
	desc->size = size;	//���� ���� ����ü�� �߰��� ������ ũ�� ���� 

	PFILE_NODE node = archive->filelist.next;	//ù ��° ���
	if (node == NULL) //��ī�̺� ���Ͽ� ������ �ϳ��� ������ 
	{	fseek(archive->fp, sizeof(ARCHIVE_HEADER), SEEK_SET);	//��ī�̺� ��� �ٷ� �������� ���� �����͸� �̵���Ŵ 
	desc->dataOffset = ftell(archive->fp) + sizeof(FILE_DESC);
	//���� �߰��� ���� �������� ������ġ�� 
	//���� ���� �������� ��ġ�� ���� ���� ũ�⸸ŭ ���������� �̵���Ų �� 
	}
	else //���� ����Ʈ���� ù ��° ��尡 ���� �������� �߰��� ���� 
	{	//�������� �߰��� ������ ���� ������ ��ġ���� ���� ũ�⸸ŭ ���������� �̵�
		fseek(archive->fp, node->desc.dataOffset + node->desc.size, SEEK_SET);
			
		//���� �߰��� ���� �������� ���� ��ġ�� 
		//�������� �߰��� ������ ���� ������ ��ġ���� 
		//���� ũ��, ���� ���� ũ�⸸ŭ ���������� �̵���Ų �� 
		desc->dataOffset = node->desc.dataOffset + node->desc.size + sizeof(FILE_DESC);
	}

	//��ī�̺� ���Ͽ� �� ���� ���� ����
	if (fwrite(desc, sizeof(FILE_DESC), 1, archive->fp) < 1)
	{
		printf("���� ������ ���� ����\n");
		ret = -1;
		goto Error2;	//fp�� �ݰ�, desc�� buffer�� �����ϴ� ����ó���� �̵�
	}
	//fwrite�Լ��� ���Ͽ� ���� �� ũ�⸸ŭ ���� �����Ͱ� ���������� �̵��ϱ� ������ ���� fseek �Լ��� �� ����ص� �� 
	
	//��ī�̺� ���Ͽ� �� ���� ������ ���� 
	if (fwrite(buffer, size, 1, archive->fp) < 1)
	{
		printf("���� ������ ���� ����\n");
		ret = -1;
		goto Error2;	//fp�� �ݰ�, desc�� buffer�� �����ϴ� ����ó���� �̵�
	}

	printf("%s ���� �߰� ����\nũ��: %d\n", filename, size);

	//Error2�� ���� �ؿ� Error1�� ������ �� 
Error2:
	free(desc);	//���� ����� ���� �޸� ���� 

Error1:
	free(buffer);	//���� ���� ����� ���� �޸� ���� 
	fclose(fp);	//���� ������ �ݱ�


	return ret;	//�����̳� ���п� ���� 0 �Ǵ� -1�� ��ȯ�� 
}

void list(PARCHIVE archive)
{
	printf("���� ���:\n");

	//���� ��� ���Ḯ��Ʈ�� ��ȸ�ϸ鼭 ���� �̸� ��� 
	PFILE_NODE curr = archive->filelist.next;	//ù ��° ���
	while (curr != NULL)
	{
		printf("	%s\n", curr->desc.name);
		curr = curr->next;
	}


}

int extract(PARCHIVE archive, char *filename)	//���� ���� �Լ� ����
{

	//���� ��� ���Ḯ��Ʈ�� ��ȸ�� 
	PFILE_NODE curr = archive->filelist.next;	//ù ��° ���

	while (curr != NULL)
	{	//������ ������ �ִ��� �˻��� 
		if (strcmp(curr->desc.name, filename) == 0)	//��ī�̺� ���� �ȿ� ������ ������ �ִٸ� 
		{
			int ret = 0;
			uint32_t size = curr->desc.size;
			uint8_t *buffer = malloc(size);	//���� ũ�⸸ŭ ���۸� �Ҵ��� 

			//��ī�̺� ���Ͽ��� ���� �����͸� desc.dataOffset��ŭ ���� ������ ��ġ�� �̵���Ŵ 
			fseek(archive->fp, curr->desc.dataOffset, SEEK_SET);

			//fread�Լ��� ������ ���� ũ�� ��ŭ �б� 
			if (fread(buffer, size, 1, archive->fp) < 1)
			{
				printf("��ī�̺� ���� �б� ����\n");
				ret = -1;	//-1�� ����
				goto Error1;	//buffer�� �����ϴ� ���� ó���� �̵��� 
			}

			//������ ������ ������ �� ������ ������ 
			FILE *fp = fopen(filename, "wb");
			if (fp == NULL)
			{
				printf("%s ���� ���� ����\n", filename);
				ret = -1;
				goto Error1;	//buffer�� �����ϴ� ���� ó���� �̵��� 
			}

			//���� ������ ���Ͽ� ���� ������ ���� 
			if (fwrite(buffer, size, 1, fp) < 1)
			{
				printf("%s ���� ���� ����\n", filename);
				ret = -1;
				goto Error2;
			}

			printf("%s ���� ���� ����\nũ��: %d\n", filename, size);

		Error2:
			fclose(fp);	//���� ������ �ݱ�

		Error1:
			free(buffer);	//���� �޸� ����
			return ret;		//���� �Ǵ� ���п� ���� 0 �Ǵ� -1�� ��ȯ�� 

		}

		curr = curr->next;
	}


	return -1;

}
