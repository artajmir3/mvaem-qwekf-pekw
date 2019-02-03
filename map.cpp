#include "map.h"
#include <stdlib.h>
#include "emptycell.h"
#include "minecell.h"

Map::Map(Player *active_player, QWidget *window, int width, int height/*, vector<vector<bool>> layout*/):
    cells(width, vector<Cell*>(height, nullptr))
{
    this->active_player = active_player;
    this->window = window;
    this->width = width;
    this->height = height;

    for (int i = 0; i < this->width; i++){
        for (int j = 0; j < this->height; j++){
            int r = rand() %10;
            if(r < 8){
                cells[i][j] = new EmptyCell(window, i, j);
            }else{
                cells[i][j] = new MineCell(window, i, j);
            }
        }
    }

    for (int i = 0; i < this->width; i++){
        for (int j = 0; j < this->height; j++){
            Cell *up = nullptr;
            Cell *down = nullptr;
            Cell *right = nullptr;
            Cell *left = nullptr;
            if(i > 0){
                left = this->cells[i - 1][j];
            }
            if(j > 0){
                up = this->cells[i][j - 1];
            }
            if(i < this->width - 1){
                right = this->cells[i + 1][j];
            }
            if(j < this->height - 1){
                down = this->cells[i][j + 1];
            }
            this->cells[i][j]->setNeighbours(up, down, right, left);
        }
    }
}
