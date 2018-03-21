bool compare(const Player &p1, const Player &p2) {
  if (p1.score < p2.score) return false;
  else if (p1.score > p2.score) return true;
  else return (p1.name < p2.name);
}

vector<Player> comparator(vector<Player> players) {
  sort(players.begin(), players.end(), compare);
  return players;
}