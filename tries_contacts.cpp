#include <string>

using namespace std;

int index_of(char letter) { return int(letter) - 97; };

class Trie {
public:
  Trie(char);
  void add_contact(string contact);
  int match_contact(string contact);

private:
  Trie* alphabet [26];
  char letter;
  int count;
};

Trie::Trie(char l) {
  letter = l;
  count = 0;
}

void Trie::add_contact(string contact) {
  Trie *curr = this;
  for (int i = 0; i < contact.size(); i++) {
    contact[i] = tolower(contact[i]);
    curr->count += 1;
    if(!curr->alphabet[index_of(contact[i])])
      curr->alphabet[index_of(contact[i])] = new Trie(contact[i]);
    curr = curr->alphabet[index_of(contact[i])];
  }
}

int Trie::match_contact(string contact) {
  Trie *curr = this;
  for (int i = 0; i < contact.size(); i++) {
    contact[i] = tolower(contact[i]);
    if (!curr->alphabet[index_of(contact[i])])
      return 0;
    curr = curr->alphabet[index_of(contact[i])];
  }
  return curr->count;
}
