
#include "Combat.h"

Combat::Combat(Hero& mainHero, Hero& CompanionHero, Enemy& enemy)
    : mainHero(mainHero), CompanionHero(CompanionHero), enemy(enemy) {
}
int Combat::chooseAction(Hero& hero) {
    std::cout << "Wybierz akcjê:\n";
    std::cout << "1. Mocny atak\n";
    std::cout << "2. S³aby atak\n";
    std::cout << "3. Unik\n";
    std::cout << "4. Leczenie\n";

    Equipment& eq = hero.getEquipment();
    bool hasPotion = false;

  
    if (eq.hasPotion()) {
        std::cout << "5. U¿yj mikstury\n";
    }

    int choice;
    std::cin >> choice;
    return choice;
}
void Combat::StartBattle() {
    while (mainHero.getHealthPoints() > 0 && enemy.getHealthPoints() > 0) {

        if (enemy.getHealthPoints() <= 0) break;


    }

}

