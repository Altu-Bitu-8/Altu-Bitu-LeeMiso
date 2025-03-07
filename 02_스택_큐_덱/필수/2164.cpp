#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
int n,k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    queue<int> q;

    for(int i=1;i<=n;i++){
        q.push(i);
    }
    
    while(q.size()!=1){
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout<<q.front();

    return 0;
}