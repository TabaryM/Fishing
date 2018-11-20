#include "SaveManager.hpp"

SaveManager::SaveManager(Stage* s) : s(s) {}

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
      y = rand()%550;
      fishs.push_back(new Fish(s->getRenderer(), Vector2D<int>(x+144, y), 6.0, type)) ;
    }
  }
}

void SaveManager::save() {
  std::ofstream file("Score/score.txt");

  if(file) {
    file << "\nJoueur : " << "nomJoueur" << "\nScore : " << "score" << "\nDate : " << "date" ;
  }
}
