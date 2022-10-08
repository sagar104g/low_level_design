/*
Board can be of any size Each player puts their counter on the board starting position.
Take it in turns to roll the dice.
Move your counter forward the number of spaces shown on the dice.
If your counter lands at the bottom of a ladder, you can move up to the top of the ladder.
If your counter lands on the head of a snake, you must slide down to the bottom of the snake.
Each player will get a fair chance to roll the dice.
Game is continued till there are two players left.
When user roles dice and not reaching the destination i.e when the user is in poisiton 99 and rolling of dice yields any number more than one the user remains in the same poistion.
*/
#include<bits/stdc++.h>
using namespace std;

class SnakeAndLadder {
    private:
        vector<Game*> games;
        vector<Player> players;

    public:
        void createGame() {


            Game *game = new Game();
        }
};

class Game {
    private:
        long id;
        Board *board;
        vector<Player> players;
        Player currentPlayer;
        Dice *dice;
    public:
        Game() {}
        void CreateGame(int boardLength, int boardWidth, vector<Player> players, vector<Varities> varities) {
            this->board = new Board(boardLength, boardWidth, varities);

            for (int playerIterator = 0; playerIterator< players.size(); playerIterator++) {
                this->players.push_back(players[playerIterator]);
            }
            if (players.size() > 0) {
                this->currentPlayer = players[0];
            }
            this->dice = new Dice();
        }

        Board* getBoard() {
            return board;
        }

        Dice* getDice() {
            return dice;
        }

        vector<Player> getPlayer() {
            return players;
        }

        Cell checkForVarities(Cell cell) {

        };

        Cell buildCell (int count) {

        }

        bool isCellValid (Cell cell) {

        }

        void movePlayer(int playerId, int count) {
            for (int playerIterator = 0; playerIterator < this->players.size(); playerIterator++) {
                if (this->players[playerIterator].getPlayerId() == playerId) {
                    Cell cell = buildCell(count);
                    bool isCellValid = this->isCellValid(cell);
                    if (isCellValid) {
                        Cell cell = this->checkForVarities(cell);
                        players[playerIterator].updateCurrentPosition(cell);
                        currentPlayer = players[playerIterator+1];
                    }
                }
            }
            
        }
};

class Board {
    private:
        int length;
        int width;
        vector<Varities> varities;
    public:
    Board(int boardLength, int boardWidth, vector<Varities> varities) {
        this->length = boardLength;
        this->width = boardWidth;
        for (int varitiesIterator = 0; varitiesIterator< varities.size(); varitiesIterator++) {
            this->varities.push_back(varities[varitiesIterator]);
        }
    }
};

class Cell {
    private:
        int x;
        int y;
};

class Varities {
    private:
        Cell start;
        Cell end;
    
};

class Player {
    private:
        int id;
        Cell currentPosition;
        string status;
        string userName;
        string color;
    public:
        int getPlayerId() {
            return this->id;
        }

        void updateCurrentPosition(Cell cell) {

            this->currentPosition = cell;
        }
};

class Dice {
    public:
        Dice() {}
        int getNumber() {
            return (rand() % 6) + 1;
        }
};