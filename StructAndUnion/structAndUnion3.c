#include <stdio.h>
#include <math.h>

struct Point2D {
	int x;
	int y;
};

int main()
{
	struct Point2D p1;
	struct Point2D p2;

	p1.x = 30;
	p1.y = 20;

	p2.x = 60;
	p2.y = 50;

	printf("p1: %d %d\n", p1.x, p1.y);
	printf("p2: %d %d\n", p2.x, p2.y);

	int a = p2.x - p1.x;
	int b = p2.y - p1.y;
	
	//��Ʈ(��)�� ���Ϸ��� sqrt�Լ��� �����
	//sqrt(��) double sqrt(double _X);
	//�������� ��ȯ, _X�� �����̸� NaN�� ��ȯ��

	//�������� ���ϴ� square root ���� ����
	//math.h ������Ͽ� ����� ����
	//double c = sqrt((a*a) + (b*b));
	double c = sqrt(pow(a, 2) + pow(b, 2));
	printf("%f\n", sqrt(-7));
	//�ŵ�����(power)�� ���ϴ� �Լ� pow�ε� ǥ���� �� ����
	//pow(��, ����);
	//double pow(double _X, double _Y);
	//_X�� _Y �ŵ������� ��ȯ�� , math.h ������Ͽ� ����� ����
	printf("%f\n", c);

	//int a = p1.x - p2.x;
	//int b = p1.y - p2.y;
	//������ �� �� ���ؼ� ����� �Ǳ� ������ �Ȱ��� ���� ����
	/*
	abs, fabs, fabsf �Լ��� ����ϸ� ��� �Ǵ� ������ ��������
	���� ���� ����, �� �Լ��� math.h�� ���������(GCC�� stdlib.h)
	
	abs(����);
	int abs(int_X);
	���� ������ ��ȯ

	fabs(double�� �Ǽ�);
	double fabs(double_X);
	double�� �Ǽ��� ������ ��ȯ
	
	fabsf(float�� �Ǽ�);
	float fabsf(float_X);
	float�� �Ǽ��� ������ ��ȯ

	int a = p2.x - p1.x;
	int b = p2.y - p1.y;
	distance = sqrt(pow(a, 2) + pow(b, 2)); 
	*/

	return 0;
}