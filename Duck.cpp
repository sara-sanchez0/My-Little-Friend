#include "Pet.h"
#include "Duck.h"
#include <string>
using namespace std;


Duck::Duck(string name) : Pet(name) {
  type = 3;
}
Duck::Duck(string inName, int inHunger, int inHappiness, int inEnergy, int inSkill) : Pet(inName, inHunger, inHappiness, inEnergy, inSkill) {
  type = 3;
}

// functions that improve status of Pets
void Duck::Feed() {
  char choice;

  cout << "  What would you like to feed " << name << "?" << endl;
  cout << "    1 - Seeds" << endl;
  cout << "    2 - Vegetable Mix" << endl << endl;
  cout << "    b - Go Back" << endl;

  // two feeding options
  cin >> choice;
  while (choice != 'b') {
    switch (choice) {
    case '1':
      cout << "  Yummy! " << name << " loves the seeds!" << endl;
      Duck::Image();
      Pet::Feed();
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    case '2':
      cout << "  " << name << " loves the Vegggie Mix! They feel better!" << endl;
      Duck::Image();
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
void Duck::PlayWith() {
  char choice;

  cout << "  How would you like to play with " << name << "?" << endl;
  cout << "    1 - Run around water sprinkler" << endl;
  cout << "    2 - Swim in kiddie pool" << endl << endl;
  cout << "    b - Go Back" << endl;

  // two playing options
  cin >> choice;
  while (choice != 'b') {
    switch (choice) {
    case '1':
      cout << "  Yay! " << name << " loved running around the sprinkler!" << endl;
      Duck::Image();
      Pet::PlayWith();
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    case '2':
      cout << "  What great times! " << name << " loved swimming with you!" << endl;
      Duck::Image();
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
void Duck::LetRest() {
  char choice;

  cout << "  How should " << name << " get rest?" << endl;
  cout << "    1 - Relax in a hidden pond" << endl;
  cout << "    2 - Sleep in lake" << endl << endl;
  cout << "    b - Go Back" << endl;

  // two resting options
  cin >> choice;
  while (choice != 'b') {
    switch (choice) {
    case '1':
      cout << "  " << name << " appreciated the calm of the pond." << endl;
      Duck::Image();
      Pet::LetRest();
      cout << "  Enter any letter key to continue" << endl;
      cin >> choice;
      choice = 'b';
      break;
      
    case '2':
      cout << "  Quack! " << name << " just had the nicest sleep ever." << endl;
      Duck::Image();
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
void Duck::Train() {   // improve skill
  char key;

  if (hunger < 75 || happiness < 75 || energy < 75) {
    cout << "  " << name << " is not in the mood to train right now." << endl;
    cout << "Ducks need 75 or higher in their stats to feel like training!" << endl;
    cout << "Press any letter key to continue" << endl;
    cin >> key;
  } 
  else {
    Pet::Train();
    cout << "  " << name << " has improved their skills!" << endl;
    Duck::Image();
    cout << "  Press any letter key to continue" << endl;
    cin >> key;
  }
  Pet::DisplayMenu();
}

// can lead to winning the game 
void Duck::Compete() {
  char choice;

  if (hunger < 90 || happiness < 90 || energy < 90) {
    cout << name << " is not feeling well enough to compete! "
    "(Ducks may compete with any skill level, but require 90 or higher on other stats to compete)." << endl;
  }
  else {
    if (skill > 98) {
      cout << "  Congratulations! " << name << " won First Place!" << endl;
      Pet::Award();
      cout << endl;
      cout << "  You and " << name << " have won the game." << endl;
      cout << "  However, you may continue to play! :)" << endl;
      Duck::Image();
        
      skill-=1;
      hunger-=10;
      happiness-=10;
      energy-=10;
    }
    else if (skill > 94) {
      cout << "  Congratulations on 2nd place! " << name << " was so close!" << endl;
      Pet::Compete();
    }
    else if (skill > 90) {
      cout << "  Congratulations on 3rd Place!" << name << " is one of the best!" << endl;
      Pet::Compete();
    }
    else {
      cout << "  " << name << " did not place in the top 3, but they still did a fantastic job!" << endl;
      Pet::Compete();
    }
  }
  cout << endl << "  Enter any letter key to continue" << endl;
  cin >> choice;
  Pet::DisplayMenu();
}

void Duck::Image() const {
  std::cout << R"(
        ,~~.
   ,   (  ^ )>
   )`~~'   (
  (  .__)   )
   `-.____,/ 
    )" << '\n';  
}