#include <string>
#include <iostream>
#include "GameOfLife.h"
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
  GameOfLife* theGame = new GameOfLife(5,5);
  string theStrings[5];
  theStrings[0] = "-xx--";
  theStrings[1] = "-x-x-";
  theStrings[2]= "--xx-";
  theStrings[3] = "-----";
  theStrings[4]= "xx-xx";

  for(int i =0;i<5;i++)
    theGame ->fillGridLine(theStrings[i]);
  for(int i = 0;i<20;i++)
  {
    cout << "Generation: " << i <<endl;
    theGame -> calculateNextGen();
    theGame -> printCurrentGrid();
  }





  // theGame -> calculateNextGen();
  // theGame -> printCurrentGrid();
  delete theGame;





  ///for testing arrays
  // int n = 5;
  // int m = 5;
  // int rowNum = n;
  // int colNum = m;
  // char** theGrid;
  // theGrid = new char*[n];
  // for(int i =0; i < m;++i)
  //   theGrid[i] = new char[m];
  //
  // for (int i = 0; i < rowNum; ++i) {   // for each row
  //   for (int j = 0; j < colNum; ++j) { // for each column
  //     theGrid[i][j] = '-';
  //     if(i == 1)
  //       theGrid[i][j] = 'x';
  //   }
  // }
  // cout << "First grid" <<endl;
  // for (int i = 0; i < rowNum; ++i) {   // for each row
  //   for (int j = 0; j < colNum; ++j) { // for each column
  //     std::cout << theGrid[i][j];
  //   }
  //   std::cout << "\n";
  // }
  //
  // //how to copy
  // char** secondGrid;
  // secondGrid =  new char*[n];
  // for(int i =0;i<m;i++)
  //   secondGrid[i] = new char[m];
  // for (int i = 0; i < rowNum; ++i) {   // for each row
  //   for (int j = 0; j < colNum; ++j) { // for each column
  //     secondGrid[i][j] = theGrid[i][j];
  //   }
  // }
  // cout<< "Second grid" <<endl;
  //
  // for (int i = 0; i < rowNum; ++i) {   // for each row
  //   for (int j = 0; j < colNum; ++j) { // for each column
  //     std::cout << secondGrid[i][j];
  //   }
  //   std::cout << "\n";
  // }
  // for(int i = 0; i< rowNum; ++ i)
  //   delete [] theGrid[i];
  // delete [] theGrid;
  // for(int i = 0; i< rowNum; ++ i)
  //   delete [] secondGrid[i];
  // delete [] secondGrid;

  return 0;
}
