#pragma once
#include <string>

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

    
};
