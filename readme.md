this repo is school related.
the goal of is to implement data structures and alogithms in C
and optimise them (hopefully well)

| data strutures        | status        | include           |
|:---------------------:|:-------------:|:-----------------:|
| Arrays                | native in C   |       /           |
| Single linked lists   | done          | include/lists.h   |
| Double linked lists   | done          | include/lists.h   |
| Circular linked lists | not done      | not implemented   |
| Stacks                | done          | include/stacks.h  |
| Simple Queue          | done          | include/queue.h   |
| Circular Queue        | not done      | not implemented   |
| Priority Queue        | not done      | not implemented   |
| Hash Tables           | not done      | not implemented   |

command to test if the libs are working as intended 
(from the root of the repo)

--to test the list library :
gcc ./tests_lib/test_lists.c ./libs/lists.c -o libs.a

--to test the stack library :
gcc ./tests_lib/test_stacks.c ./libs/stacks.c -o stacks.a

--to test the queue library :
gcc ./libs/queue.c ./tests_lib/test_queue.c -o queue.a