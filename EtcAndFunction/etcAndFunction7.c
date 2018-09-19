#include <stdio.h>

void printArray(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void setElement(int arr[])
{
	arr[2] = 300;
}

void printArray2(int *arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

swapElement(int arr[], int first, int second)
{
	int temp;

	temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
	//�迭�� �޸� �ּҸ� �޾Ƽ� �ּҿ� ���� �����ؼ� ���� ������
}

//GCC, Clang������ ������ 
//void printArray3(int arr[static 5], int count)
//{
//	for (int i = 0; i < count; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//}




void print2DArray(int arr[][5], int col, int row)
{
	//�Լ����� 2���� �迭�� �Ű������� ����Ҷ��� ��ȣ�� 2�� ���̰� 
	//2��° ��ȣ������ ����ũ�⸦ ������ 
	//��, arr[][5]�� 2���� �迭�� �޸� �ּҸ� ��� �ִ� �������̸�
	//2���� �迭�� ���� ũ�⸦ �� �� �����Ƿ� �ٸ� �Ű������� 
	//�迭�� ����, ���� ũ�⸦ �޾ƾ� ��

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}

void print2DArray2(int (*arr)[5], int col, int row)
{
	//����ũ�Ⱑ 5�� 2���� �迭�� ����Ű�� ������
	//�����ͷδ� 2���� �迭�� ũ�⸦ �� �� �����Ƿ� �ٸ� �Ű�������
	//���ؼ� ����, ���� ũ�⸦ ���� 
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}

void transpose(int (*arr)[4], int n)
{
	int temp;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (j > i)
			{
				temp = arr[i][j];
				arr[i][j] = arr[j][i];
				arr[j][i] = temp;
			}
		}
	}

}


int main()
{
	/*
	�Լ����� �迭�� �Ű������� ����ϸ� ���ӵ� ���� ������ �� ����
	�Լ��� ������ �迭�� ��Ҹ� �Լ� �ȿ��� ������ ������
	��ȯ�� �ڷ��� �Լ��̸�(�ڷ��� �Ű�����[])
	{
	}
	��ȯ�� �ڷ��� �Լ��̸�(�ڷ��� *�Ű�����)
	{
	}
	*/

	int numArr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	printArray(numArr, sizeof(numArr) / sizeof(int));

	setElement(numArr);
	//�迭�� �޸� �ּ� ���� 

	printf("%d\n", numArr[2]);

	printArray2(numArr, sizeof(numArr) / sizeof(int));
	
	swapElement(numArr, 0, 1);
	//�迭�� �޸� �ּ� ����
	printf("%d %d\n", numArr[0], numArr[1]);

	/*���� ���ͷ� ����ϱ� -> �Լ��� �迭�� �Ѱ��� �� ���� ���ͷ���
	����ϸ� �迭�� ���� �������� �ʾƵ� ��(���� ���ͷ��� C99��
	�߰��� �����), 
	(�ڷ���[]) {��1, ��2, ��3} 
	(�ڷ���[ũ��]) {��1, ��2, ��3}
	*/
	
	printArray((int[]) { 21, 25, 32, 43 , 56}, 5);

	/*
	2���� �迭�� �Ű������� ����ϱ� 
	��ȯ�� �ڷ��� �Լ��̸�(�ڷ��� �Ű�����[][����ũ��]
	{
	}
	
	��ȯ�� �ڷ��� �Լ��̸�(�ڷ��� (*�Ű�����)[����ũ��])
	{
	}

	*/

	int numArr2[2][5] = { {1,2,3,4,5},{6,7,8,9,10} };

	int col = sizeof(numArr2[0]) / sizeof(int);
	//���� ũ��� 2���� �迭�� ���� �� ���� �ڷ����� ũ��� ���� 

	int row = sizeof(numArr2) / sizeof(numArr2[0]);
	//���� ũ��� 2���� �迭 ��ü ũ�⸦ ���� �� �ٷ� ���� 
	print2DArray(numArr2, col, row);

	print2DArray2(numArr2, col, row);

	/*
void printReverse(int arr[], int count)  
{
	for(int i = 0; i < count; i++)
		printf("%d ", arr[count - (i + 1)]);

	printf("\n");
}
	*/

	int numArr3[4][4] = { {1,2,3,4},{5,6,7,8,},{9,10,11,12},
	{13,14,15,16} };

	transpose(numArr3, 4);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", numArr3[i][j]);
		}
		printf("\n");
	}






	return 0;
}