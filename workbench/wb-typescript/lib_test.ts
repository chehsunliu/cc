import { assertEquals } from "https://deno.land/std@0.84.0/testing/asserts.ts";

import { isAnagram } from "./lib.ts";

Deno.test("GG #1", () => {
  assertEquals(isAnagram("anagram", "nagaram"), true);
});

Deno.test("GG #2", () => {
  assertEquals(isAnagram("rat", "car"), false);
});
