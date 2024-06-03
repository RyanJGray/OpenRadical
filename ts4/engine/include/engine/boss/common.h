//
// The OpenFRD Project
//
// TS4 Tree

// Line 153
typedef long long unsigned int u64;

// Line 154
typedef float f32;

// Line 155
typedef unsigned int u32;

// Line 156
typedef int s32;

// Line 157
typedef short unsigned int u16;

// Line 158
typedef short int s16;

// Line 159
typedef unsigned char u8;

// Line 160
typedef char s8;

// Line 175
typedef union mtx {
  float[4][4] f;
  vec4[4] v;
  hwec4[4] sm;
  VmathMatrix4 csm;
} mtx_u;

// Line 176
typedef union vec2 {
  float[2] v;
  structure;
} vec2_u;
