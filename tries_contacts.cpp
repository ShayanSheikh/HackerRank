#include <string>

using namespace std;

int index_of(char letter) { return int(letter) - 97; };

class Trie {
public:
  Trie();
  Trie(char);
  void add_contact(string contact);
  int match_contact(string contact);

private:
  Trie* alphabet [26];
  char letter;
  int count;
};

Trie::Trie() {
  letter = 'a';
  count = 0;
}

Trie::Trie(char l) {
  letter = l;
  count = 0;
}

void Trie::add_contact(string contact) {
  Trie *curr = this;
  int nextInd;
  for (int i = 0; i < contact.size(); i++) {
    contact[i] = tolower(contact[i]);
    curr->count += 1;
    nextInd = index_of(contact[i]);
    if(!curr->alphabet[nextInd]) {
      curr->alphabet[nextInd] = new Trie;
      curr->alphabet[nextInd]->letter = contact[i];
    }
    curr = curr->alphabet[index_of(contact[i])];
  }
}

int Trie::match_contact(string contact) {
  Trie *curr = this;
  int nextInd;
  for (int i = 0; i < contact.size(); i++) {
    contact[i] = tolower(contact[i]);
    nextInd = index_of(contact[i]);
    if (!curr->alphabet[nextInd])
      return 0;
    curr = curr->alphabet[nextInd];
  }
  return curr->count;
}
