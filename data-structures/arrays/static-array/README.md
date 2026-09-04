# Static Array

## What is a Static Array?

A static array is an array whose size is fixed at compile time.

## Structure

The StaticArray contains:

`m_data` — fixed-size array that stores the elements

The array size is defined by the `N` template parameter and cannot be changed at runtime.

## Operations

- `operator[]`
- `size()`
- `initializer_list` initialization

## Time Complexity

| Operation | Complexity |
| --------- | ---------- |
| Access    | O(1)       |
| Set       | O(1)       |
| Search    | O(n)       |

## Space Complexity

O(n)

## When to use?

Use a static array when:

- You need fast indexed access
- The size is known at compile time

## Advantages

- O(1) indexed access
- Simple to use
- Cache-friendly due to contiguous memory
- No dynamic memory allocation

## Disadvantages

- Fixed size
- Cannot grow or shrink

## Implementation Checklist

- [x] Constructor
- [x] Initializer list constructor
- [x] operator[]()
- [x] size()
