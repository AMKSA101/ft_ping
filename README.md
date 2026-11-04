# ft_ping

`ft_ping` is an educational IPv4 ping implementation written in C. The project recreates the basic behavior of the GNU inetutils 2.0 `ping` command: send ICMP Echo Requests, receive responses, and report round-trip time (RTT).

## Requirements

- C and a Makefile are required. The project may use libc functions.
- The subject targets a Debian virtual machine (Debian 7.0 or newer) with a Linux kernel newer than 3.14.
- The Makefile must provide the usual targets and rebuild or relink only when needed.
- Linux raw ICMP sockets require root privileges or the `CAP_NET_RAW` capability; see [`raw(7)`](https://man7.org/linux/man-pages/man7/raw.7.html).
- Do not invoke the system `ping` command or copy source code from a standard ping implementation.

## Build

Run `make` in the project directory. The executable is named `ft_ping`.

The Makefile provides `all`, `clean`, `fclean`, and `re` targets.

## Planned usage

```text
./ft_ping [-v] <IPv4-address-or-hostname>
./ft_ping -?
```

The destination may be an IPv4 address or a hostname, including an FQDN. Resolve the destination before sending probes. Keep the entered name for display and use the packet's numeric source address for replies; do not perform reverse DNS resolution while processing each returned packet.

## Mandatory behavior

- `-?` displays usage information and exits successfully.
- `-v` displays packet-related errors, such as ICMP errors, without terminating the program unexpectedly.
- Send IPv4 ICMP Echo Requests and recognize matching Echo Replies.
- Measure and report RTT and packet statistics.
- Handle malformed or unrelated packets and system errors safely; avoid crashes, invalid memory access, and double frees.
- Match the inetutils 2.0 output indentation, except for the RTT line and reverse-DNS resolution behavior. The subject allows a ±30 ms RTT difference.

## Optional bonuses

The subject suggests `-f`, `-l`, `-n`, `-w`, `-W`, `-p`, `-r`, `-s`, `-T`, `--ttl`, and `--ip-timestamp` as possible bonuses.

Bonus work is evaluated only after every mandatory requirement works correctly. `-V`, `--usage`, and `--echo` do not count as bonuses; aliases for the same feature count as one bonus.

## Reference and evaluation

Use GNU inetutils 2.0 `ping` as the behavioral and output reference. The project is evaluated from the contents of the Git repository, on a Linux VM accessible from the evaluation cluster.
