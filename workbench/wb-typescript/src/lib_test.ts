import { assertEquals } from "https://deno.land/std@0.84.0/testing/asserts.ts";

import { isPowerOfTwo } from "./lib.ts";

Deno.test("GG #1", () => {
  assertEquals(isPowerOfTwo(1), true);
});

Deno.test("GG #2", () => {
  assertEquals(isPowerOfTwo(16), true);
});

Deno.test("GG #3", () => {
  assertEquals(isPowerOfTwo(3), false);
});

Deno.test("GG #4", () => {
  assertEquals(isPowerOfTwo(5), false);
});

Deno.test("GG #5", () => {
  assertEquals(isPowerOfTwo(0), false);
  assertEquals(isPowerOfTwo(-1), false);
  assertEquals(isPowerOfTwo(-2), false);
  assertEquals(isPowerOfTwo(-3), false);
});
