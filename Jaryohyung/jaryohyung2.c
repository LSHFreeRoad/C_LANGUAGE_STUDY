#include<stdio.h>
int main()
{
	int num1 = 0;
	int size,size1;

	size = sizeof num1; // ǥ����
	//ǥ������ ����, ���, �迭 ��
	//���α׷��Ӱ� ���� ��Ҹ� ���Ѵ�

	size1 = sizeof(int);

	printf("num1�� ũ�� : %d����Ʈ\nint�� ũ��: %d����Ʈ\n"
		, size, size1 );

	printf("=====================================\n");

	printf("char : %d \nshort : %d \nint : %d \n" 
		,sizeof(char),sizeof(short),
		sizeof(int) );
	printf("long : %d\nlong long : %d\n",sizeof(long)
		, sizeof(long long));


	return 0;


}