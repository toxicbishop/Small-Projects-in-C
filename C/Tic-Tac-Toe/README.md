# Tic-Tac-Toe Game

A classic Tic-Tac-Toe game implemented in C with two exciting game modes!

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
  - Input validation
  - Win/Draw detection

## How to Play

1. **Compile the program:**

   ```bash
   gcc tic-tac-toe.c -o tic-tac-toe
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

## Example Gameplay

```text
     |     |     
  X  |  O  |  X  
_____|_____|_____
     |     |     
  O  |  X  |     
_____|_____|_____
     |     |     
     |  O  |     
     |     |     
```

## Learning Concepts

- Multi-dimensional arrays (2D board)
- Game state management
- AI algorithm (minimax-like strategy)
- Functions and modular programming
- Input validation
- Win condition checking

Enjoy the game! 🎮
