#pragma once
#include "Character.h"
#include <string>
#include <random>

/**
 * @file Companion.h
 * 
 * @brief Klasa reprezentująca towarzysza (przydupasa) głównego bohatera.
 * 
 * Ta klasa implementuje postać towarzysza, który podróżuje z graczem. Zgodnie
 * z instructions.md, towarzysz ma specjalne funkcje związane z grzybami, a także
 * system lojalności. Towarzysz może wspierać gracza w walce, znajdować grzyby
 * o różnych efektach, oraz rozwijać relację z graczem poprzez system lojalności.
 * 
 * @author Twój Zespół
 * @date Maj 2025
 */
class Companion : public Character 
{
public:
    /**
     * @brief Konstruktor klasy Companion
     * 
     * @param name Imię towarzysza
     * @param health Punkty życia
     * @param strength Siła
     * @param intelligence Inteligencja
     * @param dexterity Zręczność
     * @param luck Szczęście
     */
    Companion(std::string name, int health, int strength, int intelligence, int dexterity, int luck);

    // Przesłonięte metody z klasy bazowej
    void attack(Character& target) override;
    void defend() override;
    void useItem(int itemId) override;
    
    /**
     * @brief Funkcja do zbierania grzybów przez towarzysza
     * 
     * Zgodnie z instructions.md, towarzysz może zbierać grzyby, które mają różne
     * efekty po zjedzeniu. To jedna z głównych mechanik związanych z tą postacią.
     * 
     * @return std::string Nazwa znalezionego grzyba
     */
    std::string gatherMushroom();
    
    /**
     * @brief Rzut k6 na efekt zjedzenia grzyba
     * 
     * Zgodnie z instructions.md, rzut k6 określa efekt zjedzenia grzyba:
     * - 1-2: Trujący (-1HP, -1 do następnego testu percepcji)
     * - 3-4: Bez efektu
     * - 5-6: Uczucie jasności (+1 do następnego testu percepcji)
     * 
     * @return int Wynik rzutu k6 (1-6)
     */
    int rollMushroomEffect();
    
    /**
     * @brief System lojalności towarzysza
     * 
     * Funkcje związane z lojalnością towarzysza wobec gracza. Lojalność może
     * się zmieniać w zależności od wyborów gracza i wpływać na zachowanie towarzysza.
     */
    int getLoyalty() const { return loyalty; }
    void increaseLoyalty(int amount) { loyalty += amount; if (loyalty > 100) loyalty = 100; }
    void decreaseLoyalty(int amount) { loyalty -= amount; if (loyalty < 0) loyalty = 0; }
    
    /**
     * @brief Funkcja obsługująca dialogi towarzysza
     * 
     * @param dialogKey Klucz dialogu do wyświetlenia
     */
    void speak(const std::string& dialogKey);

private:
    int loyalty;  // Poziom lojalności towarzysza (0-100)
    std::vector<std::string> dialogues; // Kolekcja dialogów towarzysza
};
