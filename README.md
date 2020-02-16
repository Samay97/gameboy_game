# gameboy_game

## programm bauen

Um das Spiel zu bauen benötigt man den Download [GBDK](https://sourceforge.net/projects/gbdk/files/).
Kopier den Ordner in den Root dieses Projectes und führe folgenden Befehl aus:

```
./make.bat
```

## Spielen
Der Programmcode wird aus Funktionen der GBDK Datei erstellt.
Ist man nun fertig muss der Code in eine `.gb` file umgewandelt werden. Dies geschieht mit Hilfe der makefile.
Um das Spiel zu starten muss der Build-Prozess abgeschlossen sein, so dass eine `main.gb` Datei existiert.
Man kann nun den Emulator [bgb](http://bgb.bircd.org/) starten. Mit rechts klick auf das geöffnete Programm
wählt man den Punkt `Load ROM` aus und wählt die `main.gb` Datei. Nun wird das Spiel gelanden.


# Anwenderdokumentation:

Das Spiel beginnt mit einem Startbildschirm.
Wird die Enter-Taste gedrückt beginnt das Spiel.

Der Spieler steuert hier seinen Character durch die Wüste und versucht einigen Dornenbüschen auszuweichen.
Der Character wird von selbst immer schneller.
Die Steuerung beschränkt sich auf die Pfeiltasten um sich nach links und rechts zu bewegen und die Taste "S" um zu springen und so den Büschen auszuweichen.

Landet man früher oder später dann unglücklich in einem Dornenbusch, kommt ein Game Over screen mit dem Punktestand.

Ziel des Spiels ist es so lange wie möglich zu überleben und einen möglichst hohen Punktestand zu bekommen.

## Known BUG´s
- Der Score wird nicht immer Angezeigt beim ausführen des Spiels. Durch erneutes laden wird dieser wieder angezeit.
