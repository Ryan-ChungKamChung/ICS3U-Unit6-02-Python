// Copyright (c) 2020 Ryan Chung Kam Chung All rights reserved
//
// Created by Ryan Chung Kam Chung
// Created in January 2021
// Program generates 10 random numbers and displays largest

#include <iostream>
#include <random>
#include <array>

template<size_t N>
int largest(std::array<int, N> random_numbers) {
    // Finds the largest number

    int loop_counter = 0;
    int largest_number = random_numbers[0];

    for (int loop_counter = 0; loop_counter < random_numbers.size();
         loop_counter++) {
        if (random_numbers[loop_counter] > largest_number) {
            largest_number = random_numbers[loop_counter];
        }
    }

    return largest_number;
}


int main() {
    // Generates 10 random numbers and displays largest

    int loop_counter = 0;
    int largest_number;
    std::array<int, 10> random_numbers;

    for (int loop_counter; loop_counter < 10; loop_counter++) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());  // mersenne_twister
        std::uniform_int_distribution<int> idist(1.0, 100.0);  // [0,100]
        random_numbers[loop_counter] = idist(rgen);

        if (loop_counter < 9) {
            std::cout << random_numbers[loop_counter] << ", ";
        } else {
            std::cout << random_numbers[loop_counter] << std::endl;
        }
    }

    largest_number = largest(random_numbers);

    std::cout << "The largest number is: " << largest_number << std::endl;
}
