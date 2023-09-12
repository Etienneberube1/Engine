#pragma once


class IGraphics {
public:
	virtual ~IGraphics() = default;

	virtual void DrawLine(int x1, int x2, int y1, int y2) = 0;
	virtual void DrawRect() = 0;
	virtual void DrawFilledRect() = 0;

};

