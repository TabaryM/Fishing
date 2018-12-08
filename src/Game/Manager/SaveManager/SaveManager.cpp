#include "SaveManager.hpp"

SaveManager::SaveManager(Stage* s) : s(s){}

void SaveManager::load(std::vector<Fish*>& fishs, Score* score, Timer* timer) {
  std::ifstream file("stages/niveau_1.txt");

  std::string line;
  int x, y, t, g;
  int type;
  if(file){
    std::getline(file, line);
    std::getline(file, line);
    std::stringstream parserT(line);
    parserT >> t ;

    std::getline(file, line);
    std::stringstream parserG(line) ;
    parserG >> g ;

    while(std::getline(file, line)) {
      std::stringstream parser(line);
      parser >> type;
      x = rand()%990;
      y = rand()%1600;
      fishs.push_back(new Fish(s->getRenderer(), Vector2D<int>(x, (y + 180)), 6, type)) ;
    }
    score->setGoal(g) ;
    timer->setValue(t) ;
    int max = 0;
    for (Fish* f : fishs){
      max += f->getPoints();
    }
  }
}

void SaveManager::save(Score* sc) {
  std::ofstream file("scores/score.txt");
  time_t now = time(0) ;
  tm *ltm = localtime(&now) ;
  if(file) {
    file << "\nJoueur : " << "nomJoueur" << "\nScore : " << sc->getValue() << "\nDate : " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\nHeure : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec ;
  }
}
