# Bash Command Frequency Analyzer

A minimal, memory-safe C utility that parses, deduplicates, and ranks the top 10 most frequently executed shell commands directly from your local `.bash_history`.

## Features
- **Dynamic Path Resolution**: Uses `getenv("HOME")` to locate `.bash_history` automatically on any standard Linux distribution.
- **Efficient Deduplication**: Employs an array registry structure to match and track command frequencies securely.
- **Custom Sorting Mechanism**: Integrates an exact-boundary Bubble Sort to rank commands accurately without data corruption.

## Quick Start

Compile using your preferred C compiler (e.g., GCC) and execute it from your terminal:

```bash
gcc -O2 -Wall -Wextra main.c -o freq
./freq
```
