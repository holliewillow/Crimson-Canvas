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
const double f_gravity = 0.05;

int player_button[2] = { 0 };
char player_ready[2] = { 0 };
int clicked_character[2] = { -1, -1 };
int chosen_character[2] = { -1, -1 };
int winner = -1;
const int frame_limit = 60;
char paused = 0;

namespace Images
{
	const char* main_menu_filename = "Sprites\\main_menu.png";
	const char* character_menu_filename = "Sprites\\character_menu.png";
	const char* Camila_filename = "Sprites\\Camila_walk.png";
	const char* TK_filename = "Sprites\\TkFin.png";
	const char* Wrecca_filename = "Sprites\\Wrecca_spritesheet_Fin.png";
	const char* blood_filename = "Sprites\\blood.png";
	const int n_blood_particle_frames = 3;
	const char* blood_particle_filenames[n_blood_particle_frames] = { "Sprites\\red_blood_particle.png", "Sprites\\green_blood_particle.png" ,"Sprites\\purple_blood_particle.png" };
	const char* numbers_filename = "Sprites\\numbers.png";
	const char* title_filename = "Sprites\\title.png";
	const char* win_filename[2] = { "Sprites\\TK_win.png", "Sprites\\Wrecca_win.png" };

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
		int attack_audio_offset = 2;
		float f_move = 0.5;

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

		int punch_combo_hit_x = 120;
		int punch_combo_hit_y = 10;
		int punch_combo_hit_w = 340;
		int punch_combo_hit_h = 320;
		int punch_combo_damage = 50;

		int first_frame_x = 0;
		int first_frame_y = 540;

		int walk_frame_y = 0;
		int n_walk_frames = 8;
		int walk_duration = 75;

		int idle_frame_y = 540;
		int n_idle_frames = 4;
		int idle_duration = 180;

		int jump_frame_y = 2160;
		int n_jump_frames = 9;
		int jump_duration = 190;

		int front_punch_frame_y = 1620;
		int n_front_punch_frames = 4;
		int front_punch_duration = 150;

		int back_punch_frame_y = 2700;
		int n_back_punch_frames = 4;
		int back_punch_duration = 150;

		int block_frame_y = 2700;
		int crouch_frame_y = 1080;

		int punch_combo_frame_y = 3240;
		int n_punch_combo_frames = 20;
		int punch_combo_duration = 100;

		int blood_shade = 1;
	};

	//character index 1;
	struct Wrecca
	{
		int attack_audio_offset = 6;
		float f_move = 0.5;

		float head_offset_x = 180;
		float head_offset_y = 160;
		float head_w = 100;
		float head_h = 70;

		float shoulder_offset_x = 170;
		float shoulder_offset_y = 225;
		float shoulder_w = 110;
		float shoulder_h = 50;

		float torso_offset_x = 190;
		float torso_offset_y = 275;
		float torso_w = 80;
		float torso_h = 80;

		float leg_offset_x = 190;
		float leg_offset_y = 350;
		float leg_w = 110;
		float leg_h = 150;

		int collision_offset_x = 115;
		int collision_offset_y = 102;
		int width = 470;
		int height = 540;
		int collision_width = 150;
		int collision_height = 463;

		int front_punch_hit_x = 0;
		int front_punch_hit_y = 180;
		int front_punch_hit_w = 160;
		int front_punch_hit_h = 177;
		int front_punch_damage = 70;

		int back_punch_hit_x = 35;
		int back_punch_hit_y = 257;
		int back_punch_hit_w = 180;
		int back_punch_hit_h = 60;
		int back_punch_damage = 30;

		int punch_combo_hit_x = 0;
		int punch_combo_hit_y = 40;
		int punch_combo_hit_w = 200;
		int punch_combo_hit_h = 310;
		int punch_combo_damage = 100;

		int first_frame_x = 0;
		int first_frame_y = 540;

		int walk_frame_y = 3780;
		int n_walk_frames = 8;
		int walk_duration = 75;

		int idle_frame_y = 540;
		int n_idle_frames = 10;
		int idle_duration = 180;

		int jump_frame_y = 2700;
		int n_jump_frames = 10;
		int jump_duration = 190;

		int front_punch_frame_y = 2160;
		int n_front_punch_frames = 15;
		int front_punch_duration = 30;

		int back_punch_frame_y = 0;
		int n_back_punch_frames = 12;
		int back_punch_duration = 40;

		int punch_combo_frame_y = 3240;
		int n_punch_combo_frames = 13;
		int punch_combo_duration = 70;

		int crouch_frame_y = 1080;
		int block_frame_y = 1620;

		int blood_shade = 2;
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
		c->speed = 0.1;
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
		char hit_ground;
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
		blood->hit_ground = 0;
	}

	void create_Blood(Particles *blood, float spawn_x, float spawn_y, int damage, const int facing, const int player_shade)
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
			blood->hit_ground = 0;
		}
	}

	void update_Blood(Particles *blood, Mix_Chunk *blood_fx, unsigned int current_time, const int ground_y)
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

				if (blood->pos[i].y >= screen_height)
				{
					blood->active[i] = 0;
					blood->hit_ground = 1;
				}
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
		back_kick,
		punch_combo
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
		Mix_Chunk** hurt_fx;
		int* attack_audio_offset;
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
		int* x_count;
		int* y_count;
		int* a_count;
		int* b_count;

		int* score;

		Vec* frame_pos;
		int *walk_y;
		int *walk_duration;
		int *idle_y;
		int *idle_duration;
		int *jump_y;
		int *jump_duration;
		int *front_punch_y;
		int *front_punch_duration;
		int *back_punch_y;
		int *back_punch_duration;
		int *punch_combo_y;
		int *punch_combo_duration;
		int *n_punch_combo_frames;
		int *block_y;
		int *crouch_y;
		int *n_walk_frames;
		int *n_idle_frames;
		int *n_jump_frames;
		int *n_front_punch_frames;
		int *n_back_punch_frames;
		unsigned int *last_punch_combo_change_time;
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
		p->hurt_fx = (Mix_Chunk**)malloc(sizeof(Mix_Chunk*) * p->n_players);
		p->pos = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->collision_pos = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->collision_offset = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->accel = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->vel = (Vec*)malloc(sizeof(Vec) * p->n_players);
		p->texture = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * p->n_players);
		p->player_flip = (SDL_RendererFlip*)malloc(sizeof(SDL_RendererFlip) * p->n_players);
		p->attack_audio_offset = (int*)malloc(sizeof(int) * p->n_players);
		p->crouched = (char*)calloc(p->n_players, sizeof(char));
		p->max_vel = 0.01;
		p->f_move = (float*)malloc(sizeof(float)*p->n_players);
		p->f_jump = 1.4;
		p->width = (int*)malloc(sizeof(int) * p->n_players);
		p->height = (int*)malloc(sizeof(int) * p->n_players);
		p->collision_width = (int*)malloc(sizeof(int) * p->n_players);
		p->collision_height = (int*)malloc(sizeof(int) * p->n_players);
		p->damage_dealt = (int*)calloc(p->n_players, sizeof(int));
		p->got_hurt = (char*)calloc(p->n_players, sizeof(char));
		p->blood_shade = (int*)malloc(sizeof(int) * p->n_players);
		p->x_count = (int*)calloc(p->n_players, sizeof(int));
		p->y_count = (int*)calloc(p->n_players, sizeof(int));
		p->a_count = (int*)calloc(p->n_players, sizeof(int));
		p->b_count = (int*)calloc(p->n_players, sizeof(int));

		p->score = (int*)malloc(sizeof(int) * p->n_players);

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
		p->walk_y = (int*)malloc(sizeof(int) * p->n_players);
		p->walk_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->idle_y = (int*)malloc(sizeof(int) * p->n_players);
		p->idle_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->jump_y = (int*)malloc(sizeof(int) * p->n_players);
		p->jump_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->front_punch_y = (int*)malloc(sizeof(int) * p->n_players);
		p->front_punch_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->back_punch_y = (int*)malloc(sizeof(int) * p->n_players);
		p->back_punch_duration = (int*)malloc(sizeof(int) * p->n_players);
		p->punch_combo_y = (int*)malloc(sizeof(int) * p->n_players);
		p->n_punch_combo_frames = (int*)malloc(sizeof(int) * p->n_players);
		p->punch_combo_duration = (int*)malloc(sizeof(int) * p->n_players);

		p->block_y = (int*)malloc(sizeof(int) * p->n_players);
		p->crouch_y = (int*)malloc(sizeof(int) * p->n_players);
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
		p->last_punch_combo_change_time = (unsigned int*)malloc(sizeof(unsigned int) * p->n_players);
		p->current_frame = (int*)malloc(sizeof(int) * p->n_players);
	}

	void player_Character_Setup(Player *p, Character_Data::TK *tk, SDL_Texture *TK_texture, Mix_Music *tk_theme, Mix_Chunk *tk_hurt_fx, Character_Data::Camila *camila, SDL_Texture *Camila_texture, Mix_Music *camila_theme, Character_Data::Wrecca *wrecca, SDL_Texture *Wrecca_texture, Mix_Music* wrecca_theme, Mix_Chunk* wrecca_hurt_fx, int* chosen_character, int ground_y)
	{
		switch (chosen_character[0])
		{
		case 0:
		{
			p->attack_audio_offset[0] = tk->attack_audio_offset;
			p->music[0] = tk_theme;
			p->texture[0] = TK_texture;
			p->hurt_fx[0] = tk_hurt_fx;
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
			p->walk_y[0] = tk->walk_frame_y;
			p->n_walk_frames[0] = tk->n_walk_frames;
			p->walk_duration[0] = tk->walk_duration;
			p->idle_y[0] = tk->idle_frame_y;
			p->n_idle_frames[0] = tk->n_idle_frames;
			p->idle_duration[0] = tk->idle_duration;
			p->jump_y[0] = tk->jump_frame_y;
			p->n_jump_frames[0] = tk->n_jump_frames;
			p->jump_duration[0] = tk->jump_duration;
			p->front_punch_y[0] = tk->front_punch_frame_y;
			p->n_front_punch_frames[0] = tk->n_front_punch_frames;
			p->front_punch_duration[0] = tk->front_punch_duration;
			p->back_punch_y[0] = tk->back_punch_frame_y;
			p->n_back_punch_frames[0] = tk->n_front_punch_frames;
			p->back_punch_duration[0] = tk->front_punch_duration;
			p->punch_combo_y[0] = tk->punch_combo_frame_y;
			p->n_punch_combo_frames[0] = tk->n_punch_combo_frames;
			p->punch_combo_duration[0] = tk->punch_combo_duration;
			p->last_punch_combo_change_time[0] = 0;
			p->block_y[0] = tk->block_frame_y;
			p->crouch_y[0] = tk->crouch_frame_y;
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

			p->hit_boxes[0][4].offset_x = tk->punch_combo_hit_x;
			p->hit_boxes[0][4].offset_y = tk->punch_combo_hit_y;
			p->hit_boxes[0][4].x = p->pos[0].x + p->hit_boxes[0][4].offset_x;
			p->hit_boxes[0][4].y = p->pos[0].y + p->hit_boxes[0][4].offset_y;
			p->hit_boxes[0][4].w = tk->punch_combo_hit_w;
			p->hit_boxes[0][4].h = tk->punch_combo_hit_h;
			p->hit_boxes[0][4].damage = tk->punch_combo_damage;
		}
		break;
		case 1:
		{
			p->attack_audio_offset[0] = wrecca->attack_audio_offset;
			p->music[0] = wrecca_theme;
			p->texture[0] = Wrecca_texture;
			p->hurt_fx[0] = wrecca_hurt_fx;
			p->blood_shade[0] = wrecca->blood_shade;
			p->player_flip[0] = SDL_FLIP_HORIZONTAL;
			p->state[0] = idle;
			p->facing[0] = right;
			p->pos[0].x = 1100;
			p->pos[0].y = ground_y - wrecca->height;
			p->collision_offset[0].x = wrecca->collision_offset_x;
			p->collision_offset[0].y = wrecca->collision_offset_y;
			p->collision_pos[0].x = p->pos[0].x + p->collision_offset[0].x;
			p->collision_pos[0].y = p->pos[0].y + p->collision_offset[0].y;
			p->accel[0].x = 0;
			p->accel[0].y = 0;
			p->vel[0].x = 0;
			p->vel[0].y = 0;
			p->f_move[0] = wrecca->f_move;
			p->width[0] = wrecca->width;
			p->height[0] = wrecca->height;
			p->collision_width[0] = wrecca->collision_width;
			p->collision_height[0] = wrecca->collision_height;

			p->frame_pos[0].x = wrecca->first_frame_x;
			p->frame_pos[0].y = wrecca->first_frame_y;
			p->walk_y[0] = wrecca->walk_frame_y;
			p->n_walk_frames[0] = wrecca->n_walk_frames;
			p->walk_duration[0] = wrecca->walk_duration;
			p->idle_y[0] = wrecca->idle_frame_y;
			p->n_idle_frames[0] = wrecca->n_idle_frames;
			p->idle_duration[0] = wrecca->idle_duration;
			p->jump_y[0] = wrecca->jump_frame_y;
			p->n_jump_frames[0] = wrecca->n_jump_frames;
			p->jump_duration[0] = wrecca->jump_duration;
			p->front_punch_y[0] = wrecca->front_punch_frame_y;
			p->n_front_punch_frames[0] = wrecca->n_front_punch_frames;
			p->front_punch_duration[0] = wrecca->front_punch_duration;
			p->back_punch_y[0] = wrecca->back_punch_frame_y;
			p->n_back_punch_frames[0] = wrecca->n_front_punch_frames;
			p->back_punch_duration[0] = wrecca->front_punch_duration;

			p->punch_combo_y[0] = wrecca->punch_combo_frame_y;
			p->n_punch_combo_frames[0] = wrecca->n_punch_combo_frames;
			p->punch_combo_duration[0] = wrecca->punch_combo_duration;
			p->last_punch_combo_change_time[0] = 0;

			p->block_y[0] = wrecca->block_frame_y;
			p->crouch_y[0] = wrecca->crouch_frame_y;
			p->last_jump_change_time[0] = 0;
			p->last_front_punch_change_time[0] = 0;
			p->last_back_punch_change_time[0] = 0;
			p->last_walk_change_time[0] = 0;
			p->last_idle_change_time[0] = 0;
			p->current_frame[0] = 0;

			p->hurt_boxes[0][0].offset_x = wrecca->head_offset_x;
			p->hurt_boxes[0][0].offset_y = wrecca->head_offset_y;
			p->hurt_boxes[0][0].x = p->pos[0].x + p->hurt_boxes[0][0].offset_x;
			p->hurt_boxes[0][0].y = p->pos[0].y + p->hurt_boxes[0][0].offset_y;
			p->hurt_boxes[0][0].w = wrecca->head_w;
			p->hurt_boxes[0][0].h = wrecca->head_h;

			p->hurt_boxes[0][1].offset_x = wrecca->shoulder_offset_x;
			p->hurt_boxes[0][1].offset_y = wrecca->shoulder_offset_y;
			p->hurt_boxes[0][1].x = p->pos[0].x + p->hurt_boxes[0][1].offset_x;
			p->hurt_boxes[0][1].y = p->pos[0].y + p->hurt_boxes[0][1].offset_y;
			p->hurt_boxes[0][1].w = wrecca->shoulder_w;
			p->hurt_boxes[0][1].h = wrecca->shoulder_h;

			p->hurt_boxes[0][2].offset_x = wrecca->torso_offset_x;
			p->hurt_boxes[0][2].offset_y = wrecca->torso_offset_y;
			p->hurt_boxes[0][2].x = p->pos[0].x + p->hurt_boxes[0][2].offset_x;
			p->hurt_boxes[0][2].y = p->pos[0].y + p->hurt_boxes[0][2].offset_x;
			p->hurt_boxes[0][2].w = wrecca->torso_w;
			p->hurt_boxes[0][2].h = wrecca->torso_h;

			p->hurt_boxes[0][3].offset_x = wrecca->leg_offset_x;
			p->hurt_boxes[0][3].offset_y = wrecca->leg_offset_y;
			p->hurt_boxes[0][3].x = p->pos[0].x + p->hurt_boxes[0][3].offset_x;
			p->hurt_boxes[0][3].y = p->pos[0].y + p->hurt_boxes[0][3].offset_y;
			p->hurt_boxes[0][3].w = wrecca->leg_w;
			p->hurt_boxes[0][3].h = wrecca->leg_h;

			p->hit_boxes[0][0].offset_x = wrecca->front_punch_hit_x;
			p->hit_boxes[0][0].offset_y = wrecca->front_punch_hit_y;
			p->hit_boxes[0][0].x = p->pos[0].x + p->hit_boxes[0][0].offset_x;
			p->hit_boxes[0][0].y = p->pos[0].y + p->hit_boxes[0][0].offset_y;
			p->hit_boxes[0][0].w = wrecca->front_punch_hit_w;
			p->hit_boxes[0][0].h = wrecca->front_punch_hit_h;
			p->hit_boxes[0][0].damage = wrecca->front_punch_damage;

			p->hit_boxes[0][1].offset_x = wrecca->back_punch_hit_x;
			p->hit_boxes[0][1].offset_y = wrecca->back_punch_hit_y;
			p->hit_boxes[0][1].x = p->pos[0].x + p->hit_boxes[0][1].offset_x;
			p->hit_boxes[0][1].y = p->pos[0].y + p->hit_boxes[0][1].offset_y;
			p->hit_boxes[0][1].w = wrecca->back_punch_hit_w;
			p->hit_boxes[0][1].h = wrecca->back_punch_hit_h;
			p->hit_boxes[0][1].damage = wrecca->back_punch_damage;

			p->hit_boxes[0][4].offset_x = wrecca->punch_combo_hit_x;
			p->hit_boxes[0][4].offset_y = wrecca->punch_combo_hit_y;
			p->hit_boxes[0][4].x = p->pos[0].x + p->hit_boxes[0][4].offset_x;
			p->hit_boxes[0][4].y = p->pos[0].y + p->hit_boxes[0][4].offset_y;
			p->hit_boxes[0][4].w = wrecca->punch_combo_hit_w;
			p->hit_boxes[0][4].h = wrecca->punch_combo_hit_h;
			p->hit_boxes[0][4].damage = wrecca->punch_combo_damage;
		}
		break;
		default:
		{
			printf("ERROR: Invalid Character Selection.  Player 0 defaulted to character 0\n");
			chosen_character[0] = 0;
			p->music[0] = tk_theme;
			p->texture[0] = TK_texture;
			p->hurt_fx[0] = tk_hurt_fx;
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
			p->walk_y[0] = tk->walk_frame_y;
			p->n_walk_frames[0] = tk->n_walk_frames;
			p->walk_duration[0] = tk->walk_duration;
			p->idle_y[0] = tk->idle_frame_y;
			p->n_idle_frames[0] = tk->n_idle_frames;
			p->idle_duration[0] = tk->idle_duration;
			p->jump_y[0] = tk->jump_frame_y;
			p->n_jump_frames[0] = tk->n_jump_frames;
			p->jump_duration[0] = tk->jump_duration;
			p->front_punch_y[0] = tk->front_punch_frame_y;
			p->n_front_punch_frames[0] = tk->n_front_punch_frames;
			p->front_punch_duration[0] = tk->front_punch_duration;
			p->back_punch_y[0] = tk->back_punch_frame_y;
			p->n_back_punch_frames[0] = tk->n_front_punch_frames;
			p->back_punch_duration[0] = tk->front_punch_duration;
			p->punch_combo_y[0] = tk->punch_combo_frame_y;
			p->n_punch_combo_frames[0] = tk->n_punch_combo_frames;
			p->punch_combo_duration[0] = tk->punch_combo_duration;
			p->last_punch_combo_change_time[0] = 0;

			p->block_y[0] = tk->block_frame_y;
			p->crouch_y[0] = tk->crouch_frame_y;

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

			p->hit_boxes[0][4].offset_x = tk->punch_combo_hit_x;
			p->hit_boxes[0][4].offset_y = tk->punch_combo_hit_y;
			p->hit_boxes[0][4].x = p->pos[0].x + p->hit_boxes[0][4].offset_x;
			p->hit_boxes[0][4].y = p->pos[0].y + p->hit_boxes[0][4].offset_y;
			p->hit_boxes[0][4].w = tk->punch_combo_hit_w;
			p->hit_boxes[0][4].h = tk->punch_combo_hit_h;
			p->hit_boxes[0][4].damage = tk->punch_combo_damage;
		}
		break;
		}

		switch (chosen_character[1])
		{
		case 0:
		{
			p->attack_audio_offset[1] = tk->attack_audio_offset;
			p->music[1] = tk_theme;
			p->texture[1] = TK_texture;
			p->hurt_fx[1] = tk_hurt_fx;
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
			p->walk_y[1] = tk->walk_frame_y;
			p->n_walk_frames[1] = tk->n_walk_frames;
			p->walk_duration[1] = tk->walk_duration;
			p->idle_y[1] = tk->idle_frame_y;
			p->n_idle_frames[1] = tk->n_idle_frames;
			p->idle_duration[1] = tk->idle_duration;
			p->jump_y[1] = tk->jump_frame_y;
			p->n_jump_frames[1] = tk->n_jump_frames;
			p->jump_duration[1] = tk->jump_duration;
			p->front_punch_y[1] = tk->front_punch_frame_y;
			p->n_front_punch_frames[1] = tk->n_front_punch_frames;
			p->front_punch_duration[1] = tk->front_punch_duration;
			p->back_punch_y[1] = tk->back_punch_frame_y;
			p->n_back_punch_frames[1] = tk->n_front_punch_frames;
			p->back_punch_duration[1] = tk->front_punch_duration;

			p->punch_combo_y[1] = tk->punch_combo_frame_y;
			p->n_punch_combo_frames[1] = tk->n_punch_combo_frames;
			p->punch_combo_duration[1] = tk->punch_combo_duration;
			p->last_punch_combo_change_time[1] = 0;

			p->block_y[1] = tk->block_frame_y;
			p->crouch_y[1] = tk->crouch_frame_y;
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

			p->hit_boxes[1][4].offset_x = tk->punch_combo_hit_x;
			p->hit_boxes[1][4].offset_y = tk->punch_combo_hit_y;
			p->hit_boxes[1][4].x = p->pos[1].x + p->hit_boxes[1][4].offset_x;
			p->hit_boxes[1][4].y = p->pos[1].y + p->hit_boxes[1][4].offset_y;
			p->hit_boxes[1][4].w = tk->punch_combo_hit_w;
			p->hit_boxes[1][4].h = tk->punch_combo_hit_h;
			p->hit_boxes[1][4].damage = tk->punch_combo_damage;
		}
		break;
		case 1:
		{
			p->attack_audio_offset[1] = wrecca->attack_audio_offset;
			p->music[1] = wrecca_theme;
			p->texture[1] = Wrecca_texture;
			p->hurt_fx[1] = wrecca_hurt_fx;
			p->blood_shade[1] = wrecca->blood_shade;
			p->player_flip[1] = SDL_FLIP_NONE;
			p->state[1] = idle;
			p->facing[1] = left;
			p->pos[1].x = 2300;
			p->pos[1].y = ground_y - wrecca->height;
			p->collision_offset[1].x = wrecca->collision_offset_x;
			p->collision_offset[1].y = wrecca->collision_offset_y;
			p->collision_pos[1].x = p->pos[1].x + p->collision_offset[1].x;
			p->collision_pos[1].y = p->pos[1].y + p->collision_offset[1].y;
			p->accel[1].x = 0;
			p->accel[1].y = 0;
			p->vel[1].x = 0;
			p->vel[1].y = 0;
			p->f_move[1] = wrecca->f_move;
			p->width[1] = wrecca->width;
			p->height[1] = wrecca->height;
			p->collision_width[1] = wrecca->collision_width;
			p->collision_height[1] = wrecca->collision_height;

			p->frame_pos[1].x = wrecca->first_frame_x;
			p->frame_pos[1].y = wrecca->first_frame_y;
			p->walk_y[1] = wrecca->walk_frame_y;
			p->n_walk_frames[1] = wrecca->n_walk_frames;
			p->walk_duration[1] = wrecca->walk_duration;
			p->idle_y[1] = wrecca->idle_frame_y;
			p->n_idle_frames[1] = wrecca->n_idle_frames;
			p->idle_duration[1] = wrecca->idle_duration;
			p->jump_y[1] = wrecca->jump_frame_y;
			p->n_jump_frames[1] = wrecca->n_jump_frames;
			p->jump_duration[1] = wrecca->jump_duration;
			p->front_punch_y[1] = wrecca->front_punch_frame_y;
			p->n_front_punch_frames[1] = wrecca->n_front_punch_frames;
			p->front_punch_duration[1] = wrecca->front_punch_duration;
			p->back_punch_y[1] = wrecca->back_punch_frame_y;
			p->n_back_punch_frames[1] = wrecca->n_front_punch_frames;
			p->back_punch_duration[1] = wrecca->front_punch_duration;

			p->punch_combo_y[1] = wrecca->punch_combo_frame_y;
			p->n_punch_combo_frames[1] = wrecca->n_punch_combo_frames;
			p->punch_combo_duration[1] = wrecca->punch_combo_duration;
			p->last_punch_combo_change_time[1] = 0;

			p->block_y[1] = wrecca->block_frame_y;
			p->crouch_y[1] = wrecca->crouch_frame_y;
			p->last_jump_change_time[1] = 0;
			p->last_front_punch_change_time[1] = 0;
			p->last_back_punch_change_time[1] = 0;
			p->last_walk_change_time[1] = 0;
			p->last_idle_change_time[1] = 0;
			p->current_frame[1] = 0;

			p->hurt_boxes[1][0].offset_x = wrecca->head_offset_x;
			p->hurt_boxes[1][0].offset_y = wrecca->head_offset_y;
			p->hurt_boxes[1][0].x = p->pos[1].x + p->hurt_boxes[1][0].offset_x;
			p->hurt_boxes[1][0].y = p->pos[1].y + p->hurt_boxes[1][0].offset_y;
			p->hurt_boxes[1][0].w = wrecca->head_w;
			p->hurt_boxes[1][0].h = wrecca->head_h;

			p->hurt_boxes[1][1].offset_x = wrecca->shoulder_offset_x;
			p->hurt_boxes[1][1].offset_y = wrecca->shoulder_offset_y;
			p->hurt_boxes[1][1].x = p->pos[1].x + p->hurt_boxes[1][1].offset_x;
			p->hurt_boxes[1][1].y = p->pos[1].y + p->hurt_boxes[1][1].offset_y;
			p->hurt_boxes[1][1].w = wrecca->shoulder_w;
			p->hurt_boxes[1][1].h = wrecca->shoulder_h;

			p->hurt_boxes[1][2].offset_x = wrecca->torso_offset_x;
			p->hurt_boxes[1][2].offset_y = wrecca->torso_offset_y;
			p->hurt_boxes[1][2].x = p->pos[1].x + p->hurt_boxes[1][2].offset_x;
			p->hurt_boxes[1][2].y = p->pos[1].y + p->hurt_boxes[1][2].offset_x;
			p->hurt_boxes[1][2].w = wrecca->torso_w;
			p->hurt_boxes[1][2].h = wrecca->torso_h;

			p->hurt_boxes[1][3].offset_x = wrecca->leg_offset_x;
			p->hurt_boxes[1][3].offset_y = wrecca->leg_offset_y;
			p->hurt_boxes[1][3].x = p->pos[1].x + p->hurt_boxes[1][3].offset_x;
			p->hurt_boxes[1][3].y = p->pos[1].y + p->hurt_boxes[1][3].offset_y;
			p->hurt_boxes[1][3].w = wrecca->leg_w;
			p->hurt_boxes[1][3].h = wrecca->leg_h;

			p->hit_boxes[1][0].offset_x = wrecca->front_punch_hit_x;
			p->hit_boxes[1][0].offset_y = wrecca->front_punch_hit_y;
			p->hit_boxes[1][0].x = p->pos[1].x + p->hit_boxes[1][0].offset_x;
			p->hit_boxes[1][0].y = p->pos[1].y + p->hit_boxes[1][0].offset_y;
			p->hit_boxes[1][0].w = wrecca->front_punch_hit_w;
			p->hit_boxes[1][0].h = wrecca->front_punch_hit_h;
			p->hit_boxes[1][0].damage = wrecca->front_punch_damage;

			p->hit_boxes[1][1].offset_x = wrecca->back_punch_hit_x;
			p->hit_boxes[1][1].offset_y = wrecca->back_punch_hit_y;
			p->hit_boxes[1][1].x = p->pos[1].x + p->hit_boxes[1][1].offset_x;
			p->hit_boxes[1][1].y = p->pos[1].y + p->hit_boxes[1][1].offset_y;
			p->hit_boxes[1][1].w = wrecca->back_punch_hit_w;
			p->hit_boxes[1][1].h = wrecca->back_punch_hit_h;
			p->hit_boxes[1][1].damage = wrecca->back_punch_damage;

			p->hit_boxes[1][4].offset_x = wrecca->punch_combo_hit_x;
			p->hit_boxes[1][4].offset_y = wrecca->punch_combo_hit_y;
			p->hit_boxes[1][4].x = p->pos[1].x + p->hit_boxes[1][4].offset_x;
			p->hit_boxes[1][4].y = p->pos[1].y + p->hit_boxes[1][4].offset_y;
			p->hit_boxes[1][4].w = wrecca->punch_combo_hit_w;
			p->hit_boxes[1][4].h = wrecca->punch_combo_hit_h;
			p->hit_boxes[1][4].damage = wrecca->punch_combo_damage;
		}
		break;
		default:
		{
			printf("ERROR: Invalid Character Selection.  Player 1 defaulted to character 1\n");
			chosen_character[1] = 1;
			p->music[1] = wrecca_theme;
			p->texture[1] = Wrecca_texture;
			p->hurt_fx[1] = wrecca_hurt_fx;
			p->blood_shade[1] = wrecca->blood_shade;
			p->player_flip[1] = SDL_FLIP_NONE;
			p->state[1] = idle;
			p->facing[1] = left;
			p->pos[1].x = 2300;
			p->pos[1].y = ground_y - wrecca->height;
			p->collision_offset[1].x = wrecca->collision_offset_x;
			p->collision_offset[1].y = wrecca->collision_offset_y;
			p->collision_pos[1].x = p->pos[1].x + p->collision_offset[1].x;
			p->collision_pos[1].y = p->pos[1].y + p->collision_offset[1].y;
			p->accel[1].x = 0;
			p->accel[1].y = 0;
			p->vel[1].x = 0;
			p->vel[1].y = 0;
			p->f_move[1] = wrecca->f_move;
			p->width[1] = wrecca->width;
			p->height[1] = wrecca->height;
			p->collision_width[1] = wrecca->collision_width;
			p->collision_height[1] = wrecca->collision_height;

			p->frame_pos[1].x = wrecca->first_frame_x;
			p->frame_pos[1].y = wrecca->first_frame_y;
			p->walk_y[1] = wrecca->walk_frame_y;
			p->n_walk_frames[1] = wrecca->n_walk_frames;
			p->walk_duration[1] = wrecca->walk_duration;
			p->idle_y[1] = wrecca->idle_frame_y;
			p->n_idle_frames[1] = wrecca->n_idle_frames;
			p->idle_duration[1] = wrecca->idle_duration;
			p->jump_y[1] = wrecca->jump_frame_y;
			p->n_jump_frames[1] = wrecca->n_jump_frames;
			p->jump_duration[1] = wrecca->jump_duration;
			p->front_punch_y[1] = wrecca->front_punch_frame_y;
			p->n_front_punch_frames[1] = wrecca->n_front_punch_frames;
			p->front_punch_duration[1] = wrecca->front_punch_duration;
			p->back_punch_y[1] = wrecca->back_punch_frame_y;
			p->n_back_punch_frames[1] = wrecca->n_front_punch_frames;
			p->back_punch_duration[1] = wrecca->front_punch_duration;

			p->punch_combo_y[1] = wrecca->punch_combo_frame_y;
			p->n_punch_combo_frames[1] = wrecca->n_punch_combo_frames;
			p->punch_combo_duration[1] = wrecca->punch_combo_duration;
			p->last_punch_combo_change_time[1] = 0;

			p->block_y[1] = wrecca->block_frame_y;
			p->crouch_y[1] = wrecca->crouch_frame_y;
			p->last_jump_change_time[1] = 0;
			p->last_front_punch_change_time[1] = 0;
			p->last_back_punch_change_time[1] = 0;
			p->last_walk_change_time[1] = 0;
			p->last_idle_change_time[1] = 0;
			p->current_frame[1] = 0;

			p->hurt_boxes[1][0].offset_x = wrecca->head_offset_x;
			p->hurt_boxes[1][0].offset_y = wrecca->head_offset_y;
			p->hurt_boxes[1][0].x = p->pos[1].x + p->hurt_boxes[1][0].offset_x;
			p->hurt_boxes[1][0].y = p->pos[1].y + p->hurt_boxes[1][0].offset_y;
			p->hurt_boxes[1][0].w = wrecca->head_w;
			p->hurt_boxes[1][0].h = wrecca->head_h;

			p->hurt_boxes[1][1].offset_x = wrecca->shoulder_offset_x;
			p->hurt_boxes[1][1].offset_y = wrecca->shoulder_offset_y;
			p->hurt_boxes[1][1].x = p->pos[1].x + p->hurt_boxes[1][1].offset_x;
			p->hurt_boxes[1][1].y = p->pos[1].y + p->hurt_boxes[1][1].offset_y;
			p->hurt_boxes[1][1].w = wrecca->shoulder_w;
			p->hurt_boxes[1][1].h = wrecca->shoulder_h;

			p->hurt_boxes[1][2].offset_x = wrecca->torso_offset_x;
			p->hurt_boxes[1][2].offset_y = wrecca->torso_offset_y;
			p->hurt_boxes[1][2].x = p->pos[1].x + p->hurt_boxes[1][2].offset_x;
			p->hurt_boxes[1][2].y = p->pos[1].y + p->hurt_boxes[1][2].offset_x;
			p->hurt_boxes[1][2].w = wrecca->torso_w;
			p->hurt_boxes[1][2].h = wrecca->torso_h;

			p->hurt_boxes[1][3].offset_x = wrecca->leg_offset_x;
			p->hurt_boxes[1][3].offset_y = wrecca->leg_offset_y;
			p->hurt_boxes[1][3].x = p->pos[1].x + p->hurt_boxes[1][3].offset_x;
			p->hurt_boxes[1][3].y = p->pos[1].y + p->hurt_boxes[1][3].offset_y;
			p->hurt_boxes[1][3].w = wrecca->leg_w;
			p->hurt_boxes[1][3].h = wrecca->leg_h;

			p->hit_boxes[1][0].offset_x = wrecca->front_punch_hit_x;
			p->hit_boxes[1][0].offset_y = wrecca->front_punch_hit_y;
			p->hit_boxes[1][0].x = p->pos[1].x + p->hit_boxes[1][0].offset_x;
			p->hit_boxes[1][0].y = p->pos[1].y + p->hit_boxes[1][0].offset_y;
			p->hit_boxes[1][0].w = wrecca->front_punch_hit_w;
			p->hit_boxes[1][0].h = wrecca->front_punch_hit_h;
			p->hit_boxes[1][0].damage = wrecca->front_punch_damage;

			p->hit_boxes[1][1].offset_x = wrecca->back_punch_hit_x;
			p->hit_boxes[1][1].offset_y = wrecca->back_punch_hit_y;
			p->hit_boxes[1][1].x = p->pos[1].x + p->hit_boxes[1][1].offset_x;
			p->hit_boxes[1][1].y = p->pos[1].y + p->hit_boxes[1][1].offset_y;
			p->hit_boxes[1][1].w = wrecca->back_punch_hit_w;
			p->hit_boxes[1][1].h = wrecca->back_punch_hit_h;
			p->hit_boxes[1][1].damage = wrecca->back_punch_damage;

			p->hit_boxes[1][4].offset_x = wrecca->punch_combo_hit_x;
			p->hit_boxes[1][4].offset_y = wrecca->punch_combo_hit_y;
			p->hit_boxes[1][4].x = p->pos[1].x + p->hit_boxes[1][4].offset_x;
			p->hit_boxes[1][4].y = p->pos[1].y + p->hit_boxes[1][4].offset_y;
			p->hit_boxes[1][4].w = wrecca->punch_combo_hit_w;
			p->hit_boxes[1][4].h = wrecca->punch_combo_hit_h;
			p->hit_boxes[1][4].damage = wrecca->punch_combo_damage;
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
			p->blood_shade[0] = 1;
			p->blood_shade[1] = 0;
		}
	}

	int check_Opponent_Collision(Player *p)
	{
		if (p->collision_pos[0].x + p->collision_width[0] < p->collision_pos[1].x) return 2;
		else if (p->collision_pos[0].x > p->collision_pos[1].x + p->collision_width[1]) return 3;
		else if (p->hurt_boxes[0][3].y + p->hurt_boxes[0][3].h < p->collision_pos[1].y) return 0;
		else if (p->hurt_boxes[1][3].y + p->hurt_boxes[1][3].h < p->collision_pos[0].y) return 0;

		else return 1;
	}

	void check_Hit(Player *p, Particles::Particles *blood, int current_time)
	{
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
				if (p->attacks[0] != punch_combo)
				{
					p->vel[1].x = 0.1;
					if (p->pos[1].x < p->pos[0].x) p->vel[1].x = -0.1;
					for (int k = 0; k < 100; k++)
					{
						p->pos[1].x += 0.1 * p->vel[1].x * dt;
					}
				}
				//if (j == 0) p->damage_dealt[0] *= 2;
				Particles::create_Blood(blood, p->hurt_boxes[1][j].x + p->hurt_boxes[1][j].w / 3, p->hurt_boxes[1][j].y + p->hurt_boxes[1][j].h, p->damage_dealt[0], p->facing[1], p->blood_shade[1]);
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
				if (p->attacks[1] != punch_combo)
				{

					p->vel[0].x = 0.1;
					if (p->pos[0].x < p->pos[1].x) p->vel[0].x = -0.1;
					for (int k = 0; k < 100; k++)
					{
						p->pos[0].x += 0.1 * p->vel[0].x * dt;
					}
				}
				//if (j == 0) p->damage_dealt[1] *= 2;
				Particles::create_Blood(blood, p->hurt_boxes[0][j].x + p->hurt_boxes[0][j].w / 2, p->hurt_boxes[0][j].y + p->hurt_boxes[0][j].h / 2, p->damage_dealt[1], p->facing[0], p->blood_shade[0]);
				break;
			}
		}


	}

	void check_Combos(Player *p, int i)
	{
		if (p->x_count[i] == 2 && p->y_count[i] == 1 && p->state[i] != jumping && p->state[i] != blocking && p->state[i] != walking && p->crouched[i] == 0)
		{
			if (p->attacks[i] != punch_combo) p->current_frame[i] = 0;
			p->attacks[i] = punch_combo;
			p->frame_pos[i].y = p->punch_combo_y[i];
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
			else if (check_Opponent_Collision(p) == 2)
			{
				
				p->facing[0] = right;
				if (chosen_character[0] == 0) p->player_flip[0] = SDL_FLIP_NONE;
				else p->player_flip[0] = SDL_FLIP_HORIZONTAL;

			
				p->facing[1] = left;
				if (chosen_character[1] == 0) p->player_flip[1] = SDL_FLIP_HORIZONTAL;
				else p->player_flip[1] = SDL_FLIP_NONE;
			}
			else if (check_Opponent_Collision(p) == 3)
			{
				p->facing[0] = left;
				if (chosen_character[0] == 0) p->player_flip[0] = SDL_FLIP_HORIZONTAL;
				else p->player_flip[0] = SDL_FLIP_NONE;

				p->facing[1] = right;
				if (chosen_character[1] == 0) p->player_flip[1] = SDL_FLIP_NONE;
				else p->player_flip[1] = SDL_FLIP_HORIZONTAL;
			}

			if (p->vel[i].x >= p->max_vel)
			{
				p->vel[i].x = 0;
			}
			if (p->vel[i].x <= -p->max_vel)
			{
				p->vel[i].x = 0;
			}


			if (p->pos[i].x >= c->cam_center.x + 551)
			{
				c->accel.x += c->speed;
				p->pos[i].x = c->cam_center.x + 550;
			}
			if (p->pos[i].x <= c->cam_center.x - 1051)
			{
				c->accel.x -= c->speed;
				p->pos[i].x = c->cam_center.x - 1050;
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

			if (chosen_character[i] == 0)
			{
				if (p->facing[i] == left)
				{
					p->hurt_boxes[i][0].x += p->hurt_boxes[i][0].offset_x / 14;
					p->hurt_boxes[i][1].x += p->hurt_boxes[i][1].offset_x / 2;
					p->hurt_boxes[i][2].x += p->hurt_boxes[i][2].offset_x / 2;
					p->hurt_boxes[i][3].x += p->hurt_boxes[i][3].offset_x / 7;

					p->hit_boxes[i][0].x -= p->hit_boxes[i][0].offset_x / 1.15;
					p->hit_boxes[i][1].x -= p->hit_boxes[i][1].offset_x / 1.2;
					p->hit_boxes[i][4].x -= p->hit_boxes[i][1].offset_x / 2.7;
				}
				if (p->crouched[i] == 1)
				{
					p->hurt_boxes[i][0].y += p->hurt_boxes[i][0].offset_y * 3;
					p->hurt_boxes[i][1].y += p->hurt_boxes[i][1].offset_y * 1.5;
					p->hurt_boxes[i][2].y += p->hurt_boxes[i][2].offset_y / 2;
					p->hurt_boxes[i][3].y += p->hurt_boxes[i][3].offset_y / 3;
				}
			}

			if (chosen_character[i] == 1)
			{
				if (p->facing[i] == right)
				{
					p->hurt_boxes[i][0].x += p->hurt_boxes[i][0].offset_x / 6;
					p->hurt_boxes[i][1].x += p->hurt_boxes[i][1].offset_x / 10;
					p->hurt_boxes[i][2].x += p->hurt_boxes[i][2].offset_x / 15;
					p->hurt_boxes[i][3].x -= p->hurt_boxes[i][3].offset_x / 10;

					p->hit_boxes[i][0].x += 310;
					p->hit_boxes[i][1].x += p->hit_boxes[i][1].offset_x * 6.3;
					p->hit_boxes[i][4].x += p->hit_boxes[i][1].offset_x * 7.8;
				}
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
				else if (bg->pos[i].x > (c->cam_center.x + screen_width / 2)) continue;
				else if (bg->pos[i].y + screen_height < (c->cam_center.y - screen_height / 2)) continue;
				else if (bg->pos[i].y > (c->cam_center.y + screen_height / 2)) continue;
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
		int blood_grid_rows;
		int blood_grid_columns;
		int blood_grid_size;
		Vec** pos;
		int **alpha;
		int tile_size;
		int frame_x;
		int frame_y;
		int frame_size;
	};

	void init(Blood_Grid *b, Player::Player *p, Backgrounds::Backgrounds *bg)
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
		b->pos = (Vec**)calloc(b->blood_grid_rows, sizeof(Vec*));
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			b->pos[i] = (Vec*)calloc(b->blood_grid_columns, sizeof(Vec));
		}
		b->alpha = (int**)malloc(sizeof(int*) * b->blood_grid_rows);
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			b->alpha[i] = (int*)malloc(sizeof(int) * b->blood_grid_columns);
		}
		b->frame_x = 0;
		b->frame_y = 0;
		b->frame_size = 10;
	}

	void place_blood_tiles(Blood_Grid *b)
	{
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			for (int j = 0; j < b->blood_grid_columns; j++)
			{
				b->pos[i][j].x = j * b->tile_size;
				b->pos[i][j].y = i * b->tile_size;
				b->alpha[i][j] = 255;
				b->grid[i][j] = 3;
			}
		}
	}

	void get_Covered_Tile(Blood_Grid *b, Player::Player *p, Particles::Particles *blood, int j)
	{
		blood->current_row[j] = (int)blood->pos[j].y / b->tile_size;
		blood->current_column[j] = (int)blood->pos[j].x / b->tile_size;
	}

	void update(Blood_Grid *b, Player::Player *p, Particles::Particles *blood, int current_time)
	{
		int count = 0;
		Player::check_Hit(p, blood, current_time);
		for (int i = 0; i < p->n_players; i++)
		{
			if (p->got_hurt[i] == 1)
			{
				for (int j = 0; j < blood->max_particles; j++)
				{
					if (blood->active[j] == 1)
					{
						get_Covered_Tile(b, p, blood, j);

						for (int a = -1; a < 1; a++)
						{
							for (int c = -1; c < 1; c++)
							{
								if (b->grid[blood->current_row[j] + a][blood->current_column[j] + c] == b->grid[blood->current_row[j]][blood->current_column[j]])
								{
									b->grid[blood->current_row[j] + a][blood->current_column[j] + c] = p->blood_shade[i];
								}
							}
						}

						b->grid[blood->current_row[j]][blood->current_column[j]] = p->blood_shade[i];
						b->alpha[blood->current_row[j]][blood->current_column[j]] = 255;

					}
				}
				p->got_hurt[i] = 0;
			}
			
			
		}
		for (int h = 0; h < b->blood_grid_rows; h++)
		{
			for (int j = 0; j < b->blood_grid_columns; j++)
			{
				if (b->grid[h][j] == p->blood_shade[1]) count++;
			}
		}
		p->score[0] = count;
		count = 0;

		for (int h = 0; h < b->blood_grid_rows; h++)
		{
			for (int j = 0; j < b->blood_grid_columns; j++)
			{
				if (b->grid[h][j] == p->blood_shade[0]) count++;
			}
		}
		p->score[1] = count;
	}
	void draw(Blood_Grid *b, Camera::Camera *c, SDL_Texture *blood_texture, SDL_Rect blood_tile_src, SDL_RendererFlip fliptype)
	{
		SDL_Rect blood_dest;
		for (int i = 0; i < b->blood_grid_rows; i++)
		{
			for (int j = 0; j < b->blood_grid_columns; j++)
			{
				if (b->alpha[i][j] > 150 && b->grid[i][j] != 3) b->alpha[i][j]--;
				if (b->pos[i][j].x + b->tile_size < (c->cam_center.x - screen_width / 2)) continue;
				else if (b->pos[i][j].x > (c->cam_center.x + screen_width / 2)) continue;
				else if (b->pos[i][j].y + b->tile_size < (c->cam_center.y - screen_height / 2)) continue;
				else if (b->pos[i][j].y > (c->cam_center.y + screen_height / 2)) continue;

				blood_tile_src.x = b->grid[i][j] * 10;

				blood_dest.x = b->pos[i][j].x - c->cam_center.x + screen_width / 2;
				blood_dest.y = b->pos[i][j].y - c->cam_center.y + screen_height / 2;
				blood_dest.w = b->tile_size;
				blood_dest.h = b->tile_size;


				SDL_SetTextureAlphaMod(blood_texture, b->alpha[i][j]);
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
			SDL_RenderDrawRect(renderer, &selector_rect);
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


}

namespace Timer
{
	struct Timer
	{
		Vec pos;
		int digit_w;
		int digit_h;
		unsigned int n_digits;
		const unsigned int max_time = 125000;
		unsigned int last_time;
		unsigned int seconds_digit;
		unsigned int seconds_tens;
		unsigned int minutes;
	};

	void init(Timer *t)
	{
		t->pos.x = screen_width / 2 - 300;
		t->pos.y = 100;
		t->digit_w = 100;
		t->digit_h = 100;
		t->n_digits = 3;
		t->minutes = 0;
	}
	int update(Timer *t, unsigned int current_time)
	{
		t->seconds_digit = (t->max_time - current_time) / 1000;
		t->seconds_tens = (t->max_time - current_time) / 10000;
		if (t->seconds_tens >= 6)
		{
			if (t->minutes == 1) t->minutes = 2;
			else t->minutes = 1;
			t->seconds_tens -= 6;
		}
		else t->minutes = 0;

		if (t->seconds_digit % 10 == 0 && t->seconds_tens % 10 == 0 && t->minutes == 0) return 1;

		return 0;
	}
	void draw(Timer *t, SDL_Rect src, SDL_Texture *numbers_texture, SDL_RendererFlip fliptype)
	{
		SDL_Rect dest1 = { t->pos.x + t->digit_w * 4, t->pos.y, t->digit_w, t->digit_h };
		src.x = t->digit_w * (t->seconds_digit % 10);
		SDL_SetTextureAlphaMod(numbers_texture, 255);
		SDL_RenderCopyEx(renderer, numbers_texture, &src, &dest1, 0, NULL, fliptype);

		SDL_Rect dest2 = { t->pos.x + t->digit_w * 3, t->pos.y, t->digit_w, t->digit_h };
		src.x = t->digit_w * (t->seconds_tens % 10);
		SDL_SetTextureAlphaMod(numbers_texture, 255);
		SDL_RenderCopyEx(renderer, numbers_texture, &src, &dest2, 0, NULL, fliptype);

		SDL_Rect dest3 = { t->pos.x + t->digit_w * 2, t->pos.y, t->digit_w, t->digit_h };
		src.x = t->digit_w * 10;
		SDL_SetTextureAlphaMod(numbers_texture, 255);
		SDL_RenderCopyEx(renderer, numbers_texture, &src, &dest3, 0, NULL, fliptype);

		SDL_Rect dest4 = { t->pos.x + t->digit_w, t->pos.y, t->digit_w, t->digit_h };
		src.x = t->digit_w * (t->minutes % 10);
		SDL_SetTextureAlphaMod(numbers_texture, 255);
		SDL_RenderCopyEx(renderer, numbers_texture, &src, &dest4, 0, NULL, fliptype);
	}
}

void draw_win(SDL_Texture **texture, SDL_RendererFlip fliptype, int winner)
{
	SDL_Rect src = { 0, 0, screen_width, screen_height };
	SDL_Rect dest;
	dest.x = 0;
	dest.y = 0;
	dest.w = screen_width;
	dest.h = screen_height;

	SDL_SetTextureAlphaMod(texture[winner], 255);
	SDL_RenderCopyEx(renderer, texture[winner], &src, &dest, 0, NULL, fliptype);
}

enum Interface
{
	title_screen,
	main_menu,
	character_select,
	local_multi,
	win_screen
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
	Mix_Chunk *title_fx = Mix_LoadWAV("Audio\\Title_CC.wav");
	Mix_Chunk *blood_fx = Mix_LoadWAV("Audio\\Blood_CC.wav");
	Mix_Chunk *cell_fx = Mix_LoadWAV("Audio\\Cell_CC.wav");
	Mix_Chunk *block_fx = Mix_LoadWAV("Audio\\Dodge_CC.wav");
	Mix_Chunk *punch_0_fx = Mix_LoadWAV("Audio\\Hook_CC.wav");
	Mix_Chunk *punch_1_fx = Mix_LoadWAV("Audio\\Jab_CC.wav");
	Mix_Chunk *punch_2_fx = Mix_LoadWAV("Audio\\Punch_CC.wav");
	Mix_Chunk *punch_3_fx = Mix_LoadWAV("Audio\\Punch2_CC.wav");
	Mix_Chunk *punch_4_fx = Mix_LoadWAV("Audio\\Punch3_CC.wav");
	Mix_Chunk *punch_5_fx = Mix_LoadWAV("Audio\\Upper_Cut_CC.wav");
	Mix_Chunk *chomp_fx = Mix_LoadWAV("Audio\\Wrecca_chomp.wav");
	Mix_Chunk *tk_hurt_fx = Mix_LoadWAV("Audio\\TK_CC.wav");
	Mix_Chunk *wrecca_hurt_fx = Mix_LoadWAV("Audio\\HitWrecca_CC.wav");
	Mix_Chunk *fight_begin_fx = Mix_LoadWAV("Audio\\short_fight.wav");

	SDL_Window *window = SDL_CreateWindow("Crimson Canvas", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_RendererFlip fliptype = SDL_FLIP_NONE;

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

	SDL_Surface *Wrecca_surface = IMG_Load(Images::Wrecca_filename);
	assert(Wrecca_surface);
	SDL_Texture *Wrecca_texture = SDL_CreateTextureFromSurface(renderer, Wrecca_surface);
	SDL_FreeSurface(Wrecca_surface);

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

	SDL_Surface *numbers_surface = IMG_Load(Images::numbers_filename);
	assert(numbers_surface);
	SDL_Texture *numbers_texture = SDL_CreateTextureFromSurface(renderer, numbers_surface);
	SDL_FreeSurface(numbers_surface);

	SDL_Surface **win_surface = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * 2);
	SDL_Texture **win_texture = (SDL_Texture**)malloc(sizeof(SDL_Texture*) * 2);
	for (int i = 0; i < 2; i++)
	{
		win_surface[i] = IMG_Load(Images::win_filename[i]);
		assert(win_surface[i]);
		win_texture[i] = SDL_CreateTextureFromSurface(renderer, win_surface[i]);
		SDL_FreeSurface(win_surface[i]);
	}

	Interface game_state;
	unsigned char *key_state = (unsigned char*)SDL_GetKeyboardState(NULL);
	static unsigned char last_key_state[256];
	memset(last_key_state, 0, 256);

	const int ground_y = 1000;
	Mix_VolumeMusic(30);
	Mix_VolumeChunk(tk_hurt_fx, 80);
	Mix_VolumeChunk(wrecca_hurt_fx, 30);
	Input::init();
	Camera::Camera c;
	Camera::init(&c);
	Character_Data::TK tk;
	Character_Data::Camila camila;
	Character_Data::Wrecca wrecca;
	game_state = title_screen;

	unsigned int current_mouse_state = 0;
	unsigned int prev_mouse_state = 0;
	unsigned int game_start_time = SDL_GetTicks();
	unsigned int current_time = 0;
	unsigned int last_frame_time = 0;
	unsigned int timer_time = 0;
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
			Mix_PlayChannel(-1, title_fx, 0);
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
						Mix_PlayChannel(-1, cell_fx, 0);
						game_state = main_menu;
						break;
					}

					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					Menu::draw_Menu(&title, title_texture, title_src, fliptype);
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
						Mix_PlayChannel(-1, cell_fx, 0);
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
						Mix_PlayChannel(-1, cell_fx, 0);
						game_state = character_select;
						break;
					}

					if ((s.current_button[1] == 0) && (P2_A == 1 && LAST_P2_A))
					{
						Mix_PlayChannel(-1, cell_fx, 0);
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
						Mix_PlayChannel(-1, cell_fx, 0);
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
			Player::Player p;
			Player::allocate(&p);
			Grid::Blood_Grid b;
			Grid::init(&b, &p, &bg);
			Grid::place_blood_tiles(&b);



			SDL_Rect TK_src = { 0 };
			SDL_Rect bg_src = { 0, 0, screen_width, screen_height };
			SDL_Rect blood_tile_src = { 0, 0 , b.frame_size, b.frame_size };
			SDL_Rect blood_particle_src = { 0, 0, blood.width, blood.height };
			SDL_Rect score_src = { 0, 0 , 100, 100 };

			c.cam_center.x = screen_width;

			Player::player_Character_Setup(&p, &tk, TK_texture, tk_theme, tk_hurt_fx, &camila, Camila_texture, camila_theme, &wrecca, Wrecca_texture, wrecca_theme, wrecca_hurt_fx, chosen_character, ground_y);


			SDL_Delay(1000);
			Mix_PlayChannel(-1, fight_begin_fx, 0);
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


				Timer::Timer t;
				Timer::init(&t);
				SDL_Rect timer_src = { 0, 0 , t.digit_w, t.digit_h };


				current_time = SDL_GetTicks();
				timer_time = current_time;
				if (paused == 1)
				{
					Input::update();
					if ((P1_START == 1 && LAST_P1_START == 0) || (P2_START == 1 && LAST_P2_START == 0)) paused = 0;
				}

				if (1000.0 / (current_time - last_frame_time) <= frame_limit && paused == 0)
				{
					last_frame_time = current_time;
					if (Timer::update(&t, timer_time) == 1)
					{
						if (p.score[0] > p.score[1]) winner = 0;
						else if (p.score[0] < p.score[1]) winner = 1;
						else winner = chosen_character[rand() % 2];
						printf("player %d wins with %d points\n", winner, p.score[winner]);
						game_state = win_screen;
						break;
					}
					Input::update();

					if (paused == 0)
					{
						if ((P1_START == 1 && LAST_P1_START == 0) || (P2_START == 1 && LAST_P2_START == 0)) paused = 1;
					}

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
							p.frame_pos[0].y = p.block_y[0];
						}
					}
					if (P1_LEFTY > Input::stick_dead_zone || P1_DPAD_DOWN == 1 || key_state[SDL_SCANCODE_S])
					{
						if (p.state[0] != Player::jumping && p.attacks[0] == Player::not_attacking)
						{
							p.crouched[0] = 1;
							p.state[0] = Player::blocking;
							p.frame_pos[0].y = p.crouch_y[0];
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
								p.frame_pos[0].y = p.jump_y[0];
								p.current_frame[0] = 0;
								p.accel[0].y -= p.f_jump;
							}
						}
					}

					if (P1_LEFTX < -Input::stick_dead_zone || P1_DPAD_LEFT == 1 || key_state[SDL_SCANCODE_A])
					{
						if (p.state[0] != Player::blocking && p.attacks[0] == Player::not_attacking)
						{
							p.f_move[0] = tk.f_move;
							//p.facing[0] = Player::left;
							//p.player_flip[0] = SDL_FLIP_HORIZONTAL;
							if (chosen_character[0] == 1) p.player_flip[0] = SDL_FLIP_NONE;
							p.accel[0].x += -p.f_move[0];
							if (p.state[0] != Player::jumping)
							{
								p.frame_pos[0].y = p.walk_y[0];
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
						if (p.state[0] != Player::blocking && p.attacks[0] == Player::not_attacking)
						{
							p.f_move[0] = tk.f_move;
							//p.facing[0] = Player::right;
							//p.player_flip[0] = SDL_FLIP_NONE;
							if (chosen_character[0] == 1) p.player_flip[0] = SDL_FLIP_HORIZONTAL;
							p.accel[0].x += p.f_move[0];
							if (p.state[0] != Player::jumping)
							{
								p.frame_pos[0].y = p.walk_y[0];
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
						if (p.state[0] != Player::blocking && p.state[0] != Player::jumping && p.attacks[0] == Player::not_attacking)
						{
							p.state[0] = Player::idle;
							p.x_count[0] = 0;
							p.y_count[0] = 0;
							p.a_count[0] = 0;
							p.b_count[0] = 0;
							p.frame_pos[0].y = p.idle_y[0];
							if (current_time - p.last_idle_change_time[0] >= p.idle_duration[0])
							{
								p.current_frame[0] = (p.current_frame[0] + 1) % p.n_idle_frames[0];
								p.last_idle_change_time[0] = current_time;
							}
						}
					}

					/*
					front punch is x
					back punch is y
					front kick is a
					back kick is b
					*/
					if ((P1_X == 1 && LAST_P1_X == 0) || (key_state[SDL_SCANCODE_J] && last_key_state[SDL_SCANCODE_J] == 0))
					{
						if (P1_Y == 0 && P1_A == 0 && P1_B == 0)
						{
							if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::not_attacking && p.state[0] != Player::jumping)
							{
								p.x_count[0]++;
								p.attacks[0] = Player::front_punch;
								p.frame_pos[0].y = p.front_punch_y[0];
								p.current_frame[0] = 0;
							}
							else if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::back_punch && p.state[0] != Player::jumping)
							{
								if (p.current_frame[0] > p.n_back_punch_frames[0] - 1)
								{
									p.x_count[0] = 0;
									p.y_count[0] = 0;
								}
								else p.x_count[0]++;
							}
							else if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::front_punch && p.state[0] != Player::jumping)
							{
								if (p.current_frame[0] > p.n_front_punch_frames[0] - 1) p.x_count[0] = 0;
								else p.x_count[0]++;
							}
							else if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::punch_combo && p.state[0] != Player::jumping)
							{
								p.hit_boxes[0][4].active = 0;
								p.x_count[0]++;
								p.attacks[0] = Player::not_attacking;
							}
						}
					}
					if ((P1_Y == 1 && LAST_P1_Y == 0) || (key_state[SDL_SCANCODE_I] && last_key_state[SDL_SCANCODE_I] == 0))
					{
						if (P1_X == 0 && P1_A == 0 && P1_B == 0)
						{
							if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::not_attacking && p.state[0] != Player::jumping)
							{
								p.y_count[0]++;
								p.attacks[0] = Player::back_punch;
								p.frame_pos[0].y = p.back_punch_y[0];
								p.current_frame[0] = 0;
							}
							else if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::front_punch && p.state[0] != Player::jumping)
							{
								if (p.current_frame[0] > p.n_front_punch_frames[0] - 1)
								{
									p.x_count[0] = 0;
									p.y_count[0] = 0;
								}
								else p.y_count[0]++;
							}
							else if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::back_punch && p.state[0] != Player::jumping)
							{
								if (p.current_frame[0] > p.n_back_punch_frames[0] - 1) p.y_count[0] = 0;
								else p.y_count[0]++;
							}
							else if (p.state[0] != Player::blocking && p.crouched[0] == 0 && p.attacks[0] == Player::punch_combo && p.state[0] != Player::jumping)
							{
								p.hit_boxes[0][4].active = 0;
								p.y_count[0]++;
								p.attacks[0] = Player::not_attacking;
							}
						}
					}
					if ((P1_A == 1 && LAST_P1_A == 0) || (key_state[SDL_SCANCODE_K] && last_key_state[SDL_SCANCODE_K] == 0))
					{
						p.a_count[0]++;
						printf("p1 combo count A %d\n", p.a_count[0]);
					}
					if ((P1_B == 1 && LAST_P1_B == 0) || (key_state[SDL_SCANCODE_L] && last_key_state[SDL_SCANCODE_L] == 0))
					{
						p.b_count[0]++;
						printf("p1 combo count B %d\n", p.b_count[0]);
					}

					Player::check_Combos(&p, 0);
					if (p.state[0] == Player::jumping)
					{
						if (current_time - p.last_jump_change_time[0] >= p.jump_duration[0])
						{
							p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_jump_frames[0] + 1);
							p.last_jump_change_time[0] = current_time;
						}
					}

					if (p.attacks[0] == Player::punch_combo)
					{
						if (p.state[0] != Player::walking)
						{
							p.hit_boxes[0][0].active = 0;
							p.hit_boxes[0][1].active = 0;
							if (chosen_character[0] == 0)
							{
								p.hit_boxes[0][4].active = 1;
								if (p.state[0] == Player::jumping) p.attacks[0] = Player::not_attacking;
								if (current_time - p.last_punch_combo_change_time[0] >= p.punch_combo_duration[0])
								{
									p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_punch_combo_frames[0] + 1);
									if (p.current_frame[0] < p.n_punch_combo_frames[0] - p.attack_audio_offset[0] - 1)
									{
										if (p.damage_dealt[0] > 0)
										{
											Mix_PlayChannel(-1, punch_1_fx, 0);
											Mix_PlayChannel(-1, p.hurt_fx[1], 0);
											Mix_PlayChannel(-1, blood_fx, 0);
										}
										else Mix_PlayChannel(-1, block_fx, 0);
									}
									p.last_punch_combo_change_time[0] = current_time;
								}
								if (p.current_frame[0] >= p.n_punch_combo_frames[0])
								{
									p.hit_boxes[0][4].active = 0;
									p.attacks[0] = Player::not_attacking;
									p.current_frame[0] = 0;
									p.damage_dealt[0] = 0;
								}
							}
							else if (chosen_character[0] == 1)
							{
								if (p.state[0] == Player::jumping) p.attacks[0] = Player::not_attacking;
								if (current_time - p.last_punch_combo_change_time[0] >= p.punch_combo_duration[0])
								{
									p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_punch_combo_frames[0] + 1);
									p.last_punch_combo_change_time[0] = current_time;
									if (p.current_frame[0] == 10)
									{
										if (p.damage_dealt[0] > 0)
										{
											Mix_PlayChannel(-1, chomp_fx, 0);
											Mix_PlayChannel(-1, p.hurt_fx[1], 0);
											Mix_PlayChannel(-1, blood_fx, 0);
										}
										else Mix_PlayChannel(-1, block_fx, 0);
									}
								}
								if (p.current_frame[0] >= 9 && p.current_frame[0] <= 11) p.hit_boxes[0][4].active = 1;
								if (p.current_frame[0] >= p.n_punch_combo_frames[0])
								{
									p.hit_boxes[0][4].active = 0;
									p.attacks[0] = Player::not_attacking;
									p.current_frame[0] = 0;
									p.damage_dealt[0] = 0;
								}
							}
						}
					}
					else if (p.attacks[0] == Player::front_punch)
					{
						if (chosen_character[0] == 0)
						{
							p.hit_boxes[0][0].active = 1;
							if (current_time - p.last_front_punch_change_time[0] >= p.front_punch_duration[0])
							{
								p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_front_punch_frames[0] + 1);
								if (p.current_frame[0] == p.n_front_punch_frames[0] - p.attack_audio_offset[0])
								{
									if (p.damage_dealt[0] > 0)
									{
										Mix_PlayChannel(-1, punch_5_fx, 0);
										Mix_PlayChannel(-1, p.hurt_fx[1], 0);
										Mix_PlayChannel(-1, blood_fx, 0);
									}
									else Mix_PlayChannel(-1, block_fx, 0);
								}
								p.last_front_punch_change_time[0] = current_time;
							}

							if (p.current_frame[0] >= p.n_front_punch_frames[0])
							{
								p.hit_boxes[0][0].active = 0;
								p.attacks[0] = Player::not_attacking;
								p.current_frame[0] = 0;
								p.damage_dealt[0] = 0;
							}
						}
						else if (chosen_character[0] == 1)
						{
							if (current_time - p.last_front_punch_change_time[0] >= p.front_punch_duration[0])
							{
								p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_front_punch_frames[0] + 1);

								if (p.current_frame[0] == 9)
								{
									if (p.damage_dealt[0] > 0)
									{
										Mix_PlayChannel(-1, punch_4_fx, 0);
										Mix_PlayChannel(-1, p.hurt_fx[1], 0);
										Mix_PlayChannel(-1, blood_fx, 0);
									}
									else Mix_PlayChannel(-1, block_fx, 0);
								}
								p.last_front_punch_change_time[0] = current_time;
							}
							if (p.current_frame[0] == 8) p.hit_boxes[0][0].active = 1;
							else p.hit_boxes[0][0].active = 0;
							if (p.current_frame[0] >= p.n_front_punch_frames[0])
							{
								p.hit_boxes[0][0].active = 0;
								p.attacks[0] = Player::not_attacking;
								p.current_frame[0] = 0;
								p.damage_dealt[0] = 0;
							}
						}
					}
					else if (p.attacks[0] == Player::back_punch)
					{
						if (chosen_character[0] == 0)
						{
							p.hit_boxes[0][1].active = 1;
							if (current_time - p.last_back_punch_change_time[0] >= p.back_punch_duration[0])
							{
								p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_back_punch_frames[0] + 1);
								if (p.current_frame[0] == p.n_back_punch_frames[0] - p.attack_audio_offset[0])
								{
									if (p.damage_dealt[0] > 0)
									{
										Mix_PlayChannel(-1, punch_0_fx, 0);
										Mix_PlayChannel(-1, p.hurt_fx[1], 0);
										Mix_PlayChannel(-1, blood_fx, 0);
									}
									else Mix_PlayChannel(-1, block_fx, 0);
								}
								p.last_back_punch_change_time[0] = current_time;
							}
							if (p.current_frame[0] >= p.n_back_punch_frames[0])
							{
								p.hit_boxes[0][1].active = 0;
								p.attacks[0] = Player::not_attacking;
								p.current_frame[0] = 0;
								p.damage_dealt[0] = 0;
							}
						}
						else if (chosen_character[0] == 1)
						{
							if (current_time - p.last_back_punch_change_time[0] >= p.back_punch_duration[0])
							{
								p.current_frame[0] = (p.current_frame[0] + 1) % (p.n_back_punch_frames[0] + 1);

								if (p.current_frame[0] == 7 || p.current_frame[0] == 10)
								{
									if (p.damage_dealt[0] > 0)
									{
										Mix_PlayChannel(-1, punch_4_fx, 0);
										Mix_PlayChannel(-1, p.hurt_fx[1], 0);
										Mix_PlayChannel(-1, blood_fx, 0);
									}
									else Mix_PlayChannel(-1, block_fx, 0);
								}
								p.last_back_punch_change_time[0] = current_time;
							}
							if (p.current_frame[0] == 6 || p.current_frame[0] == 9) p.hit_boxes[0][1].active = 1;
							else p.hit_boxes[0][1].active = 0;
							if (p.current_frame[0] >= p.n_back_punch_frames[0] - 3)
							{
								p.hit_boxes[0][1].active = 0;
								p.attacks[0] = Player::not_attacking;
								p.current_frame[0] = 0;
								p.damage_dealt[0] = 0;
							}
						}
					}
					else
					{
						p.attacks[0] = Player::not_attacking;
						p.x_count[0] = 0;
						p.y_count[0] = 0;
						p.a_count[0] = 0;
						p.b_count[0] = 0;
						for (int i = 0; i < Character_Data::n_hit_boxes; i++)
						{
							p.hit_boxes[0][i].active = 0;
						}
					}

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
							p.frame_pos[1].y = p.block_y[1];
						}
					}
					if (P2_LEFTY > Input::stick_dead_zone || P2_DPAD_DOWN == 1 || key_state[SDL_SCANCODE_DOWN])
					{
						if (p.state[1] != Player::jumping && p.attacks[1] == Player::not_attacking)
						{
							p.crouched[1] = 1;
							p.state[1] = Player::blocking;
							p.frame_pos[1].y = p.crouch_y[1];
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
								p.frame_pos[1].y = p.jump_y[1];
								p.current_frame[1] = 0;
								p.accel[1].y -= p.f_jump;
							}
						}
					}

					if (P2_LEFTX < -Input::stick_dead_zone || P2_DPAD_LEFT == 1 || key_state[SDL_SCANCODE_LEFT])
					{
						if (p.state[1] != Player::blocking && p.attacks[1] == Player::not_attacking)
						{
							p.f_move[1] = tk.f_move;
							//p.facing[1] = Player::left;
							//p.player_flip[1] = SDL_FLIP_HORIZONTAL;
							if (chosen_character[1] == 1) p.player_flip[1] = SDL_FLIP_NONE;
							p.accel[1].x += -p.f_move[1];
							if (p.state[1] != Player::jumping)
							{
								p.frame_pos[1].y = p.walk_y[1];
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
						if (p.state[1] != Player::blocking && p.attacks[1] == Player::not_attacking)
						{
							p.f_move[1] = tk.f_move;
							//p.facing[1] = Player::right;
							//p.player_flip[1] = SDL_FLIP_NONE;
							if (chosen_character[1] == 1) p.player_flip[1] = SDL_FLIP_HORIZONTAL;
							p.accel[1].x += p.f_move[1];
							if (p.state[1] != Player::jumping)
							{
								p.frame_pos[1].y = p.walk_y[1];
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
							p.state[1] = Player::idle;
							p.x_count[1] = 0;
							p.y_count[1] = 0;
							p.a_count[1] = 0;
							p.b_count[1] = 0;
							p.frame_pos[1].x = 0;
							p.frame_pos[1].y = p.idle_y[1];
							if (current_time - p.last_idle_change_time[1] >= p.idle_duration[1])
							{
								p.current_frame[1] = (p.current_frame[1] + 1) % p.n_idle_frames[1];
								p.last_idle_change_time[1] = current_time;
							}
						}
					}

					/*
					front punch is x
					back punch is y
					front kick is a
					back kick is b
					*/

					if ((P2_X == 1 && LAST_P2_X == 0) || (key_state[SDL_SCANCODE_KP_7] && last_key_state[SDL_SCANCODE_KP_7] == 0))
					{
						if (P2_Y == 0 && P2_A == 0 && P2_B == 0)
						{
							if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::not_attacking && p.state[1] != Player::jumping)
							{
								p.x_count[1]++;
								p.attacks[1] = Player::front_punch;
								p.frame_pos[1].y = p.front_punch_y[1];
								p.current_frame[1] = 0;
							}
							else if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::back_punch && p.state[1] != Player::jumping)
							{
								if (p.current_frame[1] > p.n_back_punch_frames[1] - 1)
								{
									p.x_count[1] = 0;
									p.y_count[1] = 0;
								}
								else p.x_count[1]++;
							}
							else if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::front_punch && p.state[1] != Player::jumping)
							{
								if (p.current_frame[1] > p.n_front_punch_frames[1] - 1) p.x_count[1] = 0;
								else p.x_count[1]++;
							}
							else if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::punch_combo && p.state[1] != Player::jumping)
							{
								p.hit_boxes[1][4].active = 0;
								p.x_count[1]++;
								p.attacks[1] = Player::not_attacking;
							}
						}
					}
					if ((P2_Y == 1 && LAST_P2_Y == 0) || (key_state[SDL_SCANCODE_KP_8] && last_key_state[SDL_SCANCODE_KP_8] == 0))
					{
						if (P2_X == 0 && P2_A == 0 && P2_B == 0)
						{
							if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::not_attacking && p.state[1] != Player::jumping)
							{
								p.y_count[1]++;
								p.attacks[1] = Player::back_punch;
								p.frame_pos[1].y = p.back_punch_y[1];
								p.current_frame[1] = 0;
							}
							else if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::front_punch && p.state[1] != Player::jumping)
							{
								if (p.current_frame[1] > p.n_front_punch_frames[1] - 1)
								{
									p.x_count[1] = 0;
									p.y_count[1] = 0;
								}
								else p.y_count[1]++;
							}
							else if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::back_punch && p.state[1] != Player::jumping)
							{
								if (p.current_frame[1] > p.n_back_punch_frames[1] - 1) p.y_count[1] = 0;
								else p.y_count[1]++;
							}
							else if (p.state[1] != Player::blocking && p.crouched[1] == 0 && p.attacks[1] == Player::punch_combo && p.state[1] != Player::jumping)
							{
								p.hit_boxes[1][4].active = 0;
								p.y_count[1]++;
								p.attacks[1] = Player::not_attacking;
							}
						}
					}

					if ((P2_A == 1 && LAST_P2_A == 0) || (key_state[SDL_SCANCODE_KP_4] && last_key_state[SDL_SCANCODE_KP_4] == 0))
					{
						p.a_count[1]++;
						printf("p2 combo count A %d\n", p.a_count[1]);
					}
					if ((P2_B == 1 && LAST_P2_B == 0) || (key_state[SDL_SCANCODE_KP_5] && last_key_state[SDL_SCANCODE_KP_5] == 0))
					{
						p.b_count[1]++;
						printf("p2 combo count B %d\n", p.b_count[1]);
					}

					Player::check_Combos(&p, 1);
					if (p.state[1] == Player::jumping)
					{
						if (current_time - p.last_jump_change_time[1] >= p.jump_duration[1])
						{
							p.current_frame[1] = (p.current_frame[1] + 1) % p.n_jump_frames[1];
							p.last_jump_change_time[1] = current_time;
						}
					}

					if (p.attacks[1] == Player::punch_combo)
					{
						if (p.state[1] != Player::walking)
						{
							p.hit_boxes[1][0].active = 0;
							p.hit_boxes[1][1].active = 0;
							if (chosen_character[1] == 0)
							{
								p.hit_boxes[1][4].active = 1;
								if (p.state[1] == Player::jumping) p.attacks[1] = Player::not_attacking;
								if (current_time - p.last_punch_combo_change_time[1] >= p.punch_combo_duration[1])
								{
									p.current_frame[1] = (p.current_frame[1] + 1) % (p.n_punch_combo_frames[1] + 1);
									if (p.current_frame[1] < p.n_punch_combo_frames[1] - p.attack_audio_offset[1] - 1)
									{
										if (p.damage_dealt[1] > 0)
										{
											Mix_PlayChannel(-1, punch_1_fx, 0);
											Mix_PlayChannel(-1, p.hurt_fx[0], 0);
											Mix_PlayChannel(-1, blood_fx, 0);
										}
										else Mix_PlayChannel(-1, block_fx, 0);
									}
									p.last_punch_combo_change_time[1] = current_time;
								}
								if (p.current_frame[1] >= p.n_punch_combo_frames[1])
								{
									p.hit_boxes[1][4].active = 0;
									p.attacks[1] = Player::not_attacking;
									p.current_frame[1] = 0;
									p.damage_dealt[1] = 0;
								}
							}



							else if (chosen_character[1] == 1)
							{

								if (p.state[1] == Player::jumping) p.attacks[1] = Player::not_attacking;
								if (current_time - p.last_punch_combo_change_time[1] >= p.punch_combo_duration[1])
								{
									p.current_frame[1] = (p.current_frame[1] + 1) % (p.n_punch_combo_frames[1] + 1);
									p.last_punch_combo_change_time[1] = current_time;

									if (p.current_frame[1] == 10)
									{

										if (p.damage_dealt[1] > 0)
										{
											Mix_PlayChannel(-1, chomp_fx, 0);
											Mix_PlayChannel(-1, p.hurt_fx[0], 0);
											Mix_PlayChannel(-1, blood_fx, 0);
										}
										else Mix_PlayChannel(-1, block_fx, 0);
									}
								}

								if (p.current_frame[1] >= 9 && p.current_frame[1] <= 11) p.hit_boxes[1][4].active = 1;
								if (p.current_frame[1] >= p.n_punch_combo_frames[1])
								{
									p.hit_boxes[1][4].active = 0;
									p.attacks[1] = Player::not_attacking;
									p.current_frame[1] = 0;
									p.damage_dealt[1] = 0;
								}
							}
						}
					}
					else if (p.attacks[1] == Player::front_punch)
					{
						if (chosen_character[1] == 0)
						{
							p.hit_boxes[1][0].active = 1;
							if (current_time - p.last_front_punch_change_time[1] >= p.front_punch_duration[1])
							{
								p.current_frame[1] = (p.current_frame[1] + 1) % (p.n_front_punch_frames[1] + 1);
								if (p.current_frame[1] == p.n_front_punch_frames[1] - p.attack_audio_offset[1])
								{
									if (p.damage_dealt[1] > 0)
									{
										Mix_PlayChannel(-1, punch_5_fx, 0);
										Mix_PlayChannel(-1, p.hurt_fx[0], 0);
										Mix_PlayChannel(-1, blood_fx, 0);
									}
									else Mix_PlayChannel(-1, block_fx, 0);
								}
								p.last_front_punch_change_time[1] = current_time;
							}

							if (p.current_frame[1] >= p.n_front_punch_frames[1])
							{
								p.hit_boxes[1][0].active = 0;
								p.attacks[1] = Player::not_attacking;
								p.current_frame[1] = 0;
								p.damage_dealt[1] = 0;
							}
						}



						else if (chosen_character[1] == 1)
						{
							if (current_time - p.last_front_punch_change_time[1] >= p.front_punch_duration[1])
							{
								p.current_frame[1] = (p.current_frame[1] + 1) % (p.n_front_punch_frames[1] + 1);

								if (p.current_frame[1] == 9)
								{
									if (p.damage_dealt[1] > 0)
									{
										Mix_PlayChannel(-1, punch_4_fx, 0);
										Mix_PlayChannel(-1, p.hurt_fx[0], 0);
										Mix_PlayChannel(-1, blood_fx, 0);
									}
									else Mix_PlayChannel(-1, block_fx, 0);
								}
								p.last_front_punch_change_time[1] = current_time;
							}
							if (p.current_frame[1] == 8) p.hit_boxes[1][0].active = 1;
							else p.hit_boxes[1][0].active = 0;
							if (p.current_frame[1] >= p.n_front_punch_frames[1])
							{
								p.hit_boxes[1][0].active = 0;
								p.attacks[1] = Player::not_attacking;
								p.current_frame[1] = 0;
								p.damage_dealt[1] = 0;
							}
						}
					}
					else if (p.attacks[1] == Player::back_punch)
					{

						if (chosen_character[1] == 0)
						{
							p.hit_boxes[1][1].active = 1;
							if (current_time - p.last_back_punch_change_time[1] >= p.back_punch_duration[1])
							{
								p.current_frame[1] = (p.current_frame[1] + 1) % (p.n_back_punch_frames[1] + 1);
								if (p.current_frame[1] == p.n_back_punch_frames[1] - p.attack_audio_offset[1])
								{
									if (p.damage_dealt[1] > 0)
									{
										Mix_PlayChannel(-1, punch_0_fx, 0);
										Mix_PlayChannel(-1, p.hurt_fx[0], 0);
										Mix_PlayChannel(-1, blood_fx, 0);
									}
									else Mix_PlayChannel(-1, block_fx, 0);
								}
								p.last_back_punch_change_time[1] = current_time;
							}
							if (p.current_frame[1] >= p.n_back_punch_frames[1])
							{
								p.hit_boxes[1][1].active = 0;
								p.attacks[1] = Player::not_attacking;
								p.current_frame[1] = 0;
								p.damage_dealt[1] = 0;
							}
						}

						else if (chosen_character[1] == 1)
						{
							if (current_time - p.last_back_punch_change_time[1] >= p.back_punch_duration[1])
							{
								p.current_frame[1] = (p.current_frame[1] + 1) % (p.n_back_punch_frames[1] + 1);

								if (p.current_frame[1] == 7 || p.current_frame[1] == 10)
								{
									if (p.damage_dealt[1] > 0)
									{
										Mix_PlayChannel(-1, punch_4_fx, 0);
										Mix_PlayChannel(-1, p.hurt_fx[0], 0);
										Mix_PlayChannel(-1, blood_fx, 0);
									}
									else Mix_PlayChannel(-1, block_fx, 0);
								}
								p.last_back_punch_change_time[1] = current_time;
							}
							if (p.current_frame[1] == 6 || p.current_frame[1] == 9) p.hit_boxes[1][1].active = 1;
							else p.hit_boxes[1][1].active = 0;
							if (p.current_frame[1] >= p.n_back_punch_frames[1] - 3)
							{
								p.hit_boxes[1][1].active = 0;
								p.attacks[1] = Player::not_attacking;
								p.current_frame[1] = 0;
								p.damage_dealt[1] = 0;
							}
						}

					}
					else
					{
						p.attacks[1] = Player::not_attacking;
						p.x_count[1] = 0;
						p.y_count[1] = 0;
						p.a_count[1] = 0;
						p.b_count[1] = 0;

						for (int i = 0; i < Character_Data::n_hit_boxes; i++)
						{
							p.hit_boxes[1][i].active = 0;
						}
					}

					Camera::update(&c);
					Grid::update(&b, &p, &blood, current_time);
					Particles::update_Blood(&blood, blood_fx, current_time, ground_y);
					//ALL FORCES MUST HAVE BEEN ADDED BY THIS POINT
					//UPDATE WILL TRANSLATE THOSE INTO VELOCITY
					Player::update(&p, &c, ground_y);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					Backgrounds::draw(&bg, &c, level_2_textures, bg_src, fliptype, current_time);
					Grid::draw(&b, &c, blood_texture, blood_tile_src, fliptype);
					Player::draw(&p, &c, TK_src);
					Particles::draw_Blood(&blood, blood_particle_textures, blood_particle_src, &c, fliptype);
					Timer::draw(&t, timer_src, numbers_texture, fliptype);

					SDL_RenderPresent(renderer);
				}
			}
		}
		else if (game_state == win_screen)
		{
			Mix_FadeInMusic(victory_theme, -1, 500);
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
						return 0;
						break;
					}

					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					draw_win(win_texture, fliptype, chosen_character[winner]);
					SDL_RenderPresent(renderer);
				}
			}
		}
	}
}