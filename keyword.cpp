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
	"case", 0, //2
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
	"switch", 0,//25
	"typedef", 0,
	"union", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
};
// case 2  switch 25
int obj[100];
int KeySearch(string str) {//�ǵ�Ҫ��һ���۰���ң�����ֵ�±� 
	int index = -1;
	for (int i = 0; i < 32; i++) {
		if(keytab[i].word == str){
			keytab[i].count++;
			index = i;
			break;
		}
	}
	return index;
}
void CutWord(string str) {
	string newword;
	int i = 0,index;
	while (!isalpha(str[i])) {//ʹword��Ӣ�Ŀ�ͷ 
		i++;
	}
	for ( ; i < str.size(); i++) {
		if (!isalpha(str[i]) && str[i]!='_' && !isalnum(str[i])){//������ĸ�����֡��»���ʱ
			if (newword.size()>=2){//word���ȴ��2��ԭ��ؼ������Ϊdo������2 
				//cout<<"__________ "<<newword<<" __________"<<endl;
				index = KeySearch(newword);
				if (keytab[25].count > 0 && index == 2) {//����switchʱ����case�ҵ�����1 
					obj[keytab[25].count-1]++;
				}
			} 
			newword = "";
		}
		else{
			//cout<<"~"<<str[i]<<"~"<<endl;
			newword += str[i];
		}
	}
	if (newword != "") {//��βʱע���ַ����Ƿ�Ϊ�� 
		if (newword.size()>=2){
			//cout<<"__________  "<<newword<<"  _______"<<endl;
			index = KeySearch(newword);
			if (keytab[25].count > 0 && index == 2){
				obj[keytab[25].count-1]++;
	    	}
		}
	}
}
void SearchFile(const char *file, int level) {
	ifstream fin(file); //infile.open(file, ios::in);
	if (!fin.is_open()) {
		cout << "error!" << endl;
	} else {
		string str;
		while (fin >> str) { //�Կո�س����ֶ�ȡ
			//cout << str << endl; // KeySearch(str) no!
			CutWord(str); //��ϸ�µ��и��С�� 
		} 
		fin.close();
	}
}
void Print() {
	int sum = 0;
	for (int i = 0; i < 32; i++){ //ͳ������ 
		if(keytab[i].count != 0){
			if (i != 2) {
				cout << keytab[i].word << " num: " << keytab[i].count << endl;
			} else {
				cout << keytab[i].word << " num: ";
				for(int j=0; j < keytab[25].count; j++){
					cout << obj[j] << " ";
				}
				cout << endl;
			} 
		}
		sum += keytab[i].count;
	}
	cout << "total num��" << sum << endl;
	
}

int main() {
	string file_path;
	int level=1;
	cout<<"��ӭ��������ؼ�����ȡ"<<endl<<"��ɵȼ���2"<<endl<<"(ע���ȼ��ӵ͵���Ϊ1-4)"<<endl;
	cout<<"�������ļ�����"<<endl;
	cin>>file_path;
	//cin>>level;
	SearchFile(file_path.c_str(), level); //file_path.c_str(): string to const char*
	Print();
	return 0;
}
