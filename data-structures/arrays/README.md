# Arrays

## What is an Array?

An array is a data structure that stores elements in contiguous
memory locations and allows direct access using an index.

## Types

- Static Array
- Dynamic Array

## Comparison

| Feature       | Static Array               | Dynamic Array   |
| ------------- | -------------------------- | --------------- |
| Size          | Fixed                      | Dynamic         |
| Random Access | O(1)                       | O(1)            |
| Insert at End | O(1) if space is available | O(1) amortized  |
| Delete at End | O(1)                       | O(1)            |
| Resize        | Not possible               | O(n)            |
| Memory        | Fixed                      | Can grow/shrink |

## When to use?

Use an array when fast indexed access is important.

## Advantages

- O(1) random access
- Simple structure
- Cache-friendly due to contiguous memory

## Disadvantages

- Inserting/removing from the middle is O(n)
- Static arrays have fixed size
- Dynamic arrays may require resizing
