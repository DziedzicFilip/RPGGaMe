#include "NPC.h"


extern "C" int PrintText(const char* text);

NPC::NPC(const std::string& name, Equipment equipment)
    : name(name), equipment (equipment){
}

const std::string& NPC::getName() const {
    return name;
}

Equipment& NPC::getEquipment() {
    return equipment;
}

void NPC::dialogue(const std::string& text) const {
    PrintText(text.c_str());
}
