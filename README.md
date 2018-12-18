# Fishing

Pour compiler :
  - Tout d'abord il faut créer un repertoir "obj" au même niveau que les repertoir "src" et "bin"
  - Si vous êtes sous Linux : renommez le fichier "Makefile_lin" en "Makefile" puis entrez la commande "make clean all" dans un terminal
  - Si vous êtes sous Windows :
    - Renommez le fichier "Makefile_win" en "Makefile"
    - Vérifiez que vous disposez bien des fichiers désigné par les variables INC, LIBBIR et LIB (ainsi que les fichiers lié), si vous ne les avez pas, veuillez télécharger mingw32, SDL2, SDL2_ttf et SDL2 image (le tout en version développeur) et les mettre aux chemin désigné.
    - Enfin, entrez la commande "make clean all"

Pour executer :
  Vous pouvez executer le jeu comme vous le souhaitez, il n'y a pas d'arguments d'execution à saisir.


Les inputs :
  - Déplacements avec W, A, S, D
  - mise en pause avec P
  - Vous pouvez interagir avec les boutons à l'écran (dans le menu de Pause et à la fin de niveau) avec votre curseur.


Level Design :
  Il est tout à fait possible de créer de nouveaux niveaux selon vos goûts en quelques étapes :
  - Dans le repertoir "bin/stages", créez un fichier au format .txt
  - Le premier caractère du fichier doit être un retour à la ligne
  - Ensuite veuillez renseigner (dans cet ordre) :
    - Le Score minimum pour gagner le niveaux
    - Le temps du niveau
    - Les poissons à créer en indiquant le type du poisson (un entier de 1 à 6). Un poisson par ligne

Nous vous souhaitons de passer de bons moments sur notre jeu !
