#include "SaveManager.hpp"

SaveManager::SaveManager(Stage* s) : s(s) {}

void SaveManager::load(std::vector<Fish*>& fishs) {
  std::ifstream file("stages/niveau_1.txt");

  std::string line;
  int x, y;
  int type;
  char trash;
  if(file){
    std::getline(file, line);
    while(std::getline(file, line)) {
      std::stringstream parser(line);
      parser >> x >> trash >> y >> trash >> type;
      fishs.push_back(new Fish(s->getRenderer(), Vector2D<int>(50 + x *10, 190 + y * 10), 6.0, type)) ;
    }
  }
}

void SaveManager::save(std::vector<Fish*>& fishs) {
  std::ofstream file("stages/niveau_1.txt");

  if(file) {
    file << '\n' ;
    std::cout << "Ajout de la ligne moche" << std::endl ;
    for(Fish* f : fishs) {
      std::cout << ((f->getX() - 50) / 10) << '-' << ((f->getY() - 190) / 10) << '-' << f->getTypeFish() << '\n' << std::endl ;
      file << ((f->getX() - 50) / 10) << '-' << ((f->getY() - 190) / 10) << '-' << f->getTypeFish() << '\n' ;
    }
  }
}
