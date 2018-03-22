function Trie(_letter) {
  this.letter = _letter || null;
  this.alphabet = {};
  this.count = 0;
}

Trie.prototype.insert = function (contact) {
  let curr = this;
  for (let i = 0; i < contact.length; i++) {
    if (!curr.alphabet[contact[i]]) curr.alphabet[contact[i]] = new Trie(contact[i]);
    curr = curr.alphabet[contact[i]];
    curr.count = curr.count + 1;
  }
}

Trie.prototype.check = function (contact) {
  let curr = this;
  for (let i = 0; i < contact.length; i++) {
    if (!curr.alphabet[contact[i]]) return 0;
    curr = curr.alphabet[contact[i]];
  }
  return curr.count;
}
