#include <cassert>
#include <iostream>

using namespace std;

struct A {};  								  // Can implicitly add copy assignment
struct B {B& operator=(const B&) = delete;};  // Copy assignment deleted
struct C {C(const C& other) {};}; 			  // CopyAssignable but not CopyConstructable
struct D {D(const D& other) = delete;}; 	  // CopyAssignable but not CopyConstructable
struct E {E(E&& other) {};}; 				  // Copy constructor added but not copy assignment
struct F {F(const F& other) = default;};      // Trivial and non throwing
struct G {G& operator=(G&& other) {return other;};}; // MoveAssignable but not CopyAssignable



int main() {
	assert(is_copy_assignable<A>::value);
	assert(!is_copy_assignable<B>::value);
	assert(is_copy_assignable<C>::value);
	assert(is_copy_assignable<D>::value);
	assert(!is_copy_assignable<E>::value);
	assert(is_copy_assignable<F>::value);
	assert(!is_copy_assignable<G>::value);
}
