#include<iostream>

using namespace std;

void increment1(int **p){
  p=p+1;
}

void increment2(int **p){
  *p=*p+1;
}

void increment3(int **p){
  **p=**p+1;
}

int main(){
  int i=10;
  int *p= &i;

  int **p2=&p;
  cout<<p2<<endl;
  cout<<&p<<endl;
  
  cout<<p<<endl;
  cout<<*p2<<endl;
  cout<<&i<<endl;

  cout<<i<<endl;
  cout<<*p<<endl;
  cout<<**p2<<endl;

  cout<<i<<"\t\t"<<p<<"\t\t"<<p2<<endl;
  increment1(p2);
  cout<<i<<"\t\t"<<p<<"\t\t"<<p2<<endl;
  // increment2(p2);
  cout<<i<<"\t\t"<<p<<"\t\t"<<p2<<endl;
  increment3(p2);
  cout<<i<<"\t\t"<<p<<"\t\t"<<p2<<endl;
}