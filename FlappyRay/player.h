#pragma once
#include <raylib.h>
#include <raymath.h>

class player
{
	// Constants
	const float max_velocity_{ 10 };

	// Properties
	Vector2 velocity_{ 0 , 0 };
	Vector2 size_{ 64, 64 };
	Vector2 position_{ 450.f / 2.f - size_.x / 2.f, 800.f / 2.f - size_.y / 2.f };
	Rectangle rectangle_{};
	Vector2 origin_{ size_.x / 2, size_.y / 2 };
	float rotation_{0};
	Color color_{BLUE};

public:
	// Functions
	player() = default;
	~player() = default;
	void update(bool game_over, bool countdown_active);
	void draw() const;
	Vector2 get_position() const;
	bool is_off_screen() const;
	Rectangle get_rect() const;
	void reset();
	void set_velocity(Vector2 velocity);
};

