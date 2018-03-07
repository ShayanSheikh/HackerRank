function processData(input) {
  let entries = input.split('\n');
  let queue = [];
  function enqueue(val) {
    queue.push(val);
  }
  function dequeue() {
    queue.shift(1);
  }
  function peek() {
    if (queue.length > 0) console.log(queue[0]);
  }

  for (let i = 1; i < entries.length; i++) {
    let curr = entries[i].split(' ');
    switch (curr[0]) {
      case '1':
        enqueue(curr[1]);
        break;
      case '2':
        dequeue();
        break;
      case '3':
        peek();
        break;
      default:
        break;
    }
  }
}
