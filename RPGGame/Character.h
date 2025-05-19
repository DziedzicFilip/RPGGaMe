#pragma once
#include <string>
#include <random>
#include <iostream>

/**
 * @file Character.h
 * 
 * @brief Abstrakcyjna klasa bazowa dla wszystkich postaci w grze.
 * 
 * Ta klasa zawiera podstawowe właściwości i metody wspólne dla wszystkich postaci
 * w grze, takie jak gracz, towarzysz, NPC i przeciwnicy. Zawiera również
 * implementację mechanizmu testów percepcji opartego na instrukcjach z pliku instructions.md.
 * 
 * @author Twój Zespół
 * @date Maj 2025
 */
class Character
{
public:
    /**
     * @brief Konstruktor z parametrami dla postaci
     * 
     * @param name Imię postaci
     * @param health Punkty życia
     * @param strength Siła (wpływa na obrażenia fizyczne)
     * @param intelligence Inteligencja (wpływa na testy percepcji)
     * @param dexterity Zręczność (wpływa na uniki i testy percepcji)
     * @param luck Szczęście (wpływa losowo na różne testy)
     */
    Character(std::string name, int health, int strength, int intelligence, int dexterity, int luck);
    virtual ~Character() = default;
    
    // Gettery - pobieranie wartości atrybutów
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getStrength() const { return strength; }
    int getIntelligence() const { return intelligence; }
    int getDexterity() const { return dexterity; }
    int getLuck() const { return luck; }
    int getLevel() const { return level; }
    
    // Settery - ustawianie wartości atrybutów
    void setHealth(int newHealth) { health = newHealth > 0 ? newHealth : 0; }
    void increaseLevel() { level++; }
    
    // Metody wirtualne do przesłonięcia przez klasy pochodne
    virtual void attack(Character& target) = 0;  // Atak na inną postać
    virtual void defend() = 0;                  // Obrona
    virtual void useItem(int itemId) = 0;       // Używanie przedmiotu
    
    /**
     * @brief Test percepcji oparty na instrukcjach z instructions.md
     * 
     * Test percepcji jest zależny od inteligencji, zręczności i szczęścia.
     * Różne progi sukcesu są używane w różnych aktach gry:
     * - 15+ w Akcie 1 (Las Cieni)
     * - 12+ w Akcie 2 (Wioska Zamarłych)
     * 
     * @return int Wynik rzutu percepcji
     */
    int perceptionTest();
    
    /**
     * @brief Wyświetla statystyki postaci
     */
    void displayStats() const;
    
protected:
    std::string name;        // Imię postaci
    int health;              // Punkty życia
    int strength;            // Siła
    int intelligence;        // Inteligencja
    int dexterity;           // Zręczność
    int luck;                // Szczęście
    int level;               // Poziom postaci (zaczyna od 1)
    
    // Generator liczb losowych do rzutów kośćmi
    std::mt19937 rng;
};
