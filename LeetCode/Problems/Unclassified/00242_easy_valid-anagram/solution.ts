let createHist = (s: string): number[] =>
  [...s].reduce((acc, c) => {
    acc[c.charCodeAt(0) - "a".charCodeAt(0)] += 1;
    return acc;
  }, new Array(26).fill(0).map((_) => 0));

export function isAnagram(s: string, t: string): boolean {
  let h1: number[] = createHist(s);
  let h2: number[] = createHist(t);

  return h1.length === h2.length &&
    h1.every((value, index) => value === h2[index]);
}
