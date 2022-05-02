#include<iostream>

using namespace std;

#include "Pair_template.cpp"

int main(){
  // we need to specify the T while declaring the Pair class object
  // Pair<int> p1; // int will replace the type "T" written in the Pair class. here datatype can be anything like: double, float, char or any data type
  // p1.setX(10);
  // p1.setY(20);
  // cout<<p1.getX()<<endl;
  // cout<<p1.getY()<<endl;

  // cout<<endl;
  // Pair<double> p2; // T will be double here.
  // p2.setX(10.1);
  // p2.setY(20.2);
  // cout<<p2.getX()<<endl;
  // cout<<p2.getY()<<endl;
  
  // cout<<endl;
  // Pair<char> p3; // T will be char here.
  // p3.setX('a');
  // p3.setY('b');
  // cout<<p3.getX()<<endl;
  // cout<<p3.getY()<<endl;
  
  // Here we need to specify the type T and V both during the object creation as we have 2 temporary datatype in our Pair class.
  // Pair<int, double> p4;
  // // int x = 12.32;
  // // cout<<x<<endl; // results 12 and .32 is ignored
  // // p4.setX(100.01);  // .01 is ignored and we get only 100 becuase X is of type int we declared above during the object creation.
  // p4.setX(11);
  // p4.setY(10.11);
  // cout<<p4.getX()<<endl;
  // cout<<p4.getY()<<endl;

  Pair<Pair<int,int>, int> p5;
  Pair<int, int> p6;
  p6.setX(10);
  p6.setY(20);
  p5.setY(30);
  p5.setX(p6);
  // p5 will be something like: (10,20,30)
  cout<<p5.getX().getX()<<endl; // 10 // p5.getX() returns the pair that itself has x and y that can be accessed using getX and getY. So complete way is p5.getX().getX() or p5.getX().getY()
  cout<<p5.getX().getY()<<endl; // 20
  cout<<p5.getY()<<endl; // 30
  
}
