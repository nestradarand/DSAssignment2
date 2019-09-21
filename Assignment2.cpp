#include <string>
#include <iostream>
#include "GameOfLife.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  GameOfLife* theGame = new GameOfLife(5,5);
  string theStrings[5];
  theStrings[0] = "----x";
  theStrings[1] = "--x--";
  theStrings[2]= "-xx--";
  theStrings[3] = "-----";
  theStrings[4]= "xxxxx";

  for(int i =0;i<5;i++)
    theGame ->fillGridLine(theStrings[i]);
  theGame -> printCurrentGrid();
  delete theGame;


  return 0;
}
