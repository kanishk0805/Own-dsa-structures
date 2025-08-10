#include <iostream>
using namespace std;
template <typename T,typename V> 

class Pair{
    T x;
    V y;
    public:
    void valx(T x){
        this->x=x;
    }
    void valy(V y){
        this->y=y;
    }
    T getx(){
       return x;
    }
    V gety(){
        return y;
    }
};
int main(){
    Pair < Pair<int,int>, int> z;
    Pair<int,int> y;
    z.valx(y);
    y.valx(90);
    y.valy(87);

    z.valy(10);
    cout<<z.getx().getx()<<"  "<<z.gety()<<endl;
    z.valx(y);
    cout<<z.getx().getx()<<"  "<<z.gety()<<endl;
}
