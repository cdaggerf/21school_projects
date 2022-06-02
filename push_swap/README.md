42Project-PushSwap

This project's goal is to make the student get in contact with the idea of sorting algorithms and complexity. In possession of a list of numbers, the program must be able to use only two stacks and a restricted number of movements in order to sort the list out.

Mandatory
For the mandatory part, we should:

Be able to sort the given list of numbers correctly;
Do it so with the least possible number of movements.
Bonus
For the bonus part we should:

Do a checker program in order to access if the movements done can correctly sort the list given.
The project
Rules
You have 2 stacks named A and B.

The stack A contains a random amount of negative and/or positive numbers which cannot be duplicated.
The stack B is empty.
The goal is to sort in ascending order numbers into stack A. To do so you have the following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
pb (push b): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
ra (rotate a): Shift up all elements of stack A by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack B by 1. The first element becomes the last one.
rr: ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack A by 1. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack B by 1. The last element becomes the first one.
rrr: rra and rrb at the same time.
You can launch the program by doing

> $ ./push_swap <list_of_integers> 
The list can be passed as a single array of multiple numbers, indiferently.

> $ ./push_swap 1 3 5 4 2 0 -4
The expected output should be the instructions applied in order to sort the stack:

> $ ./push_swap 0 4 2
> pb
> ra
> pa
Or an Error message in case of errors of any kind:

> $ ./push_swap 0 4 two
> Error
If no parameters are passed, the command prompted will be returned with no error message: Or an Error message in case of errors of any kind:

> $ ./push_swap
> $
