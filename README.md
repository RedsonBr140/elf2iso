# elf2iso

A command-line tool for converting ELF files to ISO format for the PlayStation 2.

## Usage

```bash
./elf2iso [OPTIONS] ELF_FILE

# Example:
./elf2iso -VPAL hello.elf -o hello.iso
```
This would generate a `hello.iso` file at the current directory, with the video mode being PAL.

### Options


|Short|Long| Description |
|--|--|---|
|  -o | --output[=ELF_FILE.iso | Where to output the iso (Default: $(PWD)/ELF_FILE_NAME.iso) |
|  -d | --delete |               Delete ISO directory after building the ISO itself. |
|  -D | --dir[=ISO/] |           Generate the ISO from this directory. Useful if you want to include other files. (Default: ISO) |
|  -V | --video[=NTSC] |         Video mode (Default: NTSC) |
|  -? | --help |                 Give this help list |
|     | --usage|                Give a short usage message|
|     | --version|              Print program version|

## Dependencies

Elf2iso depends on:

- GCC (or Clang)
- Meson
- Libisofs

## Installation
### Linux

1. Clone the repository: `git clone https://github.com/username/elf2iso.git`
2. Navigate to the project directory: `cd elf2iso`
3. Setup meson: `meson setup build`
4. Build the project: `meson compile -C build`
4. Install the binary: `sudo meson install -C build`

## License

Elf2iso is licensed under the MIT license. See `LICENSE` for more information.
