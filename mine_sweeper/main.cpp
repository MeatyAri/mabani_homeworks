#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>


enum Menu { MainMenu, GameMenu };
enum PlayerState { Won, GameOver, MidGame };

struct GmenuResp {
    bool menu_resp;
    std::string coordinate;
};
struct stdCoordinate {
    int row, column;
};
struct MinesweeperBoard {
    std::vector<std::vector<char>> hidden_board;
    std::vector<std::vector<char>> player_board;
};

int x_dim=10, y_dim=10, mines_num=10;
PlayerState player_state = MidGame;

void display_menu(Menu menu);
bool main_menu_handler();
MinesweeperBoard generate_board(size_t, size_t, size_t);
GmenuResp game_menu_handler();
void draw_board(const std::vector<std::vector<char>>&);
stdCoordinate process_coordinate(std::string);
void flag(MinesweeperBoard&, stdCoordinate);
void choose_cell(MinesweeperBoard&, stdCoordinate);
void check_neighbors(MinesweeperBoard&, stdCoordinate);
void make_a_move(MinesweeperBoard&, GmenuResp);
void check_victory();
void play_game(MinesweeperBoard&);


int main() {
    display_menu(MainMenu);
    if (main_menu_handler()) {
        // initialize the board and the player
        MinesweeperBoard board = generate_board(x_dim, y_dim, mines_num);

        play_game(board);
    }
    return 0;
}


void display_menu(Menu menu) {
    switch (menu)
    {
    case MainMenu:
        std::cout << "1- Play the game, 2- Exit (P/e)? ";
        break;
    
    case GameMenu:
        std::cout << "1- Insert/remove a flag, 2- Choose a cell (i/C)? ";
        break;
    }
}


bool main_menu_handler() {
    char inp;
    std::cin >> inp;
    std::cout << '\n';

    switch (inp)
    {
    case 'P':
    case 'p':
        std::cout << "Entering the game.\n";
        return 1;
    
    case 'e':
        std::cout << "Exiting the game...";
        exit(0);
    
    default:
        return 1;
    }
}


MinesweeperBoard generate_board(size_t rows, size_t columns, size_t mines) {
    std::vector<std::vector<char>> player_board(rows, std::vector<char>(columns, '.'));
    std::vector<std::vector<char>> hidden_board(rows, std::vector<char>(columns, '.'));
    std::vector<char> flat_board(rows * columns, '.');

    for (int i = 0; i < mines; i++) {
        flat_board[i] = '*';
    }

    // Use a random seed
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(flat_board.begin(), flat_board.end(), g);

    auto it = flat_board.begin();
    for (auto& row : hidden_board) {
        for (auto& element : row) {
            element = *it++;
        }
    }

    MinesweeperBoard board;
    board.player_board = player_board;
    board.hidden_board = hidden_board;
    return board;
}


GmenuResp game_menu_handler() {
    char inp;
    bool menu_resp;
    std::cin >> inp;
    std::cout << '\n' << "Enter the coordinates of the cell: ";

    switch (inp)
    {
    case 'c':
    case 'C':
        menu_resp = 1;
        break;

    case 'i':
        menu_resp = 0;
        break;
    
    default:
        menu_resp = 1;
        break;
    }

    std::string coordinate;
    std::cin >> coordinate;

    GmenuResp gmenu_resp;
    gmenu_resp.menu_resp = menu_resp;
    gmenu_resp.coordinate = coordinate;
    return gmenu_resp;
}


void draw_board(const std::vector<std::vector<char>>& board) {
    std::cout << "info: Bombs=" << mines_num << '\n' << std::endl;
    std::cout << "    ";
    for (size_t i = 0; i < board[0].size(); i++) {
        std::cout << " " << static_cast<char>('a' + i) << "  ";
    }
    std::cout << std::endl;

    std::cout << "   +";
    for (size_t i = 0; i < board[0].size(); i++) {
        std::cout << "---+";
    }
    std::cout << std::endl;

    for (size_t rowIdx = 0; rowIdx < board.size(); rowIdx++) {
        std::cout << (rowIdx + 1 < 10 ? " " : "") << rowIdx + 1 << " |";
        for (char cell : board[rowIdx]) {
            std::cout << " " << cell << " |";
        }
        std::cout << std::endl;

        std::cout << "   +";
        for (size_t i = 0; i < board[rowIdx].size(); i++) {
            std::cout << "---+";
        }
        std::cout << std::endl;
    }
}


stdCoordinate process_coordinate(std::string coordinate) {
    stdCoordinate result;
    int alpha_index;

    if (coordinate.length() < 2) {
        // invalid coordinate
        result.row = result.column = -1;
        return result;
    }

    for (int i = 0; i < coordinate.length(); i++) {
        if (std::isalpha(coordinate[i])) {
            alpha_index = i;
            break;
        }
    }

    if (alpha_index == 0) {
        result.row = std::stoi(coordinate.substr(1)) - 1;
        result.column = coordinate[0] - 'a';
    }
    else {
        result.row = std::stoi(coordinate.substr(0, alpha_index)) - 1;
        result.column = coordinate[alpha_index] - 'a';
    }

    return result;
}


void flag(MinesweeperBoard& board, stdCoordinate flag_coordinate) {
    char& target = board.player_board[flag_coordinate.row][flag_coordinate.column];
    if (target == '.') {
        target = '#';
        mines_num--;
    } else if (target == '#') {
        target = '.';
        mines_num++;
    } else {
        std::cout << "Can't insert a flag here\n";
    }
}


void check_neighbors(MinesweeperBoard& board, stdCoordinate cell_coordinate) {
    stdCoordinate neighbour;
    for (int i=(cell_coordinate.row-1 < 0 ? 0 : cell_coordinate.row-1); i <= (cell_coordinate.row+1 > y_dim-1 ? y_dim-1 : cell_coordinate.row+1); i++) {
        for (int j=(cell_coordinate.column-1 < 0 ? 0 : cell_coordinate.column-1); j <= (cell_coordinate.column+1 > x_dim-1 ? x_dim-1 : cell_coordinate.column+1); j++) {
            neighbour.row = i;
            neighbour.column = j;
            if (board.player_board[i][j] == '.') {
                choose_cell(board, neighbour);
            }
        }
    }
}


void choose_cell(MinesweeperBoard& board, stdCoordinate cell_coordinate) {
    // std::cout << "chosen cell: " << cell_coordinate.row << ' ' << cell_coordinate.column << '\n';
    char& ground_truth = board.hidden_board[cell_coordinate.row][cell_coordinate.column];
    char& target = board.player_board[cell_coordinate.row][cell_coordinate.column];


    if (target == '.'){
        if (ground_truth == '*') {
            player_state = GameOver;
            draw_board(board.hidden_board);
            std::cout << "Unfortunately you lost the game!\n";
        }
        else {
            int nearby_mines = 0;
            for (int i=(cell_coordinate.row-1 < 0 ? 0 : cell_coordinate.row-1); i <= (cell_coordinate.row+1 > y_dim-1 ? y_dim-1 : cell_coordinate.row+1); i++) {
                for (int j=(cell_coordinate.column-1 < 0 ? 0 : cell_coordinate.column-1); j <= (cell_coordinate.column+1 > x_dim-1 ? x_dim-1 : cell_coordinate.column+1); j++) {
                    if (board.hidden_board[i][j] == '*') {
                        nearby_mines++;
                    }
                }
            }
            // std::cout << "nearby mines: " << nearby_mines << '\n';
            target = std::to_string(nearby_mines)[0];
            if (nearby_mines == 0) {
                check_neighbors(board, cell_coordinate);
            }
        }

    }
}


void make_a_move(MinesweeperBoard& board, GmenuResp gmenu_resp) {
    stdCoordinate std_coordinate = process_coordinate(gmenu_resp.coordinate);
    if (std_coordinate.row == -1) {
        // invalid coordinate
        std::cout << "coordinate_Error\n";
    }
    else {
        if (!gmenu_resp.menu_resp) {
            // insert flag
            flag(board, std_coordinate);
        }
        else {
            // normal choosen cell
            choose_cell(board, std_coordinate);
        }
    }
}


void check_victory() {
    if (mines_num == 0) {
        player_state = Won;
        std::cout << "Congrats! YOU WON THE GAME!";
    }
}


void play_game(MinesweeperBoard& board) {
    while (player_state == MidGame) {
        draw_board(board.player_board);
        display_menu(GameMenu);
        GmenuResp gmenu_resp = game_menu_handler();
        make_a_move(board, gmenu_resp);
        check_victory();
    }
}
