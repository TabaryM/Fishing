#include "GameManager.hpp"


GameManager::GameManager(Stage* s, Input* i) : Manager(s, i), speed(1), focus(0), profondeur(150), borders(Vector2D<int>(Window::WIDTH, Window::HEIGHT)) {}

void GameManager::create(){

  using namespace std;

  int const maxX = 23;
  int const maxY = 100;
  int nbFish = 50;

  ifstream fichier("stages/niveau_1.txt", ios::in);  // on ouvre en lecture
  char Fishs[nbFish];

  if(fichier){  // si l'ouverture a fonctionné
    string ligne;
    int i = 0;
    nbFish = 0 ;
    while(getline(fichier, ligne)){  // tant que l'on peut mettre la ligne dans "contenu"
      for(unsigned int j = 0; j < ligne.size(); j++){
      	Fishs[nbFish] = ligne[j]; //j'assigne chaque caractere de la ligne dans le tableau
      }
    i++;
    }
  }else{
    cerr << "Impossible d'ouvrir le fichier !" << endl;
  }

  objets["Ocean"] = new Object(s->getRenderer(), new Surface(Vector2D<int>(borders.getSize().getX(), borders.getSize().getY() *0.8), 0, 102, 204, 255), Vector2D<int>(0, 0), 1);
  objets["Ocean2"] = new Object(s->getRenderer(), new Surface(Vector2D<int>(borders.getSize().getX(), borders.getSize().getY() *0.8), 0, 102, 204, 255), Vector2D<int>(0, borders.getSize().getY() *0.8), 2);
  objets["Ciel"] = new Object(s->getRenderer(), new Surface("sprites/Sky.png"), Vector2D<int>(0, 0), 3);
  objets["Bateau"] = new Boat(s->getRenderer(), 500, 100, 4);
  objets["Hook"] = new Hook(s->getRenderer(), Vector2D<int>(objets["Bateau"]->getX() + 0.5 * objets["Bateau"]->getSize().getX() , objets["Bateau"]->getY() + 60 ),5);
  objets["Kappa"] = new Object(s->getRenderer(), new Surface("sprites/Kappa.png"), Vector2D<int>(objets["Bateau"]->getX() + 0.82 * objets["Bateau"]->getSize().getX(), objets["Bateau"]->getY() - 46) , objets["Bateau"]->getZ());
  objets["FishPole"] = new Object(s->getRenderer(), new Surface("sprites/FishPole.png"), Vector2D<int>(objets["Kappa"]->getX()-98, objets["Kappa"]->getY()-50) , objets["Bateau"]->getZ());

  objets["Bateau"]->link(objets["Kappa"]);
  objets["Bateau"]->link(objets["Hook"]);
  objets["Kappa"]->link(objets["FishPole"]);
  objets["FishPole"]->link(objets["Hook"]);

  nbFish = 0;
  for(int i = 0; i < maxX; i++) {
    for(int j = 0; j < maxY; j++){
      if(Fishs[nbFish] == '1'){
      	objets["Fish" + std::to_string(nbFish)] = new NormalFish(s->getRenderer(), Vector2D<int>(i*51,190 + 50 * j), nbFish + 10);
      	nbFish++;
      }
      if(Fishs[nbFish] == '2'){
      	objets["Fish" + std::to_string(nbFish)] = new GoldFish(s->getRenderer(), Vector2D<int>(j*51,190 + 50 * i), nbFish + 10);
      	nbFish++;
      }
      if(Fishs[nbFish] == '3'){
      	objets["Fish" + std::to_string(nbFish)] = new FastFish(s->getRenderer(), Vector2D<int>(i*51,190 + 50 * j), nbFish + 10);
      	nbFish++;
      }
      if(Fishs[nbFish] == '4'){
	objets["Fish" + std::to_string(nbFish)] = new RipFish(s->getRenderer(), Vector2D<int>(j*51,190 + 50 * i), nbFish + 10);
	nbFish++;
      }
      if(Fishs[nbFish] == '5'){
      	objets["Fish" + std::to_string(nbFish)] = new BombFish(s->getRenderer(), Vector2D<int>(i*51,190 + 50 * j), nbFish + 10);
      	nbFish++;
      }
      if(Fishs[nbFish] == '6'){
      	objets["Fish" + std::to_string(nbFish)] = new GoldFish(s->getRenderer(), Vector2D<int>(j*51,190 + 50 * i), nbFish + 10);
      	nbFish++;
      }
    }
  }

  for (int i = 0; i < 14; i++) {
    objets["Wave" + std::to_string(i)] = new Wave(s->getRenderer(), Vector2D<int>(-98.5 + 98.5 * i, 143), 3.05);
  }

  Manager::create();
}

void GameManager::update(){

  for (int i = 0; i < nbFish; i++) {

    int timeDegre = rand() % 50 ;
    int timeDirection = rand() % 1000;
    int timeSpeed = rand() % 500;

    if(timeDegre == 20){
      static_cast <Fish*> (objets["Fish" + std::to_string(i)])->setDegre((rand() % 21 - 10)/10);
    }

    if(timeDirection == 502){
      static_cast <Fish*> (objets["Fish" + std::to_string(i)])->setRight(rand() % 2);
    }

    if(timeSpeed == 329){
      static_cast <Fish*> (objets["Fish" + std::to_string(i)])->setDir(rand() % 4 );
    }

    if((objets["Fish" + std::to_string(i)]->getX()) + (1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir()) < 0){
      static_cast <Fish*> (objets["Fish" + std::to_string(i)])->setRight(1);
    }
    if((objets["Fish" + std::to_string(i)]->getX() + objets["Fish" + std::to_string(i)]->getW() ) + (1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir()) > borders.getW()){
      static_cast <Fish*> (objets["Fish" + std::to_string(i)])->setRight(1);
    }
    if((objets["Fish" + std::to_string(i)]->getY()) + (1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDegre()) < borders.getH()*0.3 - profondeur){
      static_cast <Fish*> (objets["Fish" + std::to_string(i)])->setDegre(0);
    }
    objets["Fish" + std::to_string(i)]->move(1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir(), 1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDegre()+focus);
  }
  updateControlX(objets["Bateau"]);
  updateControlY(objets["Hook"]);

}

void GameManager::render(){
  Manager::render();
  s->draw(objets["Hook"]->getX() + 0.5*objets["Hook"]->getW() , objets["Hook"]->getY() +0.15*objets["Hook"]->getH(), objets["FishPole"]->getX(), objets["FishPole"]->getY());
}

void GameManager::destroy(){
}

void GameManager::updateControlX(Object* obj) {
  int depX = 0;
  int depY = 0;

  if (i->isActive(SDL_SCANCODE_A)) {
    if (obj->getX() -speed <= 0 ) {
      depX -= obj->getX();
    }
    else{
      depX -= speed;
    }
  }

  if (i->isActive(SDL_SCANCODE_D)) {
    if (obj->getX() + obj->getW() + speed >= 1280) {
      depX += 1280 - obj->getW() - obj->getX();
    }
    else{
      depX += speed;
    }
  }

  if (i->isActive(SDL_SCANCODE_E)) {
    speed++;
  }
  if (i->isActive(SDL_SCANCODE_R)) {
    if (speed > 1) {
      speed--;
    }
  }

  obj->move(depX, depY);

}
void GameManager::updateControlY(Object* obj) {
  int depX = 0;
  int depY = 0;
  bool hookFocus = false;
  bool dir = true;
  focus = 0;

   if(obj->getY() > borders.getH() * 0.5){
     hookFocus = true;
   }

  if (i->isActive(SDL_SCANCODE_W)) {
    dir = false;
    if(profondeur <= borders.getH() * 0.5){
      if (obj->getY() - speed <= 150 ) {
	depY -= obj-> getY() - 150 ;
      }
      else{
	depY -= speed;
      }
      if(!hookFocus){
	focus += speed;
      }
    }else{
      focus += speed;
      profondeur -= speed;
    }
  }

  if (i->isActive(SDL_SCANCODE_S)) {
    if (!hookFocus){
      dir = true;
      if (obj->getY() + obj->getH() + speed >= 720) {
	depY += 720 - obj->getY() - obj->getH();
      }
      else{
	depY += speed;
      }

      if(hookFocus){
	focus -= speed;
      }
    }else{
      focus -= speed;
      profondeur += speed;
    }
  }

  obj->move(depX, depY);
  if( objets["Ocean"]->getY() + objets["Ocean"]->getH() <= -10 && dir == true){
    objets["Ocean"]->move(0,objets["Ocean"]->getH() * 2);
  }
  if( objets["Ocean2"]->getY() + objets["Ocean2"]->getH() <= -10 && dir == true){
    objets["Ocean2"]->move(0,objets["Ocean2"]->getH() * 2);
  }

  if( objets["Ocean"]->getY() == objets["Ocean"]->getH() && dir == false){
    objets["Ocean"]->move(0,-objets["Ocean"]->getH() * 2);
  }
  if( objets["Ocean2"]->getY() == objets["Ocean2"]->getH() && dir == false){
    objets["Ocean2"]->move(0,-objets["Ocean2"]->getH() * 2);
  }

  objets["Ciel"]->move(0,focus);
  objets["Ocean2"]->move(0,focus);
  objets["Ocean"]->move(0,focus);
  objets["Bateau"]->move(0,focus);

}
