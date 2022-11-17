#include <random>
#include <iostream>
#include "dice.h"

Dice::Dice(){}


int Dice::roll(){
      last_roll = this->pips[std::rand() % 6];
      return last_roll;
  }


int Dice::getLastRoll(){return last_roll;}





    
