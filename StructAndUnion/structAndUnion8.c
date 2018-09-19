#include <stdio.h>
#include <stdlib.h>
struct Phone {
	int areacode;
	unsigned long long number;
};

struct Person {
	char name[20];
	int age;
	struct Phone phone;
	struct Phone *phone2;
	//����ü�� ����� �������� ����ü �ȿ��� ����ü�� �����ϸ� ��
};

struct Vector3 {
	union {
		struct {
			float x;
			float y;
			float z;
		};	
		//pos.xó�� ����� �ٷ� �����ϱ� ���� �͸� ����ü�� ������ 
		float v[3];
		//�͸� ����ü�� x,y,z �͸� ����ü�� �迭 v�� ���ΰ� ����
		//pos.vó�� ����� �ٷ� �����ϱ� ���� �͸� ����ü�� ������ 
	};
};


int main()
{
	struct Person p1;

	//����� ������ ���� .�� ����ؼ� ������ �ִ� ����ü�� 
	//���������� �����ϸ� �� , ����.���.���

	p1.phone.areacode = 82;
	p1.phone.number = 3045671234;

	printf("%d %llu\n", p1.phone.areacode, p1.phone.number);

	/*

	struct Person {
		char name[20];
		int age;
		struct Phone {
			int areacode;
			unsigned long long number;
		} phone;
	};

	����ü ������ ����ü�� ������ ���� �ݵ�� ������ �����ؾ� ��!
	���� ����ü���� ����ü�� ������ ���� �� ����Ǵ� ����ü��
	������ �����߾�� ��		
	*/

	struct Person *p2 = malloc(sizeof(struct Person));

	p2->phone.areacode = 82;
	p2->phone.number = 3045671234;

	//p2�� ->�� ����Ͽ� ����� ���� , phone�� �����Ͱ� �ƴ� �Ϲ�
	//�����̹Ƿ� .�� ����Ͽ� ����� ������. ��, ������->���.���


	printf("%d %llu\n", p2->phone.areacode, p2->phone.number);

	free(p2);

	struct Person *p3 = malloc(sizeof(struct Person));
	p3->phone2 = malloc(sizeof(struct Phone));

	p3->phone2->areacode = 82;
	p3->phone2->number = 3045671234;

	printf("%d %llu\n", p3->phone2->areacode, p3->phone2->number);

	free(p3);

	/*
	�ٱ��� �ִ� ����ü �����͸� ���� �����ϸ� �����Ͱ� ������Ƿ�
	�ȿ� �ִ� ����� �� �̻� ������ ���� ���� ��, �׷���
	��� �����Ͱ� ����� �ּҵ� �� �� �����Ƿ� ������ �� �� ���� 
	������ �̸� ��� �������� �ּҸ� �ٸ� ���� ������ �ξ��ٸ� 
	�ٱ��� �ִ� ����ü �����͸� ���� �����ص� ����� ����
	����ü �ȿ� ����ü�� �����ͷ� �� ���� ���� ������ ����ϸ�
	���ǵ��� ���� ����ü�� ���� ����� ���� ����
	struct ����ü �̸�;
	*/

	struct Vector3 pos;
	
	for (int i = 0; i < 3; i++)
	{
		pos.v[i] = i + 1.0f; //v�� �迭�̹Ƿ� �ε����� ����
	}

	printf("%f %f %f\n", pos.x, pos.y, pos.z);
	//����ü�� ���� �־����Ƿ� ���� ���� ������ �ִ�
	//���� x,y,z ����ε� ������ ���� �ִ�.
	
	/*
	struct Champion *swain = malloc(sizeof(struct Champion));
	swain->stats = malloc(sizeof(struct Stats));

	strcpy(swain->name, "Swain");
	swain->stats->health = 463.000000f;
	*/
	/*
	struct DeviceOption{
		union{
			struct{
				char boot;
				char interrupt;
			};
				short option;
		};
	};	
	*/

	return 0;
}