#define _CRT_SECURE_NO_WARNINGS 
//fopen 함수의 보안경고 방지 
#include <stdio.h>
#include <string.h>
int main()
{	
	/* 문자열을 파일에 쓰는 방법 -> fprintf를 사용하면 됨
	파일에 문자열을 쓸 때는 fopen 함수로 파일을 열어서 파일
	포인터를 얻은 뒤 fprintf 함수를 사용함
	FILE *포인터 이름 = fopen(파일명, 파일모드);
	성공하면 파일 포인터를 반환하고 실패하면 NULL을 반환함 
	보안경고가 발생하므로 #define _CRT_SECURE_NO_WARNINGS 넣기
	fprintf(파일 포인터, 서식, 값1, 값2, ...)
	성공하면 쓴 문자열의 길이를 반환하고 실패하면 음수를 반환함
	fclose(파일포인터)
	성공하면 O을 반환, 실패하면 EOF(-1)를 반환
	전부 stdio.h에 선언되있음
	여기서 FILE 구조체도 stdio.h에 정의되있으며 보통 FILE과 
	*를 합쳐서 파일 포인터라고 부름 
	*/

	FILE *fp = fopen("hello.txt", "w");
	/* 읽을 파일 이름 hello.txt로 지정하고 파일 모드는 w로 해줌
	파일 열기에 성공하면 파일 포인터를 반한하고 실패하면
	NULL을 반환함 
	파일모드-> "r": 읽기전용, 파일을 읽기전용으로 열음
	단 파일이 있어야함, "w": 쓰기 전용, 새 파일을 생성함, 만약
	파일이 있으면 내용을 덮어씀, "a": 추가, 파일을 열어 파일 
	끝에 값을 이어 씀, 만약 파일이 없으면 새로 생성함
	"r+": 읽기/쓰기, 파일을 읽기 쓰기용으로 열음, 단 파일이
	반드시 있어야 하며 파일이 없으면 NULL을 반환함
	"w+": 읽기/쓰기, 파일을 읽기/쓰기용으로 열음, 파일이
	없으면 파일을 생성하고 파일이 있으면 내용을 덮어씀 
	"a+": 추가(읽기/쓰기), 파일을 열어 파일 끝에 값을 이어씀
	만약 파일이 없으면 파일을 생성함, 읽기는 파일의 모든
	구간에서 가능하지만 쓰기는 파일의 끝에서만 가능함
	"t": 텍스트 모드, 파일을 읽거나 쓸때 개행문자 \n과 \r\n을
	서로 변환함, ^Z를 파일의 끝으로 인식하므로 ^Z까지만 파일을
	읽음, "b": 바이너리 모드: 파일의 내용을 그대로 읽고
	값을 그대로 씀
	파일 모드는 보통 "rb","rt", "w+b", "w+t"와 같이 읽기/쓰기
	모드와 텍스트/바이너리 모드를 조합해서 사용함
	*/
	fprintf(fp, "%s %d\n", "Hello", 100);
	//서식을 지정하여 문자열을 파일에 저장함

	fclose(fp);
	//파일 포인터 닫기 
	//파일 포인터 fp도 FILE 구조체 크기만큼 동적 메모리를 
	//할당한 것이기 때문에 안 닫으면 메모리 누수가 발생함
	//한 가지 특이한 점은 fprintf함수로도 화면에 문자열을
	//출력할 수 있는데 stdout이라는 매크로를 사용하면 됨

	fprintf(stdout, "%s %d\n", "hello", 100);

	char address1[200] = "C:\\securityStudy\\CLanguage";
	char address2[] = "\\난 할 수 있다.hwp";

	strcat(address1, address2);

	FILE *fp2 =fopen(address1, "w");
	fprintf(fp2, "%s %d%s\n", "난 현재", 21, "살이야");
	fclose(fp2);
	
	/*
	파일을 읽을 때도 fopen함수로 파일을 열어서 파일 포인터를
	얻은 뒤 fscanf 함수로 서식을 지정하여 파일의 내용을
	읽음 ,fscanf(파일포인터, 서식, 변수의 주소1, 변수의 주소2);
	성공하면 읽어온 값의 개수를 반환하고 실패하면 EOF(-1)를 
	반환함, fscanf함수는 stdio.h에 선언되어 있음		
	*/

	char s1[10];
	int num1;
	FILE *fp3 = fopen("hello.txt", "r");
	//hello.txt 파일을 읽기모드로 열어서 파일 포인터를 반환함

	fscanf(fp3, "%s %d", s1, &num1);
	//서식을 지정하여 파일에서 문자열을 읽어서 변수에 저장함
	printf("%s %d\n", s1, num1);
	fclose(fp3);
	//fclose 함수로 파일 포인터를 닫음 

	fscanf(stdin, "%s %d", s1, &num1);
	//fscanf 함수는 stdin을 이용하면 사용자가 입력한 값을 
	//변수에 저장할 수가 있음 

	printf("%s %d\n", s1, num1);
	
	/* fprintf, fscanf 등의 함수의 매개변수에서 파일 포인터
	부분을 보면 FILE* const_Stream과 같이 스트림이라고 되있음
	파일 포인터를 파일 스트림이라고 하며 파일 스트림도 파일의
	데이터를 연속적으로 처리함, 즉, 파일에서 데이터를 처리할
	때마다 매번 파일을 여는 것이 아니라 파일 스트림을 한 번
	생성해서 계속 데이터를 쓰거나 가져오는 방식임, fopen은
	입력 스트림, 쓰기 전용은 출력 스트림 , 읽기/쓰기 전용은 
	입출력 스트림에 해당함
	서식없이 파일에 문자열 쓰기-> fputs 함수를 이용하면 됨
	fputs(버퍼, 파일 포인터);	
	성공하면 음수가 아닌 값을 반환하고 실패하면 EOF(-1)를
	반환함, stdio.h 헤더파일에 선언되 있음
	*/

	FILE *fp4 = fopen("hello.txt", "w");
	//hello.txt 파일을 쓰기모드로 열음
	//파일 포인터를 반환함

	fputs("Hello, world!", fp4);
	//fputs는 파일에 쓸 문자열(배열이나 동적 메모리를 할당한
	//포인터도 가능함)과 파일 포인터를 넣어줌
	//이렇게 하면 "Hello, world!" 문자열만 hello.txt 파일에
	//저장이 됨

	fclose(fp4);

	fputs("Hello, world\n", stdout);

	/* 
	fwrite함수를 이용해서 문자열을 파일에 쓰기
	fwrite 함수는 stdio.h 헤더파일에 선언되있음
	fwrite(버퍼, 쓰기크기, 쓰기횟수, 파일 포인터);	
	성공하면 쓰기 횟수를 반환, 실패하면 지정된 쓰기 횟수보다
	작은 값을 반환함
	*/

	char *s2 = "Hello, world!!";

	FILE *fp5 = fopen("hello.txt", "w");

	fwrite(s2, strlen(s2), 1, fp5);
	//fwrite는 쓰기 크기와 쓰기 횟수를 지정해야됨
	//먼저 파일에 쓸 문자열의 포인터를 지정함 
	//그리고 쓰기 크기에는 문자열의 길이를 구해서 넣고 
	//쓰기 횟수에는 1을 넣음 
	//파일을 쓰는 크기는 쓰기크기 * 쓰기 횟수가 됨 

	fclose(fp5);
	//fclose 함수를 써서 파일 포인터를 닫아줌 
	//만약 fclose 함수를 쓰지 않으면 파일에 내용을 쓰더라도
	//완전히 저장되지 않을 수 있음 
	
	char *s3 = "Hello, world!!\n";

	fwrite(s3, strlen(s3), 1, stdout);

	/*
	파일에서 문자열 읽기, 파일을 읽을 때는 fopen함수로 파일을
	열어서 파일 포인터를 얻은 뒤 fgets 함수로 파일의 내용을
	읽음, stdio.h 에 선언되 있음
	fgets(버퍼, 버퍼크기, 파일 포인터)
	성공하면 읽은 문자열의 포인터를 반환, 실패하면 NULL을 반환
	*/


	char buffer[20];
	//파일을 읽을 때의 임시공간

	FILE *fp6 = fopen("hello.txt", "r");

	fgets(buffer, sizeof(buffer), fp6);
	printf("%s\n", buffer);

	fclose(fp6);

	FILE *fp7 = fopen("hello2.txt", "r");

	fgets(buffer, sizeof(buffer), fp7);
	//버퍼 크기를 20바이트로 지정한 뒤 파일을 읽으면 딱 버퍼
	//크기만큼만 읽음, 따라서 널 문자를 포함하여 20바이트를
	//읽으며 실제 문자열은 19바이트임 

	printf("%s\n", buffer);

	fclose(fp7);

	FILE *fp8 = fopen("hello3.txt", "r");

	fgets(buffer, sizeof(buffer), fp8);
	//줄바꿈(\n)이 있으면 버퍼 크기와는 상관없이 \n까지
	//문자열을 읽음 

	printf("%s\n", buffer);

	fclose(fp8);

	fgets(buffer, sizeof(buffer), stdin);
	fgets(buffer, sizeof(buffer), stdin);
	//\n까지 입력을 받음(널 문자 포함 버퍼 크기만큼 받음)

	printf("%s\n", buffer);

	/*
	fread 함수를 사용해서도 파일을 읽을 수가 있음
	fread(버퍼, 읽기크기, 읽기 횟수, 파일포인터);
	stdio.h에 선언되 있음, 성공하면 읽기 횟수를 반환하고
	실패하면 지정된 읽기 횟수보다 작은 값을 반환함 
	*/

	char buffer2[20] = { 0, };
	//파일을 읽을 때 사용할 임시공간(버퍼)을 선언해야 되는데
	//fread 함수를 사용할 때는 반드시 char 배열을 선언한 뒤
	//0으로 초기화 해야됨

	FILE *fp9 = fopen("hello.txt", "r");

	fread(buffer2, sizeof(buffer2), 1, fp9);
	/* fread 함수에서 파일을 읽는 크기는 읽기 크기 * 읽기 횟수 
	fread 함수는 \n과 상관없이 무조건 지정된 크기만큼 읽으며
	파일의 끝까지 읽음(지정된 크기 > 파일 크기)
	*/

	printf("%s\n", buffer2);

	fclose(fp9);

	/*
	만약 버퍼를 0(NULL)으로 초기화하지 않고 fread 함수로 파일을
	읽으면 "Hello, world!!" 이외에도 쓸데없는 값들이 함께
	출력됨, 왜냐하면 C 언어로 만든 문자열 포인터 및 문자열이
	저장된 배열은 끝에 NULL문자가 들어가 있지만 파일은 그렇지가 
	않음. 그러다 보니 파일에서 문자열만 읽어서 buffer에 
	가져오면 이전에 메모리에 저장되 있던 값과 합쳐지게 됨
	즉 문자열 끝에 NULL이 없어서 버퍼의 내용을 모두 출력하게됨
	fread 함수도 stdin을 지정하면 사용자가 입력한 문자열을 
	버퍼에 저장하게 됨 
	*/

	char buffer3[20] = { 0, };
	fread(buffer3, sizeof(buffer3) - 1, 1, stdin);
	//버퍼 끝에 널('\0'=NULL)이 들어갈 수 있도록 읽기 크기를 
	//sizeof(buffer) - 1을 지정해줌
	printf("%s\n", buffer3);

	/*
	stdin은 standard input, stdout은 standard output, stderr은
	standard error를 뜻하는데 보통 stdin은 키보드 입력,
	stdout과 stderr은 콘솔 출력임. 특히 C 언어에서 stdin,stdout
	stderr은 파일 포인터이므로 파일 포인터를 받는 함수들과 함께
	쓸수가 있음 
	
	*/
	return 0;
}