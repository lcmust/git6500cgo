package main

import "fmt"

func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}

func main() {
	fmt.Println(split(17))
	fmt.Println(split(17))
	fmt.Println(split(17))
	fmt.Println(split(17))
	fmt.Println(split(17))
	fmt.Println(split(1792382924))
	fmt.Println(split(17))
}

/*
func example(name1 string) (name string) {
	name = name1
	return name
}
*/
