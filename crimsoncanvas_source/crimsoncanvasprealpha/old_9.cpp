//NEED TO FIX: KEYBOARD STATES DO NOT WORK WHEN FPS IS LOCKED

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
const int screen_width = 1920;
const int screen_height = 1080;
double dt = 5.0;
const double f_gravity = 0.02;

int player_button[2] = { 0 };
char player_ready[2] = { 0 };
int clicked_character[2] = { -1 };
int chosen_character[2] = { -1 };
const int frame_limit = 60;


namespace Images
{
	const char* main_menu_filename = "Sprites\\main_menu.png";
	const char* character_menu_filename = "Sprites\\character_menu.png";
	const char* Camila_filename = "Sprites\\Camila_walk.png";
	const char* TK_filename = "Sprites\\TkFin.png";
	const char* blood_filename = "Sprites\\blood.png";
	const int n_blood_particle_frames = 2;
	const char* blood_particle_filenames[2] = { "Sprites\\red_blood_particle.png", "Sprites\\green_blood_particle.png" };

	/*(const int n_title_frames = 39;
	const char* title_filenames[n_title_frames] = {
	"Sprites\\title_screen\\title_00.png", "Sprites\\title_screen\\title_01.png","Sprites\\title_screen\\title_02.png",
	"Sprites\\title_screen\\title_03.png", "Sprites\\title_screen\\title_04.png", "Sprites\\title_screen\\title_05.png",
	"Sprites\\title_screen\\title_06.png", "Sprites\\title_screen\\title_07.png", "Sprites\\title_screen\\title_08.png",
	"Sprites\\title_screen\\title_09.png", "Sprites\\title_screen\\title_11.png", "Sprites\\title_screen\\title_11.png",
	"Sprites\\title_screen\\title_12.png", "Sprites\\title_screen\\title_13.png", "Sprites\\title_screen\\title_14.png",
	"Sprites\\title_screen\\title_15.png", "Sprites\\title_screen\\title_16.png", "Sprites\\title_screen\\title_17.png",
	"Sprites\\title_screen\\title_18.png", "Sprites\\title_screen\\title_19.png", "Sprites\\title_screen\\title_20.png",
	"Sprites\\title_screen\\title_21.png", "Sprites\\title_screen\\title_22.png", "Sprites\\title_screen\\title_23.png",
	"Sprites\\title_screen\\title_24.png", "Sprites\\title_screen\\title_25.png", "Sprites\\title_screen\\title_26.png",
	"Sprites\\title_screen\\title_27.png", "Sprites\\title_screen\\title_28.png", "Sprites\\title_screen\\title_29.png",
	"Sprites\\title_screen\\title_30.png", "Sprites\\title_screen\\title_31.png", "Sprites\\title_screen\\title_32.png",
	"Sprites\\title_screen\\title_33.png", "Sprites\\title_screen\\title_34.png", "Sprites\\title_screen\\title_35.png",
	"Sprites\\title_screen\\title_36.png", "Sprites\\title_screen\\title_37.png", "Sprites\\title_screen\\title_38.png"
	};*/
	const char* title_filename = "Sprites\\title.png";

	const int n_level_2_frames = 16;
	const char* level_2_filenames[n_level_2_frames] = {
		"Stages\\Level2_0.png", "Stages\\Level2_1.png","Stages\\Level2_2.png","Stages\\Level2_3.png",
		"Stages\\Level2_4.png","Stages\\Level2_5.png", "Stages\\Level2_6.png", "Stages\\Level2_7.png",
		"Stages\\Level2_8.png", "Stages\\Level2_9.png","Stages\\Level2_10.png", "Stages\\Level2_11.png",
		"Stages\\Level2_12.png", "Stages\\Level2_13.png", "Stages\\Level2_14.png", "Stages\\Level2_15.png"
	};

}

struct Vec
{
	float x, y;
};

struct Box
{
	float x, y, w, h, offset_x, offset_y;
	int damage, current_row, current_column, was_hit;
	char active;
};

namespace Character_Data
{
	const int n_hurt_boxes = 4;
	const int n_hit_boxes = 20;

	//character index 0;
	struct TK
	{
		float f_move = 1.0;

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
		float leg_h = 190;

		int collision_offset_x = 60;
		int collision_offset_y = 40;
		int width = 470;
		int height = 540;
		int collision_width = 190;
		int collision_height = 270;

		int front_punch_hit_x = 275;
		int front_punch_hit_y = 80;
		int front_punch_hit_w = 160;
		int front_punch_hit_h = 160;
		int front_punch_damage = 20;

		int back_punch_hit_x = 300;
		int back_punch_hit_y = 140;
		int back_punch_hit_w = 125;
		int back_punch_hit_h = 90;
		int back_punch_damage = 15;

		int first_frame_x = 0;
		int first_frame_y = 540;
		int n_walk_frames = 8;
		int walk_duration = 75;
		int n_idle_frames = 4;
		int idle_duration = 180;
		int n_jump_frames = 9;
		int jump_duration = 190;
		int n_front_punch_frames = 4;
		int front_punch_duration = 150;
		int n_back_punch_frames = 4;
		int back_punch_duration = 150;

		int blood_shade = 1;
	};

	//character index 1;
	struct Wrecca
	{
		float f_move = 1.0;

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
		float leg_h = 190;

		int collision_offset_x = 60;
		int collision_offset_y = 40;
		int width = 470;
		int height = 540;
		int collision_width = 190;
		int collision_height = 270;

		int front_punch_hit_x = 275;
		int front_punch_hit_y = 80;
		int front_punch_hit_w = 160;
		int front_punch_hit_h = 160;
		int front_punch_damage = 20;

		//not done
		int back_punch_hit_x = 300;
		int back_punch_hit_y = 140;
		int back_punch_hit_w = 125;
		int back_punch_hit_h = 90;
		int back_punch_damage = 15;

		int first_frame_x = 0;
		int first_frame_y = 540;

		//not done
		int n_walk_frames = 8;
		int walk_duration = 75;

		int n_idle_frames = 10;
		int idle_duration = 180;

		//not done
		int n_jump_frames = 9;
		int jump_duration = 190;

		int n_front_punch_frames = 12;
		int front_punch_duration = 150;
		
		//not done
		int n_back_punch_frames = 4;
		int back_punch_duration = 150;
	};

	//character index 2;
	struct Camila
	{
		//need data
	};
}

namespace Input
{
	int mx, my, m_left, last_m_left, m_right, last_m_right;

	const int max_game_controllers = 2;
	const int num_sticks = 6;
	const int num_buttons = 15;
	const int stick_dead_zone = 13000;
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

namespace Particles
{
	struct Particles
	{
		Vec *pos;
		Vec *vel;
		Vec *accel;
		const int max_particles = 10000;
		char *active;
		int *duration;
		int *spawn_time;
		int *current_row;
		int *current_column;
		int *shade;
		int width;
		int height;
		int r;
		int g;
		int b;
	};

	void init_Blood(Particles *blood)
	{
		blood->pos = (Vec*)malloc(sizeof(Vec) * blood->max_particles);
		blood->vel = (Vec*)malloc(sizeof(Vec) * blood->max_particles);
		blood->accel = (Vec*)malloc(sizeof(Vec) * blood->max_particles);
		blood->active = (char*)calloc(blood->max_particles, sizeof(char));
		blood->duration = (int*)malloc(sizeof(int) * blood->max_particles);
		blood->spawn_time = (int*)malloc(sizeof(int) * blood->max_particles);
		blood->current_row = (int*)malloc(sizeof(int) * blood->max_particles);
		blood->current_column = (int*)malloc(sizeof(int) * blood->max_particles);
		blood->shade = (int*)malloc(sizeof(int) * blood->max_particles);
		blood->width = 10;
		blood->height = 10;
		blood->r = 255;
		blood->g = 0;
		blood->b = 0;
	}

	void create_Blood(Particles *blood, float spawn_x, float spawn_y, int damage, const int facing, const int player_shade, int time)
	{
		for (int i = 0; i < damage; i++)
		{
			if (blood->active[i] == 1)
			{
				damage++;
				continue;
			}
			blood->spawn_time[i] = SDL_GetTicks();
			blood->shade[i] = player_shade;
			blood->accel[i].x = 0;
			blood->accel[i].y = 0;
			blood->accel[i].x = {};
			blood->accel[i].y = {};
			blood->vel[i].x = 1.5 * (1.0 - 2.0 * rand() / RAND_MAX);
			blood->vel[i].y = 1.5 * (1.0 - 2.0 * rand() / RAND_MAX);
			blood->pos[i].x = spawn_x + rand() % 50 - 10;
			blood->pos[i].y = spawn_y - rand() % 50;
			blood->duration[i] = 300;
			blood->active[i] = 1;
		}
	}

	void update_Blood(Particles *blood, unsigned int current_time, const int ground_y)
	{
		for (int i = 0; i < blood->max_particles; i++)
		{
			if (blood->active[i] == 1)
			{
				if (current_time - blood->spawn_time[i] >= blood->duration[i])
				{
					blood->active[i] = 0;
					continue;
				}

				blood->accel[i].y += f_gravity;

				blood->vel[i].x += blood->accel[i].x * dt;
				blood->vel[i].y += blood->accel[i].y * dt;
				blood->pos[i].x += blood->vel[i].x * dt;
				blood->pos[i].y += blood->vel[i].y * dt;
				
				if (blood->pos[i].y >= ground_y) blood->active[i] = 0;
			}
		}
	}

	void draw_Blood(Particles *blood, SDL_Texture **textures, SDL_Rect src, Camera::Camera *c, SDL_RendererFlip fliptype)
	{
		SDL_Rect blood_rect;
		blood_rect.w = blood->width;
		blood_rect.h = blood->height;
		for (int i = 0; i < blood->max_particles; i++)
		{
			if (blood->active[i] == 1)
			{
				blood_rect.x = blood->pos[i].x - c->cam_center.x + screen_width / 2;
				blood_rect.y = blood->pos[i].y - c->cam_center.y + screen_height / 2;
				
				SDL_SetTextureAlphaMod(textures[blood->shade[i]], 255);
				SDL_RenderCopyEx(renderer, textures[blood->shade[i]], &src, &blood_rect, 0, NULL, fliptype);
			}
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

	enum player_Attacks
	{
		not_attacking,
		front_punch,
		back_punch,
		front_kick,
		back_kick
	};

	struct Player
	{
		const int n_players = 2;
		Mix_Music **music;

		player_States* state;
		player_Facing* facing;
		player_Attacks* attacks;
		Vec* pos;
		Vec* collision_pos;
		Vec* collision_offset;
		Vec* accel;
		Vec* vel;
		Box** hurt_boxes;
		Box** hit_boxes;
		SDL_Texture** texture;
		SDL_RendererFlip* player_flip;
		char* crouched;
		float max_vel;
		float max_jump_vel;
		float* f_move;
		float f_jump;
		int* width;
		int* height;
		int* collision_width;
		int* collision_height;
		int* damage_dealt;
		char* got_hurt;
		int* blood_shade;

		Vec* frame_pos;
		int *walk_duration;
		int *idle_duration;
		int *jump_duration;
		int *front_punch_duration;
		int *back_punch_duration;
		int *n_walk_frames;
		int *n_idle_frames;
		int *n_jump_frames;
		int *n_front_punch_frames;
		int *n_back_punch_frames;
		unsigned int *last_walk_change_time;
		unsigned int *last_idle_change_time;
		unsigned int *last_jump_change_time;
		unsigned int *last_front_punch_change_time;
		unsigned int *last_back_punch_change_time;
		int *current_frame;
	};

	void allocate(Player *p)
	{
		p->music = (Mix_Music**)malloc(sizeof(Mix_Music*) * p->n_players);
		p->state = (player_States*)malloc(sizeof(player_States) * p->n_players);
		p->facing = (player_Facing*)malloc(sizeof(player_Facing) * p->n_players);
		p->attacks = (player_Attacks*)malloc(sizeof(player_Attacks) * p->n_players);
		p->pos = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->collision_pos = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->collision_offset = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->accel = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->vel = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->texture = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * p->n_players);
		p->player_flip = (SDL_RendererFlip*)malloc(sizeof(SDL_RendererFlip) * p->n_players);
		p->crouched = (char*)calloc(p->n_players, sizeof(char));
		p->max_vel = 0.01;
		p->f_move = (float*)malloc(sizeof(float)*p->n_players);
		p->f_jump = 0.9;
		p->width = (int*)malloc(sizeof(int) * p->n_players);
		p->height = (int*)malloc(sizeof(int) * p->n_players);
		p->collision_width = (int*)malloc(sizeof(int) * p->n_players);
		p->collision_height = (int*)malloc(sizeof(int) * p->n_players);
		p->damage_dealt = (int*)calloc(p->n_players, sizeof(int));
		p->got_hurt = (char*)calloc(p->n_players, sizeof(char));
		p->blood_shade = (int*)malloc(sizeof(int) * p->n_players);

		p->hurt_boxes = (Box**)malloc(sizeof(Box*) * Character_Data::n_hurt_boxes);
		for (int i = 0; i < p->n_players; i++)
		{
			p->hurt_boxes[i] = (Box*)malloc(sizeof(Box) * Character_Data::n_hurt_boxes);
		}
		p->hit_boxes = (Box**)malloc(sizeof(Box*) * Character_Data::n_hit_boxes);
		for (int i = 0; i < p->n_players; i++)
		{
			p->hit_boxes[i] = (Box*)malloc(sizeof(Box) * Character_Data::n_hit_boxes);
		}

		p->frame_pos = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->walk_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->idle_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->jump_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->front_punch_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->back_punch_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->n_walk_frames = (int*)malloc(sizeof(int) * p->n_players);
		p->n_idle_frames = (int*)malloc(sizeof(int) * p->n_players);
		p->n_jump_frames = (int*)malloc(sizeof(int) * p->n_players);
		p->n_front_punch_frames = (int*)malloc(sizeof(int) * p->n_players);
		p->n_back_punch_frames = (int*)malloc(sizeof(int) * p->n_players);
		p->last_walk_change_time = (unsigned int*)malloc(sizeof(unsigned int) * p->n_players);
		p->last_idle_change_time = (unsigned int*)malloc(sizeof(unsigned int) * p->n_players);
		p->last_jump_change_time = (unsigned int*)malloc(sizeof(unsigned int) * p->n_players);
		p->last_front_punch_change_time = (unsigned int*)malloc(sizeof(unsigned int) * p->n_players);
		p->last_back_punch_change_time = (unsigned int*)malloc(sizeof(unsigned int) * p->n_players);
		p->current_frame = (int*)malloc(sizeof(int) * p->n_players);
	}

	void player_Character_Setup(Player *p, Character_Data::TK *tk, SDL_Texture *TK_texture, Mix_Music *tk_theme, Character_Data::Camila *camila, SDL_Texture *Camila_texture, Mix_Music *camila_theme, Character_Data::Wrecca *wrecca, Mix_Music* wrecca_theme, int* chosen_character, int ground_y)
	{

		switch (chosen_character[0])
		{
		case 0:
		{
			p->music[0] = tk_theme;
			p->texture[0] = TK_texture;
			p->blood_shade[0] = tk->blood_shade;
			p->player_flip[0] = SDL_FLIP_NONE;
			p->state[0] = idle;
			p->facing[0] = right;
			p->pos[0].x = 1100;
			p->pos[0].y = ground_y - tk->height;
			p->collision_offset[0].x = tk->collision_offset_x;
			p->collision_offset[0].y = tk->collision_offset_y;
			p->collision_pos[0].x = p->pos[0].x + p->collision_offset[0].x;
			p->collision_pos[0].y = p->pos[0].y + p->collision_offset[0].y;
			p->accel[0].x = 0;
			p->accel[0].y = 0;
			p->vel[0].x = 0;
			p->vel[0].y = 0;
			p->f_move[0] = tk->f_move;
			p->width[0] = tk->width;
			p->height[0] = tk->height;
			p->collision_width[0] = tk->collision_width;
			p->collision_height[0] = tk->collision_height;

			p->frame_pos[0].x = tk->first_frame_x;
			p->frame_pos[0].y = tk->first_frame_y;
			p->n_walk_frames[0] = tk->n_walk_frames;
			p->walk_duration[0] = tk->walk_duration;
			p->n_idle_frames[0] = tk->n_idle_frames;
			p->idle_duration[0] = tk->idle_duration;
			p->n_jump_frames[0] = tk->n_jump_frames;
			p->jump_duration[0] = tk->jump_duration;
			p->n_front_punch_frames[0] = tk->n_front_punch_frames;
			p->front_punch_duration[0] = tk->front_punch_duration;
			p->n_back_punch_frames[0] = tk->n_front_punch_frames;
			p->back_punch_duration[0] = tk->front_punch_duration;
			p->last_jump_change_time[0] = 0;
			p->last_front_punch_change_time[0] = 0;
			p->last_back_punch_change_time[0] = 0;
			p->last_walk_change_time[0] = 0;
			p->last_idle_change_time[0] = 0;
			p->current_frame[0] = 0;

			p->hurt_boxes[0][0].offset_x = tk->head_offset_x;
			p->hurt_boxes[0][0].offset_y = tk->head_offset_y;
			p->hurt_boxes[0][0].x = p->pos[0].x + p->hurt_boxes[0][0].offset_x;
			p->hurt_boxes[0][0].y = p->pos[0].y + p->hurt_boxes[0][0].offset_y;
			p->hurt_boxes[0][0].w = tk->head_w;
			p->hurt_boxes[0][0].h = tk->head_h;

			p->hurt_boxes[0][1].offset_x = tk->shoulder_offset_x;
			p->hurt_boxes[0][1].offset_y = tk->shoulder_offset_y;
			p->hurt_boxes[0][1].x = p->pos[0].x + p->hurt_boxes[0][1].offset_x;
			p->hurt_boxes[0][1].y = p->pos[0].y + p->hurt_boxes[0][1].offset_y;
			p->hurt_boxes[0][1].w = tk->shoulder_w;
			p->hurt_boxes[0][1].h = tk->shoulder_h;

			p->hurt_boxes[0][2].offset_x = tk->torso_offset_x;
			p->hurt_boxes[0][2].offset_y = tk->torso_offset_y;
			p->hurt_boxes[0][2].x = p->pos[0].x + p->hurt_boxes[0][2].offset_x;
			p->hurt_boxes[0][2].y = p->pos[0].y + p->hurt_boxes[0][2].offset_x;
			p->hurt_boxes[0][2].w = tk->torso_w;
			p->hurt_boxes[0][2].h = tk->torso_h;

			p->hurt_boxes[0][3].offset_x = tk->leg_offset_x;
			p->hurt_boxes[0][3].offset_y = tk->leg_offset_y;
			p->hurt_boxes[0][3].x = p->pos[0].x + p->hurt_boxes[0][3].offset_x;
			p->hurt_boxes[0][3].y = p->pos[0].y + p->hurt_boxes[0][3].offset_y;
			p->hurt_boxes[0][3].w = tk->leg_w;
			p->hurt_boxes[0][3].h = tk->leg_h;

			p->hit_boxes[0][0].offset_x = tk->front_punch_hit_x;
			p->hit_boxes[0][0].offset_y = tk->front_punch_hit_y;
			p->hit_boxes[0][0].x = p->pos[0].x + p->hit_boxes[0][0].offset_x;
			p->hit_boxes[0][0].y = p->pos[0].y + p->hit_boxes[0][0].offset_y;
			p->hit_boxes[0][0].w = tk->front_punch_hit_w;
			p->hit_boxes[0][0].h = tk->front_punch_hit_h;
			p->hit_boxes[0][0].damage = tk->front_punch_damage;

			p->hit_boxes[0][1].offset_x = tk->back_punch_hit_x;
			p->hit_boxes[0][1].offset_y = tk->back_punch_hit_y;
			p->hit_boxes[0][1].x = p->pos[0].x + p->hit_boxes[0][1].offset_x;
			p->hit_boxes[0][1].y = p->pos[0].y + p->hit_boxes[0][1].offset_y;
			p->hit_boxes[0][1].w = tk->back_punch_hit_w;
			p->hit_boxes[0][1].h = tk->back_punch_hit_h;
			p->hit_boxes[0][1].damage = tk->back_punch_damage;

		}
		break;
		default:
		{
			printf("ERROR: Invalid Character Selection.  Player 0 defaulted to character 0\n");
			p->music[0] = tk_theme;
			p->texture[0] = TK_texture;
			p->blood_shade[0] = tk->blood_shade;
			p->player_flip[0] = SDL_FLIP_NONE;
			p->state[0] = idle;
			p->facing[0] = right;
			p->pos[0].x = 1100;
			p->pos[0].y = ground_y - tk->height;
			p->collision_offset[0].x = tk->collision_offset_x;
			p->collision_offset[0].y = tk->collision_offset_y;
			p->collision_pos[0].x = p->pos[0].x + p->collision_offset[0].x;
			p->collision_pos[0].y = p->pos[0].y + p->collision_offset[0].y;
			p->accel[0].x = 0;
			p->accel[0].y = 0;
			p->vel[0].x = 0;
			p->vel[0].y = 0;
			p->f_move[0] = tk->f_move;
			p->width[0] = tk->width;
			p->height[0] = tk->height;
			p->collision_width[0] = tk->collision_width;
			p->collision_height[0] = tk->collision_height;

			p->frame_pos[0].x = tk->first_frame_x;
			p->frame_pos[0].y = tk->first_frame_y;
			p->n_walk_frames[0] = tk->n_walk_frames;
			p->walk_duration[0] = tk->walk_duration;
			p->n_idle_frames[0] = tk->n_idle_frames;
			p->idle_duration[0] = tk->idle_duration;
			p->n_jump_frames[0] = tk->n_jump_frames;
			p->jump_duration[0] = tk->jump_duration;
			p->n_front_punch_frames[0] = tk->n_front_punch_frames;
			p->front_punch_duration[0] = tk->front_punch_duration;
			p->n_back_punch_frames[0] = tk->n_front_punch_frames;
			p->back_punch_duration[0] = tk->front_punch_duration;
			p->last_jump_change_time[0] = 0;
			p->last_front_punch_change_time[0] = 0;
			p->last_back_punch_change_time[0] = 0;
			p->last_walk_change_time[0] = 0;
			p->last_idle_change_time[0] = 0;
			p->current_frame[0] = 0;

			p->hurt_boxes[0][0].offset_x = tk->head_offset_x;
			p->hurt_boxes[0][0].offset_y = tk->head_offset_y;
			p->hurt_boxes[0][0].x = p->pos[0].x + p->hurt_boxes[0][0].offset_x;
			p->hurt_boxes[0][0].y = p->pos[0].y + p->hurt_boxes[0][0].offset_y;
			p->hurt_boxes[0][0].w = tk->head_w;
			p->hurt_boxes[0][0].h = tk->head_h;

			p->hurt_boxes[0][1].offset_x = tk->shoulder_offset_x;
			p->hurt_boxes[0][1].offset_y = tk->shoulder_offset_y;
			p->hurt_boxes[0][1].x = p->pos[0].x + p->hurt_boxes[0][1].offset_x;
			p->hurt_boxes[0][1].y = p->pos[0].y + p->hurt_boxes[0][1].offset_y;
			p->hurt_boxes[0][1].w = tk->shoulder_w;
			p->hurt_boxes[0][1].h = tk->shoulder_h;

			p->hurt_boxes[0][2].offset_x = tk->torso_offset_x;
			p->hurt_boxes[0][2].offset_y = tk->torso_offset_y;
			p->hurt_boxes[0][2].x = p->pos[0].x + p->hurt_boxes[0][2].offset_x;
			p->hurt_boxes[0][2].y = p->pos[0].y + p->hurt_boxes[0][2].offset_x;
			p->hurt_boxes[0][2].w = tk->torso_w;
			p->hurt_boxes[0][2].h = tk->torso_h;

			p->hurt_boxes[0][3].offset_x = tk->leg_offset_x;
			p->hurt_boxes[0][3].offset_y = tk->leg_offset_y;
			p->hurt_boxes[0][3].x = p->pos[0].x + p->hurt_boxes[0][3].offset_x;
			p->hurt_boxes[0][3].y = p->pos[0].y + p->hurt_boxes[0][3].offset_y;
			p->hurt_boxes[0][3].w = tk->leg_w;
			p->hurt_boxes[0][3].h = tk->leg_h;

			p->hit_boxes[0][0].offset_x = tk->front_punch_hit_x;
			p->hit_boxes[0][0].offset_y = tk->front_punch_hit_y;
			p->hit_boxes[0][0].x = p->pos[0].x + p->hit_boxes[0][0].offset_x;
			p->hit_boxes[0][0].y = p->pos[0].y + p->hit_boxes[0][0].offset_y;
			p->hit_boxes[0][0].w = tk->front_punch_hit_w;
			p->hit_boxes[0][0].h = tk->front_punch_hit_h;
			p->hit_boxes[0][0].damage = tk->front_punch_damage;

			p->hit_boxes[0][1].offset_x = tk->back_punch_hit_x;
			p->hit_boxes[0][1].offset_y = tk->back_punch_hit_y;
			p->hit_boxes[0][1].x = p->pos[0].x + p->hit_boxes[0][1].offset_x;
			p->hit_boxes[0][1].y = p->pos[0].y + p->hit_boxes[0][1].offset_y;
			p->hit_boxes[0][1].w = tk->back_punch_hit_w;
			p->hit_boxes[0][1].h = tk->back_punch_hit_h;
			p->hit_boxes[0][1].damage = tk->back_punch_damage;
		}
		break;
		}

		switch (chosen_character[1])
		{
		case 0:
		{
			p->music[1] = tk_theme;
			p->texture[1] = TK_texture;
			p->blood_shade[1] = tk->blood_shade;
			p->player_flip[1] = SDL_FLIP_HORIZONTAL;
			p->state[1] = idle;
			p->facing[1] = left;
			p->pos[1].x = 2300;
			p->pos[1].y = ground_y - tk->height;
			p->collision_offset[1].x = tk->collision_offset_x;
			p->collision_offset[1].y = tk->collision_offset_y;
			p->collision_pos[1].x = p->pos[1].x + p->collision_offset[1].x;
			p->collision_pos[1].y = p->pos[1].y + p->collision_offset[1].y;
			p->accel[1].x = 0;
			p->accel[1].y = 0;
			p->vel[1].x = 0;
			p->vel[1].y = 0;
			p->f_move[1] = tk->f_move;
			p->width[1] = tk->width;
			p->height[1] = tk->height;
			p->collision_width[1] = tk->collision_width;
			p->collision_height[1] = tk->collision_height;

			p->frame_pos[1].x = tk->first_frame_x;
			p->frame_pos[1].y = tk->first_frame_y;
			p->n_walk_frames[1] = tk->n_walk_frames;
			p->walk_duration[1] = tk->walk_duration;
			p->idle_duration[1] = tk->idle_duration;
			p->n_idle_frames[1] = tk->n_idle_frames;
			p->n_jump_frames[1] = tk->n_jump_frames;
			p->jump_duration[1] = tk->jump_duration;
			p->n_front_punch_frames[1] = tk->n_front_punch_frames;
			p->front_punch_duration[1] = tk->front_punch_duration;
			p->n_back_punch_frames[1] = tk->n_back_punch_frames;
			p->back_punch_duration[1] = tk->back_punch_duration;
			p->last_jump_change_time[1] = 0;
			p->last_front_punch_change_time[1] = 0;
			p->last_back_punch_change_time[1] = 0;
			p->last_walk_change_time[1] = 0;
			p->last_idle_change_time[1] = 0;
			p->current_frame[1] = 0;

			p->hurt_boxes[1][0].offset_x = tk->head_offset_x;
			p->hurt_boxes[1][0].offset_y = tk->head_offset_y;
			p->hurt_boxes[1][0].x = p->pos[1].x + p->hurt_boxes[1][0].offset_x;
			p->hurt_boxes[1][0].y = p->pos[1].y + p->hurt_boxes[1][0].offset_y;
			p->hurt_boxes[1][0].w = tk->head_w;
			p->hurt_boxes[1][0].h = tk->head_h;

			p->hurt_boxes[1][1].offset_x = tk->shoulder_offset_x;
			p->hurt_boxes[1][1].offset_y = tk->shoulder_offset_y;
			p->hurt_boxes[1][1].x = p->pos[1].x + p->hurt_boxes[1][1].offset_x;
			p->hurt_boxes[1][1].y = p->pos[1].y + p->hurt_boxes[1][1].offset_y;
			p->hurt_boxes[1][1].w = tk->shoulder_w;
			p->hurt_boxes[1][1].h = tk->shoulder_h;

			p->hurt_boxes[1][2].offset_x = tk->torso_offset_x;
			p->hurt_boxes[1][2].offset_y = tk->torso_offset_y;
			p->hurt_boxes[1][2].x = p->pos[1].x + p->hurt_boxes[1][2].offset_x;
			p->hurt_boxes[1][2].y = p->pos[1].y + p->hurt_boxes[1][2].offset_x;
			p->hurt_boxes[1][2].w = tk->torso_w;
			p->hurt_boxes[1][2].h = tk->torso_h;

			p->hurt_boxes[1][3].offset_x = tk->leg_offset_x;
			p->hurt_boxes[1][3].offset_y = tk->leg_offset_y;
			p->hurt_boxes[1][3].x = p->pos[1].x + p->hurt_boxes[1][3].offset_x;
			p->hurt_boxes[1][3].y = p->pos[1].y + p->hurt_boxes[1][3].offset_y;
			p->hurt_boxes[1][3].w = tk->leg_w;
			p->hurt_boxes[1][3].h = tk->leg_h;

			p->hit_boxes[1][0].offset_x = tk->front_punch_hit_x;
			p->hit_boxes[1][0].offset_y = tk->front_punch_hit_y;
			p->hit_boxes[1][0].x = p->pos[1].x + p->hit_boxes[1][0].offset_x;
			p->hit_boxes[1][0].y = p->pos[1].y + p->hit_boxes[1][0].offset_y;
			p->hit_boxes[1][0].w = tk->front_punch_hit_w;
			p->hit_boxes[1][0].h = tk->front_punch_hit_h;
			p->hit_boxes[1][0].damage = tk->front_punch_damage;

			p->hit_boxes[1][1].offset_x = tk->back_punch_hit_x;
			p->hit_boxes[1][1].offset_y = tk->back_punch_hit_y;
			p->hit_boxes[1][1].x = p->pos[1].x + p->hit_boxes[1][1].offset_x;
			p->hit_boxes[1][1].y = p->pos[1].y + p->hit_boxes[1][1].offset_y;
			p->hit_boxes[1][1].w = tk->back_punch_hit_w;
			p->hit_boxes[1][1].h = tk->back_punch_hit_h;
			p->hit_boxes[1][1].damage = tk->back_punch_damage;
		}
		break;
		default:
		{
			printf("ERROR: Invalid Character Selection.  Player 1 defaulted to character 0\n");
			p->music[1] = tk_theme;
			p->texture[1] = TK_texture;
			p->blood_shade[1] = tk->blood_shade;
			p->player_flip[1] = SDL_FLIP_HORIZONTAL;
			p->state[1] = idle;
			p->facing[1] = left;
			p->pos[1].x = 2300;
			p->pos[1].y = ground_y - tk->height;
			p->collision_offset[1].x = tk->collision_offset_x;
			p->collision_offset[1].y = tk->collision_offset_y;
			p->collision_pos[1].x = p->pos[1].x + p->collision_offset[1].x;
			p->collision_pos[1].y = p->pos[1].y + p->collision_offset[1].y;
			p->accel[1].x = 0;
			p->accel[1].y = 0;
			p->vel[1].x = 0;
			p->vel[1].y = 0;
			p->f_move[1] = tk->f_move;
			p->width[1] = tk->width;
			p->height[1] = tk->height;
			p->collision_width[1] = tk->collision_width;
			p->collision_height[1] = tk->collision_height;

			p->frame_pos[1].x = tk->first_frame_x;
			p->frame_pos[1].y = tk->first_frame_y;
			p->n_walk_frames[1] = tk->n_walk_frames;
			p->walk_duration[1] = tk->walk_duration;
			p->idle_duration[1] = tk->idle_duration;
			p->n_idle_frames[1] = tk->n_idle_frames;
			p->n_jump_frames[1] = tk->n_jump_frames;
			p->jump_duration[1] = tk->jump_duration;
			p->n_front_punch_frames[1] = tk->n_front_punch_frames;
			p->front_punch_duration[1] = tk->front_punch_duration;
			p->n_back_punch_frames[1] = tk->n_back_punch_frames;
			p->back_punch_duration[1] = tk->back_punch_duration;
			p->last_jump_change_time[1] = 0;
			p->last_front_punch_change_time[1] = 0;
			p->last_back_punch_change_time[1] = 0;
			p->last_walk_change_time[1] = 0;
			p->last_idle_change_time[1] = 0;
			p->current_frame[1] = 0;

			p->hurt_boxes[1][0].offset_x = tk->head_offset_x;
			p->hurt_boxes[1][0].offset_y = tk->head_offset_y;
			p->hurt_boxes[1][0].x = p->pos[1].x + p->hurt_boxes[1][0].offset_x;
			p->hurt_boxes[1][0].y = p->pos[1].y + p->hurt_boxes[1][0].offset_y;
			p->hurt_boxes[1][0].w = tk->head_w;
			p->hurt_boxes[1][0].h = tk->head_h;

			p->hurt_boxes[1][1].offset_x = tk->shoulder_offset_x;
			p->hurt_boxes[1][1].offset_y = tk->shoulder_offset_y;
			p->hurt_boxes[1][1].x = p->pos[1].x + p->hurt_boxes[1][1].offset_x;
			p->hurt_boxes[1][1].y = p->pos[1].y + p->hurt_boxes[1][1].offset_y;
			p->hurt_boxes[1][1].w = tk->shoulder_w;
			p->hurt_boxes[1][1].h = tk->shoulder_h;

			p->hurt_boxes[1][2].offset_x = tk->torso_offset_x;
			p->hurt_boxes[1][2].offset_y = tk->torso_offset_y;
			p->hurt_boxes[1][2].x = p->pos[1].x + p->hurt_boxes[1][2].offset_x;
			p->hurt_boxes[1][2].y = p->pos[1].y + p->hurt_boxes[1][2].offset_x;
			p->hurt_boxes[1][2].w = tk->torso_w;
			p->hurt_boxes[1][2].h = tk->torso_h;

			p->hurt_boxes[1][3].offset_x = tk->leg_offset_x;
			p->hurt_boxes[1][3].offset_y = tk->leg_offset_y;
			p->hurt_boxes[1][3].x = p->pos[1].x + p->hurt_boxes[1][3].offset_x;
			p->hurt_boxes[1][3].y = p->pos[1].y + p->hurt_boxes[1][3].offset_y;
			p->hurt_boxes[1][3].w = tk->leg_w;
			p->hurt_boxes[1][3].h = tk->leg_h;

			p->hit_boxes[1][0].offset_x = tk->front_punch_hit_x;
			p->hit_boxes[1][0].offset_y = tk->front_punch_hit_y;
			p->hit_boxes[1][0].x = p->pos[1].x + p->hit_boxes[1][0].offset_x;
			p->hit_boxes[1][0].y = p->pos[1].y + p->hit_boxes[1][0].offset_y;
			p->hit_boxes[1][0].w = tk->front_punch_hit_w;
			p->hit_boxes[1][0].h = tk->front_punch_hit_h;
			p->hit_boxes[1][0].damage = tk->front_punch_damage;

			p->hit_boxes[1][1].offset_x = tk->back_punch_hit_x;
			p->hit_boxes[1][1].offset_y = tk->back_punch_hit_y;
			p->hit_boxes[1][1].x = p->pos[1].x + p->hit_boxes[1][1].offset_x;
			p->hit_boxes[1][1].y = p->pos[1].y + p->hit_boxes[1][1].offset_y;
			p->hit_boxes[1][1].w = tk->back_punch_hit_w;
			p->hit_boxes[1][1].h = tk->back_punch_hit_h;
			p->hit_boxes[1][1].damage = tk->back_punch_damage;
		}
		break;
		}

		for (int i = 0; i < p->n_players; i++)
		{
			for (int j = 0; j < Character_Data::n_hit_boxes; j++)
			{
				p->hit_boxes[i][j].active = 0;
			}
		}

		if (p->blood_shade[0] == p->blood_shade[1])
		{
			p->blood_shade[0] = 0;
			p->blood_shade[1] = 1;
		}
	}

	int check_Opponent_Collision(Player *p)
	{
		if (p->collision_pos[0].x + p->collision_width[0] < p->collision_pos[1].x) return 0;
		else if (p->collision_pos[0].x > p->collision_pos[1].x + p->collision_width[1]) return 0;
		else if (p->collision_pos[0].y + p->collision_height[0] < p->collision_pos[1].y) return 0;
		else if (p->collision_pos[0].y > p->collision_pos[1].y + p->collision_height[1]) return 0;

		else return 1;
	}

	void check_Hit(Player *p, Particles::Particles *blood)
	{
		unsigned int spawn_time = SDL_GetTicks();
		for (int i = 0; i < Character_Data::n_hit_boxes; i++)
		{
			if (p->state[1] == blocking) break;
			if (p->hit_boxes[0][i].active == 0) continue;

			for (int j = 0; j < Character_Data::n_hurt_boxes; j++)
			{
				if (p->hit_boxes[0][i].x + p->hit_boxes[0][i].w < p->hurt_boxes[1][j].x) continue;
				else if (p->hit_boxes[0][i].x > p->hurt_boxes[1][j].x + p->hurt_boxes[1][j].w) continue;
				else if (p->hit_boxes[0][i].y + p->hit_boxes[0][i].h < p->hurt_boxes[1][j].y) continue;
				else if (p->hit_boxes[0][i].y > p->hurt_boxes[1][j].y + p->hurt_boxes[1][j].h) continue;

				p->damage_dealt[0] = p->hit_boxes[0][i].damage;
				p->got_hurt[1] = 1;
				p->hurt_boxes[1][j].was_hit = 1;
				if (j == 0) p->damage_dealt[0] *= 2;
				Particles::create_Blood(blood, p->hurt_boxes[1][j].x + p->hurt_boxes[1][j].w / 3, p->hurt_boxes[1][j].y + p->hurt_boxes[1][j].h , p->damage_dealt[0], p->facing[1], p->blood_shade[1], spawn_time);
				break;
			}
		}


		for (int i = 0; i < Character_Data::n_hit_boxes; i++)
		{
			if (p->state[0] == blocking) break;
			if (p->hit_boxes[1][i].active == 0) continue;

			for (int j = 0; j < Character_Data::n_hurt_boxes; j++)
			{
				if (p->hit_boxes[1][i].x + p->hit_boxes[1][i].w < p->hurt_boxes[0][j].x) continue;
				else if (p->hit_boxes[1][i].x > p->hurt_boxes[0][j].x + p->hurt_boxes[0][j].w) continue;
				else if (p->hit_boxes[1][i].y + p->hit_boxes[1][i].h < p->hurt_boxes[0][j].y) continue;
				else if (p->hit_boxes[1][i].y > p->hurt_boxes[0][j].y + p->hurt_boxes[0][j].h) continue;

				p->damage_dealt[1] = p->hit_boxes[1][i].damage;
				p->got_hurt[0] = 1;
				p->hurt_boxes[0][j].was_hit = 1;
				if (j == 0) p->damage_dealt[1] *= 2;
				Particles::create_Blood(blood, p->hurt_boxes[0][j].x + p->hurt_boxes[0][j].w / 2, p->hurt_boxes[0][j].y + p->hurt_boxes[0][j].h / 2, p->damage_dealt[1], p->facing[0], p->blood_shade[0], spawn_time);
				break;
			}
		}


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
				for (int j = 0; j < 10; j++)
				{
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
			if (p->pos[i].y + p->height[i] > ground_y)
			{
				p->state[i] = idle;
				p->vel[i].y = 0;
				p->pos[i].y = ground_y - p->height[i];
				c->cam_center.y = 540;
			}

			for (int j = 0; j < Character_Data::n_hurt_boxes; j++)
			{
				p->hurt_boxes[i][j].x = p->pos[i].x + p->hurt_boxes[i][j].offset_x;
				p->hurt_boxes[i][j].y = p->pos[i].y + p->hurt_boxes[i][j].offset_y;
			}

			for (int j = 0; j < Character_Data::n_hit_boxes; j++)
			{
				p->hit_boxes[i][j].x = p->pos[i].x + p->hit_boxes[i][j].offset_x;
				p->hit_boxes[i][j].y = p->pos[i].y + p->hit_boxes[i][j].offset_y;
			}

			if (p->facing[i] == left)
			{
				p->hurt_boxes[i][0].x += p->hurt_boxes[i][0].offset_x / 14;
				p->hurt_boxes[i][1].x += p->hurt_boxes[i][1].offset_x / 2;
				p->hurt_boxes[i][2].x += p->hurt_boxes[i][2].offset_x / 2;
				p->hurt_boxes[i][3].x += p->hurt_boxes[i][3].offset_x / 7;

				p->hit_boxes[i][0].x -= p->hit_boxes[i][0].offset_x / 1.15;
				p->hit_boxes[i][1].x -= p->hit_boxes[i][1].offset_x / 1.2;
			}
			if (p->crouched[i] == 1)
			{
				p->hurt_boxes[i][0].y += p->hurt_boxes[i][0].offset_y * 3;
				p->hurt_boxes[i][1].y += p->hurt_boxes[i][1].offset_y * 1.5;
				p->hurt_boxes[i][2].y += p->hurt_boxes[i][2].offset_y / 2;
				p->hurt_boxes[i][3].y += p->hurt_boxes[i][3].offset_y / 3;
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

	void draw_hit_boxes(Player *p, Camera::Camera *c)
	{
		SDL_Rect dest;
		for (int i = 0; i < p->n_players; i++)
		{
			if (p->attacks[i] == not_attacking) continue;
			for (int j = 0; j < Character_Data::n_hit_boxes; j++)
			{
				if (p->hit_boxes[i][j].active == 0) continue;
				dest.x = p->hit_boxes[i][j].x - c->cam_center.x + screen_width / 2;
				dest.y = p->hit_boxes[i][j].y - c->cam_center.y + screen_height / 2;
				dest.w = p->hit_boxes[i][j].w;
				dest.h = p->hit_boxes[i][j].h;

				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderDrawRect(renderer, &dest);
			}
		}
	}
}

namespace Backgrounds
{
	struct Backgrounds
	{
		int n_background_tiles;
		Vec *pos;
		int* background_tiles;
		int stage_width;
		const int stage_height = screen_height;
		int last_frame_change_time;
		int frame_duration;
		int current_frame;
		int n_frames;
	};

	void init(Backgrounds *bg)
	{
		bg->n_background_tiles = 2;
		bg->background_tiles[bg->n_background_tiles];
		bg->pos = (Vec*)malloc(sizeof(Vec) * bg->n_background_tiles);
		for (int i = 0; i < bg->n_background_tiles; i++)
		{
			bg->pos[i].x = screen_width * i;
			bg->pos[i].y = 0;
		}
		bg->stage_width = screen_width * bg->n_background_tiles;
		bg->last_frame_change_time = 0;
		bg->current_frame = 0;
		bg->n_frames = 0;
		bg->frame_duration = 100;
	}


	void draw(Backgrounds *bg, Camera::Camera *c, SDL_Texture **level_textures, SDL_Rect src, SDL_RendererFlip fliptype, int current_time)
	{
		SDL_Rect dest;
		for (int i = 0; i < bg->n_background_tiles; i++)
		{
			if (bg->n_background_tiles != 1)
			{
				if (bg->pos[i].x + screen_width < (c->cam_center.x - screen_width / 2)) continue;
				else if (bg->pos[i].x >(c->cam_center.x + screen_width / 2)) continue;
				else if (bg->pos[i].y + screen_height < (c->cam_center.y - screen_height / 2)) continue;
				else if (bg->pos[i].y >(c->cam_center.y + screen_height / 2)) continue;
			}

			if (current_time - bg->last_frame_change_time >= bg->frame_duration)
			{
				bg->current_frame = (bg->current_frame + 1) % bg->n_frames;
				bg->last_frame_change_time = current_time;
			}

			src.x = bg->pos[i].x;

			dest.x = 0;
			if (bg->n_background_tiles != 1)
			{
				dest.x = bg->pos[i].x - c->cam_center.x + screen_width / 2;
			}
			dest.y = 0 - c->cam_center.y + screen_height / 2;
			dest.w = screen_width;
			dest.h = screen_height;

			SDL_SetTextureAlphaMod(level_textures[bg->current_frame], 255);
			SDL_RenderCopyEx(renderer, level_textures[bg->current_frame], &src, &dest, 0, NULL, fliptype);
		}
	}


}

namespace Grid
{
	struct Blood_Grid
	{
		int** grid;
		int** mark_count;
		int blood_grid_rows;
		int blood_grid_columns;
		int blood_grid_size;
		Vec** pos;
		int tile_size;
		int frame_x;
		int frame_y;
		int frame_size;
		int possible_neighbors;
		int same_neighbors;
		int* neighbor_list;
		int* neighbor_count_list;
	};

	void init(Blood_Grid *b, Backgrounds::Backgrounds *bg)
	{
		b->tile_size = 40;
		b->blood_grid_columns = bg->stage_width / b->tile_size;
		b->blood_grid_rows = bg->stage_height / b->tile_size;
		b->blood_grid_size = b->blood_grid_columns * b->blood_grid_rows;

		b->grid = (int**)malloc(sizeof(int*)*b->blood_grid_rows);
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			b->grid[i] = (int*)malloc(sizeof(int) * b->blood_grid_columns);
		}
		b->mark_count = (int**)calloc(b->blood_grid_rows, sizeof(int*));
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			b->mark_count[i] = (int*)calloc(b->blood_grid_rows, sizeof(int));
		}
		b->pos = (Vec**)calloc(b->blood_grid_rows, sizeof(Vec*));
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			b->pos[i] = (Vec*)calloc(b->blood_grid_columns, sizeof(Vec));
		}
		b->frame_x = 0;
		b->frame_y = 0;
		b->frame_size = 10;
		b->possible_neighbors = 9;
		b->same_neighbors = 0;
		b->neighbor_list = (int*)calloc(b->possible_neighbors, sizeof(int));
		b->neighbor_count_list = (int*)calloc(b->possible_neighbors, sizeof(int));
	}

	void place_blood_tiles(Blood_Grid *b)
	{
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			for (int j = 0; j < b->blood_grid_columns; j++)
			{
				b->pos[i][j].x = j * b->tile_size;
				b->pos[i][j].y = i * b->tile_size;
				b->grid[i][j] = 2;
			}
		}
	}

	void get_Covered_Tile(Blood_Grid *b, Player::Player *p, Particles::Particles *blood, int j)
	{	
		blood->current_row[j] = (int)blood->pos[j].y / b->tile_size;
		blood->current_column[j] = (int)blood->pos[j].x / b->tile_size;
	}

	void update(Blood_Grid *b, Player::Player *p, Particles::Particles *blood)
	{
		Player::check_Hit(p, blood);
		for (int i = 0; i < p->n_players; i++)
		{
			if (p->got_hurt[i] == 1)
			{
				for (int j = 0; j < blood->max_particles; j++)
				{
					if (blood->active[j] == 1)
					{
						get_Covered_Tile(b, p, blood, j);
						for (int k = 0; k < 3; k++)
						{
							b->grid[blood->current_row[j] + k][blood->current_column[j]] = p->blood_shade[i];
						}
						j += 20;
					}
				}
				p->got_hurt[i] = 0;
			}
		}
	}

	void draw(Blood_Grid *b, Camera::Camera *c, SDL_Texture *blood_texture, SDL_Rect blood_tile_src, SDL_RendererFlip fliptype)
	{
		SDL_Rect blood_dest;
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			for (int j = 0; j < b->blood_grid_columns; j++)
			{
				if (b->pos[i][j].x + b->tile_size < (c->cam_center.x - screen_width / 2)) continue;
				else if (b->pos[i][j].x >(c->cam_center.x + screen_width / 2)) continue;
				else if (b->pos[i][j].y + b->tile_size < (c->cam_center.y - screen_height / 2)) continue;
				else if (b->pos[i][j].y >(c->cam_center.y + screen_height / 2)) continue;

				blood_tile_src.x = b->grid[i][j] * 10;

				blood_dest.x = b->pos[i][j].x - c->cam_center.x + screen_width / 2;
				blood_dest.y = b->pos[i][j].y - c->cam_center.y + screen_height / 2;
				blood_dest.w = b->tile_size;
				blood_dest.h = b->tile_size;

				SDL_SetTextureAlphaMod(blood_texture, 150);
				SDL_RenderCopyEx(renderer, blood_texture, &blood_tile_src, &blood_dest, 0, NULL, fliptype);
			}
		}
	}
}

namespace Menu
{
	struct Menu
	{
		Vec pos;
		Vec frame_pos;
		int n_frames;
		int width;
		int height;
	};

	void init_Menu(Menu *m)
	{
		m->pos.x = 0;
		m->pos.y = 0;
		m->frame_pos.x = 0;
		m->frame_pos.y = 0;
		m->n_frames = 1;
		m->width = screen_width;
		m->height = screen_height;
	}

	void draw_Menu(Menu *m, SDL_Texture *texture, SDL_Rect src, SDL_RendererFlip fliptype)
	{
		SDL_Rect dest;
		dest.x = m->pos.x;
		dest.y = m->pos.y;
		dest.w = m->width;
		dest.h = m->height;

		SDL_SetTextureAlphaMod(texture, 255);
		SDL_RenderCopyEx(renderer, texture, &src, &dest, 0, NULL, fliptype);
	}

	struct Menu_Button
	{
		int n_menu_buttons;
		Vec *pos;
		int *width;
		int *height;
		char* active;
	};

	void init_Menu_Button(Menu_Button *mb)
	{
		mb->n_menu_buttons = 15;
		mb->pos = (Vec*)malloc(sizeof(Vec) * mb->n_menu_buttons);
		mb->width = (int*)malloc(sizeof(int) * mb->n_menu_buttons);
		mb->height = (int*)malloc(sizeof(int) * mb->n_menu_buttons);
		mb->active = (char*)calloc(mb->n_menu_buttons, sizeof(char));
	}

	int check_Button_Click(Menu_Button *mb, float mx, float my)
	{
		for (int i = 0; i < mb->n_menu_buttons; i++)
		{
			if (mb->active[i] == 0)continue;

			if (mb->pos[i].x + mb->width[i] < mx) continue;
			if (mx < mb->pos[i].x) continue;
			if (mb->pos[i].y + mb->height[i] < my) continue;
			if (my < mb->pos[i].y) continue;

			return i;
		}

		return -1;
	}

	struct Selector
	{
		const int n_selectors = 2;
		Vec* pos;
		int width;
		int height;
		int* r;
		int* g;
		int* b;
		int* current_button;
	};

	void init_Selector(Selector *s)
	{
		s->pos = (Vec*)malloc(sizeof(Vec) * s->n_selectors);
		s->width = 70;
		s->height = 70;
		s->r = (int*)malloc(sizeof(int) * s->n_selectors);
		s->g = (int*)malloc(sizeof(int) * s->n_selectors);
		s->b = (int*)malloc(sizeof(int) * s->n_selectors);
		s->current_button = (int*)malloc(sizeof(int) * s->n_selectors);
	}

	void draw_Selector(Selector *s)
	{
		for (int i = 0; i < s->n_selectors; i++)
		{
			SDL_Rect selector_rect = { s->pos[i].x, s->pos[i].y, s->width, s->height };

			SDL_SetRenderDrawColor(renderer, s->r[i], s->g[i], s->b[i], 255);
			SDL_RenderFillRect(renderer, &selector_rect);
		}
	}

	int check_Selector_Overlap(Selector *s, Menu_Button *mb)
	{
		for (int i = 0; i < s->n_selectors; i++)
		{
			for (int j = 0; j < mb->n_menu_buttons; j++)
			{
				if (mb->active[j] == 0) continue;

				if (mb->pos[j].x + mb->width[j] < s->pos[i].x) continue;
				if (mb->pos[j].x > s->pos[i].x + s->width) continue;
				if (mb->pos[j].y + mb->height[j] < s->pos[i].y) continue;
				if (mb->pos[j].y > s->pos[i].y + s->height) continue;

				s->current_button[i] = j;
			}
		}
		return -1;
	}

	/*void draw_title_words(SDL_Texture *texture, SDL_Rect src, SDL_RendererFlip fliptype)
	{
	SDL_Rect dest = { 205, 75, 1578, 183 };
	SDL_SetTextureAlphaMod(texture, 255);
	SDL_RenderCopyEx(renderer, texture, &src, &dest, 0, NULL, fliptype);
	}*/
}

enum Interface
{
	title_screen,
	main_menu,
	character_select,
	local_multi,
};

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER);
	TTF_Init();
	SDL_StartTextInput();
	srand(time(0));

	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 2048);
	Mix_Music *main_theme = Mix_LoadMUS("Audio\\CC_Theme.wav");
	Mix_Music *camila_theme = Mix_LoadMUS("Audio\\Camila_Theme.wav");
	Mix_Music *tk_theme = Mix_LoadMUS("Audio\\TK_Theme.wav");
	Mix_Music *wrecca_theme = Mix_LoadMUS("Audio\\Wrecca_Theme.wav");
	Mix_Music *victory_theme = Mix_LoadMUS("Audio\\Victory_Theme.wav");
	Mix_Music *boss_theme = Mix_LoadMUS("Audio\\Jolie_Boss.wav");

	SDL_Window *window = SDL_CreateWindow("Crimson Canvas", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_RendererFlip fliptype = SDL_FLIP_NONE;

	/*SDL_Surface **title_surfaces = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * Images::n_title_frames);
	SDL_Texture **title_textures = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * Images::n_title_frames);
	for (int i = 0; i < Images::n_title_frames; i++)
	{
	title_surfaces[i] = IMG_Load(Images::title_filenames[i]);
	assert(title_surfaces[i]);
	title_textures[i] = SDL_CreateTextureFromSurface(renderer, title_surfaces[i]);
	SDL_FreeSurface(title_surfaces[i]);
	}*/

	SDL_Surface *title_surface = IMG_Load(Images::title_filename);
	assert(title_surface);
	SDL_Texture *title_texture = SDL_CreateTextureFromSurface(renderer, title_surface);
	SDL_FreeSurface(title_surface);

	SDL_Surface *main_menu_surface = IMG_Load(Images::main_menu_filename);
	assert(main_menu_surface);
	SDL_Texture *main_menu_texture = SDL_CreateTextureFromSurface(renderer, main_menu_surface);
	SDL_FreeSurface(main_menu_surface);

	SDL_Surface *character_menu_surface = IMG_Load(Images::character_menu_filename);
	assert(character_menu_surface);
	SDL_Texture *character_menu_texture = SDL_CreateTextureFromSurface(renderer, character_menu_surface);
	SDL_FreeSurface(character_menu_surface);

	SDL_Surface **level_2_surfaces = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * Images::n_level_2_frames);
	SDL_Texture **level_2_textures = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * Images::n_level_2_frames);
	for (int i = 0; i < Images::n_level_2_frames; i++)
	{
		level_2_surfaces[i] = IMG_Load(Images::level_2_filenames[i]);
		assert(level_2_surfaces[i]);
		level_2_textures[i] = SDL_CreateTextureFromSurface(renderer, level_2_surfaces[i]);
		SDL_FreeSurface(level_2_surfaces[i]);
	}

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

	SDL_Surface **blood_particle_surfaces = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * Images::n_blood_particle_frames);
	SDL_Texture **blood_particle_textures = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * Images::n_blood_particle_frames);
	for (int i = 0; i < Images::n_blood_particle_frames; i++)
	{
		blood_particle_surfaces[i] = IMG_Load(Images::blood_particle_filenames[i]);
		assert(blood_particle_surfaces[i]);
		blood_particle_textures[i] = SDL_CreateTextureFromSurface(renderer, blood_particle_surfaces[i]);
		SDL_FreeSurface(blood_particle_surfaces[i]);
	}

	Interface game_state;
	unsigned char *key_state = (unsigned char*)SDL_GetKeyboardState(NULL);
	static unsigned char last_key_state[256];
	memset(last_key_state, 0, 256);

	const int ground_y = 1000;
	Mix_VolumeMusic(0);
	Input::init();
	Camera::Camera c;
	Camera::init(&c);
	Character_Data::TK tk;
	Character_Data::Camila camila;
	Character_Data::Wrecca wrecca;
	game_state = local_multi;

	unsigned int current_mouse_state = 0;
	unsigned int prev_mouse_state = 0;
	unsigned int game_start_time = SDL_GetTicks();
	unsigned int current_time = 0;
	unsigned int last_frame_time = 0;
	for (;;)
	{
		if (game_state == title_screen)
		{
			Mix_PlayMusic(main_theme, -1);
			SDL_ShowCursor(SDL_DISABLE);
			Menu::Menu title;
			Menu::init_Menu(&title);
			SDL_Rect title_src = { 0, 0 , screen_width, screen_height };
			SDL_Rect title_words_src = { 0, 0, 1578, 183 };
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

				if (1000.0 / (current_time - last_frame_time) <= frame_limit)
				{
					last_frame_time = current_time;
					Input::update();

					if ((key_state[SDL_SCANCODE_RETURN] && last_key_state[SDL_SCANCODE_RETURN] == 0) || (P1_START == 1 && LAST_P1_START == 0) || (P2_START == 1 && LAST_P2_START == 0))
					{
						game_state = main_menu;
						break;
					}

					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);


					Menu::draw_Menu(&title, title_texture, title_src, fliptype);
					//Menu::draw_title_words(title_words_texture, title_words_src, fliptype);

					SDL_RenderPresent(renderer);
				}
			}
		}
		else if (game_state == main_menu)
		{

			SDL_ShowCursor(SDL_ENABLE);
			Menu::Menu main_menu;
			Menu::init_Menu(&main_menu);
			Menu::Menu_Button main_buttons;
			Menu::init_Menu_Button(&main_buttons);
			Menu::Selector s;
			Menu::init_Selector(&s);

			SDL_Rect main_menu_src = { main_menu.frame_pos.x, main_menu.frame_pos.y , main_menu.width, main_menu.height };

			main_buttons.pos[0].x = 560;
			main_buttons.pos[0].y = 190;
			main_buttons.width[0] = 350;
			main_buttons.height[0] = 715;
			main_buttons.active[0] = 1;

			main_buttons.pos[1].x = 1050;
			main_buttons.pos[1].y = 190;
			main_buttons.width[1] = 350;
			main_buttons.height[1] = 715;
			main_buttons.active[1] = 1;

			s.pos[0].x = main_buttons.pos[0].x + main_buttons.width[0] / 3;
			s.pos[0].y = main_buttons.pos[0].y + main_buttons.height[0] / 3;
			s.r[0] = 255;
			s.g[0] = 0;
			s.b[0] = 0;


			s.pos[1].x = main_buttons.pos[0].x + main_buttons.width[0] / 3;
			s.pos[1].y = main_buttons.pos[0].y + main_buttons.height[0] / 2;
			s.r[1] = 0;
			s.g[1] = 255;
			s.b[1] = 0;


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
				last_frame_time = current_time;
				if (current_time - last_frame_time < 15)
				{
					Input::update();
					if ((Menu::check_Button_Click(&main_buttons, Input::mx, Input::my) == 1) && (Input::m_left == 1 && Input::last_m_left == 0))
					{

						game_state = character_select;
						break;
					}

					if ((P1_LEFTX < -Input::stick_dead_zone && LAST_P1_LEFTX >= -Input::stick_dead_zone) || (P1_DPAD_LEFT == 1 && LAST_P1_DPAD_LEFT == 0))
					{
						if (player_button[0] > 0) player_button[0]--;
						s.pos[0].x = main_buttons.pos[player_button[0]].x + main_buttons.width[player_button[0]] / 3;
						s.current_button[0] = player_button[0];
					}
					if ((P1_LEFTX > Input::stick_dead_zone && LAST_P1_LEFTX <= Input::stick_dead_zone) || (P1_DPAD_RIGHT == 1 && LAST_P1_DPAD_RIGHT == 0))
					{
						if (player_button[0] < 1) player_button[0]++;
						s.pos[0].x = main_buttons.pos[player_button[0]].x + main_buttons.width[player_button[0]] / 3;
						s.current_button[0] = player_button[0];
					}
					if ((P2_LEFTX < -Input::stick_dead_zone && LAST_P2_LEFTX >= -Input::stick_dead_zone) || (P2_DPAD_LEFT == 1 && LAST_P2_DPAD_LEFT == 0))
					{
						if (player_button[1] > 0) player_button[1]--;
						s.pos[1].x = main_buttons.pos[player_button[1]].x + main_buttons.width[player_button[1]] / 3;
						s.current_button[1] = player_button[1];
					}
					if ((P2_LEFTX > Input::stick_dead_zone && LAST_P2_LEFTX <= Input::stick_dead_zone) || (P2_DPAD_RIGHT == 1 && LAST_P2_DPAD_RIGHT == 0))
					{
						if (player_button[1] < 1) player_button[1]++;
						s.pos[1].x = main_buttons.pos[player_button[1]].x + main_buttons.width[player_button[1]] / 3;
						s.current_button[1] = player_button[1];
					}

					if ((s.current_button[0] == 0) && (P1_A == 1 && LAST_P1_A))
					{
						game_state = character_select;
						break;
					}

					if ((s.current_button[1] == 0) && (P2_A == 1 && LAST_P2_A))
					{
						game_state = character_select;
						break;
					}

					Menu::check_Selector_Overlap(&s, &main_buttons);

					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					Menu::draw_Menu(&main_menu, main_menu_texture, main_menu_src, fliptype);
					Menu::draw_Selector(&s);

					SDL_RenderPresent(renderer);
				}
			}
		}
		else if (game_state == character_select)
		{
			SDL_ShowCursor(SDL_ENABLE);
			Menu::Menu character_menu;
			Menu::init_Menu(&character_menu);
			Menu::Menu_Button character_buttons;
			Menu::init_Menu_Button(&character_buttons);
			Menu::Selector s;
			Menu::init_Selector(&s);

			SDL_Rect character_menu_src = { character_menu.frame_pos.x, character_menu.frame_pos.y , character_menu.width, character_menu.height };

			character_buttons.active[0] = 1;
			for (int i = 0; i < character_buttons.n_menu_buttons; i++)
			{
				character_buttons.width[i] = 175;
				character_buttons.height[i] = 185;
				character_buttons.pos[i].x = 412 + character_buttons.width[i] * i;
				character_buttons.pos[i].y = 705;
				character_buttons.active[i] = 1;
			}

			s.pos[0].x = character_buttons.pos[0].x + character_buttons.width[0] / 2;
			s.pos[0].y = character_buttons.pos[0].y + character_buttons.height[0] / 12;
			s.r[0] = 255;
			s.g[0] = 0;
			s.b[0] = 0;
			s.current_button[0] = 0;
			player_button[0] = 0;

			s.pos[1].x = character_buttons.pos[0].x + character_buttons.width[0] / 2;
			s.pos[1].y = character_buttons.pos[0].y + character_buttons.height[0] / 2;
			s.r[1] = 0;
			s.g[1] = 255;
			s.b[1] = 0;
			s.current_button[1] = 0;
			player_button[1] = 0;

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
				last_frame_time = current_time;
				if (current_time - last_frame_time < 15)
				{
					Input::update();

					clicked_character[0] = Menu::check_Button_Click(&character_buttons, Input::mx, Input::my);
					if ((clicked_character[0] >= 0) && (Input::m_left == 1 && Input::last_m_left == 0))
					{
						player_ready[0] = 1;
						chosen_character[0] = clicked_character[0];
						printf("player 0 using character %d\n", chosen_character[0]);
					}

					clicked_character[1] = Menu::check_Button_Click(&character_buttons, Input::mx, Input::my);
					if ((clicked_character[1] >= 0) && (Input::m_right == 1 && Input::last_m_right == 0))
					{
						player_ready[1] = 1;
						chosen_character[1] = clicked_character[1];
						printf("player 1 using character %d\n", chosen_character[1]);
					}

					if ((P1_LEFTX < -Input::stick_dead_zone && LAST_P1_LEFTX >= -Input::stick_dead_zone) || (P1_DPAD_LEFT == 1 && LAST_P1_DPAD_LEFT == 0))
					{
						if (player_button[0] > 0) player_button[0]--;
						s.pos[0].x = character_buttons.pos[player_button[0]].x + character_buttons.width[player_button[0]] / 2;
						s.current_button[0] = player_button[0];
					}
					if ((P1_LEFTX > Input::stick_dead_zone && LAST_P1_LEFTX <= Input::stick_dead_zone) || (P1_DPAD_RIGHT == 1 && LAST_P1_DPAD_RIGHT == 0))
					{
						if (player_button[0] < 5) player_button[0]++;
						s.pos[0].x = character_buttons.pos[player_button[0]].x + character_buttons.width[player_button[0]] / 2;
						s.current_button[0] = player_button[0];
					}
					if ((P2_LEFTX < -Input::stick_dead_zone && LAST_P2_LEFTX >= -Input::stick_dead_zone) || (P2_DPAD_LEFT == 1 && LAST_P2_DPAD_LEFT == 0))
					{
						if (player_button[1] > 0) player_button[1]--;
						s.pos[1].x = character_buttons.pos[player_button[1]].x + character_buttons.width[player_button[1]] / 2;
						s.current_button[1] = player_button[1];
					}
					if ((P2_LEFTX > Input::stick_dead_zone && LAST_P2_LEFTX <= Input::stick_dead_zone) || (P2_DPAD_RIGHT == 1 && LAST_P2_DPAD_RIGHT == 0))
					{
						if (player_button[1] < 5) player_button[1]++;
						s.pos[1].x = character_buttons.pos[player_button[1]].x + character_buttons.width[player_button[1]] / 2;
						s.current_button[1] = player_button[1];
					}

					if ((s.current_button[0] >= 0 && s.current_button[0] <= 2) && (P1_A == 1 && LAST_P1_A == 0))
					{
						player_ready[0] = 1;
						chosen_character[0] = s.current_button[0];
						printf("player 0 using character %d\n", chosen_character[0]);
					}

					if ((s.current_button[1] >= 0 && s.current_button[1] <= 2) && (P2_A == 1 && LAST_P2_A == 0))
					{
						player_ready[1] = 1;
						chosen_character[1] = s.current_button[1];
						printf("player 1 using character %d\n", chosen_character[1]);
					}

					if (player_ready[0] == 1 && player_ready[1] == 1)
					{
						game_state = local_multi;
						break;
					}

					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					Menu::draw_Menu(&character_menu, character_menu_texture, character_menu_src, fliptype);
					Menu::draw_Selector(&s);

					SDL_RenderPresent(renderer);
				}
			}
		}
		else if (game_state == local_multi)
		{
			SDL_ShowCursor(SDL_DISABLE);
			Backgrounds::Backgrounds bg;
			Backgrounds::init(&bg);
			bg.n_frames = Images::n_level_2_frames;
			Particles::Particles blood;
			Particles::init_Blood(&blood);
			Grid::Blood_Grid b;
			Grid::init(&b, &bg);
			Grid::place_blood_tiles(&b);

			Player::Player p;
			Player::allocate(&p);

			SDL_Rect TK_src = { 0 };
			SDL_Rect bg_src = { 0, 0, screen_width, screen_height };
			SDL_Rect blood_tile_src = { 0, 0 , b.frame_size, b.frame_size };
			SDL_Rect blood_particle_src = { 0, 0, blood.width, blood.height };
			c.cam_center.x = screen_width;

			Player::player_Character_Setup(&p, &tk, TK_texture, tk_theme, &camila, Camila_texture, camila_theme, &wrecca, wrecca_theme, chosen_character, ground_y);

			Mix_FadeInMusic(p.music[rand() % 2], -1, 500);

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
				if (1000.0 / (current_time - last_frame_time) <= frame_limit)
				{
					last_frame_time = current_time;
					/*
					front punch is x
					back punch is y
					front kick is a
					back kick is b
					*/

					Input::update();

					p.accel[0].x = {};
					p.accel[0].y = {};
					p.accel[0].y = f_gravity;//add constant forces like gravity
					if (P1_RIGHTTRIGGER > Input::stick_dead_zone || key_state[SDL_SCANCODE_SEMICOLON])
					{
						if (p.state[0] != Player::jumping)
						{
							p.current_frame[0] = 0;
							p.state[0] = Player::blocking;
							p.attacks[0] = Player::not_attacking;
							for (int i = 0; i < Character_Data::n_hit_boxes; i++)
							{
								p.hit_boxes[0][i].active = 0;
							}
							p.f_move[0] = 0;
							p.frame_pos[0].x = 0;
							p.frame_pos[0].y = 540;
						}
					}
					if (P1_LEFTY > Input::stick_dead_zone || P1_DPAD_DOWN == 1 || key_state[SDL_SCANCODE_S])
					{
						if (p.state[0] != Player::jumping && p.attacks[0] == Player::not_attacking)
						{
							p.crouched[0] = 1;
							p.state[0] = Player::blocking;
							p.frame_pos[0].y = 1080;
							p.current_frame[0] = 0;
						}
					}
					else p.crouched[0] = 0;

					if ((P1_LEFTY < -Input::stick_dead_zone && LAST_P1_LEFTY >= -Input::stick_dead_zone) || (P1_DPAD_UP == 1 && LAST_P1_DPAD_UP == 0) || (key_state[SDL_SCANCODE_W] && last_key_state[SDL_SCANCODE_W] == 0))
					{
						if (p.state[0] != Player::blocking)
						{
							if (p.pos[0].y + p.height[0] >= ground_y)
							{
								p.f_move[0] = 1.0;
								p.state[0] = Player::jumping;
								p.frame_pos[0].y = 2160;
								p.current_frame[0] = 0;
								p.accel[0].y -= p.f_jump;
							}
						}
					}

					if (P1_LEFTX < -Input::stick_dead_zone || P1_DPAD_LEFT == 1 || key_state[SDL_SCANCODE_A])
					{
						if (p.state[0] != Player::blocking)
						{
							p.f_move[0] = tk.f_move;
							p.facing[0] = Player::left;
							p.player_flip[0] = SDL_FLIP_HORIZONTAL;
							p.accel[0].x += -p.f_move[0];
							if (p.state[0] != Player::jumping)
							{
								p.frame_pos[0].y = 0;
								p.state[0] = Player::walking;
								if (current_time - p.last_walk_change_time[0] >= p.walk_duration[0])
								{
									p.current_frame[0] = (p.current_frame[0] + 1) % p.n_walk_frames[0];
									p.last_walk_change_time[0] = current_time;
								}
							}
						}
					}
					else if (P1_LEFTX > Input::stick_dead_zone || P1_DPAD_RIGHT == 1 || key_state[SDL_SCANCODE_D])
					{
						if (p.state[0] != Player::blocking)
						{
							p.f_move[0] = tk.f_move;
							p.facing[0] = Player::right;
							p.player_flip[0] = SDL_FLIP_NONE;
							p.accel[0].x += p.f_move[0];
							if (p.state[0] != Player::jumping)
							{
								p.frame_pos[0].y = 0;
								p.state[0] = Player::walking;
								if (current_time - p.last_walk_change_time[0] >= p.walk_duration[0])
								{
									p.current_frame[0] = (p.current_frame[0] + 1) % p.n_walk_frames[0];
									p.last_walk_change_time[0] = current_time;
								}
							}
						}
					}
					else
					{
						if (p.state[0] != Player::blocking &&p.state[0] != Player::jumping && p.attacks[0] == Player::not_attacking)
						{
							if (p.state[0] != Player::jumping) p.state[0] = Player::idle;
							p.frame_pos[0].x = 0;
							p.frame_pos[0].y = 540;
							if (current_time - p.last_idle_change_time[0] >= p.idle_duration[0])
							{
								p.current_frame[0] = (p.current_frame[0] + 1) % p.n_idle_frames[0];
								p.last_idle_change_time[0] = current_time;
							}
						}
					}

					if ((P1_X == 1 && LAST_P1_X == 0) || (key_state[SDL_SCANCODE_J] && last_key_state[SDL_SCANCODE_J] == 0))
					{
						if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::not_attacking && p.state[0] != Player::jumping)
						{
							p.attacks[0] = Player::front_punch;
							p.frame_pos[0].y = 1620;
							p.current_frame[0] = 0;
						}
					}
					else if ((P1_Y == 1 && LAST_P1_Y == 0) || (key_state[SDL_SCANCODE_I] && last_key_state[SDL_SCANCODE_I] == 0))
					{
						if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::not_attacking && p.state[0] != Player::jumping)
						{
							p.attacks[0] = Player::back_punch;
							p.frame_pos[0].y = 2700;
							p.current_frame[0] = 0;
						}
					}
					else if ((P1_A == 1 && LAST_P1_A == 0) || (key_state[SDL_SCANCODE_K] && last_key_state[SDL_SCANCODE_K] == 0))
					{
						printf("P1 front kick!\n");
					}
					else if ((P1_B == 1 && LAST_P1_B == 0) || (key_state[SDL_SCANCODE_L] && last_key_state[SDL_SCANCODE_L] == 0))
					{
						printf("P1 back kick!\n");
					}

					if (p.state[0] == Player::jumping)
					{
						if (current_time - p.last_jump_change_time[0] >= p.jump_duration[0])
						{
							p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_jump_frames[0] + 1);
							p.last_jump_change_time[0] = current_time;
						}
					}

					if (p.attacks[0] == Player::front_punch)
					{
						p.hit_boxes[0][0].active = 1;
						if (current_time - p.last_front_punch_change_time[0] >= p.front_punch_duration[0])
						{
							p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_front_punch_frames[0] + 1);
							p.last_front_punch_change_time[0] = current_time;
						}
						if (p.current_frame[0] >= p.n_front_punch_frames[0])
						{
							p.hit_boxes[0][0].active = 0;
							p.attacks[0] = Player::not_attacking;
							p.current_frame[0] = 0;
							printf("p1 dealt %d damage with this attack\n", p.damage_dealt[0]);
							p.damage_dealt[0] /= 10;
							p.damage_dealt[0] = 0;
						}
					}
					else if (p.attacks[0] == Player::back_punch)
					{
						p.hit_boxes[0][1].active = 1;
						if (current_time - p.last_back_punch_change_time[0] >= p.back_punch_duration[0])
						{
							p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_back_punch_frames[0] + 1);
							p.last_back_punch_change_time[0] = current_time;
						}
						if (p.current_frame[0] >= p.n_back_punch_frames[0])
						{
							p.hit_boxes[0][1].active = 0;
							p.attacks[0] = Player::not_attacking;
							p.current_frame[0] = 0;
							printf("p1 dealt %d damage with this attack\n", p.damage_dealt[0]);
							p.damage_dealt[0] /= 10;
							p.damage_dealt[0] = 0;
						}
					}
					else p.attacks[0] = Player::not_attacking;

					p.accel[1].x = {};
					p.accel[1].y = {};
					p.accel[1].y = f_gravity;
					if (P2_RIGHTTRIGGER > Input::stick_dead_zone || key_state[SDL_SCANCODE_KP_6])
					{
						if (p.state[1] != Player::jumping)
						{
							p.current_frame[1] = 0;
							p.state[1] = Player::blocking;
							p.attacks[1] = Player::not_attacking;
							for (int i = 0; i < Character_Data::n_hit_boxes; i++)
							{
								p.hit_boxes[1][i].active = 0;
							}
							p.f_move[1] = 0;
							p.frame_pos[1].x = 0;
							p.frame_pos[1].y = 540;
						}
					}
					if (P2_LEFTY > Input::stick_dead_zone || P2_DPAD_DOWN == 1 || key_state[SDL_SCANCODE_DOWN])
					{
						if (p.state[1] != Player::jumping && p.attacks[1] == Player::not_attacking)
						{
							p.crouched[1] = 1;
							p.state[1] = Player::blocking;
							p.frame_pos[1].y = 1080;
							p.current_frame[1] = 0;
						}
					}
					else p.crouched[1] = 0;

					if ((P2_LEFTY < -Input::stick_dead_zone && LAST_P2_LEFTY >= -Input::stick_dead_zone) || (P2_DPAD_UP == 1 && LAST_P2_DPAD_UP == 0))
					{
						if (p.state[1] != Player::blocking)
						{
							if (p.pos[1].y + p.height[1] >= ground_y)
							{
								p.f_move[1] = 1.0;
								p.state[1] = Player::jumping;
								p.frame_pos[1].y = 2160;
								p.current_frame[1] = 0;
								p.accel[1].y -= p.f_jump;
							}
						}
					}

					if (P2_LEFTX < -Input::stick_dead_zone || P2_DPAD_LEFT == 1 || key_state[SDL_SCANCODE_LEFT])
					{
						if (p.state[1] != Player::blocking)
						{
							p.f_move[1] = tk.f_move;
							p.facing[1] = Player::left;
							p.player_flip[1] = SDL_FLIP_HORIZONTAL;
							p.accel[1].x += -p.f_move[1];
							if (p.state[1] != Player::jumping)
							{
								p.frame_pos[1].y = 0;
								p.state[1] = Player::walking;
								if (current_time - p.last_walk_change_time[1] >= p.walk_duration[1])
								{
									p.current_frame[1] = (p.current_frame[1] + 1) % p.n_walk_frames[1];
									p.last_walk_change_time[1] = current_time;
								}
							}
						}
					}
					else if (P2_LEFTX > Input::stick_dead_zone || P2_DPAD_RIGHT == 1 || key_state[SDL_SCANCODE_RIGHT])
					{
						if (p.state[1] != Player::blocking)
						{
							p.f_move[1] = tk.f_move;
							p.facing[1] = Player::right;
							p.player_flip[1] = SDL_FLIP_NONE;
							p.accel[1].x += p.f_move[1];
							if (p.state[1] != Player::jumping)
							{
								p.frame_pos[1].y = 0;
								p.state[1] = Player::walking;
								if (current_time - p.last_walk_change_time[1] >= p.walk_duration[1])
								{
									p.current_frame[1] = (p.current_frame[1] + 1) % p.n_walk_frames[1];
									p.last_walk_change_time[1] = current_time;
								}
							}
						}
					}
					else
					{
						if (p.state[1] != Player::blocking &&p.state[1] != Player::jumping && p.attacks[1] == Player::not_attacking)
						{
							if (p.state[1] != Player::jumping) p.state[1] = Player::idle;
							p.frame_pos[1].x = 0;
							p.frame_pos[1].y = 540;
							if (current_time - p.last_idle_change_time[1] >= p.idle_duration[1])
							{
								p.current_frame[1] = (p.current_frame[1] + 1) % p.n_idle_frames[1];
								p.last_idle_change_time[1] = current_time;
							}
						}
					}

					if ((P2_X == 1 && LAST_P2_X == 0) || (key_state[SDL_SCANCODE_KP_7] && last_key_state[SDL_SCANCODE_KP_7] == 0))
					{
						if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::not_attacking && p.state[1] != Player::jumping)
						{
							p.attacks[1] = Player::front_punch;
							p.frame_pos[1].y = 1620;
							p.current_frame[1] = 0;
						}
					}
					else if ((P2_Y == 1 && LAST_P2_Y == 0) || (key_state[SDL_SCANCODE_KP_8] && last_key_state[SDL_SCANCODE_KP_8] == 0))
					{
						if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::not_attacking && p.state[1] != Player::jumping)
						{
							p.attacks[1] = Player::back_punch;
							p.frame_pos[1].y = 2700;
							p.current_frame[1] = 0;
						}
					}
					else if ((P2_A == 1 && LAST_P2_A == 0) || (key_state[SDL_SCANCODE_KP_4] && last_key_state[SDL_SCANCODE_KP_4] == 0))
					{
						printf("P2 front kick!\n");
					}
					else if ((P2_B == 1 && LAST_P2_B == 0) || (key_state[SDL_SCANCODE_KP_5] && last_key_state[SDL_SCANCODE_KP_5] == 0))
					{
						printf("P2 back kick!\n");
					}

					if (p.state[1] == Player::jumping)
					{
						if (current_time - p.last_jump_change_time[1] >= p.jump_duration[1])
						{
							p.current_frame[1] = (p.current_frame[1] + 1) % p.n_jump_frames[1];
							p.last_jump_change_time[1] = current_time;
						}
					}

					if (p.attacks[1] == Player::front_punch)
					{
						p.hit_boxes[1][0].active = 1;
						if (current_time - p.last_front_punch_change_time[1] >= p.front_punch_duration[1])
						{
							p.current_frame[1] = (p.current_frame[1] + 1) % (p.n_front_punch_frames[1] + 1);
							p.last_front_punch_change_time[1] = current_time;
						}
						if (p.current_frame[1] >= p.n_front_punch_frames[1])
						{
							p.hit_boxes[1][0].active = 0;
							p.attacks[1] = Player::not_attacking;
							p.current_frame[1] = 0;
							printf("P2 dealt %d damage with this attack\n", p.damage_dealt[1]);
							//p.damage_dealt[1] /= 10;
							p.damage_dealt[1] = 0;
						}
					}
					else if (p.attacks[1] == Player::back_punch)
					{
						p.hit_boxes[1][1].active = 1;
						if (current_time - p.last_back_punch_change_time[1] >= p.back_punch_duration[1])
						{
							p.current_frame[1] = (p.current_frame[1] + 1) % (p.n_back_punch_frames[1] + 1);
							p.last_back_punch_change_time[1] = current_time;
						}
						if (p.current_frame[1] >= p.n_back_punch_frames[1])
						{
							p.hit_boxes[1][1].active = 0;
							p.attacks[1] = Player::not_attacking;
							p.current_frame[1] = 0;
							printf("P2 dealt %d damage with this attack\n", p.damage_dealt[1]);
							//p.damage_dealt[1] /= 10;
							p.damage_dealt[1] = 0;
						}
					}
					else p.attacks[1] = Player::not_attacking;

					Camera::update(&c);
					Grid::update(&b, &p, &blood);
					Particles::update_Blood(&blood, current_time, ground_y);
					//ALL FORCES MUST HAVE BEEN ADDED BY THIS POINT
					//UPDATE WILL TRANSLATE THOSE INTO VELOCITY
					Player::update(&p, &c, ground_y);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					Backgrounds::draw(&bg, &c, level_2_textures, bg_src, fliptype, current_time);
					Grid::draw(&b, &c, blood_texture, blood_tile_src, fliptype);
					Player::draw(&p, &c, TK_src);
					Particles::draw_Blood(&blood, blood_particle_textures, blood_particle_src, &c, fliptype);
					Player::draw_hurt_boxes(&p, &c);
					Player::draw_hit_boxes(&p, &c);
					

					SDL_RenderPresent(renderer);
				}
			}
		}
	}
}