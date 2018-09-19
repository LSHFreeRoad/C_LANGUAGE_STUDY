#include <stdio.h>
#include <stddef.h>

struct PacketHeader {
	char flags;
	int seq;
};
#pragma pack(push, 1)
struct PacketHeader1 {
	char flags;
	int seq;
};
#pragma pack(pop)
int main()
{
	/*
	����ü�� �޸𸮿� �ö��� �� ����� ������
	��ǻ���� CPU�� �޸𸮿� ������ �� 32��Ʈ�� 4����Ʈ ���� 
	64��Ʈ�� 8����Ʈ ������ ������
	32��Ʈ CPU���� 4����Ʈ���� ���������Ϳ� ������ ��� 
	���������� ����Ʈ ������ �߻��ؼ� ȿ���� ������(�Ȱ��� 4����Ʈ
	�� �о����) , �׷��� C ��� �����Ϸ��� CPU�� �޸��� �����Ϳ�
	ȿ�������� ������ �ֵ��� ����ü�� ������ ũ��� ������ �ϰ� ��
	���� ��� ����ü ũ�Ⱑ 15 �� 17����Ʈ�� �Ǹ� ���� ȿ���� 
	�������� �ǹǷ� 2, 4, 8, 16����Ʈ ������ ������ ��, ������ 
	������ ���ĵǸ� ������ �ǰ� ��Ʈ��ũ �����͵� ������ ��
	�� ����Ʈ�� � ������ ������ �Ծ��� ���س�����
	���� ������ �Ǹ� �޴� �ʿ��� �����͸� �˾ƺ� �� ���Ե�
	sizeof(struct ����ü)
	sizeof(����ü ��Ī)
	sizeof(����ü ����)
	*/
										
	struct PacketHeader header;

	printf("%llu\n", sizeof(header.flags));
	printf("%llu\n", sizeof(header.seq));
	printf("%llu\n", sizeof(header));
	printf("%llu\n", sizeof(struct PacketHeader));
	
	//C ������ ���� ū �ڷ��� ũ���� ����� ������ ��
	//���⼱ int�� ���� ū �ڷ����̹Ƿ� int�� ũ�� 4����Ʈ�� 
	//�������� ������, 4����Ʈ�� �����ؼ� flags�� seq�� ��� 
	//���� �ּ�ũ��� 8����Ʈ��, 1����Ʈ ũ���� char flags �ڿ�
	//4����Ʈ�� ���߱� ���� �ڿ� 3����Ʈ�� �� ���Ե�. 
	//���� ������ ä��� ���� �е��̶�� ��, ����ü���� �����
	//��ġ�� ���� ���� offsetof ��ũ�θ� �����, stddef.h�� ����� 

	//offsetof(struct ����ü, ���);
	//offsetof(����ü��Ī, ���);

	printf("%llu\n", offsetof(struct PacketHeader, flags));
	printf("%llu\n", offsetof(struct PacketHeader, seq));

	/*
	����ü ������ ���� �ʴ� �����? 
	c������ ����ü�� �����ϴ� ǥ�� ����� ���� -> �� �����Ϸ�
	���� �����ϴ� Ư���� �����ڸ� ����ϸ� ����ü ���� ũ�⸦
	������ �� ����
	visual studio , gcc 4.0 �̻��� #pragma pack(push, ����ũ��)
	#pragma pack(pop) , GCC 4.0 �̸��� __attribute__((aligned(����
	ũ��), packed))
	pragma�� �׸������ action�̶�� �ǹ� �����Ϸ��� �ൿ ���� 	
	*/

	struct PacketHeader1 header1;

	printf("%llu\n", sizeof(header1.flags));
	printf("%llu\n", sizeof(header1.seq));
	printf("%llu\n", sizeof(header1));

	//pack�� 1����Ʈ ������ �����ϰ� �Ǹ� ���� �������� �ڷ���
	//ũ�� �״�� �޸𸮿� �ö󰡰� ��
	//#pragma pack(push, 1)�� �� �� ����ϸ� �� �Ʒ��� ����
	//��� ����ü�� ������ �ֹǷ� ���� ������ �� �ڿ� 
	//#pragma pack(pop)�� ����Ͽ� ���� ���·� �ǵ��� 

	printf("%llu\n", offsetof(struct PacketHeader1, flags));
	printf("%llu\n", offsetof(struct PacketHeader1, seq));

	//2����Ʈ ������ �����ϸ� �� 6����Ʈ�� ��
	//4����Ʈ ������ �����ϸ� �� 8����Ʈ�� ��

	return 0;
}