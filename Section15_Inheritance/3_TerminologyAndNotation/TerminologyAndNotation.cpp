/***
 * [Inheritance]
 * Terminology
 * 
 * Inheritance
 *  Process of creating new classes from existing classes 
 *  Reuse mechanism
 * 
 * Single Inheritance => When use inheritance to create a new class, there may be several classes involved. 
 *  A new class is created from another 'single' class
 * 
 * Multiple Inheritance
 *  A new class is created from two (or more) other classes
 * 
 * => The classes that are involved in the inheritance relationship also have terms associated with them. 
 * Base class (parent, super class)
 *  The class being extended or inherited from => This class is also referred to as the parent class or super class in the inheritance relationship
 * 
 * Derived class (child class, sub class) 
 *  The class being created from the Base class
 *  Will inherit attributes and operations from Base class => This class is also referred to as the child class or the subclass. You can see in the diagram, the commonly used notation used to express this inheritance relationship.
 *                                                            We draw a solid line between the base class and the derived class with a closed unfilled arrowhead or triangle pointing to the base class. This is a uml class diagram and can also show uch more information about the classes we're modeling.
 * Derived ------|> Base
 * 
 * => When we use classic or public inheritance, our derived classes are generally subtypes of their base classes. 
 * This implies an is a relationship. So a circle is a shape, a savings account is an account. 
 * Generalization is about combining similar classes into a single, more general class based on the class's common attributes. 
 * The more general class is obviously more abstract and can therefore potentially be reused more easily. Specialization is the opposite of generalization. 
 * This is about creating new classes from existing classes. And these new classes generally and attributes and operations to the already inherited ones. 
 * As programmers and designers, we use both generalization and specialization to create inheritance hierarchies. 
 * Inheritance hierarchies is how we organize our inheritance relationships so that we can more effectively organize and reuse our code.
 * "Is-A" relationship
 *  public inheritance
 *  Derived classes are sub-types of their Base classes
 *  Can use a derived class object wherever we use a base class object
 * 
 * Generalization
 *  Combining similar classes into a single, more general class based on common attributes
 * 
 * Specialization
 *  Creating new classes from existing classes proving more specialized attributes or operations
 * 
 * Inheritance or Class Hierarchies
 *  Organization of our inheritance relationships
 * 
 * <Section15_TerminologyAndNotation1.png>
 * In this example, we have classes a b c d, and e and we have public inheritance that is a relationship between derived and based classes
 * you can see that class a is not being derived from any other class. This class is often referred to as the root class in the hierarchy. 
 * B is derived from a, c is also derived from a, d is derived from c and e is derived from d. 
 * You can see the class hierarchy in the diagram. Notice that the higher up we go in the hierarchy, the more general our classes are.
 * And the lower we go in our hierarchy, the more specialized they are.
 * Also notice the is a relationships. In this example, b is an a. C is also an a since they're both derived from the class a, and e is a b because e is derived from class d. 
 * Now notice that e is also a c since inheritance is transitive. 
 * In fact, in this example, e is also an a. However, class b is not a c. There is no inheritance relationship directly between b and c. 
 * 
 * <Section15_TerminologyAndNotation2.png>
 * In this example, we have a root class person that's the most general or abstract class in this class hierarchy. 
 * You can see that student is derived from person. So a student is a person and inherits the attributes and operations of the person class.
 * we also see that employee is a person, and faculty staff and administrators are derived from employee, so they are employees. 
 * In fact, they're also persons. 
 * But notice that a student is not an employee in this class hierarchy. 
 * Also notice that the is a relationships are not bi-directional. 
 * For example, a person is not necessarily an employee because they could be a student. 
 * You can see how useful a class diagram can be since it provides a high level structural overview of the classes and the relationships. 
 * ***/