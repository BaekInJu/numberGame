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
	srand(time(NULL));      //rand�� seed��
	answer = rand() % 99 + 1;       //1 ~ 99 
	do {
		printf("�����Է�:");
		scanf("%d", &guess);
		if (answer > guess) {
			printf("��\n");

		}
		else if (answer < guess) {
			printf("�ٿ�\n");
		}
		else {
			printf("����");
		}
	} while (guess != answer);

}

void game2(void) {
	int comNum1 = 0, comNum2 = 0, comNum3 = 0;
	int userNum1 = 0, userNum2 = 0, userNum3 = 0;

	srand(time(NULL));
	//���� ���� ����
	do {
		comNum1 = rand() % 9 + 1;
		comNum2 = rand() % 9 + 1;
		comNum3 = rand() % 9 + 1;
	} while (comNum1 == comNum2 || comNum2 == comNum3 || comNum3 == comNum1);

	//����� �Է�(���߱�)
	do {
		//�ݺ��Ҷ����� strike, ball �ʱ�ȭ
		int strike = 0, ball = 0;
		//�Է�
		printf("ù��° �Է�");
		scanf("%d", &userNum1);
		printf("�ι�° �Է�");
		scanf("%d", &userNum2);
		printf("����° �Է�");
		scanf("%d", &userNum3);

		//���ǽ�
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
		//��Ʈ(strike, ball)
		printf("%dstrike %dball\n", strike, ball);

		//���߿� ���亸�� (-1)
		if (userNum1 == -1) {
			printf("%d,%d,%d", comNum1, comNum2, comNum3);
		}

		//strike�� 3�� �Ǹ� �ݺ��� ����
		if (strike == 3)
			break;

	} while (1); //break�� ���ö����� �ݺ�
	printf("���� : %d %d %d\n", comNum1, comNum2, comNum3);
}


int main(void) {
	system("mode con: cols=80 lines=20");
	int num;
	while (1) {
		gotoxy(33, 1);
		printf("1. ���ڰ���\n");
		gotoxy(33, 2);
		printf("2. �߱�����\n");
		gotoxy(33, 3);
		printf("3. ��    ��");

		gotoxy(20, 4);
		printf("����(����(1), �߱�(2), ����(3))");
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
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���\n");
		}


		system("pause");
		system("cls");
	}
	return 0;
}
