**#Minröj#**
##Beskrivning##
Detta är ett enkelt textbaserat Minröj-spel skrivet i C++. Spelet erbjuder olika svårighetsgrader och låter spelaren spara och ladda spel.

##Installation##
Se till att du har en C++-kompilator installerad på din dator.
Klona eller ladda ner projektet till din lokala maskin.

##Kompilering##
Kompilera spelet med följande kommando i terminalen eller kommandotolken:

g++ -o game main.cpp Game.cpp Board.cpp


##Användning##
Starta spelet med följande kommando:

./game


Följ instruktionerna på skärmen för att spela spelet. Du kan välja att avslöja en ruta, markera en potentiell mina, spara spelet, eller avsluta.

##Funktioner##
Flera svårighetsgrader: Beginner, Intermediate, Advanced.
Spara och ladda spel.
Textbaserad användargränssnitt.

##Viktig information##
Sparad fil: Filen saved_game.txt används för att spara spelets tillstånd. Notera att filen rensas varje gång du kompilerar om spelet. Se därför till att spara viktig speldata innan du kompilerar om.