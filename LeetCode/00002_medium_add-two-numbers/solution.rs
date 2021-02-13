impl Solution {
    pub fn add_two_numbers(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut l1 = &l1;
        let mut l2 = &l2;
        let mut root = Some(Box::new(ListNode::new(0)));

        let mut p = &mut root;

        loop {
            let mut current_value: i32 = p.as_ref().unwrap().val;

            l1 = match l1 {
                None => &None,
                Some(x) => {
                    current_value += x.val;
                    &x.next
                }
            };

            l2 = match l2 {
                None => &None,
                Some(x) => {
                    current_value += x.val;
                    &x.next
                }
            };

            p.as_mut().unwrap().val = current_value % 10;

            if l1.is_none() && l2.is_none() {
                if current_value / 10 > 0 {
                    p.as_mut().unwrap().next = Some(Box::new(ListNode::new(current_value / 10)));
                }
                break;
            } else {
                p.as_mut().unwrap().next = Some(Box::new(ListNode::new(current_value / 10)));
                p = &mut p.as_mut().unwrap().next;
            }
        }

        root
    }
}

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

struct Solution {}

#[cfg(test)]
mod tests {
    use super::*;

    fn to_list(v: &Vec<i32>) -> Option<Box<ListNode>> {
        let mut n0: Option<Box<ListNode>> = None;

        for val in v.iter().rev() {
            n0 = Some(Box::new(ListNode {
                val: *val,
                next: n0,
            }));
        }

        n0
    }

    fn to_vec(mut l: &Option<Box<ListNode>>) -> Vec<i32> {
        let mut v: Vec<i32> = vec![];

        loop {
            match *l {
                Some(ref current_node) => {
                    v.push(current_node.val);
                    l = &current_node.next;
                }
                None => break,
            }
        }

        v
    }

    #[test]
    fn conversion_works() {
        let v1 = vec![2, 4, 3];
        let v2 = to_vec(&to_list(&v1));
        assert_eq!(v1, v2);
    }

    #[test]
    fn example1() {
        let l1 = to_list(&vec![2, 4, 3]);
        let l2 = to_list(&vec![5, 6, 4]);
        let ans = to_vec(&Solution::add_two_numbers(l1, l2));
        assert_eq!(vec![7, 0, 8], ans);
    }

    #[test]
    fn example2() {
        let l1 = to_list(&vec![0]);
        let l2 = to_list(&vec![0]);
        let ans = to_vec(&Solution::add_two_numbers(l1, l2));
        assert_eq!(vec![0], ans);
    }

    #[test]
    fn example3() {
        let l1 = to_list(&vec![9, 9, 9, 9, 9, 9, 9]);
        let l2 = to_list(&vec![9, 9, 9, 9]);
        let ans = to_vec(&Solution::add_two_numbers(l1, l2));
        assert_eq!(vec![8, 9, 9, 9, 0, 0, 0, 1], ans);
    }
}
