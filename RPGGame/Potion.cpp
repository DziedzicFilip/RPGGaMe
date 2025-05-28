#include "Potion.h"

Potion::Potion(Type type, double amount,double value)
    : type(type), amount(amount),value(value) {
}

Potion::Type Potion::getType() const {
    return type;
}

double Potion::getAmount() const {
    return amount;
}


double Potion::getValue() const {
	return value;
}
