#include "dice.h"
#include <iostream>


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
  

  while(choice != 1 and choice != 0)
    std::cin >> choice;

  
  std::cout << "\nRevealing dice: ";
  std::cin.ignore();
  std::cout << dice[0].getLastRoll() << "\t" << dice[1].getLastRoll() << std::endl;
  std::cout << "\nTotal: " << sum << std::endl;

  if(sum % 2 == 1)
    std::cout << "\n\tODD!!\t\n";
  else
    std::cout << "\n\tEVEN!!\t\n";

  if(sum % 2 == choice){
    std::cout << "\n\tWINNER!\t\n";
  }
  else
    std::cout << "\n\tLOSER!\t\n";

  return 0;

}

void startMsg(){
  std::cout <<"================================"<< std::endl;
 std::cout << "\tOdd or Even  (1 or 0)" << std::endl;
 std::cout <<"================================"<< std::endl;
}

void clrscr(){std::cout << "\033[2J\033[1;1H";}
