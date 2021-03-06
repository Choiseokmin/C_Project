#include <stdio.h>
#include <stdlib.h> //random, srand 함수
#include <time.h> //time 함수

//사람 VS 컴퓨터 비교 함수
//게임머니 계산
int comVShu(int hu, int com, int baeting, int hu_money, int com_money) {

	if (hu == com) {
		printf("비겼습니다.\n");
		printf("현재 남은 게임머니는 %d원 입니다.\n", hu_money);
	}

	else if (com > (hu + 1) % 3) {
		printf("이겼습니다.\n");
		hu_money += baeting;
		com_money -= baeting;
		printf("현재 남은 게임머니는 %d원 입니다.\n", hu_money);

		if (com_money <= 0)
			printf("@@@플레이어가 승리했습니다.@@@\n");
	}

	else {
		printf("졌습니다.\n");
		hu_money -= baeting;
		com_money += baeting;
		printf("현재 남은 게임머니는 %d원 입니다.\n", hu_money);

		if (hu_money <= 0)
			printf("@@@플레이어가 패배하였습니다.@@@\n");
	}

	return hu_money, com_money;
}

int main() {
	//게임머니 설정
	int Game_money;
	printf("게임머니를 설정하세요: ");
	scanf("%d", &Game_money);
	int Hu_game_money = Game_money;
	int Com_game_money = Game_money;

	while (Hu_game_money || Com_game_money >= 0) {
		
		int Baeting_money;
		printf("---------------------------------------\n");
		printf("금액을 배팅하세요:");
		scanf("%d", &Baeting_money);

		printf("가위(1), 바위(2), 보(3)중 하나를 입력하시오:\n");

		//컴퓨터의 가위바위보 랜덤 출력
		srand(time(NULL));
		int com_RPS = 0;
		com_RPS = rand() % 3 + 1;

		//사람 가위바위보 입력
		int hu_RPS = 0;
		scanf("%d", &hu_RPS);

		//함수를 이용한 대결, 게임머니 계산
		int result;
		result = comVShu(hu_RPS, com_RPS, Baeting_money, Hu_game_money, Com_game_money);
	}
	return 0;
}
