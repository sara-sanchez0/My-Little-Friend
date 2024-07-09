#include "Pet.h"
#include "Bunny.h"
#include <string>
using namespace std;


Bunny::Bunny(string name) : Pet(name) {
  type = 2;
}
Bunny::Bunny(string inName, int inHunger, int inHappiness, int inEnergy, int inSkill) : Pet(inName, inHunger, inHappiness, inEnergy, inSkill) {
  type = 2;
}

// functions that improve status of Pets
void Bunny::Feed() {
  char choice;

  cout << "  What would you like to feed " << name << "?" << endl;
  cout << "    1 - Small Carrot" << endl;
  cout << "    2 - HayStack" << endl << endl;
  cout << "    b - Go Back" << endl;

  // two feeding options
  cin >> choice;
  while (choice != 'b') {
    switch (choice) {
    case '1':
      cout << "  Yummy! " << name << " loves the carrot!" << endl;
      Bunny::Image();
      Pet::Feed();
      hunger += 0;
      happiness += 5;
      energy += 5;
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    case '2':
      cout << "  " << name << " loved the HayStack!" << endl;
      Bunny::Image();
      Pet::Feed();
      hunger += 10;
      happiness += 10;
      energy += 10;
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    default:
      cout << "  Please enter a valid choice" << endl;
      cin >> choice;
    }
  }
  Pet::DisplayMenu();
}
void Bunny::PlayWith() {
  char choice;

  cout << "  How would you like to play with " << name << "?" << endl;
  cout << "    1 - Wooden Chew Toy" << endl;
  cout << "    2 - Tunnel System" << endl << endl;
  cout << "    b - Go Back" << endl;

  // two playing options
  cin >> choice;
  while (choice != 'b') {
    switch (choice) {
    case '1':
      cout << "  Yay! " << name << " loved chewing on the wooden toy!" << endl;
      Bunny::Image();
      Pet::PlayWith();
      happiness += 0;
      hunger += 5;
      energy += 5;
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    case '2':
      cout << "  What a fun time! " << name << " loved playing in the tunnels!" << endl;
      Bunny::Image();
      Pet::PlayWith();
      happiness += 10;
      hunger += 10;
      energy += 10;
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    default:
      cout << "  Please enter a valid choice" << endl;
      cin >> choice;
    }
  }
  Pet::DisplayMenu();
}
void Bunny::LetRest() {
  char choice;

  cout << "  How should " << name << " get rest?" << endl;
  cout << "    1 - Small nap on soft grass" << endl;
  cout << "    2 - Cuddle with human (that's you)" << endl << endl;
  cout << "    b - Go Back" << endl;

  // two resting options
  cin >> choice;
  while (choice != 'b') {
    switch (choice) {
    case '1':
      cout << "  " << name << " feels more energized (and soft)!" << endl;
      Bunny::Image();
      Pet::LetRest();
      energy += 0;
      happiness += 5;
      hunger += 5;
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    case '2':
      cout << "  " << name << " feels very hoppy! :)" << endl;
      Bunny::Image();
      Pet::LetRest();
      energy += 10;
      happiness += 10;
      hunger += 10;
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    default:
      cout << "  Please enter a valid choice" << endl;
      cin >> choice;
    }
  }
  Pet::DisplayMenu();
}
void Bunny::Train() {   // improve skill
  char key;

  if (hunger < 75 || happiness < 75 || energy < 75) {
    cout << "  " << name << " is not in the mood to train right now." << endl;
    cout << "  Bunnies need 75 or higher in their stats to feel like training!" << endl;
    cout << "  Press any letter key to continue" << endl;
    cin >> key;
  } 
  else {
    Pet::Train();
    skill += 1;  // increase skill gain for Bunny
    hunger += 5; // reduce impact on Bunny stats
    happiness += 5;
    energy += 5;
    cout << "  " << name << " has improved their skills!" << endl;
    Bunny::Image();
    cout << "  Press any letter key to continue" << endl;
    cin >> key;
  }
  Pet::DisplayMenu();
}

// can lead to winning the game 
void Bunny::Compete() {
  char choice;

  if (hunger < 90 || happiness < 90 || energy < 90) {
    cout << "  " << name << " is not feeling well enough to compete! " << endl;
    cout << "  (Bunnies may compete with any skill level, but" << endl;
    cout << "  require 90 or higher on other stats to compete)." << endl;
  }
  else {
    if (skill > 94) {
      cout << "  Congratulations! " << name << " won First Place!" << endl;
      Pet::Award();
      cout << endl;
      cout << "  You and " << name << " have won the game." << endl;
      cout << "  However, you may continue to play! :)" << endl;
      Bunny::Image();
        
      skill-=1;
      hunger-=10;
      happiness-=10;
      energy-=10;
    }
    else if (skill > 90) {
      cout << "Congratulations on 2nd place! " << name << " was so close!" << endl;
      Pet::Compete();
    }
    else if (skill > 85) {
      cout << "Congratulations on 3rd Place!" << name << " is one of the best!" << endl;
      Pet::Compete();
    }
    else {
      cout << name << " did not place in the top 3, but they still did a fantastic job!" << endl;
      Pet::Compete();
    }
  }
  cout << endl << "  Enter any letter key to continue" << endl;
  cin >> choice;
  Pet::DisplayMenu();
}

void Bunny::Image() const {
  std::cout << R"(
               ((`\
            ___ \\ '--._
         .'`   `'     ^ )
        /    \   '. __.'
       _|    /_  \ \_\_
      {_\______\-'\__\_\ )" << '\n'; 
}


