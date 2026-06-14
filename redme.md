# SysInfo Project

## Intent

### Why am I Building This?

* Learn Linux internals through implementation rather than only reading theory.
* Build my own useful command-line utility.
* Gain hands-on experience with Linux filesystems such as `procfs` and `sysfs`.
* Improve C++ skills while working with real operating system concepts.
* Understand how common Linux utilities gather and display system information.
* Create a strong foundation for future projects such as a mini shell, process monitor, log collector, or Redis-like system.

### Project Goal

Create a command-line utility called `sysinfo` that provides quick access to commonly used system information.

Example Usage:

```bash
sysinfo cpu
sysinfo memory
sysinfo uptime
sysinfo devices
sysinfo ps
```

---

# Learning Goals

By the end of this project, I should understand:

* Command Line Interfaces (CLI)
* Linux process execution
* procfs (`/proc`)
* sysfs (`/sys`)
* Device representation in Linux
* Major and Minor device numbers
* Symlinks
* Filesystem traversal
* Process information
* Parsing Linux virtual files
* Basic C++ project organization
* Building Linux tools

---

# Version 1 Scope

The first version will contain only the following commands:

* cpu
* memory
* uptime
* devices
* ps

The goal of V1 is learning Linux concepts, not building a production-ready monitoring tool.

---

# Features

## 1. CPU Information

### Command

```bash
sysinfo cpu
```

### Example Output

```text
Model: AMD Ryzen 7 5800X
Cores: 8
Threads: 16
```

### Linux Concepts

* procfs
* CPU metadata
* Virtual files

### Learnings

* Reading files from `/proc`
* Parsing text files
* Extracting structured information

### Files Used

```text
/proc/cpuinfo
```

### Difficulty

⭐

---

## 2. Memory Information

### Command

```bash
sysinfo memory
```

### Example Output

```text
Total RAM: 32GB
Free RAM: 10GB
Available RAM: 15GB
```

### Linux Concepts

* procfs
* Memory information exposure

### Learnings

* Parsing Linux system information
* Extracting key-value pairs

### Files Used

```text
/proc/meminfo
```

### Difficulty

⭐

---

## 3. System Uptime

### Command

```bash
sysinfo uptime
```

### Example Output

```text
System Uptime: 12 days 3 hours
```

### Linux Concepts

* System boot information
* Virtual filesystems

### Learnings

* Converting raw uptime values into human-readable output

### Files Used

```text
/proc/uptime
```

### Difficulty

⭐

---

## 4. Device Explorer

### Command

```bash
sysinfo devices
```

### Example Output

```text
259:0 -> nvme0n1
259:1 -> nvme0n1p1
8:0   -> sda
```

### Linux Concepts

* sysfs
* Block devices
* Device hierarchy
* Symlinks
* Major and Minor numbers

### Learnings

* Filesystem traversal
* Symlink resolution
* Device representation inside Linux

### Files Used

```text
/sys/dev/block
```

### Difficulty

⭐⭐⭐

---

## 5. Process Explorer

### Command

```bash
sysinfo ps
```

### Example Output

```text
PID     NAME
1       systemd
132     sshd
2456    chrome
```

### Linux Concepts

* Linux processes
* Process metadata
* PID directories

### Learnings

* Directory traversal
* Process discovery
* Process information parsing

### Files Used

```text
/ proc/<pid>
```

### Difficulty

⭐⭐⭐

---

# Future Enhancements

The following features are intentionally excluded from Version 1.

They may be added later after the core commands are completed.

---

## Mounted Filesystems

### Command

```bash
sysinfo mounts
```

### Example Output

```text
/dev/sda1 -> /
tmpfs -> /tmp
```

### Learnings

* Mount points
* Filesystem hierarchy
* Storage devices

### Files Used

```text
/ proc/mounts
```

---

## Open Files for a Process

### Command

```bash
sysinfo files <pid>
```

### Example Output

```text
/tmp/log.txt
/dev/null
socket:[123]
```

### Learnings

* File descriptors
* Symlinks
* Process resources

### Files Used

```text
/ proc/<pid>/fd
```

---

## Network Statistics

### Command

```bash
sysinfo network
```

### Example Output

```text
Interface: eth0
RX: 120 MB
TX: 35 MB
```

### Learnings

* Network interfaces
* Linux networking statistics

### Files Used

```text
/ proc/net
```

---

# Technical Roadmap

## Phase 1

Learn CLI basics.

Topics:

* argc
* argv
* command parsing
* executable generation

Deliverable:

```bash
sysinfo cpu
```

should successfully invoke the cpu command.

---

## Phase 2

Implement:

* cpu
* memory
* uptime

Focus:

* Reading files
* Parsing text
* Clean code organization

---

## Phase 3

Implement:

* devices

Focus:

* sysfs
* symlinks
* filesystem traversal

---

## Phase 4

Implement:

* ps

Focus:

* process discovery
* PID directories

---

## Phase 5

Refactoring

Potential structure:

```text
src/
├── main.cpp
├── commands/
│   ├── CpuCommand.cpp
│   ├── MemoryCommand.cpp
│   ├── UptimeCommand.cpp
│   ├── DeviceCommand.cpp
│   └── ProcessCommand.cpp
└── utils/
```

---

# Technology Stack

Language:

* C++17 or C++20

Platform:

* Linux

Compiler:

* g++

Editor:

* VS Code

Version Control:

* Git

Build Tool:

* Initially g++
* Later CMake

---

# Success Criteria

Version 1 is considered complete when:

* `sysinfo cpu` works.
* `sysinfo memory` works.
* `sysinfo uptime` works.
* `sysinfo devices` works.
* `sysinfo ps` works.
* Commands provide meaningful output.
* Code is organized and maintainable.
* I understand the Linux concepts behind each command.
# LXKit

A Linux exploration and tooling project built to learn Linux internals through implementation.

---

## Why am I building this?

I have been studying Linux concepts such as:

* procfs (`/proc`)
* sysfs (`/sys`)
* device files (`/dev`)
* major and minor device numbers
* symlinks
* processes
* filesystems

Reading theory is useful, but implementing tools that use these concepts helps build a much deeper understanding.

LXKit serves as a bridge between Linux theory and practical implementation.

---

## Project Goal

The goal is to build a collection of Linux utilities while learning how Linux works internally.

Rather than creating isolated demo programs, every Linux concept learned should eventually become a useful LXKit command.

---

## Current Focus

Initially, the project will focus on learning:

* CLI development
* `argc` and `argv`
* Command dispatching
* Multi-file C++ project structure
* Reading and parsing Linux virtual files

Example commands:

```bash
lxkit cpu
lxkit memory
lxkit uptime
```

These commands are intentionally simple and are mainly used to become comfortable with building Linux CLI tools.

---

## Learning Approach

For every Linux topic studied:

1. Understand the concept.
2. Explore the related Linux files and directories.
3. Build a command around that concept.
4. Make the command genuinely useful.

Example:

Learning:

* Major numbers
* Minor numbers
* Device files
* sysfs hierarchy

Possible command:

```bash
lxkit device nvme0n1
```

Example output:

```text
Device Name : nvme0n1
Device File : /dev/nvme0n1
Major       : 259
Minor       : 0
Partitions  : nvme0n1p1
Subsystem   : block
```

This ensures every feature teaches a Linux concept.

---

## Planned Commands

### Basic Commands

```bash
lxkit cpu
lxkit memory
lxkit uptime
```

### Device Exploration

```bash
lxkit device <device-name>
lxkit devices
```

### Process Exploration

```bash
lxkit process <pid>
lxkit ps
```

### Filesystem Exploration

```bash
lxkit mounts
lxkit filesystem
```

### Network Exploration

```bash
lxkit network
```

### File Descriptor Exploration

```bash
lxkit files <pid>
```

---

## Long-Term Vision

LXKit should eventually become a personal Linux toolbox containing utilities that help explore:

* devices
* processes
* filesystems
* memory
* networking
* system resources

while simultaneously serving as a learning platform for Linux internals and modern C++ development.

---

## Success Criteria

This project is successful if:

* I understand Linux concepts through implementation.
* I become comfortable exploring `/proc`, `/sys`, and `/dev`.
* Every new Linux topic can be converted into a useful command.
* The project grows into a reusable Linux toolbox.
* The knowledge gained helps build more advanced systems projects in the future.
