#include "dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;
int games = 0;
float oddWins = 0;
float evenWins = 0;

void clrscr();
void startMsg();

int main(){
  clrscr();
  srand(time(0));
  Dice dice[2];
  int choice = 2;
  for(int i = 0; i < 2; i++)
    dice[i] = Dice();

  int sum = dice[0].roll() + dice[1].roll();

  startMsg();

  for(games = 0; games < 1001; games++){
    sum = dice[0].roll() + dice[1].roll();
    choice = 1;
    
    if(sum % 2 == choice)
      oddWins++;
    else
      continue;
    
  }
  for(games = 0; games < 1001; games++){
    sum = dice[0].roll() + dice[1].roll();
    choice = 0;
    
    if(sum % 2 == choice)
      evenWins++;
    else
      continue;
    
  }

  float oddWinnings = oddWins / games;
  float evenWinnings = evenWins / games;
  
  cout << "PROBABILITIES AFTER 1000 GAMES" << endl;
  cout << "Always choose Odd: " << oddWinnings * 100 << "%" << endl;
  cout << "Always choose Even: " << evenWinnings * 100 << "%" << endl;


  return 0;

}

void startMsg(){
  cout <<"================================"<< endl;
 cout << "\tOdd or Even" << endl;
 cout <<"================================"<< endl;
}

void clrscr(){cout << "\033[2J\033[1;1H";}
