#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define VER "alpha 1.2"

void intro();
int startScreen();
void gotoxy(int x, int y);
void CursorView();
void highScore();
void printTime();
char randomEn();
int randomInt(int o);
void capsLockTest();
void countDown();
void game();

void sample();

void a();
void b();
void c();
void d();
void e();
void f();
void g();
void h();
void i();
void j();
void k();
void fin();

int start;
int end;

int min;
int sec;
int ms;

int tutorial;

int main() {
	intro();
	CursorView();
	srand(time(NULL));
	tutorial = 1;
	while (1) {
		int y = startScreen();
		if (y == 1) {
			game();
		}
		else if (y == 2) {
			highScore();
		}
		else if (y == 3) {
			break;
		}
	}
}

void intro() {
	printf("speedTyper ver.%s", VER);
	printf("\n아무 키나 눌러 계속");
	char e = _getch();
}
int startScreen() {
	system("cls");
	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("게임 시작\n하이스코어\n종료");
		if (error == 1) { //Caps Lock 활성화
			gotoxy(0, 6);
			printf("Caps Lock을 풀어주세요.");
			error = 0;
		}
		else if (error == 2) { //한/영키 전환
			gotoxy(0, 6);
			printf("한/영키를 바꿔주세요.");
			error = 0;
		}
		if (tutorial == 1) {
			gotoxy(0, 6);
			printf("방향키로 선택, a로 결정");
			tutorial = 0;
		}
		if (s == 1) {
			gotoxy(10, 0);
		}
		else if (s == 2) {
			gotoxy(11, 1);
		}
		else if (s == 3) {
			gotoxy(5, 2);
		}

		printf("<");

		while (1) {
			if (_kbhit()) {
				select = _getch();
				if (select == -32) {
					select = _getch();
					switch (select) {
					case 72:
						if (s != 1) {
							s--;

						}
						break;
					case 80:
						if (s != 3) {
							s++;
						}
						break;
					}
					break;
				}
				else if (select == 'a') {
					return s;
				}
				else if (select == 'A') {
					error = 1;
					break;
				}
				else if (select < 0 || select > 126) {
					error = 2;
					break;
				}
			}
		}
	}
}

void gotoxy(int x, int y) { //커서 이동
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void highScore() {
	system("cls");
	printf("하이스코어\n\n");
	FILE* fp;
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("오류 : 파일을 열 수 없습니다.\n실행 파일과 같은 디렉토리에 nameData.txt 파일이 없을 수 있습니다.");
		char t = _getch();
		fclose(fp);
		return 0;
	}
	int l = 1;
	char name[5];
	char fsec[5];
	char fmin[5];
	char fms[5];
	while (fgets(name, sizeof(name), fp) != NULL) {
		name[strlen(name) - 1] = NULL;
		fgets(fmin, sizeof(fmin), fp);
		fmin[strlen(fmin) - 1] = NULL;
		fgets(fsec, sizeof(fsec), fp);
		fsec[strlen(fsec) - 1] = NULL;
		fgets(fms, sizeof(fms), fp);
		fms[strlen(fms) - 1] = NULL;
		printf("%d l %s  %s:%s:%s\n\n", l, name, fmin, fsec, fms);
		l++;
	}
	if (l < 11) {
		for (int i = l; i < 11; i++) {
			printf("%d l ---  -:-:- \n\n", i);
		}
	}
	fclose(fp);
	char s = _getch();
}

void printTime() {
	sec = (end - start) / 1000 - min * 60;
	ms = (end - start - min * 60000) % 1000;
	if (sec >= 60) {
		sec = 0;
		min++;
	}
	gotoxy(0, 10);
	printf("%d:%d:%d\n", min, sec, ms);
}

char randomEn() {
	int ch = rand() % 26;
	int ch2 = rand() % 2;
	char a = ch + 97;
	if (ch2 == 1) {
		a -= 32;
	}
	if (a == 'I') {
		a = 'l';
	}
	return a;
}

int randomInt(int o) {
	int a = rand() % o + 1;
	return a;
}

void capsLockTest() {
	system("cls");
	printf("Caps Lock의 비활성화를 확인합니다.\n");
	printf("다음 키를 순서대로 눌러주세요.\n\n");
	printf("A\na\nu\nU");
	while (1) {
		char s = NULL;
		s = _getch();
		if (s == 'A') {
			break;
		}
		gotoxy(2, 3);
		printf("    ");
		gotoxy(2, 3);
	}
	gotoxy(2, 3);
	printf("v");
	while (1) {
		char s = NULL;
		s = _getch();
		if (s == 'a') {
			break;
		}
		gotoxy(2, 4);
		printf("    ");
		gotoxy(2, 4);
	}
	gotoxy(2, 4);
	printf("v");
	while (1) {
		char s = NULL;
		s = _getch();
		if (s == 'u') {
			break;
		}
		gotoxy(2, 5);
		printf("    ");
		gotoxy(2, 5);
	}
	gotoxy(2, 5);
	printf("v");
	while (1) {
		char s = NULL;
		s = _getch();
		if (s == 'U') {
			break;
		}
		gotoxy(2, 5);
		printf("    ");
		gotoxy(2, 5);
	}
	gotoxy(2, 5);
	printf("v");
}
void countDown(int o) {
	start = clock();
	int time = o;

	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			printf("%d ", time);
		}
		printf("\n");
	}
	while (1) {
		end = clock();
		if (end - start >= 1000) {
			time--;
			start = clock();

			system("cls");
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 40; j++) {
					printf("%d ", time);
				}
				printf("\n");
			}
		}
		else if (time == 0) {
			system("cls");
			break;

		}


	}
}
void game() {
	char u = 0;
	system("cls");
	printf("s를 눌러 시작\nb를 눌러 뒤로가기");
	while (1) {
		char y = _getch();
		if (y == 'b') {
			break;
		}
		else if (y == 's') {
			start = clock();
			capsLockTest();
			countDown(3);
			a();
			b();
			c();
			d();
			e();
			f();
			g();
			h();
			i();
			j();
			fin();
			start = clock();
			while (1) {
				if (_kbhit()) {
					u = _getch();
				}

				end = clock();
				if (end - start == 3000) {
					break;
				}

			}
			FILE* fp;
			fp = fopen("data.txt", "r");
			FILE* bp;
			bp = fopen("buffera.txt", "w");
			FILE* vp;
			vp = fopen("bufferb.txt", "w");
			if (fp == NULL) {
				printf("오류 : 파일을 열 수 없습니다.\n실행 파일과 같은 디렉토리에 data.txt 파일이 없을 수 있습니다.");
				char t = _getch();
				fclose(fp);
				return 0;
			}
			int l = 1;
			int p = 0;
			char name[5];
			char fsec[5];
			char fmin[5];
			char fms[5];
			while (fgets(name, sizeof(name), fp) != NULL) {

				name[strlen(name) - 1] = NULL;
				fgets(fmin, sizeof(fmin), fp);;
				fmin[strlen(fmin) - 1] = NULL;
				fgets(fsec, sizeof(fsec), fp);
				fsec[strlen(fsec) - 1] = NULL;
				fgets(fms, sizeof(fms), fp);
				fms[strlen(fms) - 1] = NULL;
				int nmin = atoi(fmin);
				int nsec = atoi(fsec);
				int nms = atoi(fms);
				if (min < nmin) {
					fputs(name, vp);
					fputs("\n", vp);
					fputs(fmin, vp);
					fputs("\n", vp);
					fputs(fsec, vp);
					fputs("\n", vp);
					fputs(fms, vp);
					fputs("\n", vp);
					p = l;
					break;
				}
				else if (min == nmin) {
					if (sec < nsec) {
						fputs(name, vp);
						fputs("\n", vp);
						fputs(fmin, vp);
						fputs("\n", vp);
						fputs(fsec, vp);
						fputs("\n", vp);
						fputs(fms, vp);
						fputs("\n", vp);
						p = l;
						break;
					}
					else if (sec == nsec) {
						if (ms == nms) {
							fputs(name, vp);
							fputs("\n", vp);
							fputs(fmin, vp);
							fputs("\n", vp);
							fputs(fsec, vp);
							fputs("\n", vp);
							fputs(fms, vp);
							fputs("\n", vp);
							p = l;
							break;
						}
					}
				}
				fputs(name, bp);
				fputs("\n", bp);
				fputs(fmin, bp);
				fputs("\n", bp);
				fputs(fsec, bp);
				fputs("\n", bp);
				fputs(fms, bp);
				fputs("\n", bp);
				l++;
			}



			while (fgets(name, sizeof(name), fp) != NULL) {
				fgets(fmin, sizeof(fmin), fp);
				fgets(fsec, sizeof(fsec), fp);
				fgets(fms, sizeof(fms), fp);
				fputs(name, vp);
				fputs(fmin, vp);
				fputs(fsec, vp);
				fputs(fms, vp);
				l++;
			}
			fclose(fp);
			fclose(bp);
			fclose(vp);
			if (l < 11) {
				l = 1;
				system("cls");
				char qmin[100];
				char qsec[100];
				char qms[100];
				sprintf(qmin, "%d", min);
				sprintf(qsec, "%d", sec);
				sprintf(qms, "%d", ms);
				printf("이름을 입력해주세요.\n___\b\b\b");
				char player[100] = { 0 };
				player[0] = _getch();
				while (player[0] > 90 || player[0] < 65) {
					if (player[0] <= 122 && player[0] >= 97) {
						player[0] -= 32;
					}
					else {
						player[0] = _getch();
					}
				}
				printf("%c", player[0]);
				player[1] = _getch();
				while (player[1] > 90 || player[1] < 65) {
					if (player[1] <= 122 && player[1] >= 97) {
						player[1] -= 32;
					}
					else {
						player[1] = _getch();
					}
				}
				printf("%c", player[1]);
				player[2] = _getch();
				while (player[2] > 90 || player[2] < 65) {
					if (player[2] <= 122 && player[2] >= 97) {
						player[2] -= 32;
					}
					else {
						player[0] = _getch();
					}
				}
				printf("%c", player[2]);


				fp = fopen("data.txt", "w");
				bp = fopen("buffera.txt", "r");
				vp = fopen("bufferb.txt", "r");

				while (fgets(name, sizeof(name), bp) != NULL) {
					fgets(fmin, sizeof(fmin), bp);
					fgets(fsec, sizeof(fsec), bp);
					fgets(fms, sizeof(fms), bp);
					fputs(name, fp);
					fputs(fmin, fp);
					fputs(fsec, fp);
					fputs(fms, fp);
					l++;
				}

				fputs(player, fp);
				fputs("\n", fp);
				fputs(qmin, fp);
				fputs("\n", fp);
				fputs(qsec, fp);
				fputs("\n", fp);
				fputs(qms, fp);
				fputs("\n", fp);
				l++;
				while (fgets(name, sizeof(name), vp) != NULL) {
					if (l == 11) {
						break;
					}
					fgets(fmin, sizeof(fmin), vp);
					fgets(fsec, sizeof(fsec), vp);
					fgets(fms, sizeof(fms), vp);
					fputs(name, fp);
					fputs(fmin, fp);
					fputs(fsec, fp);
					fputs(fms, fp);
					l++;
				}
				fclose(fp);
				fclose(bp);
				fclose(vp);
			}
			l = 1;
			fp = fopen("data.txt", "r");
			system("cls");
			while (fgets(name, sizeof(name), fp) != NULL) {
				name[strlen(name) - 1] = NULL;
				fgets(fmin, sizeof(fmin), fp);
				fmin[strlen(fmin) - 1] = NULL;
				fgets(fsec, sizeof(fsec), fp);
				fsec[strlen(fsec) - 1] = NULL;
				fgets(fms, sizeof(fms), fp);
				fms[strlen(fms) - 1] = NULL;
				printf("%d l %s  %s:%s:%s", l, name, fmin, fsec, fms);
				if (l == p) {
					printf("  <<<");
				}
				printf("\n\n");
				l++;
			}
			if (l < 11) {
				for (int i = l; i < 11; i++) {
					printf("%d l ---  -:-:- \n\n", i);
				}
			}
			fclose(fp);
			start = clock();
			while (1) {
				if (_kbhit()) {
					char e = _getch();
				}
				end = clock();
				if (end - start >= 5000) {
					break;
				}
			}
			printf("\n\n아무 키나 눌러 처음으로");
			char e = _getch();
			break;
		}
	}
}

void sample() {
	char q;
	gotoxy(0, 0);
	printf("");
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			printTime();
		}
		else {
			q = _getch();
			system("cls");
			break;
		}
	}
}

void a() {
	char q;
	char ans = randomEn();
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			gotoxy(0, 0);
			printf("%c를 입력하세요!", ans);
			printTime();
		}
		else {
			q = _getch();
			if (q == ans) {
				system("cls");
				break;
			}
		}
	}
}

void b() {
	char q;
	int o = randomInt(5);
	int p = randomInt(4);
	char ans = 48 + (o + p);
	while (1) {
		end = clock();

		if (!(_kbhit())) {
			gotoxy(0, 0);
			printf("정답은?\n%d + %d = ?", o, p);
			printTime();
		}
		else {
			q = _getch();
			if (q == ans) {
				system("cls");
				break;
			}
		}
	}
}

void c() {
	char q;
	int x = 0;
	int y = 0;

	int o = randomInt(3);
	int p = randomInt(3);
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			gotoxy(0, 0);
			printf("$를 얻으세요!\n\n");
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (x == j && y == i) {
						printf("@ ");
					}
					else if (o == j && p == i) {
						printf("$ ");
					}
					else {
						printf("* ");
					}
				}
				printf("\n");
			}
			printTime();
		}
		else {
			q = _getch();
			if (q == -32) {
				q = _getch();
				switch (q) {
				case 75:
					if (x != 0) {
						x--;

					}
					break;
				case 77:
					if (x != 3) {
						x++;

					}
					break;
				case 72:
					if (y != 0) {
						y--;

					}
					break;
				case 80:
					if (y != 3) {
						y++;

					}
					break;
				}
			}
			if (x == o && p == y) {
				system("cls");
				break;
			}




		}
	}
}

void d() {
	char q;
	char ch1 = randomEn();
	char ch2 = randomEn();
	while (1) {
		if (ch2 == ch1) {
			ch2 = randomEn();
		}
		else {
			break;
		}
	}
	char ch3 = randomEn();
	while (1) {
		if (ch3 == ch1 || ch3 == ch2) {
			ch3 = randomEn();
		}
		else {
			break;
		}
	}
	char ch4 = randomEn();
	while (1) {
		if (ch4 == ch1 || ch4 == ch2 || ch4 == ch3) {
			ch4 = randomEn();
		}
		else {
			break;
		}
	}
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;

	gotoxy(0, 0);
	printf("모두 누르세요!");
	gotoxy(3, 1);
	printf("%c", ch1);
	gotoxy(0, 2);
	printf("%c", ch2);
	gotoxy(6, 2);
	printf("%c", ch3);
	gotoxy(3, 3);
	printf("%c", ch4);

	while (1) {
		end = clock();
		if (!(_kbhit())) {

			printTime();
		}
		else {
			q = _getch();
			if (q == ch1) {
				gotoxy(3, 1);
				printf("*");
				ch1 = 1;
			}
			else if (q == ch2) {
				gotoxy(0, 2);
				printf("*");
				ch2 = 1;
			}
			else if (q == ch3) {
				gotoxy(6, 2);
				printf("*");
				ch3 = 1;
			}
			else if (q == ch4) {
				gotoxy(3, 3);
				printf("*");
				ch4 = 1;
			}
			if (ch1 == 1 && ch2 == 1 && ch3 == 1 && ch4 == 1) {
				system("cls");
				break;
			}


		}
	}
}

void e() {
	char q;
	int num = randomInt(10);
	while (num == 1 || num == 10) {
		num = randomInt(10);
	}
	int s = 1;
	int o = 0;
	int n = clock();
	gotoxy(0, 0);
	printf("타이밍을 맞춰 a를 누르세요!");
	gotoxy(0, 3);
	for (int i = 1; i < 11; i++) {
		if (num == i) {
			printf("@");
		}
		else {
			printf("#");
		}
	}
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			if (end - n >= 100) {
				if (o == 0) {

					s++;
					if (s == 10) {
						o = 1;
					}
				}
				else {

					s--;
					if (s == 1) {
						o = 0;
					}
				}
				n = clock();
			}
			gotoxy(0, 2);
			for (int i = 1; i < 11; i++) {
				if (s == i) {
					printf("V");
				}
				else {
					printf(" ");
				}
			}
			printTime();
		}
		else {
			q = _getch();
			if (q == 'a') {
				if (s == num) {
					system("cls");
					break;
				}
				else {
					s = 1;
					o = 0;
				}
			}

		}
	}
}

void f() {
	char q;
	gotoxy(0, 0);
	printf("@ 를 조준하고 a로 쏘세요!\n\n");
	int x = 1;
	int y = 1;

	int o = randomInt(3);
	int p = randomInt(3);
	while (1) {
		gotoxy(0, 2);
		end = clock();
		if (!(_kbhit())) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {

					if (o == j && p == i) {
						printf("@ ");
					}
					else {
						printf("* ");
					}
				}
				printf("\n");
			}
			for (int i = 1; i < 5; i++) {
				gotoxy((i - 1) * 2, 1);
				if (x == i) {
					printf("V");
				}
				else {
					printf("  ");
				}
				gotoxy(8, 1 + i);
				if (y == i) {
					printf("<");
				}
				else {
					printf("  ");
				}
			}
			printTime();
		}
		else {
			q = _getch();
			if (q == -32) {
				q = _getch();
				switch (q) {
				case 75:
					if (x != 1) {
						x--;

					}
					break;
				case 77:
					if (x != 4) {
						x++;

					}
					break;
				case 72:
					if (y != 1) {
						y--;

					}
					break;
				case 80:
					if (y != 4) {
						y++;

					}
					break;
				}
			}
			if (q == 'a') {
				if (x - 1 == o && y - 1 == p) {
					system("cls");
					break;
				}
			}

		}
	}
}

void g() {
	char q;
	int s = 0;
	char pi[15] = { '3', '.', '1', '4', '1', '5', '9', '2', '6', '5', '3', '5', '8', '9', '7' };
	gotoxy(0, 0);
	printf("똑같이 입력하세요!");
	gotoxy(0, 2);
	for (int i = 0; i < 15; i++) {
		printf("%c", pi[i]);
	}
	gotoxy(0, 3);
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			gotoxy(0, 3);
			printTime();
			gotoxy(0, 3);
		}
		else {
			q = _getch();
			if (q == pi[s]) {
				s++;
				for (int i = 0; i < s; i++) {
					printf("%c", pi[i]);
				}
			}
			else {
				s = 0;
				printf("                     ");
				gotoxy(0, 3);
			}
			if (s == 15) {
				system("cls");
				break;
			}

		}
	}
}

void h() {
	char q;
	int o = randomInt(3);
	int p = randomInt(3);
	int j = randomInt(3);
	int ans = o + p + j;

	gotoxy(0, 0);
	printf("정답은?\n");
	printf("%d + %d + %d = ?", o, p, j);
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			printTime();
		}
		else {
			q = _getch();
			if (q - 48 == ans) {
				system("cls");
				break;
			}

		}
	}
}

void i() {
	char q;
	char ch[26];
	for (int i = 0; i < 26; i++) {
		ch[i] = 97 + i;
	}
	int n = 26;
	gotoxy(0, 0);
	printf("a부터 z까지 전부 누르세요!\n");
	printf("a b c d e f g h i j k ");
	printf("l m n o p q r s t u v ");
	printf("w x y z");
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			printTime();
		}
		else {
			q = _getch();
			if (q > 96 && q < 123) {
				if (ch[q - 97] != NULL) {
					ch[q - 97] = NULL;
					gotoxy((q - 97) * 2, 1);
					printf("-");
					n--;
				}
			}
			if (n == 0) {
				system("cls");
				break;
			}

		}
	}
}

void j() {
	char q;
	int num = 0;
	int p = 10;
	while (num < 40) {
		num = randomInt(99);
	}
	gotoxy(0, 0);
	printf("%d에 맞추세요!\n(위:10 증가/아래:10 감소/오른쪽:1증가/왼쪽:1감소 ", num);
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			gotoxy(0, 3);
			printf("%d", p);
			printTime();
		}
		else {
			q = _getch();
			if (q == -32) {
				q = _getch();
				switch (q) {
				case 75:
					if (p != 10) {
						p--;

					}
					break;
				case 77:
					if (p != 99) {
						p++;

					}
					break;
				case 80:
					if (!(p < 20)) {
						p -= 10;

					}
					break;
				case 72:
					if (!(p > 90)) {
						p += 10;

					}
					break;
				}
			}
			if (p == num) {
				system("cls");
				break;
			}

		}
	}
}

void k() {
	char q;
	int arrow[10];
	for (int i = 0; i < 10; i++) {
		arrow[i] = randomInt(4);
	}
	gotoxy(0, 0);
	printf("순서대로 누르세요!");
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			printTime();
		}
		else {
			q = _getch();
			system("cls");
			break;
		}
	}
}

void fin() {
	char q;
	int u = 0;
	int a = 0;
	int b = 100;
	while (1) {
		end = clock();
		if (!(_kbhit())) {
			gotoxy(0, 0);
			printf("마지막!!!!!\n");
			if (u == 0) {
				printf("f  <  j");
			}
			else if (u == 1) {
				printf("f  >  j");
			}
			printf("\n%d/%d", a, b);
			printTime();
		}
		else {
			q = _getch();
			if (q == 'f') {
				if (u == 0) {
					a++;
					u = 1;
				}
			}
			else if (q == 'j') {
				if (u == 1) {
					a++;
					u = 0;
				}
			}

		}
		if (a == b) {
			system("cls");
			printf("축하합니다!\n최종 기록 : %d:%d:%d", min, sec, ms);
			break;
		}
	}
}