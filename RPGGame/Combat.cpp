
#include "Combat.h"
#include "random"
Combat::Combat(Hero& mainHero, Hero& CompanionHero, Enemy& enemy)
    : mainHero(mainHero), CompanionHero(CompanionHero), enemy(enemy) {
}
void Combat::chooseAction(Hero& hero, Enemy& enemy) {
    std::cout << "Wybierz akcjê:\n";
    std::cout << "1. Mocny atak\n";
    std::cout << "2. S³aby atak\n";
	std::cout << "3. Ignis\n";
	std::cout <<"4. Water Bomb\n";
    std::cout << "5. Leczenie\n";

    Equipment& eq = hero.getEquipment();
    bool hasPotion = false;

  
    if (eq.hasPotion()) {
        std::cout << "6. U¿yj mikstury\n";
    }

    int choice;
    std::cin >> choice;
    switch (choice)
    {
	case 1 :  
		hero.heavyAttack(enemy);
		break;  
	case 2:
		hero.lightAttack(enemy);
		break;
	case 3:
		hero.ignis(enemy);
		break;
	case 4:
		hero.waterBomb(enemy);
		break;
	case 5:
		hero.heal(hero);
		break;
    case 6: 
		if (eq.hasPotion()) {
			hero.getEquipment().displayPotions();
			int potionIndex;
			std::cout << "Wybierz miksturê do u¿ycia (0-4): ";
			std::cin >> potionIndex;
			if (potionIndex >= 0 && potionIndex < 5) {
				Potion* potion = eq.getPotion(potionIndex);
				if (potion) {
					hero.setHealthPoints(hero.getHealthPoints() + potion->getAmount());
					eq.removePotion(potionIndex);
				}
				else {
					std::cout << "Nie ma takiej mikstury!\n";
				}
			}
			else {
				std::cout << "Nieprawid³owy indeks mikstury!\n";
			}
		}
		else {
			std::cout << "Nie masz mikstur!\n";
		}
		break;
    default:
        break;
    }
}

void Combat::enemyTurn(Enemy& enemy, Hero& hero) {
	std::cout << enemy.getName()+" atakuje!\n";
	int randomAction = rand() % (4-1)+1; 
	switch (randomAction) {
	case 1:

		std::cout << enemy.getName() + " u¿y³ mocnego ataku!\n";
		hero.setHealthPoints(hero.getHealthPoints() - enemy.heavyAttack());
		break;
	case 2:
		std::cout << enemy.getName() + " u¿y³ s³abego ataku!\n";
		hero.setHealthPoints(hero.getHealthPoints() - enemy.lightAttack());
		break;
	case 3:
		std::cout << enemy.getName() + " u¿y³ specjalnego ataku!\n";
		hero.setHealthPoints(hero.getHealthPoints() - enemy.specialAttack());
		break;
	case 4:
		std::cout << enemy.getName() + " u¿y³ leczenia!\n";
		enemy.heal(20);
		break;
	default:
		std::cout << "Nieznana akcja wroga!\n";
		break;
	}
}
void Combat::CompaionionTurn(Hero& CompanionHero, Enemy& enemy)
{
	std::cout << CompanionHero.getName() + " wykonuje:\n";
	int randomAction = rand() % 7;
	switch (randomAction)
	{
	case 1:
		CompanionHero.heavyAttack();
		break;
	case 2:
		CompanionHero.lightAttack();
		break;
	case 3:
		CompanionHero.ignis();
		break;
	case 4:
		CompanionHero.waterBomb();
		break;
	case 5:
		CompanionHero.heal();
		break;
	default:
		break;
	}
}
void Combat::StartBattle() {
    while (mainHero.getHealthPoints() > 0 && enemy.getHealthPoints() > 0) {
		chooseAction(mainHero, enemy);
		std::cout << enemy.getName() + " HP: " << enemy.getHealthPoints() << "\n";
		enemyTurn(enemy, mainHero);
		std::cout << "Twoje HP: " << mainHero.getHealthPoints() << "\n";
		if (mainHero.getHealthPoints() <= 0) {
			std::cout << "Przegra³eœ walkê!\n";
			break;
		}
		CompaionionTurn(CompanionHero, enemy);
		std::cout << enemy.getName() + " HP: " << enemy.getHealthPoints() << "\n";
		if (enemy.getHealthPoints() <= 0) {
			std::cout << "Wygra³eœ walkê!\n";
			break;
		}
    

    }

}

