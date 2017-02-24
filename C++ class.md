# class
## basics
* The keyword this (the pointer of current object)
* Overloading constuctor / operators
* Class templates / Template specialization
```C++
// class template:
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {element=arg;}
    T increase () {return ++element;}
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};
```
* Classes can be defined not only with keyword class, but also with keywords struct and union
    * members of classes declared with the keyword struct have _public_ access by default
    * members of classes declared with the keyword class have _private_ access by default

## Special Members
Member function	|typical form for class C |implicitly defined |	default definition
----------------|-------------------------|-------------------|--------------------
Default constructor	|C::C();|if no other constructors |	does nothing
Destructor	|C::~C();|if no destructor	|does nothing
Copy constructor	|C::C (const C&);|	if no move constructor and no move assignment|	copies all members
Copy assignment	| C& operator= (const C&);|	if no move constructor and no move assignment|	copies all members
Move constructor |	C::C (C&&);|	if no destructor, no copy constructor and no copy nor move assignment|	moves all members
Move assignment |	C& operator= (C&&);|	if no destructor, no copy constructor and no copy nor move assignment|moves all members
* constructor
    * functional form
    * member initialization
    ```
    Rectangle::Rectangle (int x, int y) : width(x), height(y) { }
    ```
    * constructors with a single parameter can be called using the variable initialization syntax
    ```
    Circle bar = 20.0;
    ```
* Attenions
    * as soon as a class has some constructor taking any number of parameters explicitly declared, the compiler no longer provides an implicit default constructor, and no longer allows the declaration of new objects of that class without arguments
    * the implicit copy constructor/assignment is automatically defined, but only performs a shallow copy
    * using the keywords default and delete to select explicitly whether default special members exist
    
## friendship 
* friend keyword : allow access from outside of class
* friend class
    * at the beginning of the program, there is an empty declaration of class Square. This is necessary because class Rectangle uses Square (as a parameter in member convert), and Square uses Rectangle (declaring it a friend)
    * allow to access private and protected members
    * not corresponded unless specified (A is B's friend class doesn't imple B is A's friend class)
    * not transitive: The friend of a friend is not considered a friend unless explicitly specified
```C++
class Square; //needed
class Rectangle {
    int width, height;
  public:
    int area ()
      {return (width * height);}
    void convert (Square a){
        width = a.side;
        height = a.side;
    }
};
class Square {
  friend class Rectangle;
  private:
    int side;
  public:
    Square (int a) : side(a) {}
};
```

## inheritance
* What is inherited from the base class?
    * a publicly derived class inherits access to every member of a base class except:
        * its constructors and its destructor
        * its assignment operator members (operator=)
        * its friends
        * its private members
    * attentions
        * Even though access to the constructors and destructor of the base class is not inherited as such, they are automatically called by the constructors and destructor of the derived class
        * Unless otherwise specified, the constructors of a derived class calls the default constructor of its base classes
        ```
        derived_constructor_name (parameters) : base_constructor_name (parameters) {...}
        ```
            
* accessibility of members from base class
    * with public, the derived class will inherit all the members with the same levels they had in the base class
    * with protected, all public members of the base class are inherited as protected in the derived class
    * with private, all the base class members are inherited as private
   
* Pointers to base class
    * a pointer to a derived class is type-compatible with a pointer to its base class
    ```C++
    Rectangle rect; //Rectangle/Triangele are derived classes from Polygon
    Triangle trgl;
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    ```
    * attentions
        * ppoly1, ppoly2 can only access the members inherited from Polygon, and not those of the derived classes Rectangle and Triangle

* Virtual members
    * can be redefined in a derived class
    * preserve its calling properties through references (_polymorphic_)
    * Non-virtual members can also be redefined in derived classes, but non-virtual members of derived classes cannot be accessed through a reference of the base class

* Abstract base classes
    * pure virtual function     
    ```
    virtual int area () =0;
    ```
    * cannot be used to instantiate objects
    * can be used to create pointers, and take advantage of all its polymorphic abilities

## static and const
* Static members
    * known as a "class variable, share the same value for all objects
    * cannot be initialized directly in the class, but need to be initialized somewhere outside it
    * can be refered directly by the class name
    ```
    class Dummy {
    public:
        static int n;
    };
    int Dummy::n=0;
    ```
* Const object
    * The access to its data members from outside the class is restricted to read-only
    * The member functions of a const object can only be called if they are themselves specified as const members    
```
const MyClass myobject;
```
* const member function
    * Member functions specified to be const cannot modify non-static data members nor call other non-const member functions
    * In essence, const members shall not modify the state of an object
```
int get() const {return x;}        // const member function
const int& get() {return x;}       // member function returning a const&
const int& get() const {return x;} // const member function returning a const&
```      
