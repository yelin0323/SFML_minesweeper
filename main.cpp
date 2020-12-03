#include<SFML/Graphics.hpp>
#include<ctime>

using namespace sf;

class Tile
{
public:
	int count; //지뢰면 9, 아니면 주변 지뢰의 수
	int open;	//0이면 close, 1이면 open
	int flag;
	Tile() : count(10), open(0), flag(0) {};
private:
	void isOpne();
	void flagcheck();	//flag와 실제 지뢰가 같은지
};

int main()
{
	Tile tiles[12][12];
	Tile stile[12][12];

	srand((unsigned int)time(NULL));

	int mineCount = 0;
	int minenum = 3;	//지뢰를 설치하고 5개 내에는 지뢰 설치 금지

	RenderWindow minesweeper(VideoMode(400, 400), "Start The Minesweeper");

	Texture t;
	t.loadFromFile("tiles.jpg");
	Sprite s(t);

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			int num = rand();
			if (num % 5 == 0 && mineCount < 10 && minenum >= 3)
			{
				tiles[i][j].count = 9;
				mineCount++;
				minenum = 0;
			}
			else
			{
				tiles[i][j].count = 0;
				minenum++;
			}
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
				if (e.key.code == Mouse::Left)
				{
					stile[x][y] = tiles[x][y];
					if (stile[x][y].count == 0)
					{
						for (int m = 1; m <= 10; m++)
						{
							for (int n = 1; n <= 10; n++)
							{
								if (tiles[m][n].count == 0)
								{
									stile[m][n] = tiles[m][n];
									s.setTextureRect(IntRect(stile[m][n].count * w, 0, w, w));
									s.setPosition(m * w, n * w);
									minesweeper.draw(s);
								}

							}
						}
					}
				}
				else if (e.key.code == Mouse::Right) stile[x][y].count = 11;

		}

		minesweeper.clear(Color::White);
		for (int i = 1; i <= 10; i++)
			for (int j = 1; j <= 10; j++) {

				if (stile[x][y].count == 9) stile[i][j] = tiles[i][j];

				s.setTextureRect(IntRect(stile[i][j].count * w, 0, w, w));
				s.setPosition(i * w, j * w);
				minesweeper.draw(s);

			}



		minesweeper.display();

	}
	
	
	

	return 0;
}