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
    string currentDate(buffer);

    // Specify the file path where you want to read and save the JSON data
    string filePath = "C:yourfilepath";

    // Check if data for the current date exists
    ifstream inputFile(filePath);
    string currentData((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close(); // Close the file after reading

    if (currentData.find(currentDate) != std::string::npos) {
        char userChoice;
        cout << "Data for the date " << currentDate << " already exists! Would you like to edit the current data? (Y/N): ";
        cin >> userChoice;

        // If user doesn't want to edit, exit the program
        if (userChoice == 'N' || userChoice == 'n') {
            cout << "Exiting program." << endl;
            return 0;
        }

        size_t pos = 0;
        while ((pos = currentData.find(currentDate, pos)) != std::string::npos) {
            size_t start = currentData.rfind('{', pos);
            size_t end = currentData.find('}', pos);
            if (start != std::string::npos && end != std::string::npos) {
                // Check for newline character immediately after '}'
                if (end + 1 < currentData.size() && currentData[end + 1] == '\n') {
                    end++;
                }
                currentData.erase(start, end - start + 1);  // Erase the entire JSON object including newline
                pos = start;  // Move the position to where the start was since the string has been altered
            }
            else {
                pos++;  // If for some reason the brackets are not found, just move to the next position
            }
        }

    }

        // Otherwise, continue with the existing flow of asking questions
    


    string jsonData = "";

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
        cout << "\nOn " << currentDate << ", you did not drink today, Woo Hoo! you saved money and your kidneys! be proud!" << endl;
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
        cout << "\nOn " << currentDate << ", you did not stretch today! body has left the chat to go on a vacation from you since your so bad!" << endl;
        jsonData += "{\"date\":\"" + currentDate + "\",";
        jsonData += "\"stretched\":\"No\"}\n";
    }

    ofstream outputFile(filePath);

    if (outputFile.is_open()) {
        // Write the existing data minus the removed data
        outputFile << currentData;

        // Append the new data
        outputFile << jsonData;

        outputFile.close();
        cout << "Data has been saved to output.json " << endl;
    }
    else {
        cerr << "Error: Unable to open the file for writing." << endl;
    }

    return 0;
}
