#pragma once

// General terms
#define LANG_CONNECT "Verbind"
#define LANG_CONNECTED "Verbonden"
#define LANG_DISCONNECT "Verbinding verbreken"
#define LANG_MANUALLY "Manueel"
#define LANG_CANCEL "Annuleren"
#define LANG_SAVE "Opslaan"
#define LANG_NEXT "Volgende"
#define LANG_DAILY "Dagelijks"
#define LANG_WEEKDAYS "Weekdagen"
#define LANG_CATEGORY "Categorie"
#define LANG_RED "rood"
#define LANG_NORMAL "normaal"
#define LANG_IMAGE "Afbeelding"
#define LANG_EXAMPLE "Voorbeeld"
#define LANG_EXAMPLES "Voorbeelden"
#define LANG_ANALOG "Analoog"
#define LANG_DIGITAL "Digitaal"
#define LANG_WATCHFACES "Klokweergave"
#define LANG_TOOLS "Hulpmiddelen"
#define LANG_WEATHER "Weer"
#define LANG_SETTINGS "Instellingen"
#define LANG_GAMES "Spelletjes"
#define LANG_DUAL "Dubbel"
#define LANG_BINARY "Binair"
#define LANG_NUMERALS "Cijfers"
#define LANG_AFIT "Analoog+Fit"

// App: Webserver
#define LANG_WEBSRV_STATION_PWD "Station wachtwoord:"
#define LANG_WEBSRV_TITLE "Configuratie"
#define LANG_WEBSRV_USER "Gebruiker:"
#define LANG_WEBSRV_PASS "Wachtwoord:"
#define LANG_WEBSRV_AP_PASSWORD_ON "AutoAP WW AAN"
#define LANG_WEBSRV_AP_PASSWORD_OFF "AutoAP WW UIT"

// App: Watchface Parent Class
#define LANG_WATCHFACE_DEFAULT_SET "Standaard klokweergave\naangepast."

// App: Watchface Binary
#define LANG_WATCHFACE_BINARY_STEPS "stappen"

// App: Watchface Fitness
#define LANG_WATCHFACE_FITNESS_DISTANCE "Afst"
#define LANG_WATCHFACE_FITNESS_STEP "Stap"

// App: Fitness Statistics
#define LANG_FITNESS_STEP "Stap"
#define LANG_FITNESS_DISTANCE "Afstand"
#define LANG_FITNESS_TOTAL "Totaal"

// App: Step Statistics
#define LANG_STEPSTATS_TITLE "Stap stat."

// App: Kcal Statistics
#define LANG_KCALSTATS_TITLE "Kcal stat."

// App: Distance Statistics
#define LANG_DISTSTATS_TITLE "Afst. stat."

// App: Tutorial
#define LANG_TUT_ANYKEY "Druk toets om verder te gaan."
#define LANG_TUT_SCR0_TITLE "Welkom!"
#define LANG_TUT_SCR0_TEXT "Dit is jouw eigen Open-Smartwatch!\n Deze handleiding zal je de \nbasis navigatieconcepten van dit OS uitleggen. \nVeel plezier!"
#define LANG_TUT_SCR1_TITLE "Navigatie"
#define LANG_TUT_SCR1_TEXT "Kies een van de toetsmodi\nin de lijst beneden om door te gaan.\nJe kan de apps openen door \n SELECT in te houden."
#define LANG_TUT_SCR1_SHORT_PRESS "Kort indrukken"
#define LANG_TUT_SCR1_DOUBLE_PRESS "2x indrukken"
#define LANG_TUT_SCR1_LONG_PRESS "Lang indrukken"
#define LANG_TUT_SCR1_VERY_LONG_PRESS "Zeer lang indrukken"
#define LANG_TUT_SCR2_TITLE "Batterij\ncalibratie"
#define LANG_TUT_SCR2_TEXT "Gezien de hardware geen BMS heeft,\nmoet het OS de batterijcapaciteit\ngaandeweg leren.\nZorg dat je de batterij volledig\nontlaad als het icoon"
#define LANG_TUT_SCR2_TEXT_COLORED "gevuld is met deze \"info\" kleur."
#define LANG_TUT_SCR3_TITLE "Hardwareproblemen"
#define LANG_TUT_SCR3_TEXT "Als je dit scherm ziet,\nhebben we hardwareproblemen\ngedetecteerd. Let op\nhet volgende:"
#define LANG_TUT_SCR3_NOBATWIFI "Geen batterijniveau met actieve wifi"
#define LANG_TUT_SCR3_WIFILOWPW "Actieve wifi kan zorgen voor CPU storingen."
#define LANG_TUT_SCR3_CRAPGPS "GPS ontvangst is... Vreselijk."

// App: Time from web
#define LANG_TFW_UPDATE "Bijwerken"

// App: BLE media control
#define LANG_BMC_VOLUME "Volume"
#define LANG_BMC_CONNECTING "Bezig met verbinden..."

// Weekdays
#define LANG_MONDAY "Maandag"
#define LANG_TUESDAY "Dinsdag"
#define LANG_WEDNESDAY "Woensdag"
#define LANG_THURSDAY "Donderdag"
#define LANG_FRIDAY "Vrijdag"
#define LANG_SATURDAY "Zaterdag"
#define LANG_SUNDAY "Zondag"

// Weekdays (short)
#define LANG_SUN "Zon"
#define LANG_MON "Ma"
#define LANG_TUE "Di"
#define LANG_WED "Woe"
#define LANG_THU "Do"
#define LANG_FRI "Vri"
#define LANG_SAT "Za"

// At the very last: Include English as a fallback -> any keys not found in the current language, they will be defined in English
#include "en-US.h"
