// Initialization List.

class Student{
  public:
    int age;
    const int rollNumber;
    int &x; // Age Reference Variable/

    //Whenever const is used, we must use initialization list to initialize its value.
    Student(int r, int age):rollNumber(r), age(age), x(this->age){ // Syntax of Initialization List, no need to do this->age in initialization list as it identifies itself the correct variables.
    // Student(int r, int age){ 
      // rollNumber = r;  // this is not allowed as rollNumber is const and can not be re-initialized.
      // if we do not use initialization list, const variable is assigned to a garbage value. 
      // this->age = age;
    }

    void display(){
      cout<<"Age: "<<age<<" rollNumber: "<<rollNumber<<endl;
    }
};