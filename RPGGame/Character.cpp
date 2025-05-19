#include "Character.h"
#include <ctime>

// Importujemy funkcje z assembly
extern "C" int AddNumbers(int a, int b);

/**
 * @brief Konstruktor klasy Character
 * 
 * Inicjalizuje wszystkie statystyki postaci i generator liczb losowych.
 */
Character::Character(std::string name, int health, int strength, int intelligence, int dexterity, int luck) 
    : name(name), health(health), strength(strength), intelligence(intelligence), dexterity(dexterity), luck(luck), level(1)
{
    // Inicjalizacja generatora liczb losowych z użyciem aktualnego czasu jako ziarna
    rng.seed(static_cast<unsigned int>(std::time(nullptr)));
}

/**
 * @brief Implementacja testu percepcji
 * 
 * Test percepcji opiera się na rzucie d20 plus modyfikatorach z inteligencji,
 * zręczności i szczęścia postaci. Funkcja wykorzystuje assemblerową funkcję
 * AddNumbers do obliczania bonusu z inteligencji.
 * 
 * Zgodnie z instructions.md, w różnych scenach są różne progi sukcesu:
 * - 15+ dla wykrycia przeciwników w lesie (Akt 1)
 * - 12+ dla znalezienia ukrytych przedmiotów w wiosce (Akt 2)
 * 
 * @return int Całkowity wynik testu percepcji
 */
int Character::perceptionTest()
{
    // Używamy funkcji assemblerowej do dodawania bonusów ze statystyk
    int intelligenceBonus = AddNumbers(0, intelligence / 3); // Każde 3 punkty inteligencji dają +1 do percepcji
    
    // Zręczność wpływa na percepcję (refleks, świadomość)
    int dexterityBonus = dexterity / 4;
    
    // Szczęście może dać mały losowy bonus
    std::uniform_int_distribution<int> luckDistribution(0, luck / 2);
    int luckBonus = luckDistribution(rng);
    
    // Rzut k20 jako bazowy test percepcji
    std::uniform_int_distribution<int> d20(1, 20);
    int baseRoll = d20(rng);
    
    // Całkowity wynik percepcji
    int totalPerception = baseRoll + intelligenceBonus + dexterityBonus + luckBonus;
    
    // Wyświetlenie szczegółów testu percepcji
    std::cout << name << "'s Perception Test:" << std::endl;
    std::cout << "Base roll (d20): " << baseRoll << std::endl;
    std::cout << "Intelligence bonus: +" << intelligenceBonus << std::endl;
    std::cout << "Dexterity bonus: +" << dexterityBonus << std::endl;
    std::cout << "Luck bonus: +" << luckBonus << std::endl;
    std::cout << "Total perception score: " << totalPerception << std::endl;
    
    return totalPerception;
}

/**
 * @brief Wyświetla statystyki postaci
 * 
 * Prosty interfejs tekstowy wyświetlający wszystkie statystyki danej postaci.
 */
void Character::displayStats() const
{
    std::cout << "===== " << name << " =====" << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Strength: " << strength << std::endl;
    std::cout << "Intelligence: " << intelligence << std::endl;
    std::cout << "Dexterity: " << dexterity << std::endl;
    std::cout << "Luck: " << luck << std::endl;
    std::cout << "===================" << std::endl;
}
