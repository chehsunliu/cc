export function fizzBuzz(n: number): string[] {
  return new Array(n).fill(0).map((_, index) => index + 1).map((value) => {
    if (value % 3 === 0 && value % 5 === 0) {
      return "FizzBuzz";
    } else if (value % 3 === 0) {
      return "Fizz";
    } else if (value % 5 === 0) {
      return "Buzz";
    } else {
      return `${value}`;
    }
  });
}
