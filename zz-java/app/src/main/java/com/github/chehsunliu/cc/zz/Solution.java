package com.github.chehsunliu.cc.zz;

public class Solution {

  public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    if (l1 == null && l2 == null) {
      return null;
    }

    ListNode ans = new ListNode();
    ListNode pointer = ans;

    while (true) {
      if (l1 != null && l2 != null) {
        if (l1.val > l2.val) {
          pointer.val = l2.val;
          l2 = l2.next;
        } else {
          pointer.val = l1.val;
          l1 = l1.next;
        }
      } else if (l1 != null) {
        pointer.val = l1.val;
        l1 = l1.next;
      } else if (l2 != null) {
        pointer.val = l2.val;
        l2 = l2.next;
      }

      if (l1 != null || l2 != null) {
        pointer.next = new ListNode();
        pointer = pointer.next;
      } else {
        break;
      }
    }

    return ans;
  }

  static class ListNode {

    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
      this.val = val;
    }

    ListNode(int val, ListNode next) {
      this.val = val;
      this.next = next;
    }
  }
}
