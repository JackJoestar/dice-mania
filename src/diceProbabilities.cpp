#include "dice.h"
#include <iostream>

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

    //Odd
    choice = 1;
    
    if(sum % 2 == choice)
      oddWins++;
    else
      continue;
    
  }
  for(games = 0; games < 1001; games++){
    sum = dice[0].roll() + dice[1].roll();

    //Even
    choice = 0;
    
    if(sum % 2 == choice)
      evenWins++;
    else
      continue;
    
  }

  float oddWinnings = oddWins / games;
  float evenWinnings = evenWins / games;
  
  std::cout << "PROBABILITIES AFTER 1000 GAMES" << std::endl;
  std::cout << "Always choose Odd: " << oddWinnings * 100 << "%" << std::endl;
  std::cout << "Always choose Even: " << evenWinnings * 100 << "%" << std::endl;


  return 0;

}

void startMsg(){
  std::cout <<"================================"<< std::endl;
 std::cout << "\tOdd or Even" << std::endl;
 std::cout <<"================================"<< std::endl;
}

void clrscr(){std::cout << "\033[2J\033[1;1H";}
