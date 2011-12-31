/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Copyright (C) 2012 Intel Corporation
** Contact: http://www.qt-project.org/
**
** This file is part of the FOO module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#define QGLOBAL_H
#include "../../src/corelib/global/qprocessordetection.h"
#include <stdio.h>

extern const char msg[];
const char msg[] = "==Qt=magic=Qt== Architecture:"

#if defined(Q_PROCESSOR_ALPHA)
"alpha"
#elif defined(Q_PROCESSOR_ARM)
"arm"
#elif defined(Q_PROCESSOR_AVR32)
"avr32"
#elif defined(Q_PROCESSOR_BLACKFIN)
"bfin"
#elif defined(Q_PROCESSOR_X86_32)
"i386"
#elif defined(Q_PROCESSOR_X86_64)
"x86_64"
#elif defined(Q_PROCESSOR_IA64)
"ia64"
#elif defined(Q_PROCESSOR_MIPS)
"mips"
#elif defined(Q_PROCESSOR_POWER)
"power"
#elif defined(Q_PROCESSOR_S390)
"s390"
#elif defined(Q_PROCESSOR_SH)
"sh"
#elif defined(Q_PROCESSOR_SPARC)
"sparc"
#else
"unknown"
#endif
                   ;

extern const char msg2[];
const char msg2[] = "==Qt=magic=Qt== Sub-architecture:"
        // This is the list of features found in GCC or MSVC
        // We don't use all of them, but this is ready for future expansion

// -- x86 --
#ifdef __3dNOW__
// 3dNow!, introduced with the AMD K6-2, discontinued after 2010
" 3dnow"
#endif
#ifdef __3dNOW_A__
// Athlon
" 3dnow-a"
#endif
#ifdef __ABM__
// Advanced Bit Manipulation, AMD Barcelona (family 10h)
" abm"
#endif
#ifdef __AES__
// AES New Instructions, Intel Core-i7 second generation ("Sandy Bridge")
" aes"
#endif
#ifdef __AVX__
// Advanced Vector Extensions, Intel Core-i7 second generation ("Sandy Bridge")
" avx"
#endif
#ifdef __AVX2__
// AVX 2, Intel codename "Haswell"
" avx2"
#endif
#ifdef __BMI__
// Bit Manipulation Instructions 1, Intel codename "Haswell", AMD "Bulldozer 2"
" bmi"
#endif
#ifdef __BMI2__
// Bit Manipulation Instructions 2, Intel codename "Haswell"
" bmi2"
#endif
#ifdef __GCC_HAVE_SYNC_COMPARE_AND_SWAP_16
// cmpxchg16b instruction, Intel Pentium 4 64-bit ("Nocona"), AMD Barcelona (family 10h)
// Notably, this instruction is missing on earlier AMD Athlon 64
" cx16"
#endif
#ifdef __F16C__
// 16-bit floating point conversion, Intel codename "Ivy Bridge"
" f16c"
#endif
#ifdef __FMA__
// Fused Multiply-Add with 3 arguments, Intel codename "Haswell", AMD "Bulldozer 2"
// a.k.a. "FMA3"
" fma"
#endif
#ifdef __FMA4__
// Fused Multiply-Add with 4 arguments, AMD "Bulldozer"
" fma4"
#endif
#ifdef __FSGSBASE__
// rdfsgsbase, wrfsgsbase, Intel codename "Ivy Bridge"
" fsgsbase"
#endif
#ifdef __LWP__
// LWP instructions, AMD "Bulldozer"
" lwp"
#endif
#ifdef __LZCNT__
// Leading-Zero bit count, Intel codename "Haswell"
" lzcnt"
#endif
#ifdef __MMX__
// Multimedia Extensions, Pentium MMX, AMD K6-2
" mmx"
#endif
#ifdef __MOVBE__
// Move Big Endian, Intel Atom & "Haswell"
" movbe"
#endif
#ifdef __NO_SAHF__
// missing SAHF instruction in 64-bit, up to Intel Pentium 4 64-bit ("Nocona"), AMD Athlon FX
// Note: the macro is not defined, so this will never show up
" no-sahf"
#endif
#ifdef __PCLMUL__
// (Packed) Carry-less multiplication, Intel Core-i7 second generation ("Sandy Bridge")
" pclmul"
#endif
#ifdef __POPCNT__
// Population Count (count of set bits), Intel Core-i7 second generation ("Sandy Bridge")
" popcnt"
#endif
#ifdef __RDRND__
// Random number generator, Intel codename "Ivy Bridge"
" rdrnd"
#endif
#if defined(__SSE__) || (defined(_M_IX86_FP) && _M_IX86_FP >= 1) || defined(_M_X64)
// Streaming SIMD Extensions, Intel Pentium III, AMD Athlon
" sse"
#endif
#if defined(__SSE2__) || (defined(_M_IX86_FP) && _M_IX86_FP >= 2) || defined(_M_X64)
// SSE2, Intel Pentium-M, Intel Pentium 4, AMD Opteron and Athlon 64
" sse2"
#endif
#ifdef __SSE3__
// SSE3, Intel Pentium 4 "Prescott", AMD Athlon 64 rev E
" sse3"
#endif
#ifdef __SSSE3__
// Supplemental SSE3, Intel Core 2, AMD "Bulldozer"
" ssse3"
#endif
#ifdef __SSE4A__
// SSE4a, AMD Barcelona
" sse4a"
#endif
#ifdef __SSE4_1__
// SSE 4.1, Intel Core-i7 ("Nehalem"), AMD "Bulldozer"
" sse4.1"
#endif
#ifdef __SSE4_2__
// SSE 4.2, Intel Core-i7 ("Nehalem"), AMD "Bulldozer"
" sse4.2"
// Since no processor supports SSE4.2 without 4.1 and since no Intel processor
// supports SSE4a, define "sse4" to indicate SSE4"
" sse4"
#endif
#ifdef __TBM__
// TBM, AMD "Bulldozer"
" tbm"
#endif
#ifdef __XOP__
// XOP, AMD "Bulldozer"
" xop"
#endif

// -- ARM --
#ifdef __ARM_NEON__
" neon"
#endif
#ifdef __IWMMXT__
" iwmmxt"
#endif

// -- SPARC --
#ifdef __VIS__
" vis"
# if __VIS__ >= 0x200
" vis2"
# endif
# if __VIS__ >= 0x300
" vis3"
# endif
#endif

// -- MIPS --
// Wikipedia says there are extensions, but GCC installs no headers

// -- POWER, PowerPC --
#ifdef __ALTIVEC__
" altivec"
#endif
                   "";

int main()
{
    puts(msg);
    puts(msg2);
}
