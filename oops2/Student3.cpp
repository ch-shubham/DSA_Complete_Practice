class Student{
  static int totalStudents;
 
  public:
    int rollNumber;
    int age;

    Student(){
      totalStudents++;
    }

    int getRollNumber(){
      return rollNumber;
    }

    static int getTotalStudents() { // static function can access only static variables and can not use "this" 
      return totalStudents;
    }
};

// :: are called scope resolution operators.
int Student :: totalStudents = 0; // initialize static data members.