#include <stdio.h>
#include <stdint.h>

uint32_t getFileSize(FILE *fp)	//������ ũ�⸦ ���ϴ� �Լ� ����
{
	uint32_t size;
	uint32_t currPos = ftell(fp);	//���� ���� �������� ��ġ ����

	//������ ������ �̵��Ͽ� ������ ũ�⸦ ����
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	fseek(fp, currPos, SEEK_SET);	//���� �����͸� ������ ��ġ�� �ǵ��� 

	return size;
}