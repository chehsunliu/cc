let divideThoroughlyByFactor = (num: number, factor: number): number => {
  while (num % factor === 0) {
    num = Math.floor(num / factor);
  }
  return num;
};

export function isUgly(num: number): boolean {
  if (num === 1) {
    return true;
  } else if (num < 1) {
    return false;
  }

  num = divideThoroughlyByFactor(num, 2);
  num = divideThoroughlyByFactor(num, 3);
  num = divideThoroughlyByFactor(num, 5);
  return num === 1;
}
