// Example program
#include <iostream>
#include <cstring>
using namespace std;

void changeToUpper (string &phrase){
    
    for (int i = 0; i < phrase.length(); i++){
           phrase[i]= toupper(phrase[i]);
        }
    }

int main()
{
  string phrase = "";
 string * ptr = nullptr;
  
  cout << " Enter your phrase" <<endl;
  getline(cin, phrase);
  
  
  changeToUpper ( phrase);
  ptr = &phrase;
  cout <<*ptr ; // the same as cout<< phrase
}

