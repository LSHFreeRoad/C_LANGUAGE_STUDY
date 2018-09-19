#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	/*
	if, else는 조건식이 참, 거짓일 때 두 가지만 처리할 수
	있음, else if는 여러 조건을 처리할 수 있지만 매번 
	조건식을 지정해야 하는 번거로움이 있음
	switch문은 조건이 많아도 손쉽게 처리할 수가 있음
	switch(num1)<-- 값을 판단할 변수
	{
	case 1: //num1이 1일 때 실행 
		printf("1입니다.\n");
		break;
	case 2: //num1이 2일 때 실행
		printf("2입니다.\n");
		break;
	defalut: //아무 case에도 해당하지 않을 때 실행함
		printf("3입니다.\n");
		break;
		//defalut는 생략이 가능함
	}

	*/


	int num1;

	scanf("%d", &num1);
	//조건식이 바뀌지 않고 값만 바뀔 때는 switch문이 적절함
	switch (num1) //괄호 안에 값을 판단할 변수
	{
	case 1:	//num1이 1일 때 
		printf("1입니다.\n");
		break;
	case 2:	//num1이 2일 떄 
		printf("2입니다.\n");
		break;
	default:	//아무 case에도 해당되지 않을 때 
		printf("default\n");
		break;
	}

	//값과 조건식이 모두 바뀔 때는 else if가 적절함 
	if (num1 == 1)
		printf("1입니다.\n");
	else if (num1 == 2)
		printf("2입니다.\n");
	else
		printf("default\n");

	

	int num2;

	scanf("%d", &num2);
	//조건식이 바뀌지 않고 값만 바뀔 때는 switch문이 적절함
	switch (num2) //괄호 안에 값을 판단할 변수
	{
	case 1:	//num2이 1일 때 
		printf("1입니다.\n");
	case 2:	//num2이 2일 떄 
		printf("2입니다.\n");
	default:	//아무 case에도 해당되지 않을 때 
		printf("default\n");
	}
	//case를 중단하지 않으면 그 다음에 있는 case가 계속 실행
	//됨, 이런 상황을 fall through라고 부르며 "구멍 사이로
	//떨어지다"에서 유래한 말임
	//default 다음에는 실행할 case가 없으므로 
	//break를 넣어도되고 안 넣어도 됨 

	int num3, num4;

	scanf("%d", &num3);
	//조건식이 바뀌지 않고 값만 바뀔 때는 switch문이 적절함
	switch (num3) //괄호 안에 값을 판단할 변수
	{
	case 1:	//num3이 1일 때 
	case 2:	//num3이 2일 때
		printf("1 또는 2입니다.\n");
		break;
	case 3:	//num3이 3일 때 
	case 4:	//num3이 4일 때 
		printf("3 또는 4입니다.\n");
		break;
	default:	//아무 case에도 해당되지 않을 때 
		printf("defalut\n");
		break;
	}
	//case에서 break 값을 생략하면 여러가지 값으로 같은 코드
	//를 실행시킬 수가 있음 

	scanf("%d", &num4);
	if (num4 == 1 || num4 == 2)
		printf("1 또는 2입니다.\n");
	else if (num4 == 3 || num4 == 4)
		printf("3 또는 4입니다.\n");
	else
		printf("default\n");
	//if, else if는 일일이 조건식을 나열해야 되서 처리할
	//숫자가 많아지면 매우 번거로워짐-> 이럴 때는
	//case에서 break를 생략하는 방식이 유용함


	//case에서 변수를 선언하려면 중괄호로 묶어줘야됨
	//case에서 선언한 변수는 case안에서만 사용이 가능하고 
	//case 밖에서나 switch문 밖에서는 사용이 안 됨

	int num5;

	scanf("%d", &num5);
	//조건식이 바뀌지 않고 값만 바뀔 때는 switch문이 적절함
	switch (num5) //괄호 안에 값을 판단할 변수
	{
	case 1: {	//num5가 1일 때
		int num6 = 3;
		printf("1입니다.\n");
		break;
	}
	case 2:	//num5가 2일 때 
		printf("2입니다.\n");
		break;
	default:	//아무 case에도 해당되지 않을 때 
		printf("default\n");
	}

	//switch에 판별할 수 있는 자료형은 정수 자료형만 가능
	//정수 자료형인 char도 가능함, 실수나 문자열 등은 안 됨

	char c1,c2;
	scanf("%c", &c2);
	scanf("%c", &c1);

	switch (c1)
	{
	case 'a':
		printf("a입니다.\n");
		break;
	case 'b':
		printf("b입니다.\n");
		break;
	default:
		printf("default\n");
		break;
	}

	return 0;
}