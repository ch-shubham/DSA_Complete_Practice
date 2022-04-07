class Fraction{
  private:

    int numerator;
    int denominator;

  public:
    Fraction(){}

    Fraction(int numerator, int denominator){
      this -> numerator = numerator;
      this -> denominator = denominator;
    }

    // Constant functions: Those that dont the values of 'this'
    int getNumerator() const{
      return numerator;
    }
    int getDenominator() const{
      return denominator;
    }

    void setNumerator(int num){
      numerator = num;
    }

    void setDenominator(int den){
      denominator = den;
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
    Fraction add(Fraction const &f2){ // Fraction &f2 = main.f2; .... Passing by reference... // This is constant reference.
      int lcm = this -> denominator * f2.denominator; // this is optional here.
      int x = lcm / denominator;
      int y = lcm / f2.denominator;
      
      int num = x * numerator + (y * f2.numerator);
      // numerator = num;
      // denominator = lcm;

      // simplify(); // implicitly means this -> simplify

      Fraction fNew(num, lcm);
      fNew.simplify();
      return fNew;
    }


    // Constant reference is used so that we do not change the values of main f2 from here.
    void multiply(Fraction const &f2){ // Constant Reference.
      numerator *= f2.numerator;
      denominator *= f2.denominator;

      simplify();
    }

    Fraction operator+(Fraction const &f2) const {
      int lcm = denominator * f2.denominator;
      int x = lcm / denominator;
      int y = lcm/(f2.denominator);
      
      int num = x * numerator + ( y * f2.numerator);

      Fraction fNew(num, lcm);
      fNew.simplify();
      return fNew;
    }

    Fraction operator*(Fraction const &f2) const {
      int x = numerator * f2.numerator;
      int y = denominator * f2.denominator;
      
      Fraction fNew(x, y);
      fNew.simplify();
      return fNew;
    }

    bool operator==(Fraction const &f2) const {
      return (numerator == f2.numerator && denominator == f2.denominator);
    }

    // Pre increment 
    Fraction operator++(){
      numerator = numerator + denominator;
      simplify();

      return *this;
    }

    // Nesting in post increment is not possible
    // post-increment
    Fraction operator++(int){
      Fraction fNew(numerator, denominator);
      numerator = numerator + denominator;
      simplify();
      fNew.simplify();
      return fNew;
    }

    // void operator+=(Fraction const &f2){
    Fraction& operator+=(Fraction const &f2){ // To support nesting of += operator we are returning Fraction reference thing.
      int lcm = denominator * f2.denominator;
      int x = lcm / denominator;
      int y = lcm / f2.denominator;
      int num = x * numerator + (y * f2.numerator);

      numerator = num;
      denominator = lcm;
      simplify();
      return *this; // To support nesting of += operator we are returning this.
    }
};
