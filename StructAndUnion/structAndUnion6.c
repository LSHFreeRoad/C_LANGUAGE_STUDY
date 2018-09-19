#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

struct Point2D {
	int x;
	int y;
};

struct Person {
	char name[30];
	int age;
};

int main()
{
	/*
	����ü �迭 
	struct ����ü �̸� ���� �̸�[ũ��]
	*/
		
	struct Point2D p[3];

	p[0].x = 10;
	p[0].y = 20;
	p[1].x = 30;
	p[1].y = 40;
	p[2].x = 50;
	p[2].y = 60;

	printf("%d %d\n", p[0].x, p[0].y);
	printf("%d %d\n", p[1].x, p[1].y);
	printf("%d %d\n", p[2].x, p[2].y);

	//�ε����� ��ҿ� ������ �� ������ ����� ������ 

	/*
	����ü �迭�� �����ϸ鼭 �ʱ�ȭ�� �ҷ��� {} �ȿ� �߰�ȣ��
	����ϸ� ��, struct ����ü�̸� �����̸�[ũ��] 
	={{.����̸�1 = ��1, .����̸�2 = ��2},
	{ .����̸�1 = ��3, .����̸�2 = ��4} };
	struct ����ü�̸� �����̸�[ũ��] = {{��1 ,��2 } 
	, {��3 ,��4 }};
	*/

	struct Point2D p1[3] = { {.x = 15,.y = 25}, {.x = 35,.y = 45},
	{.x = 55,.y = 65} };

	printf("%d %d\n", p1[0].x, p1[0].y);
	printf("%d %d\n", p1[1].x, p1[1].y);
	printf("%d %d\n", p1[2].x, p1[2].y);

	struct Point2D p2[3] = { { 13, 23 },{ 33, 43 },
	{ 53, 63 } };

	printf("%d %d\n", p2[0].x, p2[0].y);
	printf("%d %d\n", p2[1].x, p2[1].y);
	printf("%d %d\n", p2[2].x, p2[2].y);

	struct Point2D *p3[3];
	//����ü ������ �迭 ����

	for (int i = 0; i < sizeof(p3) / sizeof(struct Point2D *); i++)
	{
		p3[i] = malloc(sizeof(struct Point2D));
	}
	//�迭ũ��(��� ����)��ŭ �ݺ��ϸ鼭 �� ��ҿ� ����ü ũ�⸸ŭ
	//�޸𸮸� �Ҵ�����, ��� ������ ���Ϸ��� ����ü ������ �迭
	//��üũ�⿡�� ����ü ������ ũ��� �����ָ� ��
	//sizeof(p3) -> ����ü ������ �迭ũ��
	//sizeof(struct Point2D *) -> ����ü ������ ũ��

	p3[0]->x = 11;
	p3[0]->y = 21;
	p3[1]->x = 31;
	p3[1]->y = 41;
	p3[2]->x = 51;
	p3[2]->y = 61;

	//����ü ������ �迭���� �� ��ҿ� �����Ϸ��� �迭 �ڿ�
	//���ȣ�� ����Ͽ� ���ȣ �ȿ� �ε����� �������ָ� ��
	//�迭�ȿ� ����ִ� ��Ұ� �������̹Ƿ� ȭ��ǥ �����ڸ�
	//����Ͽ� ����� �����ؾ��� 

	printf("%d %d\n", p3[0]->x, p3[0]->y);
	printf("%d %d\n", p3[1]->x, p3[1]->y);
	printf("%d %d\n", p3[2]->x, p3[2]->y);

	//����ü ������ �迭�� ����� ������ �޸𸮸� ������

	for (int i = 0; i < sizeof(p3) / sizeof(struct Point2D *); i++)
	{
		free(p3[i]);
	}
	
	
	//size_t �ڷ����� ��ȣ ���� ���� �ڷ����̰� sizeof �����ڳ�
	//offsetof ��ũ���� ����� size_t�̴�.
	//size_t�� ����� ���� ���������ڿ� z�� ����
	size_t size = sizeof(int);
	size_t offset = offsetof(struct Point2D, x);
	//size_t�� 32��Ʈ������ 4����Ʈ, 64��Ʈ������ 8����Ʈ�� ���ǵ�

	printf("%zd %zd\n", size, offset);
	//����ü���� ����� ��ġ�� ���� ���� offsetof ��ũ�θ� �����
	//stddef.h�� �����. offsetof(struct ����ü, ���);
	//offsetof(����ü��Ī, ���);
	
	
	
	return 0;
}


/*
	double d[9];
	for(int i =0, j = 0; i < (sizeof(d) /sizeof(d[0])); i+= 3, j++)
	{	d[i] = p[j+1].x - p[j].x; 
		d[i+1] = p[j+1].y - p[j].y;
		d[i+2] = sqrt((d[i] * d[i]) + (d[i+1] * d[i+1]));
	}

	length = d[2] + d[5] + d[8];
*/	

/*	
	for(int i =0 ; i < (sizeof(p) /sizeof(struct Point2D)) - 1; i++)
	{	length += sqrt(pow((p[i+1].x - p[i].x) , 2) +
	pow((p[i+1].y - p[i].y) , 2));	
	}
*/


/*

	for(int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
		p[i] = malloc(sizeof(struct Person));

	scanf("%s %d %s %d %s %d %s %d %s %d", p[0]->name, &(p[0]->age),
	p[1]->name, &(p[1]->age), p[2]->name, &(p[2]->age)
	p[3]->name, &(p[3]->age), p[4]->name, &(p[4]->age));
	
	struct Person *temp;

	for(int i =0; i < sizeof(p) / sizeof(struct Person *) - 1; i++)
	{
		if(p[i]->age > p[i+1]->age)
		{	temp = p[i];
			p[i] = p[i+1];
			p[i+1] = temp;
		}
	}
	printf("%s\n", p[4]->name);

	for (int i = 0; i < sizeof(p) / sizeof(struct Person *); i++)
	{	free(p[i]);
	}

*/




