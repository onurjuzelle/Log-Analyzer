#include "Hashtable.h"
#include <cassert>

Htable::Htable(int size){
		assert(size > 0);

		htable = new string[size];
		indexstatuslist = new int[size];
		data = new wordindex*[size];
		for (int i = 0; i < size; i++)
		{
			indexstatuslist[i] = 0;
		}
		HTsize = size;
	}

void Htable::insert(string word, int ascii){
	int key = ascii % 1000;
	if (indexstatuslist[key] == 0)
	{
		struct wordindex* head;
		head = new wordindex;
		head->name = word;
		head->countx = 1;
		data[key] = head;
		indexstatuslist[key] = 1;
	}
	else
	{
		struct wordindex* temp = new wordindex;
		struct wordindex* temp2 = new wordindex;
		struct wordindex* temp3 = new wordindex;
		temp = data[key];
		int there = 0;
		while (temp!=NULL)
		{
			if (temp->name == word)
			{
				there = 1;
				temp->countx++;
				break;
			}
			temp2 = temp;
			temp = temp->link;
		}
		if (there == 0){
			temp3->name = word;
			temp3->countx = 1;
			temp2->link=temp3;
		}

	}
}

void Htable::print(){

	quicksort2(0, HTsize-1);

	cout << "Top 10 word:" << endl;

	for (int u=1; u <=10; u++){

		cout <<u<<".th word: "<<  htable[HTsize-u]<<" used  " <<indexstatuslist[HTsize-u] << " times." << endl;
	}
}
wordindex* Htable::quicksort1(wordindex *A){
	int max = 0;
	wordindex *b = new wordindex;
	while (A!= NULL)
	{
		if (A->countx > max){
			max = A->countx;
		}
		if (max == A->countx){
			b = A;

		}
		A = A->link;
	}
	return b;
}


void Htable::quicksort2(int left, int right){

	int i = left, j = right;
	int tmp;
	string tmp1;
	int pivot = indexstatuslist[(left + right) / 2];


	while (i <= j) {
		while (indexstatuslist[i] < pivot)
			i++;
		while (indexstatuslist[j] > pivot)
			j--;
		if (i <= j) {
			tmp1 = htable[i];
			tmp = indexstatuslist[i];
			htable[i] = htable[j];
			indexstatuslist[i] = indexstatuslist[j];
			htable[j] = tmp1;
			indexstatuslist[j] = tmp;
			i++;
			j--;
		}
	};

	if (left < j)
		quicksort2(left, j);
	if (i < right)
		quicksort2(i, right);

}


void Htable::printlink(wordindex *a){

	while (a!=NULL)
	{
		cout << a->name << a->countx << endl;
		a = a->link;
	}


}