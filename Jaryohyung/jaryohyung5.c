#include<stdio.h>
#include<float.h> 
//�Ǽ� �ڷ����� �ִ�,�ּڰ��� �ִ� �������
int main()
{
	/*
	���α׷��� ���� �Ǽ�(real number)��
	�Ҽ����� �ִ� ���� ����
	�Ǽ��� �Ǽ� �ڷ����� ���� 
	�Ǽ� �ڷ���: float, double ,long double
	�Ǽ��� �ε��Ҽ��� ������� ����
	IEEE 754 ǥ�رԾ� 
	�Ҽ����� ���ٴѴٰ� �ؼ� floating point
	double�� float�� �� �� ũ��� double 
	long double�� double���� �� �׷� ��
	�ε��Ҽ��� ��� : ��(��ȣ) m(����) x n��(���,����)
	����� 2�� ����������, ������ ���� 2 ���� 
	float�� �����е� �ε��Ҽ��� ������
	double�� �����е� �ε��Ҽ��� ������
	double�� �� �� �� �ڸ����� �Ҽ����� �����ϰ� ǥ���� ����
	window �ü�������� �Ǽ� �ڷ����� ũ��
	float : 4����Ʈ, double: 8����Ʈ, long double : 8����Ʈ
	��ȿ�ڸ���: float 7, double 16, long double 16 
	long double�� �ü������ ũ�Ⱑ �ٸ�
	*/
	
	float num1 = 0.1f;
	//.1f 1.f ���� (0����)
	double num2 = 3867.21564;
	long double num3 = 9.3425351l;

	//%f : floating point�� ���� 
	//%Lf : long floating point�� ���� 

	printf("%f\n%f\n%Lf\n",num1,num2,num3);

	/*
	���� ǥ���(exponential notation)
	���� �κ��� �� �ڸ��� ����� ������ ǥ��

	�Ǽ�e+���� : �Ǽ� *10�� �ŵ�����
	2.1e + 3�� 2.1*1000 = 2100�� �ǹ�
	
	�Ǽ�e-���� : �Ǽ� *(1/10)�� �ŵ�����
	2.1e - 2�� 2.1*(1/100) = 0.021�� �ǹ�
	*/

	float num4 = 3.e5f;	//300000 ������ ����� �� + ��������
	double num5 = -1.3827e-2;	//-0.013827	
	long double num6 = 5.21e+9l;	

	printf("%e\n%e\n%Le\n", num4, num5, num6);
	//%e �� ����ǥ���(exponential notation)�� ����
	//%Le �� long exponential notation�� ���� 

	float num7 = 0.0f;
	double num8 = 0.0;
	long double num9 = 0.0l;

	printf("float : %lld\ndouble : %lld\nlong double : %lld\n"
		, sizeof(num7),sizeof(num8),sizeof(num9) );

	float num10 = FLT_MIN;
	float num11 = FLT_MAX;
	double num12 = DBL_MIN;
	double num13 = DBL_MAX;
	long double num14 = LDBL_MIN;
	long double num15 = LDBL_MAX;

	printf("%.40f\n%.2f\n", num10, num11);	
	//�Ҽ������� �ڸ��� ���� .40f -> �Ҽ��� ���� 40�ڸ�����
	printf("%e\n%e\n", num12, num13);
	//���� ǥ������� ���
	printf("%Le\n%Le\n", num14, num15);

	float num16 = FLT_MIN;
	float num17 = FLT_MAX;
	float num18 = -FLT_MAX*10000000000;
	float num19 = -FLT_MIN / 10000000000000000;
	
	num16 = num16 / 1000000000.0f;
	num17 = num17 *1000.0f;

	printf("%e\n%e\n%e\n%e\n", num16, num17,num18, num19);
	//INF ->  ���Ѵ�(��� �ִ񰪿��� �����÷ο� �߻��� ��)
	//-INF -> ���̳ʽ� ���Ѵ�(���� �ּڰ����� 
	//��� �÷ο� �߻��� ��)
	//0�Ǵ� ������ ������ ó��(��� �ּڰ����� 
	//��� �÷ο� �߻��� ��) 
	
	return 0;


}