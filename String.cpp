 /*
 
------- SRN : 17035066 | Task 2: this is my own work and it has been tested fully-------

  */

#include <iostream> // Allows the use of commands listed in the library Iostream
#include <string> // Allows the use of commands listed in the string library
#include<list> // Allows the use of commands listed in the list library
#include <algorithm> // Allows the use of commands listed in the Algorithm library
#include <random> // Allows the use of commands in the random library
#include <fstream>//declares a set of standard file stream devices that can be used to to create, read and use files
#include <ctime>//declares a set of functions, macros and types to work with date and time information, e.g. the time() function is used to get the current time
#define cDATAFILE "Words_75K_PreSubmissionTesting.csv"\

using namespace std; // removes the need to put std:: before commands used in the code by setting std:: as default

string GetWord(void) { // a function that allows the user to input a word/phrase and then change to a differnt word/phase at a later time

  string NewString = "SRN : 17035066"; // declares a string that is used to store anything the user inputs

  cout << "please enter a word or phrase "; // a message is displayed in the console 

  bool len = false; // defines the boolean value len and sets it to false

  while (len == false){ // a loop that checks the length of the inputted string
    ws(cin); // allows the user to input a word/phrase and removes any Whitespaces

    getline (cin, NewString); // captures the whole line of cin instead of just the first word

    if (NewString.length() == 1){ // if the length of the string NewString is = 1 then an error message is shown
      cout << endl << "Please enter a valid word/phrase!\n"; // error message that is printed to console
      cout << "please enter a word or phrase "; // prints another message to the console prompting for the user to enter word/phrase
    }
  
   else { // if the length of the string NewString > 1 then this code is executed instead
      len = true; // sets the boolean len to true
    }
  }
  return NewString; // Returns the contents of NewString so that it may be used in external functions

}

void QuitNow(void) { // a function that stops the code from running when executed
  
  string confirm; //defines the string confirm which will be used to store the users input
  string quit = "y"; // creates another string called quit and stores the letter "y" in it

 cout << endl << endl << "Are you sure you want to quit?\n" << endl; // displays confirmation message in console

 ws(cin); //listens for user input and removes whitespace
 getline (cin, confirm); //reads the whole line and stores it in the string confirm

 if (confirm == quit) { // if the string confirm == quit then shut down the program
   cout << "Systems shutting down!"; // shut down message
    exit(EXIT_SUCCESS); // kills the program
 }
}

void TimeTaken() { // function to be called at the end of other functions with the sole purpose of displaying the time taken after the function has completed.
    int startTicks, stopTicks; //declares 2 integers that will be used to stop and start the "clock"
    int totalTicks; // integer that will be used to calculate the total number of ticks
    float timeSeconds; // interger that will have the time in seconds store in it

    startTicks=clock(); // starts the "clock"
    stopTicks=clock(); // stops the "clock"

    totalTicks = stopTicks - startTicks;  // total number of ticks 
    timeSeconds = totalTicks/double(CLOCKS_PER_SEC) * 1000; // converts the ticks of the "clock" into seconds

    cout << endl << endl << "The Program Took: " << timeSeconds << " seconds to complete the Task!" << endl << endl; // prints the time taken in seconds into the console


  }

void ReadFile(void) { // a function that reads through the words file
  string CurrentWord; // declares the string Currentword
  fstream dbFile; // declares dbFile allowing it to be called in the following code
  dbFile.open(cDATAFILE); // opens the file so that i can be read

  while(!dbFile.eof()) { // sets a loop that runs until you reach the end of the file
    getline(dbFile, CurrentWord); // gets the current line of the file

    //cout << endl << CurrentWord;
  }
  dbFile.close(); // closes the file

}

string ToLower(string OriginalString){ // A function that converts the contents of the string "OriginalString" to lowercase
  string LocalString; // declares the string "LocalString" 
  int len; // declares the integer "len"

  len = OriginalString.length(); //sets the integer "len" = to the length of the string "OriginalString"

  for (int i = 0; i < len; i++) { // A loop that converst the contents of "OriginalString" to lowercase using the integers "i" and "len" when "i" < "len"

    OriginalString[i] = tolower(OriginalString[i]); // converts the contents of "OriginalString" at point "i" to lowercase
    LocalString = OriginalString; // Sets the string "LocalString" = to "OriginalString"

  }

 return LocalString; // Returns the contents of the string "LocalString" so that it may be used it other functions within the code
}

string OrderWord(string OriginalString){ // A fuction that puts the characters in a string into alphabetical order. 
  string LocalString; //declares a string for use in the function called "LocalString"

  sort(OriginalString.begin(), OriginalString.end()); //sorts the characters in the string "OriginalString" into aplhabetical order from the beginning of the string to the end
  LocalString = OriginalString; // copys the contents of OriginalString into the string "LocalString"
 return LocalString; //Returns the contents of "LocalString" so that it may be used outside of the function
}


void FindAnagram(string OriginalString) { // a function that finds algorithms of the users inputted string from the words file used
  fstream dbFile; // declares dbFile so that it can be used in the function
  string LocalString; // declares the string LocalString
  string ModString; // declares the string ModString
  string ModLocal; // declares the string ModLocal
  int count = 0; // integer used to display the number of anagrams found for users input
  int test = 0; // integer used to test if all words from csv file are printed into console
  int Origlen; // declares the integer Origlen that will hold the original length of the string Original string
  int LocalLen; // declares the integer LocalLen that will hold the length of the word being read in the word file

  bool LocalBool = false; // declares a boolean value LocalBool and sets it to false
  vector<string> LocalList; // declares the vector LocalList

  ModString = ToLower(OriginalString); // converts the string OriginalString into lowercase and stores it in the string ModString
  ModString = OrderWord(ModString); // puts the characters stored in ModString into order (alphabetical)

  Origlen = ModString.length(); // sets the integer OrigLen to the length of ModString

  dbFile.open(cDATAFILE); // opens the words file

  while (!dbFile.eof()) { // a loop that scans through the file and reads each word
    getline(dbFile, LocalString); // gets the current line of the file
    
    ModLocal = OrderWord(LocalString); // orders the current word being read 
    ++test; // increments an integer that was used for testing purposes

    //cout << test <<" "<< ModLocal << "\n" <<endl; // prints all words in the csv into the console with the int "test" before them.
    
   LocalLen = ModLocal.length(); // sets the integer LocalLen to the length of ModLocal

    
    if (Origlen == LocalLen) { // compares the length of the original string to the current word being read
      if  (ModLocal == ModString) { // compares the characters in the strings ModLocal and ModString
        ++count; // increments the counter 

        LocalBool = true; // changes the value of LocalBool to true to indicate an anagram has been found
        LocalList.push_back(LocalString); // pushes the contents of LocalString into teh vector LocalList

      }
    }
  }
    if (count < 1) { // checks that the count is less than 1 
      cout << "\n \n There are no anagrams for this word or phrase!" << endl << endl; // prints an error message to the console that tells the user that no anagram was found

    }

    if (LocalBool == true) { // checks if the value of LocalBool is true 
      cout << "\n \n Found " << count << " anagram(s): "; // prints a message to tell the user that an anagram has been found along with the number found
       for(int f=0; f < LocalList.size(); f++) // a loop that runs through the vector file and prints each value into the console
        cout << LocalList.at(f) << endl; // prints the current string being read in the vecotr

    }
    dbFile.close(); // closes the file
    TimeTaken(); // prints the time taken is seconds to the console
}


/*void LargestWordAvailable (string OriginalString) { an old attempt at a function
  fstream dbFile;
  string LocalString;
  string LocalString2;
  string Longest;
  string LocalStringMod;
  string LocalStringMod2;

  int CompLen;
  int CompLen2;
  int CommonChar;
  int OrigLen;
  int MostChar;

  CompLen = OriginalString.length();

  dbFile.open(cDATAFILE);

  LocalStringMod = ToLower(OriginalString);
  LocalStringMod = OrderWord(LocalStringMod);

  OrigLen = OriginalString.length();
  MostChar = OrigLen * 0.75;

  while (!dbFile.eof()){
    getline(dbFile, LocalString2);
    
    LocalStringMod2 = OrderWord(LocalString2);
    CompLen2 = LocalString2.length();

    for (int i=0; i < LocalStringMod.length(); ++i) {
      for (int i2=0; i2 < LocalStringMod2.length(); ++i2) {
        if (LocalStringMod[i] == LocalStringMod2[i2]) {
          ++CommonChar;
        }
      }
    }

    if (CompLen2 > CompLen) {
      if (CommonChar >= MostChar) {
      Longest = LocalString2;

      CompLen = Longest.length();
      } 
    }

    }

    cout << "\n\nThe Longest Word Was " << Longest << endl;
    dbFile.close();
    TimeTaken();
} */

/*void LargestWordAvailable (string OriginalString) { another old function attempt
  fstream dbFile;
  list<string> LocalList;
  string LocalString;
  string Longest;
  string LocalRead;

  int len = OriginalString.length();
  int largestlen = 0;

  LocalString = OriginalString;


  dbFile.open(cDATAFILE);

  while (!dbFile.eof()){
    getline(dbFile, LocalRead);
    LocalList.push_back(LocalRead);
    
    for (int i=0; i < LocalList.size(); ++i) {
      if (len >= LocalList[i].length()) {
        for (int i2 = 0; i2 < LocalList[i].length(); ++i2) {
          if (LocalString.find(LocalList[i])) {
            if (LocalString.find(LocalList[i2])) {
              Longest = LocalRead;


            }
          }
        }
      }
    }

    cout << "The Longest Word is " << Longest << endl << endl;



  dbFile.close();
  TimeTaken();
  }
} */

/*void LargestWordAvailable (string OriginalString) { yet another old function attempt
  fstream dbFile;
  string LocalString;
  string LocalString2;
  string LocalString2Mod;
  string Longest;

  int CompLen;
  int CompLen2;
  int CommonChar = 0;
  int CommonCharTemp = 0;

  CompLen = OriginalString.length();

  dbFile.open(cDATAFILE);
  
  LocalString = ToLower(OriginalString);
  LocalString = OrderWord(LocalString);

  while (!dbFile.eof()){
    getline(dbFile, LocalString2);
    
    LocalString2Mod = OrderWord(LocalString2);
    CompLen2 = LocalString2.length();

    if (CompLen2 <= CompLen) {
      for (int i=0; i < LocalString.length(); ++i) {
        for (int i2=0; i2 < LocalString2.length(); ++i2) {
          if (LocalString[i] == LocalString2[i2]) {
            ++CommonChar;
          }
        }
      }
      CommonChar = CommonCharTemp;
      CommonCharTemp = 0;
    }
    if (CommonChar == CompLen * 0.75) {
      Longest = LocalString2Mod;

    }
  }
  cout << "\n\nThe Longest Word Was " << Longest << endl;
  dbFile.close();
  TimeTaken();
} */

void LargestWordAvailable(string OriginalString) { // a function that takes the users input and generates the largest word possible using it
  fstream dbFile; // allows the use of dbfile in the funcion
  string LocalString; // declares the string LocalString
  string LocalString2; // declares the string LocalString2
  string Largest; // declares the string Largest

  int Len = OriginalString.length(); // declares the integer Len and sets it to the length of the string OriginalString
  int Len2; // declares the integer Len2

  int LargestLen = 0; // declares the integer LargestLen and sets it to 0

  bool longest = false; // declares the boolean Longest and sets it to false

  LocalString = OriginalString; // sets the string LocalString to OriginalString

  dbFile.open(cDATAFILE); // opens the word file

  while (!dbFile.eof()) { // a loop that reads through the word file
    getline(dbFile, LocalString2); // gets the current line of the file and stores it in the string LocalString2
    Len2 = LocalString2.length(); // sets the integer Len2 to the length of the word currently being read
    for (int i=0; i < Len2; ++i) { // a loop that compares lengths of strings
      if (Len >= Len2) { // checks if the integer Len is > = Len2
        if (LargestLen <= Len2) { // checks if LargestLen < = Len2 
          for (int i2 = 0; i2 < Len2; ++i2) { // a loop that checks Len2
            longest = true; // sets the boolean Longest to true

            unsigned Common = 0; // declares an unsigned value Common and sets it to 0
            for (unsigned i = 0; i < LocalString.length(); ++i) { // a loop that checks the length of LocalString
              if (tolower(LocalString[i]) == tolower(LocalString2[i])) { // checks if the current character (in lowercase) being read in the string LocalString is the same as the current character (in lowercase) being read in the string LocalString2
                Common++; // increments the integer Common (common characters)
              }
            }
            if (Common >= Len * 0.8) { // checks if the number of common characters if > = 80% of the length of OriginalString (I intepretted Most Of as approx 80% of the characters)
              Largest = LocalString2; // sets the string Largest to the contents of LocalString2
            }
          }
        }
      }
    }
  }
  if (longest == true) { // if the boolean Longest is true
    LargestLen = Largest.length(); // set the integer LargestLen to the length of the string Largest

    cout << "\n\nThe Largest Word Was " << Largest << endl; // prints the largest word to the console
  }

  else { // if the boolean Longest isnt true 
    cout << "\n\nSorry, no word could be constructed using the current word or phrase!" << endl; // prints an error message to the console
  }
  dbFile.close(); // closes the word file
  TimeTaken(); // prints the time taken in seconds into the console
}

void FindAll3LetterAnagrams() { // a function that finds all the 3 letter words in the current word file
  fstream dbFile; // allows the use of dbFile in the current function
  string LocalString; // declares the string LocalString
  string LocalAnagram; // declares the string LocalAnagram
  string FileStart; // declares the string FileStart

  list<string> LocalList; // Declares the list LocalList
  
  int len; // declares the integer Len
  int Count = 0; // declares the integer Count and sets it to 0
  bool LocalBool = false; // declares the boolean value LocalBool and sets it to false

  dbFile.open(cDATAFILE); // opens the current words file

  while (!dbFile.eof()) { // a loop that is true while the file is open
    getline(dbFile, LocalString); // gets the current line being read and stores the contents in the string LocalString

    len = LocalString.length(); // sets the integer Len to the length of the string LocalString

    if (len == 3) { // checks if the the value stored in the integer Len is 3
      ++Count; // increments the integer Count
      LocalList.push_back(LocalString); // stores the current contents of LocalString to the list LocalList
    }

     if (LocalList.size() > 0) { // checks if there are any strings stored in the list LocalList
        LocalBool = true; // sets the boolean LocalBool to true
      }
  }
   if (LocalBool == true) { // checks if the boolean LocalBool is true
      cout << "\n\nThere are " << Count << " 3 letter anagrams in the current file:" << endl << endl; // prints the number of anagrams found to the console
      for (auto word = LocalList.begin(); word != LocalList.end(); word++){ 
      cout << *word << ", "; // prints each anagram found to the console separated by a comma
      }
    }
  else {
    cout << "\n\nNo 3 letter anagrams were found!" << endl; // if bool LocalBool isnt true then an error message is printed 

  }
  dbFile.close(); // closes the current word file
  TimeTaken(); // prints the time taken into the console
}

void FindAll5LetterAnagrams() { // a function that scans through a list of words and print out all the 5 letter words in the list
  fstream dbFile; // allows the use of dbFile in the function
  string LocalString; // declares the string LocalString
  string LocalAnagram; // declares the string LocalAnagram
  string FileStart; // declares the string FileStart

  list<string> LocalList; // declares the list LocalList
  
  int len; // declares the integer len
  int Count = 0; // declares the integer Count and sets it to 0
  bool LocalBool = false; // declares the boolean LocalBool and sets it to false

  dbFile.open(cDATAFILE); // opens the currently selected words file

  while (!dbFile.eof()) { // a loop that runs as long as its not the end of the file
    getline(dbFile, LocalString); // gets the current line of the file being read and stores it into the string LocalString

    len = LocalString.length(); // sets the integer Len to the length of the string LocalString

   // cout << len << endl; used to check if loop was working during debugging

    if (len == 5) { // checks if the integer len is 5
      ++Count; // increments the count
      LocalList.push_back(LocalString); // stores the current contents of LocalString into the list LocalList
    }

     if (LocalList.size() > 0) { // checks if the list LocalList isnt empty
        LocalBool = true; // sets the bool LocalBool to true
      }
  }
   if (LocalBool == true) { // if the boolean LocalBool is true
      cout << "\n\nThere are " << Count << " 5 letter anagrams in the current file:" << endl << endl; // prints the number of anagrams found to the console
      for (auto word = LocalList.begin(); word != LocalList.end(); word++){ 
      cout << *word << ", "; // prints all the anagrams found to the console separated by a comma
      }
    }
  else { // if bool LocalBool is false 
    cout << "\n\nNo 5 letter anagrams were found!" << endl; // prints error message to console

  }
  dbFile.close(); // closes current word file
  TimeTaken(); // prints the time taken to the console
}

void Menu(void) { //This function displays a menu to the user with which they can make choices of which functions to run
  string CurrentString; // a local string that will be used throughout this function
  string ModifiedString; // another local string that will also be used in this function

  int MenuOption; // declares the integer "MenuOption"

  do { // Starts a loop that will be repeated endlessly
    cout << "\nC++ Anagram Solver Challenge!" << endl << endl; // prints the title into the menu
    cout << "\t1. Enter a word or phrase (currently is: " << CurrentString << ")." << endl;
     // prints the first menu option into the console, this will execute GetWord when the number 1 is entered
    cout << "\t2. Find anagrams of the current word or phrase" << endl;
    // prints the 2nd menu option into the console that will find anagrams of the current word or phrase
    cout << "\t3. Find the largest word containing (most of) these letters." << endl;
    // 3rd menu option that will find the largest word using the letters of the current word or phrase
    cout << "\t4. Find all possible 3 letter words that are also anagrams." << endl;
    // 4th menu option that finds all 3 letter words in the current file
    cout << "\t5. Find all possible 5 letter words that are also anagrams." << endl << endl;
    // 5th menu option that finds all 5 letter words in the current file
    cout << "\t0. Quit " << endl; // prints the final menu option into the console, this will execute the quit function when the number 0 is entered

    cout << "\nPlease enter a number (1 - 5 or 0 to quit): ";
    // prompts the user to enter a number

  bool num = false; // the boolean num being declared and set to false

    while (num == false){ // a loop that checks if the number inputted in between 0 and 6
      cin >> MenuOption; // tells the console to listen for the users input and then store what they enter in the "MenuOption" integer

      if ((MenuOption < 0)|(MenuOption > 5)){ // if the users input is less than 0 or greater than 6 they are given an error message
        cout <<  " that is not a valid selection!\n"; //error message is printed to console

        cout << "\nPlease enter a number (1 - 5 or 0 to quit): "; //prints the initial value to console so they may try again
      }

      else { //provides the counter arguement that when the statement isnt met this is executed instead
        num = true; // sets num to true and breaks the loop
      }
    }
    
    switch(MenuOption) { // a switch statement that changes what function is run when certain keys are pressed
      cout << "Please enter a valid number!";
      break;

      case 1: // option 1, runs GetWord when the number 1 is entered into the console
        CurrentString = GetWord(); // stores the output of GetWord into the string "CurrentString"
        break; //used to prevent all of the menu options being true at the same time and thus ensures that the switch statement works

      case 2:
        FindAnagram(CurrentString); // option 2 : runs the find anagram function using the users inputted work

        break;//used to prevent all of the menu options being true at the same time and thus ensures that the switch statement works

      case 3:
        LargestWordAvailable(CurrentString); // options 3, finds the longest word made from the letter contained in the current word or phrase

        break;//used to prevent all of the menu options being true at the same time and thus ensures that the switch statement works

      case 4:
        FindAll3LetterAnagrams(); // option 4, finds all 3 letter anagrams in the current file

        break;//used to prevent all of the menu options being true at the same time and thus ensures that the switch statement works

      case 5:
        FindAll5LetterAnagrams(); // option 5, finds all 5 letter anagrams in the current word file

        break;//used to prevent all of the menu options being true at the same time and thus ensures that the switch statement works
      
      case 0:
        QuitNow(); // quits the program

        break;//used to prevent all of the menu options being true at the same time and thus ensures that the switch statement works
}
  } while(true); // gives the loop conditions to break the loop, while true ensures that the loop will essentially last forever

}

int main() { // the function required for the code to run, will automatically be executed

  ReadFile(); // reads the file 

  TimeTaken(); // displays the time taken for the program to read the file
  
  Menu(); // executes the Menu function when the Main function is run
}

/*
------------------------------------------------------------------------------------

Test Log

22/03/19 Tested the GetWord, ToLower and OrderWord functions using the menu function and several different string inputs. expected the Getword string to recieve user input and display it in the menu options, ToLower was expected to convert the user inputted string to lower case and OrderWord was expected to order the characters in the users inputted string into alphabetical order. The getword function did in fact request user input and then store it so that it may be used later, the ToLower function converted the input into lower case and the OrderWord function ordered all characters into alphabetical order. Tested with several string inputs and multiple times. PASSED
22/03/19 Tested the FindAnagram function using the GetWord and Menu functions. This function is expected to retrieve all anagrams of the users inputted string and then print them into the console. Tested with the string "fylngi" and the word "flying" was outputted. Also tested with several other strings. PASSED
22/03/19 Tested the Longest word function using the GetWord and Menu functions. This function is expected to create the longest word possible using the characters in the users inputted string. I tested this with the string "ynigSp" and the word "spying" was printed into the console, also tested that the fail condition works (when the program cannot find an anagram of the inputted string) with several strings. PASSED
23/03/19 Tested the FindAll3LetterAnagrams function. This function is expected to scan through all the words in the word file and print out all the 3 letter words. Tested using the 75k pre submission file and over 650 results were printed into the console. All words are 3 letters long. PASSED
23/03/19 Tested the FindAll5LetterAnagrams function using the Menu function. This functions is expected to scan through all words located in the words file and then print out all words that are 5 letters long. Tested using the 75k pre submission file and over 4700 words were output into the console. checked over these words and determined that they're all 5 letters long. PASSED

-------------------------------------------------------------------------------------

*/
