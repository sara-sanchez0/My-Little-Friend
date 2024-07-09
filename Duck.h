#ifndef DUCK_H
#define DUCK_H
#include "Pet.h"
#include <string>
using namespace std;

class Duck : public Pet {
  public:
    Duck(string name);
    Duck(string name, int hunger, int happiness, int energy, int skill);

    void Feed() override;
    void PlayWith() override;
    void LetRest() override;
    void Train() override;
    void Compete() override;
    void Image() const override;
};

#endif