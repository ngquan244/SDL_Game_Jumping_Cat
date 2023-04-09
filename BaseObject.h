/*
#pragma once
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "Common_Func.h"

class BaseObject {
public:
	BaseObject();
	~BaseObject();
	void SetRect(const int& x,const int& y) { rect_.x = x,rect_.y = y; }
	SDL_Rect GetRect() const { return rect_; }
	SDL_Surface* GetObject() const { return p_object_; }
protected:
	SDL_Rect rect_;
	SDL_Surface* p_object_;
};
#endif
*/