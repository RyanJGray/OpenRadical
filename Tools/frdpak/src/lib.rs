use byteorder::{ByteOrder, BigEndian, LittleEndian};

#[derive(Debug)]
pub enum PackVersion {
  NONE,
  P4CK,
  P5CK,
  P8CK,
}

#[derive(Debug)]
pub struct PackHeader {
  pub version: PackVersion, // P4CK, P8CK, etc.
  pub _dirofs: i32,
  pub _dirlen: i32,
}

pub fn get_slice<'a>(buffer: &'a [u8], offset: &mut usize, size: usize) -> &'a [u8] {
	let start_index = *offset;
	let end_index = start_index + size;

	*offset += size;
	&buffer[start_index..end_index]
}

impl PackHeader {
  pub fn get_version(raw_id: &i32) -> PackVersion {
    match raw_id {
      0x5034434B => PackVersion::P4CK,
      0x5035434B => PackVersion::P5CK,
      0x5038434B => PackVersion::P8CK,
      _n => PackVersion::NONE,
    }
  }

  pub fn read(buffer: &[u8], offset: &mut usize) -> PackHeader {
    let mut load_part = |size| { get_slice(&buffer, offset, size) };

    let result = PackHeader {
      version: self::PackHeader::get_version(&BigEndian::read_i32(&load_part(4))),
      _dirofs: LittleEndian::read_i32(&load_part(4)),
      _dirlen: LittleEndian::read_i32(&load_part(4)),
    };

    println!("{}", result._dirofs);

    result
  }
}

