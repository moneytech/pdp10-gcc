This is a backend for the PDP-10.  See gcc/config/pdp10.

The PDP-10 architecture is a family of 36-bit word-addressed machines.
They were manufactured primarily by DEC from 1964 to 1983, when they
were cancelled in favour of the VAX family.  Famous software first
running on PDP-10s include: EMACS, ITS, SPELL, Collosal Cave, ADVENT,
Zork, Dungeon, MacLisp.  Not first: TECO.

A memory word is 36 bits long, which is also the length of the
general-purpose registers.  All user instructions are 36 bits and have
9 bits to specify an operation, 4 bits to specify a register, 1 bit to
indicate indirect addressing, 4 bits to specify an index register, and
18 bits to specify an address or offset.  The first version of the
architecture was limited to a virtual address space of 256K words; a
later version extended this to a maximum of 1G words.
