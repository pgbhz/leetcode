/*
I'm getting lazy. Read the problem!
We can just start from a baseline number and iterate.
Hardest thing here is checking whether there's a zero inside the string representation of n.
*/

func getNoZeroIntegers(n int) []int {
	for a := 1; a < n; a++ {
		b := n - a
		if !containsZero(a) && !containsZero(b) {
			return []int{a, b}
		}
	}
	return nil
}

func containsZero(num int) bool {
	strNum := strconv.Itoa(num)
	for _, char := range strNum {
		if char == '0' {
			return true
		}
	}
	return false
}