import { assertEquals } from "https://deno.land/std@0.84.0/testing/asserts.ts";

import { firstUniqChar } from "./lib.ts";

Deno.test("GG #1", () => {
  assertEquals(firstUniqChar("leetcode"), 0);
});

Deno.test("GG #2", () => {
  assertEquals(firstUniqChar("loveleetcode"), 2);
});
