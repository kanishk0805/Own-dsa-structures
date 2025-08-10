#include <iostream>
#include "classmain.cpp"
int main(){
	proirityqueue pqt;
	pqt.insert(1);
	pqt.insert(2);
	pqt.insert(3);
	pqt.insert(4);
	pqt.insert(5);
	pqt.insert(6);
	pqt.insert(7);
	pqt.insert(8);
	pqt.insert(9);
	pqt.insert(10);
	pqt.printwhole();
	cout<<endl;
	pqt.removemin();
	pqt.printwhole();
}