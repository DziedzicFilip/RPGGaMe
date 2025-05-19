# Struktura projektu RPG Game (uproszczona)

## Struktura folderów i plików
```
RPGGame/
├── Character.h                       # Abstrakcyjna klasa bazowa dla postaci
├── Character.cpp
├── Player.h                          # Klasa głównego bohatera
├── Player.cpp
├── Companion.h                       # Klasa towarzysza (przydupasa)
├── Companion.cpp
├── NPC.h                             # Klasa postaci niezależnych (kupiec)
├── NPC.cpp
├── Enemy.h                           # Klasa przeciwników
├── Enemy.cpp
├── Item.h                            # Klasa przedmiotów w grze
├── Item.cpp
├── Game.h                            # Główna klasa gry
├── Game.cpp
├── Combat.h                          # System walki
├── Combat.cpp
├── Story.h                           # Obsługa fabuły i aktów
├── Story.cpp
├── Dialog.h                          # System dialogów
├── Dialog.cpp
├── PrintText.asm                     # Funkcja assemblerowa do wypisywania tekstu
├── AddNumbers.asm                    # Prosta funkcja pomocnicza
├── Instructions/                     # Dokumentacja projektu
│   ├── instructions.md               # Scenariusz gry
│   ├── game_plan.md                  # Plan implementacji
│   └── structure.md                  # Ten plik
├── RPGGame.cpp                       # Punkt wejścia do programu
└── RPGGame.h                         # Główny plik nagłówkowy
```

## Opis głównych modułów

### Postacie
Proste klasy do obsługi postaci w grze:
- `Character` - abstrakcyjna klasa bazowa z podstawowymi statystykami
- `Player` - klasa gracza
- `Companion` - klasa towarzysza (przydupasa) z mechaniką grzybów
- `NPC` - inne postacie niezależne (kupiec)
- `Enemy` - przeciwnicy

### System rozgrywki
- `Game` - zarządzanie stanem gry i główna pętla
- `Combat` - prosty system walki turowej
- `Item` - podstawowe przedmioty (mikstury, broń, grzyby)

### Fabuła
- `Story` - implementacja aktów fabularnych
- `Dialog` - prosty system dialogów i wyborów

### Funkcje assemblerowe
- `PrintText.asm` - wyświetlanie tekstu w konsoli
- `AddNumbers.asm` - prosta funkcja pomocnicza

## Uproszczenia w stosunku do pierwotnej koncepcji

1. **Spłaszczona struktura projektu** - rezygnacja z rozbudowanej hierarchii folderów na rzecz wszystkich plików w głównym katalogu
2. **Ograniczona rola assembly** - tylko do wyświetlania tekstu (PrintText.asm)
3. **Prostszy system walki** - podstawowa mechanika turowa bez złożonych obliczeń
4. **Ograniczony system decyzji** - proste wybory wpływające głównie na buffy/debuffy
5. **Mniej klas pomocniczych** - rezygnacja z dedykowanych klas do obsługi zasobów

## Interakcja między modułami

1. `Game` zarządza głównym cyklem gry i obsługą stanów
2. `Player` i `Companion` wchodzą w interakcje w ramach fabuły
3. `Combat` obsługuje proste starcia z przeciwnikami
4. `Story` zarządza przebiegiem fabuły
5. `PrintText.asm` jest używany do wyświetlania dialogów

## Kluczowe funkcjonalności

1. **Testy percepcji** - zaimplementowane w klasie `Character`
2. **System walki** - prosty system turowy w `Combat`
3. **Towarzysz** - klasa `Sojusznik` z mechaniką grzybów i dialogów
4. **Kupiec** - implementacja w klasie `NPC`
5. **Wybory fabularne** - wpływające na buffy/debuffy postaci
6. **Dwa zakończenia** - prosty system w `Story`
