#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class Ingredient {
public:
    Ingredient();
    Ingredient(const std::string& name, double cost);
    std::string getName() const;
    double getCost() const;

private:
    std::string name;
    double cost;
};

#endif // INGREDIENT_H
