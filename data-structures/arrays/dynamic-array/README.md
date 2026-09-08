# Dynamic Array

## What is a Dynamic Array?

A dynamic array is an array-like data structure whose capacity
can grow or shrink during runtime.

## Structure

The DynamicArray contains:

- `m_data` - pointer to the dynamically allocated array
- `m_size` - number of elements currently stored
- `m_capacity` - number of elements that can currently be stored

## Operations

- `push()`
- `pop()`
- `get()`
- `set()`
- `operator[]`
- `size()`
- `capacity()`
- `is_empty()`

## Resizing

When the array becomes full:

1. Allocate a new array with larger capacity
2. Copy the existing elements
3. Delete the old array
4. Update `m_data`

The capacity is doubled when growing.

## Shrinking

When the array becomes sufficiently empty:

1. Allocate a smaller array
2. Copy the existing elements
3. Delete the old array
4. Update `m_data`

The capacity is halved when usage falls below the threshold.

## Time Complexity

| Operation | Complexity     |
| --------- | -------------- |
| Access    | O(1)           |
| Search    | O(n)           |
| Set       | O(1)           |
| Push      | O(1) amortized |
| Pop       | O(1)           |
| Resize    | O(n)           |
| Shrink    | O(n)           |

## Space Complexity

O(n)

## When to use?

Use a dynamic array when:

- You need fast random access
- The number of elements is not known beforehand
- Elements are mostly added/removed from the end

## Advantages

- O(1) random access
- Automatically grows when necessary
- Good cache locality
- Simple to use

## Disadvantages

- Resizing requires copying elements
- Inserting/removing from the middle is O(n)
- May temporarily allocate additional memory during resizing

## Implementation Checklist

- [x] Constructor
- [x] Destructor
- [x] push()
- [x] pop()
- [x] get()
- [x] set()
- [x] operator[]()
- [x] size()
- [x] capacity()
- [x] is_empty()
- [x] resize()
- [x] shrink()
