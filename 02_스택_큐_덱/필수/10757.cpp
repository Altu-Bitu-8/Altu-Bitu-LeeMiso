#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string num1, num2;
    cin>>num1>>num2;
    int len1=num1.length();
    int len2=num2.length();

    if (len2>len1){
        swap(num1,num2);
        swap(len1,len2);
    }

    string s="";
    if(len1!=len2){
        for(int i=0;i<(len1-len2);i++){
            s+="0";
        }
    }
    num2=s+num2;

    string ans="";
    int carry=0;
    int x, y, num;
    for(int i=len1-1;i>=0;i--){
        x=num1[i]-'0';
        y=num2[i]-'0';
        num=x+y;
        if(carry==1){
            num++;
            carry=0;
        }
        if (num>9){
            carry=1;
        }
        ans+=num%10+'0';
    }

    if (carry==1){
        ans+="1";
    }
    
    for (int i=ans.length()-1;i>=0;i--){
        cout<<ans[i];
    }
}