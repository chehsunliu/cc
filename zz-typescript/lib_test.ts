import { assertEquals } from "https://deno.land/std@0.84.0/testing/asserts.ts";

import { reverseString } from "./lib.ts";

Deno.test("GG #1", () => {
  let s = ["h", "e", "l", "l", "o"];
  reverseString(s);
  assertEquals(s.join(), ["o", "l", "l", "e", "h"].join());
});

Deno.test("GG #2", () => {
  let s = ["H", "a", "n", "n", "a", "h"];
  reverseString(s);
  assertEquals(s.join(), ["h", "a", "n", "n", "a", "H"].join());
});
