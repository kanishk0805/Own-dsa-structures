#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> v){
    cout<<"size if vector is"<<v.size()<<endl;
    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<endl;
    }
}
int main(){
    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    print(v);
}