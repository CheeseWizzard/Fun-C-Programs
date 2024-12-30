#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>    // For getenv()

// Function to create a file on the Desktop with the given name
void makeFile(const std::string& fileName) {
    // Get the Desktop path
    std::string desktopPath = std::string(getenv("HOME")) + "/Desktop/";

    // Combine the Desktop path with the file name
    std::string filePath = desktopPath + fileName;

    // Create and write to the file
    std::ofstream outFile(filePath);
    if (outFile) {
        outFile << R"(#include <iostream>
int main() {
    std::cout << "Hello from the generated C++ program!" << std::endl;
    return 0;
})";
        std::cout << "C++ file created: " << filePath << std::endl;
    } else {
        std::cerr << "Failed to create the C++ file: " << filePath << std::endl;
    }
}

int main() {
    // Example usage of makeFile function
    for(int i = 0; i < 100; i++){
        std::string text = "File: ";  // The base string

         // Convert the int to a string and concatenate
        std::string result = text + std::to_string(i); 
        makeFile(result); 
    }
    return 0;
}
