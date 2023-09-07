# process states and control

privelge: dual mode
multiple processes running at the same time
    - context switch (switch between two processes)

Next:
    - process states
    - creating new processes (fork())
    - fd's pipes etc

Are all processes ready to run?
    No: waiting on I/O

Blocked state - waiting on something

Running state

blocked <-- running <
  |                 |
  -----> ready < ---- 

OS scheduler moves from running <-> ready
Waiting for an event moves from running -> blocked
An async event has happened blocked -> ready

"ready queue" or "run queue"
    - all the processes that could run at this time

n CPUs n ready processes -> all ready processes can be moved to running

n CPUs 0 ready -> CPUs will all go into idle loop

n CPUs 2n ready processes -> sched picks n to run, n stay in ready

n CPUs m >> n ready -> n gets to run, but they only make n/m times as much progress?


blocked <-- running <
  |                 |
  -----> ready < ----

This is the job control layer (in Linux)
running and ready can go ready stopped by ^Z on shell
blocked can go to blocked stopped by ^Z on shell
can go from blocked stopped to ready stopped

Final thoughts on process states
transitions are out of the programmer's control
- user actions, I/O, IPC (interprocess communication), synchronization primitive
- OS scheduler 
- block/unblock happen a lot
- Don't assume anything about order

Creating new program
- binary to run
- commandline args
- enviornment to run in

Enough to "spawn" a new program

windows createProcessA
posix systems posix_spawn

UNIX: idea : seperate process creation from new "program"
fork() new processm not a new program
    - call once, return twice

This leads to the process tree
- root process called init
