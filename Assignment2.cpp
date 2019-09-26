#include <string>
#include <iostream>
#include "GameOfLife.h"
#include "ArrayHelper.h"
#include <fstream>

using namespace std;




int main(int argc, char** argv)
{

  GameOfLife* theGame = new GameOfLife(5,5);
  string theStrings[5];
  theStrings[0] = "---X-";
  theStrings[1] = "-----";
  theStrings[2]= "-XX--";
  theStrings[3] = "-----";
  theStrings[4]= "XXXXX";

  for(int i =0;i<5;++i)
    theGame ->fillGridLine(theStrings[i]);
  theGame -> fillMirrorGrid();
  cout<< "Initial Population:" << endl;
  theGame -> printFull();
  for(int i = 0;i<10;i++)
  {
    cout << "Generation: " << i <<endl;
    theGame -> calculateNextGen();
    theGame -> fillMirrorGrid();
    theGame -> printFull();
  }



  delete theGame;

////testing starts here

  // ArrayHelper* helper = new ArrayHelper();
  //
  //
  // ///for testing arrays
  // int n = 5;
  // int m = 5;
  // int rowNum = n;
  // int colNum = m;
  // char** theGrid;
  // helper -> initializeGrid(theGrid,5,5);
  // helper -> fillGrid(theGrid,5,5);
  // helper -> printGrid(theGrid,5,5);
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
  //
  // for (int i = 0; i < rowNum; ++i) {   // for each row
  //   for (int j = 0; j < colNum; ++j) { // for each column
  //     std::cout << secondGrid[i][j];
  //   }
  //   std::cout << "\n";
  // }
  // ///deleting the arrays
  // for(int i = 0; i< rowNum; ++ i)
  //   delete [] theGrid[i];
  // delete [] theGrid;
  // for(int i = 0; i< rowNum; ++ i)
  //   delete [] secondGrid[i];
  // delete [] secondGrid;
  // helper ->deleteArray(theGrid,n);
  // delete helper;
  return 0;
}
