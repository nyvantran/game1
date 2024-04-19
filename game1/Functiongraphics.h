#pragma once
#include<iostream>
#include<cstdlib>
#include"graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;
struct ToaDo
{
	int x = 0;
	int y = 0;
	bool ssToaDo(ToaDo) const;
	bool checkToaDo() const;
	void datToaDo(int x, int y);
};
struct NodeToaDo
{
	ToaDo inf;
	NodeToaDo* next = NULL;
};
typedef NodeToaDo* PTRToaDo;
void InsertFistToaDo(PTRToaDo& fist, ToaDo x);
void deleteFistToaDo(PTRToaDo& fist);
/////////////////////////////////
class Snake
{
private:
	PTRToaDo xy;
	void* anh;
public:
	Snake();
	~Snake();
	int Diem() const;
	bool checkSnake() const;
	void CapnhapToaDo(int& x, bool& m);
	void CapNhapHinhAnh();
	void HinhAnh(ToaDo n);
};
/////
void chayRan(Snake& n, int& x, bool& m, bool& chay);
void dieuKhienRan(int& x, bool&);
////
class Moi
{
public:
	Moi();
	~Moi();
	bool checkMoi() const;
	void CapNhapHinhAnh(bool& chay, bool& m);
	void HinhAnh();
private:
	ToaDo xy;
	void* anh;
};
////
void chayMoi(Moi& moi, bool& chay, bool& m);
