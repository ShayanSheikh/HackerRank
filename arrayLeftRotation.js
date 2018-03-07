function leftRotate(arr, degree) {
  let result = [];
  let newInd;
  for (let i = 0; i < arr.length; i++) {
    newInd = i - degree;
    if (newInd < 0) newInd = arr.length + newInd;
    result[newInd] = arr[i];
  }
  return result.join(' ');
}
