#ifndef CAT_H
#define CAT_H
#include "Pet.h"
#include <string>
using namespace std;

class Cat : public Pet {
  public:
    Cat(string name);
    Cat(string name, int hunger, int happiness, int energy, int skill);

    void Feed() override;
    void PlayWith() override;
    void LetRest() override;
    void Train() override;
    void Compete() override;
    void Image() const override;
};

#endif