// Copyright [2019] <Copyright zhengxin>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <tr1/unordered_map>
using namespace std;

//����ת��ӳ�� 
tr1::unordered_map<string, string> buildMap(ifstream &map_file)
{
    tr1::unordered_map<string, string> trans_map; //����ת������
    string key; //Ҫת���ĵ���
    string value; //�滻�������
    //��ȡ��һ�����ʴ���key�У�����ʣ�����ݴ���value
    while (map_file >> key && getline(map_file, value)) 
        if(value.size() > 1) //����Ƿ���ת������
            trans_map[key] = value.substr(1); //����ǰ���ո�
        else
            throw runtime_error("no rule for " + key);
    return trans_map; 
 } 

//����ת���ı�
const string & transform(const string &s, const tr1::unordered_map<string,string> &m)
{
    //ʵ�ʵ�ת���������˲����ǳ���ĺ���
    auto map_it = m.find(s);
    //���������ת������map��
    if (map_it != m.end()) //cend��Ϊend 
        return map_it -> second; //ʹ���滻���
    else
        return s; //���򷵻�ԭstring 
} 


/*����ת������*/
void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file); //����ת������
    string text;
    while (getline(input, text)) 
    {
        istringstream stream(text);  //��ȡÿ������
        string word;
        bool firstword = true;      //�����Ƿ��ӡ�ո� 
        while (stream >> word){
            if (firstword)
                firstword = false;
            else
                cout << " ";      //�ڵ��ʼ��ӡһ���ո�
            //transform �������ĵ�һ������������ת��֮�����ʽ
            cout << transform(word, trans_map); //��ӡ��� 
        } 
        cout << endl;  //���һ�е�ת�� 
     } 
}

int main() {
    ifstream file1("map_file.txt"); //ת���Ĺ��� 
    ifstream file2("data_input.txt"); //������ļ� 
    word_transform(file1, file2);
    return 0;
}
