#ifndef PET_H
#define PET_H
#include <iostream>
#include <string>
  
using namespace std;

class Pet {
  public:
    Pet(string name);
    Pet(string name, int hunger, int happiness, int energy, int skill);

    void DisplayStatus();
    void ActionMenu();
    void DisplayMenu();
    void NextHour();
    void FixBounds();

    virtual void Feed();
    virtual void PlayWith();
    virtual void LetRest();
    virtual void Train();

    virtual void Compete();
    void Award();
    bool Lose();
    void SaveData();

    virtual void Image() const = 0;

  protected:
    string name;    
    string fileName;
    int type;
    int hunger;
    int happiness;
    int energy;
    int skill;
};

#endif
 