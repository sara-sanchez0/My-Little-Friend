#include "Cat.h"
#include "Pet.h"
#include <string>
using namespace std;

// constructors
Cat::Cat(string name) : Pet(name) {
  type = 1;
}
Cat::Cat(string inName, int inHunger, int inHappiness, int inEnergy, int inSkill) : Pet(inName, inHunger, inHappiness, inEnergy, inSkill) {
  type = 1;
}

// functions that improve status of Pets
void Cat::Feed() {
  char choice;

  cout << "  What would you like to feed " << name << "?" << endl;
  cout << "    1 - Cat Treat" << endl;
  cout << "    2 - Chicken" << endl << endl;
  cout << "    b - Go Back" << endl;

  // two feeding options
  cin >> choice;
  while (choice != 'b') {
    switch (choice) {
    case '1':
      cout << "  Yummy! " << name << " loves the snack!" << endl;
      Cat::Image();
      Pet::Feed();
      hunger += 5;
      happiness += 10;
      energy += 10;
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    case '2':
      cout << "  " << name << " loves the chicken! They feel better." << endl;
      Cat::Image();
      Pet::Feed();
      hunger += 15;
      happiness += 15;
      energy += 15;
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
void Cat::PlayWith() {
  char choice;

  cout << "  How would you like to play with " << name << "?" << endl;
  cout << "    1 - Squiggly worm teaser" << endl;
  cout << "    2 - Cat Playground" << endl << endl;
  cout << "    b - Go Back" << endl;

  // two playing options
  cin >> choice;
  while (choice != 'b') {
    switch (choice) {
    case '1':
      cout << "  Yay! " << name << " loved playing with the squiggly worm!" << endl;
      Cat::Image();
      Pet::PlayWith();
      happiness += 5;
      hunger += 10;
      energy += 10;
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    case '2':
      cout << "  What fun! " << name << " loved running around the playground!" << endl;
      Cat::Image();
      Pet::PlayWith();
      happiness += 15;
      hunger += 15;
      energy += 15;
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
void Cat::LetRest() {
  char choice;

  cout << "  How should " << name << " get rest?" << endl;
  cout << "    1 - Nap in the comfiest box to exist" << endl;
  cout << "    2 - Use deep sleep blanket" << endl << endl;
  cout << "    b - Go Back" << endl;

  // two resting options
  cin >> choice;
  while (choice != 'b') {
    switch (choice) {
    case '1':
      cout << "  " << name << " feels more energized!" << endl;
      Cat::Image();
      Pet::LetRest();
      energy += 5;
      happiness += 10;
      hunger += 5;
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    case '2':
      cout << "  Purr-fect! " << name << " feels much better!" << endl;
      Cat::Image();
      Pet::LetRest();
      energy += 15;
      happiness += 15;
      hunger += 15;
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
void Cat::Train() {   // improve skill
  char key;

  if (hunger < 70 || happiness < 70 || energy < 70) {
    cout << "  " << name << " is not in the mood to train right now." << endl;
    cout << "  Cats need 70 or higher in their stats to feel like training!" << endl;
    cout << "  Press any letter key to continue" << endl;
    cin >> key;
  } 
  else {
    Pet::Train();
    skill += 2;  // increase skill gain for Cat
    hunger += 10; // reduce impact on Cat stats
    happiness += 10;
    energy += 10;
    cout << "  " << name << " has improved their skills!" << endl;
    Cat::Image();
    cout << "  Press any letter key to continue" << endl;
    cin >> key;
  }
  Pet::DisplayMenu();
}

// can lead to winning the game 
void Cat::Compete() {
  char choice;
  
  if (hunger < 90 || happiness < 90 || energy < 90) {
    cout << "  " << name << " is not feeling well enough to compete! " << endl;
    cout << "  (Cats may compete with any skill level, but" << endl;
    cout << "  require 90 or higher on other stats to compete)." << endl << endl;
  }
  else {
    if (skill > 90) {
      cout << "  Congratulations! " << name << " won First Place!" << endl;
      Pet::Award();
      cout << endl;
      cout << "  You and " << name << " have won the game." << endl;
      cout << "  However, you may continue to play! :)" << endl << endl;
      Cat::Image();
        
      skill-=1;
      hunger-=10;
      happiness-=10;
      energy-=10;
    }
    else if (skill > 85) {
      cout << "  Congratulations on 2nd place! " << name << " was so close!" << endl;
      Pet::Compete();
    }
    else if (skill > 80) {
      cout << "  Congratulations on 3rd Place!" << name << " is one of the best!" << endl;
      Pet::Compete();
    }
    else {
      cout << "  " << name << " did not place in the top 3, but they still did a cat-tastic job!" << endl;
      Pet::Compete();
    }
  }
  cout << endl << "  Enter any letter key to continue" << endl;
  cin >> choice;
  Pet::DisplayMenu();
}

void Cat::Image() const {
  std::cout << R"(
    /\_/\
   >^.^<.---.
  _'-`-'     )\
 (6--\ |--\ (`.`-.
     --'  --'  ``-' )" << '\n';  
}