/*
Name: Noah Estrada-Rand
Student ID#: 2272490
Chapman email: estra146@mail.chapman.edu
Course Number and Section: CPSC-350-01
Assignment: Assignment 2 Game Of Life
*/

#include <string>
#include <iostream>
#include "GameOfLife.h"
#include "ArrayHelper.h"
#include <fstream>
#include <limits>

using namespace std;

/*this main method handles the main coordination of different game modes
based on user preferences and input*/

int main(int argc, char** argv)
{
  //declare all variable types to be used in the following statements
  GameOfLife* theGame;
  //these chars store the responses of the user
  char response,mode;
  //used as a temporary holder for any outputted grid
  char** holder;
  //with file is a boolean for if they want to read from a file, pauses is if they want pauses
  //outputToFile is if the user wants to output to a file
  bool withFile,pauses,outputToFile;
  //stores strings for file names and content read from a file
  string fileName,inContent,saveFile;
  //length and width used to initialize grid; genCount counts which generation we are on
  int length,width,genCount=0;
  //stores initial density of the population when generated randomly
  float density;
  //file streams to be used in the case that the user wants to read or write to a file
  ifstream inputStream;
  ofstream outputStream;
  cout << "Welcome to the Game of Life"<<endl;
  cout<< "This game simulates the lifecylce of bacteria." <<endl;
  cout << "First and foremost, would you like to provide a file to simulate with?" <<endl;
  cout<< "Type 'n' for no or 'y' for yes" <<endl;
  cin >>response;
  while(response != 'n'&&response != 'y')//ensures that a valid input is entered
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> response;
  }
  if(response  == 'y')//if the user wants to use a file they will be prompted for the file
  {
    cout << "Type the name of the file you would like to use next: " <<endl;
    cin >>fileName;
    withFile = true;
    inputStream.open(fileName);
    cout<<"File successfully opened" << endl;
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
  //ask user if they want pause between generations being displayed/saved
  cout << "Now, would you like to have pauses in between generations of the simulation for easier viewing?"<<endl;
  cout<< "Type 'n' for no or 'y' for yes:" <<endl;
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
  //prompt user to enter name of output file if they wish to have output stored to a file
  cout<<"Lastly, would you like to have the outputs only printed to the screen or also saved to a file?"<<endl;
  cout << "Enter 'p' for print only or 's' to save the outputs as well:"<<endl;
  cin >>response;
  while(response != 'p'&&response != 's')
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> response;
  }
  if(response  == 's')
  {
    outputToFile = true;
    cout << "Please enter the name of the file you wish to save to:" <<endl;
    cin >>saveFile;
    outputStream.open(saveFile);
    //handles error if the file was not able to be opened
    if(!outputStream)
    {
      cout << "Error occurred trying to read file." << endl;
      exit(1);
    }
  }
  else if(response == 'p')
    outputToFile = false;
  //if initial generation not read from file, user prompted for dimensions and density of population
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
    theGame = new GameOfLife(length,width);
    theGame -> createRandomPopulation(density);
  }
  //if user wants to provide initial generation from file the following executes
  if(withFile)
  {
    cout << "Reading file contents"<<endl;
    inputStream >>length;
    inputStream >>width;
    theGame = new GameOfLife(length,width);
    //reads in file content and populates the initial population grid
    while(inputStream >> inContent)
      theGame ->fillGridLine(inContent);
  }
  //prompt user for game mode selection
  cout<< "Lastly, enter what game mode you wish to have:" << endl;
  cout << "Enter 'c' for classic, 'm' for mirror mode, or 'd' for doughnut mode"<<endl;
  cin >> mode;
  while(mode != 'c'&&mode != 'm' && mode != 'd')
  {
    cout<< "Invalid command entered. Try again." <<endl;
    cin >> mode;
  }
  //the following will be executed for classic mode
  if(mode == 'c')
  {
    //so long as the population is not stable, this loop will run
    while(theGame -> checkStability() == 0)
    {
      cout<< "Generation " <<genCount<< endl;
      //prints the current gen
      theGame -> printCurrentGrid();
      // if user wanted pauses, then a pause occurs until enter is pressed
      if(pauses)//reference: stack overflow
        system("read -p 'Press Enter to continue...' var");
      //if user wanted output written to file
      if(outputToFile)
      {
        //returns current main grid
        holder = theGame->returnCurrentGrid();
        //prints generation number and generation to the file specified
        outputStream << "Generation " <<genCount<< "\r\n";
        for(int i = 1;i<length+1;++i)
        {
          for(int j = 1; j <width+1;++j)
          {
            outputStream << holder[i][j];
          }
          outputStream << "\r\n";
        }
      }
      //calculatges the next generation
      theGame -> calculateNextGen();
      //counter to keep track of generation number is incremented
      genCount++;
    }
    if(outputToFile)
      outputStream << "Population stable, simulation terminated.";
    cout<<"Population stable"<<endl;
  }
  //the following is executed for mirror mode
  if(mode == 'm')
  {
    //so long as the population is not stable, this loop will run
    while(theGame -> checkStability() ==0)
    {
      //fills the outer grid buffer with results of mirror rules
      theGame -> fillMirrorGrid();
      //prints the current generation
      cout << "Generation " << genCount <<endl;
      theGame ->printCurrentGrid();
      //pauses if the user wants pauses in between displays
      if(pauses)
        system("read -p 'Press Enter to continue...' var");
      //if the user wanted output saved to file the following executes
      if(outputToFile)
      {
        //stores the main grid
        holder = theGame->returnCurrentGrid();
        //writes generation info to the file
        outputStream << "Generation " <<genCount<< "\r\n";
        for(int i = 1;i<length+1;++i)
        {
          for(int j = 1; j <width+1;++j)
          {
            outputStream << holder[i][j];
          }
          outputStream << "\r\n";
        }
      }
      //calculates the next generation
      theGame -> calculateNextGen();
      //increment generation count
      genCount ++;
    }
    if(outputToFile)
      outputStream << "Population stable, simulation terminated.";
    cout<<"Population stable"<<endl;
  }
  //the following is executed for doughnut mode
  if(mode == 'd')
  {
    //so long as the population is not stable, this loop will run
    while(theGame -> checkStability() ==0)
    {
      //fills the grid buffer with the results of the doughnut rules
      theGame -> fillDoughnutGrid();
      //prints out generation number and current generation grid
      cout<< "Generation " << genCount << endl;
      theGame ->printCurrentGrid();
      //if the user wants pauses the loop pauses
      if(pauses)
        system("read -p 'Press Enter to continue...' var");
      //if the user wants to output to the file, then write to the file
      if(outputToFile)
      {
        //stores the current grid
        holder = theGame->returnCurrentGrid();
        outputStream << "Generation " <<genCount<< "\r\n";
        for(int i = 1;i<length+1;++i)
        {
          for(int j = 1; j <width+1;++j)
          {
            outputStream << holder[i][j];
          }
          outputStream << "\r\n";
        }
      }
      //calculate the next generation
      theGame ->calculateNextGen();
      //increment generation count
      genCount ++;
    }
    if(outputToFile)
      outputStream << "Population stable, simulation terminated.";
    cout<<"Population stable"<<endl;
  }
  //has user press enter to exit the whole program
  system("read -p 'Press Enter to exit the simulation...' var");

  //deallocate memory stored for the GameOfLife object and closes all streams
  delete theGame;
  outputStream.close();
  inputStream.close();
  return 0;





}
