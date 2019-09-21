#include <string>
#include <iostream>
#include "GameOfLife.h"

using namespace std;

int main(int argc, char** argv)
{
  GameOfLife* theGame = new GameOfLife(5,5);
  theGame -> fillInitialGrid();
  theGame -> printCurrentGrid();

  return 0;
}
