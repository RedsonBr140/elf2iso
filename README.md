# elf2iso

A command-line tool for converting ELF files to ISO format for the PlayStation 2.

## Usage

```bash
Usage: elf2iso [OPTIONS] <ELF> <OUTPUT>

# Example:
elf2iso -v PAL myelf.elf top10elfs.iso
```
This would generate a `top10elfs.iso` file at the current directory, with the video mode being PAL.

### Options

```
  -d, --delete        whether to delete ISO directory after building the ISO itself
  -v, --video <MODE>  Video mode [default: NTSC]
  -h, --help          Print help
  -V, --version       Print version
```

## Dependencies

Elf2iso depends on:

- Rust
- mkisofs command

## Installation
### Linux

1. Clone the repository: `git clone https://github.com/username/elf2iso.git`
2. Navigate to the project directory: `cd elf2iso`
3. Build the project: `cargo build`
4. Install the binary: `cargo install --path .`

(I swear i'll add to crates.io)

## License

Elf2iso is licensed under the MIT license. See `LICENSE` for more information.
