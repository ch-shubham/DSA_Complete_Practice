// Remove consecutive duplicate chars from string. EX: "aabbccdeadd" should return  "abcdead"

#include<iostream>

using namespace std;

void remove_duplicate(char s[]){
  if(s[0] == '\0' || s[1] == '\0'){ // if string has 0 or 1 char only then return as it is.
    return;
  }
  remove_duplicate(s+1);
  if(s[0] == s[1]){
    int i = 1;
    for(; s[i] != '\0' ; i++){
      s[i-1] = s[i];
    }
    s[i-1] = s[i];
  }
} 

int main(){
  char s[] = "aabbccdeadd";
  // char s[] = "saabbccdeadd";
  // char s[] = "s";
  // char s[] = "";
  cout<<s<<endl;
  remove_duplicate(s);
  cout<<s<<endl;
}