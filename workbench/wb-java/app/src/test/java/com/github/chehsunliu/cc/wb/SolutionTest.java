package com.github.chehsunliu.cc.wb;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class SolutionTest {
  Solution sol = new Solution();

  @Test
  void example1() {
    assertEquals(321, sol.reverse(123));
  }

  @Test
  void example2() {
    assertEquals(-321, sol.reverse(-123));
  }

  @Test
  void example3() {
    assertEquals(21, sol.reverse(120));
  }

  @Test
  void example4() {
    assertEquals(0, sol.reverse(0));
  }

  @Test
  void example5() {
    assertEquals(0, sol.reverse(2111111119));
  }
}
