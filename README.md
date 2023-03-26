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
  -D, --dir <DIR>     [default: ISO]
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
1. Install from `crates.io`: `cargo install elf2iso`

## License

Elf2iso is licensed under the MIT license. See `LICENSE` for more information.
