// BitWise operators

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <errno.h>

void control(int num)
{
	printf("can't kill me\nnum --->> %d\n", num);
}

// void print_bits(unsigned char octet)
// {
// 	int i = 8;
// 	unsigned char 	bit;

// 	while (i--)
// 	{
// 		bit = (octet >> i & 1) + '0';
// 		write(1, &bit, 1);
// 	}
// 	write(1, "\n", 1);
// }

int main(void)
{
	// int	n = 2;
	// int bit = n >> 1 & ;

	// print_bits(bit);
	struct sigaction action;
	int n, p[0];
	char buf[1000];

	pipe(p);

	action.sa_handler = control;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART; // restart automatically if the SIGINT is passed
	//action.sa_flags = 0; continues the while loop;

	sigaction(SIGINT, &action, NULL);

	while (1)
	{
		n = read(p[0], buf, 1000);
		printf("read returned: %d, errno = %d\n", n, errno);
		sleep(5);
		printf("i'm done sleeping but still...\n");
	}
	return (1);
}

// SIGINT = CTROL + C 
// KILL = STOPING A FUNCTION - CAN'T BE HANDLED, IS AN ORDER NOT A PROCESS
// sigaction (1st arg - signal type, 2nd sa_struct[handler, set of signals to be blocked, sa_flags], 3rd arg - where to return info)
//          example:
	                // main() {
					// 	struct sigaction action; 
					// 	action.sa_handler = (function to be executed);
					// 	sigemptyset(&action.sa_mask);
					// 	sigaction(SIGINT/SIGUSR1/SIGUSR2/ETC..., &action, NULL) 
					// }
// sigset_t = array of booleans (bits) representing a set of signals (hiding behind a set of macros) each bit representing a one signal type
// sigemptyset(&sigset_t) - clears all the bits  (initialise)
// sigaddset(&sigset_t, SIGTERM/SIGQUIT/SIGUSR1/etc..) - setting signals to the sigset
// sigdelset(&sigset_t, SIGTERM/etc...) - remove a signal to the set
// sigfillset(&sigset_t) - set them all
// sigismember(&sigset_t, SIGTERM/etc...) - returns true (1) if is member or false (0) if it's not
// 
// BLOCKING SIGNALS -> sigprocmask(how, set, oldset);	
//							-> how:	-> SIG_BLOCK: add these signals to the mask
//									-> SIG_UNBLOCK: remove these signals from the mask
//									-> SIG_SETMASK: assign this signal set to the mask
// 							-> set: -> set of signals to add /subtract;
//							-> oldset: return the old mask if we want
//			example:
					// main() {
					// 	sigset_t set;
					// 	 
					// 	sigemptyset(&set);
					// 	sigaddset(&set, SIGUSR1);
					// 	sigprocmask(SIG_BLOCK, &set, NULL); 
					// /* The code here will not be interrupted by SIGUSR1 */
					//  sigprocmask(SIG_UNBLOCK, &set, NULL);
					// }	
//
//
// void print_bits(unsigned char octet)
// {
// 	int i = 8;
// 	unsigned char 	bit;

// 	while (i--)
// 	{
// 		bit = (octet >> i & 1) + '0';
// 		write(1, &bit, 1);
// 	}
// 	write(1, "\n", 1);
// }

// int main(int ac, char **av)
// {
//     int i;
//     int count;

//     if (ac == 2)
//     {
//         i = 0;
//         while (av[1][i])
//         {
//             if (av[1][i] >= 'a' && av[1][i] <= 'z')
//                 count = av[1][i] - 'a' + 1;
//             else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
//                 count = av[1][i] - 'A' + 1;
//             else
//                 count = 1;
//             printf("\npointer arithmetics --->> %d\n", av[1][i] - 'a' + 1);
//             while (count--)
//                 write(1, &av[1][i], 1);
//             i++;
//         }
//     }
//     write(1, "\n", 1);
//     return 0;
// }

/*
		INTER-PROCESS COMMUNICATION
	  								--Catchable--		-- Meaning of signal sent to process --									-- Action --	-- Core dump? --
	  ***Wrongdoing Notification***	
	SIGSEGV						|	Yes		|	Invalid memory reference, termninate, no clean up					 	|	 Terminate	  |		Yes
	SIGBUS						|	Yes		|	Non-existent physiscal address										  	|	 Terminate	  |		Yes
	SIGFPE						|	Yes		|	A process executes an errnoeous float/int operation (ex: n / 0)		  	|	 Terminate	  |		Yes
	SIGILL						|	Yes		|	A process attempts a malformed/unknwon/wrong permissions CPU		   	|	 Terminate	  |	 	Yes
	SIGSYS						|	Yes		|	A process passes incompatible arg to a system call					  	|	 Terminate	  |		Yes
	SIGPIPE						|	Yes		|	A process tries to write to a pipe without another process at the end	| 	 Terminate	  |		Yes
	  ***Termination Signals***	
	SIGABRT						|	yes		|	Terminate process sent by the process itself, with no cleanup		  	|	 Terminate	  |		Yes
	SIGQUIT						|	yes		|	Terminate process sent by user										  	|	 Terminate	  |		Yes
	SIGINT						|	yes		|	The process is requested to terminate, performs cleanup				  	|	 Terminate	  |		No
	SIGTERM						|	yes		|	idem SIGINT															  	|	 Termiante	  | 	No	
	SIGKILL						|	 NO		|	Terminate instantly, no cleanup, handled by kernel					  	|	 Terminate	  |		No
	  ***CONTROL*** 
	SIGALRM		 				|   yes		|	Sent by alarm(), execute actions at a specific time						|	 Terminate	  |		No
	SIGSTOP						|    NO		|	Stop execution but stay alive											|	 Stop		  |		-		
	SIGTSTP						|   yes		|	Terminal stop execution but stay alive									|	 Stop		  |     -
	SIGCONT						|   yes		|	Continue/resume execution if stopped									|    Continue	  | 	-
	SIGHUP						|   yes		|	Sent to a process when its terminal terminates							|    Terminate	  |		No
	SIGTRAP						|   yes		|	Sent when a trap occurs for debugging (ex .var value change, func start)|    Terminate	  |		Yes
	-> wait a specified period of time with alarm() and ualarm()
	-> pause() still receives signals while sleep() function.
	  ***CHILD PROCESS***
	SIGCHLD						|	yes		|	A fore/background child process of this process has terminated/stoped/continued	| None	  | 	-
	-> wait() and waitpid() suspend the process until one of its child processes has terminated
	-> using the SIGCHLD signal, allows a parent process to do other work instead of going to sleep and be notified via signal when a child terminates
	-> then, when SIGCHLD is received, the process can immediattely or later call wait() or waitpid().
	  ***User-definned Signals***
	SIGUSR1						|	yes		|	No meanig to the kernel													|	  Terminate	  |		No
	SIGUSR2						|	yes		|	No meanig to the kernel													|	  Terminate   |		No

	pause()
	-> if a signal is set to be ignored, pause() continues to be in effect
	-> if a signal cause termination, pause() doesn't do anythin
	-> if a signal is caught, the appropiate signal handler function will be called
	-> after the signal handler function is done, paus() returns -1 and sets errno to EINTR, and then the process resumes execution 
	
	Signal Sets
	
	Declaring a signal set: 											sigset_t my_set;
	Initializing or reset the original set to have no signal types: 	sigemptyset(&my_set);
	Initializing or reset the original set to have all signal types: 	sigfillset(&my_set)
	Adding a specific signal type to the set: 							sigaddset(&my_set, signal);
	Removing a single signal type from the set:							sigdelset(&my_set, signal);

	Signal Action:

	sigaction() registers a signal handling function that you've created for a specified set of signals
	Prototype:		int sigaction(int signo, struct sigaction *new_act, struct sigaction *original_act);
							-> 1st param: is the signal type SIG, register the signal to the handler
							-> 2nd param: pointer to a datafilled sigaction struct, action that we gonna take 
							-> 3rd param: pointer to another sigaction struct with wich sigaction() will use to write out what the handling settings for the 1st param were before this change
	Structure:		
	-> void (*sa_handler)(int);	***a pointer to the function handler***
	-> sigset_t sa_mask;		***indicates what signals should be blocked while the handler is executing, multiples signals of the same type will be combined***
	-> int sa_flags;			***provides additional instructions: 	SA_RESTHAND (resets the handler) to SIGDFL (default action)
																		SA_SIGINFO	(tells the kernel to call specified function in the fourth parameter instead of the first attribute (handler)
																		SA_RESTART	(restart the function)
																		set to 0/NULL tells that you aren't planning to set any flags
	-> void (*sa_sigaction)(int, siginfo_t*, void*);

	Catching & Ignoring signals

https://www.yendor.com/programming/unix/apue/ch10.html
https://users.soe.ucsc.edu/~sbrandt/105/Slides/Chapter10.pdf
https://thelinuxcode.com/c-sigaction-function-usage/


    .-------------------.
    | BITWISE OPERATORS |
    '-------------------'
    
    AND(&)                  -> checks if the both flags are 1 and return 1, else return 0
    OR (|)                  -> checks if one on the flags are 1 return 1, else return 0
    eXclusive OR (^)        -> checks if both are the same and returns 0, else return 1
    SHIFT RIGHT (>>)        -> shifts at the right, filling the left side with 0's
                            -> any int shifted right will result the half of it rounded back
                            -> ex:  variable >> 1; destroys the bit on the far right and fill the far left with 0
                                    variable >> 3; destroys 3 bits on the far right and fill the far left with 3 zero's
    SHIFT LEFT  (<<)        -> the same bit at reverse;
    any bitwise op and '='  -> the variable will receive the result;

    Bit Manipulation

    

*/