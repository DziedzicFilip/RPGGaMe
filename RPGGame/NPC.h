#pragma once
#include "Character.h"
#include <string>
#include <vector>

// NPC class extending from Character
class NPC : public Character 
{
public:
    enum NPCType {
        COMPANION,    // Follower that can assist in battle
        MERCHANT,     // Trader that sells items
        QUEST_GIVER   // Gives quests and information
    };

    NPC(std::string name, int health, int strength, int intelligence, int dexterity, int luck, NPCType type);
    
    // Override base class virtual methods
    void attack(Character& target) override;
    void defend() override;
    void useItem(int itemId) override;
    
    // NPC specific methods
    void speak(const std::string& dialogueKey);
    bool isCompanion() const { return type == COMPANION; }
    bool isMerchant() const { return type == MERCHANT; }
    
    // Companion mushroom gathering ability
    std::string gatherMushroom();
    int rollMushroomEffect(); // Roll d6 for mushroom effect
    
private:
    NPCType type;
    std::vector<std::string> dialogues;
};

