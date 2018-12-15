#include "SaveManager.hpp"

SaveManager::SaveManager(Stage* s) : s(s){}

void SaveManager::load(std::vector<Fish*>& fishs, Score* score, Timer* timer, std::string lvl) {
  std::ifstream file(lvl);

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
    int max = 0;

    while(std::getline(file, line)) {
      std::stringstream parser(line);
      parser >> type;
      x = rand()%990 + 1;
      y = rand()%1600;
      fishs.push_back(new Fish(s->getRenderer(), Vector2D<int>(x, (y + 180)), 6, type)) ;
      if (type != 4){
        max += fishs.back()->getPoints();
      }
    }
    score->setGoal(g) ;
    timer->setValue(t) ;
    score->setMax(max) ;
    std::cout << "Goal :\t" << g << std::endl;
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
