#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> v){
    cout<<"size if vector is "<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<endl;
    }
}
int main(){
    vector<int> v;
    for(int i=0;i<v.size();i++){
        v.push_back(i);
    }
    print(v);
}