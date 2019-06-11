#include<stdio.h>
#include<string>
#include<ctime>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include "CapNhatDauSach.h"
#define DOWN -80
#define UP -72
#define LEFT -75
#define RIGHT -77
#define ENTER 13
#define ESC 27
#define BACKSPACE 8
#define SPACE 32
#define F1 -59
#define F2 -60
#define F3 -61
#define F5 -63
#define DELETE -83
#define F8 -66
#define MAX 10000
#define MAXDS 1000
#define maxsach 1000
#define STACKSIZE 500
using namespace std;

// THONG BAO ESC TRONG DANH SACH DOC GIA

int ThongBao_ESC() {
	int key, count = 0;
	TextColor(206); gotoxy(25, 12);
	printf("     Ban Co Muon Luu Vao File!   ");
	gotoxy(25, 13);	printf("   ");
	gotoxy(55, 13);	printf("   ");
	gotoxy(25, 14);	printf("   ");
	gotoxy(55, 14);	printf("   ");
	gotoxy(25, 15);	printf("   ");
	gotoxy(55, 15);	printf("   ");
	gotoxy(25, 16);	printf("                                 ");
	TextColor(238); gotoxy(28, 13); printf("                           ");
	gotoxy(28, 14); printf("                           ");
	gotoxy(28, 15); printf("                           ");
	TextColor(252);	gotoxy(33, 14);	printf(" YES ");
	TextColor(233);	gotoxy(45, 14);	printf(" NO ");
	gotoxy(34, 14);
	while (1) {
		key = GetKey();
		if (key == LEFT || key == RIGHT) {
			count++;
			if (count % 2 == 1) {
				TextColor(233);		gotoxy(33, 14); printf(" YES ");
				TextColor(252);		gotoxy(45, 14); printf(" NO ");
				gotoxy(46, 14);
			}
			else {
				TextColor(252);		gotoxy(33, 14); printf(" YES ");
				TextColor(233);		gotoxy(45, 14); printf(" NO ");
				gotoxy(34, 14);
			}
		}
		if (key == ENTER) {
			if (count == 0) {
				return 1;
			}
			else {
				if (count % 2 == 1) {
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (key == ESC) {
			return -1;
		}
	}
}


// THONG TIN CHUNG
void ThongTinChung() {
	TextColor(91);
	gotoxy(60, 9);  printf(" ¶¶   ¶¶                              ¶¶                 ");
	gotoxy(60, 10); printf("¶¶¶¶  ¶¶                                                 ");
	gotoxy(60, 11);	printf(" ¶¶   ¶¶  ¶¶    ¶¶   ¶¶    ¶¶     ¶¶  ¶¶   ¶¶¶¶   ¶¶ ¶¶  ");
	gotoxy(60, 12); printf(" ¶¶   ¶¶¶   ¶¶  ¶¶   ¶¶     ¶¶   ¶¶   ¶¶  ¶¶  ¶¶  ¶¶¶  ¶¶");
	gotoxy(60, 13); printf(" ¶¶   ¶¶    ¶¶  ¶¶   ¶¶      ¶¶ ¶¶    ¶¶  ¶¶¶     ¶¶   ¶¶");
	gotoxy(60, 14); printf(" ¶¶¶  ¶¶    ¶¶   ¶¶¶¶¶        ¶¶      ¶¶   ¶¶¶¶¶  ¶¶   ¶¶");
	gotoxy(60, 15); printf("      __...--~~~~~-._   _.-~~~~~--...__                  ");
	gotoxy(60, 16); printf("    //               `V'               \\\\                ");
	gotoxy(60, 17); printf("   //                 |                 \\\\               ");
	gotoxy(60, 18); printf("  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\\\              ");
	gotoxy(60, 19); printf(" //__.....----~~~~._\\\ | /_.~~~~----.....__\\\\             ");
	gotoxy(60, 20); printf("====================\\\\|//====================            ");
}

//KHUNG NHAP DOC GIA
void Khung_Nhap_DocGia() {
	gotoxy(0, 0);
	TextColor(90);
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");
	printf("\n   |     |		 |		      |          |	    |	               |");
	printf("\n   |-----+---------------+--------------------+----------+----------+------------------|");
	printf("\n   |	 |               |       	      |          |          |                  |");
	printf("\n   |	 |         	 |		      |	         |	    |                  |");
	printf("\n   | 	 |	         |		      |		 |	    |                  |");
	printf("\n   |	 |	         |		      | 	 |          |                  |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |-----------------------------------------------------------------------------------|");
	printf("\n   |                                                                                   |");
	printf("\n   +-----------------------------------------------------------------------------------+");
	TextColor(236);	gotoxy(33, 1);	printf("                              ");
	gotoxy(33, 2);	printf("   NHAP DANH SACH DOC GIA     ");
	gotoxy(33, 3);	printf("                              ");
	TextColor(94);	gotoxy(5, 6);    printf("STT");
	gotoxy(12, 6);	printf("MA DOC GIA");
	gotoxy(35, 6);	printf("HO");
	gotoxy(51, 6);	printf("TEN");
	gotoxy(61, 6);	printf("PHAI");
	gotoxy(72, 6);	printf("TRANG THAI THE");
	gotoxy(4, 24);	TextColor(252);	printf("ESC");
	TextColor(91);	printf(": Exit");
	gotoxy(20, 24);	TextColor(252);	printf("ENTER");
	TextColor(91);	printf(": OK");
	gotoxy(36, 24);
	TextColor(252);	printf("CONTROL");
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN");
	gotoxy(0, 27);
}

// KHUNG XUAT DOC GIA
void Khung_Xuat_DG() {
	gotoxy(0, 0);
	TextColor(90);
	printf("\n\n\n\n\n   +-----------------------------------------------------------------------------------+");
	printf("\n   |     |		 |		      |          |	    |	               |");
	printf("\n   |-----+---------------+--------------------+----------+----------+------------------|");
	printf("\n   |     |               |       	      |          |          |                  |");
	printf("\n   |     |         	 |		      |	         |	    |                  |");
	printf("\n   |     |	         |		      |		 |	    |                  |");
	printf("\n   |     |	         |		      | 	 |          |                  |");
	printf("\n   |     |	         |		      |		 |          |	               |");
	printf("\n   |     |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |	 |	         |		      |		 |          |	               |");
	printf("\n   |-----------------------------------------------------------------------------------|");
	printf("\n   |                                                                                   |");
	printf("\n   +-----------------------------------------------------------------------------------+");
	TextColor(236);	gotoxy(33, 1);	printf("                              ");
	gotoxy(33, 2);	printf("   XUAT DANH SACH DOC GIA     ");
	gotoxy(33, 3);	printf("                              ");
	TextColor(94);	gotoxy(5, 6);    printf("STT");
	gotoxy(12, 6);	printf("MA DOC GIA");
	gotoxy(35, 6);	printf("HO");
	gotoxy(51, 6);	printf("TEN");
	gotoxy(61, 6);	printf("PHAI");
	gotoxy(72, 6);	printf("TRANG THAI THE");
	gotoxy(4, 24);	TextColor(252);	printf("ESC");
	TextColor(91);	printf(": Exit");
	gotoxy(18, 24);	TextColor(252);	printf("F1");
	TextColor(91);	printf(": Insert");
	gotoxy(35, 24);	TextColor(252);	printf("F2");
	TextColor(91);	printf(": Edit");
	gotoxy(50, 24);	TextColor(252);	printf("F3");
	TextColor(91);	printf(": Delete"); TextColor(252);
	gotoxy(95, 9); printf("^");
	gotoxy(91, 11); printf("<");
	gotoxy(99, 11); printf(">");
	gotoxy(95, 13); printf("v");
	gotoxy(90, 15); printf("UP");
	gotoxy(90, 17); printf("DOWN");
	gotoxy(90, 19); printf("LEFT");
	gotoxy(90, 21); printf("RIGHT");
	TextColor(91); gotoxy(95, 15); printf(": LEN");
	gotoxy(95, 17); printf(": XUONG");
	gotoxy(95, 19); printf(": TRAI");
	gotoxy(95, 21); printf(": PHAI");
	gotoxy(0, 27);
}

//KHUNG XUAT DOC GIA MUON QUA HAN
void Khung_Xuat_Qua_Han() {
	gotoxy(0, 0);
	TextColor(90);
	printf("\n\n\n\n\n   +-------------------------------------------------------------------------------------------------------+");
	printf("\n   |     |		 |		      |          |	    |	               |                   |");
	printf("\n   |-----+---------------+--------------------+----------+----------+------------------+-------------------|");
	printf("\n   |     |               |       	      |          |          |                  |                   |");
	printf("\n   |     |         	 |		      |	         |	    |                  |                   |");
	printf("\n   |     |	         |		      |		 |	    |                  |                   |");
	printf("\n   |     |	         |		      | 	 |          |                  |                   |");
	printf("\n   |     |	         |		      |		 |          |	               |                   |");
	printf("\n   |     |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |	 |	         |		      |		 |          |	               |                   |");
	printf("\n   |-------------------------------------------------------------------------------------------------------|");
	printf("\n   |                                                                                                       |");
	printf("\n   +-------------------------------------------------------------------------------------------------------+");
	TextColor(236);	gotoxy(33, 1);	printf("                              ");
	gotoxy(33, 2);	printf("     DOC GIA MUON QUA HAN     ");
	gotoxy(33, 3);	printf("                              ");
	TextColor(94);	gotoxy(5, 6);    printf("STT");
	gotoxy(12, 6);	printf("MA DOC GIA");
	gotoxy(35, 6);	printf("HO");
	gotoxy(51, 6);	printf("TEN");
	gotoxy(61, 6);	printf("PHAI");
	gotoxy(72, 6);	printf("TRANG THAI THE");
	gotoxy(90, 6);  printf("SO NGAY QUA HAN");
	gotoxy(4, 39);	TextColor(252);	printf("ESC");
	TextColor(91);	printf(": Exit");
	gotoxy(18, 39);	TextColor(252);	printf("LEFT");
	TextColor(91);	printf(": <-");
	gotoxy(35, 39);	TextColor(252);	printf("RIGHT");
	TextColor(91);	printf(": ->");
}

// KHUNG THEM 1 DOC GIA
void Khung_Them_DG() {
	TextColor(111); gotoxy(10, 13); printf("     MA DOC GIA              HO              TEN     PHAI  TRANG THAI     ");
	gotoxy(10, 14); printf("  ");
	gotoxy(27, 14); printf("  ");
	gotoxy(49, 14); printf("  ");
	gotoxy(61, 14); printf("  ");
	gotoxy(66, 14); printf("  ");
	gotoxy(82, 14); printf("  ");
	gotoxy(10, 15); printf("                                                                          ");
	TextColor(108);
	gotoxy(55, 15); printf("Enter:");
	gotoxy(71, 15); printf("ESC:");
	TextColor(105);	gotoxy(62, 15); printf("OK");
	gotoxy(76, 15); printf("Exit");
	TextColor(12);	gotoxy(12, 14); printf("               ");
	gotoxy(29, 14); printf("                    ");
	gotoxy(51, 14); printf("          ");
	gotoxy(63, 14); printf("   ");
	gotoxy(68, 14); printf("              ");
}

// KHUNG SUA DOC GIA
void Khung_Sua_DG() {
	TextColor(111);	gotoxy(30, 13); printf("                         ");
	gotoxy(30, 14); printf("                         ");
	gotoxy(30, 15); printf("                         ");
	TextColor(107); gotoxy(30, 13); printf("Nhap Ma Doc Gia Can Sua");
	TextColor(108); gotoxy(31, 15); printf("Enter:");
	gotoxy(45, 15); printf("ESC:");
	TextColor(105); gotoxy(38, 15); printf("OK");
	gotoxy(50, 15); printf("Exit");
	TextColor(12);	gotoxy(35, 14); printf("               ");
}

// KHUNG XOA DOC GIA
void Khung_Xoa_DG() {
	TextColor(111);	gotoxy(30, 13); printf("                         ");
	gotoxy(30, 14); printf("                         ");
	gotoxy(30, 15); printf("                         ");
	TextColor(107); gotoxy(30, 13); printf("Nhap Ma Doc Gia Can Xoa");
	TextColor(108); gotoxy(31, 15); printf("Enter:");
	gotoxy(45, 15); printf("ESC:");
	TextColor(105); gotoxy(38, 15); printf("OK");
	gotoxy(50, 15); printf("Exit");
	TextColor(12);	gotoxy(35, 14); printf("               ");
}

// KHUNG TIM DOC GIA
void Khung_Tim_DG() {
	TextColor(111);	gotoxy(30, 13); printf("                             ");
	gotoxy(30, 14); printf("                             ");
	gotoxy(30, 15); printf("                             ");
	TextColor(107); gotoxy(30, 13); printf("Nhap Ma Doc Gia Can Muon Sach");
	TextColor(108); gotoxy(31, 15); printf("Enter:");
	gotoxy(45, 15); printf("ESC:");
	TextColor(105); gotoxy(38, 15); printf("OK");
	gotoxy(50, 15); printf("Exit");
	TextColor(12);	gotoxy(35, 14); printf("                 ");
}

// KHUNG MUON SACH
void Khung_Muon_Sach(){
	TextColor(111); gotoxy(100, 13); printf("     MA SACH         NGAY     THANG     NAM    ");
	gotoxy(100, 14); printf("  ");
	gotoxy(118, 14); printf("  ");
	gotoxy(127, 14); printf("  ");
	gotoxy(136, 14); printf("  ");
	gotoxy(145, 14); printf("  ");
	gotoxy(100, 15); printf("                                               ");
	TextColor(108);
	gotoxy(125, 15); printf("Enter:");
	gotoxy(136, 15); printf("ESC:");
	TextColor(105);	gotoxy(132, 15); printf("OK");
	gotoxy(140, 15); printf("Exit");
	TextColor(12);	gotoxy(102, 14); printf("                ");
	gotoxy(120, 14); printf("       ");
	gotoxy(129, 14); printf("       ");
	gotoxy(138, 14); printf("       ");                   
}

// KHUNG HIEN THI MUON - TRA SACH
void Khung_Hien_Thi_Tra_Sach(){
	gotoxy(0, 0);
	TextColor(90);
	gotoxy(100, 13); printf("+----------------------------------------------------+");
	gotoxy(100, 14); printf("|                                                    |");
	gotoxy(100, 15); printf("|                                                    |");
	gotoxy(100, 16); printf("|                                                    |");
	gotoxy(100, 17); printf("+---------------------------------------------------+");
	gotoxy(100, 18); printf("|        TEN SACH              |MA SACH|  NGAY MUON  |");
	gotoxy(100, 19); printf("+------------------------------+-------+-------------+");
	gotoxy(100, 20); printf("|                              |       |             |");
	gotoxy(100, 21); printf("|                              |       |             |");
	gotoxy(100, 22); printf("|                              |       |             |");
	gotoxy(100, 23); printf("+------------------------------+-------+-------------+");
}

// KHUNG TRA SACH
void Khung_Trong_Luc_Tra_Sach(){
	gotoxy(0, 0);
	TextColor(90);
	gotoxy(20, 13); printf("+----------------------------------------------------+");
	gotoxy(20, 14); printf("|                                                    |");
	gotoxy(20, 15); printf("|                                                    |");
	gotoxy(20, 16); printf("|                                                    |");
	gotoxy(20, 17); printf("+----------------------------------------------------+");
	gotoxy(20, 18); printf("|        TEN SACH              |MA SACH|  NGAY MUON  |");
	gotoxy(20, 19); printf("+------------------------------+-------+-------------+");
	gotoxy(20, 20); printf("|                              |       |             |");
	gotoxy(20, 21); printf("|                              |       |             |");
	gotoxy(20, 22); printf("|                              |       |             |");
	gotoxy(20, 23); printf("+------------------------------+-------+-------------+");
}

// KHUNG CLS TRA SACH
void Khung_Xoa(){
	gotoxy(0, 0);
	TextColor(90);
	gotoxy(20, 13); printf("                                                      ");
	gotoxy(20, 14); printf("                                                      ");
	gotoxy(20, 15); printf("                                                      ");
	gotoxy(20, 16); printf("                                                      ");
	gotoxy(20, 17); printf("                                                      ");
	gotoxy(20, 18); printf("                                                      ");
	gotoxy(20, 19); printf("                                                      ");
	gotoxy(20, 20); printf("                                                      ");
	gotoxy(20, 21); printf("                                                      ");
	gotoxy(20, 22); printf("                                                      ");
	gotoxy(20, 23); printf("                                                      ");
}

//MENU
char MENU[4][30] = { "  1. QUAN LI DOC GIA    ",
"  2. QUAN LI DAU SACH   ",
"  3. QUAN LI SACH       ",
"  4. THOAT              " };

char MENUdocgia[3][30] = { "  1. CAP NHAT DOC GIA      ",
"  2. DANH SACH DOC GIA     ",
"  3. DOC GIA MUON  QUA HAN " };

char MENUdausach[3][30] = { "  1. CAP NHAT DAU SACH     ",
"  2. CAP NHAT DANH MUC SACH",
"  3. HIEN THI DAU SACH     " };

char MENUsach[3][30] = { "  1. MUON SACH             ",
"  2. TRA SACH              ",
"  3. SACH MUON NHIEU NHAT  " };

char MENUindanhsach[2][30] = { "  1. THEO MA THE           ",
"  2. THEO TEN              " };

// CAC HAM TO MAU					
void ToMauMenuChinh(int color, int vitri) {
	TextColor(color);
	gotoxy(0, 5 + vitri * 4); cout << "                        ";
	gotoxy(0, 6 + vitri * 4); cout << MENU[vitri];
	gotoxy(0, 7 + vitri * 4); cout << "                        ";
}

void ToMauMenuCon(int color, char MENUCON[][30], int vitri)
{
	TextColor(color);
	gotoxy(28, 5 + (vitri + 1) * 4);	cout << "                           ";
	gotoxy(28, 6 + (vitri + 1) * 4);	cout << MENUCON[vitri];
	gotoxy(28, 7 + (vitri + 1) * 4);	cout << "                           ";
}

void ToMauMenuXuatDG(int color, int vitri) {
	TextColor(color);
	gotoxy(40, 5 + vitri * 4); cout << "                           ";
	gotoxy(40, 6 + vitri * 4); cout << MENUindanhsach[vitri];
	gotoxy(40, 7 + vitri * 4); cout << "                           ";
}

// SAVE DOC GIA
int CountNodeMT(nodemuontra First){ // dem so sach doc gia da muon
	nodemuontra p = First;
	int size = 0;
	while(p != NULL){
		size++;
		p = p->right;
	}
	return size;
}

void LuuFileDG(treedocgia root) {
	fstream f; 
	f.open("DANHSACHDOCGIA.txt", ios::out);
	treedocgia Stack[STACKSIZE];
	treedocgia p = root;
	int sp = -1;
	do {
		while (p != NULL) {
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1) {
			p = Stack[sp--];
			nodemuontra mt = p->info.pMT;
			f << p->info.mathe << endl;
			f << p->info.ho << endl;
			f << p->info.ten << endl;
			f << p->info.phai << endl;
			f << p->info.trangthai << endl;
			f << CountNodeMT(p->info.pMT)<<endl;
			while(mt != NULL){
				f << mt->info.masach << endl;
				
				f << mt->info.ngaymuon.ngay << endl;
				f << mt->info.ngaymuon.thang << endl;
				f << mt->info.ngaymuon.nam << endl;
				
				f << mt->info.ngaytra.ngay <<endl;
				f << mt->info.ngaytra.thang <<endl;
				f << mt->info.ngaytra.nam <<endl;
				f << mt->info.trangthai << endl;
				mt = mt->right;
			}
			p = p->right;
		}
		else break;
	} while (1);
	f.close();
}		

// MENU CON
int MenuCon(int item, char MENUCON[][30])
{
	// color(252): nen trang chu do; color(236): nen vang chu do
	char key;
	int vitri = 0;
	while (1)
	{
		key = GetKey();
		if (key == ENTER)
			return vitri + 1;
		if (key == ESC || key == LEFT)
			return 0;
		switch (key)
		{
		case DOWN:
		{
			if (vitri == (item - 1))
			{
				ToMauMenuCon(252, MENUCON, vitri); 
				vitri = 0;
				ToMauMenuCon(236, MENUCON, vitri); 
			}
			else
			{
				ToMauMenuCon(252, MENUCON, vitri); 
				vitri++;
				ToMauMenuCon(236, MENUCON, vitri); 
			}
		}break;
		case UP:
		{
			if (vitri == 0)
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri = item - 1;
				ToMauMenuCon(236, MENUCON, vitri);
			}
			else
			{
				ToMauMenuCon(252, MENUCON, vitri);
				vitri--;
				ToMauMenuCon(236, MENUCON, vitri);
			}
		}break;
		}
	}
}

int MenuInDG() { // menu chon In DG theo MADG or TEN
	//color(188): nen xanh chu do; color(236): nen vang chu do
	int vitri = 0;
	while (1) {
		char key = GetKey();
		if (key == ENTER) return vitri + 1;
		if (key == ESC) return 0;
		switch (key) {
		case DOWN: {
			if (vitri == 1) {
				ToMauMenuXuatDG(188, vitri);
				vitri = 0;
				ToMauMenuXuatDG(236, vitri);
			}
			else {
				ToMauMenuXuatDG(188, vitri);
				vitri++;
				ToMauMenuXuatDG(236, vitri);
			}
			break;
		}
		case UP: {
			if (vitri == 0) {
				ToMauMenuXuatDG(188, vitri);
				vitri = (2 - 1);
				ToMauMenuXuatDG(236, vitri);
			}
			else {
				ToMauMenuXuatDG(188, vitri);
				vitri--;
				ToMauMenuXuatDG(236, vitri);
			}
			break;
		}
		}

	}
}

int MenuCha() {
	//color(188): nen xanh chu do; color(236): nen vang chu do
	int vitri = 0;
	while (1) {
		ThongTinChung();
		char key = GetKey();
		if (key == ENTER || (key == RIGHT && vitri != 3)) // vitri!= 3 la ngay tai o Thoát
		{
			return vitri + 1;
		}
		switch (key) {
		case DOWN: {
			if (vitri == 3) {
				ToMauMenuChinh(188, vitri);
				vitri = 0;
				ToMauMenuChinh(236, vitri);
			}
			else {
				ToMauMenuChinh(188, vitri);
				vitri++;
				ToMauMenuChinh(236, vitri);
			}
			break;
		}
		case UP: {
			if (vitri == 0)
			{
				ToMauMenuChinh(188, vitri);
				vitri = (4 - 1);
				ToMauMenuChinh(236, vitri);
			}
			else
			{
				ToMauMenuChinh(188, vitri);
				vitri--;
				ToMauMenuChinh(236, vitri);
			}
			break;
		}
		}
	}
}

/************************* THEM-XOA-SUA DOC GIA ******************************/
void KhoiTaoTreeDG(treedocgia &root) {
	root = NULL;
}

int KiemTraRong(treedocgia root) {
	return(root == NULL ? TRUE : FALSE);
}

void Insert_nodeDG(treedocgia &p, int x, DocGia dg[], int dem) { // Insert mang DocGia vao TreeDocGia
	if (p == NULL) {
		p = new TreeDocGia;
		p->info.mathe = x; p->info = dg[dem];
		p->left = NULL; p->right = NULL;
	}
	else if (x < p->info.mathe) Insert_nodeDG(p->left, x, dg, dem);
	else if (x > p->info.mathe) Insert_nodeDG(p->right, x, dg, dem);
}

void DocFileDG(treedocgia &list) { // Load DocGia tu trong File
	int i = 0; int so_sach_muon = 0; MuonTra mt[MAX];
	string data;
	fstream f;
	f.open("DANHSACHDOCGIA.txt", ios::in);
	while (!f.eof()) {
		DocGia dg[MAX];
		getline(f, data);
		if (data.size() == 0) break; // ket thuc sao chep data neu kich thuoc cua data = 0
		dg[i].mathe = atoi(data.c_str()); // c_str(): chuyen tu std:: string sang char*
		getline(f, data); strcpy(dg[i].ho, data.c_str()); 
		getline(f, data); strcpy(dg[i].ten, data.c_str());
		getline(f, data); strcpy(dg[i].phai, data.c_str());
		getline(f, data); dg[i].trangthai = atoi(data.c_str());
		getline(f, data); so_sach_muon = atoi(data.c_str());
		
		for(int j = 0; j < so_sach_muon ; j++){

			getline(f, data);
			if(data.size() == 0)	break;
			strcpy(mt[j].masach, data.c_str());
			
			getline(f, data); mt[j].ngaymuon.ngay = atoi(data.c_str());
			getline(f, data); mt[j].ngaymuon.thang = atoi(data.c_str());
			getline(f, data); mt[j].ngaymuon.nam = atoi(data.c_str());
			getline(f, data); mt[j].ngaytra.ngay = atoi(data.c_str());
			getline(f, data); mt[j].ngaytra.thang = atoi(data.c_str());
			getline(f, data); mt[j].ngaytra.nam = atoi(data.c_str());
			getline(f, data); mt[j].trangthai = atoi(data.c_str());
			Insert_Firstmuontra(dg[i].pMT, mt, j);
		}

		
		Insert_nodeDG(list, dg[i].mathe, dg, i);
		i++;
	}
	f.close();
}

int DemDG(treedocgia p) { // Dem so luong DocGia
	int c = 1;
	if (p == NULL) return 0;
	else {
		c += DemDG(p->left);
		c += DemDG(p->right);
		return c;
	}
}

int KiemTraMaDG(treedocgia p, int maDG) { // KiemTra ma DocGia, Duyet den khi p = NULL
	if (p == NULL) return 0;
	else if (p->info.mathe == maDG) return 1; // trung maDG return 1
	else if (p->info.mathe < maDG) {
		return KiemTraMaDG(p->right, maDG);
	}
	else {
		return KiemTraMaDG(p->left, maDG);
	}
}

int Random() {
	srand(time(NULL));
	int x;
	// bo ham rand() vao vong lap moi khong bi loi tang dan, hay giam dan.
	for (int i = 0; i < 500; i++) {
		x = rand();
	}
	return x;
}

int RandomMaDG(treedocgia p) {

	int temp;
	do {
		temp = Random();
	} while (KiemTraMaDG(p, temp));
	return temp;
}

void SapXepDG_TheoMDG(treedocgia root, DocGia dg[]) { // Sap xep DocGia In ra danh sach theo MaDG tang dan
	treedocgia Stack[STACKSIZE];
	treedocgia p = root;
	int sp = -1;
	int index = 0;
	do {
		while (p != NULL) {
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1) {
			p = Stack[sp--];
			dg[index].mathe = p->info.mathe;
			strcpy(dg[index].ho, p->info.ho);
			strcpy(dg[index].ten, p->info.ten);
			strcpy(dg[index].phai, p->info.phai);
			dg[index].trangthai = p->info.trangthai;
			index++;
			p = p->right;
		}
		else break;
	} while (1);
}

// SAP XEP DOC GIA THEO THU TU TEN TANG DAN
void TreeToArr(treedocgia &root, DocGia dg[], int &vitri) { // Do du lieu tu cay vao mang de tien hanh Sort tren mang
	if (root != NULL) {
		TreeToArr(root->left, dg, vitri);
		dg[vitri++] = root->info;
		TreeToArr(root->right, dg, vitri);
	}
}

void SwapDG(DocGia &a, DocGia &b) {
	DocGia temp = a;
	a = b;
	b = temp;
}

SapXepDG_TheoHoTen(treedocgia root, DocGia dg[], int soluongnode){
	int i, j;
	char s1[100], s2[100];
	for(int i = 1; i < soluongnode; i++){
		for(int j = soluongnode - 1; j >= i; j--){
			strcpy(s1, dg[j].ten);
			strcat(s1, dg[j].ho); // noi chuoi ten + ho
			strcpy(s2, dg[j-1].ten);
			strcat(s2, dg[j-1].ho);
			if(stricmp(s1, s2) < 0) SwapDG(dg[j - 1], dg[j]);
			// stricmp(s1,s2); 
			// s1 > s2: >0, s1 < s2: <0, s1 = s2: =0
		}
	}
}

void NhapDocGia(treedocgia &root) {
	DocGia dg[MAX];
	for (int i = 0; i < MAX; i++) // Khoi tao mang tam
	{
		dg[i].mathe = NULL; dg[i].ho[0] = NULL; dg[i].ten[0] = NULL; dg[i].phai[0] = NULL; dg[i].trangthai = NULL;
	}
	int key, y = 8, vitri = 0, dem = 0, demkhongdoi = 0 /*dem khong doi:dem DocGia da nhap day du thong tin*/, temp, STT = 1; bool check_change = false;
	Khung_Nhap_DocGia();
	TextColor(92);		gotoxy(6, 8); 	 cout << STT;		TextColor(91); //In STT dau tien
MADOCGIA:
	while (1) {
		if ((dg[dem - 1].trangthai < 0 && dg[dem - 1].trangthai > 1) && y > 8) {
			GhiChu("Ban Chua Nhap Trang Thai!", 35, 27, 74, 700);
			gotoxy(69, --y);
			dem--;
			goto TRANGTHAI;
		}
		TextColor(91); gotoxy(10 + vitri, y);
		dg[dem].mathe = RandomMaDG(root);
		cout << dg[dem].mathe;
		vitri = strlen(dg[dem].ho);
		gotoxy(26 + vitri, y);
		goto HO;
	}
HO:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                              ");
		gotoxy(20, 30); printf("      HO: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 20 KI TU       ");
		gotoxy(20, 31); printf("                                                              ");
		TextColor(91); gotoxy(26 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 20)) {
			dg[dem].ho[vitri] = char(key);
			dg[dem].ho[vitri] = toupper(dg[dem].ho[vitri]);
			cout << dg[dem].ho[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(26 + vitri, y);
			cout << " ";
			gotoxy(26 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			if (dg[dem].ho[vitri - 1] == ' ') { vitri--; }//KT khi enter truoc do co phai khoang trang
			dg[dem].ho[vitri] = '\0';
			vitri = strlen(dg[dem].ten);
			gotoxy(47 + vitri, y);
			goto TEN;
		}
		if (key == SPACE && dg[dem].ho[vitri - 1] != ' ' && vitri > 0 && vitri < 20) {
			gotoxy(26 + vitri, y);
			cout << " ";
			dg[dem].ho[vitri] = ' ';
			vitri++;
		}
		if (key == ESC) {
			if (check_change == true) {
				dg[dem].ho[vitri] = '\0';
				putchar(7);	gotoxy(4, 24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	{//-1 la bat them duoc 1 phim ESC nua
					gotoxy(4, 24);  TextColor(252);	printf("ESC"); TextColor(91); continue; //Tô màu ESC
				}
				if (temp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 74, 2000);
					for (int i = 0; i < demkhongdoi; i++)
						Insert_nodeDG(root, dg[i].mathe, dg, i);
					/*ham luu ds doc gia*/
					LuuFileDG(root);
				}
				if (temp == 0) {
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 74, 2000);
					for (int i = 0; i < demkhongdoi; i++)
						Insert_nodeDG(root, dg[i].mathe, dg, i);//day vao tree doc gia
				}
			}
			system("cls");	return;
		}
		if (key == RIGHT) {
			dg[dem].ho[vitri] = '\0';
			vitri = strlen(dg[dem].ten);
			gotoxy(47 + vitri, y);
			goto TEN;
		}
		if (key == UP && y > 8) {
			dg[dem].ho[vitri] = '\0';
			dem--;
			vitri = strlen(dg[dem].ho);
			gotoxy(26 + vitri, --y);
		}
		if (key == DOWN && y < 22 && dg[1 + dem].ho[0] != '\0') {
			dg[dem].ho[vitri] = '\0';
			dem++;
			vitri = strlen(dg[dem].ho);
			gotoxy(26 + vitri, ++y);
		}
	}

TEN:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                               ");
		gotoxy(20, 30); printf("          TEN: GOM CAC KI TU (A-Z), TOI DA: 10 KI TU           ");
		gotoxy(20, 31); printf("                                                               ");
		TextColor(91); gotoxy(47 + vitri, y);
		key = GetKey();
		if (dg[dem].ho[0] == '\0') {
			GhiChu("Ban Chua Nhap Ho!", 35, 27, 74, 700);
			gotoxy(26, y);
			goto HO;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 10)) {
			dg[dem].ten[vitri] = char(key);
			dg[dem].ten[vitri] = toupper(dg[dem].ten[vitri]);
			cout << dg[dem].ten[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(47 + vitri, y);
			cout << " ";
			gotoxy(47 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			dg[dem].ten[vitri] = '\0';
			vitri = strlen(dg[dem].phai);
			gotoxy(58 + vitri, y);
			goto PHAI;
		}
		if (key == ESC) {
			if (check_change == true) {
				dg[dem].ten[vitri] = '\0';
				putchar(7);	gotoxy(4, 24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoxy(4, 24);  TextColor(252);	printf("ESC"); TextColor(91); continue;//Tô màu ESC
				}
				if (temp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 74, 2000);
					for (int i = 0; i < demkhongdoi; i++)
						Insert_nodeDG(root, dg[i].mathe, dg, i);
					/*cac ham Save file*/
					LuuFileDG(root);
				}
				if (temp == 0) {
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 74, 2000);
					for (int i = 0; i < demkhongdoi; i++)
						Insert_nodeDG(root, dg[i].mathe, dg, i);
				}
			}
			system("cls");	return;
		}
		if (key == LEFT) {
			dg[dem].ten[vitri] = '\0';
			vitri = strlen(dg[dem].ho);
			gotoxy(26 + vitri, y);
			goto HO;
		}
		if (key == RIGHT) {
			dg[dem].ten[vitri] = '\0';
			vitri = strlen(dg[dem].phai);
			gotoxy(58 + vitri, y);
			goto PHAI;
		}
		if (key == UP && y > 8) {
			dg[dem].ten[vitri] = '\0';
			dem--;
			vitri = strlen(dg[dem].ten);
			gotoxy(47 + vitri, --y);
		}
		if (key == DOWN && y < 22 && dg[1 + dem].ten[0] != '\0') {
			dg[dem].ten[vitri] = '\0';
			dem++;
			vitri = strlen(dg[dem].ten);
			gotoxy(47 + vitri, ++y);
		}
	}
PHAI:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                                ");
		gotoxy(20, 30); printf("      PHAI: GOM CAC KI TU (A-Z) - NAM/NU, TOI DA: 3 KI TU       ");
		gotoxy(20, 31); printf("                                                                "); 	TextColor(91); gotoxy(58 + vitri, y);
		key = GetKey();
		if (dg[dem].ten[0] == '\0') {
			GhiChu("Ban Chua Nhap Ten!", 35, 27, 74, 700);
			gotoxy(47, y);
			goto TEN;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 3)) {
			dg[dem].phai[vitri] = char(key);
			dg[dem].phai[vitri] = toupper(dg[dem].phai[vitri]);
			cout << dg[dem].phai[vitri];
			vitri++;
			dg[dem].phai[vitri] = '\0';
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(58 + vitri, y);
			cout << " ";
			gotoxy(58 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			dg[dem].phai[vitri] = '\0';
			if ((strcmp(dg[dem].phai, "NAM") == 0) || (strcmp(dg[dem].phai, "NU") == 0)) // So sanh
			{
				vitri = 0;
				gotoxy(69 + vitri, y);
				goto TRANGTHAI;
			}
			GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500); continue;
		}
		if (key == ESC) {
			if (check_change == true)
			{
				putchar(7);	gotoxy(4, 24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoxy(4, 24);  TextColor(252);	printf("ESC"); TextColor(91); continue;//Tô màu ESC
				}
				if (temp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 74, 2000);
					for (int i = 0; i < demkhongdoi; i++)
						Insert_nodeDG(root, dg[i].mathe, dg, i);
					/*Ham Save File*/
					LuuFileDG(root);
				}
				if (temp == 0) {
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 74, 2000);
					for (int i = 0; i < demkhongdoi; i++)
						Insert_nodeDG(root, dg[i].mathe, dg, i);
				}
			}
			system("cls"); 	return;
		}
		if (key == LEFT) {
			dg[dem].phai[vitri] = '\0';
			if ((strcmp(dg[dem].phai, "NAM") != 0) && (strcmp(dg[dem].phai, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500);	continue;
			}
			vitri = strlen(dg[dem].ten);
			gotoxy(47 + vitri, y);
			goto TEN;
		}
		if (key == RIGHT) {
			dg[dem].phai[vitri] = '\0';
			if ((strcmp(dg[dem].phai, "NAM") != 0) && (strcmp(dg[dem].phai, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500);	continue;
			}
			vitri = 0;
			gotoxy(69 + vitri, y);
			goto TRANGTHAI;
		}
		if (key == UP && y > 8) {
			dg[dem].phai[vitri] = '\0';
			if ((strcmp(dg[dem].phai, "NAM") != 0) && (strcmp(dg[dem].phai, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500);	continue;
			}
			dem--;
			vitri = strlen(dg[dem].phai);
			gotoxy(58 + vitri, --y);
		}
		if (key == DOWN && y < 22 && dg[1 + dem].phai[0] != '\0') {
			dg[dem].phai[vitri] = '\0';
			if ((strcmp(dg[dem].phai, "NAM") != 0) && (strcmp(dg[dem].phai, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500);	continue;
			}
			dem++;
			vitri = strlen(dg[dem].phai);
			gotoxy(58 + vitri, ++y);
		}
	}

TRANGTHAI:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                               ");
		gotoxy(20, 30); printf("     CHI SO:(0 hoac 1) 0: BI KHOA   1: DANG HOAT DONG          ");
		gotoxy(20, 31); printf("                                                               ");
		TextColor(91);	gotoxy(69 + vitri, y);
		key = GetKey();
		if (dg[dem].phai[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Gioi Tinh!", 35, 27, 74, 700);
			gotoxy(63, y);
			goto PHAI;
		}
		if (key >= '0' && key <= '1') {
			if (key == '1') {
				dg[dem].trangthai = 1;
			}
			else if (key == '0') {
				dg[dem].trangthai = 0;
			}
		}
		if (dg[dem].trangthai == 1) cout << " DANG HOAT DONG";
		else if (dg[dem].trangthai == 0) cout << " BI KHOA       ";
		else cout << "               ";
		if (key == ENTER && (dg[dem].trangthai == 0 || dg[dem].trangthai == 1)) {
			check_change = true; // check_change thay xac nhan doc gia da cap nhan day du thong tin
			GhiChu("Save Thanh Cong!", 40, 27, 74, 500);	TextColor(92);
			gotoxy(6, y + 1);
			if (dem == demkhongdoi) {
				cout << ++STT; //Cho xuat hien STT
				demkhongdoi++;
			}
			if ((STT - 1) % 15 == 0) {
				y = 7;
				system("cls");
				Khung_Nhap_DocGia();	TextColor(92);	gotoxy(6, 8); cout << STT;
			}
			TextColor(91);
			dem++;
			vitri = 0;
			gotoxy(10 + vitri, ++y);
			goto MADOCGIA;
		}
		if (key == ESC) {
			if (check_change == true) {
				putchar(7);	gotoxy(4, 24);  TextColor(251);	printf("ESC"); //Tô màu ESC
				int temp = ThongBao_ESC_Nhap();
				if (temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoxy(4, 24);  TextColor(252);	printf("ESC"); TextColor(91);	continue;//Tô màu ESC
				}
				if (temp == 1) {
					GhiChu("Luu Vao File Thanh Cong!", 35, 27, 74, 2000);
					for (int i = 0; i < demkhongdoi; i++)
						Insert_nodeDG(root, dg[i].mathe, dg, i);
					/*Ham Save File*/
					LuuFileDG(root);
				}
				if (temp == 0) {
					GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 74, 2000);
					for (int i = 0; i < demkhongdoi; i++)
						Insert_nodeDG(root, dg[i].mathe, dg, i);
				}
			}
			system("cls");	return;
		}
		if (key == LEFT) {
			vitri = strlen(dg[dem].phai);
			gotoxy(58 + vitri, y);
			goto PHAI;
		}
		if (key == UP && y > 8) {
			dem--;
			vitri = 0;
			gotoxy(69 + vitri, --y);
		}
		if (key == DOWN && y < 22 && dg[1 + dem].trangthai != -1) {
			dem++;
			vitri = 0;
			gotoxy(69 + vitri, ++y);
		}

	}
}

/*THEM 1 DOC GIA*/
void ThemDocGia(treedocgia &root, bool &check_change) {
	int key, check_trung, vitri = 0, x = 12, y = 14, temp = 0;
	DocGia dg[1]; dg[0].mathe = NULL; dg[0].ho[0] = NULL; dg[0].ten[0] = NULL; dg[0].phai[0] = NULL; dg[0].trangthai = NULL;
	Khung_Them_DG(); gotoxy(x, y);
MADOCGIA:
	while (1) {
		TextColor(12); gotoxy(12 + vitri, y);
		dg[0].mathe = RandomMaDG(root);
		cout << dg[0].mathe;
		vitri = strlen(dg[0].ho);
		gotoxy(29 + vitri, y);
		goto HO;
	}
HO:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                              ");
		gotoxy(20, 30); printf("      HO: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 20 KI TU       ");
		gotoxy(20, 31); printf("                                                              ");
		TextColor(91); gotoxy(29 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 20)) {
			dg[0].ho[vitri] = char(key);
			dg[0].ho[vitri] = toupper(dg[0].ho[vitri]);
			cout << dg[0].ho[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(29 + vitri, y);
			cout << " ";
			gotoxy(29 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			if (dg[0].ho[vitri - 1] == ' ') { vitri--; }//KT khi enter truoc do co phai khoang trang
			dg[0].ho[vitri] = '\0';
			vitri = strlen(dg[0].ten);
			gotoxy(51 + vitri, y);
			goto TEN;
		}
		if (key == SPACE && dg[0].ho[vitri - 1] != ' ' && vitri > 0 && vitri < 20) {
			gotoxy(29 + vitri, y);
			cout << " ";
			dg[0].ho[vitri] = ' ';
			vitri++;
		}
		if (key == ESC || key == F1) {
			return;
		}

		if (key == RIGHT) {
			dg[0].ho[vitri] = '\0';
			vitri = strlen(dg[0].ten);
			gotoxy(51 + vitri, y);
			goto TEN;
		}
	}

TEN:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                               ");
		gotoxy(20, 30); printf("          TEN: GOM CAC KI TU (A-Z), TOI DA: 10 KI TU           ");
		gotoxy(20, 31); printf("                                                               ");
		TextColor(91); gotoxy(51 + vitri, y);
		key = GetKey();
		if (dg[0].ho[0] == '\0') {
			GhiChu("Ban Chua Nhap Ho!", 35, 27, 74, 700);
			gotoxy(29, y);
			goto HO;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 10)) {
			dg[0].ten[vitri] = char(key);
			dg[0].ten[vitri] = toupper(dg[0].ten[vitri]);
			cout << dg[0].ten[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(51 + vitri, y);
			cout << " ";
			gotoxy(51 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			dg[0].ten[vitri] = '\0';
			vitri = strlen(dg[0].phai);
			gotoxy(63 + vitri, y);
			goto PHAI;
		}
		if (key == ESC || key == F1) {
			return;
		}
		if (key == LEFT) {
			dg[0].ten[vitri] = '\0';
			vitri = strlen(dg[0].ho);
			gotoxy(29 + vitri, y);
			goto HO;
		}
		if (key == RIGHT) {
			dg[0].ten[vitri] = '\0';
			vitri = strlen(dg[0].phai);
			gotoxy(63 + vitri, y);
			goto PHAI;
		}
	}
PHAI:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                                ");
		gotoxy(20, 30); printf("      PHAI: GOM CAC KI TU (A-Z) - NAM/NU, TOI DA: 3 KI TU       ");
		gotoxy(20, 31); printf("                                                                "); 	TextColor(91); gotoxy(63 + vitri, y);
		key = GetKey();
		if (dg[0].ten[0] == '\0') {
			GhiChu("Ban Chua Nhap Ten!", 35, 27, 74, 700);
			gotoxy(51, y);
			goto TEN;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 3)) {
			dg[0].phai[vitri] = char(key);
			dg[0].phai[vitri] = toupper(dg[0].phai[vitri]);
			cout << dg[0].phai[vitri];
			vitri++;
			dg[0].phai[vitri] = '\0';
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(63 + vitri, y);
			cout << " ";
			gotoxy(63 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			dg[0].phai[vitri] = '\0';
			if ((strcmp(dg[0].phai, "NAM") == 0) || (strcmp(dg[0].phai, "NU") == 0)) // So sanh
			{
				vitri = 0;
				gotoxy(69 + vitri, y);
				goto TRANGTHAI;
			}
			GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500); continue;
		}
		if (key == ESC || key == F1) {
			return;
		}
		if (key == LEFT) {
			dg[0].phai[vitri] = '\0';
			if ((strcmp(dg[0].phai, "NAM") != 0) && (strcmp(dg[0].phai, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500);	continue;
			}
			vitri = strlen(dg[0].ten);
			gotoxy(51 + vitri, y);
			goto TEN;
		}
		if (key == RIGHT) {
			dg[0].phai[vitri] = '\0';
			if ((strcmp(dg[0].phai, "NAM") != 0) && (strcmp(dg[0].phai, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500);	continue;
			}
			vitri = 0;
			gotoxy(68 + vitri, y);
			goto TRANGTHAI;
		}
	}

TRANGTHAI:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                               ");
		gotoxy(20, 30); printf("     CHI SO:(0 hoac 1) 0: BI KHOA   1: DANG HOAT DONG          ");
		gotoxy(20, 31); printf("                                                               ");
		TextColor(91);	gotoxy(68 + vitri, y);
		key = GetKey();
		if (dg[0].phai[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Gioi Tinh!", 35, 27, 74, 700);
			gotoxy(63, y);
			goto PHAI;
		}
		if (key >= '0' && key <= '1') {
			if (key == '1') {
				dg[0].trangthai = 1;
			}
			else if (key == '0') {
				dg[0].trangthai = 0;
			}
		}
		if (dg[0].trangthai == 1) cout << " DANG HOAT DONG";
		else if (dg[0].trangthai == 0) cout << " BI KHOA       ";
		else cout << "               ";
		if (key == ENTER && (dg[0].trangthai == 0 || dg[0].trangthai == 1)) {
			check_change = true;
			GhiChu("Save Thanh Cong!", 40, 27, 74, 500);
			Insert_nodeDG(root, dg[0].mathe, dg, 0);
			return;
		}
		if (key == ESC || key == F1) {
			return;
		}
		if (key == LEFT) {
			vitri = strlen(dg[0].phai);
			gotoxy(63 + vitri, y);
			goto PHAI;
		}
	}
}
/*SUA DOC GIA*/

treedocgia KTDocGia(treedocgia root, char mathe[]) { // kiem tra doc gia co ton tai ? tra ve treedocgia
	treedocgia Stack[STACKSIZE];
	int sp = -1; // khoi tao Stack rong
	treedocgia p = root;
	while (p != NULL) {
		if (p->info.mathe == atoi(mathe)) {
			return p;
		}
		if (p->right != NULL) {
			Stack[++sp] = p->right;
		}
		if (p->left != NULL) {
			p = p->left;
		}
		else if (sp == -1) {
			return 0;
		}
		else p = Stack[sp--];
	}
}
void SuaDocGia(treedocgia &root, bool &check_change) {
	int key, x = 35, y = 14, vitri = 0; char mathe[20]; mathe[0] = NULL;
	treedocgia temp, check_trung; /*check_trung: kiem tra doc gia ton tai?, gan doc gia tim thay vao temp*/
	DocGia dg[1]; dg[0].mathe = NULL; dg[0].ho[0] = NULL; dg[0].ten[0] = NULL; dg[0].phai[0] = NULL; dg[0].trangthai = NULL;
	dg[0].pMT = NULL;
	Khung_Sua_DG();
	gotoxy(x, y);
	while (1) {
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri <= 15)) {
			mathe[vitri] = char(key);
			cout << mathe[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(35 + vitri, y);
			cout << " ";
			gotoxy(35 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			mathe[vitri] = '\0'; //ngat chuoi
			check_trung = KTDocGia(root, mathe);
			if (check_trung != 0) {
				vitri = 0;
				temp = KTDocGia(root, mathe);
				dg[0].pMT = temp->info.pMT;
				break;
			}
			else {
				GhiChu("Ma Doc Gia Khong Ton Tai!", 35, 27, 74, 500);	TextColor(12);	gotoxy(35 + vitri, y);
			}
		}
		if (key == ESC || key == F2) { return; }
	}
	Khung_Them_DG(); x = 12, y = 14; gotoxy(12, y);
MADOCGIA:
	while (1) {
		TextColor(12); gotoxy(12 + vitri, y);
		dg[0].mathe = temp->info.mathe; // giu nguyen ma doc gia
		cout << dg[0].mathe;
		vitri = strlen(dg[0].ho);
		gotoxy(29 + vitri, y);
		goto HO;
	}
HO:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                              ");
		gotoxy(20, 30); printf("      HO: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 20 KI TU       ");
		gotoxy(20, 31); printf("                                                              ");
		TextColor(91); gotoxy(29 + vitri, y);
		key = GetKey();
		if (((key >= 'A' && key <= 'Z') || (key <= '9' && key >= '0') || (key >= 'a' && key <= 'z')) && (vitri < 20)) {
			dg[0].ho[vitri] = char(key);
			dg[0].ho[vitri] = toupper(dg[0].ho[vitri]);
			cout << dg[0].ho[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(29 + vitri, y);
			cout << " ";
			gotoxy(29 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			if (dg[0].ho[vitri - 1] == ' ') { vitri--; }//KT khi enter truoc do co phai khoang trang
			dg[0].ho[vitri] = '\0';
			vitri = strlen(dg[0].ten);
			gotoxy(51 + vitri, y);
			goto TEN;
		}
		if (key == SPACE && dg[0].ho[vitri - 1] != ' ' && vitri > 0 && vitri < 20) {
			gotoxy(29 + vitri, y);
			cout << " ";
			dg[0].ho[vitri] = ' ';
			vitri++;
		}
		if (key == ESC || key == F1) {
			return;
		}

		if (key == RIGHT) {
			dg[0].ho[vitri] = '\0';
			vitri = strlen(dg[0].ten);
			gotoxy(51 + vitri, y);
			goto TEN;
		}
	}

TEN:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                               ");
		gotoxy(20, 30); printf("          TEN: GOM CAC KI TU (A-Z), TOI DA: 10 KI TU           ");
		gotoxy(20, 31); printf("                                                               ");
		TextColor(91); gotoxy(51 + vitri, y);
		key = GetKey();
		if (dg[0].ho[0] == '\0') {
			GhiChu("Ban Chua Nhap Ho!", 35, 27, 74, 700);
			gotoxy(29, y);
			goto HO;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 10)) {
			dg[0].ten[vitri] = char(key);
			dg[0].ten[vitri] = toupper(dg[0].ten[vitri]);
			cout << dg[0].ten[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(51 + vitri, y);
			cout << " ";
			gotoxy(51 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			dg[0].ten[vitri] = '\0';
			vitri = strlen(dg[0].phai);
			gotoxy(63 + vitri, y);
			goto PHAI;
		}
		if (key == ESC || key == F1) {
			return;
		}
		if (key == LEFT) {
			dg[0].ten[vitri] = '\0';
			vitri = strlen(dg[0].ho);
			gotoxy(29 + vitri, y);
			goto HO;
		}
		if (key == RIGHT) {
			dg[0].ten[vitri] = '\0';
			vitri = strlen(dg[0].phai);
			gotoxy(63 + vitri, y);
			goto PHAI;
		}
	}
PHAI:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                                ");
		gotoxy(20, 30); printf("      PHAI: GOM CAC KI TU (A-Z) - NAM/NU, TOI DA: 3 KI TU       ");
		gotoxy(20, 31); printf("                                                                "); 	TextColor(91); gotoxy(63 + vitri, y);
		key = GetKey();
		if (dg[0].ten[0] == '\0') {
			GhiChu("Ban Chua Nhap Ten!", 35, 27, 74, 700);
			gotoxy(51, y);
			goto TEN;
		}
		if (((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) && (vitri < 3)) {
			dg[0].phai[vitri] = char(key);
			dg[0].phai[vitri] = toupper(dg[0].phai[vitri]);
			cout << dg[0].phai[vitri];
			vitri++;
			dg[0].phai[vitri] = '\0';
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(63 + vitri, y);
			cout << " ";
			gotoxy(63 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			dg[0].phai[vitri] = '\0';
			if ((strcmp(dg[0].phai, "NAM") == 0) || (strcmp(dg[0].phai, "NU") == 0)) // So sanh
			{
				vitri = 0;
				gotoxy(69 + vitri, y);
				goto TRANGTHAI;
			}
			GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500); continue;
		}
		if (key == ESC || key == F1) {
			return;
		}
		if (key == LEFT) {
			dg[0].phai[vitri] = '\0';
			if ((strcmp(dg[0].phai, "NAM") != 0) && (strcmp(dg[0].phai, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500);	continue;
			}
			vitri = strlen(dg[0].ten);
			gotoxy(51 + vitri, y);
			goto TEN;
		}
		if (key == RIGHT) {
			dg[0].phai[vitri] = '\0';
			if ((strcmp(dg[0].phai, "NAM") != 0) && (strcmp(dg[0].phai, "NU") != 0))
			{
				GhiChu("Gioi Tinh phai la Nam/Nu!", 35, 27, 74, 500);	continue;
			}
			vitri = 0;
			gotoxy(68 + vitri, y);
			goto TRANGTHAI;
		}
	}

TRANGTHAI:
	while (1) {
		TextColor(252);			//Chu thich
		gotoxy(20, 29); printf("                                                               ");
		gotoxy(20, 30); printf("     CHI SO:(0 hoac 1) 0: BI KHOA   1: DANG HOAT DONG          ");
		gotoxy(20, 31); printf("                                                               ");
		TextColor(91);	gotoxy(68 + vitri, y);
		key = GetKey();
		if (dg[0].phai[0] == '\0')
		{
			GhiChu("Ban Chua Nhap Gioi Tinh!", 35, 27, 74, 700);
			gotoxy(63, y);
			goto PHAI;
		}
		if (key >= '0' && key <= '1') {
			if (key == '1') {
				dg[0].trangthai = 1;
			}
			else if (key == '0') {
				dg[0].trangthai = 0;
			}
		}
		if (dg[0].trangthai == 1) cout << " DANG HOAT DONG";
		else if (dg[0].trangthai == 0) cout << " BI KHOA       ";
		else cout << "               ";
		if (key == ENTER && (dg[0].trangthai == 0 || dg[0].trangthai == 1)) {
			check_change = true;
			GhiChu("Save Thanh Cong!", 40, 27, 74, 500);
			temp->info = dg[0];
			return;
		}
		if (key == ESC || key == F1) {
			return;
		}
		if (key == LEFT) {
			vitri = strlen(dg[0].phai);
			gotoxy(63 + vitri, y);
			goto PHAI;
		}
	}
}

/*XOA DOC GIA*/
void remove_case_3(treedocgia &r, treedocgia &rp) {
	if (r->left != NULL) remove_case_3(r->left, rp);
	else {
		rp->info = r->info;
		rp = r;
		r = rp->right;
	}
}

void Remove(int mathe, treedocgia &p, treedocgia &rp) {
	int x = 35, y = 14, vitri = 0;
	if (p == NULL) {
		GhiChu("Ma Doc Gia Khong Ton Tai!", 35, 27, 74, 500);	TextColor(12);	gotoxy(35 + vitri, y);
	}
	else if (mathe < p->info.mathe) Remove(mathe, p->left, rp);
	else if (mathe > p->info.mathe) Remove(mathe, p->right, rp);
	else {
		rp = p;
		if (rp->right == NULL) p = rp->left;
		else if (rp->left == NULL) p = rp->right;
		else remove_case_3(rp->right, rp);
		delete rp;
	}
}
void XoaDocGia(treedocgia &root, bool &check_change) {
	treedocgia rp = NULL;
	char mathe[20]; mathe[0] = NULL;
	int key, x = 35, y = 14, vitri = 0;
	DocGia dg[1]; dg[0].mathe = NULL;
	treedocgia temppointer, check_trung;
	Khung_Xoa_DG();
	gotoxy(x, y);
	while (1) {
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri <= 15)) {
			mathe[vitri] = char(key);
			cout << mathe[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(35 + vitri, y);
			cout << " ";
			gotoxy(35 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			check_trung = KTDocGia(root, mathe); // kiem tra doc gia co ton tai?
			if(check_trung != 0){
				check_change = true;
				mathe[vitri] = '\0'; //ngat chuoi
				Remove(atoi(mathe), root, rp);
				GhiChu("Da Xoa Thanh Cong Doc Gia!", 35, 27, 74, 500);	TextColor(12);	gotoxy(35 + vitri, y);
				return;
			}
			else{
				GhiChu("Ma Doc Gia Khong Ton Tai!", 35, 27, 74, 500);	TextColor(12);	gotoxy(35 + vitri, y);
			}
		}
		if (key == ESC || key == F3) { return; }
			
	}
}

void XuatDocGia(treedocgia &root) {
	int key, x = 40, y = 2, vitri = 0, vitriMang, temp, STT = 1;
	int trang = 0, tongtrang = 0, soluongdg = 0, dem = 0;
	bool check_change = false;
	while (1) {
		system("cls");
		for (int i = 0; i < 2; i++) {
			if (i == 0) { TextColor(236); }
			else { TextColor(188); }
			gotoxy(40, 5 + i * 4); cout << "                           ";
			gotoxy(40, 6 + i * 4); cout << MENUindanhsach[i];
			gotoxy(40, 7 + i * 4); cout << "                           ";
		}
		int select = MenuInDG();
		while (1)
		{
			soluongdg = DemDG(root);
			if (soluongdg == 0)
			{
				GhiChu("Chua co du lieu doc gia", 35, 27, 74, 500);
			}
			else {
				if (soluongdg < 15)
				{
					tongtrang = 1;
					trang = 0;
				}
				else {
					tongtrang = ((soluongdg - 1) / 15 + 1);
				}
			}
			DocGia dg[MAX];
			if (select == 1) SapXepDG_TheoMDG(root, dg);
			else if (select == 2) {
				int i = 0;
				TreeToArr(root, dg, i);
				SapXepDG_TheoHoTen(root, dg, soluongdg);
			}
			else if (select == 0) return;
			TextColor(91);	system("cls");
			Khung_Xuat_DG();
			dem = 0;
			for (int i = trang * 15; i < 15 + trang * 15 && i < soluongdg; i++)
			{
				TextColor(92); gotoxy(6, 8 + dem); cout << (i + 1); TextColor(91);
				gotoxy(10, 8 + dem); cout << dg[i].mathe;
				gotoxy(26, 8 + dem); cout << dg[i].ho;
				gotoxy(47, 8 + dem); cout << dg[i].ten;
				gotoxy(58, 8 + dem); cout << dg[i].phai;
				gotoxy(69, 8 + dem); if (dg[i].trangthai == 1)  cout << " DANG HOAT DONG"; else if (dg[i].trangthai == 0) cout << " BI KHOA       ";
				dem++;
			}

			key = GetKey();
			if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
			if ((key == LEFT || key == UP) && trang > 0) { trang--; }
			if (key == F1) {
				gotoxy(18, 24);  TextColor(251);	printf("F1"); //Tô màu F1
				ThemDocGia(root, check_change);
			}
			if (key == F2) {
				gotoxy(35, 24);	TextColor(251);	printf("F2"); //tô màu f2	
				SuaDocGia(root, check_change);
			}
			if (key == F3) {
				gotoxy(50, 24);	TextColor(251);	printf("F3"); //Tô màu F3
				XoaDocGia(root, check_change);
			}
			if (key == ESC) {
				if (check_change == true) {
					putchar(7);	gotoxy(4, 24);  TextColor(251);	printf("ESC"); //Tô màu ESC
					int temp = ThongBao_ESC();
					if (temp == -1) { continue; } //Tra ve -1 => Bat duoc phim ESC 1 lan nua~
					if (temp == 1) { GhiChu("Luu Vao File Thanh Cong!", 35, 27, 74, 2000); LuuFileDG(root); } //Them 1 DG moi cap nhat lai 
					if (temp == 0) { GhiChu("Luu Vao File Khong Thanh Cong!", 35, 27, 74, 2000); }							   
			}
			system("cls"); return;
		}
	}
}
}

/*************************** MUON - TRA SACH ***************************************/
void KhoiTaoNode(nodemuontra &First) {
	First = NULL;
}

void Insert_First_MuonSach(nodemuontra &First, nodemuontra &Last, MuonTra info) {
	nodemuontra p;
	p = new NodeMuonTra;
	p->info = info; p->left = NULL;
	p->right = First;
	if (First = NULL) Last = p;
	else First->left = p;
	First = p;
}

bool KiemTraMatSach(nodemuontra mt){
	nodemuontra p = mt;
	while(p != NULL){
		if(p->info.trangthai == 2) return false;
		p = p->right;
	}
	return true;
}


const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
                           31, 31, 30, 31, 30, 31}; 
   
int countLeapYears(Ngay d) // dem so nam nhuan
{ 
    int years = d.ngay; 
  
    // Check if the current year needs to be considered 
    // for the count of leap years or not 
    if (d.thang <= 2) 
        years--; 
  
    // An year is a leap year if it is a multiple of 4, 
    // multiple of 400 and not a multiple of 100. 
    return years / 4 - years / 100 + years / 400; 
} 
  
// This function returns number of days between two given 
// dates 
int getDifference(Ngay dt1, Ngay dt2) 
{ 
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1' 
  
    // initialize count using years and day 
    long int n1 = dt1.nam*365 + dt1.thang; 
  
    // Add days for months in given date 
    for (int i=0; i<dt1.thang - 1; i++) 
        n1 += monthDays[i]; 
  
    // Since every leap year is of 366 days, 
    // Add a day for every leap year 
    n1 += countLeapYears(dt1); 
  
    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2' 
  
    long int n2 = dt2.nam*365 + dt2.ngay; 
    for (int i=0; i<dt2.thang - 1; i++) 
        n2 += monthDays[i]; 
    n2 += countLeapYears(dt2); 
  
    // return difference between two counts 
    return (n2 - n1); 
} 


void MuonSach(treedocgia &root, list &ds) {
NHAP:
	int key, x = 35, y = 14, vitri = 0; char mathe[20]; mathe[0] = NULL;
	Ngay homnay;
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	homnay.ngay = ltm->tm_mday;
	homnay.thang = ltm->tm_mon + 1;
	homnay.nam = ltm->tm_year + 1900;
	treedocgia check_trung, temp;
	Khung_Tim_DG();
	gotoxy(x, y);
	while (1) {
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri <= 15)) {
			mathe[vitri] = char(key);
			cout << mathe[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(35 + vitri, y);
			cout << " ";
			gotoxy(35 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			mathe[vitri] = '\0'; //ngat chuoi
			check_trung = KTDocGia(root, mathe);
			
			if (check_trung != 0 && check_trung->info.trangthai == 1) {
				temp = KTDocGia(root, mathe);
				int n = SoSachDangMuon(temp->info.pMT);
				nodemuontra p = temp->info.pMT;
				nodemuontra quahan = temp->info.pMT;
				Khung_Hien_Thi_Tra_Sach();
				gotoxy(101, 14); cout << "TEN DOC GIA:";
				gotoxy(114, 14); cout << temp->info.ho << " " << temp->info.ten;
				gotoxy(101, 15); cout << "TRANG THAI THE:";
				gotoxy(116, 15); if(temp->info.trangthai == 1) cout << "DANG HOAT DONG"; else if(temp->info.trangthai == 0) cout << "BI KHOA";
				gotoxy(101, 16); cout << "SO SACH DANG MUON:";
				gotoxy(119, 16); cout << n;
				Liet_Ke_Sach_Dang_Muon_(temp->info.pMT, ds);
				cout << endl;
				system("pause");
				
				while(quahan != NULL && quahan->info.trangthai == 0){
					if(getDifference(quahan->info.ngaymuon, homnay) > 7) {
						GhiChu("Doc Gia Muon Qua Han!", 105, 25, 74, 1000);
						system("cls");
						goto NHAP;
						break;
					}
					quahan = quahan->right;
				}
				if(KiemTraMatSach(check_trung->info.pMT) == false){
					GhiChu("Doc Gia Lam Mat Sach!", 105, 25, 74, 1000);	
					system("cls");
					goto NHAP;
				}
				if(SoSachDangMuon(temp->info.pMT) >= 3){
					GhiChu("So Sach Da Toi Da!", 105, 25, 74, 1000); 
					system("cls");
					goto NHAP;
				}
				Xuat_Dau_Sach(root, temp, ds, ds.n);
				break;
			}
			else if(check_trung != 0 && check_trung->info.trangthai == 1 && KiemTraMatSach(check_trung->info.pMT) == false){
				GhiChu("Doc Gia Lam Mat Sach!", 35, 27, 74, 500);	TextColor(12);	gotoxy(35 + vitri, y);
			}
			
			else if(check_trung == 0){
				GhiChu("Ma Doc Gia Khong Ton Tai!", 35, 27, 74, 500);	TextColor(12);	gotoxy(35 + vitri, y);
			}
			else if(check_trung != 0 && check_trung->info.trangthai == 0){
				GhiChu("The Doc Gia Bi Khoa!", 35, 27, 74, 500); TextColor(12); gotoxy(35 + vitri, y);
			}
		}
		if (key == ESC) { return; }
	}
}

void TraSach(treedocgia &root, list &ds){
UPDATE:
	int key, x = 35, y = 14, vitri = 0; char mathe[20]; mathe[0] = NULL;
	treedocgia check_trung, temp = NULL;
	Khung_Tim_DG();
	gotoxy(x, y);
	while (1) {
		key = GetKey();
		if ((key <= '9' && key >= '0') && (vitri <= 15)) {
			mathe[vitri] = char(key);
			cout << mathe[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(35 + vitri, y);
			cout << " ";
			gotoxy(35 + vitri, y);
		}
		if (key == ENTER && vitri != 0) {
			mathe[vitri] = '\0'; //ngat chuoi
			check_trung = KTDocGia(root, mathe);
			
			if (check_trung != 0 && check_trung->info.trangthai == 1) {
				while(1){
					temp = KTDocGia(root, mathe); 
					int n = SoSachDangMuon(temp->info.pMT);
					nodemuontra p = temp->info.pMT;
					Khung_Hien_Thi_Tra_Sach();
					gotoxy(101, 14); cout << "TEN DOC GIA:";
					gotoxy(114, 14); cout << temp->info.ho << " " << temp->info.ten;
					gotoxy(101, 15); cout << "TRANG THAI THE:";
					gotoxy(116, 15); if(temp->info.trangthai == 1) cout << "DANG HOAT DONG"; else if(temp->info.trangthai == 0) cout << "BI KHOA";
					gotoxy(101, 16); cout << "SO SACH DANG MUON:";
					gotoxy(119, 16); cout << n;
					if(n == 0){
						GhiChu("BAN DA TRA HET SACH", 101, 25, 200, 700); break;
					}
					Liet_Ke_Sach_Dang_Muon_(p, ds);
					cout << endl;
					gotoxy(101, 24); TextColor(228); cout<<"F1: "; 
					gotoxy(104, 24); TextColor(91); cout<<"TRA SACH";
					gotoxy(122, 24); TextColor(228); cout<<"F2: ";
					gotoxy(125, 24); TextColor(91); cout<<"BAO MAT SACH";
					gotoxy(145, 24); TextColor(228); cout<<"ESC: ";
					gotoxy(148, 24); TextColor(91); cout<<"EXIT";
					gotoxy(101, 30); cout<<"Press key to choose"<<endl;
					gotoxy(101, 31);
					Ngay date = GetCurrentDate(date);
					key = GetKey();
					if(key == F1){
						system("cls");
						Xu_Ly_Tra_Sach(root, temp, ds, date);
						Khung_Xoa();
					}
					if(key == F2){
						system("cls");
						Xu_Ly_Mat_Sach(root, temp, ds, date); 
						Khung_Xoa();
					}
					if(key == ENTER || key == ESC)	goto UPDATE;
				}
			}
			else if(check_trung == 0){
				GhiChu("Ma Doc Gia Khong Ton Tai!", 35, 27, 74, 500);	TextColor(12);	gotoxy(35 + vitri, y);
			}
		}
		if(key == ESC){
			LuuFileDG(root);
			SaveFileDS(ds, ds.n);
			GhiChu("DU LIEU DA DUOC CAP NHAT! ", 35, 10, 200, 800);
			break;
		}	
	}
} 


/***************************************************************************************/

/*************************** DOC GIA MUON QUA HAN **************************************/
int DocGiaQuaHan(treedocgia root, DocGia dg[]){
	Ngay homnay;
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	homnay.ngay = ltm->tm_mday;
	homnay.thang = ltm->tm_mon + 1;
	homnay.nam = ltm->tm_year + 1900;
	treedocgia Stack[STACKSIZE];
	treedocgia p = root;
	int sp = -1;
	int index = 0;
	do {
		while (p != NULL) {
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1) {
			p = Stack[sp--];
			nodemuontra quahan = p->info.pMT;
			while(quahan != NULL && quahan->info.trangthai == 0){
				if(getDifference(quahan->info.ngaymuon, homnay) > 7){
					dg[index] = p->info;
					index++;
					break;
				}
				quahan = quahan->right;
			}
			p = p->right;
		}
		else break;
	} while (1);
	return index;
}

int MaxQuaHan(DocGia dg){
	Ngay homnay;
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	homnay.ngay = ltm->tm_mday;
	homnay.thang = ltm->tm_mon + 1;
	homnay.nam = ltm->tm_year + 1900;
	nodemuontra p = dg.pMT;
	int max = 0;
	while(p != NULL && p->info.trangthai == 0){
		if(getDifference(p->info.ngaymuon, homnay) > 7 && getDifference(p->info.ngaymuon, homnay) > max){
			max = getDifference(p->info.ngaymuon, homnay);
		}
		p = p->right;
	}
	return max;
}

void SortGiamDanQuaHan(DocGia dg[], int soluongquahan){
	int i, j;
	DocGia temp;
	
	for(i = 1; i < soluongquahan; i++)
		for(j = soluongquahan - 1; j >= i; j--) 
		if(MaxQuaHan(dg[j - 1]) < MaxQuaHan(dg[j])){
			temp = dg[j - 1]; 
			dg[j - 1] = dg[j]; 
			dg[j] = temp; 
		}
}

void Xuat_DG_Qua_Han(treedocgia root){
	Ngay homnay;
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	homnay.ngay = ltm->tm_mday;
	homnay.thang = ltm->tm_mon + 1;
	homnay.nam = ltm->tm_year + 1900;
	int key, x = 40, y = 2, vitri = 0, vitriMang, temp, STT = 1;
	int trang = 0, tongtrang = 0, soluongdgquahan = 0, dem = 0;
	bool check_change = false;
	DocGia dg[MAX];
	while (1) {
			while (1)
			{
			soluongdgquahan = DocGiaQuaHan(root, dg);
			if (soluongdgquahan == 0)
			{
				GhiChu("Chua co du lieu doc gia", 35, 27, 74, 500);
			}
			else {
				if (soluongdgquahan < 30)
				{
					tongtrang = 1;
					trang = 0;
				}
				else {
					tongtrang = ((soluongdgquahan - 1) / 30 + 1);
				}
			}
			TextColor(91);	system("cls");
			SortGiamDanQuaHan(dg, soluongdgquahan);
			Khung_Xuat_Qua_Han();
			dem = 0;
			for (int i = trang * 30; i < 30 + trang * 30 && i < soluongdgquahan; i++)
			{
				TextColor(92); gotoxy(6, 8 + dem); cout << (i + 1); TextColor(91);
				gotoxy(10, 8 + dem); cout << dg[i].mathe;
				gotoxy(26, 8 + dem); cout << dg[i].ho;
				gotoxy(47, 8 + dem); cout << dg[i].ten;
				gotoxy(58, 8 + dem); cout << dg[i].phai;
				gotoxy(69, 8 + dem); if (dg[i].trangthai == 1)  cout << " DANG HOAT DONG"; else if (dg[i].trangthai == 0) cout << " BI KHOA       ";
				gotoxy(95, 8 + dem); cout << MaxQuaHan(dg[i]);
				dem++;
			}

			key = GetKey();
			if ((key == RIGHT || key == DOWN) && trang < tongtrang - 1) { trang++; }
			if ((key == LEFT || key == UP) && trang > 0) { trang--; }
			if (key == ESC) {
				system("cls");	return;
			}
		}
	}
}
/***************************************************************************************/
void MenuOngNoi(treedocgia &root, list &List) {
	
	int chonMenuCon;
	while (1) {
		TextColor(91);
		system("cls");
		for (int i = 0; i < 4; i++) {
			if (i == 0) { TextColor(236); }
			else { TextColor(188); }
			gotoxy(0, 5 + i * 4); cout << "                        ";
			gotoxy(0, 6 + i * 4); cout << MENU[i];
			gotoxy(0, 7 + i * 4); cout << "                        ";
		}
		gotoxy(24, 7);
		int chon = MenuCha();
		switch (chon) {
		case 1: {
			for (int i = 0; i < 3; i++) {
				if (i == 0) { TextColor(236); }
				else { TextColor(252); }
				gotoxy(28, 5 + (i + 1) * 4);	cout << "                           ";
				gotoxy(28, 6 + (i + 1) * 4);	cout << MENUdocgia[i];
				gotoxy(28, 7 + (i + 1) * 4);	cout << "                           ";
			}
			chonMenuCon = MenuCon(3, MENUdocgia);
			TextColor(91);
			system("cls");
			switch (chonMenuCon) {
			case 1: {
				NhapDocGia(root);
				break;
			}

			case 2: {
				XuatDocGia(root);
				break;
			}

			case 3: {
				Xuat_DG_Qua_Han(root);
				break;
			}
			}
			break;

		}

		case 2: {
			for (int i = 0; i < 3; i++) {
				if (i == 0) { TextColor(236); }
				else { TextColor(252); }
				gotoxy(28, 5 + (i + 1) * 4);	cout << "                           ";
				gotoxy(28, 6 + (i + 1) * 4);	cout << MENUdausach[i];
				gotoxy(28, 7 + (i + 1) * 4);	cout << "                           ";
			}
			chonMenuCon = MenuCon(3, MENUdausach);
			TextColor(91);
			system("cls");
			switch (chonMenuCon) {
			case 1: {
				Nhap_Dau_Sach(List);			
				break;
			}

			case 2: {
				Tim_Sach_Va_Cap_Nhat(List);
				break;
			}

			case 3: {
				TimNhung_SapXep(List);
				break;
				}
			}
			break;
		}

		case 3: {
			for (int i = 0; i < 3; i++) {
				if (i == 0) { TextColor(236); }
				else { TextColor(252); }
				gotoxy(28, 5 + (i + 1) * 4);	cout << "                           ";
				gotoxy(28, 6 + (i + 1) * 4);	cout << MENUsach[i];
				gotoxy(28, 7 + (i + 1) * 4);	cout << "                           ";
			}
			chonMenuCon = MenuCon(3, MENUsach);
			TextColor(91);
			system("cls");
			switch (chonMenuCon) {
			case 1: {
				MuonSach(root, List);
				break;
			}

			case 2: {
				TraSach(root, List);
				break;
			}

			case 3: {
				TopBook top[List.n + 1];
				for(int i=0;i < (List.n) + 1; i++){
					top[i].tensach[0] = NULL;
					top[i].so_sach_muon = 0;
				}
				TopBookTemp(List, top);
				system("pause");
				break;
			}
			}
			break;
			break;
		}

		case 4: {
			putchar(7);
			int temp = ThongBao_Thoat();
			if (temp == 1) {
				TextColor(91);
				system("cls");
				exit(0);
			}
			TextColor(91);
			break;
		}
		}
	}
}

int main() {
	list List; 
	treedocgia tree = NULL;
	DocFileDG(tree);
	LoadFileDS(List); 
	MenuOngNoi(tree,List);
}



