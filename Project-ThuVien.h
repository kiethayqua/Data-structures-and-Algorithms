#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000
#define maxsach 1000

/*********************************/
struct Ngay{
	int ngay;
	int thang;
	int nam;
};
/*********************************/
struct Sach{
	char masach[20];
	int trangthai=0;
	char vitri[50];
};
struct NodeSach{
	Sach info;
	NodeSach *next;
};

/*********************************/

struct DauSach{
	char ISBN[30];
	char tensach[100];
	int sotrang;
	char tacgia[100];
	int namxuatban;
	char theloai[30];
	NodeSach *pDMS=NULL;
};
struct ListDauSach{
	int n = 0;
	DauSach *nodes[MAX];
};
/*********************************/

struct MuonTra{
	char masach[20];
	Ngay ngaymuon;
	Ngay ngaytra;
	int trangthai=0;
};
struct NodeMuonTra{
	MuonTra info;
	NodeMuonTra *left, *right;
};
/*********************************/

struct DocGia{
	int mathe;
	char ho[50];
	char ten[10];
	char phai[10];
	int trangthai = 0 ;
	NodeMuonTra *pMT = NULL;
};
struct TreeDocGia{
	DocGia info; 
	TreeDocGia *left;
	TreeDocGia *right;
};

struct TopBook{
	char tensach[100];
	int so_sach_muon = 0;
};

typedef TreeDocGia *treedocgia;
typedef ListDauSach list;
typedef NodeSach *PTR;
typedef NodeMuonTra *nodemuontra;
