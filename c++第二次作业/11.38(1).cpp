// Copyright [2019] <Copyright zhengxin>
#include <iostream>
#include <string>
#include <map>
#include <tr1/unordered_map>  
using namespace std;

int main() {
	tr1::unordered_map<string, size_t> word_count; //string��size_t�Ŀ�map 
    string word;
    while(cin >> word)
        ++word_count[word];        //��ȡword�ļ������������1 
    for(const auto &w : word_count)
    	cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;
    return 0;
} 

