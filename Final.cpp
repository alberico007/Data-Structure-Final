#include <iostream> // Include the iostream library for input/output
#include <ctime> // Include the ctime library for time-related functions
#include <cstdlib> // Include the cstdlib library for general purpose functions

using namespace std; // Use the standard namespace

int main() { // This is the start of the main function
    srand(time(0)); // This will make the random number generator with the current time

    int player_score = 0; // Initialize the player's score
    int dealer_score = 0; // Initialize the dealer's score

    int player_bet = 0; // Initialize the player's bet
    int dealer_bet = 0; // Initialize the dealer's bet

    int player_credit = 10000; // Start the player's credit with $10,000... the way it's displayed is 10000

    cout << "Welcome to MSE Casino." << endl; // This causes it to display a welcome message

    while (player_credit > 0) { // Continue the game as long as the player has credit
        cout << "Your current credit is: $" << player_credit << endl; // Display the player's current credit
        cout << "MSE Casino. Please place a wager: "; // Ask the player to place a wager
        cin >> player_bet; // Get the player's wager

        if (player_bet > player_credit) { // If the player's wager is more than their credit
            cout << "You don't have enough credit for this wager. Try again." << endl; // Tell them they don't have enough credit
            continue; // Skip the rest of the loop and start the next iteration
        }

        dealer_bet = player_bet; // The dealer's bet matches the player's bet
        cout << "Dealer's bet: " << dealer_bet << endl; // This will display the dealer's bet

        player_score = 0; // Reset the player's score
        dealer_score = 0; // Reset the dealer's score

        for (int i = 0; i < 2; i++) { // Deal two cards to each player
            player_score += rand() % 10 + 1; // This adds a random number between 1 and 10 to the player's score
            dealer_score += rand() % 10 + 1; // Add a random number between 1 and 10 to the dealer's score
        }

        cout << "Your score: " << player_score << endl; // Display the player's score
        cout << "Dealer's score: " << dealer_score << endl; // Display the dealer's score

        if (player_score == 21 && dealer_score == 21) { // If both the player and the dealer have blackjack
            cout << "It's a push! Both player and dealer have blackjack. No one wins the wager." << endl; // It's a push, no one wins
            continue; // Skip the rest of the loop and start the next iteration
        } else if (player_score == 21) { // If only the player has blackjack
            cout << "Blackjack! You win! You win 1.5 times the wager of " << dealer_bet << endl; // The player wins 1.5 times their wager
            player_credit += 1.5 * dealer_bet; // Add 1.5 times the wager to the player's credit
            continue; // Skip the rest of the loop and start the next iteration
        } else if (dealer_score == 21) { // If only the dealer has blackjack
            cout << "Dealer has blackjack! You lose! Dealer wins the wager of " << player_bet << endl; // The dealer wins the player's wager
            player_credit -= player_bet; // Subtract the wager from the player's credit
            continue; // Skip the rest of the loop and start the next iteration
        }

        char choice; // This declares a variable to hold the player's choice
        do { // Start a loop that continues as long as the player wants to draw a card and their score is 21 or less
            cout << "Do you want to draw another card? (y/n): "; // Ask the player if they want to draw another card
            cin >> choice; // Get the player's choice

            if (choice == 'y') { // If the player wants to draw another card
                player_score += rand() % 10 + 1; // Add a random number between 1 and 10 to the player's score
                cout << "Your score: " << player_score << endl; // Display the player's score
                if (player_score > 21) { // If the player's score is more than 21
                    cout << "You lose! Dealer wins the wager of " << player_bet << endl; // The dealer wins the player's wager
                    player_credit -= player_bet; // Subtract the wager from the player's credit
                    break; // Exit the loop
                }
            }
        } while (choice == 'y' && player_score <= 21); // End of the loop

        while (dealer_score < 17 && player_score <= 21) { // As long as the dealer's score is less than 17 and the player's score is 21 or less
            dealer_score += rand() % 10 + 1; // The dealer draws a card
            cout << "Dealer's score: " << dealer_score << endl; // Display the dealer's score
            if (dealer_score > 21) { // If the dealer's score is more than 21
                cout << "You win! You win the wager of " << dealer_bet << endl; // The player wins the dealer's wager
                player_credit += dealer_bet; // Add the wager to the player's credit
                break; // Exit the loop
            }
        }

        if (player_score > 21) { // If the player's score is more than 21
            cout << "You lose! Dealer wins the wager of " << player_bet << endl; // The dealer wins the player's wager
            player_credit -= player_bet; // Subtract the wager from the player's credit
        } else if (dealer_score > 21) { // If the dealer's score is more than 21
            cout << "You win! You win the wager of " << dealer_bet << endl; // The player wins the dealer's wager
            player_credit += dealer_bet; // Add the wager to the player's credit
        } else if (player_score > dealer_score) { // If the player's score is more than the dealer's score
            cout << "You win! You win the wager of " << dealer_bet << endl; // The player wins the dealer's wager
            player_credit += dealer_bet; // Add the wager to the player's credit
        } else if (dealer_score > player_score) { // If the dealer's score is more than the player's score
            cout << "You lose! Dealer wins the wager of " << player_bet << endl; // The dealer wins the player's wager
            player_credit -= player_bet; // Subtract the wager from the player's credit
        } else { // If the player's score is equal to the dealer's score
            cout << "It's a draw! No one wins the wager." << endl; // It's a draw, no one wins the wager
        }
    } // This marks the end of the while loop

    cout << "You've run out of money. Game over! Better Luck Next Time!" << endl; // Display a game over message when the player runs out of credit

    return 0; // End of the main function
} // This of our program