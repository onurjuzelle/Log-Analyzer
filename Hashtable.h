#include <iostream>
#include <string>
#include <cassert>
using namespace std;
struct wordindex{
	string name;
	int countx;
	wordindex* link=NULL;
};

class Htable:public wordindex{
private:
	int HTsize;
public:
	wordindex** data;
	string *htable;
	int length = 0;
	void print();
	int *indexstatuslist;
	Htable(int size);
	void insert(string word, int ascii);
	wordindex* quicksort1(wordindex*);
	void printlink(wordindex*);
	void quicksort2(int left, int right);

};