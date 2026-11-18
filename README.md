# C Lo Shu Magic Square

A C coursework exercise that validates a 3×3 magic square. It checks that each digit from 1 to 9 occurs once and that the rows, columns, and diagonals have equal sums. A shuffle-based generator supplies a random permutation to validate.

## Build and run

```sh
cc -std=c11 -Wall -Wextra loShu.c -o lo-shu
./lo-shu
```

The program prints the results for built-in valid, invalid, and random arrangements. The generator samples permutations, so its result may fail validation.
