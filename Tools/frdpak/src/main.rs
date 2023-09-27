use std::fs::File;
use std::io::prelude::*;
use frdpak::PackHeader;
use clap::{Parser, Subcommand};

#[derive(Parser)]
#[command(author, version, about, long_about = None)]
struct Cli {
  #[command(subcommand)]
  commands: Commands,
}

#[derive(Subcommand)]
enum Commands {
  /// Inspect a PAK file.
  Inspect {
    /// Path to the file.
    path: std::path::PathBuf,
  },
  /// Generate a PAK file from a directory.
  Generate {
    /// Directory to generate PAK file from.
    path: std::path::PathBuf,
  },
}

fn main() {
  let cli = Cli::parse();

  match &cli.commands {
    Commands::Inspect { path } => {
      let mut offset = 0usize;
      let mut buffer = Vec::new();
      let mut file = File::open(path).unwrap();

      file.read_to_end(&mut buffer).unwrap();
      let header = PackHeader::read(&buffer, &mut offset);

      println!();
      println!("Pack file information");
      println!("\tVersion: {:?}", header.version);
      println!("\tString Table Offset: {}", header._dirofs);
      println!("\tString Table Length: {}", header._dirlen);
    }
    Commands::Generate { path } => { println!("Generating PAK file from {}", path.display()) }
  }
}
