function ransomNote(magazine, ransom) {
  let words = {};
  let result = '';
  magazine.forEach(word => {
    words[word] ? words[word]++ : words[word] = 1;
  })
  ransom.forEach(word => {
    if (words[word]) {
      words[word]--;
      if (words[word] < 0) {
        result = 'No';
      }
    } else {
      result = 'No';
    }
  })

  if (result.length === 0) result = 'Yes';
  return result;
}
