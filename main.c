#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void game1(void) {
	int answer = 0;
	int guess;
	srand(time(NULL));      //rand의 seed값
	answer = rand() % 99 + 1;       //1 ~ 99 
	do {
		printf("정답입력:");
		scanf("%d", &guess);
		if (answer > guess) {
			printf("업\n");

		}
		else if (answer < guess) {
			printf("다운\n");
		}
		else {
			printf("정답");
		}
	} while (guess != answer);

}

void game2(void) {
	int comNum1 = 0, comNum2 = 0, comNum3 = 0;
	int userNum1 = 0, userNum2 = 0, userNum3 = 0;

	srand(time(NULL));
	//랜덤 숫자 지정
	do {
		comNum1 = rand() % 9 + 1;
		comNum2 = rand() % 9 + 1;
		comNum3 = rand() % 9 + 1;
	} while (comNum1 == comNum2 || comNum2 == comNum3 || comNum3 == comNum1);

	//사용자 입력(맞추기)
	do {
		//반복할때마다 strike, ball 초기화
		int strike = 0, ball = 0;
		//입력
		printf("첫번째 입력");
		scanf("%d", &userNum1);
		printf("두번째 입력");
		scanf("%d", &userNum2);
		printf("세번째 입력");
		scanf("%d", &userNum3);

		//조건식
		if (comNum1 == userNum1) {
			strike++;
		}
		else if (comNum2 == userNum1 || comNum3 == userNum1) {
			ball++;
		}

		if (comNum2 == userNum2) {
			strike++;
		}
		else if (comNum1 == userNum2 || comNum3 == userNum2) {
			ball++;
		}

		if (comNum3 == userNum3) {
			strike++;
		}
		else if (comNum2 == userNum3 || comNum1 == userNum3) {
			ball++;
		}
		//힌트(strike, ball)
		printf("%dstrike %dball\n", strike, ball);

		//도중에 정답보기 (-1)
		if (userNum1 == -1) {
			printf("%d,%d,%d", comNum1, comNum2, comNum3);
		}

		//strike가 3이 되면 반복문 종료
		if (strike == 3)
			break;

	} while (1); //break가 나올때까지 반복
	printf("정답 : %d %d %d\n", comNum1, comNum2, comNum3);
}


int main(void) {
	system("mode con: cols=80 lines=20");
	int num;
	while (1) {
		gotoxy(33, 1);
		printf("1. 숫자게임\n");
		gotoxy(33, 2);
		printf("2. 야구게임\n");
		gotoxy(33, 3);
		printf("3. 종    료");

		gotoxy(20, 4);
		printf("선택(숫자(1), 야구(2), 종료(3))");
		scanf("%d", &num);

		if (num == 3)
			break;
		else if (num == 1) {
			system("cls");
			game1();
		}
		else if (num == 2) {
			system("cls");
			game2();
		}
		else {
			printf("잘못된 선택입니다. 다시 선택하세요\n");
		}


		system("pause");
		system("cls");
	}
	return 0;
}
