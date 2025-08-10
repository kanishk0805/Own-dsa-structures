#include <vector>
using namespace std;
class proirityqueue{
    vector<int> pq;
    int size;
    public:
    proirityqueue(){
        size=0;
    }
    bool isempty(){
        return size==0;
    }
    int getsize(){
        return size;
    }
    int getmin(){
        if(size==0){
            return -1;
        }
        return pq[0];
    }
    void insert(int x){
        pq.push_back(x);
        if(size==0){
            size++;
            return;
        }
        int pos=(size-1)/2;
        int cp=size;
        size++;
        while(pq[pos]>x && cp!=0){
            swap(pq[pos],pq[cp]);
            cp=pos;
            pos=(pos-1)/2;
        }
    }
    void printwhole(){
        for(int i=0;i<size;i++){
            cout<<pq[i]<<" ";
        }
    }
    void removemin(){
        if(size==0 || size==1){
            size=0;
            return;
        }
        size--;
        swap(pq[0],pq[size]);
        int cp=0,pos1=2*cp+1,pos2=2*cp+2;;
        while(pos2<=size){
            if(pq[cp]>pq[pos1] || pq[cp]>pq[pos2]){
                if(pos2<size && pq[pos2]<pq[pos1]){
                    swap(pq[cp],pq[pos2]);
                    cp=pos2;
                }else{
                    swap(pq[cp],pq[pos1]);
                    cp=pos1;
                }
            }else{
                break;
            }
            pos1=2*cp+1,pos2=2*cp+2;
        }
    }

};