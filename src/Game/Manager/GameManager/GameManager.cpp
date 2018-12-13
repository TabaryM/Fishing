#include "GameManager.hpp"


GameManager::GameManager(Stage* s, Input* i) : Manager(s, i), speed(1), profondeur(150), focus(0) , borders(Vector2D<int>(Window::WIDTH, Window::HEIGHT)) {}

void GameManager::create(){
  objets["Ciel"] = new Object(s->getRenderer(), new Surface("sprites/Sky.png"), Vector2D<int>(0, 0), 1.2);
  objets["Ocean"] = new Object(s->getRenderer(), new Surface(Vector2D<int>(borders.getSize().getX(), borders.getSize().getY()), (char)0, (char)102, (char)204, (char)255), Vector2D<int>(0, borders.getSize().getY()*0.22), 1);
  objets["Ocean2"] = new Object(s->getRenderer(), new Surface(Vector2D<int>(borders.getSize().getX(),borders.getSize().getY()), (char)0, (char)102, (char)204, (char)255), Vector2D<int>(0, borders.getSize().getY()+borders.getSize().getY()*0.22), 1);
  objets["Bateau"] = new Boat(s->getRenderer(), Vector2D<int>(500, objets["Ciel"]->getH() - 58), 1.5);
  objets["Hook"] = new Hook(s->getRenderer(), Vector2D<int>(objets["Bateau"]->getX() + 0.5 * objets["Bateau"]->getSize().getX() , objets["Bateau"]->getY() + 60 ),5);
  objets["Kappa"] = new Object(s->getRenderer(), new Surface("sprites/Kappa.png"), Vector2D<int>(objets["Bateau"]->getX() + 0.82 * objets["Bateau"]->getSize().getX(), objets["Bateau"]->getY() - 46) , 3);
  objets["FishPole"] = new Object(s->getRenderer(), new Surface("sprites/FishPole.png"), Vector2D<int>(objets["Kappa"]->getX()-98, objets["Kappa"]->getY()-50) , objets["Bateau"]->getZ());
  std::cout << "begin create Score" << std::endl;
  objets["Score"] = new Score(s->getRenderer(), Vector2D<int>(1000, 200), 500, &f);
  std::cout << "begin create Timer" << std::endl;
  objets["Timer"] = new Timer(s->getRenderer(), Vector2D<int>(0, 200), 500, &f);
  objets["Bateau"]->link(objets["Kappa"]);
  objets["Kappa"]->link(objets["FishPole"]);
  objets["FishPole"]->link(objets["Hook"]);

  for (int i = 0; i < 14; i++) {
    objets["Wave" + std::to_string(i)] = new Wave(s->getRenderer(), Vector2D<int>(98.5 * (i-1), objets["Ciel"]->getH() - 15), 1.7);
    objets["Ciel"]->link(objets["Wave" + std::to_string(i)]);
  }
  Manager::create();

}

void GameManager::update(){

  //static_cast <Timer*>(objets["Timer"])->sec(-1);
  //std::cout << static_cast <Timer*>(objets["Timer"])->getValue() << std::endl;

  for (unsigned int i = 0; i < fishs.size(); i++) {
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

      if(!objets["Fish" + std::to_string(i)]->isFliped()) {
        objets["Fish" + std::to_string(i)]->flipingTo(false);
      }

    }
    if((objets["Fish" + std::to_string(i)]->getX() + objets["Fish" + std::to_string(i)]->getW() ) + (1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir()) > borders.getW()){
      static_cast <Fish*> (objets["Fish" + std::to_string(i)])->setRight(1);

      if(!objets["Fish" + std::to_string(i)]->isFliped()) {
        objets["Fish" + std::to_string(i)]->isFlip();
      } else {
        objets["Fish" + std::to_string(i)]->isFlip() ;
      }

    }
    if((objets["Fish" + std::to_string(i)]->getY()) + (1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDegre()) < borders.getH()*0.3 - profondeur){
      static_cast <Fish*> (objets["Fish" + std::to_string(i)])->setDegre(0);
    }
  }

  for (unsigned int i = 0; i < fishs.size(); i++) {
    if(!static_cast <Fish*>(objets["Fish" + std::to_string(i)])->isHooked()){
      if( (objets["Fish" + std::to_string(i)]->getY()) <= 170){
        static_cast <Fish*>(objets["Fish" + std::to_string(i)])->setDir( - (static_cast <Fish*>(objets["Fish" + std::to_string(i)])->getDir()));
      }
      objets["Fish" + std::to_string(i)]->move(Vector2D<int>(1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir(), 0.5 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDir() + focus));
    }
  }

  for (int i = 0; i < 14; i++) {
    if(objets["Wave" + std::to_string(i)]->getX() >=1280 ){
      objets["Wave" + std::to_string(i)]->move(Vector2D<int>(-1280-98.5,0));
    }
    objets["Wave" + std::to_string(i)]->move(Vector2D<int>(1,0));
  }

  updateControlX(objets["Bateau"]);
  updateControlY(objets["Hook"]);

  for (auto& it1 : objets){
    for (auto& it2 : objets) {
        it1.second->collide([&](Object* o1, Object* o2) {
          if (o1->getType() == HOOK && o2->getType() == FISH && !static_cast <Fish*>(o2)->isHooked() && o1->getChild().size() == 0 ) {
            static_cast <Fish*>(o2)->setHook();
            o1->link(o2);
          }
          //check if you scored a FISH
          if (o1->getType() == HOOK && o2->getType() == BOAT) {
            //si o1 (HOOK) possède un enfant de type FISH dont le lequel isHooked = true
            if((o1->getChild().size())>0 && o1->getY() <= 100) {
              std::cout << "Fished a fish !" << std::endl;

              (o1->getChild().front())->move(Vector2D<int>(-5000,0));//"remove" fishes
              std::vector<Object*>().swap(o1->getChild());
              // - actualiser score
              static_cast <Score*>(objets["Score"])->addScore(s->getRenderer(), 10);
              std::cout << static_cast <Score*>(objets["Score"])->getValue() << std::endl;
              //sortObject();
            }
          }
        }, it2.second);
      }
  }
}


void GameManager::render(){
  Manager::render();
  //dessine la ligne
  s->draw(objets["Hook"]->getX() + 0.5*objets["Hook"]->getW() , objets["Hook"]->getY() +0.15*objets["Hook"]->getH(), objets["FishPole"]->getX(), objets["FishPole"]->getY());
}

void GameManager::destroy(){
  std::vector<Fish*>().swap(fishs);
}

void GameManager::updateControlX(Object* obj) {
  Vector2D<int> dep;

  if (i->isActive(SDL_SCANCODE_A)) {
    if (obj->getX() -speed <= 0 ) {
      dep.setX(dep.getX() - obj->getX());
    }
    else{
      dep.setX(dep.getX() - speed);
    }
  }

  if (i->isActive(SDL_SCANCODE_D)) {
    if (obj->getX() + obj->getW() + speed >= Window::WIDTH) {
      dep.setX(dep.getX() + Window::WIDTH - obj->getW() - obj->getX());
    }
    else{
      dep.setX(dep.getX() + speed);
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

  obj->move(dep);
}
void GameManager::updateControlY(Object* obj) {
  Vector2D<int> dep;
  Vector2D<int> dep2;
  int fondMarin = 2000;
  bool fond = false;
  bool hookFocus = false;
  bool dirDown = false;
  bool dirUp = false;
  focus = 0;
  if(profondeur >= borders.getH() * 0.5 && profondeur < fondMarin  ){
    hookFocus = true;
  }

  if(profondeur > fondMarin ){
    fond = true;
  }

  if (i->isActive(SDL_SCANCODE_W)) {
    dirUp = true;
    if(!hookFocus){
      if (obj->getY() - speed <= 100 ) {
        dep.setY(100 - obj->getY());
      }
      else{
        dep.setY(-speed);
      }
      profondeur -= speed;
    }
    else{
      focus += speed;
      dep2.setY(focus);
      profondeur -= speed;
    }
  }

  if (i->isActive(SDL_SCANCODE_S)) {
    dirDown = true;
    if (!hookFocus){
      if (profondeur + obj->getH() + speed <= fondMarin + borders.getH() * 0.5) {
      	dep.setY(speed);
      }
      profondeur += speed;
    }else{
      focus -= speed;
      dep2.setY(focus);
      profondeur += speed;
    }
  }

  if(profondeur < 150 ){
    profondeur = 150;
  }
  if(hookFocus && dirDown){
    dep.setY(speed);
  }
  if(hookFocus && dirUp){
    dep.setY(-speed);
  }

  if(!hookFocus && fond){
    dep2.setY(-objets["Ciel"]->getY());
    focus = -objets["Ciel"]->getY();
  }

  if(objets["Ocean"]->getY() < -objets["Ocean"]->getH() && dirDown){
    objets["Ocean"]->move(Vector2D<int>(0,2 * objets["Ocean2"]->getH()));
  }

  if(objets["Ocean2"]->getY() < -objets["Ocean2"]->getH() && dirDown){
    objets["Ocean2"]->move(Vector2D<int>(0,2 * objets["Ocean"]->getH()));
  }

  if(objets["Ocean"]->getY() > borders.getH() && dirUp){
    objets["Ocean"]->move(Vector2D<int>(0,-2 * objets["Ocean2"]->getH()));
  }

  if(objets["Ocean2"]->getY() > borders.getH() && dirUp){
    objets["Ocean2"]->move(Vector2D<int>(0,-2  * objets["Ocean"]->getH()));
  }

  obj->move(dep);
  objets["Ciel"]->move(dep2);
  objets["Bateau"]->move(dep2);
  objets["Ocean"]->move(dep2);
  objets["Ocean2"]->move(dep2);
}

std::vector<Fish*>& GameManager::getFishs(){
  return fishs;
}

void GameManager::fillFish(){
  for (unsigned int i = 0; i < fishs.size(); i++) {
    objets["Fish" + std::to_string(i)] = fishs[i];
  }
}
