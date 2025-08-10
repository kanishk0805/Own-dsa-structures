#include <iostream>
using namespace std;
#include<queue>
void printq(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<' ';
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> q;
    q.push(90);
    q.push(90);
    q.push(90);
    q.push(90);
    printq(q);
    printq(q);
}