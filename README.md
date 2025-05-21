Some C++ OOPC concepts used are:

1.Classes and Objects
  Defined multiple classes: Student, Marks, Result, and student_system.
  Each class represents a real-world entity, encapsulating related data and functions.

2.Inheritance
  Marks class inherits from Student using public virtual inheritance.
  student_system class inherits from Student, Marks, and Result.
  This shows multiple inheritance and virtual inheritance to avoid the diamond problem.

3.Encapsulation
  Data members like id, name, qp, oopc, etc., are marked private, and access is given via public methods.
  This hides the internal state of the objects and provides controlled access.

4.Abstraction
  The user interacts with the system through high-level methods like menu(), getinfo(), display_list(), etc., without needing to know internal details.
  Implementation details are abstracted away using functions. Menu driven interface is also a great example of abstraction.

5.Friend Class
  The class Result is declared as a friend of Marks.
  This allows Result to access private members of Marks, which is a controlled way of breaking encapsulation when necessary.  

6.Modular Class Design
  The system is broken into small, single-responsibility classes:
  Student: Identity
  Marks: Subject marks
  Result: Evaluation
  student_system: Control and integration
  This supports modular OOP design and better maintainability.

7.Object Interaction
  Result class interacts with a Marks object to calculate result.
  This demonstrates collaboration between classes — a key part of OOP design.
  
