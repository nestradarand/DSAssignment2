#include <string>
#include <iostream>
#include "GameOfLife.h"
#include "ArrayHelper.h"
#include <fstream>

using namespace std;




int main(int argc, char** argv)
{

  cout << "Welcome to the Game of Life"<<endl;
  cout<< "This game simulates the lifecylce of bacteria." <<endl;
  cout << "First and foremost, would you like to provide a file to simulate with?" <<endl;
  cout<< "Type 'n' for no or 'y' for yes" <<endl;
  char response;
  bool withFile,pauses,outputToFile;
  string fileName,x;
  int length,width;
  float density;

  ifstream inputStream;
  ofstream outputStream;
  cin >>response;
  while(response != 'n'&&response != 'y')
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> response;
  }
  if(response  == 'y')
  {
    cout << "Type the name of the file you would like to use next: " <<endl;
    cin >>fileName;
    withFile = true;
    inputStream.open(fileName);
    //ensures successful input stream established
    //reference: stack overflow
    if(!inputStream)
    {
      cout << "Error occurred trying to read file." << endl;
      exit(1);
    }
  }
  else if(response == 'n')
    withFile = false;

  cout << "Now, would you liked to have pauses in between generations of the simuilation?"<<endl;
  cout<< "Type 'n' for no or 'y' for yes" <<endl;
  cin >>response;
  while(response != 'n'&&response != 'y')
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> response;
  }
  if(response  == 'y')
    pauses = true;
  else if(response == 'n')
    pauses = false;

  cout<<"Lastly, would you like to have the outputs printed to the screen or saved to a file?"<<endl;
  cin >>response;
  while(response != 'n'&&response != 'y')
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> response;
  }
  if(response  == 'y')
    outputToFile = true;
  else if(response == 'n')
    outputToFile = false;

  if(!withFile)
  {
    cout <<"Enter the length and width of the simulation:" <<endl;
    cout << "Length: " <<endl;
    cin >>length;
    cout << "Width: " <<endl;
    cin >>width;
    cout<< "Now enter the initial density of the initial population." <<endl;
    cout << "Please enter it as a number between 0 and 1" <<endl;
    cin >> density;
  }
  if(withFile)
  {
    inputStream >>length;
    inputStream >>width;
  }



  //
  // ArrayHelper* newHelper = new ArrayHelper();


  // string theStrings[4];
  // theStrings[0] = "X---X";
  // theStrings[1] = "X---X";
  // theStrings[2]= "X---X";
  // theStrings[3] = "X---X";
  //
  // int rows = 4;
  // int cols = 5;
  //
  // // char** tempGrid;
  // // newHelper -> initializeGrid(tempGrid,rows,cols);
  // // cout << "Success" << endl;
  // // newHelper -> fillGrid(tempGrid,rows,cols);
  // // newHelper -> printGrid(tempGrid,rows,cols);
  // GameOfLife* theGame = new GameOfLife(rows,cols);
  // cout << "made" << endl;
  // for(int i = 0;i<rows;++i)
  //   theGame -> fillGridLine(theStrings[i]);
  // theGame -> printFull();
  //
  //
  // cout << "reached the end" << endl;
  // // newHelper -> deleteArray(tempGrid,rows);
  // delete newHelper;
  // delete theGame;
  // delete theGame;
  // for(int i =0;i<6;++i)
  //   newHelper -> fillGridLine(tempGrid,theStrings[i]);
  // newHelper -> printGrid(tempGrid,8,7);



  //
  // theGame -> printFull();
  //
  // for(int i =0;i<5;++i)
  //   theGame ->fillGridLine(theStrings[i]);
  // theGame -> fillDoughnutGrid();
  // cout<< "Initial Population:" << endl;
  // theGame -> printCurrentGrid();
  // theGame -> printFull();
  // for(int i = 0;i<3;i++)
  // {
  //   cout << "Generation: " << i <<endl;
  //   theGame -> calculateNextGen();
  //   theGame ->printCurrentGrid();
  //   theGame -> fillDoughnutGrid();
  //   theGame -> printFull();
  // }
  inputStream.close();
  return 0;
}
