#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub fn vec_to_nodes(v: Vec<i32>) -> Option<Box<ListNode>> {
    let mut head = None;

    for value in v.iter().rev() {
        head = Some(Box::new(ListNode {
            val: *value,
            next: head,
        }));
    }

    head
}

pub fn nodes_to_vec(node: Option<Box<ListNode>>) -> Vec<i32> {
    let mut ans = vec![];
    let mut ptr = node;

    while let Some(l) = ptr.clone() {
        ans.push(l.val);
        ptr = l.next;
    }

    ans
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn nodes_to_vec_should_work() {
        assert_eq!(nodes_to_vec(None), vec![]);
        assert_eq!(nodes_to_vec(Some(Box::new(ListNode::new(3)))), vec![3]);
    }

    #[test]
    fn example1() {
        let v = vec![1, 2, 3];
        assert_eq!(nodes_to_vec(vec_to_nodes(v.clone())), v);
    }

    #[test]
    fn example2() {
        let v = vec![];
        assert_eq!(nodes_to_vec(vec_to_nodes(v.clone())), v);
    }

    #[test]
    fn example3() {
        let v = vec![1];
        assert_eq!(nodes_to_vec(vec_to_nodes(v.clone())), v);
    }
}
