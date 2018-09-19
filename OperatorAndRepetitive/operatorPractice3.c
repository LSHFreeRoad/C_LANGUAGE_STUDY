#include<stdio.h>
#include<stdbool.h>
int main()
{
	/*불(boolean) 자료형은 논리 자료형이라고도 하며 참과
	거짓을 나타냄,  C 언어는 0을 거짓으로 0이 아닌 숫자를 참으로
	나타냄, stdbool.h 헤더파일을 사용하면 true를 참으로
	false를 거짓으로 나타낼 수가 있음
		
	*/
	
	bool b1 = true;

	if (b1 == true)	//b1이 true이므로 참이 됨
		printf("참\n");
	else
		printf("거짓\n");
	
	printf("int의 크기 : %zd\n", sizeof(int));
	printf("bool의 크기 : %zd\n", sizeof(bool));	
	//bool의 크기 :1바이트

	printf("%d\n", true && true);
	printf("%d\n", true && false);
	printf("%d\n", false && true);
	printf("%d\n", false && false);
	printf("=========================\n");
	//stdbool.h에는 자료형과 불값만 정의할 뿐 
	//전용 서식 지정자는 없음 
	printf("%d\n", true || true);
	printf("%d\n", true || false);
	printf("%d\n", false || true);
	printf("%d\n", false || false);
	printf("=========================\n");

	bool b2 = true;
	bool b3 = false;

	printf(b2 ? "true\n" : "false\n");
	printf(b3 ? "true\n" : "false\n");

	printf("%s\n", b2 ? "true" : "false");
	printf("%s\n", b3 ? "true" : "false");

	if (true)
		printf("참\n");
	else
		printf("거짓\n");

	if (false)
		printf("참\n");
	else
		printf("거짓\n");

	printf("%d\n", true);
	printf("%d\n", false);


	return 0;
}