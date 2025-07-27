# ✊🖐✌️ Rock-Paper-Scissors – C++ Console Game

A simple but well-structured Rock Paper Scissors game built in **C++**, emphasizing clean code practices, use of `enum`, `struct`, and a functional programming approach.

---

## 🚀 Features

- 🎮 Console-based interactive gameplay
- 🔁 Play multiple rounds (1 to 10 per game)
- 👤 vs 🤖 (Player vs Computer)
- 🧠 Smart use of functions to keep logic modular
- 🌈 Colored screen feedback for win/lose/draw
- 📊 Summary of results at the end of each game

---

## 🧠 Key Concepts

### ✅ Functional Programming Style

- Logic is split into **pure functions** like:
  - `ReadPlayerChoice()`
  - `WhoWonTheRound()`
  - `PlayGame()`
  - `WriteFinalWinner()`

### 🧱 `struct` Usage

- `stRoundInfo` – tracks each round's data
- `stGameResult` – holds the final game result summary

### 🎭 `enum` Usage

- `enGameChoice` – for player/computer choice (`Rock`, `Paper`, `Scissors`)
- `enWinner` – for winner (`Player`, `Computar`, `Draw`)

---

