#ifndef CapNhatDauSach_INCLUDE
#define CapNhatDauSach_INCLUDE

#include<iostream>
using namespace std;
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<cstring>
#include <ctime>
#include<string>
#include<fstream>
#include<stdlib.h>
#include"Project-ThuVien.h"
#include"CacHamDoHoa.h"
#include"HamDieuKhien.h"

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

int Empty(list &ds){
	return (ds.n == 0 ? 1 : 0);
}

int Full(list &ds){
	return (ds.n == maxsach ? 1:0);
}

void Insert_item(list &ds, int i, DauSach b){
	int j;
	if(i<0||i>ds.n+1)	cout<<"Vi tri them vao khong phu hop"<<endl;
	else{
		if(Full(ds))  cout<<"Danh sach da day"<<endl;
		else{
			if(i==0)	i = 1;
			for(j=ds.n-1;j>=i-1;j--)
				ds.nodes[j+1] = ds.nodes[j];
			strcpy(ds.nodes[i-1]->ISBN, b.ISBN);
			strcpy(ds.nodes[i-1]->tensach, b.tensach);
			strcpy(ds.nodes[i-1]->tacgia, b.tacgia);
			strcpy(ds.nodes[i-1]->theloai, b.theloai);
			ds.nodes[i-1]->sotrang = b.sotrang;
			ds.nodes[i-1]->namxuatban = b.namxuatban;
			ds.nodes[i-1]->pDMS = b.pDMS;
			 // tranh truong hop ds.nodes[-1] gay loi
			ds.n++;
		}
	}
}

void Delete_item(list &ds, int i){
	int j;
	if(i<0||i>=ds.n) 	cout<<"Vi tri xoa khong phu hop"<<endl;
	else
		if(Empty(ds))	cout<<"Danh sach khong co phan tu"<<endl;
		else{
			for(j=i;j<ds.n;j++)
			ds.nodes[j-1] = ds.nodes[j];
			ds.n--;
		}
}

void TraverseNodeSach(PTR First);
void TraverseDS(list &ds, int n){
	int i; ds.n = n;
	if(Empty(ds)){
		cout<<"\n	Danh sach khong co phan tu"<<endl; return ;
	}
	for(i=0;i<ds.n;i++){
		cout<<"ISBN : "<<ds.nodes[i]->ISBN<<endl;
		cout<<"Ten sach : "<<ds.nodes[i]->tensach<<endl;
		cout<<"Tac gia :"<<ds.nodes[i]->tacgia<<endl;
		cout<<"The loai: "<<ds.nodes[i]->theloai<<endl;
		cout<<"So trang: "<<ds.nodes[i]->sotrang<<endl;
		cout<<"Nam xuat ban: "<<ds.nodes[i]->namxuatban<<endl<<endl;
		TraverseNodeSach(ds.nodes[i]->pDMS);
	}
}

void Clear_list(list &ds){
	ds.n = 0;
}

int Check_ISBN(list &ds, int dem){
	int pos = 0;
	while(pos < dem){
		if(strcmp(ds.nodes[dem]->ISBN, ds.nodes[pos++]->ISBN) == 0)		return pos;
	}
	return -1; // pos co the la 0
}

void Khung_Nhap_Dau_Sach(){
	gotoxy(0, 0);
	TextColor(90);	
	printf("\n\n\n\n\n   +---------------------------------------------------------------------------------+-----+"   );	
	printf("\n   |     |	|		      		|          	|	   |	     |     |"   );	
	printf("\n   |-----+------+-------------------------------+---------------+----------+---------+-----|"   );	
	printf("\n   |	 |      |       	                |               |          |         |     |"   );	
	printf("\n   |	 |      |		                |	        |	   |         |     |"   );	
	printf("\n   | 	 |	|		                |		|          |         |     |"   );	
	printf("\n   |	 |	|		                | 	        |          |         |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |---------------------------------------------------------------------------------------|");	
	printf("\n   |                                                                                       |");	
	printf("\n   +---------------------------------------------------------------------------------------+");
	TextColor(236);	gotoxy(33,1);	printf("                               ");	
	gotoxy(33,2);	printf("   NHAP THONG TIN DAU SACH     ");		
	gotoxy(33,3);	printf("                               ");
	TextColor(94);	gotoxy(5,6);    printf("STT");	
	gotoxy(10,6);	printf("ISBN");	
	gotoxy(30,6);	printf("DAU SACH");	
	gotoxy(53,6);	printf("TAC GIA");	
	gotoxy(66,6);	printf("THE LOAI");	
	gotoxy(77,6);	printf("SO TRANG");	
	gotoxy(87,6);   printf("NXB");
	gotoxy(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoxy(20,24);	TextColor(252);	printf("ENTER");	
	TextColor(91);	printf(": OK");		
	gotoxy(36,24);	
	TextColor(252);	printf("CONTROL");	
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN");
	gotoxy(76, 24);
	gotoxy(0,27);
}

void Khung_Xuat_Dau_Sach(){
	gotoxy(0, 0);
	TextColor(90);	
	printf("\n\n\n\n\n   +---------------------------------------------------------------------------------+-----+"   );	
	printf("\n   |     |	|		      		|          	|	   |	     |     |"   );	
	printf("\n   |-----+------+-------------------------------+---------------+----------+---------+-----|"   );	
	printf("\n   |	 |      |       	                |               |          |         |     |"   );	
	printf("\n   |	 |      |		                |	        |	   |         |     |"   );	
	printf("\n   | 	 |	|		                |		|          |         |     |"   );	
	printf("\n   |	 |	|		                | 	        |          |         |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |	 |	|		                |		|          |	     |     |"   );	
	printf("\n   |---------------------------------------------------------------------------------------|");	
	printf("\n   |                                                                                       |");	
	printf("\n   +---------------------------------------------------------------------------------------+");
	TextColor(236);	gotoxy(33,1);	printf("                               ");	
	gotoxy(33,2);	printf("      THONG TIN DAU SACH       ");		
	gotoxy(33,3);	printf("                               ");
	TextColor(94);	gotoxy(5,6);    printf("STT");	
	gotoxy(10,6);	printf("ISBN");	
	gotoxy(30,6);	printf("DAU SACH");	
	gotoxy(53,6);	printf("TAC GIA");	
	gotoxy(66,6);	printf("THE LOAI");	
	gotoxy(77,6);	printf("SO TRANG");	
	gotoxy(87,6);   printf("NXB");
	gotoxy(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoxy(20,24);	TextColor(252);	printf("F2");	
	TextColor(91);	printf(": SEARCHING");		
	gotoxy(36,24);	
	TextColor(252);	printf("PREVIOUS/ NEXT PAGE");	
	TextColor(91);	printf(": LEFT - RIGHT ");
	gotoxy(0,27);
}

int findsubstr(const char *str, char *sub);
Sach Search_masach(char* search, list ds, int nodeth){
	for(PTR q = ds.nodes[nodeth]->pDMS; q != NULL; q = q->next){
		if(findsubstr(q->info.masach, ds.nodes[nodeth]->ISBN) != -1){
			if(strcmp(q->info.masach, search) == 0){
				return q->info;
				break;	
			}
		} 		
	}
	Sach n;
	n.masach[0] = NULL; n.trangthai = 0; n.vitri[0] = NULL;
	return n;
}

int Thuoc_Dau_Sach_Thu(list &ds, char* search){
	for(int i = 0; i < ds.n; i++){
		if(findsubstr(search, ds.nodes[i]->ISBN) != -1) {
			return i; break;
		}
	}
	return -1;
}

void Thay_Doi_Trang_Thai_Sach(list ds, int nodeth, char* search, int trangthai){
	for(PTR p = ds.nodes[nodeth]->pDMS ; p != NULL; p = p->next){
		if(strcmp(p->info.masach, search) == 0){
			p->info.trangthai = trangthai;
			break;
		}
	}	
}

void SaveFileDS(list ds, int n);
void LuuFileDG(treedocgia root);
void Insert_Firstmuontra(nodemuontra &First, MuonTra mt[], int index){
	nodemuontra p;
	p = new NodeMuonTra;
	p->info = mt[index];
	if(First == NULL){
		p->right = NULL;
	}
	else{
		// tao lien ket giua p va First.
		p->right = First;
		First->left = p;
	}
	First = p;
	p->left = NULL;
}
int CountNodeMT(nodemuontra First);
void danhsachmuontra(nodemuontra First){
	if(First == NULL){
		cout << "khong co data" << endl;
		return;
	}
	nodemuontra p = First;
	while(p != NULL){
		cout << p->info.masach << endl;
		p = p->right;
	}
}

bool KT_Trung_DS_Ben_Ngoai(list &ds, nodemuontra First, int nodeth){
	bool trung_dau_sach = false;
	for(nodemuontra p = First ; p != NULL; p = p->right){
	if(p->info.trangthai == 0){
		int i = Thuoc_Dau_Sach_Thu(ds, p->info.masach);
		if(i == nodeth && i != -1){
			trung_dau_sach = true;
			GhiChu("DOC GIA KHONG DUOC MUON SACH CUA MOT DAU SACH QUA 1 LAN", 30, 5, 200, 1800);
			break;
				}
			}
		}
	return trung_dau_sach;
} 

bool KT_Trung_DS_Ben_Trong(int *arr, int k, int nodeth){
	bool trung_dau_sach = false;
	for(int j = 0; j < k; j++){
		if(arr[j] == nodeth){
			trung_dau_sach = true;
			GhiChu("Doc gia da muon sach nay truoc do", 42, 5, 200, 1800);
			break;
		}
	}
	return trung_dau_sach;	
}

Ngay GetCurrentDate(Ngay dt){
	time_t now = time(0);
	tm *ltm  = localtime(&now);
	dt.ngay  = ltm->tm_mday;
	dt.thang = 1 + ltm->tm_mon;
	dt.nam   = 1900 + ltm->tm_year;
	return dt;
}

void Thay_Doi_Trang_Thai_MT(nodemuontra First, char* search, Ngay date, int trang_thai){
	for(nodemuontra p = First; p != NULL; p = p->right){
		if(strcmp(p->info.masach, search) == 0){
			p->info.ngaytra   = date;
			p->info.trangthai = trang_thai; // da tra sach
			break;
		}
	}	
}	
					
int SoSachDangMuon(nodemuontra First){
	int count = 0;
	for(nodemuontra p = First; p != NULL; p = p->right){
		if(p->info.trangthai == 0 || p->info.trangthai == 2) count++;
	}
	return count;
}

void Liet_Ke_Sach_Dang_Muon(nodemuontra First, list &ds){
	int i = 0;
	for(nodemuontra p = First; p != NULL; p = p->right){
		if(p->info.trangthai == 0 || p->info.trangthai == 2){
			gotoxy(21, 20 + i); if(Thuoc_Dau_Sach_Thu(ds, p->info.masach) != -1) cout << ds.nodes[Thuoc_Dau_Sach_Thu(ds, p->info.masach)]->tensach;
			gotoxy(52, 20 + i); cout<<p->info.masach;
			gotoxy(61, 20 + i); cout <<p->info.ngaymuon.ngay << "/" << p->info.ngaymuon.thang << "/" << p->info.ngaymuon.nam;
			i++;
		}
	}
}

void Liet_Ke_Sach_Dang_Muon_(nodemuontra First, list &ds){
	int i = 0;
	for(nodemuontra p = First; p != NULL; p = p->right){
		if(p->info.trangthai == 0 || p->info.trangthai == 2){
			gotoxy(101, 20 + i); if(Thuoc_Dau_Sach_Thu(ds, p->info.masach) != -1) cout << ds.nodes[Thuoc_Dau_Sach_Thu(ds, p->info.masach)]->tensach;
			gotoxy(132, 20 + i); cout<<p->info.masach;
			gotoxy(141, 20 + i); cout <<p->info.ngaymuon.ngay << "/" << p->info.ngaymuon.thang << "/" << p->info.ngaymuon.nam;
			i++;
		}
	}
}

bool Thuoc_Ve_MT(nodemuontra First, char* search){
	for(nodemuontra p = First; p != NULL; p = p->right){
		if(p->info.trangthai == 0 || p->info.trangthai == 2){
			if(strcmp(p->info.masach, search) == 0)
				return true; 
		}
	}
	return false;
}

void Insert_nodeDG(treedocgia &p, int x, DocGia dg[], int dem);
void Khung_Muon_Sach();
int Tim_Dau_Sach(list &ds, string search);

void Xuat_Dau_Sach(treedocgia &root, treedocgia &temp, list &ds, int so_luong){
	bool check_change = false;
	int muon = 0;
	int duocmuon = 3 - SoSachDangMuon(temp->info.pMT);
	int nodeth_da_muon[duocmuon], k = 0;
	MuonTra mt[MAX];
	for(int i = 0; i < MAX; i++)
	{
		mt[i].masach[0] = NULL;
		mt[i].ngaymuon.ngay = NULL;
		mt[i].ngaymuon.thang = NULL;
		mt[i].ngaymuon.nam = NULL;
		mt[i].ngaytra.ngay = NULL;
		mt[i].ngaytra.thang = NULL;
		mt[i].ngaytra.nam = NULL;
		mt[i].trangthai = NULL;
	}

	int page = 0, total_page = 0, STT = 1, dem = 0;
	while(1){
		system("cls");
		dem = 0;
		if(so_luong == 0)	GhiChu("Chua co du lieu dau sach", 35, 27, 74, 500);
		else{
			if(so_luong < 15){
				total_page = 1;
				page = 0;
			}
			else{
				total_page = ((so_luong - 1) / 15 + 1);
			}
		}
		TextColor(91);	system("cls");
		Khung_Xuat_Dau_Sach();
		dem = 0;
		for (int i = page * 15; i < 15 + page * 15 && i < so_luong; i++){
			TextColor(92); gotoxy(6, 8 + dem); cout << (i + 1); TextColor(91);
			gotoxy(10, 8 + dem); cout<<ds.nodes[i]->ISBN;
			gotoxy(17, 8 + dem); cout << ds.nodes[i]->tensach;
			gotoxy(49, 8 + dem); cout <<ds.nodes[i]->tacgia;
			gotoxy(65, 8 + dem); cout<<ds.nodes[i]->theloai;
			gotoxy(80, 8 + dem); cout<<ds.nodes[i]->sotrang;
			gotoxy(86, 8 + dem); cout<<ds.nodes[i]->namxuatban;
			dem++;
		}
		char key = GetKey();
		if (key == RIGHT && page < total_page - 1) { page++; }
		if (key == LEFT && page > 0) { page--; }
		if(key == F2){
A:			system("cls"); char search[100];
			gotoxy(18, 1); TextColor(6);
			gotoxy(18, 1); cout<<"                          "<<endl;
			gotoxy(18, 1); cout<<"NHAP DAY DU TEN SACH CAN MUON:    "<<endl;
			gotoxy(48, 1); TextColor(240); cout<<"                                                   "<<endl;
			gotoxy(48, 1); //gets(search);
		
			int y = 1, vitri = 0;
			while(1){ // while dung nhap ten sach
				int key = GetKey();
				if((( key >= 'A' && key <= 'Z')||( key <= '9' && key >= '0')||( key >='a' && key <= 'z' )) && (vitri < 45)){
					search[vitri] = char(key);
					search[vitri] = toupper(search[vitri]);
					cout << search[vitri];
					vitri++;
				}
				if (key == BACKSPACE && vitri > 0) {
					vitri--;
					gotoxy(48 + vitri, y);
					cout << " ";
					gotoxy(48 + vitri, y);
				}
				if(key == ESC)	break;
				if( key == SPACE && search[vitri-1] != ' ' && vitri > 0 && vitri < 45){	// neu phan dau va phan cuoi cua ho la Space
					gotoxy(48+vitri , y);
					cout<<" ";
					search[vitri] = ' ';
					vitri++;
				}
				if(key == ENTER && vitri != 0){
					search[vitri] = '\0';
					int nodeth = Tim_Dau_Sach(ds, search);
					if(nodeth == -1){
						GhiChu("TEN SACH KHONG TON TAI", 30, 5, 200, 600);
						system("pause"); goto A;
						break;
					}	
					else{	
						if(KT_Trung_DS_Ben_Ngoai(ds, temp->info.pMT, nodeth))	goto A;
						if(KT_Trung_DS_Ben_Trong(nodeth_da_muon, k, nodeth))	goto A;
						while(1){
							system("cls");
							TextColor(11); 
							cout<<"\n\t\t\tISBN: "<<ds.nodes[nodeth]->ISBN<<endl;
							cout<<"\t\t\tTen Sach: "<<ds.nodes[nodeth]->tensach<<endl;
							cout<<"\t\t\tTen Tac Gia: "<<ds.nodes[nodeth]->tacgia<<endl;
							cout<<"\t\t\tTen the loai: "<<ds.nodes[nodeth]->theloai<<endl;
							cout<<"\t\t\tSo trang: "<<ds.nodes[nodeth]->sotrang<<endl;
							cout<<"\t\t\tNam xuat ban: "<<ds.nodes[nodeth]->namxuatban<<endl;
							TextColor(206);
							cout<<"\t    Cac sach trong danh muc: "<<endl<<endl;
							if(ds.nodes[nodeth]->pDMS != NULL){
								TextColor(116);
								TraverseNodeSach(ds.nodes[nodeth]->pDMS);
								cout<<endl;
								cout<<"Press F2 to borrow books\n";
							}
							int key = GetKey();
							if(key == F2){
LABEL:						int y = 14;
							int vitri = 0;
							char masach[20];
							char ngay[2];
							char thang[2];
							char nam[10];

							time_t baygio = time(0);
							tm *ltm = localtime(&baygio);
							itoa(ltm->tm_mday, ngay, 10);
							itoa(ltm->tm_mon + 1, thang, 10);
							itoa(ltm->tm_year + 1900, nam, 10);
							Khung_Muon_Sach();
							gotoxy(102, y);
MASACH:						while(1){
								key = GetKey();
								if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri <= 15)){ 
								masach[vitri] = char(key);
								masach[vitri] = toupper(masach[vitri]);
								cout << masach[vitri];
								vitri++;
								}
								if (key == BACKSPACE && vitri > 0) {
								vitri--;
								gotoxy(102 + vitri, y);
								cout << " ";
								gotoxy(102 + vitri, y);
								}
								
								if(key == ENTER){
									if(masach[vitri - 1] == ' ') vitri--;
									masach[vitri] = '\0';
									Sach result; bool tim_thay = false;
									for(int i=0;i<ds.n;i++){
										result = Search_masach(masach, ds, i);
										if(result.masach[0] != NULL){
											tim_thay = true;
											if(result.trangthai != 0){
												GhiChu("SACH DA CO CHU", 105, 17, 200, 600); goto LABEL; 
											}
											strcpy(mt[muon].masach, result.masach);
											break;
										}
									}
									if(tim_thay == false){
										GhiChu("MA SACH KHONG TON TAI", 105, 17, 200, 600); goto LABEL; 
									}
									nodeth_da_muon[k++] = nodeth;
									vitri = strlen(ngay);
									gotoxy(120 + vitri, y);
									goto NGAY;
								}
								
								if(key == ESC) {
									break;
								}
							} 
NGAY:						gotoxy(120, y);
							cout << ngay;
							vitri = strlen(ngay);
							while(1){
								key = GetKey();
								if( key <= '9' && key >= '0' && vitri < 2){
								ngay[vitri] = char(key); 
								cout << ngay[vitri];
								vitri++;
								}
								if (key == BACKSPACE && vitri > 0) {
								vitri--;
								gotoxy(120 + vitri, y);
								cout << " ";
								gotoxy(120 + vitri, y);
								}
								
								if(key == ENTER){
									if(ngay[vitri - 1] == ' ') vitri--;
									ngay[vitri] = '\0';
									if(atoi(ngay) > 31 || atoi(ngay) <= 0){
										GhiChu("Ban Nhap Sai Ngay!", 105, 17, 200, 600);
										vitri = strlen(ngay);
										gotoxy(120 + vitri, y); goto NGAY;
									}
									mt[muon].ngaymuon.ngay = atoi(ngay);
									vitri = strlen(thang);
									gotoxy(129 + vitri, y);
									goto THANG;
								}
								
								if(key == ESC) {
									break;
								}
							}
THANG:						gotoxy(129, y);
							cout << thang;
							vitri = strlen(thang);
							while(1){
								key = GetKey();
								if( key <= '9' && key >= '0' && vitri < 2){ 
								thang[vitri] = char(key);
								cout << thang[vitri];
								vitri++;
								}
								if (key == BACKSPACE && vitri > 0) {
								vitri--;
								gotoxy(129 + vitri, y);
								cout << " ";
								gotoxy(129 + vitri, y);
								}
								
								if(key == ENTER){
									if(thang[vitri - 1] == ' ') vitri--;
									thang[vitri] = '\0';
									if(atoi(thang) > 12 || atoi(thang) <= 0){
										GhiChu("Ban Nhap Sai Thang!", 105, 17, 200, 600);
										vitri = strlen(thang);
										gotoxy(129 + vitri, y); goto THANG;
									}
									else if((atoi(thang) == 4 || atoi(thang) == 6 || atoi(thang) == 9 || atoi(thang) == 11) && atoi(ngay) > 30){
										GhiChu("Ban Nhap Sai Ngay!", 105, 17, 200, 600);
										vitri = strlen(ngay);
										gotoxy(120 + vitri, y); goto NGAY;
									}
									
									else if(atoi(thang) == 2 && atoi(ngay) > 29){
										GhiChu("Ban Nhap Sai Ngay!", 105, 17, 200, 600);
										vitri = strlen(ngay);
										gotoxy(120 + vitri, y); goto NGAY;
									}
									 
									mt[muon].ngaymuon.thang = atoi(thang);
									vitri = strlen(nam);
									gotoxy(138 + vitri, y);
									goto NAM;
								}
								
								if(key == ESC) {
									break;
								}
							}
NAM:						gotoxy(138, y);
							cout << nam;
							vitri = strlen(nam);
							while(1){
								key = GetKey();
								if( key <= '9' && key >= '0' && vitri < 4){ 
								nam[vitri] = char(key);
								cout << nam[vitri];
								vitri++;
								}
								if (key == BACKSPACE && vitri > 0) {
								vitri--;
								gotoxy(138 + vitri, y);
								cout << " ";
								gotoxy(138 + vitri, y);
								}
								
								if(key == ENTER){
									if(atoi(nam) < 2000){
										GhiChu("Ban Nhap Sai Nam!", 105, 17, 200, 600);
										vitri = strlen(nam);
										gotoxy(138 + vitri, y); goto NAM;
									}
		
									else if((atoi(nam) % 4 != 0 && atoi(nam) % 100 != 0) || atoi(nam) % 400 != 0){
										if(atoi(thang) == 2 && (atoi(ngay) > 28)) {
											GhiChu("Ban Nhap Sai Ngay!", 105, 17, 200, 600);
											vitri = strlen(ngay);
											gotoxy(120 + vitri, y); goto NGAY;
										}
									}
									mt[muon].ngaymuon.nam = atoi(nam);
									check_change = true;
									mt[muon].trangthai = 0;
									Thay_Doi_Trang_Thai_Sach(ds, nodeth, mt[muon].masach, 1);
									GhiChu("Muon Thanh cong!", 35, 27, 74, 500);
									muon++;
									if(muon == duocmuon) {
										GhiChu("Ban Da Muon Toi Da Sach!", 35, 27, 74, 500);
										for(int i = 0; i < muon; i++) Insert_Firstmuontra(temp->info.pMT, mt, i);
										LuuFileDG(root);
										SaveFileDS(ds, ds.n);
										return;
									}
									goto A;
								}
								
								if(key == ESC) {
									break;
								}
							}											
							} 
								if(key == ESC){
									break;
								}			
							}
					}
				}
			} 
		} 
		
		if(key == ESC){
		if(check_change == true) {
			for(int i = 0; i < muon; i++) Insert_Firstmuontra(temp->info.pMT, mt, i);
			LuuFileDG(root);
			SaveFileDS(ds, ds.n);
			check_change = false;
		}
		else break;
	}
	} 
	
}

treedocgia KTDocGia(treedocgia root, char mathe[]);
void Khung_Trong_Luc_Tra_Sach();
void Xu_Ly_Tra_Sach(treedocgia &root, treedocgia &temp, list &ds, Ngay date){
TRA:
	Khung_Trong_Luc_Tra_Sach();
	int n = SoSachDangMuon(temp->info.pMT);
	nodemuontra p = temp->info.pMT;
	gotoxy(21, 14); cout << "TEN DOC GIA:";
	gotoxy(34, 14); cout << temp->info.ho << " " << temp->info.ten;
	gotoxy(21, 15); cout << "TRANG THAI THE:";
	gotoxy(36, 15); if(temp->info.trangthai == 1) cout << "DANG HOAT DONG"; else if(temp->info.trangthai == 0) cout << "BI KHOA";
	gotoxy(21, 16); cout << "SO SACH DANG MUON:";
	gotoxy(39, 16); cout << n;
	Liet_Ke_Sach_Dang_Muon(p, ds);
	if(n == 0){
		GhiChu("DOC GIA DA TRA HET SACH DANG MUON", 101, 17, 200, 600); return;
	}
	int y = 14,vitri = 0 ;
	char masach[20];
	Khung_Muon_Sach();
	gotoxy(122, 14); cout<<date.ngay;
	gotoxy(132, 14); cout<<date.thang;
	gotoxy(140, 14); cout<<date.nam;
	gotoxy(102, y);
	while(1){
		int key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri <= 15)){ 
		masach[vitri] = char(key);
		masach[vitri] = toupper(masach[vitri]);
		cout << masach[vitri];
		vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
		vitri--;
		gotoxy(102 + vitri, y);
		cout << " ";
		gotoxy(102 + vitri, y);
		}
		if(key == ENTER){
			if(masach[vitri - 1] == ' ') vitri--;
			masach[vitri] = '\0';
			Sach result; bool tim_thay = false;
			for(int i=0;i<ds.n;i++){
				result = Search_masach(masach, ds, i);
				if(Thuoc_Ve_MT(temp->info.pMT, masach) == false){
					GhiChu("MA SACH KHONG THUOC VE DOC GIA", 105, 17, 200, 800); goto TRA; break;
				}
				else{
					if(result.masach[0] != NULL){
						tim_thay = true;
						Thay_Doi_Trang_Thai_MT(temp->info.pMT, result.masach, date, 1);
						int nodeth = Thuoc_Dau_Sach_Thu(ds, result.masach);
						Thay_Doi_Trang_Thai_Sach(ds, nodeth, result.masach, 0);
						GhiChu("TRA SACH THANH CONG! ^^", 105, 17, 200, 700);
						goto TRA;
						break;
					}
				}
			}
			if(tim_thay == false){
				GhiChu("MA SACH KHONG DUNG", 105, 17, 200, 600); goto TRA; 
			}
		}
		if(key == ESC)		break;
	}
}

void Xu_Ly_Mat_Sach(treedocgia &root, treedocgia &temp, list &ds, Ngay date){
MAT:
	Khung_Trong_Luc_Tra_Sach();
	int n = SoSachDangMuon(temp->info.pMT);
	nodemuontra p = temp->info.pMT;
	gotoxy(21, 14); cout << "TEN DOC GIA:";
	gotoxy(34, 14); cout << temp->info.ho << " " << temp->info.ten;
	gotoxy(21, 15); cout << "TRANG THAI THE:";
	gotoxy(36, 15); if(temp->info.trangthai == 1) cout << "DANG HOAT DONG"; else if(temp->info.trangthai == 0) cout << "BI KHOA";
	gotoxy(21, 16); cout << "SO SACH DANG MUON:";
	gotoxy(39, 16); cout << n;
	int height = 0;
	Liet_Ke_Sach_Dang_Muon(p, ds);
	
	int y = 14,vitri = 0 ;
	char masach[20];
	Khung_Muon_Sach();
	gotoxy(122, 14); cout<<date.ngay;
	gotoxy(132, 14); cout<<date.thang;
	gotoxy(140, 14); cout<<date.nam;
	gotoxy(102, y);
	while(1){
		int key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri <= 15)){ 
		masach[vitri] = char(key);
		masach[vitri] = toupper(masach[vitri]);
		cout << masach[vitri];
		vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
		vitri--;
		gotoxy(102 + vitri, y);
		cout << " ";
		gotoxy(102 + vitri, y);
		}
		if(key == ENTER){
			if(masach[vitri - 1] == ' ') vitri--;
			masach[vitri] = '\0';
			Sach result; bool tim_thay = false;
			for(int i=0;i<ds.n;i++){
				result = Search_masach(masach, ds, i);
				if(Thuoc_Ve_MT(temp->info.pMT, masach) == false){
					GhiChu("MA SACH KHONG THUOC VE DOC GIA", 105, 17, 200, 800); goto MAT; break;
				}
				else{
					if(result.masach[0] != NULL){
						tim_thay = true;
						Thay_Doi_Trang_Thai_MT(temp->info.pMT, result.masach, date, 2);
						temp->info.pMT->info.ngaytra.ngay = 0;
						temp->info.pMT->info.ngaytra.thang = 0;
						temp->info.pMT->info.ngaytra.nam = 0;
						int nodeth = Thuoc_Dau_Sach_Thu(ds, result.masach);
						Thay_Doi_Trang_Thai_Sach(ds, nodeth, result.masach, 2);
						GhiChu("BAO MAT SACH THANH CONG! ^^", 105, 17, 200, 700);
						goto MAT;
						break;
					}
				}
			}
			if(tim_thay == false){
				GhiChu("MA SACH KHONG DUNG", 105, 17, 200, 600); goto MAT; 
			}
		}
		if(key == ESC)		break;
	}	
}

int countNode(PTR First);
void SaveFileDS(list ds, int n){
	
	ofstream fout("DAUSACH.txt", std::ofstream::trunc); int so_sach = 0;
	if(!fout.is_open()){
		cout<<"Khong mo duoc file"; exit(0);
	}
	else{
		for(int i=0;i<n;i++){
			PTR temp = NULL;
			fout << ds.nodes[i]->ISBN<<endl;
			fout << ds.nodes[i]->tensach<<endl;
			fout << ds.nodes[i]->tacgia<<endl;
			fout << ds.nodes[i]->theloai<<endl;
			fout << ds.nodes[i]->sotrang<<endl;
			fout << ds.nodes[i]->namxuatban<<endl;
			
			temp = ds.nodes[i]->pDMS;
			so_sach = countNode(temp);
			fout << so_sach <<endl;
			int j = 0;
			while((temp != NULL) && (j < so_sach) && (so_sach > 0)){

				fout<<temp->info.masach<<endl;
				fout<<temp->info.vitri<<endl;
				fout<<temp->info.trangthai<<endl;

				temp = temp->next;
				j++;
			}
			
		}
	}
	fout.close();
}

void Insert_Last(PTR &First, Sach &s);
void Delete_First(PTR &First);
PTR NewNode();
void LoadFileDS(list &ds){
	int so_sach = 0, j = 0; PTR p = NULL; Sach sach; 
	for(int i=0;i<MAXDS;i++){
		ds.nodes[i] = new DauSach;
		ds.nodes[i]->ISBN[0] = NULL;
		ds.nodes[i]->tensach[0] = NULL;
		ds.nodes[i]->tacgia[0] = NULL;
		ds.nodes[i]->theloai[0] = NULL;
		ds.nodes[i]->sotrang = 0;
		ds.nodes[i]->namxuatban = 0;
		ds.nodes[i]->pDMS = NULL;
	}

	ifstream fin("DAUSACH.txt");
	if(!fin.is_open()){
		cout<<"Can not open file"<<endl;
		exit(0);
	}	
	string s; DauSach b;
	while(!fin.eof() && j < MAXDS){		
		p = NULL;		
		getline(fin, s); 
		if(s.size() == 0) break;
		strcpy(b.ISBN, s.c_str()); 
		
		getline(fin, s); 
		if(s.size() == 0) break;
		strcpy(b.tensach, s.c_str());
		
		getline(fin, s);  
		if(s.size() == 0) break;
		strcpy(b.tacgia, s.c_str());
		
		getline(fin, s); 
		if(s.size() == 0) break;
		strcpy(b.theloai, s.c_str()); 
		
		fin>>b.sotrang;
		fin>>b.namxuatban;
		fin>>so_sach;
		
		// Doc nhung sach trong danh muc sach
		int k = 0; 
		while((k < so_sach) && (so_sach > 0)){
		
			fin.ignore();
			getline(fin, s);
			if(s.size() == 0)	break;
			strcpy(sach.masach, s.c_str());
			
			getline(fin, s);
			if(s.size() == 0)	break;
			strcpy(sach.vitri, s.c_str());
				
			fin>>sach.trangthai;
			Insert_Last(p, sach);
		
			k++; 
		}
		b.pDMS = p;
		
		fin.ignore();
		j++;
		
		Insert_item(ds, j, b); 	
			
	}
	fin.close();
}

void Nhap_Dau_Sach(list &ds){ // pos la vi tri sap duoc nhap vao cua mang
	int key, y = 8, dem, demkhongdoi, vitri = 0, temp, STT = 1; bool check_change = false; 
	dem = ds.n; demkhongdoi = ds.n;
	char so_trang[MAXDS][6], nam_xb[MAXDS][6]; // 
	
	if(dem == 0){
	for(int i=0;i<MAXDS;i++){
		ds.nodes[i] = new DauSach;
		
		ds.nodes[i]->ISBN[0] = '\0'; 
		ds.nodes[i]->namxuatban = 0; 
		ds.nodes[i]->pDMS = NULL;
		ds.nodes[i]->sotrang = 0; 
		ds.nodes[i]->tacgia[0] = '\0'; 
		ds.nodes[i]->tensach[0] = '\0'; 
		ds.nodes[i]->theloai[0] = '\0';
		
		so_trang[i][0] = NULL; nam_xb[i][0] = NULL;
		}
	}
	
	Khung_Nhap_Dau_Sach();
	TextColor(92);		gotoxy(6,8); 	 cout<<STT;		TextColor(91); 	
ISBN:
	while(1){
		TextColor(252);		
		gotoxy(20,29); printf("                                                              ");
		gotoxy(20,30); printf("          ISBN: TOI DA 4 KI TU (CAC KI TU TU A - Z)           ");
		gotoxy(20,31); printf("                                                              "); 
		TextColor(91);
		gotoxy(10+vitri,y); 
		key = GetKey();
		if((dem > 0) && (ds.nodes[dem-1]->namxuatban == 0) && y > 8){
			GhiChu("BAN CHUA NHAP NAM XUAT BAN!", 35, 27, 74, 700);
			gotoxy(86, --y);
			dem--;
			goto NXB;
		}
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri < 4)){
		
			ds.nodes[dem]->ISBN[vitri] = char(key);
			ds.nodes[dem]->ISBN[vitri] = toupper(ds.nodes[dem]->ISBN[vitri]);
			cout << ds.nodes[dem]->ISBN[vitri];
			vitri++;
			}
		if( key == BACKSPACE && vitri > 0){
			vitri--;
			gotoxy(10+vitri, y);
			cout<<" ";
			gotoxy(10+vitri, y);
		}
		if(key == ENTER && vitri != 0){
			ds.nodes[dem]->ISBN[vitri] = '\0';
	
			if(Check_ISBN(ds, dem) != -1){
				GhiChu("ISBN da ton tai, vui long nhap lai", 25, 26, 100, 700);
				vitri = strlen(ds.nodes[dem]->ISBN);
				gotoxy(10+vitri, y);
				cout<<" ";
				goto ISBN;
			}
			else{
				vitri = strlen(ds.nodes[dem]->tensach); 
				gotoxy(17+vitri, y);
				goto DAUSACH;
			}
		}
		if(key == ESC){
			if(check_change == true){
				ds.nodes[dem]->ISBN[vitri] = '\0';
				putchar(7);	gotoxy(4,24);  TextColor(251);	printf("ESC"); 
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	//-1 la Bat duoc 1 phim ESC nua~
				{
					gotoxy(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue; //Tô màu ESC
														// continue quay lai vong lap, cat khung thoat di
				}	
				if(temp == 1){
					SaveFileDS(ds, demkhongdoi);
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
				}
				if(temp == 0){
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
				}	
			}
			system("cls"); return;
		}
		if(key == RIGHT){ 
			ds.nodes[dem]->ISBN[vitri] = '\0';
			if(Check_ISBN(ds, dem) > 0){
				GhiChu("ISBN da ton tai, vui long nhap lai", 25, 26, 100, 700);
				vitri = strlen(ds.nodes[dem]->ISBN);
				gotoxy(10+vitri, y);
				cout<<" ";
				goto ISBN;
			}
			else{
				vitri = strlen(ds.nodes[dem]->tensach); 
				gotoxy(17+vitri, y);
				goto DAUSACH;
			}
		}
		if(key == UP && y > 8){
			ds.nodes[dem]->ISBN[vitri] = '\0';
			dem--;
			vitri = strlen(ds.nodes[dem]->ISBN);
			gotoxy(10+vitri,--y);
		}
		if(key == DOWN && y < 22 && ds.nodes[1+dem]->ISBN[0] != '\0'){
			ds.nodes[dem]->ISBN[vitri] = '\0';
			dem++;
			vitri = strlen(ds.nodes[dem]->ISBN);
			gotoxy(10+vitri,++y);
		}
	}

DAUSACH:
	while(1){
		TextColor(252);			
		gotoxy(20,29); printf("                                                               ");
		gotoxy(20,30); printf("       DAU SACH: GOM CAC KI TU (A-Z), TOI DA: 100 KI TU        ");
		gotoxy(20,31); printf("                                                               "); 
		TextColor(91);gotoxy(17+vitri,y);
		key = GetKey();
		if(ds.nodes[dem]->ISBN[0] == '\0'){
			GhiChu("BAN CHUA NHAP ISBN!",35,27,74,2000);
			vitri = strlen(ds.nodes[dem]->ISBN);
			gotoxy(10 + vitri,y);
			goto ISBN;
		}
		if((( key >= 'A' && key <= 'Z') || ((key<='9')&&key>='0') || ( key >='a' && key <= 'z' )) && (vitri < 31)){
			ds.nodes[dem]->tensach[vitri] = char(key);
			ds.nodes[dem]->tensach[vitri] = toupper(ds.nodes[dem]->tensach[vitri]);
			cout<<ds.nodes[dem]->tensach[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0){
			vitri--;
			gotoxy(17+vitri, y);
			cout<<" ";
			gotoxy(17+vitri, y);
		}
		if( key == SPACE && ds.nodes[dem]->tensach[vitri-1] != ' ' && vitri > 0 && vitri < 45){	// neu phan dau va phan cuoi cua ho la Space
			gotoxy(17+vitri , y);
			cout<<" ";
			ds.nodes[dem]->tensach[vitri] = ' ';
			vitri++;
		}
		if(key == ENTER && vitri!=0){
			if(ds.nodes[dem]->tensach[vitri-1] == ' ') 	{vitri--;}
			ds.nodes[dem]->tensach[vitri] = '\0';
			vitri = strlen(ds.nodes[dem]->tacgia);
			gotoxy(49+vitri,y);
			goto TACGIA;
		}
		if(key == ESC){
			if(check_change == true){
				ds.nodes[dem]->tensach[vitri] = '\0';
				putchar(7);	gotoxy(4,24);  TextColor(251);	printf("ESC"); 
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)
				{
					gotoxy(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue;
				}	
			if(temp == 1){
					SaveFileDS(ds, demkhongdoi);
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
				}
			if(temp == 0){
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
				}
			}
			system("cls");	return;
		}
		if(key == LEFT){
			ds.nodes[dem]->tensach[vitri] = '\0';
			vitri = strlen(ds.nodes[dem]->ISBN);
			gotoxy(10+vitri,y);
			goto ISBN;
		}
		if(key == RIGHT){
			ds.nodes[dem]->tensach[vitri] = '\0';
			vitri = strlen(ds.nodes[dem]->tacgia);
			gotoxy(49+vitri,y);
			goto TACGIA;
		}
		if(key == UP && y > 8){
			ds.nodes[dem]->tensach[vitri] = '\0';
			dem--;
			vitri = strlen(ds.nodes[dem]->tensach);
			gotoxy(17+vitri,--y);
		}
		if(key == DOWN && y < 22 && ds.nodes[1+dem]->tensach[0] != '\0'){
			ds.nodes[dem]->tensach[vitri] = '\0';
			dem++;
			vitri = strlen(ds.nodes[dem]->tensach);
			gotoxy(17+vitri,++y);
		}
	}
	
TACGIA:
	while(1){
		TextColor(252);			
		gotoxy(20,29); printf("                                                                ");
		gotoxy(20,30); printf("      PHAI: GOM CAC KI TU (A-Z) - NAM/NU, TOI DA: 3 KI TU       ");
		gotoxy(20,31); printf("                                                                "); 	
		TextColor(91);gotoxy(49+vitri,y);
		key = GetKey();
		if(ds.nodes[dem]->tensach[0] == '\0'){
			GhiChu("BAN CHUA NHAP TEN DAU SACH!",35,27,74,700);
			gotoxy(17,y);
			goto DAUSACH;
		}
		if((( key >= 'A' && key <= 'Z') ||  ( key >='a' && key <= 'z' )) && (vitri < 15)){
			ds.nodes[dem]->tacgia[vitri] = char(key);
			ds.nodes[dem]->tacgia[vitri] = toupper(ds.nodes[dem]->tacgia[vitri]);
			cout<<ds.nodes[dem]->tacgia[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0){
			vitri--;
			gotoxy(49+vitri, y);
			cout<<" ";
			gotoxy(49+vitri, y);
		}
		if(key == ENTER && vitri!=0){
			if(ds.nodes[dem]->tacgia[vitri-1] == ' ') 	{vitri--;}
			ds.nodes[dem]->tacgia[vitri] = '\0';
			vitri = strlen(ds.nodes[dem]->theloai);
			gotoxy(65+vitri,y);
			goto THELOAI;
		}
		if( key == SPACE && ds.nodes[dem]->tacgia[vitri-1] != ' ' && vitri > 0 && vitri < 30){	// neu phan dau va phan cuoi cua ho la Space
			gotoxy(49+vitri , y);
			cout<<" ";
			ds.nodes[dem]->tacgia[vitri] = ' ';
			vitri++;
		}
		if(key == ESC){
			if(check_change == true){
				ds.nodes[dem]->tacgia[vitri] = '\0';
				putchar(7);	gotoxy(4,24);  TextColor(251);	printf("ESC"); 
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	
				{
					gotoxy(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue;
				}	
			if(temp == 1){
					SaveFileDS(ds, demkhongdoi);
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
				}
			if(temp == 0){
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
				}
			}
			system("cls");	return;
		}
		if(key == LEFT){
			ds.nodes[dem]->tacgia[vitri] = '\0';
			vitri = strlen(ds.nodes[dem]->tensach);
			gotoxy(17+vitri,y);
			goto DAUSACH;
		}
		if(key == RIGHT){
			ds.nodes[dem]->tacgia[vitri] = '\0';
			vitri = strlen(ds.nodes[dem]->theloai);
			gotoxy(65+vitri,y);
			goto THELOAI;
		}
		if(key == UP && y > 8){
			ds.nodes[dem]->tacgia[vitri] = '\0';
			dem--;
			vitri = strlen(ds.nodes[dem]->tacgia);
			gotoxy(49+vitri,--y);
		}
		if(key == DOWN && y < 22 && ds.nodes[1+dem]->tensach[0] != '\0'){
			ds.nodes[dem]->tacgia[vitri] = '\0';
			dem++;
			vitri = strlen(ds.nodes[dem]->tacgia);
			gotoxy(49+vitri,++y);
		}
	}
	
THELOAI:
	while(1){
		TextColor(252);			
		gotoxy(20,29); printf("                                                              ");
		gotoxy(20,30); printf("    THE LOAI: GOM CAC KI TU (A-Z) & (0-9), TOI DA: 30 KI TU   ");
		gotoxy(20,31); printf("                                                              "); 
		TextColor(91);gotoxy(65+vitri,y);
		key = GetKey();
		if(ds.nodes[dem]->tacgia[0] == '\0'){
			GhiChu("BAN CHUA NHAP TEN TAC GIA!",35,27,74,700);
			gotoxy(49,y);
			goto TACGIA;
		}
		if((( key >= 'A' && key <= 'Z') || ( key >='a' && key <= 'z' )) && (vitri < 10)){
			ds.nodes[dem]->theloai[vitri] = char(key);
			ds.nodes[dem]->theloai[vitri] = toupper(ds.nodes[dem]->theloai[vitri]);
			cout << ds.nodes[dem]->theloai[vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0){
			vitri--;
			gotoxy(65+vitri, y);
			cout<<" ";
			gotoxy(65+vitri, y);
		}
		if(key == ENTER && vitri!=0){
			if(ds.nodes[dem]->theloai[vitri-1] == ' ') 	{vitri--;}
			ds.nodes[dem]->theloai[vitri] = '\0';
			vitri = strlen(so_trang[dem]);
			gotoxy(80+vitri,y);
			goto SOTRANG;
		}
		if( key == SPACE && ds.nodes[dem]->theloai[vitri-1] != ' ' && vitri > 0 && vitri < 15){	
			gotoxy(65+vitri , y);
			cout<<" ";
			ds.nodes[dem]->theloai[vitri] = ' '; 
			vitri++;
		}
		if(key == ESC){
			if(check_change == true){
				ds.nodes[dem]->theloai[vitri] = '\0';
				putchar(7);	gotoxy(4,24);  TextColor(251);	printf("ESC"); 
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	
				{
					gotoxy(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue;
				}	
			if(temp == 1){
					SaveFileDS(ds, demkhongdoi);
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
				}
			if(temp == 0){
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
				}
			}
			system("cls");	return;
		}
		if(key == LEFT){
			ds.nodes[dem]->theloai[vitri] = '\0';
			vitri = strlen(ds.nodes[dem]->tacgia);
			gotoxy(49+vitri,y);
			goto TACGIA;
		}
		if(key == RIGHT){
			ds.nodes[dem]->theloai[vitri] = '\0';
			vitri = strlen(so_trang[dem]);
			gotoxy(80+vitri,y);
			goto SOTRANG;
		}
		if(key == UP && y > 8){
			ds.nodes[dem]->theloai[vitri] = '\0';
			dem--;
			vitri = strlen(ds.nodes[dem]->theloai);
			gotoxy(65+vitri,--y);
		}
		if(key == DOWN && y < 22 && ds.nodes[1+dem]->theloai[0] != '\0'){
			ds.nodes[dem]->theloai[vitri] = '\0';
			dem++;
			vitri = strlen(ds.nodes[dem]->theloai);
			gotoxy(65+vitri,++y);
		}
	}

SOTRANG:
	while(1){
		TextColor(252);			
		gotoxy(20,29); printf("                                                               ");
		gotoxy(20,30); printf("           SO TRANG: SO NGUYEN GOM CAC KI TU (0-9)             ");
		gotoxy(20,31); printf("                                                               "); 
		TextColor(91);gotoxy(80+vitri,y);
		key = GetKey();
		if(ds.nodes[dem]->theloai[0] == '\0'){
			GhiChu("BAN CHUA NHAP THE LOAI!",35,27,74,700);
			gotoxy(65,y);
			goto THELOAI;
		}
		if((key >= '0' && key <= '9') && (vitri < 5)){
			so_trang[dem][vitri] = key;
			cout<<so_trang[dem][vitri];
			vitri++;
		}
		
		if( key == BACKSPACE && vitri > 0){
			vitri--;
			gotoxy(80+vitri, y);
			cout<<" ";
			gotoxy(80+vitri, y);
		}
		if(key == ENTER && vitri!=0){
			so_trang[dem][vitri] = '\0';
			ds.nodes[dem]->sotrang = atoi(so_trang[dem]);
			vitri = strlen(nam_xb[dem]);
			gotoxy(86+vitri,y);
			goto NXB;
		}
		if(key == ESC){
			if(check_change == true){
				so_trang[dem][vitri] = '\0';
				putchar(7);	gotoxy(4,24);  TextColor(251);	printf("ESC"); 
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	
				{
					gotoxy(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue;
				}	
			if(temp == 1){
					SaveFileDS(ds, demkhongdoi);
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
				}
			if(temp == 0){
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
				}
			}
			system("cls");	return;
		}
		if(key == LEFT){
			so_trang[dem][vitri] = '\0';
			vitri = strlen(ds.nodes[dem]->theloai);
			gotoxy(65+vitri,y);
			goto THELOAI;
		}
		if(key == RIGHT){
			so_trang[dem][vitri] = '\0';
			vitri = strlen(nam_xb[dem]);
			gotoxy(86+vitri,y);
			goto NXB;
		}
		if(key == UP && y > 8){
			so_trang[dem][vitri] = '\0';
			dem--;
			vitri = strlen(so_trang[dem]);
			gotoxy(80+vitri,--y);
		}
		if(key == DOWN && y < 22 && strlen(so_trang[1+dem]) != 0){
			so_trang[dem][vitri] = '\0';
			dem++;
			vitri = strlen(so_trang[dem]);
			gotoxy(80+vitri,++y);
		}
	}

NXB:
	while(1){
		TextColor(252);			
		gotoxy(20,29); printf("                                                               ");
		gotoxy(20,30); printf("           NAM XUAT BAN: SO NGUYEN GOM CAC KI TU (0-9)         ");
		gotoxy(20,31); printf("                                                               "); 
		TextColor(91);gotoxy(86+vitri,y);
		key = GetKey();
	
		if(so_trang[dem][0] == '\0'){
			GhiChu("BAN CHUA NHAP SO TRANG!",35,27,74,700);
			cout<<" ";
			gotoxy(80,y);
			goto SOTRANG;
		}
		if((key >= '0' && key <= '9') && (vitri < 4)){
			nam_xb[dem][vitri] = key;
			cout<<nam_xb[dem][vitri];
			vitri++;
		}
		if( key == BACKSPACE && vitri > 0){
			vitri--;
			gotoxy(86+vitri, y);
			cout<<" ";
			gotoxy(87+vitri, y);
		}
		if(key == LEFT){
			nam_xb[dem][vitri] = '\0';
			vitri = strlen(so_trang[dem]);
			gotoxy(80+vitri,y);
			goto SOTRANG;
		}
		if(key == UP && y > 8){
			nam_xb[dem][vitri] = '\0';
			dem--;
			vitri = strlen(nam_xb[dem]);
			gotoxy(86+vitri,--y);
		}
		if(key == DOWN && y < 22 && strlen(nam_xb[1+dem]) != 0){
			nam_xb[dem][vitri] = '\0';
			dem++;
			vitri = strlen(nam_xb[dem]);
			gotoxy(86+vitri,++y);
		}
		if(key == ENTER && strlen(nam_xb[dem]) != 0){
			ds.nodes[dem]->namxuatban = atoi(nam_xb[dem]);
			check_change = true;
			GhiChu("Save Thanh Cong!",40,27,74,500);	TextColor(92);
			gotoxy(6,y+1);
			if(dem == demkhongdoi) {
				cout<<++STT; 
				demkhongdoi++;
			}
			if((STT-1) % 15 == 0){
				y = 7;
				system("cls");
				Khung_Nhap_Dau_Sach();	TextColor(92);	gotoxy(6,8); cout<<STT;	
			}
			TextColor(91);	
			dem++;
			ds.n++;
			vitri = strlen(ds.nodes[dem]->ISBN);
			gotoxy(10+vitri,++y);
			goto ISBN ;
		}
		if(key == ESC){
			if(check_change == true){
				nam_xb[dem][vitri] = '\0';
				putchar(7);	gotoxy(4,24);  TextColor(251);	printf("ESC"); 
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	
				{
					gotoxy(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue;
				}	
			if(temp == 1){
					SaveFileDS(ds, demkhongdoi);
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
				}
			if(temp == 0){
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
				}
			}
			system("cls");	return;
			
		}
	}
}

//--------------------------------------------------   DANH MUC SACH   ---------------------------------------------------------//

PTR First = NULL;
void Initialize(PTR &First) 	{First = NULL; }

PTR NewNode(){
	PTR p = new NodeSach;
	return p ;
}

// nodepointer: xac dinh con tro cua nut i trong danh sach lien ket
PTR nodepointer(PTR First, int i){
	PTR p;
	int pos = 1;
	p = First;
	while(p != NULL && pos < i){
		p = p->next;
		pos++;
	}
	return p;
}

// position xac dinh vi tri cua nut p trong danh sach lien ket.
int position(PTR First, PTR p){
	int pos;
	PTR q;
	q = First;
	pos = 1;
	while(q != NULL && q != p){
		q = q->next;
		pos++;
	}
	if(q == NULL)	return -1; 
	else return pos;
}

int EmptyDMS(PTR First){
	return(First == NULL ? 1 : 0);
}
// Them nut moi vao dau danh sach lk don
void Insert_First(PTR &First, Sach s){
	PTR p = new NodeSach;
	p->info = s;
	p->next = First;
	First = p;
}

//Them nut moi vao sau nut co dia chi p
void Insert_After(PTR p, Sach s){
	PTR q;
	if(p == NULL)	cout<<"Khong the them sach vao danh sach duoc"<<endl;
	else{
		q = new NodeSach;
		q->info = s;
		q->next = p->next;
		p->next = q;
	}
}

void Insert_Last(PTR &First, Sach &s){
	PTR p = NewNode();
	p->info = s;
	p->next = NULL;
	if(First == NULL)	First = p;
	else{
		PTR Last;
		for(Last=First; Last->next != NULL; Last=Last->next);
		Last->next = p;
	}
}

void Delete_First(PTR &First){
	PTR p;
	if(EmptyDMS(First))	cout<<"Khong co sach nao trong danh sach"<<endl;
	else{
		p = First;
		First = p->next;
		delete p;
	}
}

// xoa nut sau nut p
void Delete_After(PTR p){
	PTR q;
	// Neu p la nut cuoi hoac p chi den nut cuoi
	if(p == NULL || p->next == NULL){
		cout<<"Khong the xoa duoc sach nay"<<endl;
	}
	else{
		q = p->next;
		p->next = q->next; // tao lien ket moc vong qua node q
		delete q; 		   // sau do xoa node q.
	}
}

void Clear_List(PTR &First){
	PTR p;
	p = First;
	while(First != NULL){
		p = First;
		First = First->next;
		delete p;
	}
}

int countNode(PTR First){
	int count = 0;
	PTR p = First;
	if(p == NULL)	return 0;
	while(p!=NULL){
		count++; p = p->next;
	}
	return count;
}

void TraverseNodeSach(PTR First){
	PTR p;
	int stt = 0;
	p = First;
	if(p==NULL)		cout<<"Khong co sach nao trong danh muc sach\n\n";
	else 	
		cout<<"   STT"<<"     MA SACH"<<"    VI TRI       TRANG THAI        "<<endl;
		cout<<"-----------------------------------------------------"<<endl;
	while(p != NULL){
		cout.setf(ios::left);
		cout<<" | "<<setw(5)<<++stt;
		cout<<" | "<<setw(6)<<p->info.masach;
		cout<<" | "<<setw(10)<<p->info.vitri;
		//cout.setf(ios::right);
		cout<<" | "<<setw(20);
		if(p->info.trangthai == 0) cout<<"CHO MUON DUOC"<<endl;
		else if(p->info.trangthai == 1)	cout<<"DA DUOC MUON"<<endl;
		else cout<<"DA THANH LY"<<endl;
		p = p->next; 
	}
	cout<<endl;
}

string Chuan_Hoa_Str(string a){
	for(int i=1;i<a.length();i++){
		if(a[0] == ' '){
			a.erase(0, 1); // xoa ki tu dau mang
			i--;
		}
		else if(a[i-1] == ' ' && a[i] == ' '){ // giua 2 chu khong co nhieu hon 1 khoang trang
			a.erase(i-1, 1);
			i--;
		}
		else if(a[a.length() - 1] == ' '){
			a.erase(a.length() - 1, 1);
			i--;
		}
	}
	return a;
}

int Tim_Dau_Sach(list &ds, string search){
	char word[100]; int i = 0;
	search = Chuan_Hoa_Str(search);
	strcpy(word, search.c_str());
	
	strupr(word);
	while(i < ds.n && strcmp(ds.nodes[i]->tensach, word) != 0){
		i++;
		}
	return((i==ds.n) ? -1 : i);
}

// -----------------------------------------	TIM NHUNG   ----------------------------------------------//
int findsubstr(const char *str, char *sub);

void Tim_Nhung(list &ds, string search){
		char word[100]; int i = 0, time = 0;
		search = Chuan_Hoa_Str(search);
		strcpy(word, search.c_str());
		
		strupr(word);
		
		bool found = false;
		for(i=0;i<ds.n;i++){
			if((findsubstr(ds.nodes[i]->tensach, word) != -1) && strcmp(word, " ") != 0 && strcmp(word, "\0") != 0){
				found = true;
				TextColor(11); 
				cout<<"\n\t\t\tISBN: "<<ds.nodes[i]->ISBN<<endl;
				cout<<"\t\t\tTen Sach: "<<ds.nodes[i]->tensach<<endl;
				cout<<"\t\t\tTen Tac Gia: "<<ds.nodes[i]->tacgia<<endl;
				cout<<"\t\t\tTen the loai: "<<ds.nodes[i]->theloai<<endl;
				cout<<"\t\t\tSo trang: "<<ds.nodes[i]->sotrang<<endl;
				cout<<"\t\t\tNam xuat ban: "<<ds.nodes[i]->namxuatban<<endl;
				TextColor(206);
				cout<<"\t    Cac sach trong danh muc: "<<endl<<endl;
				if(ds.nodes[i]->pDMS != NULL){
					TextColor(116);
					TraverseNodeSach(ds.nodes[i]->pDMS);
					cout<<endl;
				}
				time++;
			}
		}
		if(found == false && time == 0){
			gotoxy(48, 3); TextColor(110); cout << "TEN SACH KHONG TON TAI"<<endl;
		}	
}

// ---------------------------------------------- SAP XEP DAU SACH THEO TUNG THE LOAI -------------------------//

int TimTheLoaiPhanBiet(list &ds, int a[]){
	int m ; m = 0; 
	a[m] = 0; // the loai dau tien la the loai phan biet
	m++; // so luong tang len (co 1 phan tu the loai phan biet)
	for(int i=1;i<ds.n;i++){
		bool check = true ; // la the loai phan biet
		for(int j=i-1; j>=0;j--){
			if(strcmp(ds.nodes[i]->theloai, ds.nodes[j]->theloai) == 0){
				check = false; // the loai nay da co roi nen khong la the loai phan biet
				break;
			}
		}
		if(check){
			a[m] = i; // cat chi so cua danh sach co the loai phan biet vao mang a
			m++; 
		}
	}
	return m; // m la so phan tu cua mang a 
}

void Swap(DauSach &p, DauSach &q){
	DauSach _temp;
	_temp = p; p = q; q = _temp;
}

void Selection_Sort(DauSach arr[], int n){
	char min[100];
	int vitrimin, i, j;
	
	for(i = 0; i<(n - 1); i++){
		strcpy(min, arr[i].tensach);
		vitrimin = i;
		for(j = i+1; j < n; j++){
			if(strcmp(arr[j].tensach, min) < 0){
				strcpy(min, arr[j].tensach);
				vitrimin = j;
			}
		}
		Swap(arr[i], arr[vitrimin]);
	}		
}

void DanhSachTam(list &ds, int a[], DauSach arr[], int num){
	DauSach b; 
	TextColor(233);
	cout<<"\n--------------------------------* DANH SACH CAC DAU SACH THEO THU TU TEN SACH TANG DAN *----------------------------\n";
	for(int i=0;i<num;i++){
		TextColor(10);
		cout<<"\n\t\t\t\t*********  CAC SACH THUOC THE LOAI ";
		TextColor(206);
		cout<<ds.nodes[a[i]]->theloai;
		TextColor(10);
		cout<<" *********\n"<<endl;
		int k = 0; // cu moi lan di vao the loai moi thi reset k = 0
		for(int j=0;j<ds.n;j++){
			if(strcmp(ds.nodes[j]->theloai, ds.nodes[a[i]]->theloai) == 0){
				strcpy(b.ISBN, ds.nodes[j]->ISBN);
				strcpy(b.tensach, ds.nodes[j]->tensach);
				strcpy(b.tacgia, ds.nodes[j]->tacgia);
				strcpy(b.theloai, ds.nodes[j]->theloai);
				b.sotrang = ds.nodes[j]->sotrang;
				b.namxuatban = ds.nodes[j]->namxuatban;
				b.pDMS = ds.nodes[j]->pDMS;
				
				arr[k] = b;
				k++;
			}
		}
		// SAP XEP DANH SACH TAM VA IN RA MAN HINH
		Selection_Sort(arr, k);
		for(int i=0;i<k;i++){
			TextColor(11);
			cout<<"\t\t\t\t\t"<<arr[i].tensach<<endl;
		}	
	}
}

void Xu_Ly_Tim_Nhung(list &ds);
void TimNhung_SapXep(list &List){
	TextColor(11);
	while(1){
		system("cls");
		TextColor(11);
		int a[20]; DauSach A[MAXDS]; 
		for(int i=0;i<20;i++)	a[i] = 0;	// Khoi tao mang a
		int num = TimTheLoaiPhanBiet(List, a);
	
		DanhSachTam(List, a, A, num);
		system("pause");
		cout<<"Press F1 for searching"<<endl;
		cout<<"Press ESC to exit"<<endl;
		int key = GetKey();
		system("cls");
		if(key == ESC)	break;
		else if(key == F1){
			Xu_Ly_Tim_Nhung(List);
			system("cls");
			TextColor(11);
		}
	}
}

// ----------------------------------------- THONG KE SACH MUON NHIEU ------------------------------------------//

int TongSoSachDangMuon(PTR &p){
	int dem = 0;
	PTR temp;
	for(temp = p; temp != NULL; temp = temp->next){
		if((temp->info.trangthai == 1) || (temp->info.trangthai == 2)){
			dem++;
		}
	}
	return dem;
}

void SwapTopBook(TopBook &p, TopBook &q){
	TopBook temp_top = p;
	p = q;  q = temp_top;
}

void heapify(TopBook arr[], int n, int i) // vun dong cho cay, i la goc, n la so luong phan tu
{ 
    int min = i; // Initialize minimum as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
    // If left child is less than root 
    if (l < n && arr[l].so_sach_muon < arr[min].so_sach_muon) 
        min = l; 
  
    // If right child is less than largest so far 
    if (r < n && arr[r].so_sach_muon < arr[min].so_sach_muon) 
        min = r; 
  
    // If minimum is not root 
    if (min != i) 
    { 
        SwapTopBook(arr[i], arr[min]); 
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, min); 
    } 
} 

void HeapSort(TopBook arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
	
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        SwapTopBook(arr[0], arr[i]); 
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

void TopBookTemp(list &ds, TopBook top[]){
	TopBook t;
	for(int i=0;i<ds.n;i++){
		strcpy(t.tensach, ds.nodes[i]->tensach);
		t.so_sach_muon = TongSoSachDangMuon(ds.nodes[i]->pDMS);
		top[i] = t;
	}
	HeapSort(top, ds.n);
	TextColor(14);
	cout<<"				TOP 10 SACH CO LUOT MUON NHIEU NHAT\n\n\n";
	cout<<"   STT"<<"                   TEN SACH                   SO LUOT MUON"<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
	int stt = 0;
	while((top[stt].so_sach_muon > 0 && stt < 10) || (top[stt].so_sach_muon == top[stt+1].so_sach_muon && top[stt].so_sach_muon > 0)){
				
		TextColor(11);
		cout.setf(ios::left);

		cout<<" | "<<setw(5)<<++stt<<" | "<<setw(40)<<top[stt].tensach<<" | "<<setw(10)<<top[stt].so_sach_muon<<endl;
	}
	TextColor(243);
}

//--------------------------------------------------------------------------------------------------------//

void Khung_Cap_Nhat_DMS(){
	SetBGColor(45);
	gotoxy(0, 0);
	TextColor(90);	
	printf("\n\n\n\n\n   +---------------------------------------------------------------------"   );	
	printf("\n   |     |	   |		      		          |          	|");	
	printf("\n   |-----+---------+--------------------------------------+-------------+");	
	printf("\n   |	 |         |       	                          |             |");	
	printf("\n   |	 |         |		                          |	        |");	
	printf("\n   | 	 |	   |		                          |		|");	
	printf("\n   |	 |	   |		                          | 	        |");	
	printf("\n   |	 |	   |		                          |		|");	
	printf("\n   |	 |	   |		                          |		|");	
	printf("\n   |	 |	   |		                          |		|");	
	printf("\n   |	 |	   |		                          |		|");	
	printf("\n   |	 |	   |		                          |		|");	
	printf("\n   |	 |	   |		                          |		|"   );	
	printf("\n   |	 |	   |		                          |		|"   );	
	printf("\n   |	 |	   |		                          |		|"   );	
	printf("\n   |	 |	   |		                          |		|"   );	
	printf("\n   |	 |	   |		                          |		|"   );	
	printf("\n   |	 |	   |		                          |		|"   );	
	printf("\n   |--------------------------------------------------------------------|");	
	printf("\n   |                                                                    |");	
	printf("\n   +--------------------------------------------------------------------+");
	TextColor(236);	gotoxy(16,1);	printf("                                                                                    ");	
	gotoxy(16,2);					printf("                CAP NHAT THONG TIN DANH MUC SACH CUA DAU SACH                       ");		
	gotoxy(16,3);					printf("                                                                                    ");
	TextColor(94);
	gotoxy(5,6);    printf("STT");	
	gotoxy(11,6);	printf("MA SACH");	
	gotoxy(35,6);	printf("VI TRI");	
	gotoxy(60,6);	printf("TRANG THAI");	

	gotoxy(4,24);	TextColor(252);	printf("ESC");	
	TextColor(91);	printf(": Exit");		
	gotoxy(20,24);	TextColor(252);	printf("ENTER");	
	TextColor(116);	printf(": OK");		
	gotoxy(36,24);	
	TextColor(252);	printf("CONTROL");	
	TextColor(91);	printf(": LEFT - RIGHT - UP - DOWN");
	TextColor(91); gotoxy(76, 24);
	gotoxy(0,27);
}

int findsubstr(const char *str, char *sub)
{
    const char *p = str;
    int len = strlen(sub);
    while(*p != NULL)
    {
        if (strlen(p) >= len)
        {
            if (strncmp(p, sub, strlen(sub)) == 0)
            {
                return (p - str);
            }
        }
        else
        {
            break;
        }
        p++;
    }
    return -1;
}

char* Auto_Code(list &ds, int i, int increment){
	// Load file danh muc sach de biet co nhieu sach da ton tai trong danh muc sach
	int nodeth, so_sach = 0;
	char a[5], temp[4];
	nodeth = i;
	for(PTR q=ds.nodes[nodeth]->pDMS; q!=NULL; q=q->next)
		if(findsubstr(q->info.masach, ds.nodes[nodeth]->ISBN) != -1)	so_sach++;

	so_sach += increment;
	strcpy(temp, ds.nodes[nodeth]->ISBN);
	itoa(so_sach, a, 10);
	strcat(temp, a);
	
	return temp;
}

void Cap_Nhat_DMS(list &ds, int k){// Danh ma tu dong, k cho biet Dau sach can cap nhat o nut thu may
	Sach s[MAX]; 					// r cho biet so luong dau sach
	
	for(int i=0;i<MAX;i++){
		s[i].masach[0] = NULL;
		s[i].trangthai = 0;
		s[i].vitri[0] = NULL;
	}
	
	int key, y = 8, vitri1 = 0, dem = 0, demkhongdoi = 0, temp, STT = 1; bool check_change = false;
	
	Khung_Cap_Nhat_DMS();
	TextColor(92);		gotoxy(6,8); 	 cout<<STT;		TextColor(91);

MASACH:
	while(1){
		TextColor(92); gotoxy(10 + vitri1, y);
		strcpy(s[dem].masach, Auto_Code(ds, k, dem));
		cout<<s[dem].masach;
		vitri1 = strlen(s[dem].vitri);
		gotoxy(20+vitri1, y);
		goto VITRI;
	}
	
VITRI:
	while(1){
		TextColor(91);			
		gotoxy(10,29); printf("                                                               					");
		gotoxy(10,30); printf("                                    VI TRI GOM CAC KI TU TU A-Z, 0-9                                  ");
		gotoxy(10,31); printf("                                                               					");
		TextColor(92);gotoxy(20+vitri1,y);
		key = GetKey();
		if((( key >= 'A' && key <= 'Z') || ( key <= '9' && key >= '0') || ( key >='a' && key <= 'z' )) && (vitri1 < 38)){
			s[dem].vitri[vitri1] = char(key);
			s[dem].vitri[vitri1] = toupper(s[dem].vitri[vitri1]);
			cout << s[dem].vitri[vitri1];
			vitri1++;
		}
		if( key == BACKSPACE && vitri1 > 0){
			vitri1--;
			gotoxy(20+vitri1, y);
			cout<<" ";
			gotoxy(20+vitri1, y);
		}
		if(key == ENTER && vitri1 != 0){ 
			if(s[dem].vitri[vitri1-1] == ' ') 	{vitri1--;}
			s[dem].vitri[vitri1] = '\0'; 
			vitri1 = 1;
			gotoxy(58+vitri1, y);
			goto TRANGTHAI;
		}
		if( key == SPACE && s[dem].vitri[vitri1-1] != ' ' && vitri1 > 0 && vitri1 < 38){	
			gotoxy(20+vitri1 , y);
			cout<<" ";
			s[dem].vitri[vitri1] = ' '; 
			vitri1++;
		}
		if(key == ESC){
			if(check_change == true){
				s[dem].vitri[vitri1] = '\0';
				putchar(7);	gotoxy(4,24);  TextColor(251);	printf("ESC"); 
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	
				{
					gotoxy(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue; 
				}	
				if(temp == 1){
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					for(int i = 0; i < demkhongdoi; i++)
					Insert_Last(ds.nodes[k]->pDMS, s[i]);
					
					SaveFileDS(ds, ds.n); 
					
				}
				if(temp == 0){
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)
					
						Insert_Last(ds.nodes[k]->pDMS, s[i]);
						
						//tro den danh sach cac sach cua dau sach
						
				}
			}		
			system("cls");	return;
		}
		if(key == RIGHT){ 
			s[dem].vitri[vitri1] = '\0';
			vitri1 = 1;
			gotoxy(58+vitri1,y);
			goto TRANGTHAI;
		}
		if(key == UP && y > 8){
			s[dem].vitri[vitri1] = '\0';
			dem--;
			vitri1 = strlen(s[dem].vitri);
			gotoxy(20+vitri1,--y);
		}
		if(key == DOWN && y < 22 && s[1+dem].vitri[0] != '\0'){
			s[dem].vitri[vitri1] = '\0';
			dem++;
			vitri1 = strlen(s[dem].vitri);
			gotoxy(20+vitri1,++y);
		}
	}
	
TRANGTHAI:
	while(1){
		TextColor(91);			
		gotoxy(10,29); printf("                                                               					");
		gotoxy(10,30); printf("     CHI SO:(0, 1 HOAC 2) 0: CHO MUON DUOC  1: DA CO NGUOI MUON  2:DA THANH LY                        ");
		gotoxy(10,31); printf("                                                               					");
		TextColor(92);	
		gotoxy(58 + vitri1, y);
		key = GetKey();
		if(s[dem].vitri[0] == '\0' )
		{
			GhiChu("BAN CHUA NHAP VI TRI SACH!",35,27,74,700);
			gotoxy(20,y);
			goto VITRI;
		}
		if(key >= '0' && key <= '2'){
			if(key == '0'){
				s[dem].trangthai = 0; 
			}
			else if(key == '1'){
				s[dem].trangthai = 1;
			}
			else {
				s[dem].trangthai = 2;
			}
		}
		if(s[dem].trangthai == 0)		cout<<"CHO MUON DUOC";
		else if(s[dem].trangthai == 1)	cout<<"DA DUOC MUON ";
		else if(s[dem].trangthai == 2)	cout<<"DA THANH LY  ";
		else	cout<<"               ";
		if(key == LEFT){
			vitri1 = strlen(s[dem].vitri);
			gotoxy(20+vitri1, y);
			goto VITRI;
		}
		if(key == UP && y>8){
			dem--;
			vitri1 = 1;
			gotoxy(58+vitri1, --y);
		}
		if(key == DOWN && y < 22 && s[1+dem].trangthai != -1){
			dem++;
			vitri1 = 1;
			gotoxy(58+vitri1, ++y);
		}
		if(key == ESC){
			if(check_change == true){
				s[dem].vitri[vitri1] = '\0';
				putchar(7);	gotoxy(4,24);  TextColor(251);	printf("ESC"); 
				int temp = ThongBao_ESC_Nhap();
				if(temp == -1)	
				{
					gotoxy(4,24);  TextColor(252);	printf("ESC"); TextColor(91); continue; 
				}	
				if(temp == 1){
					GhiChu("Luu Vao File Thanh Cong!",35,27,74,2000); 
					
					for(int i = 0; i < demkhongdoi; i++)
						Insert_Last(ds.nodes[k]->pDMS, s[i]);
						SaveFileDS(ds, ds.n); 
					
				}
				if(temp == 0){
					GhiChu("Luu Vao File Khong Thanh Cong!",35,27,74,2000);
					for(int i = 0; i < demkhongdoi; i++)
					Insert_Last(ds.nodes[k]->pDMS, s[i]);
					
				}
			}		
			system("cls");	return;
		}
		if(key == ENTER && (s[dem].trangthai == 0 || s[dem].trangthai == 1 || s[dem].trangthai == 2)){ 
			check_change = true; 
			GhiChu("Save Thanh Cong!",40,27,74,500);
			TextColor(92);
			gotoxy(6,y+1);
			if(dem == demkhongdoi) { 
				cout<<++STT; 
				demkhongdoi++;
			}
			if((STT-1) % 15 == 0){
				y = 7;
				system("cls");
				Khung_Cap_Nhat_DMS();	TextColor(116);	gotoxy(6,8); cout<<STT;	
			}
			TextColor(92);	
			dem++;
			vitri1 = 0;
			gotoxy(10+vitri1,++y);
			goto MASACH;
		}
	}
}

void Tim_Sach_Va_Cap_Nhat(list &ds){
C:
	system("cls");
	char search[100]; 
	gotoxy(19, 1); TextColor(6);
	gotoxy(19, 1); cout<<"                          "<<endl;
	gotoxy(19, 1); cout<<"NHAP DAY DU TEN SACH CAN TIM:    "<<endl;
	gotoxy(48, 1); TextColor(240); cout<<"                                                   "<<endl;
	gotoxy(48, 1);
	int y = 1, vitri = 0;
	while(1){
		int key = GetKey();
		if((( key >= 'A' && key <= 'Z')||( key <= '9' && key >= '0')||( key >='a' && key <= 'z' )) && (vitri < 45)){
			search[vitri] = char(key);
			search[vitri] = toupper(search[vitri]);
			cout << search[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(48 + vitri, y);
			cout << " ";
			gotoxy(48 + vitri, y);
		}
		if(key == ESC)	break;
		if( key == SPACE && search[vitri-1] != ' ' && vitri > 0 && vitri < 45){	
			gotoxy(48+vitri , y);
			cout<<" ";
			search[vitri] = ' ';
			vitri++;
		}
		if(key == ENTER && vitri != 0){
			search[vitri] = '\0';
			int nodeth = Tim_Dau_Sach(ds, search);
			if(nodeth == -1){
			GhiChu("TEN SACH KHONG TON TAI", 30, 5, 200, 600);  goto C;
			//system("pause"); 
			}
			else{
				Cap_Nhat_DMS(ds, nodeth);  goto C;
			}	
		}
	}
}

void Xu_Ly_Tim_Nhung(list &ds){
B:
	system("cls"); TextColor(11);
	char search[100]; 
	gotoxy(25, 1); TextColor(6);
	gotoxy(25, 1); cout<<"                          "<<endl;
	gotoxy(25, 1); cout<<"NHAP TEN SACH CAN TIM:    "<<endl;
	gotoxy(48, 1); TextColor(240); cout<<"                                                   "<<endl;
	gotoxy(48, 1);
	int y = 1, vitri = 0;	
	while(1){
		int key = GetKey();
		if((( key >= 'A' && key <= 'Z')||( key <= '9' && key >= '0')||( key >='a' && key <= 'z' )) && (vitri < 45)){
			search[vitri] = char(key);
			search[vitri] = toupper(search[vitri]);
			cout << search[vitri];
			vitri++;
		}
		if (key == BACKSPACE && vitri > 0) {
			vitri--;
			gotoxy(48 + vitri, y);
			cout << " ";
			gotoxy(48 + vitri, y);
		}
		if(key == ESC)	break;
		if( key == SPACE && search[vitri-1] != ' ' && vitri > 0 && vitri < 45){	// neu phan dau va phan cuoi cua ho la Space
			gotoxy(48+vitri , y);
			cout<<" ";
			search[vitri] = ' ';
			vitri++;
		}
		if(key == ENTER && vitri != 0){
			search[vitri] = '\0';
			Tim_Nhung(ds, search);
			system("pause"); goto B;
			//break;
		}
	}
}


#endif
