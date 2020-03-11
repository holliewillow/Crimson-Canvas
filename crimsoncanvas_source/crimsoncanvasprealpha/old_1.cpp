#include <string.h>
#include <time.h>
#include <random>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
//headers
#include "SDL2-2.0.10\include\SDL.h"
#include "SDL2-2.0.10\include\SDL_image.h"
#include "SDL2-2.0.10\include\SDL_ttf.h"
#include "SDL2-2.0.10\include\SDL_mixer.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <time.h>
using namespace std;
//libraries
#pragma comment(lib,"SDL2-2.0.10\\lib\\x64\\SDL2.lib")
#pragma comment(lib,"SDL2-2.0.10\\lib\\x64\\SDL2main.lib")
#pragma comment(lib,"SDL2-2.0.10\\lib\\x64\\SDL2_image.lib")
#pragma comment(lib,"SDL2-2.0.10\\lib\\x64\\SDL2_mixer.lib")
#pragma comment(lib,"SDL2_ttf.lib")
#pragma comment(linker,"/subsystem:console")

#define P1_LEFTX Input::controller_sticks[0][0]
#define P1_LEFTY Input::controller_sticks[0][1]
#define P1_RIGHTX Input::controller_sticks[0][2]
#define P1_RIGHTY Input::controller_sticks[0][3]
#define P1_LEFTTRIGGER Input::controller_sticks[0][4]
#define P1_RIGHTTRIGGER Input::controller_sticks[0][5]
#define P1_A Input::controller_buttons[0][0]
#define P1_B Input::controller_buttons[0][1]
#define P1_X Input::controller_buttons[0][2]
#define P1_Y Input::controller_buttons[0][3]
#define P1_BACK Input::controller_buttons[0][4]
#define P1_GUIDE Input::controller_buttons[0][5]
#define P1_START Input::controller_buttons[0][6]
#define P1_LEFT_PRESS Input::controller_buttons[0][7]
#define P1_RIGHT_PRESS Input::controller_buttons[0][8]
#define P1_LEFT_SHOULDER Input::controller_buttons[0][9]
#define P1_RIGHT_SHOULDER Input::controller_buttons[0][10]
#define P1_DPAD_UP Input::controller_buttons[0][11]
#define P1_DPAD_DOWN Input::controller_buttons[0][12]
#define P1_DPAD_LEFT Input::controller_buttons[0][13]
#define P1_DPAD_RIGHT Input::controller_buttons[0][14]

#define LAST_P1_LEFTX Input::last_controller_sticks[0][0]
#define LAST_P1_LEFTY Input::last_controller_sticks[0][1]
#define LAST_P1_RIGHTX Input::last_controller_sticks[0][2]
#define LAST_P1_RIGHTY Input::last_controller_sticks[0][3]
#define LAST_P1_LEFTTRIGGER Input::last_controller_sticks[0][4]
#define LAST_P1_RIGHTTRIGGER Input::last_controller_sticks[0][5]
#define LAST_P1_A Input::last_controller_buttons[0][0]
#define LAST_P1_B Input::last_controller_buttons[0][1]
#define LAST_P1_X Input::last_controller_buttons[0][2]
#define LAST_P1_Y Input::last_controller_buttons[0][3]
#define LAST_P1_BACK Input::last_controller_buttons[0][4]
#define LAST_P1_GUIDE Input::last_controller_buttons[0][5]
#define LAST_P1_START Input::last_controller_buttons[0][6]
#define LAST_P1_LEFT_PRESS Input::last_controller_buttons[0][7]
#define LAST_P1_RIGHT_PRESS Input::last_controller_buttons[0][8]
#define LAST_P1_LEFT_SHOULDER Input::last_controller_buttons[0][9]
#define LAST_P1_RIGHT_SHOULDER Input::last_controller_buttons[0][10]
#define LAST_P1_DPAD_UP Input::last_controller_buttons[0][11]
#define LAST_P1_DPAD_DOWN Input::last_controller_buttons[0][12]
#define LAST_P1_DPAD_LEFT Input::last_controller_buttons[0][13]
#define LAST_P1_DPAD_RIGHT Input::last_controller_buttons[0][14]


#define P2_LEFTX Input::controller_sticks[1][0]
#define P2_LEFTY Input::controller_sticks[1][1]
#define P2_RIGHTX Input::controller_sticks[1][2]
#define P2_RIGHTY Input::controller_sticks[1][3]
#define P2_LEFTTRIGGER Input::controller_sticks[1][4]
#define P2_RIGHTTRIGGER Input::controller_sticks[1][5]
#define P2_A Input::controller_buttons[1][0]
#define P2_B Input::controller_buttons[1][1]
#define P2_X Input::controller_buttons[1][2]
#define P2_Y Input::controller_buttons[1][3]
#define P2_BACK Input::controller_buttons[1][4]
#define P2_GUIDE Input::controller_buttons[1][5]
#define P2_START Input::controller_buttons[1][6]
#define P2_LEFT_PRESS Input::controller_buttons[1][7]
#define P2_RIGHT_PRESS Input::controller_buttons[1][8]
#define P2_LEFT_SHOULDER Input::controller_buttons[1][9]
#define P2_RIGHT_SHOULDER Input::controller_buttons[1][10]
#define P2_DPAD_UP Input::controller_buttons[1][11]
#define P2_DPAD_DOWN Input::controller_buttons[1][12]
#define P2_DPAD_LEFT Input::controller_buttons[1][13]
#define P2_DPAD_RIGHT Input::controller_buttons[1][14]

#define LAST_P2_LEFTX Input::last_controller_sticks[1][0]
#define LAST_P2_LEFTY Input::last_controller_sticks[1][1]
#define LAST_P2_RIGHTX Input::last_controller_sticks[1][2]
#define LAST_P2_RIGHTY Input::last_controller_sticks[1][3]
#define LAST_P2_LEFTTRIGGER Input::last_controller_sticks[1][4]
#define LAST_P2_RIGHTTRIGGER Input::last_controller_sticks[1][5]
#define LAST_P2_A Input::last_controller_buttons[1][0]
#define LAST_P2_B Input::last_controller_buttons[1][1]
#define LAST_P2_X Input::last_controller_buttons[1][2]
#define LAST_P2_Y Input::last_controller_buttons[1][3]
#define LAST_P2_BACK Input::last_controller_buttons[1][4]
#define LAST_P2_GUIDE Input::last_controller_buttons[1][5]
#define LAST_P2_START Input::last_controller_buttons[1][6]
#define LAST_P2_LEFT_PRESS Input::last_controller_buttons[1][7]
#define LAST_P2_RIGHT_PRESS Input::last_controller_buttons[1][8]
#define LAST_P2_LEFT_SHOULDER Input::last_controller_buttons[1][9]
#define LAST_P2_RIGHT_SHOULDER Input::last_controller_buttons[1][10]
#define LAST_P2_DPAD_UP Input::last_controller_buttons[1][11]
#define LAST_P2_DPAD_DOWN Input::last_controller_buttons[1][12]
#define LAST_P2_DPAD_LEFT Input::last_controller_buttons[1][13]
#define LAST_P2_DPAD_RIGHT Input::last_controller_buttons[1][14]

#define HEAD hurt_boxes[0];
#define SHOULDERS hurt_boxes[1];
#define TORSO hurt_boxes[2];
#define LEGS hurt_boxes[3];

SDL_Renderer *renderer = NULL;
int screen_width = 1920;
int screen_height = 1080;
double dt = 1;

namespace Images
{
	const char* player_filename = "Sprites\\Camila_walk.png";
	const char* bg_filename = "Sprites\\bg.png";
	const char* blood_filename = "Sprites\\blood.png";
}

struct Vec
{
	float x, y;
};

namespace Input
{
	int mx, my, m_left, last_m_left, m_right, last_m_right;
	
	const int max_game_controllers = 2;
	const int num_sticks = 6;
	const int num_buttons = 15;
	const int stick_dead_zone = 10000;
	SDL_GameController* game_controllers[max_game_controllers];
	//[joystick id] [x or y axis]
	/*
	0	SDL_CONTROLLER_AXIS_LEFTX
	1	SDL_CONTROLLER_AXIS_LEFTY
	2	SDL_CONTROLLER_AXIS_RIGHTX
	3	SDL_CONTROLLER_AXIS_RIGHTY
	4	SDL_CONTROLLER_AXIS_TRIGGERLEFT
	5	SDL_CONTROLLER_AXIS_TRIGGERRIGHT
	*/
	int last_controller_sticks[max_game_controllers][num_sticks];
	int controller_sticks[max_game_controllers][num_sticks];
	/*
	0	SDL_CONTROLLER_BUTTON_A
	1	SDL_CONTROLLER_BUTTON_B
	2	SDL_CONTROLLER_BUTTON_X
	3	SDL_CONTROLLER_BUTTON_Y
	4	SDL_CONTROLLER_BUTTON_BACK
	5	SDL_CONTROLLER_BUTTON_GUIDE
	6	SDL_CONTROLLER_BUTTON_START
	7	SDL_CONTROLLER_BUTTON_LEFTSTICK
	8	SDL_CONTROLLER_BUTTON_RIGHTSTICK
	9	SDL_CONTROLLER_BUTTON_LEFTSHOULDER
	10	SDL_CONTROLLER_BUTTON_RIGHTSHOULDER
	11	SDL_CONTROLLER_BUTTON_DPAD_UP
	12	SDL_CONTROLLER_BUTTON_DPAD_DOWN
	13	SDL_CONTROLLER_BUTTON_DPAD_LEFT
	14	SDL_CONTROLLER_BUTTON_DPAD_RIGHT
	*/
	int last_controller_buttons[max_game_controllers][num_buttons];
	int controller_buttons[max_game_controllers][num_buttons];
	int num_game_controllers = 0;
	

	void init()
	{
		int num_connected = SDL_NumJoysticks();
		num_game_controllers = 0;
		for (int i = 0; i < num_connected; i++)
		{
			if (SDL_IsGameController(i))
			{
				game_controllers[num_game_controllers] = SDL_GameControllerOpen(i);
				if (game_controllers[num_game_controllers] != NULL) num_game_controllers++;
			}
		}
		printf("connected to %d controllers\n", num_game_controllers);
	}

	void update()
	{
		for (int i = 0; i < num_game_controllers; i++)
		{
			memcpy(last_controller_sticks[i], controller_sticks[i], sizeof(int) * num_sticks);
			for (int j = 0; j < num_sticks; j++)
			{
				controller_sticks[i][j] = SDL_GameControllerGetAxis(game_controllers[i], (SDL_GameControllerAxis)j);
			}
			memcpy(last_controller_buttons[i], controller_buttons[i], sizeof(int) * num_buttons);
			for (int k = 0; k < num_buttons; k++)
			{
				controller_buttons[i][k] = SDL_GameControllerGetButton(game_controllers[i], (SDL_GameControllerButton)k);
			}
		}

		int mouse_button = SDL_GetMouseState(&mx, &my);
		last_m_left = m_left;
		last_m_right = m_right;
		m_left = mouse_button & SDL_BUTTON(SDL_BUTTON_LEFT);
		m_right = (mouse_button & SDL_BUTTON(SDL_BUTTON_RIGHT)) == SDL_BUTTON(SDL_BUTTON_RIGHT);
	}
}

namespace Camera
{
	struct Camera
	{
		Vec vel;
		Vec accel;
		Vec cam_center;
		Vec screen_center;
		float speed;
		float max_vel;
	};

	void init(Camera *c)
	{
		c->cam_center.x = 960;
		c->cam_center.y = 540;
		c->vel.x = 0.0;
		c->vel.y = 0.0;
		c->accel.x = 0.0;
		c->accel.y = 0.0;
		c->speed = 1;
		c->screen_center.x = screen_width / 2;
		c->screen_center.y = screen_height / 2;
		c->max_vel = 0.01;
	}

	void update(Camera *c)
	{
		c->vel.x += c->accel.x * dt;
		c->vel.y += c->accel.y * dt;
		c->cam_center.x += c->vel.x * dt;
		c->cam_center.y += c->vel.y * dt;

		if (c->vel.x >= c->max_vel)
		{
			c->vel.x = 0;
		}
		if (c->vel.x <= -c->max_vel)
		{
			c->vel.x = 0;
		}
		

		if (c->cam_center.x >= 2925)
		{
			c->cam_center.x = 2925;
			c->vel.x = 0;
		}
		if (c->cam_center.x <= 925)
		{
			c->cam_center.x = 925;
			c->vel.x = 0;
		}
	}
}

namespace Player
{
	struct collision_box
	{
		float x, y, w, h;
		int id, damage;
	};
	enum player_States
	{
		idle,
		walking,
		jumping,
		blocking,
	};

	enum player_Facing
	{
		left,
		right
	};

	struct Player
	{
		player_States state;
		player_Facing facing;
		player_Facing collision_facing;
		Vec pos;
		Vec accel;
		Vec vel;
		collision_box* hurt_boxes;
		collision_box* hit_boxes;
		float max_vel;
		float max_jump_vel;
		float f_move;
		float f_jump;
		float f_fall;
		int jump_duration;
		int width;
		int height;

		int n_hurt_boxes;
		int n_hit_boxes;

		int frame_x;
		int frame_y;
		int frame_duration;
		int n_frames;
		unsigned int last_frame_change_time;
		int current_frame;
	};

	void init(Player *p)
	{
		p->state = idle;
		p->pos.x = 400;
		p->pos.y = 500;
		p->accel.x = 0;
		p->accel.y = 0;
		p->vel.x = 0;
		p->vel.y = 0;
		p->max_vel = 0.01;
		p->f_move = 0.5;
		p->f_jump = 1;
		p->f_fall = 5;
		p->jump_duration = 225;
		p->width = 64;
		p->height = 128;

		p->n_hurt_boxes = 4;
		p->hurt_boxes = (collision_box*)malloc(sizeof(collision_box) * p->n_hurt_boxes);
		p->frame_x = 576;
		p->frame_y = 0;
		p->frame_duration = 150;
		p->n_frames = 10;
		p->last_frame_change_time = 0;
		p->current_frame = 0;
	}

	int check_Opponent_Collision(Player *p, Player *other)
	{
		if (p->pos.x + p->width * 2.5 < other->pos.x) return 0;
		else if (p->pos.x > other->pos.x + other->width * 2.5) return 0;
		else if (p->pos.y + p->height * 2.5 < other->pos.y) return 0;
		else if (p->pos.y > other->pos.y + other->height * 2.5) return 0;

		else return 1;
	}

	void update(Player *p, Camera::Camera *c, Player *other, char collision)
	{
		c->accel.x = {};
		c->accel.y = {};

		p->vel.x += p->accel.x * dt;
		p->vel.y += p->accel.y * dt;
		
		if (collision == 1 && p->state != jumping)
		{
			if (p->facing == p->collision_facing) p->vel.x = 0;
		}

		p->pos.x += p->vel.x * dt;
		p->pos.y += p->vel.y * dt;

	
		/*else if (collision == 1 && p->state == jumping)
		{
			if (p->facing != other->facing && p->facing == left)
			{
				p->accel.x = 0;
				other->accel.x = 0;
				p->pos.x += 1;
				other->pos.x -= 1;
			}
			else if (p->facing != other->facing && p->facing == right)
			{
				p->accel.x = 0;
				other->accel.x = 0;
				p->pos.x -= 1;
				other->pos.x += 1;
			}
		}*/

		if (p->vel.x >= p->max_vel)
		{
			p->vel.x = 0;
		}
		if (p->vel.x <= -p->max_vel)
		{
			p->vel.x = 0;
		}

		if (p->pos.x >= c->cam_center.x + 650)
		{
			c->accel.x += c->speed;
			p->pos.x = c->cam_center.x + 650;
			p->vel.x = 0;
		}
		if (p->pos.x <= c->cam_center.x - 900)
		{
			c->accel.x -= c->speed;
			p->pos.x = c->cam_center.x - 900;
			p->vel.x = 0;
		}
		if (p->pos.y <= c->cam_center.y - 500)
		{
			p->vel.y += 5 * p->f_jump;
			p->pos.y = c->cam_center.y - 500;
		}
		if (p->pos.y >= 500)
		{
			p->state = idle;
			p->pos.y = 500;
			p->vel.y = 0;
			c->cam_center.y = 540;
		}
	}

	void draw(Player *p, Camera::Camera *c, SDL_Texture *texture, SDL_Rect src, SDL_RendererFlip fliptype)
	{
		SDL_Rect dest = { p->pos.x - c->cam_center.x + screen_width / 2, p->pos.y - c->cam_center.y + screen_height / 2, p->width * 4, p->height * 4};
		SDL_SetTextureAlphaMod(texture, 255);
		SDL_RenderCopyEx(renderer, texture, &src, &dest, 0, NULL, fliptype);
	}
}

namespace Backgrounds
{
	struct Backgrounds
	{
		const int n_background_tiles = 2;
		Vec *pos;
		int* background_tiles;
		int stage_width;
		const int stage_height = 1080;
	};

	void init(Backgrounds *bg)
	{
		bg->background_tiles[bg->n_background_tiles];
		bg->pos = (Vec*)malloc(sizeof(Vec) * 2);
		for (int i = 0; i < bg->n_background_tiles; i++)
		{
			bg->pos[i].x = 1920 * i;
			bg->pos[i].y = 0;
		}
		bg->stage_width = 1920 * bg->n_background_tiles;
	}


	void draw(Backgrounds *bg, Camera::Camera *c, SDL_Texture *texture, SDL_Rect src, SDL_RendererFlip fliptype)
	{
		SDL_Rect dest;
		for (int i = 0; i < bg->n_background_tiles; i++)
		{
			dest.x = bg->pos[i].x - c->cam_center.x + screen_width / 2;
			dest.y = 0 - c->cam_center.y + screen_height / 2;
			dest.w = 1920;
			dest.h = 1080;
			src.x = 1920 * i;
			SDL_SetTextureAlphaMod(texture, 255);
			SDL_RenderCopyEx(renderer, texture, &src, &dest, 0, NULL, fliptype);
		}
	}
}

namespace Blood_Grid
{
	struct Blood_Grid
	{
		int** blood_tile_array;
		int blood_grid_rows;
		int blood_grid_columns;
		int blood_grid_size;
		int* blood_grid_value;
		Vec* pos;
		int tile_size;
		int frame_x;
		int frame_y;
		int frame_size;
	};

	void init(Blood_Grid *b, Backgrounds::Backgrounds *bg)
	{
		b->tile_size = 40;
		b->blood_grid_columns = bg->stage_width / b->tile_size;
		b->blood_grid_rows = bg->stage_height / b->tile_size;
		b->blood_grid_size = b->blood_grid_columns * b->blood_grid_rows;

		b->blood_tile_array = (int**)malloc(sizeof(int*)*b->blood_grid_rows);
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			b->blood_tile_array[i] = (int*)malloc(sizeof(int) * b->blood_grid_columns);
		}
		b->pos = (Vec*)calloc(b->blood_grid_size, sizeof(Vec));
		b->blood_grid_value = (int*)calloc(b->blood_grid_size, sizeof(int));	
		b->frame_x = 0;
		b->frame_y = 0;
		b->frame_size = 10;
	}

	void place_blood_tiles(Blood_Grid *b)
	{
		int current_tile = 0;
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			for (int j = 0; j < b->blood_grid_columns; j++)
			{
				b->pos[current_tile].x = j * b->tile_size;
				b->pos[current_tile].y = i * b->tile_size;
				b->blood_grid_value[current_tile] = rand() % 3;
				current_tile++;
			}
		}
	}

	void update(Blood_Grid *b)
	{
		
	}

	void draw(Blood_Grid *b, Camera::Camera *c, SDL_Texture *blood_texture, SDL_Rect blood_tile_src, SDL_RendererFlip fliptype)
	{
		SDL_Rect blood_dest;
		for (int i = 0; i < b->blood_grid_size; i++)
		{
			if (b->pos[i].x + b->tile_size < (c->cam_center.x - screen_width / 2)) continue;
			else if (b->pos[i].x > (c->cam_center.x + screen_width / 2)) continue;
			else if (b->pos[i].y + b->tile_size < (c->cam_center.y - screen_height / 2)) continue;
			else if (b->pos[i].y > (c->cam_center.y + screen_height / 2)) continue;

			blood_dest.x = b->pos[i].x - c->cam_center.x + screen_width / 2;
			blood_dest.y = b->pos[i].y - c->cam_center.y + screen_height / 2;
			blood_dest.w = b->tile_size;
			blood_dest.h = b->tile_size;

			
			if (b->blood_grid_value[i] == 0) blood_tile_src.x = 10;
			if (b->blood_grid_value[i] == 1) blood_tile_src.x = 0;
			if (b->blood_grid_value[i] == 2) blood_tile_src.x = 20;

			SDL_SetTextureAlphaMod(blood_texture, 255);
			SDL_RenderCopyEx(renderer, blood_texture, &blood_tile_src, &blood_dest, 0, NULL, fliptype);
		}
	}
}

enum Interface
{
	start,
	gameplay,
	game_over,
	win
};

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER);
	TTF_Init();
	SDL_StartTextInput();
	srand(time(0));

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 2048);

	SDL_Window *window = SDL_CreateWindow("Crimson Canvas", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface *bg_surface = IMG_Load(Images::bg_filename);
	assert(bg_surface);
	SDL_Texture *bg_texture = SDL_CreateTextureFromSurface(renderer, bg_surface);
	SDL_FreeSurface(bg_surface);
	SDL_RendererFlip fliptype = SDL_FLIP_NONE;

	SDL_Surface *p1_surface = IMG_Load(Images::player_filename);
	assert(p1_surface);
	SDL_Texture *p1_texture = SDL_CreateTextureFromSurface(renderer, p1_surface);
	SDL_FreeSurface(p1_surface);

	SDL_Surface *blood_surface = IMG_Load(Images::blood_filename);
	assert(blood_surface);
	SDL_Texture *blood_texture = SDL_CreateTextureFromSurface(renderer, blood_surface);
	SDL_FreeSurface(blood_surface);

	unsigned int current_mouse_state = 0;
	unsigned int prev_mouse_state = 0;
	unsigned int game_start_time = SDL_GetTicks();
	unsigned int current_time = game_start_time;
	unsigned int last_frame_time = 0;

	unsigned char *key_state = (unsigned char*)SDL_GetKeyboardState(NULL);
	static unsigned char last_key_state[256];
	memset(last_key_state, 0, 256);

	Input::init();
	Backgrounds::Backgrounds bg;
	Backgrounds::init(&bg);
	Blood_Grid::Blood_Grid b;
	Blood_Grid::init(&b, &bg);
	Blood_Grid::place_blood_tiles(&b);
	Camera::Camera c;
	Camera::init(&c);

	Player::Player p1;
	Player::init(&p1);
	p1.facing = Player::right;
	p1.pos.x = 400;
	p1.pos.y = 500;
	p1.frame_y = 0;

	Player::Player p2;
	Player::init(&p2);
	p2.facing = Player::left;
	p2.pos.x = 1220;
	p2.pos.y = 500;
	p2.frame_y = 128;

	const int ground_y = 1012;
	int collision = 0;

	for (;;)
	{
		current_time = SDL_GetTicks();
		memcpy(last_key_state, key_state, 256);
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return 0;
			}
		}
		if (key_state[SDL_SCANCODE_ESCAPE])
		{
			return 0;
		}

		dt = 1 * (current_time - last_frame_time);
		last_frame_time = current_time;
		if (current_time - last_frame_time < 15)
		{
			/*
			front punch is x
			back punch is y
			front kick is a
			back kick is b
			*/
			Input::update();

			p1.accel.x = {};
			p1.accel.y = {};
			if (P1_RIGHTTRIGGER > Input::stick_dead_zone || key_state[SDL_SCANCODE_SEMICOLON])
			{
				p1.state = Player::blocking;
				p1.f_move = 0;
				p1.frame_x = 576;
				p1.current_frame = 0;
			}
			if (P1_LEFTY < -Input::stick_dead_zone|| P1_DPAD_UP == 1|| key_state[SDL_SCANCODE_W])
			{
				if (p1.state != Player::blocking)
				{
					if (p1.pos.y + p1.height * 4 >= ground_y)
					{
						p1.state = Player::jumping;
						p1.accel.y -= p1.f_jump;
						if (current_time - p1.last_frame_change_time >= p1.frame_duration)
						{
							p1.current_frame = (p1.current_frame + 1) % (p1.n_frames - 1);
							p1.last_frame_change_time = current_time;
						}
					}
				}
			}
			if (P1_LEFTX < -Input::stick_dead_zone || P1_DPAD_LEFT == 1 || key_state[SDL_SCANCODE_A])
			{
				if (p1.state != Player::blocking)
				{
					if (p1.state != Player::jumping) p1.state = Player::walking;
					p1.f_move = 0.5;
					p1.facing = Player::left;
					p1.frame_x = 0;
					p1.frame_y = 128;
					p1.accel.x += -p1.f_move;
					if (current_time - p1.last_frame_change_time >= p1.frame_duration)
					{
						p1.current_frame = (p1.current_frame + 1) % (p1.n_frames - 1);
						p1.last_frame_change_time = current_time;
					}
				}
			}
			else if (P1_LEFTX > Input::stick_dead_zone || P1_DPAD_RIGHT == 1 || key_state[SDL_SCANCODE_D])
			{
					if (p1.state != Player::blocking)
					{
						if (p1.state != Player::jumping) p1.state = Player::walking;
						p1.f_move = 0.5;
						p1.facing = Player::right;
						p1.frame_x = 0;
						p1.frame_y = 0;
						p1.accel.x += p1.f_move;
						if (current_time - p1.last_frame_change_time >= p1.frame_duration)
						{
							p1.current_frame = (p1.current_frame + 1) % (p1.n_frames - 1);
							p1.last_frame_change_time = current_time;
						}
					}
			}
			else
			{
				if (p1.state != Player::blocking)
				{
					if (p1.state != Player::jumping) p1.state = Player::idle;
					p1.frame_x = 576;
					p1.current_frame = 0;
				}
			}

			p2.accel.x = {};
			p2.accel.y = {};
			if (P2_RIGHTTRIGGER > Input::stick_dead_zone || key_state[SDL_SCANCODE_KP_1])
			{
				p2.state = Player::blocking;
				p2.f_move = 0;
				p2.frame_x = 576;
				p2.current_frame = 0;
			}
			if (P2_LEFTY < -Input::stick_dead_zone || P2_DPAD_UP == 1 || key_state[SDL_SCANCODE_UP])
			{
				if (p2.state != Player::blocking)
				{
					if (p2.pos.y + p2.height * 4 >= ground_y)
					{
						p2.state = Player::jumping;
						p2.accel.y -= p2.f_jump;
						if (current_time - p2.last_frame_change_time >= p2.frame_duration)
						{
							p2.current_frame = (p2.current_frame + 1) % (p2.n_frames - 1);
							p2.last_frame_change_time = current_time;
						}
					}
				}
			}
			if (P2_LEFTX < -Input::stick_dead_zone || P2_DPAD_LEFT == 1 || key_state[SDL_SCANCODE_LEFT])
			{
				if (p2.state != Player::blocking)
				{
					if (p2.state != Player::jumping) p2.state = Player::walking;
					p2.f_move = 0.5;
					p2.facing = Player::left;
					p2.frame_x = 0;
					p2.frame_y = 128;
					p2.accel.x += -p2.f_move;
					if (current_time - p2.last_frame_change_time >= p2.frame_duration)
					{
						p2.current_frame = (p2.current_frame + 1) % (p2.n_frames - 1);
						p2.last_frame_change_time = current_time;
					}
				}
			}
			else if (P2_LEFTX > Input::stick_dead_zone || P2_DPAD_RIGHT == 1 || key_state[SDL_SCANCODE_RIGHT])
			{
				if (p2.state != Player::blocking)
				{
					if (p2.state != Player::jumping) p2.state = Player::walking;
					p2.f_move = 0.5;
					p2.facing = Player::right;
					p2.frame_x = 0;
					p2.frame_y = 0;
					p2.accel.x += p2.f_move;
					if (current_time - p2.last_frame_change_time >= p2.frame_duration)
					{
						p2.current_frame = (p2.current_frame + 1) % (p2.n_frames - 1);
						p2.last_frame_change_time = current_time;
					}
				}
			}
			else
			{
				if (p2.state != Player::blocking)
				{
					if (p2.state != Player::jumping) p2.state = Player::idle;
					p2.frame_x = 576;
					p2.current_frame = 0;
				}
			}


			if (p1.state == Player::jumping) printf("jumping\n");
			else if (p1.state == Player::walking) printf("walking\n");
			else if (p1.state == Player::idle) printf("idle\n");
			else if (p1.state == Player::blocking) printf("blocking\n");
			//if (p1.facing == Player::right) printf("right\n");
			//else if (p1.facing == Player::left) printf("left\n");
			
			collision = Player::check_Opponent_Collision(&p1, &p2);
			Player::update(&p1, &c, &p2, collision);
			Camera::update(&c);
			collision = Player::check_Opponent_Collision(&p2, &p1);
			Player::update(&p2, &c, &p1, collision);
			Camera::update(&c);

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			SDL_Rect p1_src = { p1.frame_x + p1.current_frame * p1.width, p1.frame_y, p1.width, p1.height};
			SDL_Rect p2_src = { p2.frame_x + p2.current_frame * p2.width, p2.frame_y, p2.width, p2.height };
			SDL_Rect bg_src = { 0, 0, 1920, 1080 };
			SDL_Rect blood_tile_src = { 0, 0 , b.frame_size, b.frame_size };

			Backgrounds::draw(&bg, &c, bg_texture, bg_src, fliptype);
			Blood_Grid::draw(&b, &c, blood_texture, blood_tile_src, fliptype);
			Player::draw(&p1, &c, p1_texture, p1_src, fliptype);
			Player::draw(&p2, &c, p1_texture, p2_src, fliptype);

			SDL_RenderPresent(renderer);
		}
	}
}