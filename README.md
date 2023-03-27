# push_swap
Sorting a set of integers with 2 stacks and operations.

## Introduction
The Push swap project is a very simple and a highly straightforward algorithm project: data must be sorted.
A set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.

## Operations
>#### *Swap*
**sa (swap a)** : Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.\
**sb (swap b)** : Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.\
**ss** : sa and sb at the same time.
>#### *Push*
**pa (push a)** : Take the first element at the top of b and put it at the top of a.\
Do nothing if b is empty.\
**pb (push b)** : Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.\
>#### *Rotate*
**ra (rotate a)** : Shift up all elements of stack a by 1. The first element becomes the last one.\
**rb (rotate b)** : Shift up all elements of stack b by 1. The first element becomes the last one.\
**rr** : ra and rb at the same time.
>#### *Reverse rotate*
**rra** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.\
**rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.\
**rrr** : rra and rrb at the same time.

  command out
## Examples
>Init a and b:
```
2
1
3
6
5
8 
__ __
a  b
```

>Exec sa:
```
1
2
3
6
5
8
__ __
a  b 
```
>Exec pb pb pb:
```
6  3
5  2
8  1
__ __
a  b
```
>Exec ra rb (equiv. to rr):
```
5  2
8  1
6  3
__ __
a  b 
```

>Exec rra rrb (equiv. to rrr):
```
6  3
5  2
8  1
__ __
a  b
```
>Exec sa:
```
5  3 
6  2
8  1 
__ __
a  b 
```
>Exec pa pa pa:
```
1
2  
3
5  
6
8
__ __
a  b 
```
