#include <stdio.h>
#include <stdlib.h> //random, srand �Լ�
#include <time.h> //time �Լ�

//��� VS ��ǻ�� �� �Լ�
//���ӸӴ� ���
int comVShu(int hu, int com, int baeting, int hu_money, int com_money) {

	if (hu == com) {
		printf("�����ϴ�.\n");
		printf("���� ���� ���ӸӴϴ� %d�� �Դϴ�.\n", hu_money);
	}

	else if (com > (hu + 1) % 3) {
		printf("�̰���ϴ�.\n");
		hu_money += baeting;
		com_money -= baeting;
		printf("���� ���� ���ӸӴϴ� %d�� �Դϴ�.\n", hu_money);

		if (com_money <= 0)
			printf("@@@�÷��̾ �¸��߽��ϴ�.@@@\n");
	}

	else {
		printf("�����ϴ�.\n");
		hu_money -= baeting;
		com_money += baeting;
		printf("���� ���� ���ӸӴϴ� %d�� �Դϴ�.\n", hu_money);

		if (hu_money <= 0)
			printf("@@@�÷��̾ �й��Ͽ����ϴ�.@@@\n");
	}

	return hu_money, com_money;
}

int main() {
	//���ӸӴ� ����
	int Game_money;
	printf("���ӸӴϸ� �����ϼ���: ");
	scanf("%d", &Game_money);
	int Hu_game_money = Game_money;
	int Com_game_money = Game_money;

	while (Hu_game_money || Com_game_money >= 0) {
		
		int Baeting_money;
		printf("---------------------------------------\n");
		printf("�ݾ��� �����ϼ���:");
		scanf("%d", &Baeting_money);

		printf("����(1), ����(2), ��(3)�� �ϳ��� �Է��Ͻÿ�:\n");

		//��ǻ���� ���������� ���� ���
		srand(time(NULL));
		int com_RPS = 0;
		com_RPS = rand() % 3 + 1;

		//��� ���������� �Է�
		int hu_RPS = 0;
		scanf("%d", &hu_RPS);

		//�Լ��� �̿��� ���, ���ӸӴ� ���
		int result;
		result = comVShu(hu_RPS, com_RPS, Baeting_money, Hu_game_money, Com_game_money);
	}
	return 0;
}
