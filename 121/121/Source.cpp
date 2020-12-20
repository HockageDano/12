#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

struct Elem
{
	Elem* link1,
		* link2;
	int info;
};

void main() {
	Elem* p;

	p = new Elem; //1
	p->info = 1;//2
	p->link1 = new Elem;//3
	p->link1->info = 2;//4
	p->link1->link2 = NULL;//5
	p->link1->link1 = NULL;//6
	p->link1->link1->info = 3;//7
	p->link1->link1->link2->link2->info = 4;//8
	p->link1->link1->link2->link2->link1;//9
	delete p->link1; //10
	delete p->link1->link1;//11
	delete p->link1; //12
	delete p;//14

}