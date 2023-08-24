# Lecture 2 Processes

process (libc) 
--------
kernel
--------
H/W

syscall communicates between process and kernel

Process: abstraction of a running program
> logical flow of control through instructions "thread" ("thread of execution")
    - processes have at least one thread
> address space
    - stack
    - heap
    - program code
> abstract view of resources
    > write(1, "hello world", 12);
        - 0 stdin
        - 1 stdout
        - 2 stderr (these are all file descriptors)

Why do we need it (process abstraction)?
    - originally : no OS
    - mainframes : batch jobs, library I/O device code seems special, hlt (stop instruction)
    - minicomputers : digital PDP 
        - multiprogramming : switch programs if I/O (I/O is really slow)
        - time-sharing : switch programs so all make progress
        - two ideas found in UNIX
    - OS dark ages PC-era 
        - DOS - no memory protection 
        - MACOS - only cooperative scheduling
    - Now:
        - UNIX ideas are in all OS's
            - Windows NT
            - OSX
            - Linux  

protection:
    - privilegded instructions
        - hlt
        - I/O instruction
        - (change security policy, arbitrary access)

Dual Mode Operation
    - CPU has a bit {user, supervisor} (1 for user, 0 for supervisor)
        - user space (ring 3) / kernel space (ring 0)

When does the user go to kernel?
    - system call
    - async/external interrupt
        - device interrupt
        - timer interrupt
    - sync/internal intterupts 
        - divide by 0 (trap or exception)
        - system call
Kernel has {trap handler, interrupt handler} code that runs when an interrupt is raised

When does the kernel -> user
    - kernel issues iret (special instruction) that returns to user space
        - privileged instruction
    - where do you return to?
        - retry (e.g. page fault)
        - just after (e.g. syscall)

These are the mode switch (user mode <-> kernel mode)

Things about kernel safety / modules
Containing the omnipotent Root
eBPF
CAP_NET_ADMIN, Linux capabilities
Attestation

Context switch
- save state of P1
- restore state of P2

State of process
    - address space
    - registers
    - metadata in kernel ( but this is stored in the kernel for all processes)

Limited Direct Execution
    - direct execution : instructions are run directly on 
    - limited : can't run priv insns and can't take ontrol forever
