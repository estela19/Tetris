#include <windows.h>
#include <stdexcept>

#include <Tetris/Game.h>
#include <Tetris/Point.h>
#include <Tetris/Screen.h>
#include <Tetris/tetrimino.h>

#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define DARK_BLUE SetConsoleTextAttribute(COL, 0x0001);
#define GREEN SetConsoleTextAttribute(COL, 0x0002);
#define PURPLE SetConsoleTextAttribute(COL, 0x0005);
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);
#define RED SetConsoleTextAttribute(COL, 0x000c);
#define PLUM SetConsoleTextAttribute(COL, 0x000d);
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);
#define ORIGINAL SetConsoleTextAttribute(COL, 0x0007);

namespace Tetris
{
void Screen::PrintBoard()
{
    // Print board struct
    for (std::size_t i = 0; i < Game::height_; i++)
    {
        Point::GotoScrXY(0, i);
        ORIGINAL std::cout << "��";
        Point::GotoScrXY(Game::scrwidth_, i);
        ORIGINAL std::cout << "��";
    }

    for (std::size_t i = 0; i <= Game::scrwidth_; i++)
    {
        Point::GotoScrXY(i, Game::height_);
        ORIGINAL std::cout << "��";
    }

    Point::GotoScrXY(15, 5);
    ORIGINAL std::cout << "Score : " << Game::Get().GetScore();
    Point::GotoScrXY(15, 7);
    ORIGINAL std::cout << "Level : " << Game::Get().GetLevel();
    Point::GotoScrXY(15, 9);
    ORIGINAL std::cout << "Clear Lines : " << Game::Get().GetClearCnt();

    // Print board
    Board& pboard = Game::Get().GetBoard();
    for (std::size_t i = 0; i < Game::width_; i++)
    {
        for (std::size_t j = 0; j < Game::height_; j++)
        {
            Point::GotoScrXY(i + 1, j);
            if (pboard.Getboard(j, i) == TetriminoType::I)
            {
                DARK_BLUE std::cout << "��";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::J)
            {
                GREEN std::cout << "��";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::L)
            {
                PURPLE std::cout << "��";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::O)
            {
                SKY_BLUE std::cout << "��";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::S)
            {
                RED std::cout << "��";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::T)
            {
                PLUM std::cout << "��";
            }
            else if (pboard.Getboard(j, i) == TetriminoType::Z)
            {
                YELLOW std::cout << "��";
            }
        }
    }
}

void Screen::PrintBlocks(const Tetrimino& tetrimino)
{
    for (int i = 0; i < 4; i++)
    {
        Point::GotoScrXY(
            tetrimino.GetPos().GetX() + (tetrimino.GetType() + i)->GetX() + 1,
            tetrimino.GetPos().GetY() + (tetrimino.GetType() + i)->GetY());

        if (tetrimino.GetTType() == TetriminoType::I)
        {
            DARK_BLUE std::cout << "��";
        }
        else if (tetrimino.GetTType() == TetriminoType::J)
        {
            GREEN std::cout << "��";
        }
        else if (tetrimino.GetTType() == TetriminoType::L)
        {
            PURPLE std::cout << "��";
        }
        else if (tetrimino.GetTType() == TetriminoType::O)
        {
            SKY_BLUE std::cout << "��";
        }
        else if (tetrimino.GetTType() == TetriminoType::S)
        {
            RED std::cout << "��";
        }
        else if (tetrimino.GetTType() == TetriminoType::T)
        {
            PLUM std::cout << "��";
        }
        else if (tetrimino.GetTType() == TetriminoType::Z)
        {
            YELLOW std::cout << "��";
        }
        else
        {
            throw std::logic_error("tetrimino type error");
        }
    }
}

void Screen::PrintSpace(const Tetrimino& tetrimino)
{
    for (int i = 0; i < 4; i++)
    {
        Point::GotoScrXY(
            tetrimino.GetPos().GetX() + (tetrimino.GetType() + i)->GetX() + 1,
            tetrimino.GetPos().GetY() + (tetrimino.GetType() + i)->GetY());

        std::cout << (" ");
    }
}

void Screen::PrintGameOver()
{
    Point::GotoScrXY(15, 13);
    ORIGINAL std::cout << "Game Over";
    Point::GotoScrXY(15, 15);
    ORIGINAL std::cout << "Your score is ";
    YELLOW std::cout << Game::Get().GetScore();
    Point::GotoScrXY(15, 17);
    ORIGINAL std::cout << "Your Level is ";
    GREEN std::cout << Game::Get().GetLevel();
    Point::GotoScrXY(20, 25);
    ORIGINAL std::cout << " ";
}
}  // namespace Tetris