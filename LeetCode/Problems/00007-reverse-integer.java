package com.github.chehsunliu.cc.wb;

public class Solution {

  public int reverse(int x) {
    try {
      int ans = 0;

      while (x != 0) {
        ans = Math.addExact(Math.multiplyExact(ans, 10), x % 10);
        x /= 10;
      }

      return ans;
    } catch (ArithmeticException e) {
      return 0;
    }
  }

  public static void main(String[] args) {
    System.out.println("Hello!");
  }
}
