#include "GameRunner.h"
#include "GameOfLife.h"
#include <iostream>
#include <string>

using namespace std;

GameRunner::GameRunner(GameOfLife* &newGame,bool pause)
{
  theGame = newGame;
  pauses = pause;
}
GameRunner::GameRunner(GameOfLife* &newGame,bool pause,std::string fileName)
{
  theGame = newGame;
  pauses = pause;
  fileName = fileName;
  fileOutput = true;
}
GameRunner::~GameRunner()
{
  // delete theGame;
}
void GameRunner::runClassic()
{
  
}
void GameRunner::runMirror()
{

}
void GameRunner::runDoughnut()
{

}
