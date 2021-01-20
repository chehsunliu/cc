import { assertEquals } from "https://deno.land/std@0.84.0/testing/asserts.ts";

import { isUgly } from "./lib.ts";

Deno.test("GG #1", () => {
  assertEquals(isUgly(6), true);
});

Deno.test("GG #2", () => {
  assertEquals(isUgly(8), true);
});

Deno.test("GG #3", () => {
  assertEquals(isUgly(14), false);
});

Deno.test("GG #4", () => {
  assertEquals(isUgly(1), true);
  assertEquals(isUgly(0), false);
  assertEquals(isUgly(-1), false);
  assertEquals(isUgly(288637140), false);
});
