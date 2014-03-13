Classical Concurrency Problems
==============================

These collection of programs have been written to show how
concurrency is something that needs to be done properly.

Building the tests
------------------

To build the binaries run make. pthreads must be installed

> make

Broken Banks
------------

> ./test_broken_bank

This should normally return 1100 coins after all the processes.

However there are cases where it wont as it has interleaved the
processes oddly and caused issues. The brokenbank.cpp class
has been designed to increase the chance of this happening.
Sometimes the printf statements will come out in different orders,
very rarely seemingly random values will appear as the value.

Fixed Banks
-----------

> ./test_fixed_bank

Is the same program with a fixed bank, using mutexes around all
the methods. This actually makes the program singlethreaded but
fixes issues as the above program has. Further optimisations can
be made to reduce the critical region size, but for demonstration
this hasnt been performed.

Dining Philosophers
-------------------

> ./test_dining

This is used to run the dining philosphers problem. Currently there is an issue
where it will deadlock if they all pick up one fork at a time. This can be fixed
by making one person pick up the fork in a different order However this has
fairness issues. Currently left as an exercise to the reader.
