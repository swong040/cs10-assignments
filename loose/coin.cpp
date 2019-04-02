#include <iostream>
#include <cstdlib>


using namespace std;

const int heads = 0;
const int tails = 1;

double percentHeads(double coinToss){
   double headCount = 0;
   int coin;
   for(int i = 1; i <= coinToss; i++){
      coin = rand() % 2;
      if(coin == heads){
         ++headCount;
      }
   }
   double percent = (headCount/coinToss) * 100.00;
   
   return percent;
}

int main(){
   int userInput = 0;
   srand(4444);
   
   cout << "Enter the number of times you want to toss the coin: ";
   cin >> userInput;
   
   
   cout << "Heads came up " << percentHeads(userInput) << "% of the time." << endl;
   
   
}