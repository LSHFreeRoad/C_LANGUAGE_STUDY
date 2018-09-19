#include<stdio.h>
//#include<memory.h>
#include<string.h>
#include<stdlib.h>	//free�Լ��� ����� �������
int main()
{
	/*
	�����Ϳ��� malloc�Լ��� ���ϴ� ��ŭ �޸𸮸� �Ҵ���
	�� ����, malloc -> ��� -> free
	�޸𸮸� ����Ϸ��� malloc �Լ��� �޸� ������ Ȯ��
	�ؾߵ�, �� �� �ʿ��� �޸� ũ��� ����Ʈ ������ ����
	�޸� �Ҵ�, ���� �Լ��� stdlib.h ������Ͽ� �����
	����, ������ = malloc(ũ��); ,
	void malloc(size_t_Size);
	�����ϸ� �޸� �ּ� ��ȯ, �����ϸ� NULL ��ȯ
	*/

	int num1 = 20;
	int *numPtr1;

	numPtr1 = &num1;

	int *numPtr2;

	numPtr2 = malloc(sizeof(int));
	/*�޸𸮸� �Ҵ��Ҷ��� malloc�Լ��� ����ؼ� �Ҵ���
	�޸� ������ ũ�⸦ �־���, int�� ũ�⸸ŭ �޸�
	�Ҵ�, ���ϴ� ������ ���ϴ� ��ŭ �޸𸮸� �Ҵ��� ��
	�ִٰ� �ؼ� ���� �޸� �Ҵ�(dynamic memory 
	allocation)�̶�� �θ�
	���� �޸� �ּҶ� ���������� �ణ�� ���̰� ����
	����(stack)�� ��(heap) �� �����ε� ������
	stack�� malloc�Լ��� heap �κ��� �޸𸮸� �����
	���ð� ���� ū �������� �޸� �����̴�, ���ÿ�
	������ ������ ����� �� ���� ó���� ������ �ʾƵ�
	������ malloc �Լ��� ����Ͽ� heap���� �Ҵ���
	�޸𸮴� �ݵ�� ������ �ؾߵ�(free �Լ� �̿�)
	free(������) -> free(void *_Block)
	�޸� ������ ���û����� �ƴ϶� �ʼ���-> ������
	���ϸ� �ý��ۿ� �޸𸮰� ���������� �ü���� 
	���α׷��� ������ �����Ű�ų� �޸� �Ҵ翡 
	�����ϰ� ��, �Ҵ���� �޸� ������ �������� �ʾƼ�
	�޸� ��뷮�� ��� �����ϴ� ������
	�޸� ����(memory leak)��� �θ�
	*/
	
	printf("%p\n", numPtr1);
	printf("%p\n", numPtr2);

	free(numPtr2);

	int *numPtr3;

	numPtr3 = malloc(sizeof(int));
	*numPtr3 = 10;	//�Ҵ���� �޸𸮿� ���� ������ ���� 
	//�����͸� �������� �� ���� �����ϸ� ��

	printf("%d\n", *numPtr3);

	free(numPtr3);

	//memset �Լ��� ����ϸ� �޸��� ������ ���ϴ�
	//ũ�⸸ŭ Ư�� ������ ������ �� ������ memset��
	//memory set���� ����->string.h �Ǵ� memory.h 
	//������Ͽ� ����� ����, �����ϴ� ũ��� ����Ʈ ����
	//memset(������, ������ ��, ũ��)

	long long *numPtr4 = malloc(sizeof(long long));

	memset(numPtr4, 0x27, 8);
	//numPtr4�� ����Ű�� �޸� ������ 8����Ʈ��ŭ 0x27��
	//������
	printf("0x%llx\n", *numPtr4);
	//0x2727272727272727 -> 16���� 27�� 8�� ������� 
	free(numPtr4);


	//�޸𸮰� �Ҵ���� ���� ������

	int *numPtr5 = NULL;	//NULL�� ����ִ� �����͸�
	//��(NULL) �����Ͷ�� �� 

	printf("%p\n", numPtr5);



	return 0;
}