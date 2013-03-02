package main

import "fmt"

func fib(n int) (ret int) {
	if n < 2 {
		return n
	} else {
		return fib(n-1) + fib(n-2)
	}
	return
}

func main() {
	var result int
	result = fib(40)
	if result > 0 {
		fmt.Println("fib(40)= ", result)
	}
}
