function largestOverlap(img1: number[][], img2: number[][]): number {
  const shiftUp = (img: number[][]) => {
    img.push(Array(img.length).fill(0));
    img.shift();
  };
  const shiftDown = (img: number[][]) => {
    img.unshift(Array(img.length).fill(0));
    img.pop();
  };
  const shiftLeft = (img: number[][]) => {
    img.forEach((row) => {
      row.push(0);
      row.shift();
    });
  };
  const shiftRight = (img: number[][]) => {
    img.forEach((row) => {
      row.unshift(0);
      row.pop();
    });
  };

  const countOverlap = (img1: number[][], img2: number[][]) => {
    let count = 0;
    for (let i = 0; i < img1.length; i++) {
      for (let j = 0; j < img1[0].length; j++) {
        if (img1[i][j] === 1 && img2[i][j] === 1) {
          count++;
        }
      }
    }
    return count;
  };

  let maxOverlap = 0;

  for (let i = 0; i < img1.length; i++) {
    for (let j = 0; j < img1[0].length; j++) {
      let copy = JSON.parse(JSON.stringify(img1));
      shiftRight(img1);
      maxOverlap = Math.max(maxOverlap, countOverlap(img1, img2));
      shiftLeft(img1);
      maxOverlap = Math.max(maxOverlap, countOverlap(img1, img2));
      shiftUp(img1);
      maxOverlap = Math.max(maxOverlap, countOverlap(img1, img2));
      shiftDown(img1);
      maxOverlap = Math.max(maxOverlap, countOverlap(img1, img2));
    }
  }
  return maxOverlap;
}