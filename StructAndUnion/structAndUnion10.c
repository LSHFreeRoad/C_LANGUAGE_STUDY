#include <stdio.h>

enum DayOfWeek {
	Sunday = 0,
	Monday,	//1
	Tuesday, //2
	Wendesday,	//3
	Thursday,	//4
	Friday,	//5
	Saturday	//6
	//열거형의 값은 처음에만 할당해주면 그 아래에 오는 값들은
	//1씩 증가하면서 자동으로 할당됨, 아무것도 할당하지 않으면
	//0부터 시작함
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
	열거형은 정수형 상수에 이름을 붙여서 코드를 이해하기 쉽게 해줌
	열거형은 enum키워드로 정의함
	열거, 목록을 의미하는 enumeration에서 따옴
	열거형도 정의만 해서는 사용할 수 없고 열거형도 변수로
	선언해서 사용함
	enum 열거형이름{
		값1 = 초깃값,
		값2,
		값3
		.
		.
		.
	};
	*/

	enum DayOfWeek week; //열거형 변수 선언 

	week = Tuesday; //열거형 변수에는 미리 정의한 열거형 값을 넣음

	printf("%d\n", week);

	/*
	열거형 이름이나 값을 정의할 때 대문자만 사용하는 경우가 많음
	특히 단어와 단어 사이에는 _을 붙임
	열거형도 typedef로 열거형 별칭을 지정하고 익명 열거형을
	정의할 수 있음, 열거형을 정의하는 동시에 변수 선언이 가능함
	switch(열거형 변수)
	{
	case 열거형값;
		실행할 코드;
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
	//프로그램은 1, 2, 3, 4로 처리하고 사람은 스킬이름을 보고
	//사용하는 방식, 여기서는 skill에 LightBinding을 할당했으므로
	//case LightBinding: 이 실행됨

	for (DayOfWeek2 i = Sunday2; i < DayOfWeekCount; i++)
	{
		printf("%d\n", i);
	}//열거형 값 Sunday부터 Saturday까지 반복할 수 있음 

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