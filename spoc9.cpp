#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool in_It(char s, string str){  //�ж��ַ���str���Ƿ����ַ�s 
    for (int i = 0; i < str.size(); i++){
        if (s == str[i]){
            return true;
	    }
    }
    return false;
}

int main(){
    
    string address = "edaccdbcecead";   //�������� 
    string inMem = "ade";     //��פ�� 
    string workSet = "";     //������ 
   
    for (int t = 3;t < 13; t++){ 
        workSet = "";   
        if (in_It(address[t], inMem)){ //�����ǰʱ��Ҫ���ʵ�ҳ�ڳ�פ���� 
            cout << t-2 << "ʱ�̣�" << address[t] << ' ' << "���ʳɹ�" << endl;
        }
        else {                         //�����ǰʱ��Ҫ���ʵ�ҳ���ڳ�פ���� 
	        inMem += address[t];    //������ӵ���פ�� 
            cout << t-2 << "ʱ�̣�" << address[t] << ' ' << "����ʧ��,��" << address[t] << "�����ڴ�" << endl;
	    }

	    workSet += address[t];      //���㵱ǰʱ�̹���������СΪ4 
	    workSet += address[t-1];
	    workSet += address[t-2];
	    workSet += address[t-3];
                
     //������פ����ÿ��ҳ������ҳ���ڹ������У�����ӳ�פ����ȡ�� 
        for (int j = 0; j < inMem.size(); j++){
            if (!(in_It(inMem[j], workSet))){
                cout << t-2 << "ʱ�̣�" << "�ӳ�פ����ȡ��" << inMem[j] << endl;
                inMem = inMem.erase(j,1);                     
	        } 	    
	    } 
    }
    system("pause");
    return 0;
}
