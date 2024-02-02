////Standard Libraries
//#include<iostream>
////Third Party Libraries
//#include<SDL.h>
//#include<SDL_image.h>
//#include<C:/Users/messi/source/repos/MINESWEEPER SDL2/MINESWEEPER SDL2/minesweeper/HeaderFIles/constances.h>
//#define MAXMINES 22;
//#define FLAGS 22;
////#include<C:/Users/messi/source/repos/MINESWEEPER SDL2/MINESWEEPER SDL2/minesweeper/HeaderFIles/tile.h>
////SDL_Rect rectArray[TILE_ROWS][TILE_COLS];
//class Tile 
//{
//public:
//	int i, j;
//	bool isRevealed, isMine,isFlagged;
//	int adjacentMines;
//	Tile()
//	{
//		//Initially setting reveal and mine to false
//
//		isRevealed = false;
//		isMine = false; 
//	}
//  };
//enum State
//{
//	// Game States
//	PLAYING,
//	PAUSED,
//    WIN,
//    LOSE
//};
// Tile tileArray[TILE_ROWS][TILE_COLS];
// State state = PLAYING ;
//
//void DrawTile(Tile tile,SDL_Texture * t_imgUnknown1, SDL_Texture* t_imgEmpty,SDL_Texture * t_flagged,SDL_Renderer * renderer,SDL_Texture* t_imgMine)
//{
//	// Draw Tiles 
//	// Empty, Not Revealed, Mines
//	SDL_Rect destRect= { tile.i * TILE_WIDTH, tile.j * TILE_HEIGHT, 40, 40 };
//	SDL_Texture* text = t_imgUnknown1;
//
//	if (!tile.isRevealed && tile.isFlagged)
//	{
//			text = t_flagged;
//			SDL_RenderCopy(renderer, text, NULL, &destRect);
//			return;
//	}
//	else if (tile.isRevealed )
//	{
//		if (tile.isMine)
//		{
//			text = t_imgMine;
//		}
//		else {
//			text = t_imgEmpty;
//		}
//	}
//	SDL_RenderCopy(renderer, text, NULL, &destRect);
//}
//void InsertFlag(int i , int j, int& flags)
//{
//	//Insert Flag 
//	if (tileArray[i][j].isRevealed)
//	{
//		std::cout << " Tile Revealed" << std::endl;
//		return;
//	}
//	if (!tileArray[i][j].isFlagged && flags <=0)
//	{
//		return;
//	}
//	tileArray[i][j].isFlagged = !tileArray[i][j].isFlagged;
//	if (tileArray[i][j].isFlagged)
//	{
//		flags--;
//	}
//	else
//	{
//		flags++;
//	}
//}
//bool IsIndexValid(int i, int j)
//{
//	//Check If the index is valid or not 
//	return  (i >= 0 && i < TILE_ROWS) && (j >= 0 && j < TILE_COLS);
//}
//
//int NearMineCount(int i , int j)
//{
//	int count=0;
//	//Count Near By Mines
//	for (int i1 = -1; i1 <= 1; i1++)
//	{
//		for (int j1 = -1; j1 <= 1; j1++)
//		{
//			if (i1 == 0 && j1 == 0)
//			{
//				continue;
//			}
//			if (!IsIndexValid(i + i1, j + j1))
//			{
//				continue;
//			}
//			if (tileArray[i + i1][j + j1].isMine)
//			{
//				count++;
//			}
//		}
//	}
//	return count;
//}
//void InsertAdjacentNumberText( Tile tile,SDL_Texture* text1, SDL_Texture* text2, SDL_Texture* text3,SDL_Texture* text4, SDL_Texture * text5 ,SDL_Renderer * renderer)
//{
//
//	SDL_Texture* numText = nullptr; 
//	//Creating Rectangle to Set Numbers
//	SDL_Rect destRect = { tile.i * TILE_WIDTH, tile.j * TILE_HEIGHT, 40, 40 };
//
//	if (tile.isRevealed  && tile.adjacentMines > 0  )
//	{
//		if (tile.adjacentMines == 1)
//		{
//			numText = text1;
//		}
//		else if (tile.adjacentMines == 2)
//		{
//			numText = text2;
//		}
//		else if (tile.adjacentMines == 3)
//		{
//			numText = text3;
//		}
//		else if (tile.adjacentMines == 4)
//		{
//			numText = text4;
//		}
//		else if (tile.adjacentMines == 5)
//		{
//			numText = text5;
//		}
//	}
//	SDL_RenderCopy(renderer, numText, NULL, &destRect);
//}
//void FloodFill(int i , int j )
//{
//	// Check if the index is valid and the tile is not revealed
//	if (IsIndexValid(i, j) && !tileArray[i][j].isRevealed)
//	{
//		// Reveal the tile
//		tileArray[i][j].isRevealed = true;
//
//		// Check the number of adjacent mines
//		int count = tileArray[i][j].adjacentMines;
//
//		// If the tile has zero adjacent mines, call FloodFill on its neighbors
//		if (count == 0)
//		{
//			for (int i1 = -1; i1 <= 1; i1++)
//			{
//				for (int j1 = -1; j1 <= 1; j1++)
//				{
//					// Skip the current tile
//					if (i1 == 0 && j1 == 0)
//					{
//						continue;
//					}
//
//					// Call FloodFill on the neighbor tile
//					FloodFill(i + i1, j + j1);
//				}
//			}
//		}
//	}
//}
//
//int main(int argc, char* argv[])
//{
//	int flags = FLAGS;
//	 srand(time(0));
//	//Creating SDL Window
//	SDL_Window* window = nullptr;
//    window = SDL_CreateWindow("Minesweeper", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,480 , 480, SDL_WINDOW_SHOWN);
//
//	// Creating SDL Renderer 
//	//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
//	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
//    SDL_Renderer * renderer = nullptr;
//	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//
//	// Surfaces for all the Images
//
//	SDL_Surface* s_imgUnknown2  = IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/unknown_2_64x64.png");
//	SDL_Surface* s_imgEmpty = IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/empty_64x64.png");
//	SDL_Surface* s_imgMine = IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/bomb_exploded_64x64.png");
//	SDL_Surface* s_num1 = IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/1_64x64.png");
//	SDL_Surface* s_num2 = IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/2_64x64.png");
//	SDL_Surface* s_num3 = IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/3_64x64.png");
//	SDL_Surface* s_num4 = IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/4_64x64.png");
//	SDL_Surface* s_num5 = IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/5_64x64.png");
//	SDL_Surface* s_flagged = IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/flag_1_64x64.png");
//
//	// Textures for all the Images 
//	//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
//	SDL_Texture* t_imgUnknown1 = SDL_CreateTextureFromSurface(renderer, s_imgUnknown2);
//	SDL_Texture* t_imgEmpty = SDL_CreateTextureFromSurface(renderer, s_imgEmpty);
//	SDL_Texture* t_imgMine = SDL_CreateTextureFromSurface(renderer, s_imgMine);
//	SDL_Texture* t_imgnum1 = SDL_CreateTextureFromSurface(renderer, s_num1);
//	SDL_Texture* t_imgnum2 = SDL_CreateTextureFromSurface(renderer, s_num2);
//	SDL_Texture* t_imgnum3 = SDL_CreateTextureFromSurface(renderer, s_num3);
//	SDL_Texture* t_imgnum4 = SDL_CreateTextureFromSurface(renderer, s_num4);
//	SDL_Texture* t_imgnum5 = SDL_CreateTextureFromSurface(renderer, s_num5);
//	SDL_Texture* t_flagged = SDL_CreateTextureFromSurface(renderer, s_flagged);
//
//	//Free SDL Surface
//
//	SDL_FreeSurface(s_imgUnknown2);
//	SDL_FreeSurface(s_imgEmpty);
//	SDL_FreeSurface(s_imgMine);
//	SDL_FreeSurface(s_num1);
//	SDL_FreeSurface(s_num2);
//	SDL_FreeSurface(s_num3);
//	SDL_FreeSurface(s_num4);
//	SDL_FreeSurface(s_num5);
//	SDL_FreeSurface(s_flagged);
//	
//	bool running = true; 
//	SDL_Event event;
//	int n = 5;
//
//	if (SDL_Init(SDL_INIT_VIDEO)  < 0)	
//	{
//		std::cout << "system is not  initialized \n";
//	}
//	for (int i = 0; i < TILE_ROWS; i++)
//	{
//		for (int j = 0; j < TILE_ROWS; j++)
//		{
//				tileArray[i][j].i = i;
//				tileArray[i][j].j = j;
//				tileArray[i][j].isRevealed = false;
//				tileArray[i][j].isMine = false;
//				tileArray[i][j].adjacentMines = -1;
//				tileArray[i][j].isFlagged = false; 
//		}
//	}
//	int numOfMines = MAXMINES;             //TILE_COLS * TILE_ROWS * 0.1;
//	while (numOfMines > 0)
//	{
//		int i = rand() % TILE_ROWS;
//		int j = rand() % TILE_COLS;
//		if (!tileArray[i][j].isMine)
//		{
//			tileArray[i][j].isMine = true;
//			numOfMines--;
//		}
//
//	}
//	while (running)
//	{
//		SDL_PollEvent(&event);
//		// To stop the game loop
//		if (event.type == SDL_QUIT)
//		{
//			running = false;
//			std::cout << "running is set to false" << std::endl;
//		}
//		// Draw Tiles For Minesweeper
//		//RenderClear
//		SDL_RenderClear(renderer);
//		for (int i = 0; i < TILE_ROWS; i++)
//		{
//			for (int j = 0; j < TILE_COLS; j++)
//			{
//				DrawTile(tileArray[i][j], t_imgUnknown1, t_imgEmpty, t_flagged, renderer, t_imgMine);
//				//InsertMine(i, j);
//			}
//		}
//		// Nested loops to Draw Calculate Numbers on the Tiles
//		// Num Textures
//		for (int i = 0; i < TILE_ROWS; i++)
//		{
//			for (int j = 0; j < TILE_COLS; j++)
//			{
//				if (!tileArray[i][j].isMine)
//				{
//					tileArray[i][j].adjacentMines = NearMineCount(i, j);
//					InsertAdjacentNumberText(tileArray[i][j], t_imgnum1, t_imgnum2, t_imgnum3, t_imgnum4, t_imgnum5, renderer);
//				}
//			}
//		}
//		SDL_RenderPresent(renderer);
//
//		// Taking Mouse Inputs 
//		// Left Click -> Reveal Tile        Right Click -> Insert Flag 
//	
//		if(event.type == SDL_MOUSEBUTTONDOWN)
//		{
//		if (event.button.button == SDL_BUTTON_LEFT)
//		{
//			int x, y;
//			SDL_GetMouseState(&x, &y);
//			int i = x / TILE_WIDTH;
//			int j = y / TILE_HEIGHT;
//			if (IsIndexValid(i, j) && !tileArray[i][j].isFlagged )
//			{
//				FloodFill(i, j);
//			}
//		}
//		else if (event.button.button == SDL_BUTTON_RIGHT)
//		{
//			int x, y;
//			SDL_GetMouseState(&x, &y);
//			int i = x / TILE_WIDTH;
//			int j = y / TILE_HEIGHT;	
//
//			if (IsIndexValid(i, j))
//			{
//				InsertFlag(i, j, flags);
//			}
//		}
//	}
//	}
//	SDL_Quit();
//	return 0;
//}