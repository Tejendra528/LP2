#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Chatbot: Hello! How can I help you?\n";

    while (true) {
        cout << "You: ";
        getline(cin, input);

        if (input == "hi" || input == "hello")
            cout << "Chatbot: Hello! How can I assist you?\n";
        else if (input == "bye")
        {
            cout << "Chatbot: Goodbye!\n";
            break;
        }
        else if (input.find("name") != string::npos)
            cout << "Chatbot: I'm a simple rule-based bot.\n";
        else
            cout << "Chatbot: Sorry, I didn't understand that.\n";
    }

    return 0;
}
