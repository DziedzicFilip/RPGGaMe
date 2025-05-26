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

void Potion::use(Character& character) const {
    if (type == Type::Health) {
        character.setHealthPoints(character.getHealthPoints() + amount);
    }
    else if (type == Type::Mana) {
        character.setMana(character.getMana() + amount);
    }
}
