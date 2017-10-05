#ifndef AIRSYNTH_8192_H_
#define AIRSYNTH_8192_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define AIRSYNTH_8192_NUM_CELLS 6546
#define AIRSYNTH_8192_SAMPLERATE 8192
 
const int8_t __attribute__((section(".progmem.data"))) AIRSYNTH_8192_DATA [] =
{0, 0, -1, -1, 0, 0, -1, -1, 0, -1, -3, -3, 0, 2, 3, 3, 5, 9, 12, 13, 14, 18,
21, 21, 20, 19, 19, 17, 14, 12, 12, 10, 7, 4, 3, 3, 1, -2, -6, -9, -11, -13,
-17, -22, -27, -32, -35, -36, -38, -39, -37, -32, -28, -26, -24, -21, -17, -13,
-9, -4, 1, 5, 7, 9, 10, 9, 7, 6, 7, 7, 5, 3, 5, 8, 9, 8, 8, 11, 14, 13, 10, 8,
9, 10, 12, 14, 18, 21, 25, 28, 32, 35, 37, 40, 43, 46, 48, 50, 52, 52, 50, 47,
45, 42, 39, 34, 28, 22, 16, 9, 3, -1, -4, -7, -11, -16, -20, -26, -33, -41, -47,
-52, -55, -58, -60, -60, -56, -53, -51, -50, -47, -42, -37, -31, -26, -20, -15,
-12, -11, -10, -8, -6, -6, -5, -4, -3, -4, -4, -2, 0, 0, -2, -1, 3, 5, 2, -1, 1,
5, 7, 5, 4, 9, 15, 17, 17, 18, 22, 28, 33, 36, 37, 37, 38, 38, 35, 30, 25, 21,
18, 14, 8, 3, 1, -1, -4, -7, -11, -15, -20, -24, -26, -26, -27, -31, -35, -37,
-36, -34, -34, -33, -30, -25, -21, -17, -13, -7, -2, 1, 3, 7, 12, 16, 16, 14,
13, 14, 14, 12, 12, 14, 17, 19, 20, 21, 24, 27, 27, 26, 28, 32, 34, 32, 29, 28,
30, 32, 34, 36, 38, 41, 43, 45, 47, 48, 47, 45, 42, 41, 40, 37, 33, 27, 20, 12,
5, 1, 0, -2, -7, -13, -19, -22, -25, -28, -31, -33, -35, -38, -42, -44, -44,
-44, -44, -44, -41, -37, -32, -26, -19, -11, -7, -8, -9, -8, -4, 0, 1, 1, 0, -2,
-4, -4, -3, -2, -3, -2, 0, 1, 2, 1, 1, 1, 1, -1, -1, 0, -2, -4, -5, -2, 3, 7, 9,
12, 16, 17, 16, 14, 14, 15, 15, 12, 9, 6, 3, -2, -7, -12, -15, -16, -18, -19,
-20, -20, -21, -22, -25, -29, -32, -35, -38, -40, -40, -39, -36, -33, -29, -22,
-15, -9, -7, -4, 0, 5, 8, 8, 8, 10, 14, 17, 18, 18, 18, 19, 22, 23, 23, 23, 25,
28, 31, 32, 32, 32, 32, 30, 27, 25, 25, 28, 32, 35, 38, 41, 44, 46, 47, 46, 46,
46, 46, 45, 41, 35, 28, 21, 15, 10, 6, 1, -2, -4, -7, -9, -13, -19, -25, -31,
-36, -40, -45, -49, -52, -53, -51, -49, -48, -46, -41, -35, -28, -24, -22, -18,
-12, -4, 2, 3, 3, 5, 8, 9, 5, 1, 2, 5, 7, 8, 11, 16, 17, 14, 8, 5, 2, -2, -8,
-11, -11, -11, -13, -13, -9, -4, -1, 1, 4, 7, 8, 9, 12, 16, 17, 16, 13, 12, 10,
5, 0, -2, -2, -4, -7, -9, -10, -11, -16, -20, -23, -26, -31, -36, -41, -42, -42,
-42, -41, -39, -35, -31, -25, -19, -13, -8, 0, 8, 15, 19, 23, 26, 29, 28, 27,
28, 31, 34, 34, 34, 36, 39, 40, 39, 37, 35, 32, 27, 21, 17, 18, 20, 21, 21, 22,
25, 28, 30, 32, 36, 39, 41, 42, 45, 47, 46, 41, 36, 33, 32, 27, 22, 17, 15, 14,
11, 5, -1, -7, -13, -17, -22, -29, -38, -45, -50, -52, -54, -54, -49, -42, -38,
-38, -37, -29, -18, -10, -6, -4, 0, 4, 7, 7, 7, 8, 8, 8, 9, 10, 12, 12, 9, 5, 1,
-2, -6, -12, -19, -24, -28, -28, -28, -27, -26, -24, -20, -16, -11, -5, 1, 6, 9,
11, 14, 18, 19, 18, 16, 14, 14, 13, 10, 8, 7, 6, 5, 2, -2, -8, -15, -21, -26,
-31, -37, -40, -42, -43, -44, -44, -42, -37, -31, -24, -17, -9, -4, -1, 1, 6,
12, 19, 25, 28, 28, 28, 28, 31, 34, 35, 36, 39, 43, 43, 37, 29, 23, 21, 19, 16,
12, 11, 10, 10, 12, 17, 23, 27, 28, 32, 37, 43, 46, 48, 50, 50, 48, 45, 43, 42,
41, 38, 34, 30, 29, 26, 21, 13, 5, -3, -10, -17, -26, -34, -40, -45, -49, -52,
-53, -53, -51, -48, -44, -39, -33, -25, -17, -11, -7, -5, -3, 0, 2, 2, 3, 4, 5,
5, 4, 4, 4, 1, -5, -10, -14, -19, -26, -34, -40, -42, -42, -44, -43, -41, -37,
-33, -29, -22, -13, -5, 2, 8, 14, 17, 18, 19, 21, 22, 21, 22, 23, 24, 23, 23,
23, 22, 18, 11, 5, -1, -8, -16, -24, -29, -33, -38, -42, -43, -42, -41, -38,
-32, -24, -18, -15, -10, -3, 4, 9, 11, 14, 16, 16, 15, 15, 18, 21, 24, 26, 27,
27, 24, 19, 15, 10, 7, 3, -1, -4, -7, -8, -7, -4, 1, 7, 12, 18, 24, 30, 36, 41,
44, 46, 47, 46, 44, 43, 42, 41, 39, 37, 38, 39, 38, 34, 27, 21, 15, 10, 5, -1,
-7, -15, -21, -26, -28, -29, -29, -26, -21, -17, -12, -8, -3, 1, 4, 5, 5, 5, 5,
5, 6, 7, 7, 7, 5, 3, 2, 1, 0, -2, -8, -17, -25, -31, -36, -40, -45, -49, -50,
-47, -43, -38, -34, -29, -22, -13, -6, 0, 5, 10, 15, 16, 14, 12, 13, 14, 14, 12,
12, 14, 15, 12, 9, 7, 5, -1, -9, -18, -26, -33, -40, -46, -47, -46, -44, -44,
-41, -35, -28, -22, -17, -11, -3, 3, 6, 7, 8, 10, 13, 16, 17, 19, 21, 23, 24,
25, 24, 23, 21, 17, 15, 12, 9, 5, 0, -4, -7, -10, -9, -4, 4, 12, 19, 27, 35, 43,
47, 48, 49, 50, 49, 47, 44, 44, 46, 46, 45, 41, 37, 36, 35, 34, 30, 25, 18, 10,
1, -10, -17, -22, -25, -29, -33, -33, -29, -24, -19, -15, -10, -4, 0, 5, 10, 14,
14, 12, 11, 12, 12, 10, 8, 8, 9, 9, 6, 3, -1, -6, -11, -17, -23, -31, -40, -46,
-48, -47, -47, -48, -45, -38, -29, -21, -14, -9, -5, -1, 4, 9, 11, 12, 12, 12,
12, 10, 9, 11, 12, 12, 10, 9, 8, 5, -2, -9, -16, -22, -30, -38, -43, -44, -44,
-45, -45, -40, -33, -26, -19, -13, -7, -2, 2, 5, 8, 10, 11, 12, 14, 18, 20, 19,
18, 19, 22, 23, 21, 17, 14, 10, 5, -1, -5, -8, -9, -10, -8, -4, 2, 8, 15, 23,
32, 41, 47, 52, 55, 55, 54, 54, 54, 55, 54, 52, 49, 46, 44, 41, 39, 35, 31, 27,
21, 14, 4, -6, -15, -22, -29, -33, -34, -33, -31, -27, -22, -15, -9, -4, 0, 3,
6, 7, 7, 8, 10, 10, 8, 5, 3, 1, 0, 0, -1, -2, -6, -11, -16, -20, -27, -35, -42,
-47, -51, -53, -53, -51, -47, -40, -32, -22, -13, -6, -1, 3, 8, 12, 13, 12, 12,
14, 15, 16, 16, 15, 14, 12, 10, 8, 7, 3, -1, -6, -11, -16, -25, -35, -43, -47,
-50, -51, -50, -45, -38, -32, -26, -18, -9, -3, 0, 2, 5, 8, 9, 9, 11, 14, 15,
14, 15, 17, 19, 18, 14, 12, 11, 9, 5, 1, -3, -7, -14, -21, -23, -22, -17, -10,
-1, 9, 19, 30, 40, 48, 54, 57, 59, 61, 61, 61, 60, 61, 61, 59, 56, 54, 51, 48,
44, 39, 34, 26, 19, 12, 6, -3, -12, -22, -31, -39, -43, -44, -39, -33, -27, -20,
-12, -4, 0, 1, 4, 7, 8, 7, 6, 7, 9, 9, 6, 3, 1, 0, -2, -4, -8, -13, -19, -24,
-28, -33, -39, -46, -53, -58, -60, -56, -49, -40, -33, -26, -17, -8, -1, 3, 7,
12, 18, 21, 23, 25, 26, 25, 22, 19, 20, 23, 25, 23, 18, 14, 12, 8, 1, -9, -20,
-28, -35, -44, -51, -53, -51, -47, -45, -40, -31, -20, -12, -10, -8, -4, 1, 5,
7, 9, 12, 14, 14, 14, 16, 19, 19, 16, 14, 14, 14, 12, 10, 10, 9, 3, -6, -11,
-11, -9, -9, -8, -1, 11, 20, 26, 32, 41, 49, 53, 55, 59, 64, 66, 63, 61, 62, 64,
63, 59, 56, 55, 53, 48, 43, 37, 32, 25, 17, 6, -5, -15, -22, -28, -32, -36, -39,
-39, -35, -29, -23, -17, -12, -9, -7, -6, -6, -8, -8, -6, -3, 0, -1, -2, -5, -8,
-10, -11, -12, -13, -16, -20, -25, -29, -35, -42, -47, -49, -50, -49, -47, -42,
-35, -28, -19, -11, -4, 3, 10, 16, 21, 23, 24, 27, 30, 32, 32, 30, 30, 30, 30,
28, 27, 26, 24, 18, 10, 1, -7, -17, -26, -35, -42, -47, -50, -51, -50, -47, -43,
-39, -35, -31, -27, -22, -19, -17, -14, -10, -3, 1, 2, 1, 2, 5, 8, 8, 9, 10, 13,
14, 12, 9, 6, 3, -1, -6, -8, -6, -2, 1, 4, 8, 15, 25, 34, 41, 46, 52, 57, 59,
59, 59, 62, 66, 69, 70, 69, 68, 66, 62, 57, 54, 53, 52, 48, 41, 33, 23, 10, -2,
-12, -19, -24, -29, -33, -33, -32, -31, -30, -30, -28, -25, -24, -24, -24, -23,
-23, -23, -22, -20, -19, -19, -18, -16, -15, -15, -18, -20, -20, -21, -23, -27,
-31, -35, -39, -42, -43, -44, -44, -42, -36, -28, -20, -13, -6, -1, 2, 3, 5, 8,
13, 18, 21, 25, 26, 25, 22, 21, 22, 23, 23, 23, 23, 19, 12, 3, -4, -12, -21,
-31, -37, -41, -43, -45, -45, -42, -38, -36, -35, -33, -29, -25, -22, -21, -20,
-18, -15, -10, -4, 2, 5, 6, 7, 9, 12, 15, 19, 22, 22, 21, 20, 18, 15, 12, 9, 9,
10, 14, 19, 25, 32, 37, 41, 45, 50, 55, 60, 63, 63, 62, 62, 63, 65, 66, 66, 65,
63, 61, 59, 59, 58, 53, 46, 39, 34, 28, 20, 10, 0, -10, -18, -24, -27, -29, -31,
-33, -34, -33, -32, -31, -31, -31, -33, -35, -36, -35, -33, -31, -31, -31, -30,
-28, -26, -24, -21, -19, -18, -20, -23, -26, -28, -33, -39, -44, -45, -44, -42,
-40, -37, -31, -24, -19, -15, -11, -6, -1, 2, 5, 9, 12, 13, 14, 16, 19, 20, 18,
18, 21, 24, 21, 16, 14, 13, 10, 3, -6, -13, -20, -29, -38, -43, -44, -43, -42,
-39, -33, -28, -28, -29, -29, -27, -24, -21, -20, -20, -19, -15, -10, -6, -4,
-2, 3, 9, 14, 16, 19, 24, 28, 30, 28, 26, 25, 22, 19, 18, 19, 24, 30, 36, 43,
49, 55, 61, 66, 71, 75, 76, 75, 74, 73, 75, 77, 78, 77, 75, 74, 71, 66, 62, 61,
60, 55, 45, 34, 26, 17, 6, -7, -18, -26, -31, -34, -35, -33, -32, -31, -30, -30,
-29, -29, -30, -33, -38, -42, -43, -40, -38, -38, -39, -37, -33, -31, -30, -30,
-27, -24, -24, -28, -33, -38, -42, -46, -48, -49, -49, -48, -44, -38, -30, -22,
-15, -9, -5, -1, 3, 7, 9, 10, 10, 11, 11, 12, 13, 14, 17, 19, 20, 20, 20, 21,
22, 20, 13, 1, -11, -20, -27, -33, -40, -45, -47, -46, -44, -40, -35, -31, -30,
-29, -26, -22, -20, -20, -19, -17, -14, -13, -11, -8, -2, 5, 11, 16, 19, 23, 26,
28, 28, 27, 24, 21, 19, 16, 13, 12, 14, 17, 23, 32, 42, 50, 55, 59, 64, 68, 70,
70, 70, 71, 73, 74, 74, 73, 72, 72, 72, 71, 70, 66, 63, 61, 56, 48, 37, 26, 16,
5, -7, -19, -26, -29, -31, -33, -34, -33, -30, -27, -28, -31, -34, -35, -36,
-39, -41, -42, -41, -40, -40, -38, -34, -30, -28, -27, -26, -24, -24, -27, -31,
-35, -40, -45, -50, -53, -54, -54, -53, -49, -42, -33, -24, -17, -11, -8, -5,
-2, 0, 1, 3, 5, 7, 7, 6, 7, 10, 14, 16, 17, 19, 21, 20, 16, 10, 5, 0, -8, -17,
-26, -34, -42, -47, -47, -43, -38, -36, -35, -31, -26, -22, -20, -20, -19, -17,
-15, -13, -11, -9, -6, -1, 5, 12, 19, 25, 30, 34, 36, 35, 34, 31, 28, 25, 23,
20, 18, 15, 16, 20, 26, 33, 39, 46, 54, 60, 64, 66, 66, 66, 66, 67, 70, 73, 75,
76, 75, 73, 72, 70, 70, 69, 68, 64, 57, 47, 36, 24, 12, 1, -8, -15, -22, -28,
-33, -35, -35, -33, -29, -26, -26, -28, -31, -35, -38, -41, -42, -41, -38, -36,
-33, -29, -26, -23, -22, -21, -19, -17, -17, -20, -28, -36, -42, -46, -49, -53,
-55, -54, -51, -49, -46, -40, -31, -23, -19, -15, -9, -6, -6, -8, -8, -3, 1, 3,
3, 6, 10, 14, 16, 18, 19, 19, 16, 12, 9, 4, -4, -13, -20, -27, -35, -41, -44,
-43, -42, -42, -42, -39, -35, -31, -27, -24, -22, -23, -24, -22, -19, -15, -11,
-6, 1, 8, 16, 25, 34, 41, 45, 48, 50, 50, 47, 41, 37, 35, 34, 33, 32, 32, 34,
35, 37, 40, 45, 50, 57, 64, 68, 69, 68, 67, 68, 69, 68, 68, 70, 72, 73, 72, 70,
68, 66, 63, 59, 53, 45, 34, 21, 10, 2, -6, -15, -24, -29, -32, -33, -35, -38,
-40, -40, -42, -45, -50, -53, -52, -49, -46, -46, -47, -45, -41, -35, -31, -29,
-26, -21, -15, -11, -10, -12, -15, -18, -23, -28, -34, -40, -44, -44, -42, -40,
-37, -33, -28, -26, -25, -26, -25, -22, -18, -15, -12, -9, -7, -4, -1, 3, 7, 10,
14, 18, 20, 19, 17, 14, 10, 5, -3, -11, -19, -26, -34, -40, -43, -42, -40, -40,
-41, -40, -37, -33, -30, -30, -30, -29, -26, -22, -19, -15, -9, -3, 4, 11, 17,
24, 32, 40, 45, 48, 48, 47, 47, 46, 42, 36, 31, 30, 32, 34, 36, 39, 42, 45, 46,
46, 48, 50, 52, 53, 55, 58, 61, 62, 63, 65, 68, 71, 73, 74, 74, 73, 72, 70, 66,
59, 48, 38, 29, 21, 13, 3, -5, -13, -21, -27, -32, -35, -38, -42, -46, -49, -52,
-54, -56, -57, -56, -56, -57, -57, -51, -44, -38, -35, -31, -26, -20, -17, -15,
-13, -12, -15, -20, -24, -25, -26, -30, -33, -33, -31, -31, -31, -31, -29, -30,
-31, -31, -28, -25, -26, -27, -24, -19, -15, -13, -9, -3, 3, 6, 9, 12, 16, 16,
14, 11, 8, 3, -4, -11, -17, -22, -27, -33, -35, -34, -33, -32, -33, -35, -36,
-38, -39, -37, -33, -28, -24, -19, -13, -6, -1, 5, 12, 21, 30, 37, 43, 48, 52,
54, 56, 56, 55, 54, 52, 49, 44, 41, 41, 43, 44, 45, 45, 45, 44, 43, 41, 40, 41,
43, 45, 47, 48, 49, 52, 56, 61, 63, 65, 66, 68, 67, 63, 56, 52, 48, 43, 35, 26,
19, 12, 5, -2, -8, -13, -19, -24, -29, -33, -39, -48, -54, -56, -56, -57, -57,
-56, -53, -50, -48, -45, -40, -33, -28, -24, -19, -13, -9, -7, -9, -12, -13,
-15, -19, -24, -28, -27, -26, -26, -28, -27, -25, -26, -30, -34, -35, -33, -32,
-31, -28, -24, -21, -18, -14, -6, 1, 5, 9, 14, 19, 19, 17, 16, 16, 16, 13, 9, 5,
-1, -7, -13, -15, -15, -18, -24, -29, -31, -33, -35, -37, -39, -40, -40, -39,
-35, -30, -25, -20, -13, -4, 5, 14, 21, 28, 34, 39, 44, 50, 54, 56, 57, 58, 57,
55, 52, 50, 52, 54, 54, 51, 48, 47, 46, 43, 39, 38, 39, 41, 43, 44, 46, 50, 52,
53, 56, 58, 61, 63, 65, 65, 62, 57, 52, 48, 43, 36, 28, 23, 17, 8, -2, -10, -13,
-16, -22, -30, -38, -46, -55, -63, -69, -70, -69, -67, -64, -60, -57, -53, -49,
-44, -38, -34, -29, -25, -20, -17, -13, -10, -10, -11, -13, -13, -13, -17, -22,
-24, -22, -21, -22, -25, -26, -26, -29, -34, -37, -37, -38, -39, -37, -28, -19,
-13, -11, -9, -4, 2, 7, 9, 10, 11, 10, 10, 10, 11, 11, 7, 3, 0, -4, -9, -13,
-16, -18, -22, -28, -32, -34, -37, -42, -48, -51, -48, -44, -39, -33, -24, -15,
-8, -2, 6, 15, 23, 29, 34, 41, 47, 50, 52, 53, 56, 59, 59, 57, 54, 52, 52, 53,
52, 48, 44, 41, 39, 36, 33, 32, 34, 36, 37, 39, 43, 48, 52, 55, 60, 66, 71, 72,
68, 63, 57, 54, 52, 50, 46, 41, 35, 28, 18, 7, -2, -8, -13, -20, -31, -40, -48,
-56, -65, -71, -73, -72, -72, -71, -68, -63, -58, -53, -46, -38, -30, -24, -21,
-18, -16, -13, -11, -9, -8, -8, -8, -9, -11, -13, -16, -18, -19, -21, -23, -27,
-32, -37, -41, -43, -45, -44, -42, -38, -33, -28, -23, -18, -11, -3, 6, 12, 17,
19, 19, 20, 21, 24, 27, 27, 24, 21, 18, 14, 8, 1, -5, -9, -15, -22, -30, -36,
-41, -46, -52, -54, -52, -48, -44, -42, -37, -28, -17, -6, 5, 14, 21, 27, 32,
39, 45, 48, 51, 53, 56, 57, 57, 57, 58, 57, 53, 48, 45, 43, 38, 32, 27, 25, 24,
23, 23, 25, 26, 26, 27, 32, 39, 45, 49, 55, 64, 70, 70, 68, 66, 66, 65, 63, 60,
57, 53, 48, 42, 36, 27, 17, 7, -4, -15, -28, -40, -51, -60, -67, -71, -73, -73,
-74, -75, -74, -72, -67, -61, -51, -41, -33, -28, -22, -15, -10, -7, -6, -3, 0,
-1, -2, -3, -2, -4, -10, -15, -18, -21, -26, -33, -40, -45, -49, -52, -51, -47,
-44, -41, -36, -30, -24, -20, -14, -7, 1, 8, 14, 21, 26, 27, 25, 24, 24, 26, 27,
26, 24, 21, 16, 11, 4, -2, -11, -20, -30, -38, -43, -47, -50, -51, -51, -50,
-48, -44, -38, -31, -24, -18, -9, 3, 15, 26, 32, 38, 44, 51, 56, 58, 61, 63, 65,
64, 62, 60, 55, 50, 46, 43, 37, 30, 23, 19, 18, 16, 16, 17, 21, 24, 26, 30, 36,
41, 45, 49, 55, 63, 66, 66, 66, 68, 68, 65, 61, 57, 54, 48, 41, 34, 25, 13, 0,
-13, -24, -35, -47, -58, -64, -67, -71, -76, -80, -80, -78, -73, -67, -60, -53,
-47, -42, -35, -26, -18, -11, -6, -2, 0, 1, 2, 3, 4, 3, 1, -3, -5, -9, -17, -28,
-38, -45, -50, -53, -55, -54, -53, -51, -49, -45, -39, -33, -29, -25, -20, -13,
-5, 3, 11, 17, 21, 25, 29, 34, 36, 36, 36, 35, 33, 27, 20, 16, 11, 3, -9, -22,
-32, -38, -44, -47, -48, -47, -47, -47, -44, -37, -29, -22, -16, -8, 0, 7, 12,
21, 33, 43, 49, 54, 59, 63, 63, 61, 60, 63, 63, 59, 51, 43, 36, 28, 19, 10, 6,
5, 4, 3, 5, 10, 15, 17, 20, 25, 32, 37, 41, 47, 53, 59, 62, 63, 65, 68, 70, 68,
64, 59, 55, 50, 44, 35, 24, 12, 0, -13, -28, -42, -53, -60, -65, -69, -73, -76,
-76, -72, -68, -66, -63, -58, -51, -42, -34, -26, -17, -10, -3, 1, 6, 10, 14,
16, 17, 17, 17, 14, 7, -2, -11, -18, -27, -37, -45, -51, -54, -58, -62, -64,
-61, -56, -52, -47, -41, -33, -27, -22, -15, -4, 7, 14, 18, 23, 29, 34, 36, 37,
38, 37, 34, 30, 25, 19, 12, 3, -6, -17, -28, -36, -41, -44, -46, -47, -46, -42,
-38, -35, -30, -22, -13, -6, 1, 9, 18, 28, 37, 45, 51, 55, 59, 63, 65, 66, 66,
64, 62, 57, 49, 41, 34, 28, 20, 9, 0, -4, -4, -4, -5, -6, -4, -1, 4, 9, 15, 23,
30, 36, 41, 48, 56, 63, 65, 64, 63, 63, 63, 62, 60, 56, 51, 44, 35, 23, 9, -4,
-18, -33, -46, -57, -61, -63, -66, -71, -75, -74, -71, -68, -63, -54, -43, -33,
-27, -20, -11, -1, 6, 11, 16, 23, 26, 25, 22, 21, 20, 18, 14, 8, 1, -9, -22,
-33, -40, -46, -51, -56, -61, -64, -63, -62, -59, -55, -47, -38, -29, -22, -15,
-6, 5, 14, 20, 25, 31, 35, 37, 36, 36, 39, 40, 38, 32, 26, 20, 12, 2, -8, -17,
-25, -34, -42, -48, -51, -51, -49, -47, -44, -37, -30, -22, -13, -3, 8, 19, 30,
41, 52, 59, 63, 64, 66, 69, 70, 69, 68, 65, 61, 54, 46, 38, 28, 17, 7, -1, -8,
-13, -18, -22, -24, -24, -22, -16, -8, -1, 5, 12, 21, 32, 41, 48, 55, 61, 64,
64, 63, 61, 59, 56, 54, 51, 46, 39, 28, 16, 3, -10, -24, -37, -48, -55, -60,
-65, -71, -77, -80, -77, -73, -68, -63, -55, -42, -28, -17, -7, 1, 10, 18, 22,
25, 26, 27, 28, 28, 26, 21, 16, 10, 4, -4, -14, -26, -37, -47, -55, -62, -67,
-72, -77, -78, -75, -71, -66, -60, -51, -38, -27, -19, -11, 0, 13, 23, 29, 32,
35, 37, 37, 37, 41, 45, 42, 34, 25, 19, 15, 7, -5, -15, -22, -27, -35, -42, -46,
-46, -44, -42, -38, -31, -23, -13, -2, 10, 24, 36, 45, 52, 58, 64, 69, 72, 72,
72, 72, 73, 72, 66, 59, 52, 45, 36, 24, 12, 3, -4, -11, -19, -25, -27, -29, -31,
-32, -27, -17, -6, 3, 11, 20, 30, 39, 45, 49, 53, 58, 61, 62, 61, 58, 54, 49,
44, 40, 34, 26, 16, 3, -9, -20, -29, -38, -47, -56, -64, -69, -73, -74, -73,
-67, -60, -52, -42, -29, -17, -8, -4, 1, 10, 20, 27, 29, 30, 31, 29, 23, 17, 16,
14, 8, -3, -13, -24, -35, -48, -56, -60, -62, -68, -73, -74, -72, -71, -73, -70,
-61, -48, -37, -27, -17, -4, 7, 16, 25, 33, 39, 41, 43, 44, 45, 43, 39, 35, 30,
23, 15, 8, 2, -6, -13, -19, -24, -29, -35, -37, -35, -31, -28, -24, -18, -11,
-4, 5, 17, 30, 42, 52, 62, 71, 78, 79, 78, 77, 77, 75, 72, 66, 59, 50, 41, 30,
19, 11, 4, -3, -9, -17, -22, -24, -25, -27, -29, -28, -23, -15, -7, 1, 9, 18,
28, 39, 49, 55, 59, 61, 61, 59, 57, 57, 57, 54, 44, 30, 19, 10, 2, -10, -21,
-29, -36, -44, -54, -62, -66, -67, -68, -67, -65, -60, -54, -47, -39, -28, -15,
-2, 9, 17, 24, 28, 31, 32, 33, 34, 33, 28, 22, 14, 6, -2, -14, -29, -43, -53,
-58, -62, -67, -74, -80, -83, -84, -84, -81, -76, -69, -60, -49, -36, -23, -11,
-1, 9, 17, 25, 32, 37, 41, 41, 40, 41, 42, 41, 36, 30, 24, 18, 8, -2, -10, -15,
-18, -22, -26, -27, -27, -26, -25, -22, -18, -13, -6, 5, 20, 35, 46, 54, 61, 70,
77, 81, 81, 81, 79, 77, 74, 70, 63, 54, 44, 35, 25, 12, -1, -11, -19, -26, -33,
-38, -40, -38, -36, -35, -33, -29, -24, -17, -8, 3, 16, 28, 39, 48, 54, 57, 57,
55, 54, 52, 48, 45, 41, 35, 27, 14, -1, -13, -22, -29, -36, -42, -48, -53, -57,
-60, -62, -62, -59, -55, -48, -38, -28, -19, -10, 0, 11, 23, 33, 39, 42, 43, 41,
39, 38, 35, 31, 25, 17, 8, -2, -15, -30, -44, -55, -63, -70, -76, -82, -87, -90,
-91, -90, -87, -82, -75, -66, -56, -45, -33, -20, -7, 4, 14, 21, 29, 35, 39, 40,
39, 39, 39, 36, 30, 24, 17, 10, 2, -6, -12, -14, -16, -20, -24, -25, -23, -21,
-19, -16, -9, 1, 12, 23, 34, 45, 57, 68, 78, 84, 87, 89, 90, 89, 86, 81, 78, 72,
62, 50, 40, 31, 21, 7, -5, -13, -17, -21, -27, -33, -37, -39, -40, -38, -33,
-28, -24, -17, -6, 6, 18, 28, 37, 47, 54, 56, 55, 53, 52, 52, 50, 45, 38, 29,
19, 9, -2, -14, -26, -35, -40, -44, -48, -51, -54, -56, -57, -55, -53, -48, -42,
-34, -24, -12, -1, 8, 16, 24, 34, 40, 43, 42, 41, 40, 38, 33, 26, 18, 9, -3,
-17, -29, -40, -50, -60, -69, -74, -76, -78, -82, -85, -86, -86, -84, -79, -72,
-60, -48, -36, -25, -13, -1, 11, 19, 24, 29, 34, 38, 41, 40, 38, 33, 28, 22, 16,
9, 1, -6, -11, -13, -13, -14, -15, -15, -15, -15, -13, -9, -2, 5, 12, 22, 34,
46, 55, 63, 72, 80, 86, 88, 88, 88, 88, 84, 79, 72, 64, 54, 43, 31, 19, 6, -6,
-15, -21, -25, -29, -32, -35, -38, -42, -42, -39, -33, -27, -20, -10, 1, 10, 19,
30, 42, 50, 52, 52, 54, 57, 57, 52, 46, 41, 35, 25, 12, 0, -11, -20, -28, -33,
-35, -37, -38, -40, -43, -47, -50, -49, -44, -38, -33, -26, -16, -4, 6, 14, 21,
28, 34, 37, 40, 41, 39, 34, 26, 19, 13, 5, -7, -20, -32, -42, -52, -60, -66,
-71, -75, -80, -83, -85, -86, -87, -87, -83, -77, -69, -59, -45, -31, -19, -8,
1, 12, 21, 28, 34, 39, 44, 46, 43, 37, 30, 24, 18, 11, 5, 1, -2, -5, -8, -8, -6,
-4, -4, -7, -7, -6, -3, 2, 7, 15, 25, 36, 48, 59, 66, 70, 74, 78, 82, 85, 84,
82, 77, 69, 59, 49, 39, 28, 16, 5, -4, -11, -18, -26, -31, -35, -38, -41, -44,
-45, -46, -46, -44, -38, -28, -15, -2, 10, 21, 29, 36, 42, 48, 54, 57, 59, 57,
52, 45, 37, 28, 17, 5, -5, -11, -15, -20, -27, -33, -34, -33, -32, -35, -39,
-42, -43, -42, -37, -27, -16, -6, 4, 14, 23, 28, 30, 32, 35, 37, 37, 34, 29, 23,
13, 1, -10, -19, -27, -37, -48, -58, -64, -67, -69, -71, -74, -78, -83, -87,
-88, -85, -81, -76, -70, -62, -51, -38, -24, -10, 3, 12, 21, 30, 39, 45, 45, 43,
41, 39, 36, 32, 27, 21, 15, 9, 4, 3, 4, 5, 4, 3, 3, 3, 2, 1, 2, 5, 11, 19, 29,
41, 54, 66, 75, 81, 83, 86, 89, 90, 86, 79, 70, 61, 52, 41, 28, 16, 5, -4, -13,
-22, -29, -33, -36, -38, -41, -44, -48, -53, -56, -55, -50, -42, -33, -24, -15,
-6, 5, 16, 26, 36, 43, 46, 47, 45, 41, 37, 33, 29, 24, 17, 10, 3, -3, -8, -12,
-15, -17, -19, -21, -24, -26, -28, -28, -27, -26, -22, -16, -8, 1, 10, 19, 28,
37, 45, 49, 50, 48, 45, 39, 32, 24, 14, 3, -10, -22, -33, -42, -49, -56, -62,
-65, -69, -75, -81, -87, -91, -92, -90, -88, -84, -78, -71, -63, -53, -40, -24,
-8, 5, 15, 23, 30, 34, 35, 36, 38, 39, 37, 32, 27, 25, 22, 17, 14, 14, 17, 19,
18, 16, 15, 14, 11, 9, 8, 12, 18, 25, 32, 41, 49, 58, 64, 69, 76, 83, 89, 91,
88, 81, 72, 62, 53, 45, 37, 28, 18, 9, 0, -8, -15, -22, -28, -33, -38, -42, -44,
-48, -52, -56, -56, -51, -45, -38, -31, -22, -14, -6, 3, 14, 25, 32, 34, 32, 30,
28, 26, 23, 20, 16, 11, 7, 3, 1, -1, -4, -6, -8, -8, -9, -12, -15, -18, -20,
-20, -17, -12, -6, 0, 5, 8, 12, 19, 28, 36, 39, 39, 37, 34, 28, 19, 8, -1, -8,
-14, -22, -30, -38, -46, -53, -59, -65, -70, -74, -78, -82, -85, -87, -87, -85,
-82, -76, -69, -60, -52, -42, -30, -17, -5, 5, 13, 21, 27, 30, 31, 32, 32, 32,
30, 28, 28, 28, 29, 30, 31, 30, 28, 25, 23, 23, 23, 21, 19, 19, 23, 27, 29, 32,
39, 48, 56, 61, 65, 70, 74, 75, 72, 66, 60, 53, 46, 39, 33, 25, 15, 5, -2, -6,
-10, -15, -21, -28, -33, -38, -44, -49, -52, -51, -49, -48, -46, -42, -36, -31,
-25, -17, -5, 7, 14, 19, 23, 25, 23, 21, 21, 23, 24, 21, 16, 12, 9, 7, 4, 1, 0,
-1, -3, -6, -10, -15, -19, -20, -16, -10, -4, 0, 2, 5, 8, 12, 17, 21, 24, 27,
27, 24, 20, 16, 12, 6, -1, -7, -13, -19, -26, -33, -37, -41, -46, -54, -61, -64,
-67, -72, -79, -82, -81, -78, -74, -69, -62, -54, -46, -39, -30, -20, -11, -3,
4, 11, 16, 21, 26, 30, 32, 34, 37, 41, 45, 46, 47, 48, 48, 46, 43, 41, 40, 37,
34, 32, 32, 32, 32, 32, 34, 39, 44, 48, 51, 54, 55, 55, 54, 54, 53, 50, 46, 43,
40, 35, 29, 23, 18, 13, 9, 4, -2, -10, -18, -25, -31, -37, -44, -49, -50, -50,
-49, -49, -46, -41, -35, -31, -27, -21, -14, -9, -6, -3, 2, 7, 10, 12, 13, 14,
15, 16, 16, 18, 21, 23, 22, 19, 15, 12, 9, 5, 1, 0, -1, -2, -4, -4, -2, -1, 1,
3, 7, 10, 11, 10, 10, 10, 10, 9, 8, 7, 4, 0, -5, -8, -10, -13, -18, -22, -26,
-31, -37, -42, -47, -53, -59, -64, -66, -67, -67, -67, -66, -62, -56, -49, -42,
-35, -29, -22, -15, -8, -2, 3, 9, 16, 21, 25, 28, 34, 40, 45, 47, 48, 49, 50,
50, 50, 49, 48, 47, 44, 43, 43, 43, 43, 42, 45, 49, 53, 55, 55, 57, 59, 57, 50,
44, 41, 41, 39, 35, 30, 26, 21, 17, 14, 12, 8, 3, -4, -11, -19, -27, -35, -41,
-46, -49, -53, -54, -55, -55, -54, -53, -49, -44, -40, -36, -31, -25, -20, -19,
-19, -16, -11, -6, -2, 1, 5, 10, 16, 20, 23, 25, 26, 27, 27, 25, 21, 16, 12, 10,
8, 9, 10, 12, 14, 14, 14, 14, 16, 16, 16, 14, 12, 11, 10, 8, 5, 1, -2, -5, -8,
-11, -15, -17, -18, -21, -24, -28, -33, -39, -46, -53, -58, -63, -67, -72, -74,
-74, -71, -67, -62, -55, -47, -41, -36, -34, -31, -25, -17, -10, -6, -2, 5, 14,
21, 26, 32, 39, 46, 50, 54, 59, 64, 67, 66, 64, 63, 60, 55, 50, 48, 49, 50, 51,
54, 57, 59, 59, 59, 60, 61, 58, 52, 45, 39, 33, 28, 26, 25, 21, 16, 11, 8, 6, 1,
-5, -11, -16, -22, -29, -35, -41, -47, -55, -60, -62, -62, -63, -64, -61, -55,
-48, -44, -42, -40, -38, -35, -32, -29, -27, -24, -20, -15, -9, -4, 0, 5, 10,
16, 20, 23, 25, 27, 26, 23, 20, 18, 16, 14, 12, 12, 14, 16, 16, 18, 21, 25, 27,
26, 24, 21, 18, 14, 9, 5, 3, 1, -1, -4, -7, -10, -11, -13, -15, -19, -23, -27,
-32, -37, -42, -49, -55, -60, -63, -63, -63, -62, -60, -56, -52, -48, -43, -36,
-30, -26, -23, -20, -15, -10, -4, 2, 9, 17, 25, 32, 42, 53, 61, 65, 65, 68, 72,
74, 72, 70, 67, 65, 62, 59, 57, 55, 54, 54, 57, 63, 66, 66, 64, 61, 58, 54, 47,
41, 36, 32, 28, 23, 19, 16, 14, 10, 5, 1, -1, -4, -11, -22, -32, -39, -44, -51,
-58, -64, -66, -69, -72, -75, -72, -67, -62, -60, -58, -54, -51, -49, -48, -45,
-41, -39, -36, -31, -23, -15, -7, 2, 12, 19, 23, 25, 29, 32, 31, 29, 28, 28, 26,
21, 18, 19, 22, 21, 20, 21, 25, 29, 29, 28, 29, 30, 28, 23, 19, 16, 12, 7, 2, 1,
2, 3, 3, 1, -1, -6, -11, -15, -19, -26, -34, -42, -48, -55, -60, -64, -64, -64,
-63, -60, -55, -49, -46, -44, -41, -35, -28, -22, -19, -15, -10, -4, 0, 3, 9,
19, 31, 41, 49, 57, 65, 70, 72, 71, 71, 70, 68, 64, 61, 59, 57, 53, 52, 54, 56,
57, 56, 58, 60, 59, 54, 49, 44, 41, 36, 30, 26, 23, 18, 12, 9, 8, 7, 5, 3, -1,
-7, -15, -23, -29, -37, -45, -54, -60, -65, -71, -74, -74, -72, -71, -71, -69,
-65, -60, -57, -54, -50, -46, -42, -38, -33, -28, -24, -20, -13, -3, 7, 14, 22,
30, 36, 38, 37, 37, 38, 36, 31, 28, 27, 25, 21, 19, 20, 23, 24, 23, 23, 25, 26,
24, 22, 20, 17, 12, 7, 5, 4, 1, -3, -6, -4, -3, -3, -6, -8, -10, -13, -18, -25,
-33, -42, -51, -57, -60, -61, -62, -62, -62, -60, -58, -56, -53, -46, -38, -32,
-28, -23, -17, -11, -8, -6, 0, 10, 21, 30, 39, 50, 63, 72, 77, 81, 84, 86, 82,
76, 72, 69, 66, 62, 59, 58, 57, 55, 52, 50, 48, 46, 43, 40, 39, 37, 32, 27, 25,
22, 17, 11, 7, 5, 5, 4, 3, 2, -1, -4, -10, -16, -24, -35, -47, -58, -65, -72,
-76, -79, -80, -81, -82, -80, -76, -74, -73, -71, -65, -59, -55, -52, -47, -40,
-33, -28, -22, -14, -4, 6, 16, 26, 36, 44, 50, 54, 55, 53, 48, 44, 41, 38, 34,
29, 27, 26, 25, 23, 23, 24, 23, 20, 18, 17, 16, 13, 9, 5, 3, 0, -4, -8, -10, -7,
-4, -2, -2, -2, -2, -4, -10, -18, -27, -35, -42, -49, -56, -62, -65, -67, -67,
-64, -60, -56, -53, -50, -46, -40, -33, -27, -20, -14, -8, -3, 3, 11, 21, 32,
45, 58, 71, 83, 92, 97, 100, 101, 101, 98, 93, 87, 81, 75, 70, 67, 65, 62, 57,
52, 48, 46, 43, 37, 32, 28, 25, 19, 12, 7, 3, -1, -4, -6, -6, -6, -6, -5, -4,
-4, -8, -15, -24, -34, -44, -55, -65, -75, -82, -86, -89, -89, -89, -88, -87,
-84, -80, -75, -69, -62, -56, -52, -49, -44, -37, -28, -18, -8, 3, 15, 27, 39,
52, 63, 70, 72, 72, 70, 66, 61, 55, 50, 46, 42, 37, 33, 30, 29, 27, 23, 19, 16,
12, 9, 5, 1, -4, -9, -13, -17, -18, -18, -17, -15, -11, -7, -2, 1, 1, -2, -8,
-16, -26, -34, -42, -49, -54, -60, -64, -66, -67, -67, -65, -64, -60, -55, -49,
-44, -38, -32, -26, -20, -15, -8, 1, 10, 19, 30, 45, 60, 75, 88, 99, 108, 113,
115, 113, 109, 104, 98, 91, 86, 83, 78, 73, 68, 65, 61, 57, 51, 45, 39, 34, 27,
20, 11, 3, -4, -9, -14, -15, -14, -11, -9, -8, -6, -4, -5, -10, -17, -25, -34,
-46, -58, -69, -77, -86, -93, -96, -94, -93, -94, -96, -94, -89, -86, -83, -78,
-71, -64, -60, -55, -48, -37, -25, -13, -1, 13, 29, 44, 57, 68, 75, 79, 79, 76,
72, 68, 64, 60, 54, 47, 43, 40, 37, 33, 29, 26, 23, 18, 11, 4, -1, -6, -13, -20,
-24, -26, -27, -27, -24, -21, -16, -12, -6, -1, 0, -4, -12, -19, -25, -33, -42,
-51, -56, -59, -64, -69, -70, -68, -66, -64, -62, -55, -48, -43, -40, -36, -29,
-24, -20, -15, -6, 6, 17, 31, 46, 64, 80, 95, 106, 113, 116, 116, 115, 113, 107,
101, 95, 92, 87, 82, 77, 75, 71, 63, 54, 48, 44, 39, 31, 20, 12, 4, -4, -12,
-17, -19, -20, -19, -17, -13, -7, -3, -3, -5, -11, -19, -28, -37, -47, -56, -64,
-71, -78, -85, -89, -90, -89, -89, -89, -87, -84, -80, -78, -75, -71, -66, -62,
-56, -48, -37, -26, -14, -1, 16, 34, 51, 64, 75, 83, 86, 84, 81, 79, 77, 71, 64,
57, 54, 52, 47, 41, 38, 35, 32, 27, 22, 19, 13, 3, -8, -15, -19, -24, -30, -33,
-32, -29, -26, -22, -16, -9, -6, -8, -13, -19, -25, -33, -41, -49, -56, -62,
-66, -69, -71, -71, -69, -65, -63, -62, -59, -55, -49, -44, -40, -37, -31, -24,
-15, -4, 7, 19, 34, 52, 71, 88, 102, 113, 120, 122, 121, 120, 119, 117, 111,
104, 99, 95, 90, 84, 79, 75, 71, 64, 56, 48, 41, 34, 25, 16, 7, -1, -8, -15,
-19, -20, -18, -13, -8, -4, -2, 0, -1, -6, -15, -26, -36, -46, -56, -65, -72,
-77, -81, -85, -88, -87, -85, -85, -87, -87, -85, -79, -74, -71, -69, -65, -60,
-53, -45, -34, -23, -8, 10, 30, 50, 64, 74, 81, 85, 86, 83, 79, 75, 70, 64, 59,
55, 52, 47, 43, 39, 36, 31, 25, 18, 12, 6, -2, -12, -20, -27, -33, -38, -40,
-39, -35, -29, -22, -15, -10, -6, -4, -6, -12, -19, -27, -35, -44, -54, -61,
-66, -68, -68, -69, -68, -66, -62, -60, -58, -55, -50, -45, -41, -39, -35, -29,
-22, -13, -2, 12, 30, 48, 66, 82, 98, 111, 119, 124, 127, 127, 125, 118, 111,
106, 102, 97, 90, 85, 80, 77, 72, 67, 60, 51, 43, 34, 26, 15, 4, -5, -12, -17,
-23, -27, -26, -21, -16, -13, -11, -8, -7, -9, -16, -24, -34, -43, -54, -64,
-73, -79, -85, -89, -93, -94, -93, -91, -90, -89, -86, -82, -79, -78, -76, -71,
-64, -58, -52, -44, -30, -13, 4, 21, 38, 55, 71, 84, 93, 97, 97, 95, 91, 86, 80,
74, 68, 63, 57, 52, 49, 46, 41, 34, 25, 17, 9, 0, -11, -20, -29, -36, -42, -44,
-44, -42, -38, -33, -27, -22, -19, -17, -16, -17, -21, -28, -36, -44, -50, -55,
-59, -65, -71, -73, -72, -71, -70, -67, -62, -56, -53, -51, -48, -44, -42, -40,
-36, -27, -16, -4, 11, 30, 51, 70, 86, 102, 115, 122, 123, 124, 126, 127, 124,
119, 114, 109, 103, 95, 89, 86, 82, 75, 68, 61, 53, 43, 32, 23, 14, 5, -4, -13,
-21, -26, -27, -26, -23, -20, -16, -11, -10, -13, -19, -24, -29, -36, -47, -56,
-65, -73, -80, -85, -86, -85, -85, -85, -84, -82, -81, -82, -81, -76, -71, -67,
-65, -60, -53, -44, -34, -20, -4, 12, 28, 43, 57, 68, 75, 83, 90, 95, 94, 90,
86, 82, 76, 68, 63, 60, 58, 52, 46, 42, 40, 34, 24, 14, 5, -2, -11, -21, -30,
-36, -40, -40, -38, -34, -31, -28, -25, -22, -20, -21, -24, -27, -31, -37, -45,
-54, -61, -64, -66, -69, -71, -71, -70, -69, -67, -64, -59, -55, -50, -44, -37,
-31, -26, -18, -9, -1, 8, 19, 35, 52, 66, 77, 88, 100, 110, 115, 116, 117, 116,
115, 111, 106, 99, 93, 88, 84, 79, 73, 68, 64, 60, 52, 41, 32, 25, 19, 11, 1,
-7, -11, -14, -17, -17, -17, -17, -18, -20, -20, -19, -20, -26, -33, -40, -45,
-52, -60, -68, -74, -79, -82, -83, -81, -78, -75, -71, -67, -63, -60, -57, -51,
-43, -37, -32, -27, -19, -8, 4, 16, 27, 37, 47, 55, 64, 72, 76, 75, 72, 68, 63,
55, 47, 39, 32, 25, 17, 10, 6, 3, -2, -8, -13, -17, -22, -27, -32, -35, -37,
-38, -39, -39, -36, -33, -28, -24, -20, -17, -12, -6, -2, };

#endif /* AIRSYNTH_8192_H_ */