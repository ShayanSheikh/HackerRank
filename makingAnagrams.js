function anagram(a, b) {
  a = a.toLowerCase();
  b = b.toLowerCase();
  if (a.length < b.length)[a, b] = [b, a];
  let letters = {};
  let result = 0;
  for (let i = 0; i < a.length; i++) {
    letters[a[i]] ? ++letters[a[i]] : letters[a[i]] = 1;
  }
  for (let i = 0; i < b.length; i++) {
    letters[b[i]] ? --letters[b[i]] : letters[b[i]] = 1;
  }
  for (let key in letters) {
    if (letters.hasOwnProperty(key)) {
      result += Math.abs(letters[key]);
    }
  }
  console.log(result);
}
