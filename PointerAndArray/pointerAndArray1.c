#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main()
{
	/*
	중간의 코드는 무시하고 건너뛸 때 goto 제어문을 사용함
	goto를 적절히 활용하면 중복되는 코드를 없애고 코드를
	좀 더 간결하게 만들 수 있다. 특히 에러 처리에 유용함
	*/
		int num1;
	
		scanf("%d", &num1);
		if (num1 == 1)	//num1이 1이면 레이블 ONE으로 이동
			goto ONE;
		else if (num1 == 2) //num1이 2이면 레이블 TWO로 이동 
			goto TWO;
		else
			goto THREE;
	
	ONE:	//레이블 ONE
		printf("1입니다.\n");
		goto THREE;
	TWO:	//레이블 TWO
		printf("2입니다.\n");
		goto THREE;
	THREE:	//레이블 EXIT
		printf("");
	
		
	int num2 = 0;

	bool exitOuterLoop = false;
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (num2 == 20)
			{
				exitOuterLoop = true;
				break;
			}
			num2++;
		}

		if (exitOuterLoop == true)
			break;
	}

	printf("%d\n", num2);

		int num3 = 0;
	
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (num3 == 20)
					goto EXIT;
					
				num3++;
			}
	
		}
	
	EXIT:
		printf("%d\n", num3);



	int gender;
	int age;
	int temp;
	bool isOwner;

	scanf("%d %d %d", &gender, &age, &temp);
	//성별 : 남자 1, 여자 2, 나이, 주택 소유 여부 : 자가 1
	//전월세 : 0
	isOwner = temp;

	printf("안녕하세요.\n");
	printf("문을 연다.\n");

	if (gender == 2)
		goto FINISH;

	if (age < 30)
		goto FINISH;

	if (isOwner == false)
		goto FINISH;

	
	FINISH:
		if (gender == 1 && age == 30 && isOwner == 1)
			goto SUCCESS;
			printf("안녕히계세요.\n");
			printf("문을 닫는다.\n");

	SUCCESS:
		if (gender == 1 && age == 30 && isOwner == 1)
			printf("제가 찾으시는 분이 맞군요!\n");
	
	return 0;

}
