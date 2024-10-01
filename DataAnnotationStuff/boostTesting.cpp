#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/range/algorithm/find_if.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <regex>

// Example 1: Boost.Algorithm.String - Split a string
int main()
{
    std::string input_data = "Hello, World! How are you?";
    std::vector<std::string> tokens;

    boost::algorithm::split(tokens, input_data, boost::is_any_of(", !"));

    // Process the tokens
    for (const std::string &token : tokens)
    {
        std::cout << token << std::endl;
    }
    return 0;
}

// Example 2: Boost.Lexical_Cast - Convert between types (realistic: data parsing from file)
int parseEmployeeRecord(const std::string &record)
{
    std::vector<std::string> values;
    boost::algorithm::split(values, record, boost::is_any_of(","));

    try
    {
        int employeeId = boost::lexical_cast<int>(values[0]);
        std::string employeeName = values[1];
        double salary = boost::lexical_cast<double>(values[2]);

        // Process the parsed data...
        std::cout << "Employee ID: " << employeeId << ", Name: " << employeeName << ", Salary: " << salary << std::endl;
        return 0;
    }
    catch (const boost::bad_lexical_cast &e)
    {
        std::cerr << "Error parsing employee record: " << e.what() << std::endl;
        return 1;
    }
}

// Example 3: std::find_if with Boost.Function and Boost.Bind - Finding an element in a container (realistic: custom sorting)
struct Person
{
    std::string name;
    int age;
};
bool isAdult(const Person &p)
{
    return p.age >= 18;
}

int main()
{
    std::vector<Person> people = {
        {"Alice", 16}, {"Bob", 19}, {"Charlie", 12}, {"David", 21}};

    // Find the first adult using std::find_if with Boost.Function and Boost.Bind
    auto adultIt = std::find_if(people.begin(), people.end(), boost::bind(isAdult, _1));

    if (adultIt != people.end())
    {
        std::cout << "First adult found: " << adultIt->name << std::endl;
    }
    else
    {
        std::cout << "No adults found." << std::endl;
    }
    return 0;
}

// Example 4: Boost.Function - Creating and calling a function object (realistic: event handling)
class Button
{
public:
    boost::function<void()> click_event;

    void simulateClick()
    {
        if (click_event)
        {
            click_event(); // Call the registered function
        }
    }
};

int main()
{
    Button btn;

    // Register a function to be called when the button is clicked
    btn.click_event = []()
    {
        std::cout << "Button clicked!" << std::endl;
    };

    btn.simulateClick(); // Output: Button clicked!
    return 0;
}

// Example 5: Boost.Range::find_if - Finding an element in a range (realistic: data validation)
bool isValidEmail(const std::string &email)
{
    // Simple email validation regex (in real-world scenarios, use more robust libraries)
    const std::regex emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
    return std::regex_match(email, emailRegex);
}

int main()