#ifndef ARRAY_HELPER_H
#define ARRAY_HELPER_H
#include <iostream>
#include <string>


class ArrayHelper
{
  int numLine = 1;
public:
  ArrayHelper();
  ~ArrayHelper();
  void deleteArray(char** toDelete, int length);
  void copyArray(char** initArray, char** &copyArray,int n, int m);
  void printGrid(char** &theArray, int n,int m);
  void printSelectGrid(char** &theArray, int n,int m);
  void initializeGrid(char** &newArray,int n, int m);
  void fillGrid(char** &grid,int n, int m);
  void fillGridLine(char** &gridToFill,std::string str);
  bool checkEquality(char** firstGrid, char** secondGrid,int n,int m);


};
#endif
