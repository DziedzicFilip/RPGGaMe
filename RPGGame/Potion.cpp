#include "Potion.h"

Potion::Potion(Type type, double amount)
    : type(type), amount(amount) {
}

Potion::Type Potion::getType() const {
    return type;
}

double Potion::getAmount() const {
    return amount;
}


