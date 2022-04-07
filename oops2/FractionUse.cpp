#include<iostream>

using namespace std;

#include "Fraction.cpp"

int main(){
  Fraction f1(10,2);
  Fraction f2(15,4);

  // Fraction const f3; // constant object can only call constant functions.
  // cout<<f3.getNumerator()<< " " <<f3.getDenominator() << endl;

  // Fraction const f3(10,20); // constant object can only call constant functions.
  // cout<<f3.getNumerator()<< " " <<f3.getDenominator() << endl;


  // f3.setNumerator(200); // Not allowed as its not a const funciton

  // Fraction f3 = f1.add(f2);
  // Fraction f4 = f1 + f2;
  // f1.print();
  // f2.print();
  // f3.print();
  // f4.print();

  // Fraction f5 = f1*f2;
  // f5.print();

  // Fraction f6(10,2);
  // bool test1 = f1 == f2;
  // bool test2 = f1 == f6;
  // cout<<test1<<endl;
  // cout<<test2<<endl;

  // Fraction f7 = f1++;
  // f1.print();
  // f7.print();


  // Fraction f8 = ++f1;
  // f1.print();
  // f8.print();

  // Fraction f8 = ++(++(++f1)); // Nesting is possible in pre-increment only and not on post increment
  // f1.print();
  // f8.print();

  // int i = 5, j = 3;
  // (i += j) += j;
  // cout << i << " " << j << endl;

  // f1 += f2;
  (f1 += f2) += f2;
  f1.print();
  f2.print();



} 