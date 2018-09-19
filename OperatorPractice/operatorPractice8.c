#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	//int kor, eng, math, science, avg;
	//scanf("%d %d %d %d", &kor, &eng, &math, &science);

	//if (0 <= kor && kor <= 100 && 0 <= eng && eng<= 100 && 0 <= math && math <= 100 && 0 <= science && science <= 100)
	//{
	//avg = (kor + eng + math + science) / 4;
	//	if (85 <= avg)
	//		printf("합격\n");
	//	else
	//		printf("불합격\n");
	//}
	//else
	//	printf("잘못된 점수\n");

	int balance = 10000;
	int age;

	scanf("%d", &age);

	if (7 <= age && age <= 12)
	{
		balance -= 450;
	}
	else if (13 <= age && age <= 18)
	{
		balance -= 720;
	}
	else if (19 <= age)
		balance -= 1200;

	printf("%d\n", balance);

	return 0;
}