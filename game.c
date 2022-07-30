#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

int startScreen();
void gotoxy(int x, int y);
void CursorView();
void highScore();
void printTime();
char randomEn();
int randomInt(int o);
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

int startScreen() {
	system("cls");
	int s = 1;
	int error = 0;
	char select = NULL;
	while (1) {
		system("cls");
		printf("���� ����\n���̽��ھ�\n����");
		if (error == 1) { //Caps Lock Ȱ��ȭ
			gotoxy(0, 6);
			printf("Caps Lock�� Ǯ���ּ���.");
			error = 0;
		}
		else if (error == 2) { //��/��Ű ��ȯ
			gotoxy(0, 6);
			printf("��/��Ű�� �ٲ��ּ���.");
			error = 0;
		}
		if (tutorial == 1) {
			gotoxy(0, 6);
			printf("����Ű�� ����, a�� ����");
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

void gotoxy(int x, int y) { //Ŀ�� �̵�
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
	printf("���̽��ھ�\n\n");
	FILE* fp;
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("���� : ������ �� �� �����ϴ�.\n���� ���ϰ� ���� ���丮�� nameData.txt ������ ���� �� �ֽ��ϴ�.");
		char t = _getch();
		fclose(fp);
		return 0;
	}
	int l = 1;
	char name[5];
	char sec[5];
	char min[5];
	char ms[5];
	while (fgets(name, sizeof(name), fp) != NULL) {
		name[strlen(name) - 1] = NULL;
		fgets(min, sizeof(min), fp);
		min[strlen(min) - 1] = NULL;
		fgets(sec, sizeof(sec), fp);
		sec[strlen(sec) - 1] = NULL;
		fgets(ms, sizeof(ms), fp);
		ms[strlen(ms) - 1] = NULL;
		printf("%d - %s  %s:%s:%s\n\n", l, name, min, sec, ms);
		l++;
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
	return a;
}

int randomInt(int o) {
	int a = rand() % o + 1;
	return a;
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
	system("cls");
	printf("s�� ���� ����\nb�� ���� �ڷΰ���");
	while (1) {
		char y = _getch();
		if (y == 'b') {
			break;
		}
		else if (y == 's') {
			start = clock();
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
			while(1) {
				end = clock();
				if (end - start == 3000) {
					break;
				}

			}

			char q = _getch();
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
			printf("%c�� �Է��ϼ���!", ans);
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
			printf("������?\n%d + %d = ?", o, p);
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
			printf("$�� ��������!\n\n");
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
	printf("��� ��������!");
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
	printf("Ÿ�̹��� ���� a�� ��������!");
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
	printf("@ �� �����ϰ� a�� ���!\n\n");
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
	char pi[15] = {'3', '.', '1', '4', '1', '5', '9', '2', '6', '5', '3', '5', '8', '9', '7'};
	gotoxy(0, 0);
	printf("�Ȱ��� �Է��ϼ���!");
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
	printf("������?\n");
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
	printf("a���� z���� ���� ��������!\n");
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
	printf("%d�� ���߼���!\n(��:10 ����/�Ʒ�:10 ����/������:1����/����:1���� ", num);
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
	printf("������� ��������!");
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
			printf("������!!!!!\n");
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
			printf("�����մϴ�!\n���� ��� : %d:%d:%d", min, sec, ms);
			break;
		}
	}
}