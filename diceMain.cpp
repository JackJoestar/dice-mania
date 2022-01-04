#include "dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

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
    cin >> choice;

  
  cout << "\nRevealing dice: ";
  cin.ignore();
  cout << dice[0].getLastRoll() << "\t" << dice[1].getLastRoll() << endl;
  cout << "\nTotal: " << sum << endl;

  if(sum % 2 == 1)
    cout << "\n\tODD!!\t\n";
  else
    cout << "\n\tEVEN!!\t\n";

  if(sum % 2 == choice){
    cout << "\n\tWINNER!\t\n";
  }
  else
    cout << "\n\tLOSER!\t\n";

  return 0;

}

void startMsg(){
  cout <<"================================"<< endl;
 cout << "\tOdd or Even  (1 or 0)" << endl;
 cout <<"================================"<< endl;
}

void clrscr(){cout << "\033[2J\033[1;1H";}
