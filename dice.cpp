#include <random>
#include <iostream>
#include <ctime>
#include <cstdlib>



using namespace std;
#include "dice.h"
#include <cstdlib>
#include <ctime>

Dice::Dice(){}


int Dice::roll(){
      last_roll = this->pips[rand() % 6];
      return last_roll;
  }


int Dice::getLastRoll(){return last_roll;}





    
