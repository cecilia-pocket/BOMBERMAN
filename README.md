# Bomberman

## 🎓 Étudiants :
K. C.  
A. V.  
Cécilia NGUYEN

## Diagramme des classes

[Lien vers le diagramme](https://cdn.discordapp.com/attachments/653242922266918915/841243371283808257/Bomberman.png)

-----------------

## 💣 Le Bomberman : 

Ce projet est un [Bomberman](https://fr.wikipedia.org/wiki/Bomberman) réalisé en C++ dans le cadre de l'UE Conception Et Développement D'Applications.
Le Bomberman est disponible en version console (TXT) mais elle est aussi disponible avec un affichage graphique (SDL2).

Sur un terrain rempli de briques, vous incarnez un personnage qui peut poser des bombes. Votre but est simple : Frayez-vous un chemin en utilisant vos bombes afin de tuer les joueurs adverses. Mais attention à ne pas se faire toucher par une bombe !
Sous TXT, les briques sont représenté par un ``.`` et les murs par des ``#``. Tandis que sous SDL2, les objets sont représenté par des images.

### 🕹️ Utilisation :
Que ce soit en mode TXT ou SDL2, les touches sont les mêmes, la seule différence est bien-sûr l'affichage. Le jeu est fait pour être utilisé sur un clavier AZERTY!
Pour quitter le jeu sous SDL, appuyez sur ECHAP. Et pour la version TXT, appuyez sur C.
```
+---------------------------+----------------------------+
|   Touches du Joueur 1     |     Touches du Joueur 2    |
+---------------------------+----------------------------+
| Z 👉 Se déplacer en haut  | O 👉 Se déplacer en haut  |
| Q 👉 Se déplacer à gauche | K 👉 Se déplacer à gauche |
| S 👉 Se déplacer en bas   | L 👉 Se déplacer en bas   |
| D 👉 Se déplacer à droite | M 👉 Se déplacer à droite |
| A 👉 Poser une bombe      | P 👉 Poser une bombe      |
+---------------------------+----------------------------+
```


### 🔖 Organisation de l'archive :  
```
bin/
├─ Fichiers éxecutable
data/
├─ Assets (Images, sons, fonts...)
doc/
├─ Documentation généré par doxyfile (Diagramme UML/Gantt, cahier des charges...)
obj/
├─ Fichiers *.o
src/
├─ core/
│  ├─ *.cpp et *.h du Bomberman
├─ sdl2/
│  ├─ *.cpp et *.h du Bomberman en version SDL2
├─ txt/
│  ├─ *.cpp et *.h du Bomberman en version TXT
├─ Test.cpp pour effectuer les tests de régression
README
```
-----------------

## 🛠️ Compilation :

Afin de pouvoir compiler le programme, il faut utiliser le Makefile :

```
make
```


-----------------

## ⚒️ Exécution :

Pour éxecuter le Bomberman en version TXT :

```
./bin/mainTXT
```

Pour éxecuter le Bomberman en version SDL :

```
./bin/mainSDL
```
-----------------

## 📚 Documentation :

La documentation a été générée automatiquement via [Doxygen](https://www.doxygen.nl/index.html)  

Pour pouvoir accéder à la documentation :  
```
doxygen doc/doxyfile.doxy
```

Puis pour afficher la documentation :
```
[nom_de_votre_navigateur] doc/html/index.html
```
