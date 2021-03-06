#include<stdio.h>
int main()
{
	/*
	c언어에는 문자열을 저장하는 자료형은 없음
	char s1 = "Hello";
	printf("%s", s1); 컴파일은 되지만 실행에러가 발생함
	문자열은 char 포인터 형식으로 사용함
	char * 변수이름 = "문자열";
	문자는 1바이트 크기의 char에 저장할 수 있음
	문자열은 크기가 1바이트를 넘어서므로 char에 저장할 수 없고
	따라서 변수에 직접 저장하지 않고 포인터를 이용해서 저장함
	이때 문자열은 메모리에 저장되 있고 포인터에는 문자열의 메모리
	주소만 저장됨. 문자열 리터럴이 있는 메모리 주소는 읽기 전용
	이므로 다른 문자열을 덮어쓸 수 없음, 또한 문자열 리터럴이 저장
	되는 위치는 컴파일러가 알아서 결정함, 문자열을 출력할 때는
	서식 지정자 %s를 사용하면 됨. 문자열은 마지막에 항상
	널 문자(NULL ='\0')가 붙게되며 문자열의 끝을 나타냄
	문장 끝에 마침표를 찍는 것처럼 C 언어는 문자열 끝에 널 문자를
	붙이자고 정함. 하지만 널 문자는 눈에 보이지 않음
	보통 문자열은 시작되는 쪽을 앞 끝나는 쪽을 뒤라고 부름
	하지만 실제로 메모리 주소를 다루는 포인터 연산에서는 낮은
	주소가 뒤쪽 , 높은 주소가 앞쪽이다. 그래서 뒤쪽으로 가는 것을
	역방향, 앞쪽으로 가는 것을 순방향이라고 한다. 여기서 문자열은
	메모리의 낮은 주소부터 시작해서 높은 주소까지 저장되는데 
	그러면 문자열이 시작되는 부분이 뒤, 끝나는 부분이 앞이 되버림
	메모리 주소의 앞뒤와 구분하기 위해 문자열은 왼쪽, 오른쪽
	처음, 마지막이라는 말을 자주 사용함
	*/

	char c1 = 'a';
	char *s1 = "Hello";
	printf("%c\n", c1);
	printf("%s\n", s1);

	printf("%c\n", s1[1]);	//e: 인덱스 1의 문자 출력
	printf("%c\n", s1[4]);	//o: 인덱스 4의 문자 출력
	printf("%c\n", s1[5]);  //'\0'(NULL 문자) 출력됨

	//문자열 포인터에 인덱스로 접근해서 문자를 할당하려면
	//에러가 발생하게 된다. 왜냐하면 문자열 리터럴이 있는 메모리
	//주소는 읽기 전용이기 때문이다.
	//문자열은 문자(char) 배열에 저장할 수도 있다
	//char 배열이름[크기] = "문자열";																							
														
	char s2[10] = "Hello";	//크기가 10인 char형 배열을 선언한
	//후에 문자열을 할당함
	//문자열을 배열에 저장하는 방식은 배열 요소 하나하나에 문자가
	//저장되게 됨. 문자열의 맨 뒤에는 NULL이 들어감 
	//문자열과 NULL을 저장한 뒤에 남는 요소들에는 보통
	//NULL이 들어감
	printf("%s\n", s2);
	
	//배열로 문자열을 사용할 때 주의할 점은 배열을 선언한 즉시
	//문자열로 초기화해야 한다는 점이다.
	//이미 선언된 배열에는 문자열을 할당할 수 없음
	//정 할당하고 싶으면 배열의 요소 하나하나에 문자를
	//집어넣으면 됨. 또는 문자열 관련 함수를 사용하면 됨
	//배열을 선언할 때는 할당할 문자열보다 크게 지정해야됨

	char s3[6] = "Hello";

	//배열에 문자열을 할당할 때 배열의 최소 크기는
	//문자 개수 + NULL하나 

	//문자 배열을 선언하면서 문자열을 바로 할당할 때는 	
	//배열의 크기를 생략할 수 있다. 그리고 이때 배열의 크기는
	//할당되는 문자열의 문자 개수 + NULL 하나가 됨
	
	char s4[] = "Hello";
	printf("s4 배열의 크기: %llu\n", sizeof(s4));

	char s5[10] = "Hello";

	printf("%c\n", s5[1]);
	printf("%c\n", s5[4]);
	printf("%c\n", s5[5]);

	//배열 형태의 문자열은 인덱스로 접근하여 내용을 변경할 수가
	//있는데 배열에 문자열이 모두 복사되기 때문임

	s5[0] = 'A';

	printf("%s\n", s5);



	return 0;
}
