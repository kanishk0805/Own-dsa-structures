#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;
bool helper(int div5,int div3,vector<int> & v,int pos){
    if(pos==v.size()) return div5==div3;
    return helper(div5+v[pos],div3,v,pos+1) || helper(div5, div3+v[pos], v, pos+1);
}

bool splitArray(int *input, int size) {

     vector<int> v;
     int div5=0,div3=0;
     for(int i=0;i<size;++i){
         if(input[i]%5==0) div5+=input[i];
         else if(input[i]%3==0) div3+=input[i];
         else v.push_back(input[i]);
     }
    return helper(div5, div3, v, 0);

    
}
