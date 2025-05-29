#include "Trade.h"
#include "NPC.h"
#include "Hero.h"


void Trade::StartTrade(NPC& npc, Hero& hero) {
	bool tradeActive = true;
	while (tradeActive)
	{
		std::cout << "Trade with " << npc.getName() << " started." << std::endl;
		std::cout << "1. Buy Weapon" << std::endl;
		std::cout << "2. Sell Weapon" << std::endl;
		std::cout << "3. Buy Potion" << std::endl;
		std::cout << "4. Sell Potion" << std::endl;
		std::cout << "5. Exit Trade" << std::endl;
		std::cout << "6. Show Hero Inventory" << std::endl;
		std::cout << "7. Show NPC Inventory" << std::endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			BuyItem(npc,  hero);
			break;
		case 2:
			SellItem(npc, hero);
			break;
		case 3:
			BuyPotion(npc,  hero);
			break;
		case 4:
			SellPotion(npc, hero);
			break;
		case 5:
			tradeActive = false;
			std::cout << "Trade ended." << std::endl;
			break;
		case 6:
			ShowInventoryHero(hero);
			break;
		case 7:
			ShowInventoryNpc(npc);
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
	}

}

void Trade::BuyItem(NPC& npc, Hero& hero) {
	std::cout << "Choose an item to buy from the NPC's inventory." << std::endl;
	npc.getEquipment().displayWeapons();

	int choice;
	std::cin >> choice;

	Weapon* weaponToBuy = npc.getEquipment().getWeapon(choice);

	if (weaponToBuy == nullptr) {
		std::cout << "Invalid choice. No such item." << std::endl;
		return;
	}

	double value = weaponToBuy->getValue();

	if (hero.getEquipment().getGold() < value) {
		std::cout << "You don't have enough gold to buy this item." << std::endl;
		return;
	}

	if (hero.getEquipment().getWeaponCount() >= 2) {
		std::cout << "You don't have space for more weapons" << std::endl;
		
		return;
	}
	else
	{
		hero.getEquipment().setGold(hero.getEquipment().getGold() - value);
		npc.getEquipment().removeWeapon(choice);
		hero.getEquipment().addWeapon(weaponToBuy);  
		std::cout << "You bought " << weaponToBuy->getName()
			<< " for " << value << " gold." << std::endl;
	}
	

	
	
}

void Trade::SellItem(NPC& npc, Hero& hero) {
	std::cout << "Choose an item to sell from your inventory." << std::endl;
	hero.getEquipment().displayWeapons();  
	int choice;
	std::cin >> choice;

	Weapon* itemToSell = hero.getEquipment().getWeapon(choice);
	if (itemToSell == nullptr) {
		std::cout << "Invalid choice. No such item." << std::endl;
		return;
	}

	double value = itemToSell->getValue();
	std::string itemName = itemToSell->getName();

	
	if (npc.getEquipment().getWeaponCount() > 0) {
		npc.getEquipment().addWeapon(itemToSell);  // NPC przejmuje przedmiot
	}
	else {
		std::cout << "NPC has no space. The item will be discarded after selling." << std::endl;
		delete itemToSell;  
	}

	
	hero.getEquipment().setGold(hero.getEquipment().getGold() + value);

	
	hero.getEquipment().removeWeapon(choice);

	std::cout << "You sold " << itemName << " for " << value << " gold." << std::endl;
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
	std::cout << "Choose a potion to buy from the NPC's inventory." << std::endl;
	npc.getEquipment().displayPotions();  // wyœwietlenie mikstur NPC-a

	int choice;
	std::cin >> choice;

	Potion* potionToBuy = npc.getEquipment().getPotion(choice);
	if (potionToBuy == nullptr) {
		std::cout << "Invalid choice. No such potion." << std::endl;
		return;
	}

	double value = potionToBuy->getValue();
	std::string potionType = (potionToBuy->getType() == Potion::Type::Health) ? "Health" : "Mana";

	if (hero.getEquipment().getGold() < value) {
		std::cout << "You don't have enough gold to buy this potion." << std::endl;
		return;
	}

	// Jeœli bohater ma miejsce na miksturê — dodaje j¹
	if (hero.getEquipment().getPotionCount() < 5) {
		hero.getEquipment().addPotion(potionToBuy);
	}
	else {
		std::cout << "You don't have space. " << std::endl;
		return;
	}

	// Odejmowanie z³ota bohatera
	hero.getEquipment().setGold(hero.getEquipment().getGold() - value);

	// Usuniêcie mikstury z ekwipunku NPC-a
	npc.getEquipment().removePotion(choice);
	hero.getEquipment().addPotion(potionToBuy);  // dodanie mikstury do ekwipunku bohatera
	std::cout << "You bought a " << potionType << " potion for " << value << " gold." << std::endl;
}

void Trade::SellPotion(NPC& npc, Hero& hero) {
	std::cout << "Choose a potion to sell from your inventory." << std::endl;
	hero.getEquipment().displayPotions();  // zak³adam, ¿e to wypisuje potki z indeksami

	int choice;
	std::cin >> choice;

	Potion* potionToSell = hero.getEquipment().getPotion(choice);
	if (potionToSell == nullptr) {
		std::cout << "Invalid choice. No such potion." << std::endl;
		return;
	}

	double value = potionToSell->getValue();
	std::string potionType = (potionToSell->getType() == Potion::Type::Health) ? "Health" : "Mana";

	// Jeœli NPC ma miejsce — przekazuje miksturê
	if (npc.getEquipment().getPotionCount() < 5) {
		npc.getEquipment().addPotion(potionToSell);
	}
	else {
		std::cout << "NPC has no space. The potion will be discarded after selling." << std::endl;
		delete potionToSell;  // usuniêcie z pamiêci
	}

	// Dodanie z³ota bohaterowi
	hero.getEquipment().setGold(hero.getEquipment().getGold() + value);

	// Usuniêcie mikstury z ekwipunku bohatera
	hero.getEquipment().removePotion(choice);

	std::cout << "You sold a " << potionType << " potion for " << value << " gold." << std::endl;
}
