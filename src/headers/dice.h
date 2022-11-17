#ifndef DICE_H
#define DICE

class Dice {
 private:
  int pips[6] = {1,2,3,4,5,6};
  int last_roll = 1;

 public:
  Dice();
  int roll();
  int getLastRoll();

};

#endif
