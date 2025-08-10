#include <iostream>
using namespace std;

class student {
  public:
    int rollNumber;
    static int totalst;
    //student(){
     // cout<<"here"<<endl;
    //}
    student(int rollNumber) : rollNumber(rollNumber){ //initailising list
      this->rollNumber=rollNumber;
      totalst++;
    }
    void display(){
      cout<<rollNumber<<endl;
    }
    //copy constructor
    student(student &s){
      rollNumber=s.rollNumber;
      student::totalst++;
    }
    ~student(){
      cout<<"deleted"<<endl;
    }
};
int student :: totalst=0;

int main() {
    student s(23);
    cout << s.rollNumber<<endl;
    student s1(45);
    cout<<s1.rollNumber<<endl;
    s1.display();
    student s2(s1);
    s2=s;
    student *s3=new student(s1);
    cout<<student:: totalst<<endl;

    delete s3; //explicit deleting;

}

