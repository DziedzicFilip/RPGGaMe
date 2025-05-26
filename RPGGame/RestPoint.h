#pragma once
#include <string>
#include "Character.h"

class RestPoint {
private:
    std::string name;

public:
    RestPoint(const std::string& name);

    const std::string& getName() const;
    void restoreEndurance(Character& hero, int value) const;
    void restoreHP(Character& hero, double value) const;
    void restoreMana(Character& hero, double value) const;
    void dialogue(Character& hero1, Character& hero2, const std::string& text1, const std::string& text2) const;
};
