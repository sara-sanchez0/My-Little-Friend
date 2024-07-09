#ifndef BUNNY_H
#define BUNNY_H
#include "Pet.h"
#include <string>
using namespace std;

class Bunny : public Pet {
  public:
    Bunny(string name);
    Bunny(string name, int hunger, int happiness, int energy, int skill);

    void Feed() override;
    void PlayWith() override;
    void LetRest() override;
    void Train() override;
    void Compete() override;
    void Image() const override;
};

#endif