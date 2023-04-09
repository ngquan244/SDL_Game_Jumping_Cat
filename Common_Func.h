
#pragma once

#ifndef COMMON_FUNC_H_
#define COMMON_FUNC_H_

//extern unsigned char color[4];


#include <Windows.h>
#include <SDL_image.h>
#include <SDL.h>
#include <string>
#include <vector>

const int FRAME_PER_SECOND = 15; //fps
const int wait_FRAME_PER_SECOND = 10;
const int SCREEN_WIDTH = 1400;
const int SCREEN_HEIGHT = 770;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const int COLOR_KEY_R = 147;
const int COLOR_KEY_G = 187;
const int COLOR_KEY_B = 236;

const int RENDER_DRAW_COLOR = 0xff;

typedef struct Input
{
	int left_;
	int right_;
	int up_;
	int down_;
	int jump_;
};



class BaseObject {
public:
	BaseObject();
	~BaseObject();
	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }
	SDL_Rect GetRect() const { return rect_; }
	SDL_Texture* GetObject() const { return p_object_; }

	virtual bool LoadImg(std::string path, SDL_Renderer* screen);
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
	void Free();
protected:
	SDL_Rect rect_;
	SDL_Texture* p_object_;
};
//MainObject

class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();

	enum WalkType
	{
		WALK_RIGHT = 0,
		WALK_LEFT = 1,
		WAIT_LEFT = -1,
		WAIT_RIGHT = -2,
	};
	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show (SDL_Renderer* des);

	void HandleInputAction(SDL_Event events,SDL_Renderer* screen);
	void set_clips();
	bool check_act();
	float get_x_pos() const { return x_pos_; }
	float get_y_pos() const { return y_pos_; }
	int get_width_frame() const { return width_frame_; }
	int get_height_frame() const { return height_frame_; }
	void set_x_pos(const float& xp) { x_pos_ = xp; }
	void set_y_pos(const float& yp) { y_pos_ = yp; }
private:
	float x_val_;
	float y_val_;

	float x_pos_;
	float y_pos_;

	int width_frame_;
	int height_frame_;

	

	SDL_Rect frame_clip_[6];
	Input input_type_;
	int frame_;
	int status_;
	float player_speed;
};

//Timer
class ImpTimer
{
public:
	ImpTimer();
	~ImpTimer();

	void start();
	void stop();
	void paused();
	void unpaused(); 

	int get_ticks();
	bool is_started();
	bool is_paused();

private:
	int start_tick_;
	int paused_tick_;

	bool is_paused_;
	bool is_started_;
};

//Threat
class ThreatsObject
{
public:
	ThreatsObject();
	~ThreatsObject();

	void set_x_val(const float& xVal) { x_val_ = xVal; }
	void set_y_val(const float& yVal) { y_val_ = yVal; }

	void set_x_pos(const float& xp) { x_pos_ = xp; }
	void set_y_pos(const float& yp) { y_pos_ = yp; }
	float get_x_pos() const { return x_pos_; }
	float get_y_pos() const { return y_pos_; }

	void set_clips();
	bool LoadImg(std::string path, SDL_Renderer* screen);
	bool _BaseObject_LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	int get_width_frame() const { return width_frame_; }
	int get_height_frame() const { return height_frame_; }
	void set_drop_speed(const float& ds) { drop_speed = ds; }

private:
	int drop_speed;
	int map_x_;
	int map_y_;
	float x_val_;
	float y_val_;
	float x_pos_;
	float y_pos_;

	bool on_ground_;
	int come_back_time;
	SDL_Rect frame_clip_[4];
	int width_frame_;
	int height_frame_;
	int frame_;
	SDL_Rect rect_;
	SDL_Texture* p_object_;
};

//CommonFunc
namespace SDLCommonFunc
{
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}

//PlayerPower
class PlayerPower : public BaseObject
{
public:
	PlayerPower();
	~PlayerPower();

	void SetNum(const int& num) { number_ = num; }
	void AddPos(const int& xPos);
	void Show(SDL_Renderer* screen);
	void Init(SDL_Renderer* screen);

	void Increase();
	void Decrease();

private:
	int number_;
	std::vector<int> pos_list_;

};


#endif