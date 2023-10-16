#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    // Variable to store the user input.
    string programmingToday;
    string workoutToday;
    string drankToday;
    string stretchToday;

    // Get the current date
    time_t currentTime;
    struct tm timeInfo;
    char buffer[80];

    time(&currentTime);
    localtime_s(&timeInfo, &currentTime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeInfo);

    std::string jsonData = "";

    // Convert the date to a string
    string currentDate(buffer);

    // Ask the user if they programmed today.
    cout << "Did you program today? (Y/N) " << endl;
    cin >> programmingToday;

    if (programmingToday == "Y" || programmingToday == "y") {
        string programmingDuration;

        // Ask the user how long they programmed for.
        cout << "How long did you program for? Input format example: 1 hour, 1 hour 30 minutes, 1 hour 31 minutes, etc." << endl;
        cin.ignore(); // Clear the newline character left in the input buffer
        getline(cin, programmingDuration);

        // Process the input and display the current date
        cout << "\nOn " << currentDate << ", you programmed for: " << programmingDuration << endl;
        jsonData += "{\"date\":\"" + currentDate + "\",";
        jsonData += "\"programmed\":\"Yes\",";
        jsonData += "\"duration\":\"" + programmingDuration + "\"}\n";
    }
    else {
        cout << "\nOn " << currentDate << ", you did not program today." << endl;
        jsonData += "{\"date\":\"" + currentDate + "\",";
        jsonData += "\"programmed\":\"No\"}\n";
    }

     // Ask the user if they worked out today.
    cout << "Did you workout today? (Y/N) " << endl;
    cin >> workoutToday;

    if (workoutToday == "Y" || workoutToday == "y") {
        string workoutDuration;

        // Ask the user how long they worked out for.
        cout << "How long did you work out for?" << endl;
        cin.ignore(); // Clear the newline character left in the input buffer
        getline(cin, workoutDuration);

        // Process the input and display the current date
        cout << "\nOn " << currentDate << ", you worked out for: " << workoutDuration << endl;
        jsonData += "{\"date\":\"" + currentDate + "\",";
        jsonData += "\"worked out\":\"Yes\",";
        jsonData += "\"duration\":\"" + workoutDuration + "\"}\n";
    }
    else {
        cout << "\nOn " << currentDate << ", you did not work out today." << endl;
        jsonData += "{\"date\":\"" + currentDate + "\",";
        jsonData += "\"worked out\":\"No\"}\n";
    }

    // Ask the user if they drank alcohol today.
    cout << "Did you drink alcohol today? (Y/N) " << endl;
    cin >> drankToday;

    if (drankToday == "Y" || drankToday == "y") {
        string alcoholPrice;

        // Ask the user how much they spent on drinking.
        cout << "How much did you spend on drinking?" << endl;
        cin.ignore(); // Clear the newline character left in the input buffer
        getline(cin, alcoholPrice);

        // Process the input and display the current date
        cout << "\nOn " << currentDate << ", you spent this much on alcohol: " << alcoholPrice << endl;
        jsonData += "{\"date\":\"" + currentDate + "\",";
        jsonData += "\"drank alcohol\":\"Yes\",";
        jsonData += "\"price\":\"" + alcoholPrice + "\"}\n";
    }
    else {
        cout << "\nOn " << currentDate << ", you did not drink today!" << endl;
        jsonData += "{\"date\":\"" + currentDate + "\",";
        jsonData += "\"drank alcohol\":\"No\"}\n"; 
    }
    // Ask the user if they stretched today.
    cout << "Did you stretch today? (Y/N) " << endl;
    cin >> stretchToday;

    if (stretchToday == "Y" || stretchToday == "y") {
        string stretchTimes;

        // Ask the user how many times did they stretch.
        cout << "How many times did you stretch?" << endl;
        cin.ignore(); // Clear the newline character left in the input buffer
        getline(cin, stretchTimes);

        // Process the input and display the current date
        cout << "\nOn " << currentDate << ", you stretched this many times: " << stretchTimes << endl;
        jsonData += "{\"date\":\"" + currentDate + "\",";
        jsonData += "\"stretched\":\"Yes\",";
        jsonData += "\"times stretched\":\"" + stretchTimes + "\"}\n";
    }
    else {
        cout << "\nOn " << currentDate << ", you did not stretch today" << endl;
        jsonData += "{\"date\":\"" + currentDate + "\",";
        jsonData += "\"stretched\":\"No\"}\n";
    }

    // Specify the file path where you want to save the JSON data
    string filePath = "C:/Users/JaredM/Desktop/C++ Projects/Project_1_Saving_Data_to_a_JSON_File/json/output.json";

    // Open the file for writing
    ofstream outputFile(filePath);

    // Check if the file is opened successfully
    if (outputFile.is_open()) {
        // Write the JSON data to the file
        outputFile << jsonData;

        // Close the file
        outputFile.close();

        cout << "Data has been saved to output.json " << endl;
    }
    else {
        cerr << "Error: Unable to open the file for writing." << endl;
    }

    return 0;
}
