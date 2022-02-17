// Dynamic_Memory_Allocation_Basics			Feb 2022
//
// Demonstrates
// - using "new" to allocate dynamic memory from the Heap
// - using "delete" and "delete[]" to free up allocated memory
// - dynamic allocation of an array of elements
//

#include <iostream>
using namespace std;

void demo1();
void demo2();
void demo3();

int main()
{
    cout << "Dynamic Memory Allocation - new, delete, new[] and delete[]" << endl;;
    cout << "Remember to uncomment calls to demo1() , 2 and 3 etc" << endl;

    demo1();
    //demo2();
    //demo3();

}

void demo1()  // Dynamic Memory Allocation (DMA) (memory allocated form the 'Heap')
{
    /**
     When we declare a variable normally - ( e.g.  int x;) - the memory is automatically
     allocated (obtained) for us.  That is to say, the system obtains a piece
     of memory for us from the Stack, and associates it with our variable named x.

     When a Stack-based variable's life (duration) ends - the memory associated with x is
     'freed up' or given back to the system automatically.	 (Remember our stack frame diagrams!)
     So, we programmers don't have to worry about managing the memory used by 'automatic' variables.
     (Note: the duration(life) of a local variable in a function is, from its declaration in
     the function, until the function returns/ends. )

     Sometimes it is useful, for various reasons, for our program to make a request at RUN-TIME
     to obtain a block of memory of a particular size, in order to store data.
     This is called allocating memory dynamically. (or Dynamic Memory Allocation - DMA).

     Dynamically allocated memory comes from the 'Heap' part of memory
     (where, incidentally, all objects are stored in Java).
     We allocate memory using the keyword 'new', which basically requests a block of memory
     of the specified size.
     When finished, we must/should 'free up' the block of memory using the keyword 'delete'.
     When we call 'delete', the  memory isn't actually deleted, but rather, the memory block
     is freed-up (i.e. given back to the system so that it can be used again).

     Dynamically allocated memory MUST be accessed using a pointer
     (a pointer that can be assigned the address of the memory block allocated from the Heap)

     It is very important to understand DMA, however, it should only be used where
     necessary in C++, as it can be the source of 'Memory Leaks' and other bugs in programs.
     A memory leak occurs where a programmer allocates a block of memory, but
     fails to free it up after it is no longer required.
     (i.e. the programmer forgets to write the code to delete the memory block)

     Modern C++ provides many features that reduce the need to use DMA- we may examine some of them.

     Finally, an example .....

     Allocating memory dynamically using 'new'

     The following sample dynamically allocates a single byte (a char) of Heap memory.
     (It is a simple example to demonstrate the fundamentals).

*/
    cout << "\ndemo1() - dynamically allocate memory to store a single character (char = 1 byte)" << endl;

    char* char_ptr = new char;		// i.e. dynamically allocate a block of memory for one 'char' (from Heap memory),
    // and store its returned address in a pointer p

    //cout << "Output the char that char_ptr points to. It will be a 'random' garbage character: *char_ptr = " << *char_ptr << endl;

    *char_ptr = 'F';	// assign the letter 'F' into the memory location pointed at by pointer char_ptr

    cout << "*char_ptr = " << *char_ptr << endl;	// output what char_ptr points at (by de-referencing the pointer)
    // the value stored at the address pointed to by char_ptr should be 'F'

    // now, let's say that we are finished using the dynamically allocated block of memory.
    // We MUST remember to free up that memory by calling 'delete' on the pointer.

    delete char_ptr;   // frees up the memory pointed at by char_ptr.  (memory leak occurs if this is not called)

    char_ptr = nullptr; // pointers should be set to 'nullptr' after the memory that they point at has been deleted,
    // otherwise, they become what is known as 'Dangling Pointers'
    // Dangling Pointers point to memory that has been freed up.
    // Dangling pointers are another major source of errors, as, they point to memory
    // that is no longer owned by this program, and that memory may be (or may have
    // been) allocated to another program.
    // If this program accesses memory with a dangling pointer, then it may be accessing
    // data belonging to another program.!! And may corrupt that data.


    // MEMORY LEAK !!
    // A major problem (source of bugs) is forgetting to delete the dynamically allocated memory.
    // If we forget to delete the memory, our program may continue to work 'happily' (for a time).
    // No compiler errors or runtime errors will be displayed.
    // However, every time this demo1() function is called, it is allocated a NEW block
    // of dynamic memory from the Heap, but that memory is never freed up (released).
    // So, if demo1() is called many times, all the memory from the Heap will be allocated
    // (a byte at a time!), all the Heap memory will be exhausted so there will be no more to give out,
    // and our program will crash at the next request for memory allocation.
    // This sequence of allocating dynamic memory without freeing it up (using delete) is called a 'memory leakage',
    // as it seems like the computer's memory is 'leaking away' until there is none left!.
    // An additional problem is that this type of error is extremely difficult to detect, because it
    // doesn't have any effect until the point when memory is exhausted and the program crashes.

    // Modern C++ provides Smart Pointers that reduce(eliminate) the chance of memory leaks.


//TODO in class:
//    Allocate dynamic memory to store the time (UNIX time) in an unsigned long integer value.
//    Declare and add the address of the memory in a pointer called  time_ptr ("pointer to time")
//    Assign the value 1234567890 to the memory block using the (de-referenced) pointer.
//    Output the time value using the pointer (de-reference it)
//    Increment the time value by 1 (second) using the pointer.
//    Output the new value.
//
//    ...finish up
//    .. oops, did we forget something? Yes we did!!!
//
//TODO    DRAW a memory diagram to represent the state of variables in the stack frame


}


void demo2()  // using the NULL pointer "nullptr"  (Good Practice)
{
    /** Microsoft Docs says:
      "The nullptr keyword represents a null pointer value. Use a null pointer value to indicate that
       an object handle, interior pointer, or native pointer type does not point to an object."
    */
    cout << "\ndemo2() - deleting dynamic memory and using \"nullptr\"" << endl;


    int* p = new int;	// allocates one int (4 bytes) dynamically from the Heap
    *p = 25;

    cout << "p:\t" << p << endl;	// address stored in p
    cout << "*p:\t" << *p << endl;	// value stored at address pointed to by p

    // When we have finished using a pointer, and we wish to indicate that we no longer
    // want the pointer to point at an object, then we assign the value 'nullptr' to the pointer.
    // This helps ensure that we don't use the pointer by mistake (i.e. as a dangling pointer)
    // nullptr can be assigned only to pointer type variables as it is a special value.
    // It is also good practice to assign nullptr to pointers that do not yet point at an object,
    // as well as pointers that we are finished using.

    delete p;		// free up memory pointed at by p
    //cout << "After deleting p, *p = " << *p << endl;  // causes crash or possibly unnoticed error

    p = nullptr;	// setting pointer to nullptr prevents us from mistakenly using it after delete
    // Good practice to set deleted pointers to nullptr.

    cout << "p:\t" << p << " (nullptr shows as the value 00000000)" << endl;	//value stored in p

    // Attempting to dereference a null pointer will cause an exception and crash your program.
    // But, this is a GOOD thing, as it is better than allowing the use of a dangling pointer that
    // could access and modify data that doesn't belong to this program.
    //
    // Remove the comment below and try running the code
    //
    // cout << "*p:\t" << *p << endl;	// attempt to dereference a null pointer
    // Above will throw an exception - you can Debug to see the nature of the exception thrown

}

///////// demo3() functions ///////////////////////////////////////////////////////////////////

void display_using_array_notation( int array[], int size )
{
    cout << "display using array notation:" << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << endl;
}

void display_using_pointer_notation( int* array_ptr, int size )
{
    cout << "display using pointer notation:" << endl;
    for (int i = 0; i < size; i++) {
        cout << *array_ptr << endl;
        array_ptr++;	// increment the pointer (move on by one element)
    }
}

/**
* Dynamic Allocation of an ARRAY of elements from the Heap
* Using:
*		- new x[]
*		- delete []
*/

void demo3()
{
    cout << "\ndemo3() - allocating and deleting array blocks of dynamic memory"<< endl;

    int size;
    cout << "Enter size for array: (e.g. 3) ";
    cin >> size;

    int* array_ptr = new int[size];	// dynamically allocate array of 'size' ints
    // 'new' returns the address of the first element of the array.

    // using array notation with the pointer 'array_ptr'.
    // read in elements and populate the array
    for (int i = 0; i < size; i++) {
        cout << "Enter value " << i << ": ";
        cin >> array_ptr[i];	// assign inputted value to array element (array notation)
    }


    // - using array notation to access the elements
    cout << "Array elements:" << endl;
    for (int i = 0; i < size; i++)
        cout << array_ptr[i] << endl;

    display_using_array_notation(array_ptr, size);	// pass address of array (memory block)

    display_using_pointer_notation(array_ptr, size);

    //Finally - we must DELETE (free up) the allocated memory using delete []
    // Note the "[]" is ESSENTIAL, as - if we leave it out - only the first int in the
    // array will be freed up, which would lead to memory leakage.

    delete [] array_ptr;	// free up the dynamic array of int, note the "[]"
    array_ptr = nullptr;    // set to nullptr;  to prevent a dangling pointer

    cout << "Leaving demo3() - Memory has been freed up using delete []" << endl;
}

//TODO
// Write and call 2 functions:
// increase_using_pointer_notation(array_ptr,size);
// increase_using_array_notation(array_ptr, size);
// that will increase the value of each element by 2;
//
// run and test