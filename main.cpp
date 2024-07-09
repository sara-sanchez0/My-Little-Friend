#include "Pet.h"
#include "Cat.h"
#include "Bunny.h"
#include "Duck.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void PetChoice();   // used for player decision on Pet Type and Name
void LoadData();   // used to load Pet info from a file

int main() {
  string fileName;
  char choice;
  
  int type;
  string name;

  // Main Menu
  cout << "   /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\" << endl;
  cout << "  /\\ Welcome to My Little Friend! /\\" << endl;
  cout << "  \\/                              \\/" << endl;
  cout << "  /\\ Select from the following:   /\\" << endl;
  cout << "  \\/   n - Start New              \\/" << endl;
  cout << "  /\\   l - Load Pet               /\\" << endl;
  cout << "  \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << endl;


  bool validChoice = false;
  while (!validChoice) {    // used execute menu options
    cin >> choice;
    switch (choice) {
      case 'n':    // Start New 
        validChoice = true;
        PetChoice();  // let player choose pet type and name
        break;
        
      case 'l':
        validChoice = true;
        LoadData();       // load Pet data from a file, call constructors and ActionMenu()
        break;            
                              
      default:
        cout <<         "Please Select from the following:" << endl;   // ask for user input again 
        cout <<         "   n - Start New " << endl;
        cout <<         "   l - Load Pet " << endl;
        validChoice = false;
    }
  }  

  // Exit message
  cout << endl << "   /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\" << endl;
  cout << "  | Thank you for playing My Little Friend!  |" << endl;
  cout << "  |           Come back anytime! :)          |" << endl;
  cout << "   \\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << endl;
  
  return 0;
}

void PetChoice() {    // user input for new Pet Type and Name
  int type;
  string name;

  std::cout << R"( 
  /\  Which pet would you like?   /\
  \/    1 - Cat     (Easy)        \/
  \/    2 - Bunny   (Medium)      \/
  \/    3 - Duck    (Hard)        \/  )" << '\n';
  
  cin >> type;

  // verify Pet type selection
  while (type < 0 || type > 3) {
    cout << "Please make a valid selection" << endl;
    cin >> type;
  }

  // name the Pet
  cout << "  Ok! What would you like to name " << endl;
  cout << "  your new friend?" << endl;
  cin >> name;
  cout << endl << "  Let's meet " << name << "!" << endl;
  
  if (type == 1) {
    std::cout << R"(
    /\_/\
   >^.^<.---.
  _'-`-'     )\
 (6--\ |--\ (`.`-.
     --'  --'  ``-' )" << '\n';  
    Cat myCat(name);
    myCat.ActionMenu();
  }
  else if (type == 2) {
    std::cout << R"(
               ((`\
            ___ \\ '--._
         .'`   `'     ^ )
        /    \   '. __.'
       _|    /_  \ \_\_
      {_\______\-'\__\_\ )" << '\n';  
    Bunny myBunny(name);
    myBunny.ActionMenu();
  }
  else if (type == 3) {
    std::cout << R"(
        ,~~.
   ,   (  ^ )>
   )`~~'   (
  (  .__)   )
   `-.____,/ 
    )" << '\n';  
    Duck myDuck(name);
    myDuck.ActionMenu();
  }
}
void LoadData() {    // Loads data from a file and uses that data to call the constructor and ActionMenu() for a saved pet
  int type, hunger, happiness, energy, skill;
  string name, fileName;
  char choice;

  cout << "Please enter the file name to load data from:" << endl;
  cin >> fileName;
  
  ifstream fin;
  fin.open(fileName);

  if (!fin.is_open()) {
    cout << "Could not open file! Please restart the game and try a different file." << endl;
  }
  else {
    getline(fin, name);
    fin >> type >> hunger >> happiness >> energy >> skill;
    cout << "Welcome back, " << name << "!" << endl;
  }

  if (type == 1) {
    std::cout << R"(
    /\_/\
   >^.^<.---.
  _'-`-'     )\
 (6--\ |--\ (`.`-.
     --'  --'  ``-' )" << '\n';  
    Cat myCat(name, hunger, happiness, energy, skill);
    myCat.ActionMenu();
  }
  else if (type == 2) {
    std::cout << R"(
               ((`\
            ___ \\ '--._
         .'`   `'     ^ )
        /    \   '. __.'
       _|    /_  \ \_\_
      {_\______\-'\__\_\ )" << '\n';  
    Bunny myBunny(name, hunger, happiness, energy, skill);
    myBunny.ActionMenu();
  }
  else if (type == 3) {
    std::cout << R"(
        ,~~.
   ,   (  ^ )>
   )`~~'   (
  (  .__)   )
   `-.____,/ 
    )" << '\n'; 
    Duck myDuck(name, hunger, happiness, energy, skill);
    myDuck.ActionMenu();
  }
}