# 🔡 Caesar Cipher (C)

A command-line Caesar cipher tool written in portable C. Encrypt, decrypt, or brute-force a message.

## Build
```bash
gcc -Wall -Wextra -o caesar caesar.c
```

## Usage
```bash
./caesar encrypt 3 "Hello, World!"     # Khoor, Zruog!
./caesar decrypt 3 "Khoor, Zruog!"     # Hello, World!
./caesar crack "Khoor, Zruog!"         # prints all 25 possible shifts
```

## Notes
- Preserves case; leaves digits, spaces, and punctuation unchanged
- Handles negative and large keys via modulo arithmetic
- Dynamically allocates the output buffer (no fixed-size limits)
- The Caesar cipher is **not secure**; this is for learning only

## License
MIT
