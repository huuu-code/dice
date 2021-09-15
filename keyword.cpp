#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct key {
	string word;
	int count;
} keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"do", 0,
	"double", 0,
	"else", 0,
	"enum", 0,
	"extern", 0,
	"float", 0,
	"for", 0,
	"goto", 0,
	"if", 0,
	"int", 0,
	"long", 0,
	"register", 0,
	"return", 0,
	"short", 0,
	"signed", 0,
	"sizeof", 0,
	"static", 0,
	"struct", 0,
	"switch", 0,
	"typedef", 0,
	"union", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};

void KeySearch(string str) {//�ǵ�Ҫ��һ���۰���� 
	int n;
	for (int i = 0; i < 32; i++) {
		if(keytab[i].word == str){
			keytab[i].count++;
		}
	}
}
void CutWord(string str) {
	string newword;
	int i=0;
	while (!isalpha(str[i])) {
		i++;
	}
	for ( ; i < str.size(); i++) {
		if (!isalpha(str[i]) && str[i]!='_' && !isalnum(str[i])){//������ĸ�����֡��»���ʱ
			if (newword.size()>=2){
				cout<<"__________  "<<newword<<"  _______"<<endl;
				KeySearch(newword);
			} 
			newword = "";
		}
		else{
			cout<<" ~"<<str[i]<<"~ "<<endl;
			newword += str[i];
		}
	}
	if (newword != "") {
		if (newword.size()>=2){
			cout<<"__________  "<<newword<<"  _______"<<endl;
			KeySearch(newword);
		}
	}
}
void SearchFile(const char *file, int level) {
	ifstream infile;
	infile.open(file, ios::in);
	if (!infile.is_open()) {
		cout << "error! TAT" << endl;
	} else {
		string str;
		while (infile >> str) {
			cout << str << endl;
			CutWord(str);
		}//�Կո�س����ֶ�ȡ 
		infile.close();
	}
}

void Print() {
	int sum = 0;
	for (int i = 0; i < 32; i++){
		if(keytab[i].count != 0)
		cout << keytab[i].word << " num: " << keytab[i].count << endl;
		sum += keytab[i].count;
	}
	cout << "total num��" << sum << endl;
}

int main() {
	string file_path;
	int level;
	cout<<"��ӭ��������ؼ�����ȡ QAQ"<<endl<<"�������ļ�����"<<endl;
	cin>>file_path;
	cout<<"��������ɵȼ���"<<endl<<"(ע���ȼ��ӵ͵���Ϊ1-4)"<<endl; 
	cin>>level;
	SearchFile(file_path.c_str(), level); //c_str(): string to const char*
	Print();
	return 0;
}
