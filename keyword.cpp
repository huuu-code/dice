#include<iostream>
#include<string>
#include<cstdio>
#include<stack>
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
int casenum[100] = {0};//��¼ÿ��case�� 
stack<int>s;
int ie_count = 0;//��¼if-else 
int iee_count = 0;//��¼if-elseif-else 
void Print(int level);
//�ļ���ȡ�ַ��Լ����� 
void FileSearch(const char *file, int level);
//�ؼ����ַ���ƥ��  
int KeySearch(string str); 
int main(){
	string file_path;
	int level;
	cout << "��ӭ����C���Դ���ؼ���ͳ��" << endl;
	cout << "�������ļ�������ɵȼ�:" << endl;
	cin >> file_path >> level;
	FileSearch(file_path.c_str(), level);
	Print(level);
	return 0;
}
void Print(int level) {
	int sum = 0;
	cout << "�ؼ���ͳ�����飺" << endl; 
	for (int i = 0; i < 32; i++) {
		if(keytab[i].count != 0){
				cout << keytab[i].word << " num: " << keytab[i].count << endl;
		}
		sum += keytab[i].count;
	}
	cout << "------------------------------" << endl;
	cout << "total num: " << sum << endl;
	if (level >= 2) {
		  cout << "switch num: " << keytab[25].count << endl << "case num: ";
		  if (keytab[25].count == 0) {
		  	cout << "0" << endl;
			}
			else {
				for (int i = 0; i < keytab[25].count; i++)
				cout << casenum[i] << " " ;
				cout << endl;
			}
			if (level >= 3) {
				cout <<"if-else num: ";
				cout << ie_count << endl;
			}
			if (level >= 4) {
				cout << "if-elseif-else num: ";
				cout << iee_count << endl;
			}
	}
}
int KeySearch(string str) {
	int index = -1;
	for (int i = 0; i < 32; i++) {
		if (keytab[i].word == str) {
			keytab[i].count++;
			index = i;
			break;
		}
	}
	return index;
}
void FileSearch(const char *file, int level) {
	int index;
	FILE *fin;
	fin = fopen(file, "r"); 
	if (fin == NULL) {
		cout << "error!" << endl;
	}
  char c;
  string str;
  c = fgetc(fin);
	while (c != EOF) { //�Ե����ַ���ȡ,�����Կո�س�
	  if (c == '#') { //���� ͷ�ļ�,�궨�壬��� 
	  	while (c != '>') {
	  		c = fgetc(fin);
	  		if (c == '\n') break;
			}
		}
		else if (c == '\'' ) {//���� �����ţ����
			c = fgetc(fin);
			while (c != '\'') {
				c = fgetc(fin);
			}
			c = fgetc(fin); 
		}
		else if (c == '"') {//����˫���ţ���� 
		  c = fgetc(fin);
			while (c != '"') {
				c = fgetc(fin);
			}
			c = fgetc(fin);
		}
		else if (isalpha(c) || c == '_' || isalnum(c)) {//������,��������ֿ�ͷ 
			string str;
			while(isalpha(c) && c == '_' || isalnum(c)){
				str += c;
				c = fgetc(fin);
			}
			index = KeySearch(str);
			if (level >= 2) { //���ס��θߺ��ռ�Ҫ�� 
				if (keytab[25].count != 0) {
					if (index == 2) casenum[keytab[25].count-1]++;
				}
				if (index == 15) {//ƥ�䵽if-1
					s.push(1);
				}
				if (index == 9) {//׼�����ƥ�䵽�ĸ� else-2;else if-3
				  int flag = 0;
				  while (c == ' ' || c == '\n' || c == '\t') c = fgetc(fin);
					if (c == 'i') {
						if ((c = fgetc(fin)) == 'f') { //ƥ�䵽else if
							if(!s.empty() && (s.top() != 3)) s.push(3);
							flag = 1;
							keytab[15].count++;
						}
					}
					if (flag == 0) { //ƥ�䵽else 
						if (!s.empty() && (s.top() == 1)) {
							ie_count++;
							s.pop();
						}
						else if (!s.empty() && (s.top() == 3)) {
							s.pop();
							if (!s.empty() && (s.top() == 1)) {
								iee_count++;
								s.pop();
							}
						}
					}
				}
			}
		}
		else if (c == '/') { //���� ע����//��/* */ 
			c = fgetc(fin);
			if (c == '/') {
				while (c != '\n')
				  c = fgetc(fin);
			}
			if (c == '*') {
				while (c != '/')
				  c = fgetc(fin);
			}
		}
		else{ //����  �ո񡢻س��ȵ�
			c = fgetc(fin);
		}
	}
	fclose(fin);
}
