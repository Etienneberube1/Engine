#pragma once
#include "IGraphics.h"


class SDLGraphics : public IGraphics {
public:
	virtual void DrawLine(int x1, int x2, int y1, int y2) override;

};

