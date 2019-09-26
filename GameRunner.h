#ifndef GAMERUNNER_H
#define GAMERUNNER_H
#include "GameOfLife.h"
#include <string>

class GameRunner
{
  bool pauses = false;
  bool fileOutput = false;
  std::string fileName;
  GameOfLife* theGame;
public:
  GameRunner(GameOfLife* &newGame,bool pause);//for without outputfile
  GameRunner(GameOfLife* &newGame,bool pause,std::string fileName);
  ~GameRunner();
  void runClassic();
  void runMirror();
  void runDoughnut();
};
#endif
