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




SDL_Renderer *renderer = NULL;
int screen_width = 1920;
int screen_height = 1080;
double dt = 1;

namespace Images
{
	const char* Camila_filename = "Sprites\\Camila_walk.png";
	const char* TK_filename = "Sprites\\Tk.png";
	const char* bg_filename = "Sprites\\bg.png";
	const char* blood_filename = "Sprites\\blood.png";
}

struct Vec
{
	float x, y;
};

struct Box
{
	float x, y, w, h;
	int damage;
};
namespace Character_Data
{
	int n_hurt_boxes = 4;

	struct Camila
	{

	};


	struct TK
	{
		int id = 1;

		float head_offset_x = 185;
		float head_offset_y = 40;
		float head_w = 90;
		float head_h = 60;

		float shoulder_offset_x = 125;
		float shoulder_offset_y = 80;
		float shoulder_w = 160;
		float shoulder_h = 100;

		float torso_offset_x = 130;
		float torso_offset_y = 175;
		float torso_w = 150;
		float torso_h = 90;

		float leg_offset_x = 130;
		float leg_offset_y = 260;
		float leg_w = 190;
		float leg_h = 150;

		int collision_offset_x = 60;
		int collision_offset_y = 40;
		int width = 470;
		int height = 540;
		int collision_width = 190;
		int collision_height = 500;
		int first_frame_x = 0;
		int first_frame_y = 540;
		int n_walk_frames = 8;
		int walk_duration = 100;
		int n_idle_frames = 4;
		int idle_duration = 50;
	};

	struct Wrecca
	{

	};
}

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
		c->cam_center.x = 1920;
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
		const int n_players = 2;
		player_States* state;
		player_Facing* facing;
		player_Facing* collision_facing;
		Vec* pos;
		Vec* collision_pos;
		Vec* collision_offset;
		Vec* accel;
		Vec* vel;
		Vec* head_offset;
		Vec* shoulder_offset;
		Vec* torso_offset;
		Vec* leg_offset;
		Box** hurt_boxes;
		Box** hit_boxes;
		SDL_Texture** texture;
		SDL_RendererFlip* player_flip;
		char* crouched;
		float max_vel;
		float max_jump_vel;
		float* f_move;
		float f_jump;
		float f_fall;
		int jump_duration;
		int* width;
		int* height;
		int* collision_width;
		int* collision_height;

		int n_hurt_boxes;
		int n_hit_boxes;

		Vec* frame_pos;
		int *walk_duration;
		int *idle_duration;
		int *n_walk_frames;
		int *n_idle_frames;
		unsigned int *last_frame_change_time;
		int *current_frame;
	};

	void allocate(Player *p)
	{
		p->state = (player_States*)malloc(sizeof(player_States) * p->n_players);
		p->facing = (player_Facing*)malloc(sizeof(player_Facing) * p->n_players);
		p->pos = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->collision_pos = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->collision_offset = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->accel = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->vel = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->head_offset = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->shoulder_offset = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->torso_offset = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->leg_offset = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->texture = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * p->n_players);
		p->player_flip = (SDL_RendererFlip*)malloc(sizeof(SDL_RendererFlip) * p->n_players);
		p->crouched = (char*)calloc(p->n_players, sizeof(char));
		p->max_vel = 0.01;
		p->f_move = (float*)malloc(sizeof(float)*p->n_players);
		p->f_jump = 1.0;
		p->f_fall = 5.0;
		p->jump_duration = 225;
		p->width = (int*)malloc(sizeof(int) * p->n_players);
		p->height = (int*)malloc(sizeof(int) * p->n_players);
		p->collision_width = (int*)malloc(sizeof(int) * p->n_players);
		p->collision_height = (int*)malloc(sizeof(int) * p->n_players);

		p->n_hurt_boxes = Character_Data::n_hurt_boxes;
		p->hurt_boxes = (Box**)malloc(sizeof(Box*) * p->n_hurt_boxes);
		for (int i = 0; i < p->n_players; i++)
		{
			p->hurt_boxes[i] = (Box*)malloc(sizeof(Box) * p->n_hurt_boxes);
		}
		p->frame_pos = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->walk_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->idle_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->n_walk_frames = (int*)malloc(sizeof(int) * p->n_players);
		p->n_idle_frames = (int*)malloc(sizeof(int) * p->n_players);
		p->last_frame_change_time = (unsigned int*)malloc(sizeof(unsigned int) * p->n_players);
		p->current_frame = (int*)malloc(sizeof(int) * p->n_players);
	}

	int check_Opponent_Collision(Player *p)
	{
		if (p->collision_pos[0].x + p->collision_width[0]  < p->collision_pos[1].x) return 0;
		else if (p->collision_pos[0].x > p->collision_pos[1].x + p->collision_width[1]) return 0;
		else if (p->collision_pos[0].y + p->collision_height[0] < p->collision_pos[1].y) return 0;
		else if (p->collision_pos[0].y > p->collision_pos[1].y + p->collision_height[1]) return 0;

		else return 1;
	}

	void update(Player *p, Camera::Camera *c, int ground_y)
	{
		c->accel.x = {};
		c->accel.y = {};
		for (int i = 0; i < p->n_players; i++)
		{
			p->vel[i].x += p->accel[i].x * dt;
			p->vel[i].y += p->accel[i].y * dt;

			p->pos[i].x += p->vel[i].x * dt;
			p->pos[i].y += p->vel[i].y * dt;

			p->collision_pos[0].x = p->pos[0].x + p->collision_offset[0].x;
			p->collision_pos[0].y = p->pos[0].y + p->collision_offset[0].y;
			if (p->crouched[0] == 1) p->collision_pos[0].y += p->collision_height[0];
			p->collision_pos[1].x = p->pos[1].x + p->collision_offset[1].x;
			p->collision_pos[1].y = p->pos[1].y + p->collision_offset[1].y;
			if (p->crouched[1] == 1) p->collision_pos[1].y += p->collision_height[1];

			if (check_Opponent_Collision(p) == 1)
			{
					for (int j = 0; j < 20; j++)
					{
						if (p->state[i] != jumping && j >= 10) break;
						p->pos[0].x += -0.1 * p->vel[0].x * dt;
						p->pos[1].x += -0.1 * p->vel[1].x * dt;
					}
			}
			
			if (p->vel[i].x >= p->max_vel)
			{
				p->vel[i].x = 0;
			}
			if (p->vel[i].x <= -p->max_vel)
			{
				p->vel[i].x = 0;
			}

			if (p->pos[i].x >= c->cam_center.x + 550)
			{
				c->accel.x += c->speed;
				p->pos[i].x = c->cam_center.x + 550;
				p->vel[i].x = 0;
			}
			if (p->pos[i].x <= c->cam_center.x - 1050)
			{
				c->accel.x -= c->speed;
				p->pos[i].x = c->cam_center.x - 1050;
				p->vel[i].x = 0;
			}
			if (p->pos[i].y <= c->cam_center.y - 500)
			{
				p->vel[i].y += 4 * p->f_jump;
				p->pos[i].y = c->cam_center.y - 500;
			}
			if (p->pos[i].y + p->height[i] >= ground_y)
			{
				p->state[i] = idle;
				p->pos[i].y = ground_y - p->height[i];
				p->vel[i].y = 0;
				c->cam_center.y = 540;
			}
			

			p->hurt_boxes[i][0].x = p->pos[i].x + p->head_offset[i].x;
			p->hurt_boxes[i][0].y = p->pos[i].y + p->head_offset[i].y;
			p->hurt_boxes[i][1].x = p->pos[i].x + p->shoulder_offset[i].x;
			p->hurt_boxes[i][1].y = p->pos[i].y + p->shoulder_offset[i].y;
			p->hurt_boxes[i][2].x = p->pos[i].x + p->torso_offset[i].x;
			p->hurt_boxes[i][2].y = p->pos[i].y + p->torso_offset[i].y;
			p->hurt_boxes[i][3].x = p->pos[i].x + p->leg_offset[i].x;
			p->hurt_boxes[i][3].y = p->pos[i].y + p->leg_offset[i].y;

			if (p->facing[i] == left)
			{
				p->hurt_boxes[i][0].x += p->head_offset[i].x / 14;
				p->hurt_boxes[i][1].x += p->shoulder_offset[i].x / 2;
				p->hurt_boxes[i][2].x += p->torso_offset[i].x / 2;
				p->hurt_boxes[i][3].x += p->leg_offset[i].x / 7;
				
			}
			if (p->crouched[i] == 1)
			{
				p->hurt_boxes[i][0].y += p->head_offset[i].y * 3;
				p->hurt_boxes[i][1].y += p->shoulder_offset[i].y * 1.5;
				p->hurt_boxes[i][2].y += p->torso_offset[i].y / 2;
				p->hurt_boxes[i][3].y += p->leg_offset[i].y / 3;
			}
			
		}
	}

	void draw(Player *p, Camera::Camera *c, SDL_Rect src)
	{
		SDL_Rect dest;
		for (int i = 0; i < p->n_players; i++)
		{
			src.x = p->frame_pos[i].x + p->current_frame[i] * p->width[i];
			src.y = p->frame_pos[i].y;
			src.w = p->width[i];
			src.h = p->height[i];

			dest.x = p->pos[i].x - c->cam_center.x + screen_width / 2;
			dest.y = p->pos[i].y - c->cam_center.y + screen_height / 2;
			dest.w = p->width[i];
			dest.h = p->height[i];

			SDL_SetTextureAlphaMod(p->texture[i], 255);
			SDL_RenderCopyEx(renderer, p->texture[i], &src, &dest, 0, NULL, p->player_flip[i]);
		}
	}

	void draw_hurt_boxes(Player *p, Camera::Camera *c)
	{
		SDL_Rect dest;
		for (int i = 0; i < p->n_players; i++)
		{
			for (int j = 0; j < Character_Data::n_hurt_boxes; j++)
			{
				dest.x = p->hurt_boxes[i][j].x - c->cam_center.x + screen_width / 2;
				dest.y = p->hurt_boxes[i][j].y - c->cam_center.y + screen_height / 2;
				dest.w = p->hurt_boxes[i][j].w;
				dest.h = p->hurt_boxes[i][j].h;

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				SDL_RenderDrawRect(renderer, &dest);
			}
		}
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
			if (bg->pos[i].x + screen_width < (c->cam_center.x - screen_width / 2)) continue;
			else if (bg->pos[i].x > (c->cam_center.x + screen_width / 2)) continue;
			else if (bg->pos[i].y + screen_height < (c->cam_center.y - screen_height / 2)) continue;
			else if (bg->pos[i].y > (c->cam_center.y + screen_height / 2)) continue;

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
				b->blood_grid_value[current_tile] = 0;
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

	SDL_Surface *Camila_surface = IMG_Load(Images::Camila_filename);
	assert(Camila_surface);
	SDL_Texture *Camila_texture = SDL_CreateTextureFromSurface(renderer, Camila_surface);
	SDL_FreeSurface(Camila_surface);

	SDL_Surface *TK_surface = IMG_Load(Images::TK_filename);
	assert(TK_surface);
	SDL_Texture *TK_texture = SDL_CreateTextureFromSurface(renderer, TK_surface);
	SDL_FreeSurface(TK_surface);

	SDL_Surface *blood_surface = IMG_Load(Images::blood_filename);
	assert(blood_surface);
	SDL_Texture *blood_texture = SDL_CreateTextureFromSurface(renderer, blood_surface);
	SDL_FreeSurface(blood_surface);

	SDL_Rect TK_src = { 0 };
	SDL_Rect Camila_src = { 0 };

	

	unsigned char *key_state = (unsigned char*)SDL_GetKeyboardState(NULL);
	static unsigned char last_key_state[256];
	memset(last_key_state, 0, 256);

	const int ground_y = 1000;
	Input::init();
	Character_Data::TK tk;
	Character_Data::Camila camila;
	Character_Data::Wrecca wrecca;

	Backgrounds::Backgrounds bg;
	Backgrounds::init(&bg);
	Blood_Grid::Blood_Grid b;
	Blood_Grid::init(&b, &bg);
	Blood_Grid::place_blood_tiles(&b);
	Camera::Camera c;
	Camera::init(&c);

	Player::Player p;
	Player::allocate(&p);
	
	p.texture[0] = TK_texture;
	p.player_flip[0] = SDL_FLIP_NONE;
	p.state[0] = Player::idle;
	p.facing[0] = Player::right;
	p.pos[0].x = 1100;
	p.pos[0].y = ground_y - tk.height;
	p.collision_offset[0].x = tk.collision_offset_x;
	p.collision_offset[0].y = tk.collision_offset_y;
	p.collision_pos[0].x = p.pos[0].x + p.collision_offset[0].x;
	p.collision_pos[0].y = p.pos[0].y + p.collision_offset[0].y;
	p.accel[0].x = 0;
	p.accel[0].y = 0;
	p.vel[0].x = 0;
	p.vel[0].y = 0;
	p.f_move[0] = 0.5;
	p.width[0] = tk.width;
	p.height[0] = tk.height;
	p.collision_width[0] = tk.collision_width;
	p.collision_height[0] = tk.collision_height;
	p.frame_pos[0].x = tk.first_frame_x;
	p.frame_pos[0].y = tk.first_frame_y;
	p.n_walk_frames[0] = tk.n_walk_frames;
	p.walk_duration[0] = tk.walk_duration;
	p.n_idle_frames[0] = tk.n_idle_frames;
	p.idle_duration[0] = tk.idle_duration;
	p.last_frame_change_time[0] = 0;
	p.current_frame[0] = 0;
	p.head_offset[0].x = tk.head_offset_x;
	p.head_offset[0].y = tk.head_offset_y;
	p.hurt_boxes[0][0].x = p.pos[0].x + p.head_offset[0].x;
	p.hurt_boxes[0][0].y = p.pos[0].y + p.head_offset[0].y;
	p.hurt_boxes[0][0].w = tk.head_w;
	p.hurt_boxes[0][0].h = tk.head_h;
	p.shoulder_offset[0].x = tk.shoulder_offset_x;
	p.shoulder_offset[0].y = tk.shoulder_offset_y;
	p.hurt_boxes[0][1].x = p.pos[0].x + p.shoulder_offset[0].x;
	p.hurt_boxes[0][1].y = p.pos[0].y + p.shoulder_offset[0].y;
	p.hurt_boxes[0][1].w = tk.shoulder_w;
	p.hurt_boxes[0][1].h = tk.shoulder_h;
	p.torso_offset[0].x = tk.torso_offset_x;
	p.torso_offset[0].y = tk.torso_offset_y;
	p.hurt_boxes[0][2].x = p.pos[0].x + p.torso_offset[0].x;
	p.hurt_boxes[0][2].y = p.pos[0].y + p.torso_offset[0].y;
	p.hurt_boxes[0][2].w = tk.torso_w;
	p.hurt_boxes[0][2].h = tk.torso_h;
	p.leg_offset[0].x = tk.leg_offset_x;
	p.leg_offset[0].y = tk.leg_offset_y;
	p.hurt_boxes[0][3].x = p.pos[0].x + p.leg_offset[0].x;
	p.hurt_boxes[0][3].y = p.pos[0].y + p.leg_offset[0].y;
	p.hurt_boxes[0][3].w = tk.leg_w;
	p.hurt_boxes[0][3].h = tk.leg_h;



	p.texture[1] = TK_texture;
	p.player_flip[1] = SDL_FLIP_HORIZONTAL;
	p.state[1] = Player::idle;
	p.facing[1] = Player::left;
	p.pos[1].x = 2300;
	p.pos[1].y = ground_y - tk.height;
	p.collision_offset[1].x = tk.collision_offset_x;
	p.collision_offset[1].y = tk.collision_offset_y;
	p.collision_pos[1].x = p.pos[1].x + p.collision_offset[1].x;
	p.collision_pos[1].y = p.pos[1].y + p.collision_offset[1].y;
	p.accel[1].x = 0;
	p.accel[1].y = 0;
	p.vel[1].x = 0;
	p.vel[1].y = 0;
	p.f_move[1] = 0.5;
	p.width[1] = tk.width;
	p.height[1] = tk.height;
	p.collision_width[1] = tk.collision_width;
	p.collision_height[1] = tk.collision_height;
	p.frame_pos[1].x = tk.first_frame_x;
	p.frame_pos[1].y = tk.first_frame_y;
	p.n_walk_frames[1] = tk.n_walk_frames;
	p.walk_duration[1] = tk.walk_duration;
	p.idle_duration[0] = tk.idle_duration;
	p.n_idle_frames[1] = tk.n_idle_frames;
	p.last_frame_change_time[1] = 0;
	p.current_frame[1] = 0;
	p.head_offset[1].x = tk.head_offset_x;
	p.head_offset[1].y = tk.head_offset_y;
	p.hurt_boxes[1][0].x = p.pos[1].x + p.head_offset[1].x;
	p.hurt_boxes[1][0].y = p.pos[1].y + p.head_offset[1].y;
	p.hurt_boxes[1][0].w = tk.head_w;
	p.hurt_boxes[1][0].h = tk.head_h;
	p.shoulder_offset[1].x = tk.shoulder_offset_x;
	p.shoulder_offset[1].y = tk.shoulder_offset_y;
	p.hurt_boxes[1][1].x = p.pos[1].x + p.shoulder_offset[1].x;
	p.hurt_boxes[1][1].y = p.pos[1].y + p.shoulder_offset[1].y;
	p.hurt_boxes[1][1].w = tk.shoulder_w;
	p.hurt_boxes[1][1].h = tk.shoulder_h;
	p.torso_offset[1].x = tk.torso_offset_x;
	p.torso_offset[1].y = tk.torso_offset_y;
	p.hurt_boxes[1][2].x = p.pos[1].x + p.torso_offset[1].x;
	p.hurt_boxes[1][2].y = p.pos[1].y + p.torso_offset[1].y;
	p.hurt_boxes[1][2].w = tk.torso_w;
	p.hurt_boxes[1][2].h = tk.torso_h;
	p.leg_offset[1].x = tk.leg_offset_x;
	p.leg_offset[1].y = tk.leg_offset_y;
	p.hurt_boxes[1][3].x = p.pos[1].x + p.leg_offset[1].x;
	p.hurt_boxes[1][3].y = p.pos[1].y + p.leg_offset[1].y;
	p.hurt_boxes[1][3].w = tk.leg_w;
	p.hurt_boxes[1][3].h = tk.leg_h;

	
	unsigned int current_mouse_state = 0;
	unsigned int prev_mouse_state = 0;
	unsigned int game_start_time = SDL_GetTicks();
	unsigned int current_time = game_start_time;
	unsigned int last_frame_time = game_start_time;

	for (;;)
	{
		
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

		current_time = SDL_GetTicks();
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

			p.accel[0].x = {};
			p.accel[0].y = {};

			if (P1_RIGHTTRIGGER > Input::stick_dead_zone || key_state[SDL_SCANCODE_SEMICOLON])
			{
				p.state[0] = Player::blocking;
				p.f_move[0] = 0;
				p.frame_pos[0].x = 0;
				p.frame_pos[0].y = 540;
				p.current_frame[0] = 0;
			}
			if (P1_LEFTY > Input::stick_dead_zone || P1_DPAD_DOWN == 1 || key_state[SDL_SCANCODE_S])
			{
				if (p.state[0] != Player::jumping)
				{
					p.crouched[0] = 1;
					p.state[0] = Player::blocking;
					p.frame_pos[0].x = 0;
					p.frame_pos[0].y = 1080;
					p.current_frame[0] = 0;
				}
			}
			else p.crouched[0] = 0;

			if (P1_LEFTY < -Input::stick_dead_zone || P1_DPAD_UP == 1 || key_state[SDL_SCANCODE_W])
			{
				if (p.state[0] != Player::blocking)
				{
					if (p.pos[0].y + p.height[0] >= ground_y)
					{
						p.state[0] = Player::jumping;
						p.frame_pos[0].y = 540;
						p.current_frame[0] = 0;
						p.accel[0].y -= p.f_jump;
						/*if (current_time - p.last_frame_change_time[0] >= p.idle_duration[0])
						{
							p.current_frame[0] = (p.current_frame[0] + 1) % p.n_idle_frames[0];
							p.last_frame_change_time[0] = current_time;
						}*/
					}
				}
			}

			if (P1_LEFTX < -Input::stick_dead_zone || P1_DPAD_LEFT == 1 || key_state[SDL_SCANCODE_A])
			{
				if (p.state[0] != Player::blocking)
				{
					if (p.state[0] != Player::jumping) p.state[0] = Player::walking;
					p.f_move[0] = 0.5;
					p.facing[0] = Player::left;
					p.player_flip[0] = SDL_FLIP_HORIZONTAL;
					p.frame_pos[0].x = 0;
					p.frame_pos[0].y = 0;
					p.accel[0].x += -p.f_move[0];
					if (current_time - p.last_frame_change_time[0] >= p.walk_duration[0])
					{
						p.current_frame[0] = (p.current_frame[0] + 1) % p.n_walk_frames[0];
						p.last_frame_change_time[0] = current_time;
					}
				}
			}
			else if (P1_LEFTX > Input::stick_dead_zone || P1_DPAD_RIGHT == 1 || key_state[SDL_SCANCODE_D])
			{
				if (p.state[0] != Player::blocking)
				{
					if (p.state[0] != Player::jumping) p.state[0] = Player::walking;
					p.f_move[0] = 0.5;
					p.facing[0] = Player::right;
					p.player_flip[0] = SDL_FLIP_NONE;
					p.frame_pos[0].x = 0;
					p.frame_pos[0].y = 0;
					p.accel[0].x += p.f_move[0];
					if (current_time - p.last_frame_change_time[0] >= p.walk_duration[0])
					{
						p.current_frame[0] = (p.current_frame[0] + 1) % p.n_walk_frames[0];
						p.last_frame_change_time[0] = current_time;
					}
				}
			}
			else
			{
				if (p.state[0] != Player::blocking)
				{
					if (p.state[0] != Player::jumping) p.state[0] = Player::idle;
					p.frame_pos[0].x = 0;
					p.frame_pos[0].y = 540;
					p.current_frame[0] = 0;
					/*if (current_time - p.last_frame_change_time[0] >= p.idle_duration[0])
					{
						p.current_frame[0] = (p.current_frame[0] + 1) % p.n_idle_frames[0];
						p.last_frame_change_time[0] = current_time;
					}*/
				}
			}

			p.accel[1].x = {};
			p.accel[1].y = {};
			if (P2_RIGHTTRIGGER > Input::stick_dead_zone || key_state[SDL_SCANCODE_KP_1])
			{
				if (p.state[1] != Player::jumping)
				{
					p.state[1] = Player::blocking;
					p.f_move[1] = 0;
					p.frame_pos[1].y = 540;
					p.current_frame[1] = 0;
				}
			}
			if (P2_LEFTY > Input::stick_dead_zone || P2_DPAD_DOWN == 1 || key_state[SDL_SCANCODE_DOWN])
			{
				if (p.state[1] != Player::jumping)
				{
					p.state[1] = Player::blocking;
					p.crouched[1] = 1;
					p.frame_pos[1].x = 0;
					p.frame_pos[1].y = 1080;
					p.current_frame[1] = 0;
				}
			}
			else p.crouched[1] = 0;

			if (P2_LEFTY < -Input::stick_dead_zone || P2_DPAD_UP == 1 || key_state[SDL_SCANCODE_UP])
			{
				if (p.state[1] != Player::blocking)
				{
					if (p.pos[1].y + p.height[1] >= ground_y)
					{
						p.state[1] = Player::jumping;
						p.accel[1].y -= p.f_jump;
						p.frame_pos[1].y = 540;
						p.current_frame[1] = 0;
						/*if (current_time - p.last_frame_change_time[1] >= p.walk_duration[1])
						{
							p.current_frame[1] = (p.current_frame[1] + 1) % (p.n_walk_frames[1]);
							p.last_frame_change_time[0] = current_time;
						}*/
					}
				}
			}

			
			if (P2_LEFTX < -Input::stick_dead_zone || P2_DPAD_LEFT == 1 || key_state[SDL_SCANCODE_LEFT])
			{
				if (p.state[1] != Player::blocking)
				{
					if (p.state[1] != Player::jumping) p.state[1] = Player::walking;
					p.f_move[1] = 0.5;
					p.facing[1] = Player::left;
					p.player_flip[1] = SDL_FLIP_HORIZONTAL;
					p.frame_pos[1].x = 0;
					p.frame_pos[1].y = 0;
					p.accel[1].x += -p.f_move[1];
					if (current_time - p.last_frame_change_time[1] >= p.walk_duration[1])
					{
						p.current_frame[1] = (p.current_frame[1] + 1) % p.n_walk_frames[1];
						p.last_frame_change_time[1] = current_time;
					}
				}
			}
			else if (P2_LEFTX > Input::stick_dead_zone || P2_DPAD_RIGHT == 1 || key_state[SDL_SCANCODE_RIGHT])
			{
				if (p.state[1] != Player::blocking)
				{
					if (p.state[1] != Player::jumping) p.state[1] = Player::walking;
					p.f_move[1] = 0.5;
					p.facing[1] = Player::right;
					p.player_flip[1] = SDL_FLIP_NONE;
					p.frame_pos[1].x = 0;
					p.frame_pos[1].y = 0;
					p.accel[1].x += p.f_move[1];
					if (current_time - p.last_frame_change_time[1] >= p.walk_duration[1])
					{
						p.current_frame[1] = (p.current_frame[1] + 1) % p.n_walk_frames[1];
						p.last_frame_change_time[1] = current_time;
					}
				}
			}
			else
			{
				if (p.state[1] != Player::blocking)
				{
					if (p.state[1] != Player::jumping) p.state[1] = Player::idle;
					p.frame_pos[1].x = 0;
					p.frame_pos[1].y = 540;
					p.current_frame[1] = 0;
					/*if (current_time - p.last_frame_change_time[0] >= p.idle_duration[0])
					{
						p.current_frame[0] = (p.current_frame[0] + 1) % p.n_idle_frames[0];
						p.last_frame_change_time[0] = current_time;
					}*/
				}
			}
						//if (p1.state == Player::jumping) printf("jumping\n");
			//else if (p1.state == Player::walking) printf("walking\n");
			//else if (p1.state == Player::idle) printf("idle\n");
			//else if (p1.state == Player::blocking) printf("blocking\n");
			//if (p1.facing == Player::right) printf("right\n");
			//else if (p1.facing == Player::left) printf("left\n");
			Camera::update(&c);
			Player::update(&p, &c, ground_y);
			

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);

			SDL_Rect bg_src = { 0, 0, 1920, 1080 };
			SDL_Rect blood_tile_src = { 0, 0 , b.frame_size, b.frame_size };

			Backgrounds::draw(&bg, &c, bg_texture, bg_src, fliptype);
			Blood_Grid::draw(&b, &c, blood_texture, blood_tile_src, fliptype);
			Player::draw(&p, &c, TK_src);
			Player::draw_hurt_boxes(&p, &c);

			SDL_RenderPresent(renderer);
		}
	}
}
