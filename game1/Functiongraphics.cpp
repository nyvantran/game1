#include "Functiongraphics.h"

Snake::Snake()
{
	//initwindow(10, 10, "1");
	this->anh = malloc(imagesize(0, 0, 14, 14));
	setfillstyle(1, 7);
	bar(0, 0, 14, 14);
	getimage(0, 0, 14, 14, this->anh);
	putimage(0, 0, this->anh, 1);
	//closegraph();
	/*this->xy = new NodeToaDo;
	this->xy->inf.datToaDo(8, 8);*/
	ToaDo tam;
	for (int i = 10; i < 50; i += 15) {
		tam.datToaDo(8, i);
		InsertFistToaDo(this->xy, tam);
	}
}

Snake::~Snake()
{
	free(this->anh);
}

int Snake::Diem() const
{
	int diem = 0;
	for (PTRToaDo p = this->xy; p != NULL; p = p->next) {
		diem++;
	}
	return diem;
}

bool Snake::checkSnake() const
{
	for (PTRToaDo p = this->xy->next; p != NULL; p = p->next) {
		if (this->xy->inf.ssToaDo(p->inf) == 1 || this->xy->inf.checkToaDo() == 0) {
			return 1;
		}
	}
	return 0;
}

void Snake::CapnhapToaDo(int& x, bool& m)
{
	ToaDo t1, t2, t3;
	t1 = this->xy->inf;
	if (m == 0) {
		switch (x)
		{
		case 0: {
			this->xy->inf.y -= 15;
			break;
		}
		case 1: {
			this->xy->inf.x += 15;
			break;
		}
		case 2: {
			this->xy->inf.y += 15;
			break;
		}
		case 3: {
			this->xy->inf.x -= 15;
			break;
		}
		}
		for (PTRToaDo p = this->xy->next; p != NULL; p = p->next) {
			t2 = p->inf;
			p->inf = t1;
			t1 = t2;
		}
	}
	else {
		t3 = this->xy->inf;
		switch (x)
		{
		case 0: {
			t3.y -= 15;
			break;
		}
		case 1: {
			t3.x += 15;
			break;
		}
		case 2: {
			t3.y += 15;
			break;
		}
		case 3: {
			t3.x -= 15;
			break;
		}
		}
		InsertFistToaDo(this->xy, t3);
		m = 0;
	}
	if (this->checkSnake() == 1) {
		x = 5;
	}
}

void Snake::CapNhapHinhAnh()
{
	for (PTRToaDo p = this->xy; p != NULL; p = p->next) {
		this->HinhAnh(p->inf);
	}
}

void Snake::HinhAnh(ToaDo n)
{
	int x = n.x - 7, y = n.y - 7;
	//if (n.x < 7)x = 0;
	//if (n.y < 7)y = 0;
	putimage(x, y, this->anh, 1);
}
bool ToaDo::ssToaDo(ToaDo x) const
{
	if (this->x == x.x && this->y == x.y) {
		return 1;
	}
	else
	{
		return 0;
	}	
}
bool ToaDo::checkToaDo() const
{
	if (this->x < 0 || this->y < 0 || this->x>getmaxx() || this->y>getmaxy()) {
		return 0;
	}
	else return 1;	
}
///////////
void ToaDo::datToaDo(int x, int y)
{
	this->x = x;
	this->y = y;
}

void InsertFistToaDo(PTRToaDo& fist, ToaDo x)
{
	PTRToaDo p = new NodeToaDo;
	p->inf = x;
	p->next = fist;
	fist = p;
}

void chayRan(Snake& n, int& x, bool& m, bool& chay)
{
	int dem = 0;
	while (x != 5) {
		n.CapNhapHinhAnh();
		Sleep(150 - dem);
		n.CapNhapHinhAnh();
		if (m == 1) {
			if (dem < 130)dem += 5;
			n.CapnhapToaDo(x, m);
		}
		else {
			n.CapnhapToaDo(x, m);
		}
	}
	chay = 0;
}

void dieuKhienRan(int& x, bool& chay)
{
	char nhap = 0;
	while (nhap != 27 && chay == 1) {
		if (kbhit()) {
			if ((int)(nhap = getch()) == 0) {
				nhap = getch();
				switch ((int)nhap)
				{
				case 72: {
					if (x != 2) {
						x = 0;
					}
					break;
				}
				case 77: {
					if (x != 3) {
						x = 1;
					}
					break;
				}
				case 80: {
					if (x != 0) {
						x = 2;
					}
					break;
				}
				case 75: {
					if (x != 1) {
						x = 3;
					}
					break;
				}
				default:
					break;
				}
			}			
		}
	}
	x = 5;
}

void chayMoi(Moi& moi, bool& chay, bool& m)
{
	moi.CapNhapHinhAnh(chay, m);
}

Moi::Moi()
{
	srand(time(0));
	setfillstyle(1, 6);
	bar(0, 0, 14, 14);
	this->anh = malloc(imagesize(0, 0, 14, 14));
	getimage(0, 0, 14, 14, this->anh);
	putimage(0, 0, this->anh, 1);
	this->xy.datToaDo(rand() % (getmaxx() - 15) + 8, rand() % (getmaxy() - 15) + 8);
}

Moi::~Moi()
{
	free(this->anh);
}

bool Moi::checkMoi() const
{
	ToaDo n;
	n.x = this->xy.x-7;
	n.y = this->xy.y-7;
	int dem = 0;
	for (int i = n.x; i < n.x + 14; i++) {
		for (int j = n.y; j < n.y + 14; j++) {
			if (getpixel(i, j) != 6) {
				return 1;
			}
		}
	}
	return 0;
}

void Moi::CapNhapHinhAnh(bool& chay, bool& m)
{
	bool dk; m = 0;
	while (chay != 0) {
		dk = this->checkMoi();
		if (dk == 1) {
			m = 1;
			this->HinhAnh();
			this->xy.datToaDo(rand() % (getmaxx() - 15) + 8, rand() % (getmaxy() - 15) + 8);
			this->HinhAnh();
		}
	}
}

void Moi::HinhAnh()
{
	int x = this->xy.x - 7, y = this->xy.y - 7;
	if (this->xy.x < 7)x = 0;
	if (this->xy.y < 7)y = 0;
	putimage(x, y, this->anh, 1);
}
