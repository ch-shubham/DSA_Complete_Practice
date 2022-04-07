class Student{

  int age;

  public:
  char *name;
    Student(int age, char* name){
      this->age = age;
      // Shallow Copy
      // this->name = name;

      // Deep Copy
      this -> name = new char[strlen(name)+1];
      strcpy(this->name, name); // strcpy(destination,  source)

    }

    // Copy Constructor 
    // When ever array or pointer is used, we should create our own copy constructor as in default copy contructor shallow copy is done. And we should always try to do deep copy.
    Student(Student const &s){ // reference is passed so that the extra memory is not allocated temporarily and const is used so that we dont mistakenly do illegal changes in the properties of the object passed.
      this->age=s.age;
      // this->name=s.name; // Shallow Copy

      // Deep Copy
      this->name=new char[strlen(s.name)+1];
      strcpy(this->name, s.name);
    }

    void display(){
      cout<<endl<<"Name: "<< name<<" Age: "<<age<<endl;
    }

};