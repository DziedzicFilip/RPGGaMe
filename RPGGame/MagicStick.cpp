#include "MagicStick.h"

// Deklaracja funkcji z asm
extern "C" int PrintText(const char* text);

MagicStick::MagicStick(const std::string& name, double attackDamage, double magicPower, const std::string&, double value /*scaling*/)
    : Weapon(name, attackDamage, magicPower, "ap",value) {
}

void MagicStick::ignis() const {
    PrintText("Zaklêcie Ignis: Kula ognia wystrzeli³a z magicznej laski i spali³a przeciwnika!");
}

void MagicStick::waterBomb() const {
    PrintText("Zaklêcie WaterBomb: Potê¿na bomba wodna uderzy³a we wroga, zalewaj¹c go wod¹!");
}

void MagicStick::displayStats() const {
    PrintText(("MagicStick: " + name + ", DMG: " + std::to_string(attackDamage) +
        ", Magic: " + std::to_string(magicPower) + ", Scaling: " + scaling).c_str());
}
