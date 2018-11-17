#include <iostream>
#include <string>
using namespace std;
#include "BAC.h"

int main(){

string keys[26]={"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab"};
//Encryption
string str = GetStr();
int len = GetLen(str);
string encr[len];
for(int i = 0;i<len;i++){
    char ch = str[i];
    if(isupper(ch)){
        ch=tolower(ch);
    }
    if(ch>=97&&ch<=122){
        ch-=97;
        encr[i]=keys[ch];
    }else{cout<<"Characters only!\r\nTry again!";break;}
}
cout<<"\r\nYour encrypted message is:\r\n";
for(int i  = 0;i<len;i++){
    cout<<encr[i];
}

//Decryption
str = GetStr();
len = GetLen(str);
int rl_len=len/5;
char decr[rl_len]={0};
int c = 0;
for(int i = 0;i<len;i+=5){
    string s;
    for(int j = 0;j<5;j++){
        s+=str[i+j];
    }
    for(int z = 0;z<26;z++){
        if(s==keys[z]){
            decr[c]=(char)z+97;
            c++;
            break;
        }
    }
}
cout<<"\r\nYour encrypted message\r\n";
for(int i = 0;i<len/5;i++){
    cout<<decr[i];
}
return 0;
}
