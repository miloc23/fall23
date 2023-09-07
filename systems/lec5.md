# Lecture 5 Processes

fork()
    - makes a new process, but not necesarily a new program
    - UNIX: decopule new process from new program

pattern:
    checking if fork() returns -1, 0, or other is a common pattern
    - -1 means error
    - 0 means in child
    - anything else means in parent

parent can issue the wait() system call
wait()
    - blocking system call
    - waits for a child to die

fork-join programming paradigm

Can do this to ignore child
    signal(SIGCHLD, SIG_IGN);

WNOHANG
    - don't block

signals
    - use macros to decode status

exec()
   
fork()
    - new process, old program
    - clone of parent (stack, heap, fds)
    - called once, returns twice
exec()
    - new program, old process
    - reinitializes heap, stack
    - keep fds
    - called once, never returns

