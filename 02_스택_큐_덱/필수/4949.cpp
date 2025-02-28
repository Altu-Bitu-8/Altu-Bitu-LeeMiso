#include <iostream>
#include <stack>
#include <string>

int main(){
    while(true) {
        std::string input="";
        std::stack<char> s;
        std::getline(std::cin, input);
        bool result = true;

        if(input.length()==1&&input[0]=='.'){
            break;
        }

        for(int i=0;i<input.length();i++){
            if(input[i]=='['||input[i]=='('){
                s.push(input[i]);
            }

            if(input[i]==']'){
                if(!s.empty()&&s.top()=='['){
                    s.pop();
                }
                else{
                    result=false;
                    break;
                }
            }
            else if(input[i]==')'){
                if(!s.empty()&&s.top()=='('){
                    s.pop();
                }
                else{
                    result=false;
                    break;
                }
            }
        }

        if(s.empty()&&result){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }        
    }
    return 0;
}