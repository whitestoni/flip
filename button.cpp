#include <iostream>
#include <string>
using namespace std;
 void button(char letter,int times){

     char keypad[][8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
     
     if(letter-'0'>=2 && letter-'0'<=9){
         cout << keypad[letter-'0'-2][times-1];
     }
     else{
        cout << letter;
     }
 }