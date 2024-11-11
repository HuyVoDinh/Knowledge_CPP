/****
 * [Inheritance]
 * Public Inheritance vs. Composition
 * => Public inheritance creates an is a relationship between the derived and based classes. And with inheritance, we automatically inherit all of our base classes attributes and operations. 
 * 
 * 
 * Both allow reuse of existing classes
 * 
 * Public Inheritance 
 *  "is-a" relationship
 *      Employee "is-a" Person
 *      Checking Account "is-a" Account
 *      Circle "is-a" Shape
 * 
 * => However, sometimes we want to reuse existing classes, but the is a relationship really doesn't apply. 
 * For example, suppose that all persons have an account. I can't really say that  person is an account or an account is a person since that doesn't make sense. 
 * Instead, we can use composition to model this relationship. Composition creates a has a relationship between classes. 
 * For example, a person has an account, a player has a special attack, a circle has a location. 
 * using a combination of inheritance and composition, we can express complex relationships between classes and leverage code reuse. 
 * 
 * Composition
 *  "has-a" relationship
 *      Person "has a" Account
 *      Player "has-a" Special Attack
 *      Circle "has-a" Location
 * 
 * <Section15_InheritanceVsComposition1.png>
 * We have the person hierarchy we saw earlier. Note the inheritance relationships are modeled with the triangle pointing to the base class of the relationship. 
 * As we mentioned in the last slide, it wouldn't make sense to introduce another inheritance relationship between person and account since the is a relationship just doesn't apply. 
 * So we use composition instead. Notice the association between person and account. It;s modeled as a solid line, no inheritance triangle this time. 
 * UML provides several different types of notations to model associated classes that don't have an inheritance relationship. These are aggregation, association and composition. 
 * In this section, we'll use the term composition to simply mean it has a relationship, and we won't be concerned about whether the account object can logically exist without being associated with a person object. 
 * So what we're describing here is that a person has an account, that's exactly what we want.  So does a student also have an account.  Because a student is a person. 
 * What about a faculty member. Because a faculty member is a person. Notice that we create the association at the most general class in the hierarchy where it applies since it will also apply to its derived classes. 
 * We've actually been using composition all along. When we model class data members, we're using composition. Many times the instance variables are primitive types, so we don't include them in class diagrams, but the concept is the same. 
 * So when do you choose inheritance over composition. Many times it's easy to decide if the is a relationship doesn't make sense, then don't use public inheritance. 
 * Other times it's not so clear. A rule of thumb when using inheritance is to step back look at your design and be sure that the inheritance is appropriate.
 * If you can model a relationship with composition, then you should consider doing that first since inheritance adds more complexity to your design. 
 * In this case, an inheritance relationship between student and account simply doesn't make sense, so we use composition.
 * 
 * Composition
 * 
 * class Person {
 *  private:
 *      std::string name;       //has-a name
 *      Account account;        //has-a account
 * }; 
 * => Composition is a common design pattern for reuse and you'll see it used much more frequently than inheritance. But we can use both inheritance and composition together to create powerful frameworks that allow us to reuse existing code. 
 * ***/