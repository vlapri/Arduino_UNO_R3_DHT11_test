# CLAUDE.md

Pokyny pro Claude Code při práci v tomto repozitáři.

## Komunikace

- S uživatelem komunikuj vždy česky.

## Projekt

Testovací aplikace pro **Arduino UNO R3** čtoucí čidlo **DHT11** na pinu **D7**
a vypisující teplotu, vlhkost a pocitovou teplotu do sériového terminálu (9600 Bd).
Vývoj probíhá ve **VS Code + PlatformIO**.

## Struktura

- `platformio.ini` – prostředí `env:uno` (platform `atmelavr`, board `uno`, framework `arduino`),
  `monitor_speed = 9600`, závislosti v `lib_deps`.
- `src/main.cpp` – celý program (setup/loop, neblokující čtení po 2 s přes `millis()`).

## Příkazy

```bash
pio run                 # kompilace
pio run -t upload       # nahrání do desky
pio device monitor      # sériový monitor
```

## Konvence

- Výpisy na sériovou linku drž bez diakritiky a používej makro `F()` (šetří RAM – UNO má jen 2 kB).
- Pin a typ čidla jsou konstanty `DHT_PIN` a `DHT_TYPE` na začátku `src/main.cpp`.
- DHT11 nečti častěji než 1× za sekundu (aktuálně `READ_INTERVAL_MS = 2000`).
- Při změně `monitor_speed` v `platformio.ini` uprav i `Serial.begin()` a README.
- Adresář `.pio/` je build výstup a je v `.gitignore`.
