#include<iostream>
using namespace std;
class Deque {
    int arr[10];
    int size;
    int fixedsize;
    int fr;
    int end;
    public:
    Deque(int i){
        fixedsize=10;
        size=0,fr=0,end=0;
    }
    void insertFront(int a){
        if(size==10){
            cout<<-1<<endl;
            return ;
        }
        size++;
        arr[end]=a;
        end++;
        if(end==10){
            end=0;
        }
        cout<<"insertfront: "<<arr[end-1]<<" end: "<<end<<endl;
    }
    void insertRear(int a){
       if(size==fixedsize){
           cout<<-1<<endl;
            return ;
        }
        size++;
        if(fr==0){
            fr=9;
        }else{
            fr--;
        }
        arr[fr]=a;
        cout<<"insertrear: "<<arr[fr]<<" fr:  "<<fr<<endl;
        return;
    }
    void deleteRear(){
        if(size==0){
            cout<<-1<<endl;
            return;
        }
        size--;
        if(end==0){
            end=9;
            return;
        }
        end--;
    }
    void deleteFront(){
        if(size==0){
            cout<<-1<<endl;
            return;
        }
        size--;
        if(fr==9){
            fr=0;
            return;
        }
        fr++;
    }
    int getFront(){
        if(size==0){
            return -1;
        }
        return arr[fr];
    }
    int getRear(){
        if(size==0){
            return -1;
        }
        if(end==0){
            return arr[9];
        }
        return arr[end-1];
    }
};


int main()
{
    //cout<<9;
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}
