#include<stdio.h>
#include<stdint.h>	//ũ�Ⱑ ǥ�õ� ���� �ڷ���
//stdint�� �ִ� �ּڰ��� ���ǵ��ִ� �������
int main()
{
	int8_t num1 = -128;	
	//8��Ʈ(1����Ʈ) ũ���� ��ȣ�ִ� ���� �ڷ��� ����
	int8_t num5 = INT8_MAX;
	int sizeNum1 = sizeof(int8_t);

	int16_t num2 = 32767;
	//16��Ʈ(2����Ʈ) ũ���� ��ȣ�ִ� ���� �ڷ��� ����
	int16_t num6 = INT16_MIN;
	int sizeNum2 = sizeof(int16_t);

	int32_t num3 = 2147483647;
	//32��Ʈ(4����Ʈ) ũ���� ��ȣ�ִ� ���� �ڷ��� ����
	int32_t num7 = INT32_MIN;
	int sizeNum3 = sizeof(int32_t);

	int64_t num4 = 9223372026854775807;
	//64��Ʈ(8����Ʈ) ũ���� ��ȣ�ִ� ���� �ڷ��� ����
	int64_t num8 = INT64_MIN;
	int sizeNum4 = sizeof(int64_t);

	printf("%d\n%d\n%d\n%lld\n", num1, num2, num3, num4);
	printf("%d\n%d\n%d\n%lld\n", num5, num6, num7, num8);

	printf("num1 ũ��: %d\nnum2 ũ��: %d\n"
		,sizeNum1,sizeNum2);
	printf("num3 ũ��: %d\nnum4 ũ��: %d\n"
		,sizeNum3, sizeNum4);

	return 0;

}