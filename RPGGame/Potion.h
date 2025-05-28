#pragma once
#include <string>

class Potion {
public:
    enum class Type { Health, Mana };

private:
    Type type;
    double amount;
    double value;

public:
    Potion(Type type, double amount, double value);

    Type getType() const;
    double getAmount() const;
	double getValue() const;

    
};
