package workbench

func isHappy(n int) bool {
	ans1x := calculate1x(n)
	ans2x := calculate2x(n)

	for ans1x != ans2x {
		ans1x = calculate1x(ans1x)
		ans2x = calculate2x(ans2x)
	}

	return ans1x == 1
}

func calculate2x(n int) int {
	return calculate1x(calculate1x(n))
}

func calculate1x(n int) int {
	ans := 0

	for n > 0 {
		digit := n % 10
		n /= 10
		ans += digit * digit
	}

	return ans
}
