# Fishing

Documentation (via Doxygene) :
  - Installer la dernière version de Doxygene : https://sourceforge.net/projects/doxygen/files/latest/download
  - Lancer l'installateur
  - utilisez les paramètre dans le fichier Doxyfile

TODO LIST :

  - Faire une docu
  - ~~réparer deplacements bateau vitesse~~

  - ~~Menu pause~~
  - Dessiner ligne Hameçon-Bateau
  - Trouver/implémenter images ciel (http://www.coach-susana.com/wp-content/uploads/2018/04/Sue%C3%B1os.jpg), Ocean (https://www.color-hex.com/color-palette/35102), vagues
  - Animations canne-à-peche

  - Animations poissons
  - Images de courants
  - Mécanique de courants (illogique)
  - Système de scrolling vertical (complet, ciel disparait)

  - Système de score
  - Système de niveau  : {
    - x temps pour faire y score / lvl (tps, score victoire : défini dans un fichier txt)
    - temps libre pour faire max score
    - survie (nb hameçon limité <=> vies)
  }

  - ~~Sprites poisson de base~~
  - Mécaniques des poissons : {
    - poisson classique (vitesse faible et constante) : 1 pts
    - poisson sprinteur (vitesse faible mais qui sprint de manière aléatoire) : 2 pts
    - poisson rapide (vitesse constante mais plus rapide que classique) : 2 pts
    - poisson jebaited (s'approche de l'hameçon mais fuis si l'hameçon s'approche de lui quand il s'approche aussi) : 5 pts
    - poisson très rare (hérite de classique) : 10 pts
    - ...
  }


  - Menu (Jouer (mode temps, mode libre), option (musique on/off), quitter)

  - Si tout ça fait : {
    - Cinématique d'intro au menu
    - Events con (météors, volcans... etc)
    - Menu option assignation touches
    - Sons ?
  }
