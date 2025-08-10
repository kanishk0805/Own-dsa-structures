#include <iostream>
using namespace std;
class stack{
    int *data;
    int capacity;
    int index=0;
    public:
    stack(){
        capacity=5;
        data=new int[capacity];
    }
    void push(int a){
        if(index==capacity){
            int *newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
            delete []data;
            data=newdata;
        }
        data[index++]=a;
    }
    int pop(){
        if(index==0){
            cout<<"stack is empty";
            return -1;
        }
        return data[--index];
    }
    bool isempty(){
        return index==0;
    }
    int top(){
        return data[index-1];
    }

};
int main(){
    stack p;
    p.push(98);
    cout<<p.pop();
}