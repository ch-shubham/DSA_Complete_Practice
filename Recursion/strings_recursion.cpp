#include<iostream>
using namespace std;

void removeX(char s[]){
  if(s[0] == '\0'){
    return;
  }
  if(s[0] == 'x'){
    int i=1;
    for(; s[i] != '\0'; i++){
      s[i-1] = s[i];
    }
    s[i-1] = s[i];
    removeX(s+1);
  }
  else{
    removeX(s+1);
  }
}

int length(char s[]){
  if(s[0] == '\0'){
    return 0;
  }
  int smallStringLength = length(s+1);
  int finalTotalLength = 1 + smallStringLength;
  return finalTotalLength;
}

int main(){
  // char s[] = "shubham";
  // char s[] = "abxcxde";
  char s[] = "xabxcxde";

  cout<<length(s)<<endl;
  removeX(s);
  cout<<s<<endl;
  cout<<length(s)<<endl;

}