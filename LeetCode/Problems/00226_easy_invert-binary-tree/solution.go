package workbench

import "github.com/chehsunliu/cc/workbench/wb-go/pkg/leetcode"

type TreeNode = leetcode.TreeNode

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	var tmp *TreeNode = root.Left
	root.Left = invertTree(root.Right)
	root.Right = invertTree(tmp)
	return root
}

func Hello() string {
	return "Hello, world."
}
