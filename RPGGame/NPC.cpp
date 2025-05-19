#include "NPC.h"
#include <iostream>
#include <random>

extern "C" int AddNumbers(int a, int b); // Import assembly function

NPC::NPC(std::string name, int health, int strength, int intelligence, int dexterity, int luck, NPCType type)
    : Character(name, health, strength, intelligence, dexterity, luck), type(type)
{
    // Initialize dialogues based on NPC type
    if (type == COMPANION) {
        dialogues.push_back("Chcesz? Znalazłem przy strumieniu. Nie śmierdzi aż tak bardzo, jak wygląda.");
        dialogues.push_back("Zawsze za tobą, stary.");
        dialogues.push_back("Te grzyby są chyba jadalne... chyba.");
    }
    else if (type == MERCHANT) {
        dialogues.push_back("Mam coś, co może ci pomóc.");
        dialogues.push_back("Tylko najlepsze towary dla ciebie.");
        dialogues.push_back("Znalazłem coś, co może Ci pomóc.");
    }
}

void NPC::attack(Character& target)
{
    // Basic attack implementation for NPCs
    if (type == COMPANION) {
        // Companion attacks with strength-based damage
        std::uniform_int_distribution<int> d10(1, 10);
        int damage = AddNumbers(strength / 2, d10(rng));
        
        std::cout << name << " atakuje i zadaje " << damage << " obrażeń!" << std::endl;
        
        int targetHealth = target.getHealth() - damage;
        target.setHealth(targetHealth > 0 ? targetHealth : 0);
    }
}

void NPC::defend()
{
    // Basic defense implementation
    std::cout << name << " przyjmuje postawę obronną." << std::endl;
}

void NPC::useItem(int itemId)
{
    // Basic implementation for using items
    std::cout << name << " używa przedmiotu." << std::endl;
}

void NPC::speak(const std::string& dialogueKey)
{
    // For now, just pick a random dialogue from the list
    if (!dialogues.empty()) {
        std::uniform_int_distribution<int> distribution(0, dialogues.size() - 1);
        int index = distribution(rng);
        std::cout << name << ": \"" << dialogues[index] << "\"" << std::endl;
    }
    else {
        std::cout << name << " nie ma nic do powiedzenia." << std::endl;
    }
}

std::string NPC::gatherMushroom()
{
    // Companion gathers mushrooms - referenced in instructions.md
    if (type == COMPANION) {
        std::string mushroomTypes[] = {
            "fioletowy grzyb z czerwonymi porami",
            "brązowy kapelusz z białym trzonem",
            "mały czerwony grzyb z białymi kropkami",
            "blady grzyb o błękitnym odcieniu",
            "zielonkawy grzyb z czarnym trzonem"
        };
        
        std::uniform_int_distribution<int> distribution(0, 4);
        int index = distribution(rng);
        
        std::cout << name << " znalazł " << mushroomTypes[index] << "." << std::endl;
        return mushroomTypes[index];
    }
    return "";
}

int NPC::rollMushroomEffect()
{
    // Roll d6 for mushroom effect as per instructions.md
    // 1-2: Trujący (-1HP, -1 do następnego testu percepcji)
    // 3-4: Bez efektu
    // 5-6: Uczucie jasności (+1 do następnego testu percepcji)
    std::uniform_int_distribution<int> d6(1, 6);
    return d6(rng);
}
	

