#include <stdio.h>

enum DayOfWeek {
	Sunday = 0,
	Monday,	//1
	Tuesday, //2
	Wendesday,	//3
	Thursday,	//4
	Friday,	//5
	Saturday	//6
	//�������� ���� ó������ �Ҵ����ָ� �� �Ʒ��� ���� ������
	//1�� �����ϸ鼭 �ڵ����� �Ҵ��, �ƹ��͵� �Ҵ����� ������
	//0���� ������
};

typedef enum _DayOfWeek2 {
	Sunday2 = 0,
	Monday2,	//1
	Tuesday2, //2
	Wendesday2,	//3
	Thursday2,	//4
	Friday2,	//5
	Saturday2,	//6
	DayOfWeekCount
} DayOfWeek2;

enum LuxSkill {
	LightBinding = 1,
	PrismaticBarrier,
	LucentSingularity,
	FinalSpark
};

int main()
{
	/*
	�������� ������ ����� �̸��� �ٿ��� �ڵ带 �����ϱ� ���� ����
	�������� enumŰ����� ������
	����, ����� �ǹ��ϴ� enumeration���� ����
	�������� ���Ǹ� �ؼ��� ����� �� ���� �������� ������
	�����ؼ� �����
	enum �������̸�{
		��1 = �ʱ갪,
		��2,
		��3
		.
		.
		.
	};
	*/

	enum DayOfWeek week; //������ ���� ���� 

	week = Tuesday; //������ �������� �̸� ������ ������ ���� ����

	printf("%d\n", week);

	/*
	������ �̸��̳� ���� ������ �� �빮�ڸ� ����ϴ� ��찡 ����
	Ư�� �ܾ�� �ܾ� ���̿��� _�� ����
	�������� typedef�� ������ ��Ī�� �����ϰ� �͸� ��������
	������ �� ����, �������� �����ϴ� ���ÿ� ���� ������ ������
	switch(������ ����)
	{
	case ��������;
		������ �ڵ�;
		break;
	}
	*/

	enum LuxSkill skill;

	skill = LightBinding;

	switch (skill)
	{
	case LightBinding:
		printf("LightBinding\n");
		break;
	case PrismaticBarrier:
		printf("PrismaticBarrier\n");
		break;
	case LucentSingularity:
		printf("LucentSingularity\n");
		break;
	case FinalSpark:
		printf("FinalSpark\n");
		break;
	default:
		break;
	}
	//���α׷��� 1, 2, 3, 4�� ó���ϰ� ����� ��ų�̸��� ����
	//����ϴ� ���, ���⼭�� skill�� LightBinding�� �Ҵ������Ƿ�
	//case LightBinding: �� �����

	for (DayOfWeek2 i = Sunday2; i < DayOfWeekCount; i++)
	{
		printf("%d\n", i);
	}//������ �� Sunday���� Saturday���� �ݺ��� �� ���� 

	/*
	enum PROTOCOL_TYPE{
		PROTOCOL_IP = 4,
		PROTOCOL_UDP,
		PROTOCOL_TCP
	};

	enum MasterYiSkill skill;

	skill = Meditation;

	for(INTERFACE_TYPE i = Internal; i < MaximumInterfaceType; i++)
	*/
	return 0;
}