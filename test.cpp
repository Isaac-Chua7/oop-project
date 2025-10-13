#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
 private:
  string name;
  int pts;
  int reb;
  int ast;

 public:
  Player(string n, int p, int r, int a) : name(n), pts(p), reb(r), ast(a) {};
  int getPoints() { return pts; }
  string getName() { return name; }
};

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};

  v.push_back(6);

  v = {6, 7, 6, 7};

  v.pop_back();

  v.erase(v.begin() + 2);

  v[1] = 88;

  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << std::endl;
  }

  cout << endl << "new stuff with player class" << endl;

  std::vector<Player*> myPlayers;

  Player LeBron("Lebron", 25, 8, 8);

  Player Jokic("Jokic", 29, 11, 10);

  myPlayers.push_back(&LeBron);

  myPlayers.push_back(&Jokic);

  Player* Shai = new Player("Shai", 31, 6, 6);

  myPlayers.push_back(Shai);

  for (int i = 0; i < myPlayers.size(); i++) {
    cout << myPlayers[i]->getName() << " is averaging a whopping "
         << myPlayers[i]->getPoints() << " pts per game" << endl;
  }

  return 0;
}