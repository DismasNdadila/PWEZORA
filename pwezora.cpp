#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "include/ascii_art_library.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <cstdlib>
#endif

struct TerminalSize {
    int width, height;
    TerminalSize(int w = 80, int h = 25) : width(w), height(h) {}
};

class ASCIIRenderer {
private:
    std::vector<std::string> artLines;
    TerminalSize terminalSize;
    
    void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }
    
    TerminalSize getTerminalSize() {
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return TerminalSize(csbi.srWindow.Right - csbi.srWindow.Left + 1,
                           csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
    #else
        return TerminalSize(80, 25); // Default size for non-Windows
    #endif
    }
    
    void displayArt() {
        terminalSize = getTerminalSize();
        
        int artHeight = artLines.size();
        int artWidth = 0;
        for (const auto& line : artLines) {
            artWidth = std::max(artWidth, static_cast<int>(line.length()));
        }
        
        int startY = std::max(0, (terminalSize.height - artHeight) / 2);
        int startX = std::max(0, (terminalSize.width - artWidth) / 2);
        
        clearScreen();
        
        // Add some top spacing
        for (int i = 0; i < startY; ++i) {
            std::cout << "\n";
        }
        
        // Display each line with proper centering
        for (const auto& line : artLines) {
            // Add left spacing
            for (int j = 0; j < startX; ++j) {
                std::cout << " ";
            }
            std::cout << line << "\n";
        }
        
        std::cout.flush();
    }
    
public:
    ASCIIRenderer() {
        artLines = ASCIIArtLibrary::getArt(ASCIIArtLibrary::PWEZORA_TEXT);
    }
    
    void render() {
        displayArt();
    }
};

int main() {
    ASCIIRenderer renderer;
    renderer.render();
    
    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    
    return 0;
}