# Pigeonhole Sort in C++ (Ascending Order)

## Author
**Name:** Hostine Olare  
**Registration Number:** EB3/68519/23  

## Description
This program implements the **Pigeonhole Sort algorithm** in C++ to sort a user-provided list of integers in ascending order. 

It also tracks and displays the algorithm's performance metrics:
- Number of **comparisons** made.
- Number of **swaps/operations** performed.

## Features
- Accepts user input for the number of elements and the elements themselves.
- Handles input validation to prevent errors.
- Displays the unsorted list, the sorted list, and the operation counts.

## How it Works
1. **Find the smallest and largest numbers:** The code first looks through your list to find the minimum and maximum values.
2. **Setup boxes (pigeonholes):** It figures out the spread of your numbers (range = maximum - minimum + 1) and creates that many empty "boxes" (array of pigeonholes).
3. **Drop numbers into boxes:** It goes through your list again. Each number is dropped into a specific box based on its value (box position = number - minimum).
4. **Collect the numbers:** Finally, it goes through the boxes in order from left to right, picking up the numbers and putting them back into your original list. Since the boxes are in order, the list is now perfectly sorted!

