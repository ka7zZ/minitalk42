# MINITALK
## Inter-process communication using UNIX signals

================================================================================

## PROJECT STRUCTURE

```
.
├── Makefile
├── include/
│   └── minitalk.h
├── libft/
│   ├── libft.h
│   ├── ft_printf/
│   ├── strings/
│   ├── memory/
│   └── ...
└── srcs/
    ├── mandatory/
    │   ├── client.c
    │   └── server.c
    └── bonus/
        ├── client_bonus.c
        └── server_bonus.c
```

================================================================================

## MANDATORY PART

### Overview

Create a client-server communication program using UNIX signals. The server must be started first and display its PID. The client will take the server PID and a string as parameters, then send the string to the server character by character using only `SIGUSR1` and `SIGUSR2` signals.

### Key Requirements

- Server prints its PID on startup
- Client sends string to server via signals
- Communication uses only `SIGUSR1` and `SIGUSR2`
- Server displays received strings quickly (no delays > 1 second)
- Server must be able to receive strings from several clients in succession
- Communication protocol must include acknowledgment system

### Signal Encoding

Each character is transmitted bit-by-bit:
- `SIGUSR1` represents bit value 0
- `SIGUSR2` represents bit value 1

**Example: Letter 'A' (ASCII 65 = 0b01000001)**

```
Bit 7 (MSB) → SIGUSR1 (0)
Bit 6       → SIGUSR2 (1)
Bit 5       → SIGUSR1 (0)
Bit 4       → SIGUSR1 (0)
Bit 3       → SIGUSR1 (0)
Bit 2       → SIGUSR1 (0)
Bit 1       → SIGUSR1 (0)
Bit 0 (LSB) → SIGUSR2 (1)
```

### Compilation

```bash
make
```

This creates two executables: `server` and `client`

### Usage

**Terminal 1 - Start the server:**

```bash
./server
```

Output:
```
Server PID: 12345
```

**Terminal 2 - Send messages:**

```bash
./client [SERVER_PID] "Your message here"
```

**Example:**

```bash
./client 12345 "Hello, World!"
```

**Server displays:**

```
Server PID: 12345
Hello, World!
```

### Multiple Messages

Send multiple strings by passing additional arguments:

```bash
./client 12345 "First message" "Second message" "Third message"
```

**Server output:**

```
First message
Second message
Third message
```

================================================================================

## TECHNICAL IMPLEMENTATION

### Signal Handling

The project uses `sigaction()` for robust signal handling with the following flags:

**SA_SIGINFO:**
- Provides additional information about the signal
- Allows access to sender's PID via `siginfo_t` structure

**SA_RESTART:**
- Automatically restarts system calls interrupted by signals
- Prevents `pause()` from returning unexpectedly

**SA_NODEFER:**
- Allows signal handler to receive the same signal while executing
- Necessary for continuous bit reception

### Server Implementation

**Key Functions:**

```c
void ft_handle(int signo, siginfo_t *info, void *context);
void ft_handle_char(char **str, char ch);
void ft_setup(void);
```

**Process:**

1. Initialize signal handlers with `sigaction()`
2. Display server PID
3. Enter infinite loop with `pause()`
4. Receive signals bit by bit
5. Reconstruct characters from 8 bits
6. Build string dynamically using `ft_expandstr()`
7. Display message when null terminator received
8. Send acknowledgment signal back to client

### Client Implementation

**Key Functions:**

```c
void send_char(pid_t pid, char c);
void confirm(int signo);
void handle_output(char **input, pid_t pid);
```

**Process:**

1. Validate PID format (numeric only)
2. Setup signal handler for acknowledgment
3. For each character in string:
   - Extract each bit from MSB to LSB
   - Send `SIGUSR1` (0) or `SIGUSR2` (1)
   - Wait for server acknowledgment
   - Add timing delay to prevent signal overflow
4. Send null terminator to mark end of message

### Synchronization

**Bit-Level Acknowledgment:**
- Server sends `SIGUSR2` after receiving each bit
- Client waits for acknowledgment before sending next bit
- Global flag `g_check` controls synchronization

**Timing:**
- `usleep(100)` after sending signal
- `usleep(10)` while waiting for acknowledgment
- Prevents signals from arriving faster than server can process

### Memory Management

- String built dynamically with `ft_expandstr(char *str, char c)`
- Memory freed when null terminator received
- Static variables maintain state between signal handler calls

### Error Handling

**Client-side:**
- Parameter count validation (`argc != 3`)
- Empty string check
- PID format validation (must be all digits)
- Signal sending error detection

**Server-side:**
- Signal handler registration error checks
- Memory allocation failure handling

================================================================================

## BONUS PART

### Additional Features

The bonus version adds bi-directional communication:

1. **Server-to-Client Acknowledgment:**
   - Server sends `SIGUSR1` when complete message received
   - Client displays confirmation with message count

2. **Unicode Support:**
   - Handles UTF-8 encoded characters
   - Works with extended character sets

### Implementation Differences

**server_bonus.c:**
- Sends `SIGUSR1` to client PID when null terminator processed
- Extracts client PID from `siginfo_t->si_pid`

**client_bonus.c:**
- Handles both `SIGUSR1` and `SIGUSR2`
- Maintains static counter for received messages
- Displays "Received N string(s)!" with proper pluralization

### Compilation

```bash
make bonus
```

This creates: `server` and `client` (bonus versions)

### Usage

Same as mandatory, with additional client output:

```bash
./client 12345 "Hello" "World"
```

**Client output:**

```
Received 1 string!

Received 2 strings!
```

================================================================================

## BUILD SYSTEM

### Makefile Targets

```bash
make        # Compile mandatory version
make bonus  # Compile bonus version
make clean  # Remove object files
make fclean # Remove object files and executables
make re     # Recompile everything
```

### Compilation Flags

The project is compiled with strict flags:
- `-Wall` - Enable all warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors

### Dependencies

- Custom `libft` library (included)
- External functions allowed:
  - `write`, `ft_printf`, `signal`, `sigemptyset`, `sigaddset`, `sigaction`
  - `kill`, `getpid`, `malloc`, `free`, `pause`, `sleep`, `usleep`, `exit`

================================================================================
