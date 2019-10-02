/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 2 Game Of Life
*/

#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <iostream>
#include "ArrayHelper.h"

/*This game of life class is meant to be mostly self contained in terms of
managing the main grid and other functinality based on project requirements.
The actual game modes are implemented in the main Assignment2 main method class,
however the robust implementations of calculating next generations and
specific game mode requirements are contain.  The class ArrayHelper is used
to streamline the manipulation of 2d arrays*/

class GameOfLife
{
  ArrayHelper* arrayHelper = new ArrayHelper();
  int numLine = 0;
  char** theGrid;
  char** secondGrid;
  char** previousGrid;
  int rowNum = 0;
  int colNum =0;
  //number used to determine when to create a copy of the previous generation
  int checkNumber = 1;

public:
  //constructors
  GameOfLife();
  GameOfLife(int n,int m);
  //deconstructors
  ~GameOfLife();
  //prints current grid
  void printCurrentGrid();
  //usd for debugging
  void printSecondGrid();

  //works for individual lines
  void fillGridLine(std::string str);
  //calculates the next generation
  void calculateNextGen();
  //fills buffer grid with results of mirror rules
  void fillMirrorGrid();
  //fills buffer grid with results of doughnut rules
  void fillDoughnutGrid();

  //for debugging to vew buffer grid
  void printFull();
  //creates a random population based on given density
  void createRandomPopulation(float density);
  //returns if the population is stable compared to the previous generation
  bool checkStability();
  //returns the main grid
  char** returnCurrentGrid();





private:
  //saves shadow copy to main grid
  void saveShadow();
  //makes shadow copy of main grid
  void makeShadowCopy();

};
#endif
