let createHist = (s: string): number[] =>
  [...s]
    .reduce((acc, c) => {
      acc[c.charCodeAt(0) - "a".charCodeAt(0)] += 1;
      return acc;
    }, new Array(26).fill(0).map((_) => 0));

export function firstUniqChar(s: string): number {
  let hist = createHist(s);
  let indices: number[] = [...s]
    .map((c, index) =>
      hist[c.charCodeAt(0) - "a".charCodeAt(0)] === 1 ? index : -1
    )
    .filter((index) => index >= 0);

  return indices.length === 0 ? -1 : indices[0];
}
