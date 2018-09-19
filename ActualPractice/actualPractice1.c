#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#pragma pack(push,1)
typedef struct _BITMAPFILEHEADER	//BMP 파일 헤더 구조체 
{
	unsigned short bfType;	//BMP 파일 매직 넘버
	unsigned int bfSize;	//파일 크기
	unsigned short bfReserved1;	//예약
	unsigned short bfReserved2;	//예약
	unsigned int bfOffBits;	//비트맵 데이터의 시작 위치 

} BITMAPFILEHEADER;

typedef struct _BITMAPINFOHEADER	//BMP 비트맵 정보 구조체(DIB 헤더)
{
	unsigned int biSize;	//현재 구조체의 크기
	int biWidth;	//비트맵 이미지의 가로 크기
	int biHeight;	// 비트맵 이미지의 세로 크기
	unsigned short biPlanes;	//사용하는 색상판의 수 
	unsigned short biBitCount;	//픽셀 하나를 표현하는 비트 수
	unsigned int biCompression;	//압축 방식
	unsigned int biSizeImage;	//비트맵 이미지의 픽셀 데이터 크기
	int	biXPelsPerMeter;	//그림의 가로 해상도(미터당 픽셀)
	int biYPelsPerMeter;	//그림의 세로 해상도(미터당 픽셀)
	unsigned int biClrUsed;	//색상 테이블에서 실제 사용되는 색상 수
	unsigned int biClrImportant;	//비트맵을 표현하는데 필요한 색상 인덱스 수
} BITMAPINFOHEADER;

typedef struct _RGBTRIPLE	//24비트 비트맵 이미지의 픽셀 구조체
{
	unsigned char rgbBlue;	//파랑
	unsigned char rgbGreen;	//초록
	unsigned char rgbRed;	//빨강
} RGBTRIPLE;
#pragma pack(pop)

#define PIXEL_SIZE 3 //픽셀 한 개의 크기(3바이트)
#define PIXEL_ALIGN 4	//픽셀 데이터 가로 한 줄은 4의 배수 크기로 정렬됨 

int main()
{
	/*
	비트맵 그림 파일(.bmp)의 픽셀 정보를 읽어서 아스키 아트로
	출력하는 프로그램 만들어보기
	비트맵 파일에서 픽셀 정보를 읽으려면 먼저 비트맵 파일의
	구조를 알아야함.
	비트맵 파일의 구조(픽셀당 16, 24, 32비트)
	14바이트 -> 파일 헤더(비트맵 파일 식별정보, 파일 크기, 데이터 위치 등의 정보)
	40바이트 -> 비트맵 정보(DIB 헤더)(가로 및 세로 크기, 해상도, 픽셀의 비트 수 등 그림의 자세한 정보)
	가변 -> 픽셀 데이터(그림 파일의 실제 색상 정보)
	파일 헤더의 구조
	멤버		크기(바이트)		설명
	bfType		2					BMP 파일 매직 넘버. 비트맵 파일이 맞는지 확인하는데 사용하며 ASCII
									코드로 0x42(B), 0x4D(M)가 저장됨
	bfSize		4					파일 크기(바이트)
	bfReserved1 2					현재는 사용하지 않으며 미래를 위해 예약된 공간
	bfReserved2 2					현재는 사용하지 않으며 미래를 위해 예약된 공간
	bfOffBits 4						비트맵 데이터의 시작 위치

	비트맵 정보의 구조
	멤버		크기(바이트)	설명
	biSize		4				현재 비트맵 정보(BITMAPINFOHEADER)의 크기
	biWidth		4				비트맵 이미지의 가로 크기(픽셀)
	biHeight	4				비트맵 이미지의 세로 크기(픽셀). • 양수: 이미지의 상하가 뒤집혀서 저장된 상태
								• 음수: 이미지가 그대로 저장된 상태, 보통 세로 크기는 양수로 저장되어 있음
	biPlanes	2				사용하는 색상판의 수. 항상 1임
	biBitCount	2				픽셀 하나를 표현하는 비트 수
	biCompression 4				압축 방식. 보통 비트맵은 압축을 하지 않으므로 0임
	biSizeImage	  4				비트맵 이미지의 픽셀 데이터 크기(압축 되지 않은 크기)
	biXPelsPerMeter 4			그림의 가로 해상도(미터당 픽셀)
	biYPelsPerMeter 4			그림의 세로 해상도(미터당 픽셀)
	biClrUsed		4			색상 테이블에서 실제 사용되는 색상 수
	biClrImportant  4			비트맵을 표현하기 위해 필요한 색상 인덱스 수

	24비트 비트맵은 픽셀(RGBTRIPLE)을 파랑, 초록, 빨강 순서로 저장하며 각 색상의 크기는 1바이트임
	따라서 픽셀당 3바이트를 사용함
	24비트 비트맵의 픽셀 구조
	멤버	크기(바이트)	설명
	rgbtBlue  1				파랑
	rgbtGreen 1				초록
	rgbtRed	  1				빨강

	즉, 우리가 화면에서 보는 24비트 비트맵 파일의 픽셀은 3바이트로 되어 있음
	비트맵 구조체 작성하기
	주의할 점은 반드시 구조체를 1바이트 크기로 정렬해야 된다는 점
	비트맵 파일에서 각 정보는 위치와 크기가 정확하게 정해져 있으므로 반드시 구조체의 크기와 형태 그대로 읽어야됨
	*/

	//앞에서 정의한 구조체를 사용해서 이미지의 픽셀에 접근해보고 각 픽셀을 ASCII문자로 저장해보기
	/*
	비트맵 파일을 ASCII 문자로 저장하는 과정
	1. 비트맵 파일 열기
	2. 파일 헤더 읽기
	3. 매직 넘버 검사
	4. 비트맵 정보 구조체 읽기
	5. 24비트 비트맵 여부 검사
	6. 픽셀 데이터 남는 공간 구하기
	7. 픽셀 데이터 읽기
	8. 비트맵 파일 닫기
	9. 텍스트 파일 열기
	10. 픽셀 데이터로 흑백값을 구함
	11. 흑백 값으로 ASCII 문자의 인덱스를 구함
	12. ASCII 문자를 텍스트 파일에 쓰기
	13. 텍스트 파일 닫기
	10~12번을 가로 * 세로 크기만큼 반복함
	*/

	//먼저 자주 사용하는 값은 매크로로 정의하기
	//픽셀 한 개의 크기는 3바이트로 고정되있음, 픽셀 데이터 가로 한 줄은 4의 배수 크기로 정렬됨 
	//main 함수에서 비트맵 파일 포인터, 출력 결과를 저장할 텍스트 파일 포인터, 파일 헤더 구조체 변수, 
	//비트맵 정보 구조체 변수, 픽셀 데이터를 읽기 위한 포인터, 픽셀 데이터 크기, 비트맵 이미지의 가로와 세로 크기
	//픽셀 데이터가 4의 배수가 아닐 때 남는 공간을 저장할 변수를 선언함

	FILE *fpBmp;
	FILE *fpTxt;
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;

	unsigned char *image;
	int size;
	int width, height;
	int padding;

	//각 픽셀을 표현할 ASCII문자를 배열로 만들기
	char ascii[] = { '#','#', '@', '%', '=','+', '*', ':', '-', '.', ' ' };
	//비트맵 이미지에서 픽셀의 RGB 색상값이 모두 0이면 검은색이고 모두 255이면 흰색임. 값이 작을 수록 어두워지고
	//클수록 밝아짐. 따라서 배열의 낮은 인덱스에는 획수가 많은 문자를 배치하고 높은 인덱스에는 획수가 적은 문자를 배치함 
	//그리고 가장 큰 인덱스에는 공백을 넣음 

	//fopen 함수로 파일을 바이너리 모드로 열은 다음에 fread함수로 파일 헤더를 읽음 
	//그 다음에 비트맵 파일이 맞는지 확인하기 위해 bfType의 값이 'MB'가 맞는지 확인함
	//2바이트 크기의 'BM'을 리틀 엔디언 방식으로 읽었으므로 'B'와 'M'이 뒤집혀서 'MB'가 됨 
	//만약 이 값이 맞지 않으면 비트맵 파일이 아님 

	fpBmp = fopen("Lenna80x80.bmp", "rb");
	if (fpBmp == NULL)	//파일 열기에 실패하면 프로그램을 종료함 
		return 0;
	if (fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, fpBmp) < 1)
	{	//fread 함수로 sizeof(BITMAPFILEHEADER) 크기만큼 읽기에 성공하면 읽은 횟수 1을 반환하고 실패하면 1보다 작은 수를
		//반환함, 따라서 파일 읽기 실패했을 때 파일 포인터를 닫고 프로그램을 종료함 
		fclose(fpBmp);
		return 0;
	}

	if (fileHeader.bfType != 'MB')
	{	//매직 넘버가 MB가 맞는지 확인하기, 아니라면 파일 포인터 닫고 프로그램을 종료시킴 
		fclose(fpBmp);
		return 0;
	}

	if (fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, fpBmp) < 1)
	{
		fclose(fpBmp);
		return 0;
	}

	if (infoHeader.biBitCount != 24)
	{	//24비트 비트맵이 아니면 종료시킴 
		fclose(fpBmp);
		return 0;
	}

	//픽셀 데이터의 크기 및 이미지의 가로, 세로 크기와 같이 자주 사용하는 정보는 변수에 따로 저장해 놓기 
	size = infoHeader.biSizeImage;	//픽셀 데이터의 크기 
	width = infoHeader.biWidth;		//비트맵 이미지의 가로 크기
	height = infoHeader.biHeight;	//비트맵 이미지의 세로 크기

	/*픽셀 데이터의 가로 공간이 저장될 때 남는 공간(padding)을 구하기
	비트맵 포맷은 픽셀의 가로 한 줄을 4의 배수 크기로 저장하는데 만약 가로 한 줄의 크기가
	4의 배수가 아니라면 남는 공간을 0으로 채워서 저장함, 따라서 픽셀 데이터를 읽기 위해서는
	남는 공간을 알고 있어야 됨, 이렇게 하는 이유는 CPU가 데이터를 처리 시에 4바이트 크기가 효율적이라서 그럼
	남는 공간을 구하기 전에 나머지 계산해야 하는데 계산식은  (가로 크기 * PIXEL_SIZE) % PIXEL_ALIGN
	이미지의 가로 크기에 픽셀 크기를 곱해서 가로 한 줄의 크기를 구하고 4로 나머지를 구함
	그리고 4에서 나머지를 빼주면 남는 공간을 구할 수 있음, 하지만 남는 공간이 0이라면
	최종결과가 4가 되버리므로 여기서 다시 4로 나눠서 나머지를 구함
	*/
	padding = (PIXEL_ALIGN - ((width * PIXEL_SIZE) % PIXEL_ALIGN)) % PIXEL_ALIGN;

	if (size == 0)
	{
		size = (width * PIXEL_SIZE + padding) * height;
	}

	//비트맵 파일 중에 픽셀 데이터의 크기 size가 0인 경우도 있음, 이때 이미지의 가로 크기에 픽셀 크기를 곱한 뒤에 
	//남는 공간을 더해주면 완전한 가로 한 줄의 크기를 구할 수 있음. 그리고 여기에 이미지의 세로 크기를 곱해주면
	//픽셀 데이터의 크기를 구할 수 있음 

	image = malloc(size);

	//image 포인터에 size(픽셀 데이터 크기)만큼 동적 메모리를 할당함 
	//이제 비트맵 이미지의 픽셀 데이터를 읽어오기 , 24비트 비트맵 파일에서는 비트맵 정보 뒤에 바로 픽셀 데이터가 있어서
	//바로 fread함수로 읽어도 되지만 bfOffBits(비트맵 데이터 시작 위치)값을 활용하여 파일 포인터를
	//픽셀 데이터의 시작 위치로 이동시킴 

	fseek(fpBmp, fileHeader.bfOffBits, SEEK_SET);

	if (fread(image, size, 1, fpBmp) < 1)
	{	//파일에서 픽셀 데이터 크기만큼 읽기, 읽기에 실패하면 파일포인터를 닫고 프로그램을 종료시킴 
		fclose(fpBmp);
		return 0;
	}
	fclose(fpBmp);	//비트맵 파일 닫기 

	fpTxt = fopen("ascii.txt", "w");	//결과 출력용 텍스트 파일 열기 
	if (fpTxt == NULL)
	{	//파일 열기에 실패하면 픽셀 데이터를 저장한 동적 메모리를 해제하고 프로그램을 종료시킴 
		free(image);
		return 0;
	}

	//보통 비트맵 파일의 픽셀 데이터는 아래 위가 뒤집혀서 저장되므로 아래쪽부터 반복함
	//세로 크기만큼 반복하기 
	/*먼저 세로부터 처리해야 되는데 배열의 인덱스는 0부터 시작하므로 height-1부터 시작함
	단, 가로는 0부터 시작해서 width보다 작을 때까지만 반복하므로 따로 -1을 안해도 됨
	image포인터는 일렬로 된 배열이므로 x,y,padding을 이용하여 인덱스를 계산해야됨
	먼저 (x * 픽셀 크기)는 픽셀의 가로위치이고 (y * ( 세로크기 * 픽셀 크기))는 픽셀이 몇 번째
	줄인지 계산함. 마지막으로 (padding * y)는 줄별로 누적된 남는 공간임
	*/
	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{
			int index = (x * PIXEL_SIZE) + (y * (width * PIXEL_SIZE)) + (padding * y);
			//인덱스를 계산했으면 &image[index]와 같이 배열(포인터)에 인덱스를 지정하여 현재 픽셀에 접근한 뒤에 
			//&를 붙여서 현재 픽셀의 메모리 주소를 구하고 RGBTRIPLE 포인터로 변환해서 RGBTRIPLE 포인터인 pixel에
			//저장해줌 이렇게 하면 RGBTRIPLE 구조체를 이용하여 각 픽셀의 빨강, 초록, 파랑값을 손쉽게 가져올 수
			//있음
			RGBTRIPLE *pixel = (RGBTRIPLE *)&image[index];
			//RGBTRIPLE로 빨강, 초록, 파랑값을 가져옴 
			//이제 픽셀을 ASCII문자로 변환해야 되는데 RGB 중 어느 한 값을 사용하기 보다는 픽셀값을 흑백으로 바꾼 뒤에
			//변환하는 것이 좀 더 보기가 좋음(흑백값은 RGB값의 평균을 구하면 됨) 
			unsigned char blue = pixel->rgbBlue;
			unsigned char green = pixel->rgbGreen;
			unsigned char red = pixel->rgbRed;
			unsigned char gray = (red + green + blue) / PIXEL_SIZE;
			/*이제 ascii 배열에 들어가는 ASCII문자를 사용하려면 흑백값 gray를 배열의 인덱스로 만들면 됨
			즉 unsigned char의 범위인 0~255를 0~10으로 변환하는 것
			흑백값 gray를 256으로 나눈 뒤에 0~0.99사이의 값으로 만든 뒤에 sizeof(ascii)를 곱하면 ascii 배열의
			인덱스가 됨. 단, 실수가 아닌 정수 계산이므로 255 / 256 = 0.99609375가 아니라 0이 되므로 먼저 gray와
			sizeof(ascii)를 곱해서 숫자를 키운다음 256으로 나누는 것임, 만약 256이 아닌 255로 나누면 gray가 255일 때
			인덱스 값이 11이 나오므로 배열 범위를 벗어나게 됨 */
			char c = ascii[gray * sizeof(ascii) / 256];
			/*비트맵 이미지에서는 픽셀의 가로, 세로 크기가 똑같지만 보통 ASCII문자는 세로로 길쭉한 형태이므로
			정사각형 모양과 비슷하게 보여주기 위해 같은 문자를 두 번 저장해줌
			*/
			fprintf(fpTxt, "%c%c", c, c);
		}
		fprintf(fpTxt, "\n"); //가로 픽셀 저장이 끝났으면 \n을 해줘서 줄바꿈을 해줌 
	}

	fclose(fpTxt);
	free(image);

	return 0;
}
