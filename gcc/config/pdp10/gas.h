/* Definitions for PDP-10 target machine using the GNU assembler.
   Copyright (C) 2001 Free Software Foundation, Inc.
   Contributed by Lars Brinkhoff (lars@nocrew.org), funded by XKL, LLC.
   
This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */

#ifndef __PDP10_GAS_H__
#define __PDP10_GAS_H__

#define ASM_COMMENT_START "#"

#define IS_ASM_LOGICAL_LINE_SEPARATOR(C) ((C) == ';')

#define ASM_OUTPUT_SKIP(STREAM, NBYTES) \
   fprintf ((STREAM), "\t.space\t%d\n", (NBYTES))

#endif /* __PDP10_GAS_H__ */
