// Sample Class to understand the syntax of creating the class
#include<iostream>
using namespace std;

// By default the access modifiers are private.
class Student{
  public: // everything(members and methods) below this label is public and can be used anywhere.
    int rollNo;

  private: // everything(members and methods) below this label is private and can be used anywhere.
    int age;

  public:

    //Default Constructor is vanished as soon as we create our own constructor.
    Student(){
      cout<<"Constructor Called"<<endl;
    }

    // Paramterized Constructors.
    Student(int r){
      cout<<"Parameterized Constructor Called"<<endl;
      rollNo = r;
    }

    Student(int age, int r){
      // cout<<"Parameterized Constructor 2 Called"<<endl;
      rollNo = r;
      // cout<<"THIS is pointing to address = " << this <<endl; // THIS points to the address of current object.
      this -> age = age; // 
    }

    void display(){
      // std::cout<<age<<" "<<rollNo<<std::endl; // std used if we are not using namespace std;
      cout<<age<<" "<<rollNo<<endl;
    }

    // GETTER
    int getAge(){
      return age;
    }

    // SETTER
    // void setAge(int a){
    //   age = a;
    // }

    // void setAge(int age, int password){
    void setAge(int age){
      // if(a < 0 || password != 123) return;
      this -> age = age;
    }


    // DESTRUCTOR
    ~Student(){
      cout<<"Destructor Called.. "<<endl;
    }


};