export function reverseString(s: string[]): void {
  for (let index = 0; index < Math.floor(s.length / 2); index++) {
    let tmp: string = s[index];
    s[index] = s[s.length - index - 1];
    s[s.length - index - 1] = tmp;
  }
}
