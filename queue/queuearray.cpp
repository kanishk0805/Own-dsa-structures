template <typename T>
class queuearray{
    T *data;
    int fi;
    int ni;
    int size;
    int capacity;
    public:
    queuearray(int s){
        data=new T[s];
        size=0,fi=-1,ni=0,capacity=s;
    }
    bool isEmpty(){
        return size==0;
    }
    int GetSize(){
        return size;
    }
    T front(){
        if(size==0){
            cout<<"lol, it is empty";
            return 0;
        }
        return data[fi];
    }
    T dequeue(){
        if(size==0){
            cout<<"isempty";
            return 0;
        }
        T val=data[fi];
        fi=(fi+1)%capacity;
         size--;
        if(size==0){
            fi=-1,ni=0;
        }
        return val;
    }
    void enqueue(T val){
        if(size==capacity){
            T *ndata=new T[2*capacity];
            for(int i=0;i<capacity;i++){
                ndata[i]=data[(fi+i)%capacity];
            } 
            delete [] data;
            data=ndata;
           
            fi=0,ni=capacity;    
             capacity*=2;  
        }
        data[ni]=val;
        ni=(ni+1)%capacity;
        size++;
        if(fi=-1){
            fi=0;
        }
    }

};

