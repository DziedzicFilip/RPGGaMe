#pragma once
#include <string>
#include "Equipment.h"

class NPC {
private:
    std::string name;
    Equipment equipment;

public:
    NPC(const std::string& name);

    const std::string& getName() const;
    Equipment& getEquipment();
    void dialogue(const std::string& text) const;
};
