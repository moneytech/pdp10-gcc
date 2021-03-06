// { dg-do compile }

// Copyright (C) 2001 Free Software Foundation, Inc.
// Contributed by Nathan Sidwell 15 Dec 2001 <nathan@codesourcery.com>

// PR 2645

struct AS
{
  typedef void (myT) ();
  struct L {};
  
};


template <typename T> struct B1 : T
{
  typedef typename T::L __restrict__ r;// { dg-error "`__restrict' qualifiers cannot" "" }
  typedef typename T::myT __restrict__ p;// { dg-warning "ignoring `__restrict'" "" }
  
  typedef typename T::myT volatile *myvolatile; // { dg-warning "ignoring `volatile'" "" }
  typename T::myT volatile *a;    // { dg-warning "ignoring `volatile'" "" }
  myvolatile b;			 // { dg-bogus "ignoring `volatile'" "" { xfail *-*-* } }
};
template <typename T> struct B2 : T
{
  typedef typename T::myT const *myconst;
  typename T::myT const *a;
  myconst b;
};

B1<AS> b1;	// { dg-error "instantiated" "" }
B2<AS> b2;
