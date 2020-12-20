#include "Header.h"

void main()
{
	CList<int>t;
	t.addHead(10);
	t.addHead(50);
	t.addTail(15);
	t.addTail(20);
	t.show();
	t.sum();
	//t.DeleteFromHead();
	//cout << "Count = " << t.get_count() << endl;
	//t.push(3, 4);
	//t.show();
	//t.back(2);
	//t.show();
	//t.addTail(6);
	//t.show();
	//cout << "Search - " << t.search(15) << endl;
	//cout << "Search and change - " << t.search_and_change(500, 0) << endl;
	t.revers();
	t.show();
	system("pause");
}