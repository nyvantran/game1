#include <iostream>
#include<thread>
#include"Functiongraphics.h"
int main()
{
	initwindow(1500, 800, "game1");
	Snake ran;
	Moi moi;
	char diem[100]{}, nhap;
	int x = 2;
	bool chay = 1, m = 0;
	settextstyle(3, 0, 6);
	moi.HinhAnh();
	moi.checkMoi();
	thread nhanh(chayRan, ref(ran), ref(x), ref(m), ref(chay));
	thread nhanh1(chayMoi, ref(moi), ref(chay),ref(m));
	dieuKhienRan(x,chay);
	nhanh.join();
	nhanh1.join();
	_itoa_s(ran.Diem(), diem, 100, 10);
	strcat_s(diem, 100, " diem");
	outtextxy(getmaxx() / 2 - textwidth(diem) / 2, getmaxy() / 2 - textheight(diem) / 2, diem);
	settextstyle(3, 0, 1);
	outtextxy(getmaxx() / 2 - textwidth(diem) / 2, getmaxy() / 2 + 50, const_cast<char*>("nhap enter de ket thuc"));
	while (1) {
		nhap = getch();
		if ((int)nhap == 13)break;
	}
	
	closegraph();
}    
