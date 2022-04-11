# Multithreaded Prime Numbers

This is a quick project I made to display the effectiveness of multithreading by calculating the prime numbers in the range (2^0, 2^16]. It's not the largest number - 65536 - but it suits the purposes of the project*.

## Usage

For those of you who want to test out the capabilities of multithreading,
```bash
make main
./main
```

For others who would rather execute serially,
```bash
make st
./main
```

And to clean,
```bash
make clean
```

## Footnotes
*I didn't want to sit through twenty seconds of my computer calculating each prime number up to 2^24, so I decided 2^16 was a good halfway between 2^24 and 2^4.

## Contributing
Pull requests are always welcome! There's tons of fixes and additions I haven't made yet.

## License
Unlicensed
