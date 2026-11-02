
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Wlasne symbole
byte burger[8] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11111,
  B01110,
  B00100,
  B00000
};

byte car[8] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11111,
  B01010,
  B00000,
  B00000
};

byte bottle[8] = {
  B00100,
  B00100,
  B01110,
  B01110,
  B01110,
  B01110,
  B00100,
  B00000
};

byte game[8] = {
  B00000,
  B01110,
  B11111,
  B10101,
  B11111,
  B01110,
  B00100,
  B00000
};

byte bag[8] = {
  B00000,
  B01110,
  B01010,
  B11111,
  B11111,
  B11111,
  B11111,
  B00000
};

int scena = 0;
unsigned long poprzedniCzas = 0;

int indexTekstu = 0;
int miganie = 0;
bool stanMigania = false;

String reklamy[5][3] = {
  {
    "McDONALDS",
    "Glod? Mamy na to sposob! Big Mac czeka!",
    "I'M LOVIN' IT!"
  },
  {
    "BMW",
    "Poczuj moc! Ruszaj po swoje marzenia!",
    "RADOSC Z JAZDY!"
  },
  {
    "COCA-COLA",
    "Otworz chwile pelna orzezwienia!",
    "TASTE THE MAGIC!"
  },
  {
    "PLAYSTATION",
    "Wlacz konsole! Wylacz nudy!",
    "GRAJ BEZ GRANIC!"
  },
  {
    "ALLEGRO",
    "Znajdz to, czego szukasz!",
    "DOBRZE TRAFIONE!"
  }
};

byte symbole[5] = {0, 1, 2, 3, 4};

String przewijany;
String padded;

void przygotujTekst(String tekst) {
  przewijany = tekst;
  padded = "                " + przewijany + "                ";
  indexTekstu = 0;
}

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, burger);
  lcd.createChar(1, car);
  lcd.createChar(2, bottle);
  lcd.createChar(3, game);
  lcd.createChar(4, bag);

  randomSeed(analogRead(A0));
}

void loop() {
  unsigned long teraz = millis();

  switch (scena) {

    // SCENA 0 - WYBOR REKLAMY
    case 0: {
      lcd.clear();

      int firma = random(0, 5);

      lcd.setCursor(0, 0);
      lcd.write(symbole[firma]);
      lcd.print(" ");
      lcd.print(reklamy[firma][0]);

      przygotujTekst(reklamy[firma][1]);

      poprzedniCzas = teraz;
      scena = 1;
      break;
    }

    // SCENA 1 - PRZEWIJANY SLOGAN
    case 1:
      if (teraz - poprzedniCzas >= 180) {
        poprzedniCzas = teraz;

        if (indexTekstu <= padded.length() - 16) {
          lcd.setCursor(0, 1);
          lcd.print(padded.substring(indexTekstu, indexTekstu + 16));
          indexTekstu++;
        } else {
          scena = 2;
          poprzedniCzas = teraz;
          miganie = 0;
        }
      }
      break;

    // SCENA 2 - ANIMACJA HASLA
    case 2:
      if (teraz - poprzedniCzas >= 400) {
        poprzedniCzas = teraz;

        lcd.setCursor(0, 1);

        if (stanMigania) {
          lcd.print("                ");
        } else {
          lcd.print(">>> ");
          lcd.print(reklamy[0][2]); // Zastepowane ponizej
        }

        stanMigania = !stanMigania;
        miganie++;

        if (miganie >= 6) {
          scena = 3;
          poprzedniCzas = teraz;
        }
      }
      break;

    // SCENA 3 - PRZERWA I KOLEJNA REKLAMA
    case 3:
      if (teraz - poprzedniCzas >= 1500) {
        scena = 0;
      }
      break;
  }
}
