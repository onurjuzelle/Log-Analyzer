#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Hashtable.h"
#include <ctime>
using namespace std;


int main(){
	clock_t begin = clock();
	Htable fileclass(1000);
	string line;
	ifstream filename("access_log.txt");
	getline(filename, line);
	while (filename){
		int count1 = 0;
		istringstream iss(line);
		while (iss){
			count1++;
			string word;
			iss >> word;
			if (count1 == 7){
				int ascii = 0;
				for (int a = 0; a < word.size(); a++){
					ascii = ascii + word[a];
				}

				fileclass.insert(word, ascii);
			}
	
		}
		getline(filename, line);
	}
	for (int i = 0; i < 1000; i++){
		if (fileclass.indexstatuslist[i] != 0){
			wordindex *temp;
			temp = fileclass.quicksort1(fileclass.data[i]);
			fileclass.indexstatuslist[i] = temp->countx;
			fileclass.htable[i] = temp->name;
		}
	}
	fileclass.print();
	cout << "Time : " << ((double)(clock() - begin)) / CLOCKS_PER_SEC << endl;
	filename.close();
	system("pause");
	return 0;

}


