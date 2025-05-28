#include "MagicStick.h"

// Deklaracja funkcji z asm
extern "C" int PrintText(const char* text);

MagicStick::MagicStick(const std::string& name, double attackDamage, double magicPower, const std::string&, double value /*scaling*/)
    : Weapon(name, attackDamage, magicPower, "ap",value) {
}

void MagicStick::ignis() const {
    PrintText("Zakl�cie Ignis: Kula ognia wystrzeli�a z magicznej laski i spali�a przeciwnika!");
}

void MagicStick::waterBomb() const {
    PrintText("Zakl�cie WaterBomb: Pot�na bomba wodna uderzy�a we wroga, zalewaj�c go wod�!");
}

void MagicStick::displayStats() const {
    PrintText(("MagicStick: " + name + ", DMG: " + std::to_string(attackDamage) +
        ", Magic: " + std::to_string(magicPower) + ", Scaling: " + scaling).c_str());
}
