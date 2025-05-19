# Plan implementacji gry RPG (uproszczony)

## Główne założenia
Tworzymy prostą tekstową grę RPG zgodną ze scenariuszem opisanym w pliku `instructions.md`. Całość zostanie napisana w C++ z minimalnym wykorzystaniem funkcji assemblerowych (głównie PrintText.asm do wyświetlania dialogów).

## Etapy implementacji

### Etap 1: Implementacja podstawowych klas i mechaniki (3-4 dni)
1. **Abstrakcyjna klasa Character**
   - Podstawowe statystyki (zdrowie, siła, inteligencja, zręczność, szczęście)
   - Mechanizm testów percepcji z rzutami kośćmi
   - Prosty system walki 

2. **Klasy potomne**
   - Player - klasa głównego bohatera
   - Companion - klasa towarzysza (przydupasa)
   - NPC - klasa postaci niezależnych (kupiec)
   - Enemy - klasa przeciwników

3. **Klasa Item**
   - Prosty system przedmiotów (mikstury, grzyby, artefakty fabularne)

### Etap 2: System walki i interakcji (2-3 dni)
1. **Podstawowy system walki**
   - Tura po turze 
   - Proste rzuty kośćmi na obrażenia
   - Podstawowa inicjatywa

2. **Interakcje z NPC**
   - Dialog z Companionem
   - System handlu z kupcem

### Etap 3: Implementacja fabuły (3-4 dni)
1. **Prosty system dialogów**
   - Podstawowe wybory tak/nie
   - Wykorzystanie PrintText.asm do wyświetlania dialogów

2. **Implementacja aktów gry**
   - Prolog
   - Akt 1: Las Cieni
   - Akt 2: Wioska Zamarłych
   - Akt 3: Podziemia Miasta
   - Finał: Sala Tronowa

3. **Uproszczony system decyzji gracza**
   - Wybory dające buffy/debuffy
   - Dwa proste zakończenia

### Etap 4: Mechaniki dodatkowe (2-3 dni)
1. **System handlu**
   - Prosta interakcja z kupcem (zwierzęciem)
   - Podstawowy system ekonomii

2. **System ognisk i losowych znajdziek**
   - Odnowienie zdrowia przy ognisku
   - Proste testy percepcji na znajdowanie przedmiotów

3. **Mechanika halucynacji**
   - Podstawowe dialogi "głosu w głowie"
   - Wpływ na fabułę

## Harmonogram
1. Etap 1: Podstawowe klasy i mechanika - 3-4 dni
2. Etap 2: System walki i interakcji - 2-3 dni
3. Etap 3: Implementacja fabuły - 3-4 dni
4. Etap 4: Mechaniki dodatkowe - 2-3 dni
5. Testy i poprawki - 1-2 dni

**Całkowity czas**: 11-16 dni (maksymalnie 2 tygodnie)

## Najważniejsze problemy do rozwiązania
1. Zapewnienie spójnej narracji zgodnej z fabułą z instructions.md
2. Zbalansowanie prostego systemu walki
3. Implementacja podstawowych interakcji między postaciami
