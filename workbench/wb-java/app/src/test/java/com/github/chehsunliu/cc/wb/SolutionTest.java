package com.github.chehsunliu.cc.wb;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SolutionTest {

  @Test
  void appHasAGreeting() {
    Solution classUnderTest = new Solution();
    assertNotNull(classUnderTest.getGreeting(), "app should have a greeting");
  }
}
