package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func check(e error) {
	if e != nil {
		fmt.Println(e)
		panic(e)
	}
}
func getInput(fileName string) string {
	input, err := os.ReadFile(fileName)
	check(err)
	return string(input)
}

func convertStringToint(string []string) []int {

	numbers := []int{}

	for _, str := range string {
		str = strings.TrimSpace(str)
		if str == "" {
			continue
		}

		num, err := strconv.Atoi(str)
		check(err)

		numbers = append(numbers, num)
	}
	return numbers
}
func main() {

	data := getInput("input.txt")
	count := 0
	inputs := strings.Split(data, "\n")
	numbers := convertStringToint(inputs)
	//var prev int

	for i := 0; i < len(numbers)-4; i++ {

		// if i != 0 && prev < numbers[i] {
		// 	count += 1
		// }
		// prev = numbers[i]

		//PART2

		curr := numbers[i] + numbers[i+1] + numbers[i+2]
		next := numbers[i+1] + numbers[i+2] + numbers[i+3]

		if curr < next {
			count++
		}

		//PART1
		// if numbers[i] < numbers[i+1] {
		// 	count++
		// }
	}

	fmt.Println(count)
}
