#include <iostream>
#include <string>
#include "database_simulated.h"  

void displayMenu() {
    std::cout << "\n=== Real-Time Leaderboard System (Simulated) ===\n";
    std::cout << "1. Register\n";
    std::cout << "2. Login\n";
    std::cout << "3. Submit Score\n";
    std::cout << "4. View Global Leaderboard\n";
    std::cout << "5. View My Rank\n";
    std::cout << "6. View Top Players\n";
    std::cout << "7. View Game Leaderboard\n";  
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    DatabaseSimulated db;  
    std::string currentUser = "";
    std::string currentGame = "";
    
    if (!db.connect()) {
        std::cerr << "Failed to connect to database!" << std::endl;
        return 1;
    }
    
    if (!db.ping()) {
        std::cerr << "Database is not responding!" << std::endl;
        return 1;
    }
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); 
        
        switch (choice) {
            case 1: { 
                std::string username, password;
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                
                db.registerUser(username, password);
                break;
            }
            
            case 2: { 
                std::string username, password;
                std::cout << "Enter username: ";
                std::getline(std::cin, username);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                
                if (db.loginUser(username, password)) {
                    currentUser = username;
                }
                break;
            }
            
            case 3: { 
                if (currentUser.empty()) {
                    std::cout << "Please login first!" << std::endl;
                    break;
                }
                
                std::string game;
                int score;
                
                std::cout << "Enter game name: ";
                std::getline(std::cin, game);
                std::cout << "Enter score: ";
                std::cin >> score;
                std::cin.ignore();
                
                db.submitScore(currentUser, game, score);
                currentGame = game;  
                break;
            }
            
            case 4: { 
                std::cout << db.getGlobalLeaderboard() << std::endl;
                break;
            }
            
            case 5: { 
                if (currentUser.empty()) {
                    std::cout << "Please login first!" << std::endl;
                    break;
                }
                
                std::cout << db.getUserRank(currentUser) << std::endl;
                if (!currentGame.empty()) {
                    std::cout << db.getUserRank(currentUser, currentGame) << std::endl;
                }
                break;
            }
            
            case 6: { 
                std::cout << db.getTopPlayers() << std::endl;
                break;
            }
            
            case 7: { 
                if (currentGame.empty()) {
                    std::cout << "Please submit a score first to set current game!" << std::endl;
                    std::cout << "Enter game name: ";
                    std::getline(std::cin, currentGame);
                }
                std::cout << db.getUserRank(currentUser, currentGame) << std::endl;
                break;
            }
            
            case 8: { 
                running = false;
                db.disconnect();
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    
    return 0;
}