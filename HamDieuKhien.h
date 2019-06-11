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

int GetKey(){	
	char key;
	key = getch();
	if(key==-32 || key==0)
	return -getch();
	else return key;
}

// HIEN THI GHI CHU
void GhiChu(char c[], int x, int y, int color, int sleep){
	gotoxy(x,y);
	TextColor(color);
	cout<<c;
	Sleep(sleep);
	gotoxy(x,y);
	TextColor(91);
	cout<<"                                                  ";
}

int ThongBao_ESC_Nhap(){
	int key, count = 0;	TextColor(206);
	gotoxy(25,26);	printf("     Ban Co Muon Luu Vao File!   ");	
	gotoxy(25,27);	printf("   ");	gotoxy(55,27);	printf("   ");	
	gotoxy(25,28);	printf("   ");	gotoxy(55,28);	printf("   ");	
	gotoxy(25,29);	printf("   ");	gotoxy(55,29);	printf("   ");	
	gotoxy(25,30);	printf("                                 ");	
	TextColor(238);	gotoxy(28,27); printf("                           ");	
	gotoxy(28,28); printf("                           ");	
	gotoxy(28,29); printf("                           ");
	TextColor(252);	gotoxy(33,28);	printf(" YES ");	
	TextColor(233);	gotoxy(45,28);	printf(" NO ");	
	gotoxy(34,28);	
	while(1){		
		key = GetKey();		
		if(key == LEFT || key == RIGHT)	{			
			count++;			
			if(count % 2 == 1){		// Neu count la so le thi nhay qua "NO"			
				TextColor(233);				gotoxy(33,28); printf(" YES ");	// chu xanh nen vang			
				TextColor(252);				gotoxy(45,28); printf(" NO ");	// chu do nen trang(duoc chon)			
				gotoxy(46,28);			
			}else{				 	// Neu count la so chan thi nhay qua "YES"		
				TextColor(252);				gotoxy(33,28); printf(" YES ");				
				TextColor(233);				gotoxy(45,28); printf(" NO ");				
				gotoxy(34,28);			
			}		
		}		
		if(key == ENTER){			
			if(count == 0){		//neu count = 0 la chon ngay o "YES"		
				return 1;		// Thoat va luu file thanh cong	
			}else{								
				if(count % 2 == 1){					
					return 0;				
				}else{			// Neu count la so chan se nam ngay o "YES"		
					return 1;	// Thoat va luu file thanh cong			
				}			
			}		
		}		
		if(key == ESC){			
			TextColor(91);			gotoxy(24,26);	printf("                                   ");			
			gotoxy(24,27);	printf("                                   ");			
			gotoxy(24,28);	printf("                                   ");			
			gotoxy(24,29);	printf("                                   ");			
			gotoxy(24,30);	printf("                                   ");			
			return -1;		
		}	
	}
}

// THONG BAO THOAT CHUONG TRINH
int ThongBao_Thoat(){
	int key,count = 0;TextColor(206);
	gotoxy(25,12);	printf("  Ban Co Chac Chan Muon Thoat!   ");	
	gotoxy(25,13);	printf("   ");	gotoxy(55,13);	printf("   ");	
	gotoxy(25,14);	printf("   ");	gotoxy(55,14);	printf("   ");	
	gotoxy(25,15);	printf("   ");	gotoxy(55,15);	printf("   ");	
	gotoxy(25,16);	printf("                                 ");	
	TextColor(238);	gotoxy(28,13); printf("                           ");	
	gotoxy(28,14); printf("                           ");	
	gotoxy(28,15); printf("                           ");
	TextColor(252);	gotoxy(33,14);	printf(" YES ");	
	TextColor(233);	gotoxy(45,14);	printf(" NO ");	
	gotoxy(34,14);	
	while(1){		
		key = GetKey();		
		if(key == LEFT || key == RIGHT)	{
			count++;			
			if(count % 2 == 1){					
				TextColor(233);				
				gotoxy(33,14); printf(" YES ");				
				TextColor(252);				
				gotoxy(45,14); printf(" NO ");				
				gotoxy(46,14);			
			}else{				
				TextColor(252);			gotoxy(33,14); printf(" YES ");				
				TextColor(233);			gotoxy(45,14); printf(" NO ");				
				gotoxy(34,14);			
			}		
		}		
		if(key == ENTER){			
			if(count == 0){				
				return 1;			
			}else{								
				if(count % 2 == 1){	
					return 0;
				}else{					
					return 1;				
				}			
			}		
		}		
		if(key == ESC){			
			return -1;		
		}	
	}
}
