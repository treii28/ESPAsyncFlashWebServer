#include "SPIFFSEditor.h"
#include <FS.h>

//File: edit.htm.gz, Size: 4128
#define edit_htm_gz_len 4128
const uint8_t edit_htm_gz[] PROGMEM = {
 0x1F, 0x8B, 0x08, 0x08, 0x49, 0x16, 0x97, 0x59, 0x00, 0x03, 0x65, 0x64, 0x69, 0x74, 0x2E, 0x68,
 0x74, 0x6D, 0x00, 0xB5, 0x5A, 0x0D, 0x7B, 0xDB, 0xB6, 0xAE, 0xFE, 0x2B, 0x8A, 0x7A, 0x96, 0x49,
 0xC7, 0xB2, 0x6C, 0x27, 0x69, 0xD6, 0xCA, 0x51, 0x32, 0x3B, 0x49, 0x9B, 0x36, 0xCD, 0x47, 0x63,
 0xBB, 0x5D, 0xDA, 0x93, 0xBB, 0x87, 0x96, 0x68, 0x9B, 0x89, 0x44, 0xA9, 0x12, 0x15, 0x27, 0xF5,
 0xFC, 0xDF, 0x2F, 0x40, 0x4A, 0xB6, 0xE4, 0xB8, 0xED, 0x7A, 0xEE, 0xDD, 0xBA, 0xD5, 0x24, 0xC1,
 0x0F, 0x00, 0x04, 0x5E, 0x00, 0xD4, 0xF6, 0x36, 0x8E, 0x2E, 0x0E, 0xFB, 0xD7, 0x97, 0xC7, 0xDA,
 0x44, 0x84, 0xC1, 0xFE, 0x1E, 0xFE, 0xAD, 0x05, 0x84, 0x8F, 0x5D, 0xCA, 0xF7, 0xF7, 0x04, 0x13,
 0x01, 0xDD, 0x3F, 0xEE, 0x5D, 0x6A, 0xC7, 0x3E, 0x13, 0x51, 0xB2, 0xD7, 0x50, 0x23, 0x7B, 0xA9,
 0x78, 0x0C, 0xA8, 0x16, 0x52, 0x9F, 0x11, 0x37, 0xF5, 0x12, 0x0A, 0x93, 0x6D, 0x2F, 0x9C, 0x7D,
 0xAD, 0x33, 0xEE, 0xD3, 0x07, 0x67, 0xBB, 0xD9, 0x6C, 0xC7, 0x51, 0xCA, 0x04, 0x8B, 0xB8, 0x43,
 0x86, 0x69, 0x14, 0x64, 0x82, 0xB6, 0x03, 0x3A, 0x12, 0xCE, 0xF3, 0xF8, 0xA1, 0x3D, 0x8C, 0x12,
 0x9F, 0x26, 0x4E, 0x2B, 0x7E, 0xD0, 0x80, 0xC4, 0x7C, 0xED, 0xD9, 0xCE, 0xCE, 0x4E, 0x7B, 0x48,
 0xBC, 0xBB, 0x71, 0x12, 0x65, 0xDC, 0xAF, 0x7B, 0x51, 0x10, 0x25, 0xCE, 0xB3, 0xD1, 0x73, 0xFC,
 0xD3, 0xF6, 0x59, 0x1A, 0x07, 0xE4, 0xD1, 0xE1, 0x11, 0xA7, 0xB0, 0xF6, 0xA1, 0x9E, 0x4E, 0x88,
 0x1F, 0x4D, 0x9D, 0xA6, 0xD6, 0xD4, 0x5A, 0x4D, 0xD8, 0x24, 0x19, 0x0F, 0x89, 0xD1, 0xB4, 0xF0,
 0x8F, 0xBD, 0x63, 0xB6, 0x47, 0x11, 0x17, 0xF5, 0x94, 0x7D, 0xA5, 0x4E, 0x6B, 0x0B, 0x4E, 0x93,
 0xDD, 0x11, 0x09, 0x59, 0xF0, 0xE8, 0xA4, 0x84, 0xA7, 0xF5, 0x94, 0x26, 0x6C, 0xA4, 0x86, 0xA7,
 0x94, 0x8D, 0x27, 0xC2, 0xF9, 0xAD, 0xD9, 0x9C, 0x03, 0xFF, 0x5A, 0x16, 0xCC, 0x02, 0x96, 0xC2,
 0x62, 0x14, 0x4F, 0x9D, 0x27, 0xA2, 0xD8, 0x69, 0x2A, 0xD6, 0x9B, 0xED, 0x90, 0x24, 0x63, 0xC6,
 0xA1, 0x11, 0x13, 0xDF, 0x67, 0x7C, 0xEC, 0xA8, 0x65, 0x01, 0x9B, 0x2D, 0xA4, 0x4D, 0x68, 0x40,
 0x04, 0xBB, 0xA7, 0xED, 0x90, 0xF1, 0xFA, 0x94, 0xF9, 0x62, 0xE2, 0xEC, 0x02, 0x8F, 0x6D, 0x2F,
 0x4B, 0x52, 0x90, 0x29, 0x8E, 0x18, 0x17, 0x34, 0x91, 0xCB, 0xD2, 0x98, 0xF0, 0x59, 0x2E, 0x2A,
 0x2A, 0xA0, 0x90, 0x93, 0xF1, 0x80, 0x71, 0x5A, 0x1F, 0x06, 0x91, 0x77, 0xB7, 0x38, 0x69, 0x37,
 0x7E, 0xC8, 0xCF, 0x72, 0x26, 0xD1, 0x3D, 0x4D, 0x66, 0x4B, 0x75, 0xC9, 0xD5, 0x15, 0x62, 0x65,
 0x6B, 0x4A, 0xE9, 0xDC, 0x16, 0xF7, 0x19, 0x50, 0x2D, 0xF9, 0x0B, 0x52, 0x2E, 0xF8, 0x5F, 0x8A,
 0xB4, 0x22, 0xB8, 0x5A, 0xC2, 0x78, 0x9C, 0x89, 0xD9, 0xD3, 0xAB, 0x8C, 0x62, 0xE2, 0x31, 0xF1,
 0x88, 0xF2, 0xC3, 0xB4, 0x19, 0xEA, 0x12, 0x56, 0x25, 0x21, 0x09, 0x34, 0xD4, 0xB9, 0xF6, 0x81,
 0x26, 0x3E, 0xE1, 0xC4, 0xEA, 0x24, 0x8C, 0x04, 0x56, 0x6F, 0xA9, 0xF5, 0x7A, 0x18, 0x7D, 0xAD,
 0x67, 0xD0, 0x86, 0x7E, 0x40, 0x3D, 0xA1, 0x94, 0x0C, 0xF7, 0x30, 0xBC, 0x63, 0xE2, 0x29, 0xE1,
 0xC9, 0x40, 0x49, 0x5D, 0x52, 0x49, 0x13, 0x75, 0x81, 0x2D, 0xA9, 0x1E, 0xE4, 0x58, 0x4A, 0xAE,
 0x84, 0xAA, 0x0F, 0x23, 0x21, 0xA2, 0x50, 0x9A, 0xDC, 0x42, 0x60, 0x4D, 0x5A, 0xCD, 0x8B, 0x27,
 0x37, 0xB2, 0x5E, 0xFB, 0xA5, 0xED, 0xDB, 0xA0, 0x57, 0xC1, 0x3C, 0x12, 0xD4, 0x49, 0xC0, 0xC6,
 0xDC, 0x09, 0x99, 0xEF, 0x07, 0xB4, 0x64, 0xB5, 0x4E, 0x96, 0x04, 0x86, 0x4F, 0x04, 0x71, 0x58,
 0x48, 0xC6, 0xB4, 0x11, 0xF3, 0x31, 0x50, 0x53, 0xBA, 0xBB, 0x63, 0xB1, 0x0F, 0xDD, 0x8B, 0xAB,
 0x69, 0xF3, 0xF4, 0xF5, 0x38, 0xEA, 0xC0, 0x3F, 0xE7, 0xBD, 0xC1, 0xE4, 0x78, 0x30, 0x86, 0x56,
 0x17, 0xBB, 0x9D, 0xF7, 0x87, 0x9D, 0xF7, 0xF0, 0x73, 0xD8, 0xAA, 0xDD, 0x8E, 0xBE, 0xE0, 0x40,
 0xF7, 0xB5, 0xDF, 0xED, 0x0F, 0x8E, 0x3B, 0x9D, 0xD3, 0xC6, 0x9B, 0xF3, 0xE9, 0xC7, 0xD3, 0x5D,
 0x24, 0x77, 0x83, 0xE6, 0xD5, 0x87, 0x49, 0x73, 0xB0, 0xF5, 0x32, 0xF4, 0x4F, 0xFC, 0x89, 0x17,
 0x0E, 0x3A, 0xEF, 0x3F, 0x5E, 0xDD, 0x5F, 0x87, 0x83, 0x71, 0xEF, 0x63, 0x6B, 0xF2, 0x69, 0xEB,
 0x43, 0xEF, 0xD3, 0xC7, 0x57, 0x77, 0xF4, 0x8F, 0x93, 0xB7, 0x9F, 0xFA, 0x53, 0x58, 0x70, 0x14,
 0xF5, 0x06, 0x57, 0xDD, 0x0F, 0xDD, 0xF1, 0xA7, 0xAE, 0x77, 0xFC, 0x30, 0x0C, 0xCE, 0xBB, 0xAF,
 0x3B, 0xC3, 0xCE, 0x96, 0x47, 0xE9, 0xB8, 0x7F, 0xD5, 0xCD, 0xDE, 0x9C, 0x5E, 0x8C, 0x19, 0x9B,
 0xF4, 0x3E, 0x9D, 0xF7, 0xBD, 0xC3, 0xE7, 0xEF, 0x06, 0x27, 0x1D, 0x36, 0x39, 0x7F, 0x7B, 0xD5,
 0xBC, 0x7B, 0x7D, 0x7A, 0x78, 0xE4, 0x5D, 0xBF, 0xBD, 0xDE, 0x3D, 0xDA, 0x6E, 0xFC, 0xF6, 0xDB,
 0x99, 0x7F, 0xC1, 0x78, 0xFF, 0xFE, 0x6B, 0x67, 0x7C, 0x38, 0x7D, 0xF1, 0x98, 0xF6, 0x27, 0x6F,
 0xEE, 0x79, 0xE3, 0x43, 0x74, 0xFB, 0xE6, 0xF1, 0x0C, 0xFE, 0xBB, 0xBC, 0xAC, 0x0D, 0x7B, 0xAD,
 0x74, 0xF0, 0xFE, 0xCD, 0x87, 0xAD, 0xF4, 0xE5, 0xF3, 0xB8, 0x7B, 0x74, 0x74, 0x1F, 0x0E, 0x2F,
 0x1B, 0xA1, 0x7F, 0x37, 0x12, 0x2F, 0xB6, 0x45, 0x7C, 0x3D, 0xCE, 0x3E, 0x7D, 0x79, 0xFE, 0x76,
 0xD2, 0xB8, 0xA0, 0xE4, 0x7A, 0x52, 0x7B, 0xFC, 0xFA, 0xF8, 0x62, 0xD2, 0x3F, 0xB9, 0x3F, 0x0F,
 0xC8, 0xC3, 0xF9, 0xB9, 0xF7, 0x35, 0xAC, 0x05, 0xE4, 0xE5, 0x45, 0x3F, 0x20, 0x49, 0x6B, 0xE0,
 0x77, 0x1A, 0xB5, 0xC3, 0xAD, 0xCE, 0x8E, 0x48, 0xAE, 0x0E, 0xF9, 0xD1, 0xF6, 0x6D, 0xEF, 0x45,
 0xB7, 0xDB, 0x8A, 0x86, 0x5F, 0xB6, 0x5E, 0xDF, 0xED, 0xBE, 0x1E, 0xEC, 0xBE, 0x1F, 0xBE, 0xEF,
 0xF4, 0x76, 0xBA, 0x03, 0x72, 0xDD, 0x7B, 0xDF, 0x19, 0xED, 0x0C, 0x27, 0x93, 0xD3, 0xD3, 0xFE,
 0x2B, 0xBF, 0xF3, 0x35, 0xE9, 0x5C, 0x4C, 0x3B, 0x0F, 0xC7, 0x83, 0xCE, 0x49, 0xED, 0xF4, 0xF8,
 0xAC, 0xD9, 0xEA, 0x5D, 0x6F, 0x8F, 0xCF, 0x76, 0xA7, 0xDD, 0xF4, 0xB8, 0xF3, 0xBE, 0xDB, 0x1C,
 0xBF, 0xAD, 0x85, 0xE4, 0x53, 0x74, 0xB8, 0x3D, 0x7E, 0xB3, 0xCB, 0x2E, 0xAF, 0x49, 0xE7, 0x4D,
 0xF7, 0x6D, 0xCA, 0xAE, 0xC2, 0x93, 0x41, 0xB3, 0xD3, 0x79, 0x77, 0x41, 0x5F, 0x1D, 0x6E, 0x93,
 0xD3, 0x2D, 0xEF, 0x23, 0xE8, 0x7F, 0xF0, 0x07, 0xFD, 0xAD, 0xD6, 0x99, 0x5E, 0x34, 0x03, 0xEF,
 0x25, 0xED, 0x9F, 0x5C, 0xF7, 0xE5, 0xED, 0x1C, 0x07, 0xAF, 0xFA, 0x77, 0xBD, 0xEC, 0x7D, 0x78,
 0x78, 0x68, 0x6A, 0x3C, 0xAA, 0x27, 0x34, 0xA6, 0x44, 0x94, 0xE1, 0x6A, 0xE1, 0x1F, 0x60, 0x5B,
 0x4B, 0x2B, 0xCC, 0xFD, 0x54, 0xD0, 0x07, 0x51, 0xF7, 0xA9, 0x17, 0x25, 0x44, 0xCE, 0x81, 0x05,
 0x34, 0x41, 0x13, 0x9B, 0xFF, 0x2E, 0xF1, 0x53, 0x53, 0xF8, 0xA9, 0x11, 0xEE, 0x6B, 0x46, 0xE1,
 0x08, 0x08, 0x1E, 0x3E, 0xBD, 0x67, 0x1E, 0xAD, 0xC7, 0xEC, 0x81, 0x06, 0x75, 0xB9, 0xD8, 0x69,
 0x9A, 0x33, 0xE9, 0x6F, 0xC5, 0x34, 0xC2, 0xC1, 0xD4, 0xE4, 0xAE, 0xC5, 0x80, 0x7F, 0x4B, 0x3C,
 0x0A, 0xC0, 0x06, 0x2E, 0x13, 0xE2, 0xAF, 0xF2, 0x9D, 0x28, 0xA9, 0x0F, 0xB3, 0xF1, 0x88, 0x3D,
 0x80, 0x43, 0x8F, 0x18, 0x67, 0x82, 0x6A, 0xAD, 0x74, 0xFE, 0x7B, 0xB1, 0xCD, 0x1D, 0x7D, 0x1C,
 0x25, 0x24, 0xA4, 0xA9, 0xF6, 0x37, 0xB7, 0x99, 0x8D, 0x92, 0x28, 0x5C, 0x82, 0xC8, 0x5C, 0x44,
 0xA5, 0xCE, 0x7C, 0xFE, 0x2C, 0x8B, 0x83, 0x88, 0x80, 0x98, 0x6B, 0x90, 0x43, 0xE1, 0x69, 0x22,
 0xDD, 0x6A, 0x81, 0xAB, 0xB9, 0x9B, 0x6D, 0xA1, 0x5B, 0x96, 0xDD, 0x7A, 0x6B, 0x67, 0xE9, 0xBA,
 0x75, 0x39, 0x17, 0xF1, 0x7E, 0x4D, 0xA4, 0x40, 0x3C, 0x28, 0xC1, 0xDD, 0x33, 0x01, 0x2A, 0xFD,
 0xC6, 0xE1, 0xF2, 0x90, 0x1C, 0x19, 0x16, 0x0C, 0x28, 0xA0, 0x6E, 0x49, 0xA4, 0x2E, 0x24, 0x81,
 0x79, 0xF3, 0x67, 0x54, 0xC6, 0x3D, 0xEB, 0x59, 0x9C, 0xC0, 0x6D, 0xD0, 0xE9, 0xF7, 0xF6, 0x2C,
 0x64, 0xAA, 0xEE, 0xAD, 0xF6, 0x54, 0x11, 0x2F, 0x17, 0x61, 0x19, 0xF6, 0x24, 0xAF, 0xC5, 0xD6,
 0x4F, 0xA5, 0x02, 0xF2, 0x82, 0x9B, 0xE7, 0xC8, 0xCD, 0x77, 0xB5, 0xBA, 0xBD, 0xFB, 0x4B, 0xCE,
 0xC3, 0x4E, 0xF3, 0x97, 0xB9, 0x9D, 0xCF, 0x2D, 0x42, 0x72, 0xAB, 0x09, 0xFF, 0x14, 0x91, 0xF7,
 0xC5, 0x92, 0x85, 0xE1, 0x73, 0xFC, 0x53, 0x30, 0x88, 0xFB, 0x94, 0x88, 0xDB, 0x3B, 0x2F, 0x5F,
 0xF8, 0xC3, 0x82, 0x98, 0x0B, 0xF6, 0x4D, 0x7A, 0x42, 0x7C, 0x96, 0xA5, 0xCE, 0xF3, 0xE6, 0x2F,
 0xB9, 0x3E, 0xB7, 0x76, 0x50, 0xF6, 0xC5, 0x5D, 0x62, 0x67, 0x69, 0xB1, 0x69, 0xCC, 0xB8, 0xB6,
 0x95, 0x6A, 0x78, 0xDF, 0x24, 0x59, 0x18, 0x66, 0x25, 0xDA, 0xCF, 0x7F, 0x5F, 0x9A, 0x26, 0xCE,
 0x9F, 0x35, 0x7F, 0x99, 0x89, 0x04, 0xA2, 0xC9, 0x08, 0x62, 0x8D, 0x93, 0x44, 0x82, 0x08, 0x6A,
 0x34, 0xCD, 0x39, 0x08, 0xB7, 0x86, 0xB0, 0xBD, 0xDB, 0xF4, 0xE9, 0xD8, 0x9C, 0xCF, 0xF7, 0x1A,
 0x32, 0xAE, 0x41, 0xDA, 0xE2, 0x25, 0x2C, 0x16, 0xFB, 0xA3, 0x8C, 0x7B, 0xC8, 0x83, 0x36, 0xA6,
 0x06, 0x35, 0x67, 0x09, 0x15, 0x59, 0xC2, 0x35, 0x3F, 0xF2, 0x32, 0x34, 0x76, 0x7B, 0x4C, 0xC5,
 0xB1, 0xB2, 0xFB, 0xEE, 0xE3, 0x1B, 0x1F, 0x66, 0xCC, 0x17, 0x0B, 0xBC, 0xB5, 0x0B, 0xC0, 0x81,
 0xE1, 0xBC, 0x7C, 0x4D, 0x65, 0x3E, 0x04, 0x18, 0xD8, 0xE4, 0x94, 0x3E, 0x1A, 0xD4, 0x12, 0x8B,
 0x85, 0xD4, 0xC6, 0x71, 0xA3, 0x98, 0x05, 0x34, 0x6E, 0xCE, 0xEE, 0x41, 0x09, 0xC4, 0xA5, 0x9F,
 0xC5, 0x8D, 0xC5, 0x5C, 0x0E, 0x3F, 0xED, 0x7C, 0x36, 0xD9, 0x63, 0x07, 0xF5, 0x96, 0x43, 0xF6,
 0xD9, 0x41, 0x0B, 0xDC, 0xAB, 0xCC, 0x8D, 0x3C, 0xF7, 0x15, 0x0B, 0xE8, 0x20, 0x77, 0x38, 0x3C,
 0x06, 0x37, 0x5B, 0x4C, 0x21, 0x6A, 0xF3, 0xAD, 0x66, 0x73, 0xC3, 0xA5, 0x07, 0x24, 0x80, 0x18,
 0x66, 0xE8, 0xC7, 0x57, 0x57, 0x17, 0x57, 0x9F, 0xF5, 0x1A, 0xAD, 0xE9, 0x37, 0x8E, 0xA6, 0xD7,
 0xB8, 0xE9, 0x08, 0x3B, 0xA1, 0xA3, 0x84, 0xA6, 0x93, 0x4B, 0x22, 0x26, 0x86, 0x67, 0xDF, 0x93,
 0x20, 0x2B, 0x0B, 0xC2, 0x50, 0x6E, 0x64, 0x51, 0xB8, 0x9C, 0x4E, 0xB5, 0x57, 0xA0, 0xE6, 0x23,
 0x08, 0x75, 0x6D, 0x61, 0x93, 0x38, 0xA6, 0xDC, 0x37, 0xF4, 0x18, 0x16, 0xEA, 0x16, 0x35, 0xAD,
 0x84, 0x7E, 0xC9, 0x68, 0x2A, 0x52, 0x1B, 0x2C, 0xD7, 0xD0, 0x2F, 0x07, 0x7D, 0xDD, 0xD2, 0x1B,
 0xE8, 0x47, 0x3A, 0xF0, 0x46, 0xCC, 0x39, 0xEE, 0x12, 0xB9, 0xA0, 0x49, 0x5D, 0x66, 0x17, 0xBA,
 0xD9, 0x8E, 0x6C, 0xF1, 0x18, 0x53, 0x57, 0x1F, 0x81, 0x24, 0xBA, 0x15, 0xD9, 0x61, 0x16, 0x08,
 0x16, 0x07, 0xD4, 0xDD, 0x68, 0x41, 0x8F, 0xC3, 0xF5, 0xBB, 0x3A, 0x06, 0x56, 0xA4, 0x31, 0xDF,
 0xD5, 0x15, 0xBC, 0xE4, 0xA0, 0xA4, 0x5B, 0xF2, 0x16, 0x73, 0x3E, 0x0E, 0x27, 0x2C, 0xF0, 0x8D,
 0xC8, 0x6C, 0xE3, 0x29, 0x5E, 0xE5, 0x14, 0xAF, 0xBC, 0x56, 0x71, 0xEB, 0xE5, 0x07, 0x23, 0x46,
 0x63, 0x4F, 0x1D, 0x55, 0xD0, 0x7C, 0x3A, 0x22, 0xC0, 0xC9, 0x07, 0x54, 0x85, 0xAB, 0x37, 0xD6,
 0x1D, 0xE4, 0xA9, 0x83, 0x7C, 0x79, 0xD0, 0x30, 0x03, 0xFF, 0xE0, 0x70, 0x92, 0x6F, 0x33, 0xCE,
 0x69, 0x72, 0xD2, 0x3F, 0x7B, 0xE7, 0xEA, 0xEA, 0x6A, 0xD6, 0x2D, 0xF6, 0xD5, 0xE2, 0xB4, 0xBA,
 0x38, 0x2D, 0x2F, 0x3E, 0x94, 0x37, 0xBC, 0x6E, 0x71, 0xAA, 0x16, 0x07, 0x15, 0x11, 0x03, 0x29,
 0xA2, 0xC2, 0xAC, 0x3A, 0x6A, 0x13, 0x05, 0xD2, 0xAD, 0xA0, 0x22, 0x66, 0x60, 0x83, 0x8B, 0x91,
 0x61, 0x40, 0x7D, 0x77, 0xA3, 0x09, 0x3D, 0xCC, 0x94, 0xDD, 0xAD, 0xE6, 0x9A, 0x33, 0x02, 0x75,
 0x46, 0x52, 0x65, 0x30, 0x29, 0x33, 0xA8, 0xF5, 0xC8, 0x3D, 0xD5, 0xD6, 0x31, 0x98, 0x98, 0x56,
 0x6A, 0x47, 0xDC, 0x0B, 0x98, 0x77, 0xE7, 0x2E, 0x4D, 0xDD, 0x9C, 0xB1, 0x85, 0x79, 0x59, 0x5C,
 0xA2, 0xD4, 0x00, 0xF2, 0xA6, 0xC5, 0x50, 0xDE, 0x40, 0x7D, 0xCF, 0xAD, 0x64, 0xED, 0x06, 0xDC,
 0xA6, 0x0F, 0xD4, 0x3B, 0x8C, 0xC2, 0x90, 0xA0, 0xE1, 0xA5, 0xC0, 0x41, 0xDE, 0xD1, 0xCD, 0xB9,
 0xE5, 0xAF, 0x3F, 0x74, 0x64, 0x80, 0x07, 0xB8, 0x91, 0x8D, 0x5A, 0x49, 0x6D, 0xD0, 0xCC, 0x58,
 0x4C, 0x7E, 0x60, 0xD1, 0x85, 0xC9, 0xC9, 0x25, 0x9F, 0x9B, 0x37, 0xD6, 0x82, 0xC9, 0x15, 0x13,
 0xBF, 0xE8, 0xAD, 0xD8, 0x38, 0xAA, 0xA3, 0x62, 0x69, 0xE6, 0x52, 0xAA, 0x32, 0x2D, 0xB7, 0xE0,
 0x05, 0x55, 0x9F, 0xCF, 0xE1, 0x3C, 0xE0, 0x7F, 0x02, 0x15, 0x18, 0xFD, 0xFB, 0x02, 0x2C, 0x79,
 0x94, 0x26, 0x6C, 0x71, 0xD7, 0x68, 0x18, 0x07, 0xCE, 0x7F, 0x6C, 0xE3, 0xF3, 0xFF, 0xD8, 0x37,
 0x35, 0xD3, 0x3C, 0xF8, 0x57, 0x43, 0x2A, 0xCD, 0x10, 0xE6, 0xE7, 0xD6, 0x8D, 0xD5, 0x30, 0xEC,
 0x7F, 0x9B, 0xFF, 0xB1, 0x25, 0xB1, 0x42, 0x81, 0x0B, 0x8F, 0x00, 0xD8, 0xF1, 0x24, 0x34, 0x99,
 0x68, 0xA4, 0xF1, 0xCD, 0x4D, 0x03, 0x34, 0x54, 0xB9, 0x98, 0x9A, 0x80, 0x20, 0xBF, 0x82, 0x42,
 0x7D, 0x88, 0xB8, 0x0A, 0xE4, 0x16, 0x04, 0xC9, 0x37, 0x4A, 0x0B, 0xC5, 0x1A, 0x97, 0xF2, 0x4A,
 0x28, 0x07, 0x71, 0xD3, 0xC4, 0x73, 0x95, 0xBE, 0x0E, 0x0A, 0x9A, 0x0B, 0x70, 0x34, 0x2F, 0xC3,
 0x96, 0x5A, 0xBA, 0x6A, 0xCB, 0x85, 0xAA, 0xA8, 0xB5, 0xA4, 0xE2, 0x86, 0x88, 0xEF, 0x76, 0x1E,
 0x3A, 0x5C, 0x1D, 0x63, 0x87, 0x6E, 0x4D, 0x56, 0x87, 0x65, 0x4E, 0x8F, 0xE3, 0x4B, 0x03, 0xFE,
 0x75, 0x8F, 0x85, 0x63, 0xAD, 0xC4, 0x0F, 0xFE, 0xE5, 0xFE, 0x8A, 0xD0, 0xB8, 0xF9, 0xA7, 0x37,
 0x04, 0xAE, 0xC0, 0x28, 0xA8, 0xCD, 0xA3, 0xA9, 0x61, 0xD6, 0x7E, 0xD5, 0x35, 0xB9, 0xA3, 0xAB,
 0x87, 0xE4, 0x21, 0x2F, 0xEE, 0x30, 0xF4, 0xB4, 0x35, 0xEC, 0x17, 0xB5, 0x42, 0x3E, 0x20, 0xCB,
 0x2A, 0x92, 0x89, 0xA8, 0xAD, 0x15, 0x21, 0x4D, 0xD5, 0x14, 0xBA, 0xD6, 0xD8, 0xFF, 0xB5, 0x82,
 0xAC, 0x16, 0x53, 0x17, 0xA9, 0x50, 0x31, 0x0B, 0xC0, 0xC9, 0xE8, 0xB7, 0xF1, 0x2C, 0x60, 0x12,
 0x32, 0xAB, 0x30, 0x64, 0x05, 0x06, 0x33, 0x0F, 0xC0, 0x8D, 0x4A, 0xBE, 0xB9, 0x87, 0x59, 0xE8,
 0xFE, 0xA5, 0x4A, 0x2F, 0x20, 0x06, 0x62, 0x0F, 0x71, 0xED, 0x89, 0x7F, 0xC0, 0xA5, 0x11, 0x58,
 0x6E, 0x2D, 0x02, 0xDA, 0x30, 0xF2, 0x1F, 0x4B, 0x61, 0x30, 0xED, 0x3E, 0x1E, 0x06, 0x24, 0x4D,
 0xCF, 0xE1, 0x06, 0x0C, 0xDD, 0x0B, 0x41, 0xE1, 0xCA, 0xFE, 0xF6, 0x9B, 0x9B, 0x9B, 0xD5, 0x45,
 0x09, 0x0D, 0x21, 0xEB, 0x55, 0x5C, 0x41, 0xFC, 0x30, 0x9D, 0x14, 0x36, 0x06, 0x13, 0x5A, 0xC3,
 0x18, 0x3E, 0x29, 0x7C, 0x8F, 0x2B, 0x08, 0x5B, 0x62, 0x81, 0x0F, 0xFF, 0x0C, 0x77, 0x25, 0xF0,
 0x5E, 0xA3, 0x55, 0x1F, 0xCE, 0x7C, 0xCA, 0xF6, 0x51, 0x6E, 0xB0, 0x0B, 0xD6, 0xD7, 0x00, 0x0E,
 0x28, 0x94, 0xFF, 0x33, 0x2C, 0x97, 0x00, 0x79, 0x0D, 0xC7, 0x80, 0xB9, 0xC9, 0x1A, 0x8E, 0x01,
 0x65, 0x04, 0x5D, 0xF0, 0xBB, 0x06, 0x54, 0x81, 0xDF, 0xEC, 0x9F, 0xE1, 0x77, 0x69, 0xE7, 0x51,
 0x91, 0x9B, 0xA8, 0x44, 0x07, 0x25, 0xF0, 0xD9, 0xBD, 0x6E, 0x5A, 0x91, 0x5B, 0xDD, 0x01, 0x92,
 0xB4, 0x28, 0x08, 0xFA, 0x51, 0x7C, 0xF0, 0x8D, 0x71, 0x67, 0x31, 0x5E, 0x34, 0x72, 0x36, 0x97,
 0x53, 0x2C, 0x6F, 0xED, 0xA6, 0xEF, 0x20, 0xFF, 0x5E, 0xBB, 0x2B, 0x12, 0x7E, 0xB4, 0x2D, 0xCE,
 0xB1, 0x7C, 0x97, 0xDA, 0xA0, 0x3C, 0x18, 0xFD, 0xA3, 0xE6, 0x59, 0xE9, 0xA2, 0x77, 0x5D, 0x8B,
 0xDA, 0x04, 0xDA, 0xB9, 0x92, 0x5C, 0x54, 0x92, 0x45, 0xBE, 0x01, 0x40, 0xC5, 0x38, 0x96, 0x03,
 0xAE, 0x5F, 0xD3, 0xE3, 0x87, 0xE5, 0x18, 0x64, 0xE0, 0x6E, 0xAA, 0x86, 0x98, 0x41, 0x00, 0x4F,
 0x57, 0x2E, 0xA5, 0x7C, 0xDD, 0xA4, 0xC8, 0x01, 0x88, 0x1D, 0x8D, 0x46, 0x29, 0x15, 0x1F, 0x11,
 0x92, 0xAC, 0x64, 0xD1, 0x3F, 0x91, 0x90, 0x04, 0x8C, 0x45, 0x3C, 0x8C, 0xB2, 0x94, 0x46, 0x99,
 0xA8, 0x04, 0x15, 0x63, 0x21, 0xCC, 0x9E, 0xFF, 0xD7, 0x5F, 0x8B, 0xCE, 0xBE, 0x5F, 0x0B, 0x96,
 0xDD, 0xEB, 0xBD, 0xB4, 0xD4, 0xD9, 0x4F, 0x6B, 0x89, 0xB9, 0x7A, 0xE9, 0xFF, 0x67, 0x4B, 0x21,
 0x65, 0x4B, 0xF1, 0x30, 0x67, 0x2D, 0x30, 0xB1, 0x84, 0x79, 0x32, 0x81, 0xE3, 0x25, 0x9F, 0x45,
 0x83, 0xC6, 0x84, 0x24, 0x4F, 0xC7, 0x4B, 0x96, 0xCF, 0x01, 0x50, 0x56, 0x5C, 0x79, 0x0D, 0xC2,
 0x80, 0x06, 0x52, 0x44, 0x26, 0x1F, 0xB4, 0xFE, 0x2E, 0x9A, 0xD2, 0xE4, 0x90, 0xA4, 0xD4, 0x80,
 0x68, 0x29, 0x4A, 0x79, 0x09, 0xF3, 0x4D, 0x27, 0x58, 0x37, 0x6B, 0x73, 0x93, 0x28, 0xF2, 0x5C,
 0xED, 0x1D, 0x71, 0xCC, 0xAF, 0x40, 0xBE, 0xAC, 0x72, 0x02, 0xB5, 0xB1, 0xC0, 0x03, 0xA9, 0x8F,
 0x54, 0x3A, 0x69, 0x98, 0x16, 0xE4, 0xFF, 0x70, 0xCD, 0x97, 0x49, 0x14, 0x93, 0xB1, 0x2C, 0x86,
 0x60, 0x0C, 0xDD, 0x03, 0x77, 0xB3, 0x36, 0x9A, 0xB8, 0xE1, 0x52, 0x1B, 0x7E, 0xE1, 0x37, 0xCB,
 0x5A, 0x82, 0x5B, 0xBA, 0x0A, 0x86, 0xED, 0xA5, 0x2F, 0xAD, 0x89, 0x1A, 0x04, 0x9F, 0x42, 0x13,
 0x03, 0xE7, 0x40, 0x45, 0x91, 0xDF, 0x03, 0xB8, 0x5B, 0xB3, 0x1D, 0xED, 0xB1, 0x76, 0x54, 0xAB,
 0x99, 0x2A, 0xE3, 0x76, 0x5D, 0xA8, 0x37, 0xA2, 0x1B, 0x99, 0x24, 0x82, 0x50, 0xD5, 0xC8, 0x62,
 0xC0, 0xD9, 0x48, 0x54, 0x79, 0x05, 0xB6, 0x30, 0x5F, 0x34, 0xCB, 0x35, 0xCE, 0xB2, 0x34, 0xF8,
 0x46, 0xD2, 0x41, 0x31, 0xB5, 0x68, 0x43, 0x06, 0xB3, 0x9A, 0x5C, 0x08, 0x33, 0x9D, 0x32, 0xE1,
 0x4D, 0x10, 0x80, 0x3C, 0xD0, 0xAA, 0x2E, 0x20, 0x41, 0x75, 0x64, 0x6B, 0x22, 0xC2, 0x65, 0x2B,
 0xC8, 0x9B, 0xB7, 0x69, 0xDE, 0xF0, 0xD2, 0xA2, 0xF5, 0x50, 0x22, 0x42, 0x7A, 0x9A, 0x93, 0x23,
 0x3E, 0xCA, 0x9B, 0x50, 0x54, 0x16, 0xFB, 0x14, 0xC4, 0xE2, 0x37, 0x8E, 0xF3, 0x56, 0x3C, 0x29,
 0x5A, 0x13, 0xFA, 0xB0, 0x58, 0x17, 0x15, 0x54, 0x9F, 0xEA, 0x8E, 0xB2, 0xB1, 0x8D, 0xE6, 0x3C,
 0x6F, 0xB4, 0x96, 0xF2, 0x07, 0xFF, 0x8F, 0xF2, 0xC7, 0x7C, 0x5C, 0x48, 0x13, 0x17, 0xAD, 0x31,
 0x2B, 0x64, 0x19, 0x86, 0xF1, 0x77, 0x39, 0x49, 0x4A, 0xC5, 0x69, 0xA9, 0xB8, 0x14, 0x3F, 0xAA,
 0xFF, 0x84, 0xE9, 0x18, 0xA3, 0x8A, 0x3F, 0x8E, 0x6C, 0x0F, 0x7F, 0xCF, 0x23, 0x5F, 0x66, 0x95,
 0xA6, 0x15, 0x1A, 0x23, 0xC8, 0x70, 0x75, 0xB3, 0xEC, 0xA7, 0xD9, 0x7F, 0x5B, 0x13, 0x1E, 0x1D,
 0xBF, 0x3B, 0xEE, 0x1F, 0x97, 0x53, 0x66, 0xE4, 0xBC, 0x64, 0x52, 0x71, 0xA5, 0x5C, 0x5E, 0x66,
 0x04, 0x90, 0x5A, 0xA3, 0x28, 0x60, 0xAF, 0x00, 0x26, 0xD2, 0x2F, 0xDE, 0xF6, 0x2E, 0xCE, 0xED,
 0x98, 0x24, 0xE0, 0x91, 0xA4, 0xC2, 0x5C, 0x58, 0x6C, 0x51, 0x3E, 0xF8, 0xF5, 0x71, 0x29, 0x51,
 0x97, 0x4F, 0xFD, 0x8E, 0x98, 0x5B, 0xEA, 0x34, 0x55, 0x98, 0x4E, 0x5C, 0xCC, 0x2B, 0xF3, 0x27,
 0x19, 0x08, 0x4E, 0xA3, 0x65, 0xA0, 0x2A, 0x70, 0x66, 0x54, 0x86, 0x79, 0x71, 0x9F, 0xAD, 0x2B,
 0x7E, 0x46, 0xA6, 0x25, 0x26, 0x2C, 0x2D, 0x17, 0xD5, 0x15, 0x50, 0xF8, 0x9B, 0xDA, 0x9E, 0x2F,
 0x5A, 0x72, 0xBB, 0xD5, 0x9C, 0x5B, 0x7D, 0x94, 0x51, 0xF8, 0x60, 0x11, 0x44, 0xCC, 0x72, 0xB4,
 0x2D, 0xEE, 0x46, 0x87, 0xD8, 0xC3, 0xB8, 0x0E, 0x45, 0xC1, 0xCF, 0x9A, 0x27, 0x2F, 0xCC, 0x93,
 0x3F, 0x75, 0xCF, 0x85, 0xA3, 0x28, 0x5F, 0x5B, 0x1C, 0xD3, 0x1E, 0x02, 0x6B, 0x77, 0xED, 0xA5,
 0x0F, 0x03, 0x45, 0x7A, 0x70, 0x99, 0x80, 0x7E, 0x0C, 0xE3, 0xB7, 0xE4, 0x9E, 0xA8, 0x27, 0x99,
 0xEA, 0xB2, 0x75, 0x8E, 0x0A, 0xD3, 0xBD, 0x3F, 0xB1, 0x55, 0x9E, 0xB9, 0x84, 0x81, 0x74, 0xD9,
 0x2C, 0x79, 0xB3, 0x58, 0x07, 0x0E, 0x4B, 0xC4, 0x90, 0xD8, 0x00, 0xC6, 0x9B, 0xBB, 0x92, 0x26,
 0xAA, 0x31, 0x68, 0xE1, 0x37, 0x00, 0x8A, 0xDF, 0x72, 0x9C, 0x35, 0x38, 0xAD, 0x30, 0xB9, 0xE2,
 0x11, 0x64, 0xA5, 0xA6, 0x44, 0x62, 0x37, 0x88, 0x86, 0x06, 0xBE, 0xF6, 0xCC, 0x50, 0xDB, 0x0E,
 0x9F, 0x9B, 0x6B, 0x1E, 0x4F, 0x2A, 0x95, 0x25, 0xB1, 0xBC, 0x2A, 0xEC, 0x22, 0x87, 0x15, 0x73,
 0x5D, 0x5F, 0x07, 0x7D, 0xAF, 0x52, 0xCA, 0x33, 0x12, 0xE9, 0x54, 0xF4, 0x20, 0xB1, 0x21, 0x69,
 0x90, 0xEF, 0x1D, 0x80, 0x48, 0x4E, 0xA9, 0xA7, 0xEB, 0x98, 0x59, 0x7A, 0x01, 0x25, 0x49, 0x4F,
 0xD6, 0xAC, 0x32, 0x68, 0xAD, 0x60, 0xE0, 0xF7, 0x7C, 0x0D, 0x7F, 0x1C, 0x3A, 0xB7, 0x52, 0x70,
 0x33, 0x69, 0x65, 0x10, 0x74, 0x84, 0x2C, 0x2D, 0xF5, 0x86, 0x7C, 0xA0, 0xB4, 0xE5, 0x65, 0x99,
 0xD6, 0x82, 0x8A, 0x85, 0x27, 0x77, 0x23, 0x60, 0xA4, 0x34, 0x48, 0x60, 0x90, 0xA8, 0x87, 0x8C,
 0x10, 0x1F, 0x46, 0x4A, 0x24, 0x06, 0x24, 0xA6, 0x48, 0x50, 0xA1, 0x42, 0x88, 0x54, 0xE6, 0x92,
 0xEF, 0x54, 0x50, 0x94, 0x91, 0x9A, 0xC5, 0xC3, 0x06, 0xF1, 0xA8, 0x8D, 0xAC, 0x01, 0xFB, 0xB9,
 0x7B, 0xE7, 0x66, 0xBC, 0x21, 0x97, 0x25, 0x98, 0xD9, 0xF4, 0x68, 0x9A, 0x4A, 0x71, 0x51, 0x1D,
 0x67, 0xE0, 0xA3, 0x86, 0x0E, 0xCB, 0x1A, 0x21, 0xB4, 0xF0, 0x20, 0x54, 0x0C, 0x10, 0xFA, 0x13,
 0x1A, 0xE6, 0x14, 0x81, 0x4D, 0x20, 0x11, 0x24, 0xFD, 0x4B, 0x6A, 0xB8, 0x27, 0x33, 0x48, 0xC6,
 0xC7, 0x6E, 0xAB, 0xD1, 0xB4, 0x9E, 0x6E, 0x3B, 0x48, 0x69, 0x2F, 0x1A, 0x89, 0x3E, 0x19, 0xA6,
 0x06, 0x24, 0x00, 0x6B, 0x66, 0x00, 0xA9, 0x07, 0x81, 0xD7, 0xD8, 0xCA, 0xCF, 0x3B, 0x81, 0xCC,
 0x2E, 0xC0, 0xEC, 0xAE, 0xE3, 0xE1, 0xE7, 0xC6, 0x77, 0x8C, 0xD3, 0x7C, 0x25, 0x10, 0x7B, 0x93,
 0x68, 0x7A, 0x99, 0x30, 0x2E, 0xCE, 0x64, 0x19, 0x6A, 0x6C, 0xB4, 0xE4, 0xF5, 0xA9, 0x47, 0x12,
 0x79, 0x3F, 0xC5, 0xEB, 0xC9, 0x0C, 0xE3, 0xBA, 0x53, 0x79, 0x43, 0xB1, 0x86, 0x70, 0x21, 0x90,
 0x66, 0x38, 0xB3, 0x29, 0x54, 0xB0, 0xFA, 0xA1, 0x48, 0x82, 0x7A, 0x4F, 0xB7, 0x42, 0xE2, 0x41,
 0x47, 0xCD, 0x81, 0xFE, 0xDC, 0x42, 0xEC, 0x70, 0xCA, 0xA0, 0xE6, 0x43, 0xAE, 0x40, 0x91, 0x71,
 0x65, 0x33, 0x66, 0x4D, 0x87, 0x1C, 0x16, 0x30, 0x0C, 0xFC, 0xD5, 0xBF, 0xE0, 0xC1, 0xA3, 0x03,
 0xB1, 0xEA, 0x07, 0x7C, 0x64, 0xDC, 0x8F, 0xBE, 0xC7, 0xC7, 0xA7, 0x15, 0x3E, 0x3E, 0xAD, 0xE3,
 0x83, 0x56, 0x95, 0x07, 0x9D, 0x01, 0x6C, 0x7B, 0x46, 0x38, 0x19, 0xD3, 0x04, 0x06, 0xF0, 0x10,
 0x54, 0xC9, 0x4F, 0x71, 0x96, 0xD0, 0xEF, 0x73, 0xD6, 0x9B, 0xB0, 0x91, 0x78, 0xC2, 0x5F, 0x31,
 0xFA, 0x5F, 0x70, 0x89, 0x07, 0xAE, 0xE7, 0x32, 0xCF, 0x4D, 0x2B, 0x01, 0xE5, 0xFB, 0x6F, 0x25,
 0xD2, 0x8F, 0x5C, 0x80, 0x97, 0x8A, 0x83, 0xFC, 0xBC, 0xA5, 0x07, 0xE0, 0x8D, 0xC0, 0x4F, 0xA9,
 0xA8, 0xE3, 0x5D, 0x48, 0xE5, 0xDF, 0x01, 0x43, 0x86, 0x02, 0x3E, 0xEA, 0xCE, 0xE6, 0x96, 0x70,
 0x0D, 0x50, 0x8C, 0x1F, 0x4D, 0x81, 0x55, 0x4F, 0x26, 0xB8, 0xF6, 0x04, 0x22, 0x21, 0x88, 0x04,
 0x47, 0x42, 0x3C, 0x6D, 0x7C, 0x3E, 0xD8, 0xBC, 0xA9, 0x41, 0x1C, 0x72, 0xE1, 0xC7, 0x74, 0xA1,
 0xB1, 0x79, 0xF3, 0x6F, 0xB3, 0x31, 0x66, 0xD6, 0xB2, 0x22, 0xB5, 0x64, 0xB0, 0xA7, 0x9F, 0xF9,
 0x8D, 0x4B, 0x40, 0xEA, 0x4A, 0xC0, 0x2B, 0xD0, 0x0C, 0xAC, 0x0D, 0x85, 0x85, 0x1F, 0xFC, 0x3F,
 0x16, 0xE0, 0x47, 0x7A, 0x1E, 0x38, 0xF7, 0x9A, 0x87, 0x71, 0xBD, 0xF8, 0x26, 0xA5, 0x5B, 0xA5,
 0x07, 0x2B, 0x1D, 0x3F, 0x14, 0xE9, 0x58, 0x65, 0x89, 0x12, 0x94, 0xA8, 0x6D, 0x01, 0x35, 0x54,
 0xA3, 0x0C, 0x51, 0x18, 0x89, 0x17, 0xC5, 0x81, 0x22, 0x9B, 0x73, 0x34, 0x5B, 0x3A, 0x02, 0x0F,
 0xF4, 0xF5, 0x45, 0xEC, 0xFC, 0xE3, 0xEC, 0xDD, 0x89, 0x10, 0xF1, 0x95, 0xC2, 0x44, 0xD8, 0xAB,
 0x3A, 0xB0, 0xBC, 0x3C, 0x73, 0x26, 0x92, 0xC7, 0x22, 0xD5, 0xC1, 0xC0, 0xA0, 0x1C, 0xFA, 0x8F,
 0x8B, 0xE1, 0x2D, 0xE0, 0xAC, 0xA1, 0x9F, 0xA5, 0x10, 0xB0, 0xB6, 0x6C, 0x5C, 0xDE, 0xEF, 0x5F,
 0xDA, 0xBB, 0x76, 0x13, 0xF2, 0x02, 0xD0, 0x2A, 0x84, 0x65, 0xB8, 0xF7, 0xF9, 0x4F, 0x2D, 0xDE,
 0xFE, 0xB9, 0xC5, 0x0C, 0x50, 0x2B, 0x05, 0x58, 0x2A, 0xD6, 0x57, 0xD7, 0x4E, 0x92, 0x68, 0x2A,
 0x97, 0x1D, 0x27, 0x09, 0x5E, 0x4A, 0x1F, 0x32, 0x14, 0x6D, 0x08, 0x83, 0x29, 0x85, 0x02, 0x2D,
 0xA2, 0xA9, 0xC6, 0x23, 0xA1, 0xA5, 0x59, 0x1C, 0x43, 0xE1, 0xB2, 0xA2, 0x0F, 0x5B, 0x2F, 0x5E,
 0x5F, 0xDE, 0x67, 0x34, 0xA3, 0x7E, 0x3E, 0x4C, 0x93, 0x8A, 0x5E, 0x30, 0x83, 0xFA, 0x82, 0x74,
 0xF7, 0xF3, 0x4D, 0x9E, 0x4F, 0x65, 0x9C, 0x23, 0x8A, 0x6E, 0xB4, 0x54, 0x1F, 0xA4, 0x9B, 0xC0,
 0xAE, 0x2E, 0xCF, 0x82, 0x60, 0xDE, 0x5E, 0xD9, 0x0B, 0x0A, 0xAF, 0x48, 0x44, 0xF2, 0xE9, 0x7B,
 0xF6, 0x67, 0x1E, 0x9C, 0x2A, 0x2E, 0x08, 0x29, 0x4F, 0x75, 0xD7, 0xA6, 0xB5, 0x61, 0x6C, 0x50,
 0x8D, 0xF1, 0x54, 0x10, 0xEE, 0xE1, 0x35, 0x2A, 0x5D, 0x98, 0x45, 0x2E, 0x85, 0xD3, 0xDB, 0xE8,
 0x6B, 0xB9, 0x2D, 0x7D, 0x23, 0x9E, 0x4A, 0xC9, 0xB8, 0xAB, 0xEB, 0x98, 0x55, 0x51, 0xCC, 0x4F,
 0x49, 0x98, 0x96, 0xB7, 0x2D, 0x32, 0x03, 0x93, 0xBB, 0x05, 0xB9, 0x4D, 0x83, 0x14, 0x8E, 0x5E,
 0x3F, 0x3F, 0x67, 0xA3, 0x28, 0xE7, 0x08, 0xD0, 0xB4, 0x62, 0x9E, 0xC9, 0x6B, 0x70, 0x12, 0xC6,
 0xB9, 0x03, 0x19, 0x74, 0xA5, 0x01, 0x87, 0x54, 0x4C, 0x22, 0xFF, 0x40, 0x3F, 0xD0, 0x1D, 0x1D,
 0xFE, 0xDD, 0x84, 0x9C, 0xA3, 0xE6, 0x52, 0x28, 0x52, 0x7D, 0x3A, 0xB8, 0x7A, 0x03, 0xF0, 0x14,
 0x43, 0x6A, 0xC0, 0x05, 0x24, 0xCD, 0x35, 0x1D, 0x9F, 0x5E, 0x9F, 0x52, 0x8A, 0xED, 0x3F, 0x93,
 0x1B, 0xB3, 0x5D, 0x55, 0x36, 0xDC, 0x79, 0xF5, 0x3A, 0x2B, 0x97, 0x01, 0xB5, 0x30, 0x22, 0xD6,
 0x63, 0x8A, 0x1F, 0xE1, 0x9E, 0xBC, 0x64, 0x63, 0x86, 0xB4, 0x9A, 0xD7, 0x9B, 0xB3, 0x1D, 0xE4,
 0x59, 0xAE, 0xEA, 0xE1, 0x2A, 0x70, 0x97, 0xEF, 0x29, 0x59, 0xA5, 0x35, 0xDC, 0xF6, 0x48, 0x10,
 0xE0, 0x57, 0x53, 0x03, 0x0B, 0x6A, 0x22, 0xB2, 0xD4, 0xC2, 0x4D, 0x52, 0x10, 0x20, 0xA5, 0x7D,
 0x80, 0x39, 0xD3, 0x92, 0x69, 0x86, 0xB2, 0xA1, 0xBC, 0xFE, 0xC5, 0x9C, 0xA3, 0x64, 0x46, 0xE8,
 0xCE, 0x79, 0x6F, 0x73, 0x53, 0xD8, 0x85, 0x99, 0x18, 0xC5, 0xA2, 0x14, 0x01, 0x1C, 0x8A, 0x7D,
 0x28, 0x2D, 0x8C, 0xB2, 0x90, 0x98, 0xAB, 0x3D, 0xD1, 0xB6, 0x51, 0x55, 0x03, 0x64, 0x7C, 0x46,
 0x41, 0x03, 0xCE, 0xB2, 0x24, 0x00, 0xD4, 0xC5, 0x18, 0x5D, 0x99, 0x96, 0x62, 0x5E, 0x68, 0x42,
 0x05, 0xF6, 0xA3, 0xC5, 0x72, 0x29, 0x2F, 0x5B, 0x45, 0x4F, 0x24, 0x8A, 0xEF, 0xEA, 0x7E, 0x22,
 0xBF, 0x95, 0x13, 0xAA, 0x90, 0xEF, 0x10, 0x5F, 0x26, 0xB8, 0xA8, 0xA3, 0x27, 0x40, 0x4A, 0x06,
 0xA9, 0x68, 0xC0, 0x14, 0x2C, 0x37, 0x1E, 0xEA, 0xD3, 0xE9, 0xB4, 0x8E, 0x1F, 0x4D, 0xEB, 0x70,
 0x82, 0xB2, 0x02, 0x5F, 0x5F, 0xC7, 0x21, 0x47, 0x15, 0x58, 0xF8, 0x6E, 0xE1, 0xAC, 0xBA, 0xE8,
 0x42, 0x7F, 0x2B, 0xDE, 0xD4, 0xAA, 0xEE, 0xB3, 0xC2, 0xE7, 0xF2, 0xB6, 0xF7, 0x76, 0x56, 0x48,
 0x64, 0x88, 0x9F, 0x47, 0x21, 0xD2, 0x40, 0x18, 0x76, 0xCA, 0x85, 0xAC, 0x0A, 0x0A, 0x4B, 0x5C,
 0xB0, 0xE3, 0x2C, 0x9D, 0x18, 0x33, 0x60, 0xDD, 0x11, 0x96, 0xD2, 0x95, 0x43, 0x2D, 0x65, 0xB7,
 0x0E, 0xB7, 0x0A, 0xFB, 0x70, 0x30, 0x82, 0x94, 0x79, 0xFB, 0xEB, 0x2F, 0xD9, 0x5B, 0xDE, 0xF6,
 0x72, 0xC7, 0xE2, 0xC2, 0xE7, 0xF9, 0x53, 0x6B, 0x9E, 0xD3, 0x4A, 0xA3, 0x5F, 0xC1, 0x97, 0xBD,
 0x46, 0xFE, 0x3D, 0x39, 0xFF, 0xAE, 0xAC, 0x81, 0xB1, 0x43, 0x21, 0x2A, 0xDC, 0x4C, 0x8C, 0xEA,
 0x2F, 0x34, 0xE6, 0x63, 0x7A, 0x29, 0xBF, 0x2D, 0x34, 0x30, 0xCF, 0xBC, 0x4D, 0xF7, 0x57, 0x57,
 0xEC, 0x2F, 0x8A, 0x2E, 0xCC, 0x6D, 0xF3, 0x5C, 0x54, 0x61, 0x8D, 0x9A, 0xE0, 0x7E, 0xE3, 0x1B,
 0xB3, 0x9E, 0x97, 0x4D, 0x66, 0x5B, 0x35, 0xD4, 0x17, 0x15, 0x54, 0x5E, 0xEA, 0x34, 0x1A, 0x9E,
 0xCF, 0x6F, 0x53, 0xC8, 0xD6, 0xA3, 0xCC, 0x1F, 0x05, 0x24, 0xA1, 0x98, 0xD7, 0x34, 0xC8, 0x2D,
 0x79, 0x68, 0x04, 0x6C, 0x98, 0x22, 0x33, 0x8D, 0x96, 0xBD, 0x65, 0xEF, 0xE6, 0x6C, 0xE9, 0x56,
 0xBE, 0x09, 0x49, 0x1F, 0xB9, 0x87, 0xD8, 0xBA, 0x38, 0x75, 0x02, 0x97, 0x54, 0xFD, 0xEC, 0x28,
 0x67, 0x9A, 0xF3, 0xA5, 0x24, 0xF8, 0x96, 0x07, 0x79, 0x80, 0xFC, 0x86, 0x53, 0x4E, 0x07, 0xF6,
 0xF7, 0xA0, 0x6A, 0x46, 0x25, 0x28, 0x2F, 0xD6, 0x64, 0xD1, 0x9C, 0x77, 0x40, 0x11, 0x40, 0x5C,
 0xCC, 0x28, 0x42, 0xF3, 0xCA, 0x30, 0xC6, 0xE6, 0x95, 0x21, 0x15, 0xF8, 0x57, 0x06, 0xF3, 0xF2,
 0x27, 0xFF, 0x36, 0x53, 0xFE, 0xFF, 0x07, 0x8A, 0x89, 0x4C, 0x7E, 0x78, 0xC2, 0xB9, 0xD5, 0x4F,
 0x51, 0xEB, 0x97, 0xA8, 0xD9, 0xFB, 0xFF, 0x0B, 0x0D, 0xD7, 0xDE, 0xAA, 0x1B, 0x29, 0x00, 0x00
};

static bool matchWild(const char *pattern, const char *testee) {
  const char *nxPat = NULL, *nxTst = NULL;

  while (*testee) {
    if (( *pattern == '?' ) || (*pattern == *testee)){
      pattern++;testee++;
      continue;
    }
    if (*pattern=='*'){
      nxPat=pattern++; nxTst=testee;
      continue;
    }
    if (nxPat){ 
      pattern = nxPat+1; testee=++nxTst;
      continue;
    }
    return false;
  }
  while (*pattern=='*'){pattern++;}  
  return (*pattern == 0);
}

#define SPIFFS_MAXLENGTH_FILEPATH 64

static bool isExcluded(const char *filename) {
  const char *excludeList = EXCLUDELIST;
  static char linebuf[SPIFFS_MAXLENGTH_FILEPATH]; 
  fs::File excludeFile=SPIFFS.open(excludeList, "r");
  if(!excludeFile){
    excludeFile=SPIFFS.open(excludeList, "w");
    excludeFile.println("/*.js.gz");
    excludeFile.println(excludeList);
    excludeFile.close();
    excludeFile=SPIFFS.open(excludeList, "r");
  }
  if (excludeFile.size() > 0){
    uint8_t idx;
    bool isOverflowed = false;
    while (excludeFile.available()){
      linebuf[0] = '\0';
      idx = 0;
      int lastChar;
      do {
        lastChar = excludeFile.read();
        if(lastChar != '\r'){
          linebuf[idx++] = (char) lastChar;
        }
      } while ((lastChar >= 0) && (lastChar != '\n') && (idx < SPIFFS_MAXLENGTH_FILEPATH));

      if(isOverflowed){
        isOverflowed = (lastChar != '\n');
        continue;
      }
      isOverflowed = (idx >= SPIFFS_MAXLENGTH_FILEPATH);
      linebuf[idx-1] = '\0';

      if (matchWild(linebuf, filename)){
        excludeFile.close();
        return true;
      }
    }
  }
  excludeFile.close();
  return false;
}

// WEB HANDLER IMPLEMENTATION

SPIFFSEditor::SPIFFSEditor(const String& username, const String& password)
:_username(username)
,_password(password)
,_authenticated(false)
,_startTime(0)
{}

bool SPIFFSEditor::canHandle(AsyncWebServerRequest *request){
  if(request->url().equalsIgnoreCase("/edit")){
    if(request->method() == HTTP_GET){
      if(request->hasParam("list"))
        return true;
      if(request->hasParam("edit")){
        request->_tempFile = SPIFFS.open(request->arg("edit"), "r");
        if(!request->_tempFile)
          return false;
      }
      if(request->hasParam("download")){
        request->_tempFile = SPIFFS.open(request->arg("download"), "r");
        if(!request->_tempFile)
          return false;
      }
      return true;
    }
    else if(request->method() == HTTP_POST)
      return true;
    else if(request->method() == HTTP_DELETE)
      return true;
    else if(request->method() == HTTP_PUT)
      return true;

  }
  return false;
}


void SPIFFSEditor::handleRequest(AsyncWebServerRequest *request){
  if(_username.length() && _password.length() && !request->authenticate(_username.c_str(), _password.c_str()))
    return request->requestAuthentication();

  if(request->method() == HTTP_GET){
    if(request->hasParam("list")){
      String path = request->getParam("list")->value();
      Dir dir = SPIFFS.openDir(path);
      path = String();
      String output = "[";
      while(dir.next()){
        fs::File entry = dir.openFile("r");
        if (isExcluded(entry.name())) { continue; }
        if (output != "[") output += ',';
        output += "{\"type\":\"";
        output += "file";
        output += "\",\"name\":\"";
        output += String(entry.name());
        output += "\",\"size\":";
        output += String(entry.size());
        output += "}";
        entry.close();
      }
      output += "]";
      request->send(200, "text/json", output);
      output = String();
    }
    else if(request->hasParam("edit") || request->hasParam("download")){
      request->send(request->_tempFile, request->_tempFile.name(), String(), request->hasParam("download"));
    }
    else {
      AsyncWebServerResponse *response = request->beginResponse_P(200, "text/html", edit_htm_gz, edit_htm_gz_len);
      response->addHeader("Content-Encoding", "gzip");
      request->send(response);
    }
  } else if(request->method() == HTTP_DELETE){
    if(request->hasParam("path", true)){
      SPIFFS.remove(request->getParam("path", true)->value());
      request->send(200, "", "DELETE: "+request->getParam("path", true)->value());
    } else
      request->send(404);
  } else if(request->method() == HTTP_POST){
    if(request->hasParam("data", true, true) && SPIFFS.exists(request->getParam("data", true, true)->value()))
      request->send(200, "", "UPLOADED: "+request->getParam("data", true, true)->value());
    else
      request->send(500);
  } else if(request->method() == HTTP_PUT){
    if(request->hasParam("path", true)){
      String filename = request->getParam("path", true)->value();
      if(SPIFFS.exists(filename)){
        request->send(200);
      } else {
        fs::File f = SPIFFS.open(filename, "w");
        if(f){
          f.write((uint8_t)0x00);
          f.close();
          request->send(200, "", "CREATE: "+filename);
        } else {
          request->send(500);
        }
      }
    } else
      request->send(400);
  }
}

void SPIFFSEditor::handleUpload(AsyncWebServerRequest *request, const String& filename, size_t index, uint8_t *data, size_t len, bool final){
  if(!index){
    if(!_username.length() || request->authenticate(_username.c_str(),_password.c_str())){
      _authenticated = true;
      request->_tempFile = SPIFFS.open(filename, "w");
      _startTime = millis();
    }
  }
  if(_authenticated && request->_tempFile){
    if(len){
      request->_tempFile.write(data,len);
    }
    if(final){
      request->_tempFile.close();
    }
  }
}