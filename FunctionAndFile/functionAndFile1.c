#include <stdio.h>
#include <stdarg.h>

void printNumbers(int args, ...)
{
	va_list ap;

	//...으로 들어온 가변 인자를 사용하려면 stdarg.h 헤더파일에
	//정의된 매크로를 사용해야됨

	/*
	va_list: 가변 인자 목록. 가변인자의 메모리 주소를 저장하는
	포인터, va_start: 가변 인자를 가져올 수 있도록 포인터를 설정함
	va_arg: 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옴
	va_end: 가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화
	함수를 정의할 때 첫 번째 매개변수에 가변 인자의 개수를 받을 수
	있도록 지정하고, 두 번째 매개변수 부분에서 가변 인자를 줄 수
	있도록 ...으로 지정함
	*/

	va_start(ap, args);
	//printNumbers(4, 10, 20, 30, 40);을 호출한 뒤 va_start 
	//매크로를 실행하면 ap는 가변인자의 시작부분을 가리킴

	for (int i = 0; i < args; i++)
	{
		int num = va_arg(ap, int);
		//이제 반복문으로 가변 인자 개수만큼 반복하면서 va_arg
		//매크로로 값을 가져오면 됨. 이때 va_arg에는
		//가변 인자의 자료형을 지정해줌

		//int num = va_arg(ap, int);을 실행하면 현재 ap에서 
		//4바이트 크기만큼 역참조하여 값을 가져온 뒤 ap를 4바이트
		//만큼 순방향으로 이동시킴. 10을 가리키고 있던 ap가 20을
		//가리키게됨

		printf("%d ", num);
	}
	va_end(ap);
	//가변 인자 목록 포인터를 NULL로 초기화
	//인텔/AMD x86, x86-64 플랫폼에서는 va_end 매크로를 사용하지
	//않아도 동작에 지장이 없지만 다른 플랫폼에서는 문제가 생길 수
	//있으니 호환성을 위해 작성하는 것이 좋음

	printf("\n");
}

void printValues(char *types, ...)
{	
	//가변인자의 자료형으로 받음, ...으로 가변인자 설정 
	va_list ap;
	//가변 인자 목록 포인터 선언;
	int i = 0;
	va_start(ap, types);
	/*va_start 매크로는 문자열을 넣으면 문자의 개수를 구해서
	포인터를 설정해줌
	"Hello, world!"는 문자열이기 때문에 그대로 들어가지 않고
	문자열의 메모리 주소가 들어감*/ 
	while(types[i] != '\0')
	{/* types의 문자가 '\0'(NULL)이 아닐때까지 반복함
	types는 문자열이기 때문에 반드시 NULL로 끝남
	switch 분기문을 사용하여 types에 들어있는 문자로 분기한 뒤
	va_arg로 ap에서 자료형 크기만큼 값을 가져옴  
	예를 들어 "Hello, world!" 같은 경우에는 ap를 역참조해서 
	char 포인터 크기 만큼 값을 가져오고 ap를 char 포인터 크기만큼
	순방향으로 이동함
	*/

		switch (types[i])
		{
		case 'i':
			printf("%d ", va_arg(ap, int));
			break;
		case 'd':
			printf("%f ", va_arg(ap, double));
			break;
		case 'c':
			printf("%c ", va_arg(ap, char));
			break;
		case 's':
			printf("%s ", va_arg(ap, char *));
			break;
		default:
			break;
		}
		i++;
	}
	va_end(ap);

	printf("\n");
}

int main()
{
	/*
	printf나 scanf와 같이 매개변수의 개수가 정해지지 않은 함수가
	있는데 이렇게 함수에 들어가는 인자의 개수가 변하는 것을 
	가변 인자(수)라고함, 가변인자 함수 만들어보기 
	반환값 자료형 함수이름(자료형 고정매개변수,...)
	{
	}
	함수에서 가변인자를 정의할 때는 고정매개변수가 한 개 이상 
	있어야 하며 고정 매개변수 뒤에 ...을 붙여 매개변수의 개수가
	정해지지 않았다는 표시를 해줌, 단... 뒤에는 다른 매개변수를
	지정할 수 없음 
	*/

	printNumbers(1, 10);
	printNumbers(2, 10, 20);
	printNumbers(3, 10, 20, 30);
	printNumbers(4, 10, 20, 30 ,40);
	//처음에 오는 4는 매개변수 args에 들어갈고 나머지 값들은 ...
	//부분에 들어감 

	/*
	자료형이 다른 가변 인자 처리해보기
	switch와 가변 인자를 함께 사용하면 됨, 가변 인자를 처리할 때
	사용할 각 자료형 약칭, int->i, double->d, char->c, char *->s	
	*/

	printValues("i", 10);
	printValues("ci", 'a', 10);
	printValues("dci", 1.234567, 'a', 10);
	printValues("sicd", "Hello, world!", 10, 'a', 1.234567);

	//함수를 호출할 때 가변인자 자료형의 약칭을 순서대로 넣어줌
	//그리고 자료형 약칭의 개수에 맞게 가변인자를 콤마로 구분해서
	//순서대로 넣어주면 됨

	/*
	
	va_list ap;
	
	va_start(ap, args);
	int result = 0;
	
	for(int i = 0; i < args; i++)
	{	
		result += va_arg(ap, int);
	}

	va_end(ap);	

	return result;
	*/

	/*
	int getSum(char * args, ...)
	{
		va_list ap;

		int i = 0, result = 0;

		va_start(ap, args);

		while(args[i] != '\0')
		{
			switch(args[i])
			{
			case 'i':
				result += va_arg(ap, int);
				break;
			case 'd':
				va_arg(ap, double);
				break;
			case 's':
				va_arg(ap, char *);
				break;
			default:
				break;
			}
		i++;
		}

		return result;

	}
	*/
		
	return 0;
}
