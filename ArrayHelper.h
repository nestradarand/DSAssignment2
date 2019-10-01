/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 2 Game Of Life
*/
#ifndef ARRAY_HELPER_H
#define ARRAY_HELPER_H
#include <iostream>
#include <string>

/*This class is used to make basic array arithmetic and methods streamlined.
Majority of the methods service 2D arrays.  Specifically used in Game Of Life*/

class ArrayHelper
{
  int numLine = 1;
public:
  //default constructor
  ArrayHelper();
  //deconstructor
  ~ArrayHelper();
  //deletes 2d array in argument,only needs the length of the array to delete it
  void deleteArray(char** toDelete, int length);
  //assuming both arrays have the same dimensions, the method will copy the contents
  //of one array to the next based on the given dimension
  void copyArray(char** initArray, char** &copyArray,int n, int m);
  //prints a given grid based on the given dimensions
  void printGrid(char** &theArray, int n,int m);
  //used specifically in game of life to print the main grid and ignore the
  //buffer grid around the main grid
  void printSelectGrid(char** &theArray, int n,int m);
  //initializes a new array by allocating memory based on the given dimensions
  void initializeGrid(char** &newArray,int n, int m);
  //fills a given 2d array with '-' given the length and width of the grid
  void fillGrid(char** &grid,int n, int m);
  //checks the equality of two grids based on their dimensions;ASSUMES they are the same size
  bool checkEquality(char** firstGrid, char** secondGrid,int n,int m);


};
#endif
