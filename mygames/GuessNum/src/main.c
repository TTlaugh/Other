#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char const *argv[])
{
	int MAX=100, MIN=1;
	int mode, user, count, secretNumber;
	int flag=1;

	srand(time(NULL));

	do {
		system("clear");
		printf("\t<====================================>\n");
		printf("\t ||                                ||\n");
		printf("\t ||      NUMBER GUESSING GAME      ||\n");
		printf("\t ||                                ||\n");
		printf("\t<====================================>\n");
		printf("\n\n");

		printf("CHON CHE DO\n");
		printf("[1] Mot nguoi choi.\n");
		printf("[2] Hai nguoi choi.\n");
		printf("Chon mot so: "); scanf("%d", &mode);
		switch(mode) {
			case 1:
				printf("CHON DO KHO\n");
				printf("Min: "); scanf("%d", &MIN);
				printf("Max: "); scanf("%d", &MAX);
				secretNumber = (rand()%(MAX-MIN+1))+MIN;
				break;
			case 2:
				printf("Hay nhap so bi mat: "); scanf("%d", &secretNumber);
				break;
			default:
				printf("Nhap sai!\n");
				return 1;
		}

		system("clear");
		count=1;
		do {
			printf("Hay doan mot so: "); scanf("%d", &user);
			if (user < secretNumber) {
				printf("LON HON NUA!\n\n");
			}
			else if (user > secretNumber) {
				printf("NHO HON NUA!\n\n");
			}
			else {
				printf("\n*********** CHUC MUNG ***********\n");
				printf("Doan dung roi ban ey!\n\n");
				printf("Voi so luot doan la %d lan thi ", count);
				if (count <= 5) {
					printf("ban qua dinh\n");
				}
				else if (count > 5 && count <= 10) {
					printf("cung ghe day\n");
				}
				else if (count > 10 && count <= 20) {
					printf("qua la binh thuong\n");
				}
				else {
					printf("ban doan do ec\n");
				}
			}
			count++;
		} while (user != secretNumber);

		printf("\nBan co muon choi lai khong?\n");
		printf("[0] Khong!\n");
		printf("[1] Co!\n");
		printf("Chon mot so: "); scanf("%d", &flag);
	} while (flag);
	return 0;
}
