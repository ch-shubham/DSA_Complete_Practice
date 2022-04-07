class Fraction{
  private:

    int numerator;
    int denominator;

  public:
    Fraction(int numerator, int denominator){
      this -> numerator = numerator;
      this -> denominator = denominator;
    }

    void print(){
      cout<< numerator << " / " << denominator <<endl;
    }


    void simplify() {
      int gcd = 1;
      int j = min(this -> numerator, denominator); // this is optional here. Implicity it means this -> denominator only.
      for(int i = 1; i <= j ; i++){
        if(this -> numerator % i == 0 && this -> denominator % i == 0 ){
          gcd = i;
        }
      }
      this -> numerator = this -> numerator / gcd; 
      this -> denominator = this -> denominator / gcd;
    }

    // void add(Fraction f2){  // Fraction f2 = main.f2......... Copy constructor is called internally.
    void add(Fraction const &f2){ // Fraction &f2 = main.f2; .... Passing by reference... // This is constant reference.
      int lcm = this -> denominator * f2.denominator; // this is optional here.
      int x = lcm / denominator;
      int y = lcm / f2.denominator;
      
      int num = x * numerator + y * f2.numerator;
      numerator = num;
      denominator = lcm;

      simplify(); // implicitly means this -> simplify
    }


    // Constant reference is used so that we do not change the values of main f2 from here.
    void multiply(Fraction const &f2){ // Constant Reference.
      numerator *= f2.numerator;
      denominator *= f2.denominator;

      simplify();
    }


};