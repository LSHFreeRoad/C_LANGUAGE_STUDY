#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Point2D {
	int x;
	int y;
};

int main()
{
	struct Point2D p1;

	/*����ü�� �޸� �Լ� ����ϱ�
	����ü�� ����� ��� 0���� ������� ������ �� 0���� �ʱ�ȭ ����
	struct ����ü �̸� ���� �̸�={ 0 ,};
	������ �̰��� �������� ����� �� �ְ� malloc�Լ��� �Ҵ���
	�޸𸮿��� ����� ���� ����
	����ü ������ �޸��� ������ �Ѳ����� ���� �����Ϸ��� memset
	�Լ��� ����ϸ� ��
	memset(����ü ������,  ������ ��, sizeof(struct ����ü));
	*/

	memset(&p1, 0, sizeof(struct Point2D));
	//�ּ� �����ڸ� ����Ͽ� ������ �޸� �ּҸ� ���ؼ� �־���
	//�׸��� ������ ���� ũ�⸦ �־��� 
	//�޸��� ũ�� ������ 1����Ʈ��
	printf("%d %d\n", p1.x, p1.y);

	struct Point2D *p2 = malloc(sizeof(struct Point2D));
	memset(p2, 0, sizeof(struct Point2D));
	//memset �Լ��� �޸𸮿� ���� ������ ���� �����͸� �״�� ����
	//�ֳ��ϸ� �����ʹ� �ȿ� �޸� �ּҸ� ��� �־ &�� �� 
	//�ʿ䰡 ����
	printf("%d %d\n", p2->x, p2->y);
	free(p2);

	/*����ü�� �޸��� ���� ������ �� 
	memcpy(��� ������, ���� ������, ũ��); ������ �����͸� ��ȯ��
	memory copy���� ����, string.h ��� ����
	*/

	struct Point2D p3;
	struct Point2D p4;

	p3.x = 10;
	p3.y = 20;

	memcpy(&p4, &p3, sizeof(struct Point2D));
	//����ü ���� �տ� &�� ����Ͽ� ������ �޸� �ּҸ� ���ؼ�
	//�־���, ���������� ������ ũ�⸦ �־��ִµ� ���⼭�� ����ü
	//ũ�⸦ ���ؼ� �־��ָ� ��

	printf("%d %d\n", p4.x, p4.y);

	struct Point2D *p5 = malloc(sizeof(struct Point2D));
	struct Point2D *p6 = malloc(sizeof(struct Point2D));

	p5->x = 30;
	p5->y = 40;

	memcpy(p6, p5, sizeof(struct Point2D));

	printf("%d %d\n", p6->x, p6->y);

	free(p6);
	free(p5);


	return 0;
}

