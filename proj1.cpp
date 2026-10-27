//Author: Krish Patel
//Course: CMSC 202 Section 50
//Date: 9/15/23
//Description: Your assignment is to develop the code to read in a list of words into an array of strings. The program will randomly choose a word that is greater than or equal to 8 characters. The program will then build a list of all words that can be made from the chosen word. The user will guess words which will either be valid partial anagrams or not. 

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

//constant that holds max words
const int MAX_EXPRESSION = 9578;

//Array to store the constant
string words[MAX_EXPRESSION];

int number = 0;

//prototypes
void LoadFile(string fileName);
string StartingWord();
bool IsAnagram(string expression1, string expression2);
string GetInput();
int TotalAnagrams(string wordBuilt);
bool CheckGuess(string choice, string* wordGuessed, int numberGuess);
bool CheckValid(string choice, string* wordValid, int validNumber);

int main(){
  //produces welcome to anagrammer message
  cout << "Welcome to UMBC Anagrammer!" << endl;
  
  //input file
  string name = "proj1_data.txt";

  //load the filename from proj1_data.txt
  LoadFile(name);

  string start = StartingWord();

  //produces the random word everytime you run the code
   cout << "Starting word: " << start << endl;

   //number of guess
  const int MAX_NUMBER = 100;

  //array to store the number of guesses
  string wordGuessed[MAX_NUMBER];

  //integer for number of guesses
  int numberGuess = 0;

  //integer to see how many correct guees where enter
  int correct = 1;

  //interger to see total number of anagram per random word
  int total;
  
  //while loop
  while(true){
    //retrieve the input
    string choice = GetInput();

    //if statement
    if(choice.size() < 3){
      //cout the message that 3 characters are needed
      cout << "Minimum of 3 characters." << endl;
      
    }

    //else if statement
    else if(CheckGuess(choice, wordGuessed, numberGuess)){
      //produce already guessed
       cout << "Already Guessed" << endl;

       //produces total anagrams and number of anagrams guessed right
       cout << "You have guessed " << correct << " of " << total << " anagrams available" << endl;
       
    }

    //else if statement
    else if(CheckValid(choice, words, number)){
      //store valid choice
      wordGuessed[numberGuess++] = choice;

      //calculate total anagram per word
      total = TotalAnagrams(start);

      //display the choice enter and anagram 
      cout << choice << " is an angram of " << start << endl;

      //display number of correct anagram
      cout << "You have guessed " << correct << " of " << total << " anagrams available" << endl;

      //neested if statement
      if(IsAnagram(start, choice)){
	correct++;
      }
     }

    //else statment
    else{
      //display not valid word
      cout << choice << " is not a valid word" << endl;

      //display the correct number of anagram
      cout << "You have guessed " << correct << " of " << total << " anagrams available" << endl;
    }

    
  }


  
  return 0;
}

//This function opens the input file of words and loads each word into an array
void LoadFile(string fileName){
  //attempt to open the file
  ifstream myfile(fileName);

  //if statement
  if(!myfile){
    //display error opening file
    cout << "Error opening file" << endl; 
  }

  //string
  string count;

  //while loop
  while (myfile >> count && number < MAX_EXPRESSION) {
        words[number++] = count;
    }

  //close file
    myfile.close();
}

//this function Randomly chooses a word with at least 8 letters
string StartingWord(){
  //random number generator
  srand(unsigned(time(NULL)));

  //while statement
  while(true){
    //int statement to generate random word
    int ind = rand() % number;

    //if statement
    if (words[ind].size() >= 8) {
      //return statement
        return words[ind];
    }
  }
}

//This function Takes in two words and checks to see if one word can be made from the other. Returns true if word two can be made from word one. Otherwise returns false.
bool IsAnagram(string expression1, string expression2){
  //Initalize the Array
  int anaGram[256] = {0};

    // for statement
    for (int i = 0; i < expression1.size(); i++) {
        anaGram[int(expression1[i])]++;
    }

    // for statment to Check if word2 can be made from word1
    for (int i = 0; i < expression2.size(); i++) {
        int index = int(expression2[i]);

	//if statement
        if (anaGram[index] == 0) {
	  //return false
            return false;
        }
        anaGram[index]--;
    }

    //return true
    return true;

  
  
}

//This function Allows the player to guess a word
string GetInput(){
  //string
  string choice;

  //display what word word would you like to try
  cout << "What word would you like to try?"<< endl;
  cin >> choice;

  //return choice
  return choice;
  
}

//In this function Iterates through the full list of words and checks to see how many total words can be built from the starting word
int TotalAnagrams(string wordBuilt){
  int check = 0;

  //for loop
  for(int i = 0; i < number; i++){
    
    //if statement
    if(IsAnagram(wordBuilt, words[i])){
      //increment check counter
      check++;
    }
  }

  //return check
  return check;
}

//This function Checks to see if the word guessed has already been guessed
bool CheckGuess(string choice , string* wordGuessed, int numberGuess){
  //for statement
  for(int i = 0; i < numberGuess; i++){

    //if statement
    if(choice == wordGuessed[i]){
      //return true
      return true;
      }
  }

  //return false
  return false;
}

//This function Checks to see if the word guessed exists in the list of words.
bool CheckValid(string choice, string* wordValid, int validNumber){
  //for statement
  for(int i = 0; i < validNumber; i++){

    //if statement 
    if(choice == wordValid[i]){
      //return true
      return true;
    }
  }

  //return false
  return false;
}