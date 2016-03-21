#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool in_It(char s, string str){  //判断字符串str中是否含有字符s 
    for (int i = 0; i < str.size(); i++){
        if (s == str[i]){
            return true;
	    }
    }
    return false;
}

int main(){
    
    string address = "edaccdbcecead";   //访问序列 
    string inMem = "ade";     //常驻集 
    string workSet = "";     //工作集 
   
    for (int t = 3;t < 13; t++){ 
        workSet = "";   
        if (in_It(address[t], inMem)){ //如果当前时刻要访问的页在常驻集中 
            cout << t-2 << "时刻：" << address[t] << ' ' << "访问成功" << endl;
        }
        else {                         //如果当前时刻要访问的页不在常驻集中 
	        inMem += address[t];    //将其添加到常驻集 
            cout << t-2 << "时刻：" << address[t] << ' ' << "访问失败,将" << address[t] << "调入内存" << endl;
	    }

	    workSet += address[t];      //计算当前时刻工作集，大小为4 
	    workSet += address[t-1];
	    workSet += address[t-2];
	    workSet += address[t-3];
                
     //遍历常驻集中每个页，若该页不在工作集中，则将其从常驻集中取出 
        for (int j = 0; j < inMem.size(); j++){
            if (!(in_It(inMem[j], workSet))){
                cout << t-2 << "时刻：" << "从常驻集中取出" << inMem[j] << endl;
                inMem = inMem.erase(j,1);                     
	        } 	    
	    } 
    }
    system("pause");
    return 0;
}
