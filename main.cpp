#include<SFML/Graphics.hpp>
#include<time.h>

using namespace sf;

class tile
{
public:
	int count; //지뢰면 9, 아니면 주변 지뢰의 수
	int open;	//0이면 close, 1이면 open
	int flag;
private:
	void isOpne();
	void flagcheck();	//flag와 실제 지뢰가 같은지
};


class board
{
public:

private:
	void gameover();	//지뢰를 다 찾았는지, 지뢰를 눌렀는지 (게임이끝났는지확인)
};




int main()
{
	board board;
	tile tiles[12][12];

	RenderWindow minesweeper(VideoMode(400, 400), "Start The Minesweeper");

	Texture t;
	t.loadFromFile("tiles.jpg");
	Sprite s(t);

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			tiles[i][j].count = 10;
			tiles[i][j].flag = 0;
			tiles[i][j].open = 0;

			if (rand() % 5 == 0) tiles[i][j].count = 9;
			else tiles[i][j].count = 0;
		}
	}

	
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			int n = 0;
			if (tiles[i][j].count == 9) continue;

			if (tiles[i + 1][j].count == 9) n++;
			if (tiles[i][j + 1].count == 9) n++;
			if (tiles[i - 1][j].count == 9) n++;
			if (tiles[i][j - 1].count == 9) n++;

			if (tiles[i + 1][j + 1].count == 9) n++;
			if (tiles[i - 1][j - 1].count == 9) n++;
			if (tiles[i - 1][j + 1].count == 9) n++;
			if (tiles[i + 1][j - 1].count == 9) n++;

			tiles[i][j].count = n;
		}
	}

	/*
	int w = 32;

	while (minesweeper.isOpen())
	{
		Vector2i pos = Mouse::getPosition(minesweeper);
		int x = pos.x / w;
		int y = pos.y / w;

		Event e;
		while (minesweeper.pollEvent(e))
		{
			if (e.type == Event::Closed)
				minesweeper.close();

			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left) sgrid[x][y] = grid[x][y];
				else if (e.key.code == Mouse::Right) sgrid[x][y] = 11;

		}

		minesweeper.clear(Color::White);
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++) {

				if (sgrid[x][y] == 9) sgrid[i][j] = grid[i][j];

				s.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
				s.setPosition(i * w, j * w);
				minesweeper.draw(s);
			}

		minesweeper.display();



	}
	
	*/
	

	return 0;
}