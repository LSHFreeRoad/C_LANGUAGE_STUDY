#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "archive.h"
#include "command.h"

int main(int argc, char *argv[])
{

	/*
	���� ��ī�̺� �����ϱ�
	��ī�̺� ���Ͽ� �� ���� �߰�(append)
	��ī�̺� ���Ͽ� ����ִ� ������ ��� ���(list)
	��ī�̺� ���Ͽ� ����ִ� ������ �����Ͽ� �� ���Ϸ� ����(extract)
	���� �ȿ� ������ ���� ���� �����Ϸ��� ���� ������ ���޾� �����ϸ� ������ �׷��� �Ǹ� ��� ��ġ�� � ������
	����Ǿ� �ִ��� �˱Ⱑ �����. ���� ��ī�̺� ���� �ȿ��� �ʿ��� ������ �Բ� �־��־�� ��
	�ʼ����� ������ ���� �̸�, ���� ũ��, ���� ������ ��ġ��. ��ī�̺� ������ �´��� Ȯ���ϱ� ����
	���� �ѹ��� ���� ������ �ʿ���
	��ī�̺� ���� ����
	��ī�̺� ���		 ����1												 ����2
	���� �ѹ� ���� ����	 ���� �̸� ���� ũ��  ���� ������ ��ġ ���� ������   ���� �̸� ���� ũ��  ���� ������ ��ġ ���� ������

	���̳ʸ� ������ ���� ������ �����̶� �ٲ�� ����� �������. 1����Ʈ�� ��߳��� ������ �ٸ� ������ �а� �Ǳ� ������
	�׷��� ���� ���̳ʸ� �������� �� ������ ����(����) ������ �Բ� �����ϰ� ���� ������ ���� ���� ó���ϵ��� ������
	��ī�̺� ���� ����ü �ۼ��ϱ�
	��ī�̺� ��� �ۼ�(��ī�̺� ������ �����ѹ��� ���� ������ ��. ���⼭�� �� ����� ũ�⸦ ��Ȯ�ϰ� ǥ��������
	stdint.h ��������� �ڷ����� �����)
	���� ���� ����ü �ۼ��ϱ�
	���� �̸� ���ڿ��� ���� ũ��, ���� �������� ��ġ�� ��. ���� �������� ��ġ�� ��ī�̺� ���� �ȿ��� �ش� ������ �����Ͱ�
	�ִ� ���� ���� ��ġ�� �����ϰ� ��
	��ī�̺� ��� ����ü �� ���� ���� ����ü�� �ڷ��� ũ�� �״�� ����Ǿ�� �ϹǷ� #pragma pack(push,1), #pragma pack(pop)��
	����Ͽ� 1����Ʈ ũ��� ��������
	���� ������ ��ī�̺� ���� ������ �Ѱ�
	1. ���� �̸��� 255�� �̻� ������ �� ��
	2. ���� ũ��� ���� �������� ��ġ�� �����ϴ� �ڷ����� uint32�̹Ƿ� ũ�Ⱑ 4GB�̻��� ������ ������ �� ����
	3. ��ī�̺� ������ �ִ� ũ��� �ü���� ���� �ý����� ������ �� �ִ� ���� �ϳ��� ũ�⸦ ����
	��ī�̺� ������ �����ϰ� ù ������ �߰��ϴ� ����
	��ī�̺� ���� ���� -> ��ī�̺� ��� ���� -> ��ī�̺� ��� ���� -> hello.txt ���� �߰�, append() -> �߰��� ���� ���� 
	-> �߰��� ������ ũ�� ���ϱ� -> �� ���� ���� ���� -> ��ī�̺� ��� ������ �� ���� ���� ���� -> �� ���� ������ ���� 
	-> ��ī�̺� ���� �ݱ�, getFileSize: ������ ũ�⸦ ���ϴ� �Լ�, append: ��ī�̺� ���Ͽ� ������ �߰��ϴ� �Լ�
	
	main �Լ����� ��ī�̺� ���Ͽ� ��ī�̺� ����� �����ϸ� �Ʒ��� ���� ����� ��
					��ī�̺� ���	hello.txt
	archive.bin		magic version	name size	dataOffset	���� ������ 		
	*/

	/* ��ī�̺� ���Ͽ��� ���� ��� ����ϱ� -> ���Ḯ��Ʈ�� ���� 
	��ī�̺� ���Ͽ��� ���� ����� ����ϴ� ����
	��ī�̺� ���� ���� -> ��ī�̺� ��� �б� -> ���� �ѹ� �˻� -> ���� ���� �˻� -> ���� ������ �о ���� ����Ʈ�� �߰�
	-> ���� ��� ���, list() <���� ����Ʈ�� ��ȸ�ϸ鼭 ���� �̸� ���> -> ���� ����Ʈ �޸� ���� -> ��ī�̺� ���� �ݱ�  
	���� ��� ����ü�� �ʿ���(���� ����� ���Ḯ��Ʈ�� �����ؼ� ���� ����� �����ϱ� ���� ����ü��, ���α׷������� �����)  
	���� 3���� ���� ����Ʈ�� �������� �� ����
				���� A		���� B		���� C
FILE_NODE		next	->	next	->	next	->	NULL
FILE_DESC		name		name		name	
				size		size		size
				dataOffset	dataOffset	dataOffset
	ARCHIVE ����ü���� ���� ��� ���� ����Ʈ�� �Ӹ� ��带 ����� �߰����� 
	*/

	/*	��ī�̺� ���Ͽ� ����ִ� Ư�� ���� �����ϱ� 
	��ī�̺� ���� ���� -> ��ī�̺� ��� �б� -> ���� �ѹ� �˻� -> ���� ���� �˻� -> ���� ������ �о ���� ����Ʈ�� �߰�
	-> hello.txt ���� ����, extract() < ���� ��� ���� ����Ʈ ��ȸ -> ��ī�̺� ���Ͽ��� ������ ������ ������ �б� -> ������
	������ ������ �� ���� ���� -> �� ���Ͽ� ������ ���� -> ���� �ݱ�> -> ���� ����Ʈ �޸� ���� -> ��ī�̺� ���� �ݱ� 
	
	������ actualPractice3.c �ȿ� ��� ����� �� �� �ִµ� �ҽ��ڵ尡 ������ ���� �������� �ҽ��ڵ尡 ������� 
	��� �߰��� ��������� ���������� ���� �ʰ� ��
	�Լ����� ���� �з��ϱ�
	archive.h	initialize	��ī�̺� ������ ��� ���� �ѹ��� ���� ������ �˻��ϰ� ���� ����� ����
	archive.c	finalize	���α׷� �������� ���� ����ü �޸𸮸� �����ϰ� ��ī�̺� ������ ����
				isExtract	��ī�̺꿡 Ư�� ������ �ִ��� �˻��� 
	command.h	append		��ī�̺꿡 ������ �߰���
	command.h	list		��ī�̺��� ���� ����� �����		
				extract		��ī�̺꿡�� ������ ������
	file.h		getFileSize	������ ũ�⸦ ����
	file.c	
	actualPractice3.c		main�Լ�
	*/

	/*C���� �����ϴ� ���� ���� �ɼ� ����� Ȱ���Ͽ� append, list, extract ����� ó���ϱ� 
			initialize() -> �ʱ�ȭ 
		��		��		   ��
	append()	list()	extract()	-> ��� ���� 
				��
			finalize() -> ���� 
	
	*/
	//���� ���Ͽ� ������ �ɼ��� ���� �� ���α׷� ��� ��� ���
	if (argc == 1)
	{
		printf("filearchive <���> <���ϸ�>\n\n");
		printf("���:\n");
		printf("	append	���� �߰�\n");
		printf("	list	���� ��� ���\n");
		printf("	extract	���� ����\n");
		return 0;
	}
	//initialize �Լ��� ȣ���Ͽ� ��ī�̺� ������ ���� ���� ������ ���� ����� ���� 
	PARCHIVE archive = initialize();
	
	if (archive == NULL)
		return -1;
	//filearchive.exe <���> <���ϸ�> ������ �� ���̹Ƿ� argv[1]�� ���, argv[2]�� ���ϸ��� ��
	char *command = argv[1];
	char *filename = argv[2];

	//command�� ������ �Ǻ��Ͽ� append�̸� ���� �߰�, list�̸� ���� ��� ���
	//extract�̸� ���� ������ ��, ���⼭ ������ �߰��� �� ���� �̸����� �� ������ �ߺ����� �ʵ���
	//isExist �Լ��� �˻����ְ� ������ ������ ���� ��ī�̺� ���Ͽ� ������ ������ �ִ��� isExist �Լ��� �˻����� 

	if (strcmp(command, "append") == 0)	//���� �߰� ���
	{
		if (!isExist(archive, filename))	//��ī�̺� ���Ͽ� �߰��� ������ �ִ��� �˻�
		{	
			//������ �ߺ����� ������ �� ���� �߰� 
			if (append(archive, filename) == -1)
			{
				printf("%s ���� �߰� ����\n", filename);
			}
		}
		else
		{
			printf("�̹� %s ������ �߰��Ǿ� �ֽ��ϴ�.\n", filename);
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
				printf("%s ���� ���� ����\n", filename);
			}
		}
		else
		{
			printf("%s ������ �����ϴ�.\n", filename);
		}
	}
	//��� �۾��� �������� finalize�Լ��� ȣ���Ͽ� ���� �����͸� �ݰ� ��� ���� �޸𸮸� ������ 
	finalize(archive);	
	
	 //���ϵ��� ���԰���
	//actualPractice3.c (command.h, archive.h ����)
	//command.c (archive.h, file.h ����)
	//archive.c (archive.h, file.h ����)
	//command.h (archive.h ����)

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