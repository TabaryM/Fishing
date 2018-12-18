#include "GameManager.hpp"


GameManager::GameManager(Stage* s, Input* i) : Manager(s, i), speed(7), profondeur(150), focus(0) , borders(Vector2D<int>(Window::WIDTH, Window::HEIGHT)) {}

void GameManager::create(){
  objets["Ciel"] = new Object(s->getRenderer(), new Surface("sprites/Sky.png"), Vector2D<int>(0, 0), 1.2);
  objets["Ocean"] = new Object(s->getRenderer(), new Surface(Vector2D<int>(borders.getSize().getX(), borders.getSize().getY()+2000), 0, 102, 204, 255), Vector2D<int>(0, borders.getSize().getY()*0.22), 1);
  objets["Seabed"] = new Object(s->getRenderer(), new Surface("sprites/Seabed.png"), Vector2D<int>(0, 2300), 2);
  objets["Bateau"] = new Boat(s->getRenderer(), Vector2D<int>(500, objets["Ciel"]->getH() - 58), 1.5);
  objets["Hook"] = new Hook(s->getRenderer(), Vector2D<int>(objets["Bateau"]->getX() + 0.5 * objets["Bateau"]->getSize().getX() +6 , objets["Bateau"]->getY() + 60 ),5);
  objets["Kappa"] = new Object(s->getRenderer(), new Surface("sprites/Kappa.png"), Vector2D<int>(objets["Bateau"]->getX() + 0.82 * objets["Bateau"]->getSize().getX(), objets["Bateau"]->getY() - 46) , 3);
  objets["FishPole"] = new Object(s->getRenderer(), new Surface("sprites/FishPole.png"), Vector2D<int>(objets["Kappa"]->getX()-97, objets["Kappa"]->getY()-50) , objets["Bateau"]->getZ());
  objets["Bateau"]->link(objets["Kappa"]);
  objets["Kappa"]->link(objets["FishPole"]);
  objets["FishPole"]->link(objets["Hook"]);
  objets["HookHitbox"] = objets["Hook"]->getChild().front();


  for (int i = 0; i < 14; i++) {
    objets["Wave" + std::to_string(i)] = new Wave(s->getRenderer(), Vector2D<int>(98.5 * (i-1), objets["Ciel"]->getH() - 15), 1.7);
    objets["Ciel"]->link(objets["Wave" + std::to_string(i)]);
  }

  static_cast <Score*>(objets["Score"])->initScore(s->getRenderer());
  static_cast <Timer*>(objets["Timer"])->updateTimer(s->getRenderer());

  objets["Objectif"] = new Object(s->getRenderer(), new Surface(&f, "/" + std::to_string(static_cast <Score*>(objets["Score"])->getGoal())), Vector2D<int>(1140, 0), objets["Score"]->getZ()) ;

  Manager::create();
}

void GameManager::update(){
  static_cast <Score*>(objets["Score"])->addScore(s->getRenderer(), 0);
  static_cast <Timer*>(objets["Timer"])->sec(s->getRenderer(), -1);

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
      }

    }
    if((objets["Fish" + std::to_string(i)]->getY()) + (1 * static_cast <Fish*> (objets["Fish" + std::to_string(i)])->getDegre()) < borders.getH()*0.3 - profondeur){
      static_cast <Fish*> (objets["Fish" + std::to_string(i)])->setDegre(0);
    }
    //flip the hitbox
    if(objets["Fish" + std::to_string(i)]->getChild().front()->getX() == objets["Fish" + std::to_string(i)]->getX() && !objets["Fish" + std::to_string(i)]->isFliped()){
      objets["Fish" + std::to_string(i)]->getChild().front()->move(Vector2D<int>(objets["Fish" + std::to_string(i)]->getW() - objets["Fish" + std::to_string(i)]->getChild().front()->getW(),0));
    }
    else if(objets["Fish" + std::to_string(i)]->getChild().front()->getX() == objets["Fish" + std::to_string(i)]->getX() + objets["Fish" + std::to_string(i)]->getW() - objets["Fish" + std::to_string(i)]->getChild().front()->getW() && objets["Fish" + std::to_string(i)]->isFliped()){
      objets["Fish" + std::to_string(i)]->getChild().front()->move(Vector2D<int>(-objets["Fish" + std::to_string(i)]->getW()+ objets["Fish" + std::to_string(i)]->getChild().front()->getW(),0));
    }
  }

  for (unsigned int i = 0; i < fishs.size(); i++) {
    if(!static_cast <Fish*>(objets["Fish" + std::to_string(i)])->isHooked()){
      if( ((objets["Fish" + std::to_string(i)]->getY()) < objets["Bateau"]->getY() + objets["Bateau"]->getH()) || ((objets["Fish" + std::to_string(i)]->getY() + (objets["Fish" + std::to_string(i)]->getH()) > objets["Seabed"]->getY()))){
        static_cast <Fish*>(objets["Fish" + std::to_string(i)])->setDegre(10 + (static_cast <Fish*>(objets["Fish" + std::to_string(i)])->getDegre()));
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
          if (o1->getType() == HOOK && o2->getType() == FISH  && !static_cast <Fish*>(o2)->isHooked() && o1->getChild().front()->getChild().size() == 0) {
            if((o1->isFliped() && o2->isFliped()) || (!o1->isFliped() && !o2->isFliped())){
              static_cast <Fish*>(o2)->setHook();
              o2->depend();
              o1->getChild().front()->link(o2);
            }
          }
          //check if you scored a FISH
          if (o1->getType() == HOOK && o2->getType() == BOAT) {
            //si o1 (HOOK) possède un enfant de type FISH dont le lequel isHooked = true
            if((o1->getChild().front()->getChild().size())>0 && o1->getY() <= 100) {
              // - actualiser score
              static_cast <Fish*>(o1->getChild().front()->getChild().front())->getPoints(s->getRenderer(), static_cast <Score*>(objets["Score"]));
              //sortObject();
              (o1->getChild().front()->getChild().front())->move(Vector2D<int>(-5000,0));//"remove" fishes
              std::vector<Object*>().swap(o1->getChild().front()->getChild());
            }
          }
        }, it2.second);
      }
  }
}

void GameManager::render(){
  Manager::render();
  //dessine la ligne
  if(!objets["Hook"]->isFliped()){
    s->draw(objets["Hook"]->getX() + objets["Hook"]->getW() -2.5, objets["Hook"]->getY() +0.05*objets["Hook"]->getH(), objets["FishPole"]->getX(), objets["FishPole"]->getY());
  }else{
    s->draw(objets["Hook"]->getX() +2.5, objets["Hook"]->getY() +0.05*objets["Hook"]->getH(), objets["FishPole"]->getX(), objets["FishPole"]->getY());
  }
}

void GameManager::destroy(){
  removeFishs();
  Manager::destroy();
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
    if(objets["Hook"]->isFliped() && objets["Hook"]->getChild().front()->getChild().size() ==0){
      objets["Hook"]->isFlip();
      objets["Hook"]->move(Vector2D<int>(-objets["Hook"]->getW() +3.5,0));
    }
  }

  if (i->isActive(SDL_SCANCODE_D)) {
    if (obj->getX() + obj->getW() + speed >= Window::WIDTH) {
      dep.setX(dep.getX() + Window::WIDTH - obj->getW() - obj->getX());
    }
    else{
      dep.setX(dep.getX() + speed);
    }
    if(!objets["Hook"]->isFliped() && objets["Hook"]->getChild().front()->getChild().size() ==0 ){
      objets["Hook"]->isFlip();
      objets["Hook"]->move(Vector2D<int>(objets["Hook"]->getW() -3.5,0));
    }
  }

  if (i->isActive(SDL_SCANCODE_E)) {
    if (speed < 15) {
      speed++;
    }
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
      if (profondeur+obj->getH() + 80 + speed <= fondMarin + borders.getH() * 0.5) {
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

  if(!hookFocus && !fond){
    dep2.setY(-objets["Ciel"]->getY());
    focus = -objets["Ciel"]->getY();
  }

  if(objets["Ocean"]->getY() < -objets["Ocean"]->getH() && dirDown){
    objets["Ocean"]->move(Vector2D<int>(0,2 * objets["Ocean2"]->getH()));
  }

  obj->move(dep);
  objets["Ciel"]->move(dep2);
  objets["Seabed"]->move(dep2);
  objets["Bateau"]->move(dep2);
  objets["Ocean"]->move(dep2);
}

std::vector<Fish*>& GameManager::getFishs(){
  return fishs;
}

void GameManager::resetCamera(){
  Vector2D<int> dep;
  dep.setY(-profondeur);
  if (profondeur >= Window::WIDTH/2){
    for (unsigned int i = 0; i < fishs.size(); i++){
      objets["Fish"+std::to_string(i)]->move(dep);
    }
    objets["Ciel"]->move(dep);
    objets["Seabed"]->move(dep);
    objets["Bateau"]->move(dep);
    objets["Ocean"]->move(dep);
    profondeur = 150;
  }
}

void GameManager::fillFish(){
  for (unsigned int i = 0; i < fishs.size(); i++) {
    objets["Fish" + std::to_string(i)] = fishs[i];
    objets["Hitbox" + std::to_string(i)] = objets["Fish" + std::to_string(i)]->getChild().front();
  }
}

void GameManager::initST() {
  objets["Score"] = new Score(s->getRenderer(), Vector2D<int>(810, 0), 500, &f);
  objets["Timer"] = new Timer(s->getRenderer(), Vector2D<int>(0, 0), 500, &f);
}

void GameManager::cleanOld(){
    resetCamera();
    emptyHook();
    removeFishs();
    static_cast <Score*> (objets["Score"])->reset();
}

void GameManager::setObjectif(){
  delete objets["Objectif"];
  objets["Objectif"] = new Object(s->getRenderer(), new Surface(&f, "/" + std::to_string(static_cast <Score*>(objets["Score"])->getGoal())), Vector2D<int>(1140, 0), objets["Score"]->getZ()) ;
}

void GameManager::sort(){
  Manager::sortObject();
}

void GameManager::emptyHook(){
  std::vector<Object*>().swap(objets["Hook"]->getChild().front()->getChild());
}

void GameManager::removeFishs(){
  for (auto i = 0u; i < fishs.size(); i++) {
      objets.erase("Fish" + std::to_string(i));      // On retire le poisson de la map
      objets.erase("Hitbox" + std::to_string(i)); // On retire sa hit box
      delete fishs[i]->getChild().front(); // On delete sa hitbox
      fishs[i]->getChild().front() = nullptr;
      delete fishs[i]; // On delete le fish
      fishs[i] = nullptr;
  }
  std::vector<Fish*>().swap(fishs); // On vide le vecteur
}
