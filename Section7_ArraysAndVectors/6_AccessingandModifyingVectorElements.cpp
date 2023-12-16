#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /***
     * [Accessing vector elements - array syntax]
     * Using the subscript operator. Thats the square brackets. Using the name of the vector, followed by the square brackets with the index of the vector element we want inside the square brackets
     * Remember that vector subscripting or indexing is the same as in arrays.
     * When using the subscript operator with a vector, no bounds checking will be done. You have to do it yourself as with array
     * 
     *      vector_name [element_index]
     *      test_scores[1]
     *  
     *      vector <int> test_scores {100,94,73,86,93};
     *      cout << "First score at index 0: " << test_scores[0] << endl;
     *      cout << "Second score at index 1: " << test_scores[1] << endl;
     *      cout << "Third score at index 2: " << test_scores[2] << endl;
     *      cout << "Fourth score at index 3: " << test_scores[3] << endl;
     *      cout << "Fifth score at index 4: " << test_scores[4] << endl;
     * 
     * We can also access vector elements using the "at" method of vector. Vector give you and element at a specific position which you provide inside the parentheses
     * 
     *      vector_name.at(element_index)
     *      
     *      text_scores.at(1)
     *  
     *      vector <int> test_scores {100,94,73,86,93};
     * 
     *      cin >> test_scores.at(0) << endl;
     *      cin >> test_scores.at(1) << endl;
     *      cin >> test_scores.at(2) << endl;
     *      cin >> test_scores.at(3) << endl;
     *      cin >> test_scores.at(4) << endl;
     * 
     *      test_score.at(0) = 90;  // assignment statement
     * 
     *      cout << "First score at index 0: " << test_scores.at(0) << endl;
     *      cout << "Second score at index 1: " << test_scores.at(1) << endl;
     *      cout << "Third score at index 2: " << test_scores.at(2) << endl;
     *      cout << "Fourth score at index 3: " << test_scores.at(3) << endl;
     *      cout << "Fifth score at index 4: " << test_scores.at(4) << endl;
     * 
     * [vectors grow]
     *  The vector has a method called push_back. Vector will automatically allocate the required space and adds a new element to the end of the vector
     *  All element must to be the same type so the element you add must be of the same type as all the other vector elements
     * 
     *      vector_name.push_back(element)
     * 
     *      vector <int> test_scores {100,95,99}; // size is 3
     *      
     *      test_scores.push_back(90);
     *      test_scores.push_back(40);
     * 
     * [What if you are out of bounds]
     *  Array never do bounds checking
     *  Many vector methods provide bounds checking
     *  An exception and error message is generated
     * 
     *  vector <int> test_scores {100,95};
     *  cin >> test_scores.at(5);
     * 
     *  terminate called after throwing an instance of 'std::out_of_range' what(): vector::_M_range_check: __n (which is 5) >= this->size() (which is 2)
     *  This application has requested the Runtime to terminate it in an unusual way. Please contact the application's support team for more information
     * **/

    // vector <char> vowels;       //empty
    // vector <char> vowels (5);   //5 initialized to zero
    vector <char> vowels{'a','e','i','o','u'};

    cout << vowels[0] << endl;
    cout << vowels[4] << endl;

    // vector <int> test_scores (3);       // 3 elements all initialized to zero
    // vector <int> test_scores (3,100);   // 3 elements all initialized to 100

    vector <int> test_scores {100, 95,23};

    cout << "\nTest scores using array syntax: " << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;

    cout << "\nTest scores using vector syntax." << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "\nThere are " <<test_scores.size() << " scores in the vector." << endl;

    cout << "\nEnter 3 test scores:";
    cin >> test_scores.at(0);
    cin >> test_scores.at(1);
    cin >> test_scores.at(2);

    cout << "\nUpdated test scores: " << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;

    cout << "\nEnter a test score to add to the vector: ";

    int score_to_add {0};
    cin >> score_to_add;

    test_scores.push_back(score_to_add);

    cout << "\nEnter one more test score to add to the vector: ";

    cin >> score_to_add;
    
    test_scores.push_back(score_to_add);

    cout << "\nTest scores are now: " << endl;

    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;
    cout << test_scores.at(4) << endl;

    cout << "\nThere are " <<test_scores.size() << " scores in the vector." << endl;

    // cout << "This should cause an exception!" << test_scores.at(10);

    //Example of a 2D-vector
    vector <vector<int>> movie_ratings
    {
        {1,2,3,4},
        {2,3,4,5},
        {3,4,5,6}
    };

    cout << "\nHere are the movie rating for reviewer #1 using array syntax: " << endl;
    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings[0][1] << endl;
    cout << movie_ratings[0][2] << endl;
    cout << movie_ratings[0][3] << endl;

    cout << "\nHere are the movie rating for reviewer #1 using vector syntax: " << endl;
    cout << movie_ratings.at(0).at(0) << endl;
    cout << movie_ratings.at(0).at(1) << endl;
    cout << movie_ratings.at(0).at(2) << endl;
    cout << movie_ratings.at(0).at(3) << endl;
    return 0;
}