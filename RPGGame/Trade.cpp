#include "Trade.h"
#include "NPC.h"
#include "Hero.h"

void Trade::StartTrade(NPC& npc, Hero& hero) {
    bool tradeActive = true;
    while (tradeActive)
    {
        std::cout << "Zawartosc twojej sakwy: " << hero.getEquipment().getGold() << std::endl;

        std::cout << "Rozpoczeto handel z " << npc.getName() << "." << std::endl;
        std::cout << "1. Kup bron" << std::endl;
        std::cout << "2. Sprzedaj bron" << std::endl;
        std::cout << "3. Kup miksture" << std::endl;
        std::cout << "4. Sprzedaj miksture" << std::endl;
        std::cout << "5. Zakoncz handel" << std::endl;
        std::cout << "6. Pokaz ekwipunek bohatera" << std::endl;
        std::cout << "7. Pokaz ekwipunek NPC" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            BuyItem(npc, hero);
            break;
        case 2:
            SellItem(npc, hero);
            break;
        case 3:
            BuyPotion(npc, hero);
            break;
        case 4:
            SellPotion(npc, hero);
            break;
        case 5:
            tradeActive = false;
            std::cout << "Zakonczono handel." << std::endl;
            break;
        case 6:
            ShowInventoryHero(hero);
            break;
        case 7:
            ShowInventoryNpc(npc);
            break;
        default:
            std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
            break;
        }
    }
}

void Trade::BuyItem(NPC& npc, Hero& hero) {
    std::cout << "Wybierz bron do zakupu z ekwipunku NPC." << std::endl;
    npc.getEquipment().displayWeapons();

    int choice;
    std::cin >> choice;

    Weapon* weaponToBuy = npc.getEquipment().getWeapon(choice);

    if (weaponToBuy == nullptr) {
        std::cout << "Nieprawidlowy wybor. Brak takiego przedmiotu." << std::endl;
        return;
    }

    double value = weaponToBuy->getValue();

    if (hero.getEquipment().getGold() < value) {
        std::cout << "Nie masz wystarczajaco zlota, aby kupic ten przedmiot." << std::endl;
        return;
    }

    if (hero.getEquipment().getWeaponCount() >= 2) {
        std::cout << "Nie masz miejsca na wiecej broni." << std::endl;
        return;
    }
    else {
        hero.getEquipment().setGold(hero.getEquipment().getGold() - value);
        npc.getEquipment().removeWeapon(choice);
        hero.getEquipment().addWeapon(weaponToBuy);
        std::cout << "Kupiono bron: " << weaponToBuy->getName()
            << " za " << value << " zlota." << std::endl;
    }
}

void Trade::SellItem(NPC& npc, Hero& hero) {
    std::cout << "Wybierz bron do sprzedania z twojego ekwipunku." << std::endl;
    hero.getEquipment().displayWeapons();

    int choice;
    std::cin >> choice;

    Weapon* itemToSell = hero.getEquipment().getWeapon(choice);
    if (itemToSell == nullptr) {
        std::cout << "Nieprawidlowy wybor. Brak takiego przedmiotu." << std::endl;
        return;
    }

    double value = itemToSell->getValue();
    std::string itemName = itemToSell->getName();

    if (npc.getEquipment().getWeaponCount() > 0) {
        npc.getEquipment().addWeapon(itemToSell);
    }
    else {
        std::cout << "NPC nie ma miejsca. Przedmiot zostanie wyrzucony po sprzedazy." << std::endl;
        delete itemToSell;
    }

    hero.getEquipment().setGold(hero.getEquipment().getGold() + value);
    hero.getEquipment().removeWeapon(choice);

    std::cout << "Sprzedano " << itemName << " za " << value << " zlota." << std::endl;
}

void Trade::ShowInventoryNpc(NPC& npc) {
    npc.getEquipment().displayWeapons();
    npc.getEquipment().displayPotions();
}

void Trade::ShowInventoryHero(Hero& hero) {
    hero.getEquipment().displayWeapons();
    hero.getEquipment().displayPotions();
}

void Trade::BuyPotion(NPC& npc, Hero& hero) {
    std::cout << "Wybierz miksture do zakupu z ekwipunku NPC." << std::endl;
    npc.getEquipment().displayPotions();

    int choice;
    std::cin >> choice;

    Potion* potionToBuy = npc.getEquipment().getPotion(choice);
    if (potionToBuy == nullptr) {
        std::cout << "Nieprawidlowy wybor. Brak takiej mikstury." << std::endl;
        return;
    }

    double value = potionToBuy->getValue();
    std::string potionType = (potionToBuy->getType() == Potion::Type::Health) ? "Zdrowia" : "Many";

    if (hero.getEquipment().getGold() < value) {
        std::cout << "Nie masz wystarczajaco zlota, aby kupic ta miksture." << std::endl;
        return;
    }

    if (hero.getEquipment().getPotionCount() < 5) {
        hero.getEquipment().addPotion(potionToBuy);
    }
    else {
        std::cout << "Brak miejsca na mikstury." << std::endl;
        return;
    }

    hero.getEquipment().setGold(hero.getEquipment().getGold() - value);
    npc.getEquipment().removePotion(choice);
    hero.getEquipment().addPotion(potionToBuy);

    std::cout << "Kupiono miksture " << potionType << " za " << value << " zlota." << std::endl;
}

void Trade::SellPotion(NPC& npc, Hero& hero) {
    std::cout << "Wybierz miksture do sprzedania ze swojego ekwipunku." << std::endl;
    hero.getEquipment().displayPotions();

    int choice;
    std::cin >> choice;

    Potion* potionToSell = hero.getEquipment().getPotion(choice);
    if (potionToSell == nullptr) {
        std::cout << "Nieprawidlowy wybor. Brak takiej mikstury." << std::endl;
        return;
    }

    double value = potionToSell->getValue();
    std::string potionType = (potionToSell->getType() == Potion::Type::Health) ? "Zdrowia" : "Many";

    if (npc.getEquipment().getPotionCount() < 5) {
        npc.getEquipment().addPotion(potionToSell);
    }
    else {
        std::cout << "NPC nie ma miejsca. Mikstura zostanie wyrzucona po sprzedazy." << std::endl;
        delete potionToSell;
    }

    hero.getEquipment().setGold(hero.getEquipment().getGold() + value);
    hero.getEquipment().removePotion(choice);

    std::cout << "Sprzedano miksture " << potionType << " za " << value << " zlota." << std::endl;
}
