#pragma once
//screen dimension
//const int SCREEN_WIDTH = 400;
//const int SCREEN_HEIGHT = 400;
//image location 
// IMG_Load("C:/Users/messi/source/repos/MINESWEEPER SDL2/Images/MineSweeper_ModeliveskyCom/64x64/1_64x64.png")

//tiles 

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;
const int TILE_ROWS = 12;
const int TILE_COLS = 12;
const int TILE_WIDTH = SCREEN_WIDTH / TILE_COLS;
const int TILE_HEIGHT = SCREEN_HEIGHT / TILE_ROWS;




//if (SDL_GetMouseState(&msPositionX, &msPositionY))
//{
//	int indexI = msPositionX/ TILE_WIDTH;
//	int indexJ = msPositionY/TILE_HEIGHT;

//	std::cout << "I val " << indexI << " J val " << indexJ << std::endl;
//	if (IsIndexValid(indexI, indexJ))
//	{
//	//	tileArray[indexI][indexJ].isRevealed = true;
//		TileReveal(indexI, indexJ);
//	}
//}



//
//
//
//if (event.type == SDL_QUIT)
//{
//	running = false;
//}
//if (event.type == SDL_MOUSEBUTTONDOWN)
//{
//	SDL_GetMouseState(&msPositionX, &msPositionY);
//	int indexI = msPositionX / TILE_WIDTH;
//	int indexJ = msPositionY / TILE_HEIGHT;
//
//	std::cout << "I val " << indexI << " J val " << indexJ << std::endl;
//	//if (IsIndexValid(indexI, indexJ))
//	//{
//	//	//	tileArray[indexI][indexJ].isRevealed = true;
//	//	TileReveal(indexI, indexJ);
//	//}
//
//}












	/*	for (int i = 0; i < TILE_ROWS; i++)
		{
			for (int j = 0; j < TILE_ROWS; j++)
			{
					tileArray[i][j].i = i;
					tileArray[i][j].j = j;
					TileDraw(tileArray[i][j], renderer);
			}
		}*/
		/*	for (int i = 0; i < TILE_ROWS; i++)
			{
				for (int j = 0; j < TILE_ROWS; j++)
				{

				}
			}*/
			//	RenderFrames(renderer);