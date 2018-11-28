#include "SaveManager.hpp"

SaveManager::SaveManager(Stage* s) : s(s){}

void SaveManager::loadFishs(std::vector<Fish*>& fishs) {
  std::ifstream file("stages/niveau_1.txt");

  std::string line;
  int x, y;
  int type;
  //char trash;
  if(file){
    std::getline(file, line);
    while(std::getline(file, line)) {
      std::stringstream parser(line);
      parser >> type;
      x = rand()%990;
      y = rand()%1800;
      fishs.push_back(new Fish(s->getRenderer(), Vector2D<int>(x, (y + 180)), 6.0, type)) ;
    }
  }
}

void SaveManager::save(Score* sc) {
  std::ofstream file("Score/score.txt");
  time_t now = time(0) ;
  tm *ltm = localtime(&now) ;
  if(file) {
    file << "\nJoueur : " << "nomJoueur" << "\nScore : " << sc->getValue() << "\nDate : " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\nHeure : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec ;
  }
}
