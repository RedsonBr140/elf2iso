use clap::Parser;
use std::fs::{self, File};
use std::io::Write;
use std::path::{Path, PathBuf};
mod cli;
use std::io;
use std::process::Command;

fn main() -> Result<(), Box<io::Error>> {
    let path = Path::new("ISO/");
    let args = cli::Cli::parse();
    let elf_path = PathBuf::from(args.elf.unwrap());

    if let Err(err) = fs::create_dir(path) {
        match err.kind() {
            io::ErrorKind::AlreadyExists => {}
            _ => return Err(Box::new(err)),
        }
    }

    println!("Created {} directory.", path.display());

    println!("Copying {} to {}", elf_path.display(), path.display());
    fs::copy(&elf_path, path.join("BOOT.ELF"))?;

    let cnf_content = format!(
        "BOOT2 = cdrom0:\\BOOT.ELF;1\nVER = 1.00\nVMODE = {}\n",
        args.video
    );

    let mut system_cnf = File::create(path.join("SYSTEM.CNF"))?;

    system_cnf.write_all(cnf_content.as_bytes())?;

    let output = Command::new("mkisofs")
        .arg("-o")
        .arg(args.output.unwrap())
        .arg("-R")
        .arg(path.join("."))
        .output()
        .expect("Failed to execute mkisofs.");

    if output.status.success() {
        println!("ISO created.");
    } else {
        let error = String::from_utf8_lossy(&output.stderr);
        println!("Command failed with error: {}", error);
    }

    if args.should_delete {
        fs::remove_dir_all(path)?;
        println!("{} deleted as desired.", path.display());
    }
    Ok(())
}
