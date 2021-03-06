/* Configuration for GCC for ITS hosts.
   Copyright (C) 2002 Free Software Foundation, Inc.
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

/* We support both "/" and ">" since everybody tests both but we
   default to "/".  This is important because if GCC produces TOPS-20
   paths containing angle brackets, make and configure may get
   confused. */
#define DIR_SEPARATOR '/'
#define DIR_SEPARATOR_2 ';'

/* A C string representing the suffix for object files in TOPS-20.  */
#define HOST_OBJECT_SUFFIX ".REL"

/* A C string representing the suffix for executable files in TOPS-20.  */
#define HOST_EXECUTABLE_SUFFIX ".EXE"

/* EOF xm-tops20.h */
