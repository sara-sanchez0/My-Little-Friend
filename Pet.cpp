#include "Pet.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

Pet::Pet(string inName) {
  name = inName;
  hunger = 50;
  happiness = 50;
  energy = 50;
  skill = 0;
}
Pet::Pet(string inName, int inHunger, int inHappiness, int inEnergy, int inSkill) { 
  name = inName;
  hunger = inHunger;
  happiness = inHappiness;
  energy = inEnergy;
  skill = inSkill;
}

void Pet::DisplayStatus() {
  FixBounds();
  cout << endl << "  " << name << "'s Status:  " << endl;
  cout << "  >    Hunger: " << hunger << "    " << endl;
  cout << "  >    Happiness: " << happiness  << " " << endl;
  cout << "  >    Energy: " << energy  << "    " << endl;
  cout << "  >    Skill: " << skill << "      " << endl << endl;

  if (hunger < 30) {
    cout << "  Uh oh! " << name << " is really hungry! Please feed them!" << endl;
  }
  if (happiness < 30) {
    cout << "  " << name << " is feeling down! Please play with them!" << endl;
  }
  if (energy < 30) {
    cout << "  " << name << " is very tired. Maybe they need some sleep!" << endl;
  }
  
}
void Pet::ActionMenu() { 
  char choice;

  DisplayMenu();
  
  cin >> choice;
  while (choice != 'q') {
    switch (choice) {
      case 'f': 
        Feed();
        cin >> choice;
        break;
      case 'p': 
        PlayWith();
        cin >> choice;
        break;
      case 'e': 
        LetRest();
        cin >> choice;
        break;
      case 't': 
        Train();
        cin >> choice;
        break;
      case 'c': 
        Compete();
        cin >> choice;
        break;
      case 'n':
        NextHour();
        if (Lose()) {
          choice = 'q';
        }
        else {
          cin >> choice;
        }
        break;
      case 's':
        SaveData();
        cin >> choice;
        break;
      default:
        cout << "  Please select a valid option" << endl;
        cin >> choice;
    }
  }
}
void Pet::DisplayMenu() {
  DisplayStatus();
  cout << endl;
  cout << "  What would you like to do with " << name << "? :)" << endl;
  cout << "    f - Feed " << endl;
  cout << "    p - Play " << endl;
  cout << "    e - Sleep " << endl;
  cout << "    t - Train " << endl;
  cout << "    c - Compete " << endl << endl;
  cout << "    n - Skip to Next Hour" << endl;
  cout << "    s - Save Game" << endl;
  cout << "    q - Quit" << endl;
}
void Pet::NextHour() {
  char choice;
  
  srand(time(0));
  
  hunger-=20;
  happiness-=20;
  energy-=20;
  
  if (rand() % 3 == 0) {
    skill-=1;
  }

  cout << "  An hour has passed!" << endl << endl;
  cout << "  Enter any letter key to continue" << endl;
  cin >> choice;
  
  Pet::DisplayMenu();
}
void Pet::FixBounds() {
  if (hunger < 0) {
    hunger = 0;
  }
  if (happiness < 0) {
    happiness = 0;
  }
  if (energy < 0) {
    energy = 0;
  }
  if (skill < 0) {
    skill = 0;
  }

  if (hunger > 100) {
    hunger = 100;
  }
  if (happiness > 100) {
    happiness = 100;
  }
  if (energy > 100) {
    energy = 100;
  }
  if (skill > 100) {
    skill = 100;
  }
}

void Pet::Feed() { 
  srand(time(0));
  
  hunger+= 15;
  happiness-= ((rand() % 16) + 5);  // decrease by 5-20
  energy-= ((rand() % 16) + 5);
  
  if (rand() % 3 == 0) {
    skill-=1;
  }
}
void Pet::PlayWith() {
  srand(time(0));
  
  happiness+= 15;
  hunger-= ((rand() % 16) + 3);
  energy-= ((rand() % 16) + 3);
  
  if (rand() % 3 == 0) {
    skill-=1;
  }
}
void Pet::LetRest() {
  srand(time(0));
  
  energy+= 15;
  happiness-= ((rand() % 16) + 5);
  hunger-= ((rand() % 16) + 5);
  
  
  if (rand() % 3 == 0) {
    skill-=1;
  }
}
void Pet::Train() {
  srand(time(0));

  skill+= ((rand() % 6) + 10);   // increase by 10-15
  
  energy-= ((rand() % 21) + 15);     // decrease by 15-35
  happiness-= ((rand() % 21) + 15);
  hunger-= ((rand() % 21) + 15);
}

void Pet::Compete() {
  skill-=1;
  hunger-=20;
  happiness-=20;
  energy-=20;
}
void Pet::Award() {
  cout << "     _______________" << endl;
  cout << "    |@@@@|     |####|" << endl;
  cout << "    |@@@@|     |####|" << endl;
  cout << "    |@@@@|     |####|" << endl;
  cout << "    \\@@@@|     |####/" << endl;
  cout << "     \\@@@|     |###/" << endl;
  cout << "      `@@|_____|##'" << endl;
  cout << "           (O)" << endl;
  cout << "        .-'''''-." << endl;
  cout << "      .'  * * *  `." << endl;
  cout << "     :  *       *  :" << endl;
  cout << "    : ~ F I R S T ~ :" << endl;
  cout << "    : ~ P L A C E ~ :" << endl;
  cout << "     :  *       *  :" << endl;
  cout << "      `.  * * *  .'" << endl;
  cout << "        `-.....-'" << endl;
  cout << "     _______________" << endl;
  cout << "     _______________" << endl;
  cout << "     _______________" << endl;
}
bool Pet::Lose() {
  char choice;
  bool lose = false;

  if (hunger < 5 && happiness < 5 && energy < 5) {
    lose = true;
    cout << endl << "  Your pet is being taken away for neglect." << endl;
    cout << "  You lose! Please take care of your pets properly!" << endl << endl;
    cout << "  Enter any letter key to exit" << endl;
    cin >> choice;
  }
    
  return lose;
}
    
void Pet::SaveData() {
  ofstream fout;
  char choice;

  cout << "  Please enter a file name to save your Pet's data" << endl;
  cin >> fileName;
  fout.open(fileName);

  if (!fout.is_open()) {
    cout << "  Could not open the file! Enter 's' again and try another file name. " << endl;
  }
  else {
    fout << name << endl;
    fout << type << " " << hunger << " " << happiness << " " << energy << " " << skill;
    fout.close();
    cout << "  Your Pet's data was saved successfully!" << endl << endl;
    cout << "  Enter any letter key to continue" << endl;
    cin >> choice;
    DisplayMenu();
  }
}

void Pet::Image() const {}
