/*
   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
   See license.html for license.

   This just provides documentation for stuff that doesn't need to be in the
   source headers themselves.  It is a ".cc" file for the sole cheesy reason
   that it triggers many different text editors into doing Nice Things when
   typing comments.  However, it is mentioned nowhere except the *cfg.in files.

   Some actual code (declarations) is exposed here, but no compiler ever
   sees it.  The decls must be visible to doxygen, and sometimes their real
   declarations are not visible, or not visible in a way we want.

   Pieces separated by '// //' lines will usually not be presented to the
   user on the same page.
*/

// // // // // // // // // // // // // // // // // // // // // // // //
/** @namespace std
 *  @brief Everything defined by the ISO C++ Standard is within namespace std.
*/
/** @namespace __gnu_cxx
 *  @brief This namespace serves two purposes.
 *
 *  This namespace is used for two things:
 *  -  sequestering internal (implementation-only) names away from the
 *     global namespace; these are details of the implementation and should
 *     not be touched by users
 *  -  GNU extensions for public use
 *
 *  This is still fluid and changing rapidly.  Currently the rule is:  if an
 *  entitity is found in the user-level documentation, it falls into the
 *  second category.
*/

// // // // // // // // // // // // // // // // // // // // // // // //
/** @addtogroup SGIextensions STL extensions from SGI
Because libstdc++-v3 based its implementation of the STL subsections of
the library on the SGI 3.3 implementation, we inherited their extensions
as well.

They are additionally documented in the
<a href="http://gcc.gnu.org/onlinedocs/libstdc++/documentation.html">
online documentation</a>, a copy of which is also shipped with the
library source code (in .../docs/html/documentation.html).  You can also
read the documentation <a href="http://www.sgi.com/tech/stl/">on SGI's
site</a>, which is still running even though the code is not maintained.

<strong>NB</strong> that the following notes are pulled from various
comments all over the place, so they may seem stilted.
<hr>
*/

// // // // // // // // // // // // // // // // // // // // // // // //
// This is standalone because, unlike the functor introduction, there is no
// single header file which serves as a base "all containers must include
// this header".  We do some quoting of 14882 here.
/** @addtogroup Containers Containers
Containers are collections of objects.

A container may hold any type which meets certain requirements, but the type
of contained object is chosen at compile time, and all objects in a given
container must be of the same type.  (Polymorphism is possible by declaring a
container of pointers to a base class and then populating it with pointers to
instances of derived classes.  Variant value types such as the @c any class
from <a href="http://www.boost.org/">Boost</a> can also be used.

All contained types must be @c Assignable and @c CopyConstructible.
Specific containers may place additional requirements on the types of
their contained objects.

Containers manage memory allocation and deallocation themselves when
storing your objects.  The objects are destroyed when the container is
itself destroyed.  Note that if you are storing pointers in a container,
@c delete is @e not automatically called on the pointers before destroying them.

All containers must meet certain requirements, summarized in
<a href="tables.html">tables</a>.

The standard containers are further refined into
@link Sequences Sequences@endlink and
@link Assoc_containers Associative Containers@endlink.
*/

/** @addtogroup Sequences Sequences
Sequences arrange a collection of objects into a strictly linear order.

The differences between sequences are usually due to one or both of the
following:
  - memory management
  - algorithmic complexity

As an example of the first case, @c vector is required to use a contiguous
memory layout, while other sequences such as @c deque are not.

The prime reason for choosing one sequence over another should be based on
the second category of differences, algorithmic complexity.  For example, if
you need to perform many inserts and removals from the middle of a sequence,
@c list would be ideal.  But if you need to perform constant-time access to
random elements of the sequence, then @c list should not be used.

All sequences must meet certain requirements, summarized in
<a href="tables.html">tables</a>.
*/

/** @addtogroup Assoc_containers Associative Containers
Associative containers allow fast retrieval of data based on keys.

Each container type is parameterized on a @c Key type, and an ordering
relation used to sort the elements of the container.

There should be more text here.

All associative containers must meet certain requirements, summarized in
<a href="tables.html">tables</a>.
*/

// // // // // // // // // // // // // // // // // // // // // // // //
/** @namespace abi
 *  @brief The cross-vendor C++ Application Binary Interface.
 *
 *  A brief overview of an ABI is given in the libstdc++-v3 FAQ, question
 *  5.8 (you may have a copy of the FAQ locally, or you can view the online
 *  version at http://gcc.gnu.org/onlinedocs/libstdc++/faq/index.html#5_8).
 *
 *  GCC subscribes to a relatively-new cross-vendor ABI for C++, sometimes
 *  called the IA64 ABI because it happens to be the native ABI for that
 *  platform.  It is summarized at http://www.codesourcery.com/cxx-abi/
 *  along with the current specification.
 *
 *  For users of GCC 3.x, entry points are available in <cxxabi.h>, which notes,
 *  <em>"It is not normally necessary for user programs to include this header,
 *  or use the entry points directly.  However, this header is available
 *  should that be needed."</em>
*/

namespace abi {
/**
@brief New ABI-mandated entry point in the C++ runtime library for demangling.

@param mangled_name A NUL-terminated character string containing the name
                    to be demangled.

@param output_buffer A region of memory, allocated with malloc, of
                     @a *length bytes, into which the demangled name
                     is stored.  If @a output_buffer is not long enough,
                     it is expanded using realloc.  @a output_buffer may
                     instead be NULL; in that case, the demangled name is
                     placed in a region of memory allocated with malloc.

@param length If @a length is non-NULL, the length of the buffer containing
              the demangled name is placed in @a *length.

@param status @a *status is set to one of the following values:
              -   0: The demangling operation succeeded.
              -  -1: A memory allocation failiure occurred.
              -  -2: @a mangled_name is not a valid name under the C++ ABI
                     mangling rules.
              -  -3: One of the arguments is invalid.

@return A pointer to the start of the NUL-terminated demangled name, or NULL
        if the demangling fails.  The caller is responsible for deallocating
        this memory using @c free.


The demagling is performed using the C++ ABI mangling rules, with
GNU extensions.  For example, this function is used
in __gnu_cxx::__verbose_terminate_handler.  See
http://gcc.gnu.org/onlinedocs/libstdc++/18_support/howto.html#5 for other
examples of use.

@note The same demangling functionality is available via libiberty 
(@c <libiberty/demangle.h> and @c libiberty.a) in GCC 3.1 and later, but that
requires explicit installation (@c --enable-install-libiberty) and uses a
different API, although the ABI is unchanged.
*/
char* __cxa_demangle (const char* mangled_name, char* output_buffer,
                      size_t* length, int* status);
} // namespace abi

// // // // // // // // // // // // // // // // // // // // // // // //

// vim:et:noai:

