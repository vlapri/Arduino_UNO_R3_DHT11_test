# Arduino_UNO_R3_DHT11_test

Jednoduchá aplikace pro **Arduino UNO R3**, která každé 2 sekundy načte teplotu a vlhkost
z čidla **DHT11** a vypíše je do sériového terminálu. Projekt je určen pro
**VS Code + PlatformIO**.

## Zapojení

| DHT11 (modul)  | Arduino UNO R3 |
|----------------|----------------|
| VCC (+)        | 5V             |
| DATA (OUT, S)  | D7             |
| GND (-)        | GND            |

> Pokud používáš samotné čidlo (4 piny, ne modul), připoj mezi DATA a VCC
> pull-up rezistor 4,7–10 kΩ. Moduly ho obvykle už mají na desce.

## Požadavky

- [VS Code](https://code.visualstudio.com/) s rozšířením **PlatformIO IDE**
- Knihovny (stáhnou se automaticky podle `platformio.ini`):
  - `adafruit/DHT sensor library`
  - `adafruit/Adafruit Unified Sensor`

## Sestavení a nahrání

Ve VS Code otevři složku projektu a použij lištu PlatformIO dole
(✓ Build, → Upload, 🔌 Serial Monitor), nebo příkazy v terminálu:

```bash
pio run                      # kompilace
pio run -t upload            # nahrání do Arduina
pio device monitor           # sériový terminál (9600 Bd)
```

## Výstup v terminálu

```
Arduino UNO R3 - test cidla DHT11 (pin D7)
------------------------------------------
Teplota: 23.0 °C	Vlhkost: 45 %	Pocitova teplota: 22.6 °C
Teplota: 23.0 °C	Vlhkost: 46 %	Pocitova teplota: 22.6 °C
```

Při chybě čtení (špatné zapojení, vadné čidlo) se vypíše
`Chyba: nepodarilo se nacist data z DHT11!`.

## Struktura projektu

```
├── platformio.ini   # konfigurace PlatformIO (deska uno, knihovny, rychlost monitoru)
└── src/
    └── main.cpp     # hlavní program
```
