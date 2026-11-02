# 📺 Reklamowy Wyświetlacz LCD – Arduino

## 🚀 Opis projektu

Projekt przedstawia elektroniczny ekran reklamowy wykonany z wykorzystaniem Arduino oraz wyświetlacza LCD 16x2 z modułem I2C.

Urządzenie działa jak miniaturowy ekran reklamowy, który automatycznie prezentuje reklamy różnych znanych marek. Każda firma posiada własny slogan reklamowy, symbol graficzny oraz animację tekstową.

Reklamy pojawiają się w losowej kolejności, dzięki czemu każde uruchomienie urządzenia może wyglądać nieco inaczej.

## 🏢 Prezentowane firmy

Projekt zawiera przykładowe reklamy pięciu znanych marek:

| Firma | Hasło reklamowe |
| --- | --- |
| 🍔 McDonald's | I'M LOVIN' IT\! |
| 🚗 BMW | RADOŚĆ Z JAZDY\! |
| 🥤 Coca-Cola | TASTE THE MAGIC\! |
| 🎮 PlayStation | GRAJ BEZ GRANIC\! |
| 🛍️ Allegro | DOBRZE TRAFIONE\! |

## 🧰 Wykorzystane komponenty

- Arduino Uno lub kompatybilna płytka.
- Wyświetlacz LCD 16x2.
- Moduł komunikacyjny I2C.
- Przewody połączeniowe.
- Kabel USB do programowania Arduino.

## 🔌 Schemat podłączenia

Wyświetlacz LCD I2C podłączamy do Arduino w następujący sposób:

| LCD I2C | Arduino UNO |
| --- | --- |
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

## ⚙️ Jak działa projekt?

Program został podzielony na kilka etapów:

1. **Losowanie reklamy** – Arduino wybiera jedną z pięciu dostępnych firm.
2. **Wyświetlenie nazwy** – na pierwszej linii LCD pojawia się nazwa marki i jej symbol.
3. **Animacja sloganu** – druga linia wyświetla przewijający się tekst reklamowy.
4. **Efekt migania** – po przewinięciu sloganu pojawia się animowane hasło reklamowe.
5. **Zmiana reklamy** – po krótkiej przerwie urządzenie losuje kolejną firmę.

Całość działa automatycznie i nie wymaga ingerencji użytkownika.

## 💻 Wykorzystane technologie

- Język programowania C++.
- Środowisko Arduino IDE.
- Biblioteka `Wire.h` – obsługa komunikacji I2C.
- Biblioteka `LiquidCrystal_I2C.h` – sterowanie wyświetlaczem LCD.
- Funkcja `millis()` – kontrolowanie czasu animacji.
- Funkcja `random()` – losowanie kolejności reklam.
- Funkcja `createChar()` – tworzenie własnych symboli graficznych.

## ✨ Najważniejsze funkcje

- Losowa kolejność reklam.
- Przewijanie tekstu na wyświetlaczu.
- Migające slogany reklamowe.
- Własne symbole graficzne dla każdej marki.
- Automatyczna zmiana reklam.
- Brak konieczności stosowania opóźnień `delay()`.

## 🎯 Cel projektu

Celem projektu jest stworzenie prostego, interaktywnego systemu reklamowego, który pokazuje możliwości wykorzystania Arduino do sterowania wyświetlaczem LCD.

Projekt łączy podstawy programowania mikrokontrolerów z kreatywnym zastosowaniem animacji tekstowych i grafiki.

## 🔧 Możliwości rozbudowy

W przyszłości projekt można rozbudować o:

- Większą liczbę reklam i marek.
- Dodatkowe animacje i efekty tekstowe.
- Przyciski do ręcznej zmiany reklam.
- Losowanie sloganów reklamowych.
- Czujnik ruchu uruchamiający ekran.
- Większy wyświetlacz lub ekran OLED.

## 👨‍💻 Autor

Projekt edukacyjny wykonany z wykorzystaniem platformy Arduino.

---

**📢 Twoja reklama może być następna\!**

_Arduino – mały mikrokontroler, wielkie możliwości._
