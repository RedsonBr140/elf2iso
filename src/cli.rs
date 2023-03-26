use clap::Error;
use clap::Parser;
#[derive(Parser)]
#[command(
    author = "Redson <redson@riseup.net>",
    version = "0.1.0",
    about = "A command-line tool for converting ELF files to ISO format for the PlayStation 2."
)]
pub struct Cli {
    /// The ELF to be included in the ISO.
    #[arg(required = true)]
    pub elf: Option<std::path::PathBuf>,

    /// Where to output the iso.
    #[arg(required = true)]
    pub output: Option<std::path::PathBuf>,

    /// whether to delete ISO directory after building the ISO itself.
    #[arg(short = 'd', long = "delete", required = false)]
    pub should_delete: bool,

    /* TODO: Don't hardcode "ISO/". Use this instead
        #[arg(short = 'D'), default_value = "ISO"]
        dir: std::path::PathBuf,
    */
    /// Video mode
    #[arg(
        short = 'v',
        long = "video",
        value_name = "MODE",
        required = false,
        default_value = "NTSC",
        value_parser = video_mode_valid
    )]
    pub video: String,
}

const VIDEO_MODES: [&str; 2] = ["NTSC", "PAL"];

fn video_mode_valid(s: &str) -> Result<String, Error> {
    if VIDEO_MODES.contains(&s) {
        Ok(s.to_string())
    } else {
        Err(clap::Error::new(clap::error::ErrorKind::InvalidValue))
    }
}
