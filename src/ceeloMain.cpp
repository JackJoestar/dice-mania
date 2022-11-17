#include "headers/dice.h"
#include <iostream>


void clrscr();
void startMsg();
void bubbleSort(Dice arr[], int n);
void swap(Dice *xd, Dice *yd);
int unique(Dice arr[], int n);
bool checkDuplicates(Dice arr[], int n);

int player = 0;
int score1 = 0;
int score2 = 0;
bool scoreSet1 = false;
bool scoreSet2 = false;

int main(){
  clrscr();
  srand(time(0));

  //Initialize dice
  Dice dice[3];
  for(int i = 0; i < 3; i++)
    dice[i] = Dice();


  

  startMsg();

  while(player != -1){
    //First Roll The Dice then sort them
  std::cin.get();
  
  for(int i = 0; i< 3; i++){
    dice[i].roll();
  }
  
  bubbleSort(dice, 3);

  std::cout <<  "PLAYER " << player << " Rolling dice: ";
  for(int i = 0; i<3; i++){
    std::cout << dice[i].getLastRoll() << " ";
    
  }
  std::cout << std::endl;


  
  
  //Conditionals
  
  //Winning
  if(dice[0].getLastRoll() == 4 and
     dice[1].getLastRoll() == 5 and
     dice[2].getLastRoll() == 6){
    std::cout << "PLAYER " << player << " IS THE WINNER!!" << std::endl;
    break;
  }else if(((dice[0].getLastRoll() == 
	     dice[1].getLastRoll()) ==
	    dice[2].getLastRoll())){
    std::cout << "PLAYER " << player << " IS THE WINNER!!" << std::endl;
    break;
  }//Losing
  else if(dice[0].getLastRoll() == 1 and
     dice[1].getLastRoll() == 2 and
     dice[2].getLastRoll() == 3){
    std::cout << "PLAYER " << player << " IS THE LOSER!!" << std::endl;
    break;
  }

 

  //N-points

  if(player == 0 and checkDuplicates(dice, 3)){
    score1 = unique(dice, 3);
    scoreSet1 = true;
  }
  if(player == 1 and checkDuplicates(dice,3)){
    score2 = unique(dice, 3);
    scoreSet2 = true;
  }

  if(score1 > score2 and scoreSet1 and scoreSet2){
    std::cout << "\nSCORE: " << score1 << "\t" << score2 << std::endl;
    std::cout << "PLAYER 0 IS THE WINNER!!" << std::endl;
    break;
  }else if(score2 > score1 and scoreSet1 and scoreSet2){
    std::cout << "\nSCORE: " << score1 << "\t" << score2 << std::endl;
    std::cout << "PLAYER 1 IS THE WINNER!!" << std::endl;
    break;
  }else if(score1 == score2 and scoreSet1 and scoreSet2){
    player = 0;
    score1 = 0;
    score2 = 0;
    scoreSet1 = false;
    scoreSet2 = false;
    continue;}


  //Change Turn
  if(player == 0 and scoreSet1)
    player = 1;
  else if(player == 1 and scoreSet2)
    player = 0;
    
 }

  





  return 0;

}

void startMsg(){
  std::cout <<"======================================"<< std::endl;
 std::cout << "\tCEELO (Push Enter to roll!)" << std::endl;
 std::cout <<"======================================"<< std::endl;
}

void clrscr(){std::cout << "\033[2J\033[1;1H";}

void bubbleSort(Dice arr[], int n){
  int i, j;
  bool swapped;
  for(i = 0; i<n-1; i++){
    swapped = false;
    for(j = 0; j< n-i-1; j++){
      if(arr[j].getLastRoll() > arr[j+1].getLastRoll()){
	swap(&arr[j], &arr[j+1]);
	swapped = true;

      }

    }


    if( swapped == false)
      break;
    
  }
}

void swap(Dice *xd, Dice *yd){
  
  Dice temp = *xd;
  *xd = *yd;
  *yd = temp;
  

}

int unique(Dice arr[], int n){
  int unique = 0;

  for(int i = 0; i < n; i++){
      unique = unique ^ arr[i].getLastRoll();
    


  }

  return unique;


}

bool checkDuplicates(Dice arr[], int n){
  for(int i = 0; i < n; i++){
    if(arr[i].getLastRoll() == arr[i+1].getLastRoll()){
      return true;
    }
  }

  return false;

}
