#pragma once
#include <string>
#include "Character.h"

class Potion {
public:
    enum class Type { Health, Mana };

private:
    Type type;
    double amount;

public:
    Potion(Type type, double amount);

    Type getType() const;
    double getAmount() const;

    // Przywraca HP lub man� postaci
    void use(Character& character) const;
};
