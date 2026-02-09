# Tic-Tac-Toe Game (C++)

A classic Tic-Tac-Toe game implemented in C++ using Object-Oriented Programming principles!

## Features

- 🎮 **Two Game Modes:**
  - Player vs Player (local multiplayer)
  - Player vs Computer (with smart AI)

- 🤖 **Smart Computer AI:**
  - Tries to win when possible
  - Blocks opponent from winning
  - Uses strategic positioning (center, corners)

- ✨ **User-Friendly Interface:**
  - Clear visual board display
  - Position numbers for easy input (1-9)
  - Robust input validation
  - Win/Draw detection

- 🏗️ **OOP Design:**
  - Encapsulated TicTacToe class
  - Clean separation of concerns
  - Uses STL vectors for board management

## How to Play

1. **Compile the program:**

   ```bash
   g++ tic-tac-toe.cpp -o tic-tac-toe
   ```

2. **Run the game:**

   ```bash
   ./tic-tac-toe        # Linux/Mac
   tic-tac-toe.exe      # Windows
   ```

3. **Game Instructions:**
   - Choose game mode (1 or 2)
   - Enter position numbers (1-9) to place your mark
   - First player to get 3 in a row wins!

## Board Layout

```text
  1 | 2 | 3
  4 | 5 | 6
  7 | 8 | 9
```

## Code Structure

```cpp
class TicTacToe {
    - Game board (vector<vector<char>>)
    - Display methods
    - Move validation
    - AI logic
    - Win checking
    - Main game loop
}
```

## Learning Concepts

- Object-Oriented Programming (classes, encapsulation)
- STL containers (vectors)
- Game state management
- AI algorithm implementation
- Input validation and error handling
- Method organization

Enjoy the game! 🎮
